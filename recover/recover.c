#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Can't read %s\n", argv[1]);
        return 1;
    }

    int jpgNumber = 0;

    char *jpgName = malloc(8);

    FILE *jpg;

    BYTE *buffer = malloc(BLOCK_SIZE);

    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            if (jpgNumber != 0)
            {
                fclose(jpg);
            }
            sprintf(jpgName, "%.3i.jpg", jpgNumber);
            jpg = fopen(jpgName, "w");
            jpgNumber++;
            fwrite(buffer, 1, BLOCK_SIZE, jpg);
        }
        else if (jpgNumber != 0)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpg);
        }
    }
    free(buffer);
    free(jpgName);
    fclose(card);
    fclose(jpg);
}
