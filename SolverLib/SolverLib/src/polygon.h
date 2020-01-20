#pragma once
#include "plane.h"
#include "edge.h"
#include <tuple>
#include <type_traits>

template <typename T>
class polygon
{
protected:
	std::vector<vertex<T>> verteces;
	vector<T> normal;
	T area;
protected:
	
protected:
	polygon(const std::vector<vertex<T>> &verts);
	polygon();
public:
	uint32 get_edges_num();
	edge<T> get_edge(uint32 i);
	std::vector<edge<T>> get_edges();
public:
	polygon(const polygon<T> &polygon);
public:
	static std::pair<bool, polygon<T>> create_polygon(const std::vector<vertex<T>> &verts);
	static std::tuple<bool, plane<T>> compute_polygon_plane(const std::vector<vertex<T>> &verts);
	static T compute_polygon_area(const std::vector<vertex<T>> &verts);
	static std::vector<std::array<vertex<T>, 3>> triangulate_polygon(const std::vector<T> &verts);
	

};

template<typename T>
inline std::pair<bool, polygon<T>> polygon<T>::create_polygon(const std::vector<vertex<T>>& verts)
{
	auto [is_plane, pl] = polygon::compute_polygon_plane(verts);
	if (is_plane) return std::make_pair<bool, polygon<T>>(true,polygon<T>(verts));
	else return std::make_pair<bool, polygon<T>>(false, polygon<T>());
}

template<typename T>
inline std::tuple<bool, plane<T>> polygon<T>::compute_polygon_plane(const std::vector<vertex<T>> &verts)
{
	bool res = true;
	plane<T> pl(verts[0], verts[1], verts[2]);
	if (!is_equal<T>(pl.normal.length(), 0.0))
	{
		if (verts.size() > 3)
		{
			for (i = 3; i < verts.size(); i++)
			{
				if (!pl.is_vertex_on_plane(verts[i])) res = false;
			}
		}
	}
	else res = false;
	return std::make_tuple<bool, plane<T>>(res, pl);

}

template<typename T>
inline T polygon<T>::compute_polygon_area(const std::vector<vertex<T>>& verts)
{
	T res = 0.0;
	auto triangles = polygon::triangulate_polygon(verts);
	for (auto &t : triangles)
	{
		auto vec1 = t[1] - t[0];
		auto vec2 = t[2] - t[0];
		res = res + vec1.cross(vec2).length()/2.0;
	}
	return res;
}

template<typename T>
inline std::vector<std::array<vertex<T>, 3>> polygon<T>::triangulate_polygon(const std::vector<T>& verts)
{
	auto verts_num = verts.size();
	uint32 triangles_num = verts_num - 2;
	std::vector<std::array<vertex<T>, 3>> res;
	res.reserve(triangles_num);
	for (i = 0; i < triangles_num; i++)
	{
		res.push_back({ verts[0],verts[i+1],verts[i+2]});
	}
	return res;
}

template<typename T>
inline polygon<T>::polygon(const std::vector<vertex<T>>& verts):verteces(verts)
{
	area = polygon::compute_polygon_area(verteces);
	normal = (verteces[1] - verteces[0]).cross(verteces[2] - verteces[0]).get_unit();
}

template<typename T>
inline polygon<T>::polygon()
{
	verteces.push_back(vertex<T>());
	verteces.push_back(vertex<T>());
	verteces.push_back(vertex<T>());
	normal = vector<T>();
}

template<typename T>
inline uint32 polygon<T>::get_edges_num()
{
	return verteces.size();
}

template<typename T>
inline edge<T> polygon<T>::get_edge(uint32 i)
{
	if (i < verteces.size() - 1) return edge<T>(verteces[i + 1], verteces[i]);
	if (i == verteces.size() - 1) return edge<T>(verteces.front(), verteces.back());
}

template<typename T>
inline std::vector<edge<T>> polygon<T>::get_edges()
{
	std::vector<edge<T>> res;
	res.reserve(get_edges_num());
	for (uint32 i = 0; i < get_edges_num(); i++) res.push_back(get_edge(i));
	return res;
}
