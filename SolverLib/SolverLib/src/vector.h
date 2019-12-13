#pragma once
#include "vertex.h"
#include <cmath>


template <typename T>
struct vector
{
	T x, y, z;

	vector() :x(0.0), y(0.0), z(0.0) {}
	vector(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {}
	vector(const vertex<T> &vert1, const vertex<T> &vert2) :
		x(vert1.x - vert2.x), y(vert1.y - vert2.y), z(vert1.z - vert2.z) {}

	vector<T> operator = (const vector<T> &vec) { x = vec.x; y = vec.y; z = vec.z; return *this; }



	const T length() const { return std::pow(x*x + y*y + z*z, 0.5);}
	void make_unit() { auto l = length(); x = x / l; y = y / l; z = z / l; }
	vector<T> get_unit() const {return }

};