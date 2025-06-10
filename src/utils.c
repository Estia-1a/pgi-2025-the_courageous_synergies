#include <estia-image.h>

#include "utils.h"
#include <stddef.h>
/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

 pixelRGB * get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y )
 {
    if( x>width || y>height)
        return NULL;

    if(data == NULL)
        return NULL;

    unsigned int i = (y * width + x) * n;

    return (pixelRGB *) &data[i] ;
 }