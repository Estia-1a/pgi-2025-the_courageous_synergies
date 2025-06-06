#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    printf("Width : %d, Height : %d\n", width, height);

    return;
}

void first_pixel (char *source_path)
{
    
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    
    int r = (int)data[0];
    int g = (int)data[1];
    int b = (int)data[2];
    
    printf("%d %d %d\n", r, g, b);
    
    return;
}

void tenth_pixel (char *source_path)
{
    int width =0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (width * height <= 10) {
        printf("Image is too small. Please provide a bigger image\n");
        return;
    }

    int r = (int)data[3*10-3];
    int g = (int)data[3*10-2];
    int b = (int)data[3*10-1];
    printf("tenth_pixel: %d %d %d\n", r, g, b);
    return;
}