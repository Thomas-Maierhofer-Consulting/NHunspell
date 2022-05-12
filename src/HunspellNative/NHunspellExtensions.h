#pragma once





FILE * fopenMemory ( const char * filename, const char * mode );
int fcloseMemory ( FILE * stream );
char *fgetsMemory(char *str, int n, FILE *stream);

#define fopen( filename, mode ) fopenMemory(filename, mode)
#define fclose( stream ) fcloseMemory(stream)
#define fgets( str, n, stream) fgetsMemory( str, n, stream )