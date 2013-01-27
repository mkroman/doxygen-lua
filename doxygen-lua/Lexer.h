#pragma once

#include "String.h"

class File;

enum Token
{
	TokenEndOfFile = -1,
	TokenDefinition = -2,
	TokenExtern = -3,
	TokenIdentifier = -4,
	TokenNumber = -5
};

class Lexer
{
public:
	Lexer();
	~Lexer();

	void Analyze(const String& filePath);

	const Token GetToken();

private:
	File* m_file;
};