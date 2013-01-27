#pragma once

#include <cstring>
#include <cstdlib>
#include <cassert>

/// %String class.
class String
{
public:
	/// Construct empty string.
	String();

	/// Construct with allocated memory.
	String(size_t length);

	/// Construct from a C string.
	String(const char* source);

	/// Destruct.
	~String();

	/// Resize the string.
	bool Resize(size_t newLength);

	/// Return length of the string.
	const size_t Length() const;

	/// Return a const pointer to the buffer.
	const char* CString() const;

	/// Return whether the string is empty or not.
	bool IsEmpty() const;

	// Operators.

	/// Return char at index.
	char& operator [] (unsigned index)
	{
		assert(index < m_length);

		return m_buffer[index];
	}

protected:
	/// Allocate memory for the buffer.
	/// @returns New length.
	size_t Allocate(size_t length, void* base = NULL);

private:
	char* m_buffer;
	size_t m_length;
};