#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage ./create <file> ie: ./create newfile.txt\n");
    }
    else
    {
        FILE* output = fopen(argv[1], "w");
        fclose(output);
    }
}
