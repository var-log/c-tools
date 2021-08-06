#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Usage ./move <input file> <output destination> ie: ./move /home/user/docs/file.txt /home/user/file.txt\n");
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
        remove(argv[1]);
    }
}
