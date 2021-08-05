#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 2)
        {
            printf("Usage ./read <input file> ie: ./read input.txt");
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
            while((ch = fgetc(ptr)) != EOF)
            {
                printf("%c", ch);
            }
            printf("\n");
            fclose(ptr);
        }
    }
}
