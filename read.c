#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage ./read <input file> ie: ./read file.txt\n");
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
            while((ch = fgetc(input)) != EOF)
            {
                printf("%c", ch);
            }
            printf("\n");
            fclose(input);
        }
    }
}
