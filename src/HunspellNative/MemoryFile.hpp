#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <mbctype.h>
#include <string>

#include <windows.h>
#include "NHunspellExtensions.h"

// FILE Replacements to work with memory instead
const unsigned long magicConstant = 0xFE0FF07F;

struct MemoryBufferInformation
{
	unsigned long magic; // Trapping misconfigured FILE * replacements by checking magic number
	void* buffer;
	size_t bufferSize;
};


class MemoryFileManager
{
	void * zero;
	unsigned long magic;
	char * buffer;
	size_t bufferSize;
	size_t currentPos;
public:
	MemoryFileManager(const MemoryBufferInformation* info);
	char* GetString(char* str, int strBufferSize);
};


FILE* fopenMemory(const char* filename, const char* mode);
int fcloseMemory(FILE* stream);
char* fgetsMemory(char* str, int n, FILE* stream);

