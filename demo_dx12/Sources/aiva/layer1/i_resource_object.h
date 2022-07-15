#pragma once
#include <pch.h>

namespace aiva::layer1
{
	struct Engine;
}

namespace aiva::layer1
{
	struct IResourceObject
	{
	public:
		virtual ~IResourceObject() = default;
		virtual void Deserealize(aiva::layer1::Engine const& engine, std::vector<std::byte> const& binaryData) = 0;
	};
}