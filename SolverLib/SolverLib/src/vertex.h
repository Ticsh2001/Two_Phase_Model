#pragma once
#include "types.h"

template <typename T>
struct vertex
{
	T x, y, z;

	vertex() :x(0.0), y(0.0), z(0.0) {}
	vertex(T _xyz) :x(_xyz), y(_xyz), z(_xyz) {}
	vertex(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {}
	vertex(T _x, T _y) :x(_x), y(_y), z(0.0) {}
	vertex(const vertex<T>& vert) :x(vert.x), y(vert.y), z(vert.z) {}

	vertex<T> operator = (const vertex<T> &vert) { x = vert.x; y = vert.y; z = vert.z; return *this; }
	bool operator == (const vertex<T> &vert)
	{
		if ((is_equal<T>(vert.x, x)) && (is_equal<T>(vert.x, x)) && (is_equal<T>(vert.x, x))) return true;
		else return false;
	}
	bool operator != (const vertex<T> &vert)
	{
		if ((!is_equal<T>(vert.x, x)) || (!is_equal<T>(vert.x, x)) || (!is_equal<T>(vert.x, x))) return true;
		else return false;
	}

	T operator [] (uint32 i)
	{
		if (i == 0) return x;
		if (i == 1) return y;
		if (i == 2) return z;
		return 0.0;
	}
};

//template <typename T>
//using vertex_v = std::vector<vertex<T>>;
