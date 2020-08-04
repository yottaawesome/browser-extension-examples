#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include "ProcessMessage.hpp"

// Define union to read the message size easily
typedef union {
	unsigned long u32;
	unsigned char u8[4];
} U32_U8;

int SetBinaryMode(FILE* file)
{
	int result;

	result = _setmode(_fileno(file), _O_BINARY);
	if (result == -1)
	{
		perror("Cannot set mode");
		return result;
	}
	// set do not use buffer
	result = setvbuf(file, NULL, _IONBF, 0);
	if (result != 0)
	{
		perror("Cannot set zero buffer");
		return result;
	}

	return 0;
}

int main(int argc, char** args)
{
    // Set "stdin" to have binary mode:
    // https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setmode?redirectedfrom=MSDN&view=vs-2019
	if (SetBinaryMode(stdin) != 0)
		return -1;
	if (SetBinaryMode(stdout) != 0)
		return -1;

	// The format of raw message received from the stdin
	// IIIISSSSS...SS
	// IIII is a 4bytes integer in binary format. It is the lenth of the following json message.
	// SSSSS...SS is the json message immidiatlly follows the 4 bytes header. 
	// Each message is serialized using JSON, UTF-8 encoded and is preceded with 32-bit message length in native byte order.
	// You can send message back to chromium plugin by writing the same formated IIIISSSSS...SS to stdout.

	size_t iSize = 0;
	U32_U8 lenBuf;
	lenBuf.u32 = 0;
	char* jsonMsg = NULL; // a json message encoded in utf-8 

	iSize = fread(lenBuf.u8, 1, 4, stdin);
	if (iSize == 4)
	{
		int iLen = (int)lenBuf.u32;
		// now read the message
		if (iLen > 0)
		{
			jsonMsg = (char*)malloc(8 * iLen);
			iSize = fread(jsonMsg, 1, iLen, stdin);

			// process message
			ProcessMessage(jsonMsg);

			// echo the message
			fwrite(lenBuf.u8, 1, 4, stdout);
			fwrite(jsonMsg, 1, iLen, stdout);
			fflush(stdout);
		}


		//uncomment it to debug the messaging 
		/*FILE* log = fopen("D:\\native.txt", "w");
		fwrite((void*)lenBuf.u8, 1, 4, log);
		fwrite(utf8Buffer, 1, iLen, log);
		fclose(log);*/

		std::wofstream m_outputFile;
		m_outputFile.open("log.txt", std::ios_base::app);
		m_outputFile << L"OK" << std::endl;

		// free resource
		if (jsonMsg != NULL)
			free(jsonMsg);
	}
}

