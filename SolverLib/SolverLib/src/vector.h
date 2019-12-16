#pragma once
#include "vertex.h"
#include <cmath>


template <typename T>
struct vector
{
	T x, y, z;

	vector() :x(0.0), y(0.0), z(1.0) {}
	vector(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {}
	vector(const vertex<T> &vert1, const vertex<T> &vert2) :
		x(vert2.x - vert1.x), y(vert2.y - vert1.y), z(vert2.z - vert1.z) {}
	vector(const vector<T> &vec) :x(vec.x), y(vec.y), z(vec.z) {}

	vector<T> operator = (const vector<T> &vec) { x = vec.x; y = vec.y; z = vec.z; return *this; }
	vector<T> operator * (const T &val)
	{
		vector<T> vec;
		vec.x = x*val;
		vec.y = y*val;
		vec.z = z*val;
		return vec;
	}

	vertex<T> operator + (const vertex<T> &vert)
	{
		return vertex(vert.x + x, vert.y + y, vert.z + z);
	}
	
	const T length() const { return std::pow(x*x + y*y + z*z, 0.5);}
	const T dot(const vector<T> &vec) const { return x*vec.x + y*vec.y + z*vec.z; }
	vector<T> cross(const vector<T> &vec) const { return vector<T>(y*vec.z - z*vec.y, vec.x*z - x*vec.z, x*vec.y - vec.x*y); }
	
	void make_unit() { auto l = length(); x = x / l; y = y / l; z = z / l; }
	vector<T> get_unit() const { vector<T> vec = *this; vec.make_unit(); return vec; }
	void flip() { *this = *this*(-1); }
	vector<T> get_flip() { vector<T> vec = *this; vec.flip(); return vec; }

	bool is_parallel(const vector<T> &vec) { return is_equal<T>(this->cross(vec).length(), 0.0); }


};

template <typename T>
vector<T> operator - (const vertex<T> &vert1, const vertex<T> &vert2) { return vector(vert1, vert2); }
