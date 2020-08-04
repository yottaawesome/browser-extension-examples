#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>

int main(int argc, char** args)
{
    // Set "stdin" to have binary mode:
    // https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setmode?redirectedfrom=MSDN&view=vs-2019
    int result = _setmode(_fileno(stdin), _O_BINARY);
    if (result == -1)
        std::cout << "Cannot set stdin mode" << std::endl;
    else
        std::cout << "stdin successfully changed to binary mode\n" << std::endl;

    result = _setmode(_fileno(stdout), _O_BINARY);
    if (result == -1)
        std::cout << "Cannot set stdin mode" << std::endl;
    else
        std::cout << "stdout successfully changed to binary mode\n" << std::endl;

    return 0;
}

