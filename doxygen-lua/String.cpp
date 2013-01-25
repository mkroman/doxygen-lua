#include "String.h"

String::String() :
	m_data(NULL),
	m_size(0)
{
}

String::String(const char* source) :
	m_data(NULL),
	m_size(0)
{
	size_t size = strlen(source) + 1;

	if (!m_data && size > 1) {
		if (!Allocate(size))
			return;
		else
			m_data[size] = '\0';
	}

	strncpy(m_data, source, size);
}

String::~String()
{
	// if (m_data)
	// 	free(m_data);
}

size_t String::Allocate(size_t size)
{
	void* pointer = malloc(size);

	if (pointer != NULL) {
		m_data = reinterpret_cast<char*>(pointer);
		m_size = size;

		return size;
	}
	else
		return 0;
}

const size_t String::Length() const
{
	return m_size - 1;
}

const char* String::CString() const
{
	return m_data;
}