#include <pch.h>
#include <aiva/layer1/e_gpu_comparison_func.h>

#include <aiva/utils/asserts.h>

aiva::layer1::EGpuComparisonFunc aiva::layer1::FromInternalEnum(D3D12_COMPARISON_FUNC const comparisonFunc)
{
	switch (comparisonFunc)
	{
	case D3D12_COMPARISON_FUNC_NEVER:
		return EGpuComparisonFunc::Never;

	case D3D12_COMPARISON_FUNC_LESS:
		return EGpuComparisonFunc::Less;

	case D3D12_COMPARISON_FUNC_EQUAL:
		return EGpuComparisonFunc::Equal;

	case D3D12_COMPARISON_FUNC_LESS_EQUAL:
		return EGpuComparisonFunc::LessEqual;

	case D3D12_COMPARISON_FUNC_GREATER:
		return EGpuComparisonFunc::Greater;

	case D3D12_COMPARISON_FUNC_NOT_EQUAL:
		return EGpuComparisonFunc::NotEqual;

	case D3D12_COMPARISON_FUNC_GREATER_EQUAL:
		return EGpuComparisonFunc::GreaterEqual;

	case D3D12_COMPARISON_FUNC_ALWAYS:
		return EGpuComparisonFunc::Always;

	default:
		aiva::utils::Asserts::CheckBool(false);
		return {};
	}
}

D3D12_COMPARISON_FUNC aiva::layer1::ToInternalEnum(EGpuComparisonFunc const comparisonFunc)
{
	switch (comparisonFunc)
	{
	case EGpuComparisonFunc::Never:
		return D3D12_COMPARISON_FUNC_NEVER;

	case EGpuComparisonFunc::Less:
		return D3D12_COMPARISON_FUNC_LESS;

	case EGpuComparisonFunc::Equal:
		return D3D12_COMPARISON_FUNC_EQUAL;

	case EGpuComparisonFunc::LessEqual:
		return D3D12_COMPARISON_FUNC_LESS_EQUAL;

	case EGpuComparisonFunc::Greater:
		return D3D12_COMPARISON_FUNC_GREATER;

	case EGpuComparisonFunc::NotEqual:
		return D3D12_COMPARISON_FUNC_NOT_EQUAL;

	case EGpuComparisonFunc::GreaterEqual:
		return D3D12_COMPARISON_FUNC_GREATER_EQUAL;

	case EGpuComparisonFunc::Always:
		return D3D12_COMPARISON_FUNC_ALWAYS;

	default:
		aiva::utils::Asserts::CheckBool(false);
		return {};
	}
}
