#pragma once
#include <pch.h>

#include <aiva/layer1/e_gpu_resource_buffer_format.h>
#include <aiva/layer1/e_gpu_resource_memory_type.h>

namespace aiva::layer1
{
	struct GrTexture2DDesc final
	{
	// ----------------------------------------------------
	// Constructors

	public:
		GrTexture2DDesc();

		GrTexture2DDesc(winrt::com_ptr<ID3D12Resource> const& resource);

	// ----------------------------------------------------
	// Data Layout

	public:
		EGpuResourceBufferFormat BufferFormat{};

		std::uint64_t Width{};

		std::uint64_t Height{};

	// ----------------------------------------------------
	// Features

	public:
		bool SupportDepthStencil{};

		bool SupportMipMapping{};

		bool SupportRenderTarget{};

		bool SupportShaderAtomics{};

		bool SupportUnorderedAccess{};
	};
}
