#include <stdio.h>
#include "File.h"
#include "String.h"
#include "Lexer.h"
#include "Precompiled.h"
#include <string>

static const char* TokenNames[] = {
	"TokenEndOfFile",
	"TokenDefinition",
	"TokenExtern",
	"TokenIdentifier",
	"TokenNumber"
};

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
	if (m_file)
		delete m_file;
}

static std::string kIdentifierString;

const Token Lexer::GetToken()
{
	static char kLastCharacter = ' ';

	// Skip whitespace.
	while (isspace(kLastCharacter))
		kLastCharacter = m_file->ReadChar();

	if (isalpha(kLastCharacter)) {
		kIdentifierString = kLastCharacter;

		while (isalnum((kLastCharacter = m_file->ReadChar()))) {
			kIdentifierString += kLastCharacter;
		}

		if (kIdentifierString == "def") {
			return TokenDefinition;
		}
		else if (kIdentifierString == "extern") {
			return TokenExtern;
		}

		return TokenIdentifier;
	}

	if (kLastCharacter == EOF) {
		return TokenEndOfFile;
	}

	return (Token)0; 
}

void Lexer::Analyze(const String& filePath)
{
	printf("Analyzing file %s.\n", filePath.CString());

	File* file = new File(filePath, FILE_READ);

	assert(file && file->IsOpen());

	m_file = file;

	Token token = GetToken();
	
	while (token != TokenEndOfFile) {
		if (token == TokenIdentifier) {
			printf("Token: %s (%s).\n", TokenNames[abs(token) - 1], kIdentifierString.c_str());
		}
		else {
			printf("Token: %s.\n", TokenNames[abs(token) - 1]);
		}

		token = GetToken();
	}
}

/// TODO: Move this entry point.
#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char* argv[])
#endif
{
	Lexer lexer;
	lexer.Analyze("myscript2.lua");

	return 0;
}
