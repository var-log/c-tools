#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage ./create <input file> ie: ./create input.txt\n");
    }
    else
    {
        FILE* ptr = fopen(argv[1], "w");
        fclose(ptr);
    }
}