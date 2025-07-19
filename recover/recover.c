#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char filename[8];
    int file_count = 0;

    // Read the memory card block by block
    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file if open
            if (img != NULL)
            {
                fclose(img);
            }

            // Open new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            file_count++;
        }

        // Write block to file if one is open
        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    // Cleanup
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(infile);
    return 0;
}
