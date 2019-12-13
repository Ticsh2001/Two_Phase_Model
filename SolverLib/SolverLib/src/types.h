#pragma once
#include <string>
#include <vector>
#include <array>

using uint32 = unsigned int;
using float32 = float;
using int32 = int;
using float64 = double;

enum class spatial_dimensions_type
{
	SOLVER_1D = 1,
	SOLVER_2D = 2,
	SOLVER_3D = 3
}