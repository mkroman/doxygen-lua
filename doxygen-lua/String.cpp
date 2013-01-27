#include "String.h"

String::String() :
	m_buffer(NULL),
	m_length(0)
{
}

String::String(size_t length) :
	m_buffer(NULL),
	m_length(0)
{
	size_t newLength = Allocate(length);
	assert(newLength > 0);
}

String::String(const char* source) :
	m_buffer(NULL),
	m_length(0)
{
	size_t length = strlen(source) + 1;

	if (length > 0) {
		size_t allocatedLength = Allocate(length);
		assert(allocatedLength == length);

		m_buffer[allocatedLength] = 0;
	}

	strncpy(m_buffer, source, length);
}

String::~String()
{
	if (m_buffer)
	 	free(m_buffer);
}

bool String::Resize(size_t newLength)
{
	size_t allocatedLength = Allocate(newLength, m_buffer);

	return (allocatedLength > 0);
}

size_t String::Allocate(size_t length, void* base)
{
	void* pointer = realloc(base, length);

	if (pointer != NULL) {
		m_buffer = reinterpret_cast<char*>(pointer);
		m_length = length;

		return length;
	}
	else
		return 0;
}

const size_t String::Length() const
{
	return m_length;
}

const char* String::CString() const
{
	return m_buffer;
}

bool String::IsEmpty() const
{
	return (m_length == 0);
}