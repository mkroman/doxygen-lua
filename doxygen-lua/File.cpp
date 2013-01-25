#include "File.h"

static const char* openMode[] = {
	"rb",
	"wb",
	"w+b"
};

File::File() :
	m_size(-1L),
	m_handle(0)
{	
}

File::File(FileHandle handle) :
	m_size(-1L),
	m_handle(handle)
{
	GetFileSize();
}

File::File(const String& path, FileMode mode) :
	m_size(-1L),
	m_handle(0)
{
	Open(path, mode);
}

File::~File()
{
	Close();
}

bool File::IsOpen()
{
	return m_handle && !feof(m_handle);
}

bool File::Open(const String& path, FileMode mode)
{
	m_handle = fopen(path.CString(), openMode[mode]);

	if (m_handle) {
		GetFileSize();
		return true;
	}
	else {
		return false;
	}
}

bool File::Close()
{
	return fclose(m_handle) == 0;
}

void File::Write(const String& string)
{
	if (IsOpen()) {
		size_t size = fwrite(string.CString(), sizeof(char), string.Length(), m_handle);

		if (size != string.Length()) {
			printf("File::Write() something went wrong.\n");
		}
	}
}

void File::GetFileSize()
{
	if (m_handle) {
		fseek(m_handle, 0, SEEK_END);

		m_size = ftell(m_handle);

		fseek(m_handle, 0, SEEK_SET);
	}
}