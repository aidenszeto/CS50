#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
typedef uint8_t BYTE;

bool is_jpg (BYTE arr[]);

int main(int argc, char *argv[])
{

    // Check if a filename is provided
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open and check file for errors
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    // Create filename, output pointer, buffer, and jpgCount
    char filename[8];
    FILE *output = NULL;
    BYTE buffer[512];
    int jpgCount = 0;

    // Cycle through memory, locate jpgs, write jpgs to new files
    while(fread(buffer, sizeof(BYTE), 512, input) || feof(input) == 0)
    {
        if (is_jpg(buffer))
        {
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(filename, "%03i.jpg", jpgCount);
            output = fopen(filename, "w");
            jpgCount++;
        }
        if (output != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, output);
        }
    }

    if (input != NULL)
    {
        fclose(input);
    }
    if (output != NULL)
    {
        fclose(output);
    }
}

// Function for checking jpg
bool is_jpg (BYTE arr[])
{
    return (arr[0] == 0xff) && (arr[1] == 0xd8) && (arr[2] == 0xff) && ((arr[3] & 0xf0) == 0xe0);
}
