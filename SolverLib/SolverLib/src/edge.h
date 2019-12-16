#pragma once
#include "plane.h"

template <typename T>
struct edge
{
	vertex<T> vert1;
	vertex<T> vert2;

	edge() :vert1(0.0, 0.0), vert2(1.0, 1.0) {}
	edge(const vertex<T> &_v1, const vertex<T> &_v2) :vert1(_v1), vert2(_v2) {}
	edge(T _x1, T _y1, T _z1, T _x2, T _y2, T _z2 : vert1(_x1, _y1, _z1), vert2(_x2, _y2, _z2){}

	const T length() const { return (vert2 - vert1).length(); }
	void flip() { auto temp = vert1; vert1 = vert2; vert2 = temp; }
	vector<T> get_vector() const { return vert2 - vert1; }
	vertex<T> get_vertex(T coord) { auto vec = vert2 - vert1; return vert1 + vec*coord);}

	bool is_on_plane(const plane<T> &pl)
	{
		if ((pl.is_vertex_on_plane(vert1)) && (pl.is_vertex_on_plane(vert2))) return true;
		else return false;
	}

	bool is_cross(const edge<T> &e)
	{
		
	}

	bool is_parallel(const edge<T> &e)
	{
		auto v1 = get_vector();
		auto v2 = e.get_vector();
		if (is_equal<T>(v2.cross(v1).length(), 0.0)) return true;
		else return false;
	}

public:
	static vertex<T> get_vertex(const vertex<T> &_vert1, const vertex<T> &_vert2, T coord)
	{
		edge temp(_vert1, vert2);
		return temp.get_vertex(coord);
	}

	static bool is_on_plane(const vertex<T> &vert1, const vertex<T> &vert2, const plane<T> &pl)
	{
		edge<T> temp(vert1, vert2);
		return temp.is_on_plane(pl);
	}

};