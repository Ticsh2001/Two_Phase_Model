#pragma once
#include "node.h"
#include "edge.h"

enum class face_geometry_type
{
	SOLVER_FACE_POINT = 0,
	SOLVER_FACE_LINE,
	SOLVER_FACE_TRIANGLE,
	SOLVER_FACE_QUAD,
	SOLVER_FACE_UNKNOWN
};

enum class face_type
{
	SOLVER_FACE_FLUID = 0,
	SOLVER_FACE_PRESSURE_INLET,
	SOLVER_FACE_PRESSURE_OUTLET,
	SOLVER_FACE_WALL
};



template<typename T>
struct face
{
	std::vector<uint32> nodes_list;
	std::array<int32, 2> cells_list;
	face_type type;

	spatial_dimensions_type get_dimension()
	{
		if (nodes_list.size() == 1) return spatial_dimensions_type::SOLVER_1D;
		if (nodes_list.size() == 2) return spatial_dimensions_type::SOLVER_2D;
		if (nodes_list.size() > 2) return spatial_dimensions_type::SOLVER_3D;
	}

	face_geometry_type get_geometry_type()
	{
		if (nodes_list.size() == 1) return face_geometry_type::SOLVER_FACE_POINT;
		if (nodes_list.size() == 2) return face_geometry_type::SOLVER_FACE_LINE;
		if (nodes_list.size() == 3) return face_geometry_type::SOLVER_FACE_TRIANGLE;
		if (nodes_list.size() == 4) return face_geometry_type::SOLVER_FACE_QUAD;
		if (nodes_list.size() > 4) return face_geometry_type::SOLVER_FACE_UNKNOWN;
	}



};