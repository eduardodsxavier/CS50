#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Can't read %s\n", argv[1]);
        return 1;
    }

    // Read header
    // TODO #3

    WAVHEADER header;

    fread(&header, 1, sizeof(header), input);

    // Use check_format to ensure WAV format
    // TODO #4
    if(check_format(header))
    {
        fclose(input);
        printf("file isn't a WAV\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fclose(input);
        printf("can't create a file with given name\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, 1, sizeof(header), output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blockSize = get_block_size(header);

    // Write reversed audio to file
    // TODO #8

    BYTE *buffer = malloc(blockSize);

    fseek(input, -blockSize, SEEK_END);
    while (ftell(input) != sizeof(WAVHEADER))
    {
        fread(buffer, 1, blockSize, input);
        fwrite(buffer, 1, blockSize, output);
        fseek(input, -(blockSize * 2), SEEK_CUR);
    }

    fclose(input);
    fclose(output);
    free(buffer);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }

    printf("file isn't a WAVE file\n");
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
}
