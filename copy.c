#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage ./copy <input file> <output file> ie: ./copy input.txt copy.txt\n");
    }
    else
    {
        FILE* input = fopen(argv[1], "r");
        if (input == NULL)
        {
            printf("File not found.\n");
        }
        else
        {
            char ch;
            FILE* output = fopen(argv[2], "w");
            while((ch = fgetc(input)) != EOF)
            {
                fputc(ch, output);
            }
            fclose(input);
            fclose(output);
        }
    }
}
