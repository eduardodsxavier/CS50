// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    int8_t array[HEADER_SIZE];

    int sizeofint8_t = sizeof(int8_t);

    fread(array, sizeofint8_t, HEADER_SIZE, input);
    fwrite(array, sizeofint8_t, HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    int16_t bufferFactor;

    int sizeOfint16_t = sizeof(int16_t);


    while ((fread(&buffer, sizeOfint16_t, 1, input)) == 1)
    {
        bufferFactor = buffer * factor;

        fwrite(&bufferFactor, sizeOfint16_t, 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
