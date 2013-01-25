#include <stdio.h>
#include "File.h"
#include "String.h"
#include "Lexer.h"
#include "Precompiled.h"

Lexer::Lexer()
{
}

Lexer::~Lexer()
{

}

/// TODO: Move this entry point.
#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char* argv[])
#endif
{
	printf("hest\r\n");

	// File file;

	return 0;
}
