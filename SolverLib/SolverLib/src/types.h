#pragma once
#include <string>
#include <vector>
#include <array>
#include <limits>
#include <memory>

using uint32 = unsigned int;
using float32 = float;
using int32 = int;
using float64 = double;

enum class spatial_dimensions_type
{
	SOLVER_1D = 1,
	SOLVER_2D = 2,
	SOLVER_3D = 3
};

template<typename T>
bool is_equal(const T &x, const T &y)
{
	return std::abs(x - y) < std::numeric_limits<T>::epsilon();
}