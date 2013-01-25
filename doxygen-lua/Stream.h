#pragma once

#include "String.h"

class Stream
{
public:
	Stream() {}

	virtual bool IsOpen() = 0;
	
	virtual void Write(const String& string) = 0;
};