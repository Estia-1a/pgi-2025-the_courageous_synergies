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

    printf("dimension: %d, %d\n", width, height);

    return;
}

void first_pixel(char *source_path)
{
    
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    
    int r = (int)data[0];
    int g = (int)data[1];
    int b = (int)data[2];
    
    printf("first_pixel: %d, %d, %d\n", r, g, b);
    
    return;
}

void tenth_pixel(char *source_path)
{
    int width = 0;
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
    printf("tenth_pixel: %d, %d, %d\n", r, g, b);
    return;
}

void second_line (char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width,&height, &channel_count);
    if (height<2) {
        printf("Image should be at least 2 pixels in height\n");
        return;
    }

    int r= (int)data[3*width+0];
    int g= (int)data[3*width+1];
    int b= (int)data[3*width+2];
    printf("second_line: %d, %d, %d\n",r,g,b);
    return;
}

void print_pixel(char *source_path, int x, int y)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    if (width * height <= x*y) {
        printf("Image is too small. Please provide a bigger image\n");
        return;
    }
    pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

    int r = pixel->R;
    int g = pixel->G;
    int b = pixel->B;
    printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, r, g, b);

    free_image_data(data);

    return;
}

void color_red(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int i;
    for(i=0; i<width*height*3; i=i+3)
    {
        data[i+1] = 0;
        data[i+2] = 0;
    }

    write_image_data("image_out.bmp", data, width, height);

    return;
}

void color_green(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int i;
    for(i=0; i<width*height*3; i=i+3)
    {
        data[i] = 0;
        data[i+2] = 0;
    }

    write_image_data("image_out.bmp", data, width, height);

    return;
}

void color_blue(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int i;
    for(i=0; i<width*height*3; i=i+3)
    {
        data[i] = 0;
        data[i+1] = 0;
    }

    write_image_data("image_out.bmp", data, width, height);

    return;
}
    
