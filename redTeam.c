#include "redTeam.h"


/* ----------------------------------------------------- Helper methods ---------------------------------------------------- */


char* copyFileContentToBuffer(const char* path, char* buffer)
{
	// Temporary pointer for iteration (buffer remain original, pCTemp can be changed)
	char* pCTemp = buffer;
	// Variable to store each character
	char fileCharacter;
	FILE* fileToRead = fopen(path, "r");

	if (fileToRead == NULL)
	{
		// Failed to open the file
		printf("Failed to open file.\n");
		return NULL;
	}
	// Read the file character by character
	while (true)
	{
		// Getting every single character from the opened file
		fileCharacter = fgetc(fileToRead);
		// If it is EOF stop reading.
		// Not displaying the end of file representation value
		if (fileCharacter == EOF)
		{
			break;
		}
		*pCTemp = fileCharacter;
		pCTemp++;
	}
	// Remove trailing newlines if they exist
	if (pCTemp != buffer) {
		if (*(pCTemp - 1) == '\n' || *(pCTemp - 1) == '\r') {
			pCTemp--;
		}
	}
	// Null-terminate the buffer
	*pCTemp = '\0';

	// Close the opened file
	fclose(fileToRead);
	// The pointer is turned into a null pointer
	fileToRead = NULL;
	return buffer;
}


bool isValidFileType(const char* usersFile)
{
	// Find the last dot in the string

	char isDot = '.';
	char* dot = strrchr(usersFile, isDot);
	if (dot && dot != usersFile)
		/*
		if there is a dot in the string , we will be entering the if condition
		if the usersFile name is empty or it only includes '.' we wont be entering the if condition
		*/
	{
		// If there is a dot in the string, and it's not the first character
		char* extension = dot + 1;
		if (strcmp(extension, "txt") == 0 || strcmp(extension, "log") == 0 || strcmp(extension, "TXT") == 0 || strcmp(extension, "LOG") == 0)
		{
			return true;
		}
	}
	return false;
}


bool isAbsolutePath(const char* path) {
	if (path == NULL) {
		return false;
	}

	// Check for Unix-like absolute paths (starting with '/' "Root")
	if (path[0] == '/') {
		return true;
	}

	// Check for Windows absolute paths (e.g., "C:\\", "C:/")
	if (strlen(path) > 1 && ((path[1] == ':') && (path[2] == '\\' || path[2] == '/'))) {
		return true;
	}

	return false;
}


size_t getFileLength(const char* filePath)
{

	FILE* file = fopen(filePath, "r");
	if (file == NULL)
	{
		// Return 0 if file cannot be opened
		return 0;
	}
	// Initialize length to 0 - default value
	size_t length = 0;

	// move file pointer to end of file and check if fseek worked
	if (fseek(file, 0, SEEK_END) == 0)
	{
		length = ftell(file); // update length only if fseek worked
	}

	fclose(file); // close the file

	return length;
}


char* allocateMemory(size_t size)
{
	char* memory = (char*)malloc(size * sizeof(char));
	if (memory == NULL)
	{
		// If allocation fails return NULL
		return NULL;
	}
	// Return pointer to allocated memory
	return memory;
}


/* ----------------------------------------------------- Main methods ---------------------------------------------------- */


char* fileContentToString(const char* path)
{
	// Validate path type - check if path is absolute
	if (!isAbsolutePath(path))
	{
		printf("Path is not absolute.\n");
		return NULL;
	}
	// Validate file type
	if (!isValidFileType(path))
	{
		printf("Invalid file type.\n");
		return NULL;
	}
	// Get the file length
	size_t fileLength = getFileLength(path);

	if (fileLength == 0)
	{
		printf("Failed to get file size or file is empty.\n");
		return NULL;
	}
	// Allocate memory for file content Plus one for null terminator - 
	// This is reading from file content so need to insert at the end null terminator.
	char* pCBuffer = allocateMemory(fileLength + 1);
	if (pCBuffer == NULL)
	{
		printf("Memory allocation failed.\n");
		return NULL;
	}

	// Read file content into buffer - put all characters to buffer string
	if (copyFileContentToBuffer(path, pCBuffer) == NULL)
	{
		printf("Failed to read file content.\n");
		return NULL; // Failed to copy file content
	}
	return pCBuffer;
}
