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

	bool is_intersec(const line<T> &l)
	{
		return ((is_on_plane(l)) && (!is_coliniar(l)));
	}

	bool is_match(const line<T> &l)
	{
		return ((!is_parallel(l)) && (is_coliniar(l)));
	}

	bool get_intersec(const line<T> &l, vertex<T> &vert)
	{
		if (is_intersec(l))
		{
			vector<T> v1 = l.vert - vert;
			auto cross_p = v1.cross(vec);
			auto h = cross_p.length()/
		}
		else return false;
	}
};