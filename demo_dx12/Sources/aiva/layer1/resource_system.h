#pragma once
#include <pch.h>

#include <aiva/layer1/i_cpu_resource.h>
#include <aiva/utils/asserts.h>

namespace aiva::layer1
{
	struct Engine;
}

namespace aiva::layer1
{
	struct ResourceSystem final : private boost::noncopyable
	{
	// ----------------------------------------------------
	// Main

	public:
		ResourceSystem(aiva::layer1::Engine const& engine);

		~ResourceSystem();

	private:
		aiva::layer1::Engine const& mEngine;

	// ----------------------------------------------------
	// Resources

	public:
		template <typename T>
		std::shared_ptr<T> GetResource(std::filesystem::path const& fileName);

		std::shared_ptr<aiva::layer1::ICpuResource> GetResource(std::filesystem::path const& fileName);

	private:
		std::shared_ptr<aiva::layer1::ICpuResource> GetResourceFromCache(std::filesystem::path const& fileName) const;

		std::shared_ptr<aiva::layer1::ICpuResource> GetResourceFromFactory(std::filesystem::path const& fileExtension) const;

		void SetResourceToCache(std::filesystem::path const& fileName, std::shared_ptr<aiva::layer1::ICpuResource> const& resource);

		std::vector<std::byte> GetBinaryFromFile(std::filesystem::path const& fileName) const;

		void DeserealizeResourceFromBinary(std::shared_ptr<aiva::layer1::ICpuResource> const& resource, std::vector<std::byte> const& binary) const;

	private:
		std::unordered_map<std::filesystem::path, std::weak_ptr<aiva::layer1::ICpuResource>> mResources{};

	// ----------------------------------------------------
	// Factories

	private:
		using ResourceFactoryMethod = std::function<std::shared_ptr<aiva::layer1::ICpuResource>(aiva::layer1::Engine const&)>;

	private:
		void InitializeFactories();

		void TerminateFactories();

	private:
		template <typename T>
		void RegisterFactory(std::filesystem::path const& extension);

	private:
		std::unordered_map<std::filesystem::path, ResourceFactoryMethod> mFactories{};
	};
}

// --------------------------------------------------------

template <typename T>
std::shared_ptr<T> aiva::layer1::ResourceSystem::GetResource(std::filesystem::path const& fileName)
{
	aiva::utils::Asserts::CheckBool(!fileName.empty());

	std::shared_ptr<aiva::layer1::ICpuResource> const basicResource = GetResource(fileName);
	aiva::utils::Asserts::CheckBool(basicResource);

	std::shared_ptr<T> const specificResource = std::dynamic_pointer_cast<T>(basicResource);
	aiva::utils::Asserts::CheckBool(specificResource);

	return specificResource;
}

template <typename T>
void aiva::layer1::ResourceSystem::RegisterFactory(std::filesystem::path const& extension)
{
	aiva::utils::Asserts::CheckBool(!extension.empty());
	mFactories.insert_or_assign(extension, &T::Create<aiva::layer1::Engine const&>);
}
