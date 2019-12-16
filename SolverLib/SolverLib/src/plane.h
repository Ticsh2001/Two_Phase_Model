#pragma once
#include "vector.h"

template <typename T>
struct plane
{
	vertex<T> vert;
	vector<T> normal;

	plane() :vert(), normal() {}
	plane(const vertex<T> &_vert, const vector<T> &_normal) : vert(_vert), normal(_normal) { normal.make_unit(); }
	plane(const vertex<T> &vert1, const vertex<T> &vert2, const vertex<T> &vert3):vert(vert1)
	{
		auto vec1 = vert2 - vert1;
		auto vec2 = vert3 - vert1;
		normal = vec1.cross(vec2);
		normal.make_unit();
	}
	plane(const plane<T> &pl) :vert(pl.vert), normal(pl.normal) {}

	bool is_vertex_on_plane(const vertex<T> &_vert)
	{
		auto vec = _vert - vert;
		if (is_equal<T>(vec.dot(normal), 0.0)) return true;
		else return false;
	}

public:
	static bool is_vertex_on_plane(const vertex<T> &_vert, const vector<T> &_normal, const vertex<T> &_vert)
	{
		plane<T> pl(vert,normal);
		return pl.is_vertex_on_plane(_vert);
	}

	static bool is_vertex_on_plane(const vertex<T> &vert1, const vertex<T> &vert2, const vertex<T> &vert3, const vertex<T> &_vert)
	{
		plane<T> pl(vert1, vert2, vert3, normal);
		return pl.is_vertex_on_plane(_vert);
	}
	
};