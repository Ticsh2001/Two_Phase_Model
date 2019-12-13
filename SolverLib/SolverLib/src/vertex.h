#pragma once
#include "types.h"

template <typename T>
struct vertex
{
	T x, y, z;

	vertex() :x(0.0), y(0.0), z(0.0) {}
	vertex(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {}
};

//template <typename T>
//using vertex_v = std::vector<vertex<T>>;
