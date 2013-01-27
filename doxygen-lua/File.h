#pragma once

#include <cstdio>
#include "Stream.h"
#include "String.h"

typedef FILE* FileHandle;
typedef long int FileSize;

enum FileMode
{
	FILE_READ = 0,
	FILE_WRITE,
	FILE_READWRITE
};

class File : public Stream
{
public:
	File();
	File(FileHandle file);
	File(const String& path, FileMode mode = FILE_READ);
	~File();

	bool IsOpen();

	bool Open(const String& path, FileMode mode = FILE_READ);
	bool Close();

	void Write(const String& string);
	void Read(char* buffer, size_t length);

	const char ReadChar();
	const String ReadFileID();

private:
	void GetFileSize();

	FileSize m_size;
	FileHandle m_handle;
};