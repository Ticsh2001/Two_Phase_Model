#pragma once
#include <type_traits>

#define REGISTER_REF_CONSTRUCTOR_BEGIN(class_name, ...) \
class_name(typename std::enable_if<is_ref,int>::type = 0>) \
{\

#define REGISTER_REF_CONSTRUCTOR_END }

#define REGISTER_CONSTRUCTOR_BEGIN(class_name, ...) \
class_name(typename std::enable_if<!is_ref,int>::type = 0>) \
{\

#define REGISTER_REF_CONSTRUCTOR_END }

template <typename T, bool is_ref>
struct object_spec
{
	using type = std::conditional<is_ref, std::add_lvalue_reference_t<T>, T>::type;
	constexpr bool is_ref_object() { return is_ref; }
};