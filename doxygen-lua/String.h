#pragma once

#include <cstring>
#include <cstdlib>

class String
{
public:
	String();
	String(const char* source);
	~String();

	const size_t Length() const;
	const char* CString() const;

protected:
	size_t Allocate(size_t size);

private:
	char* m_data;
	size_t m_size;
};