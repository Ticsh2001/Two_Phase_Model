#pragma once
#include <type_traits>

template <typename T, bool is_ref>
struct object_spec
{
	using type = std::conditional<is_ref, std::add_lvalue_reference_t<T>, T>::type;
	constexpr bool is_ref_object() { return is_ref; }
};