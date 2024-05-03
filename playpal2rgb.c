#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static const char* usage_message =
"Convert images from PLAYPAL to RGB8888 format\n"
"\n"
"Usage: playpal2rgb <palette>\n"
"\n"
"Reads image in PLAYPAL format from stdin\n"
"Writes image in RGB888 format to stdout\n"
"Palette file should be in RGBX8888 format\n"
"\n"
"For more information, visit https://github.com/guidanoli/playpal2rgb\n";

static int read_palette_from_file
(
        FILE* palette_file,
        uint8_t palette[256][3]
)
{
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int c = fgetc(palette_file);

            if (c == EOF)
            {
                fputs("Palette file is too small\n", stderr);
                return EXIT_FAILURE;
            }
            else
            {
                // Ignore every fourth byte
                if (j < 3)
                {
                    palette[i][j] = (uint8_t)c;
                }
            }
        }
    }

    if (fgetc(palette_file) != EOF)
    {
        fputs("Palette file is too big\n", stderr);
        return EXIT_FAILURE;
    }

    if (ferror(palette_file))
    {
        perror("Error reading palette file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

static int read_palette_from_filepath
(
    const char* palette_filepath,
    uint8_t palette[256][3]
)
{
    FILE* palette_file = fopen(palette_filepath, "rb");

    if (palette_file == NULL)
    {
        perror("Error opening palette file");
        return EXIT_FAILURE;
    }

    int ret = read_palette_from_file(palette_file, palette);

    fclose(palette_file);

    return ret;
}

static int apply_palette
(
    uint8_t const palette[256][3]
)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (putchar(palette[c][i]) == EOF)
            {
                perror("Error writing to output");
                return EXIT_FAILURE;
            }
        }
    }

    if (ferror(stdin))
    {
        perror("Error reading from input");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main
(
    int argc,
    const char* argv[]
)
{
    if (argc < 2)
    {
        fputs(usage_message, stderr);
        return EXIT_FAILURE;
    }

    uint8_t palette[256][3];

    int ret = read_palette_from_filepath(argv[1], palette);

    if (ret != EXIT_SUCCESS)
    {
        return ret;
    }

    return apply_palette(palette);
}
