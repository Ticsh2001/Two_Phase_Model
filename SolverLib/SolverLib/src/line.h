#pragma once
#include "vector.h"

template <typename T>
struct plane;

template <typename T>
struct line
{
	vertex<T> vert;
	vector<T> vec;

	line() :vert(), vec() {}
	line(const vertex<T> &_vert, const vector<T> &_vec) :vert(_vert), vec(_vec) {vec.make_unit()}
	line(const vertex<T> &vert1, const vertex<T> &vert2) :vert(vert1), vec(vert1, vert2) {vec.make_unit()}
	line(const line<T> &l) :vert(l.vert), vec(l.vec) {}

	bool is_on_plane(const line<T> &l)
	{
		v = vert - l.vert;
		auto val = v.dot(vec.cross(l.vec));
		if (is_equal<T>(val, 0.0)) return true;
		else return false;
	}

	bool is_coliniar(const line<T> &l)
	{
		return vec.is_parallel(l.vec);
	}

	bool is_parallel(const line<T> &l)
	{
		return ((vec.is_parallel(l.vec))&&(!(vert-l.vert).is_parallel(vec)))

	}
};