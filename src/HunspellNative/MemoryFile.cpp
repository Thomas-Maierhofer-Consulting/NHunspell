
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <mbctype.h>

#include <windows.h>
#include "MemoryFile.hpp"
#include "NHunspellExtensions.h"


MemoryFileManager::MemoryFileManager(const MemoryBufferInformation * info )
{
	zero = 0;
	magic = magicConstant;
	buffer = static_cast<char*>(info->buffer);
	bufferSize = info->bufferSize;
	currentPos = 0;
}

char * MemoryFileManager::GetString(char * str, int strBufferSize )
{
	if( currentPos >= bufferSize )
		return 0;

	size_t stringPos = 0;

	while( stringPos < (strBufferSize -1) && currentPos < bufferSize )
	{
		char currentChar = buffer[currentPos];
		str[stringPos] = currentChar;
		++stringPos;
		++currentPos;
		if( currentChar == '\n' )
			break;
	}
	str[stringPos] = 0;

	return str; 
}

FILE * fopenMemory ( const char * filename, const char * mode )
{
	MemoryBufferInformation * info = (MemoryBufferInformation * ) filename;

	if( info->magic != magicConstant ) // must be a correct initialized memory buffer;
		return 0;
	return (FILE *) new MemoryFileManager(info);
}

int fcloseMemory ( FILE * stream )
{
	MemoryFileManager * manager = (MemoryFileManager *) stream;
	delete manager;
	return 0;
}

char *fgetsMemory(char * str, int n, FILE *stream)
{
	MemoryFileManager * manager = (MemoryFileManager *) stream;
	return manager->GetString( str, n);
}
