#pragma once
#include "types.h"

class IObject
{
public:
	virtual std::string get_name() = 0;
	virtual std::string get_desc() = 0;
	virtual bool is_init() = 0;
	virtual bool has_interface() = 0;
	virtual bool is_updated() = 0;
	virtual void update() = 0;
};