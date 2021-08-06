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
        FILE* ptr = fopen(argv[1], "r");
        if (ptr == NULL)
        {
            printf("File not found.\n");
        }
        else
        {
            char ch;
            FILE* ptr2 = fopen(argv[2], "w");
            while((ch = fgetc(ptr)) != EOF)
            {
                fputc(ch, ptr2);
            }
            fclose(ptr);
            fclose(ptr2);
        }
    }
}