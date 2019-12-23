#pragma once
#include "plane.h"
#include <tuple>
#include <type_traits>

template <typename T, bool is_ref>
class base_polygon
{
public:
	using vertex_type = std::conditional<is_ref, std::add_lvalue_reference_t<vertex<T>>, vertex<T>>::type;
protected:
	std::vector<vertex_type> verteces;
	T area;



};

template <typename T>
using polygon = base_polygon<T, false>;
template <typename T>
using polygon_r = base_polygon<T, true>;



template <typename T>
struct triangle_iterator
{

};


template <typename T>
class polygon
{
protected:
	std::vector<vertex<T>> verteces;
	plane<T> pl;
	T area;
protected:
	void recompute_area();
public:
	polygon();
public:
	bool append(const vertex<T> &vert);

public:
	std::tuple<bool,polygon<T>> get_triangle(uint32 index);

	

};

template<typename T>
inline void polygon<T>::recompute_area()
{
	uint32 triangle_index = 0;
}

template<typename T>
inline bool polygon<T>::append(const vertex<T>& vert)
{
	line<T> l(verteces.front(), verteces.back());
	if ((pl.is_vertex_on_plane(vert)) && (!l.is_vertex_on_line(vert)))
	{
		verteces.push_back(vert);
	}
	else return false;
}

template<typename T>
inline std::tuple<bool, polygon<T>> polygon<T>::get_triangle(uint32 index)
{
	if (verteces.size() == 3) return { true, *this };
	else
	{
		if (index < verteces.size() - 2) return { true, polygon<T>(verteces[0],verteces[index + 1],verteces[index + 2] };
		else return { false, polygon<T>() };
	}
}
