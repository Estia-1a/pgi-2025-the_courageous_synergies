#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

    free_image_data(data);

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

    free_image_data(data);
    
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
    free_image_data(data);
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
    free_image_data(data);
    return;
}

void max_pixel(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    int somme=0;
	int x=0;
	int y=0;
	int x_max = 0;
	int y_max=0;
	int r;
	int g;
	int b;

    read_image_data(source_path, &data, &width, &height, &channel_count);

	pixelRGB *pixel_max;
	
    int somme_max = -1;
	for (y=0;y<height; y=y+1){
		for (x=0; x < width; x=x+1) {
			pixel_max=get_pixel(data, width, height, channel_count, x, y);
			
			somme= pixel_max->R + pixel_max->G + pixel_max->B ;
			
			if (somme > somme_max){
				somme_max=somme;
				r=pixel_max->R;
				g=pixel_max->G;
				b=pixel_max->B;
				x_max=x;
				y_max=y;
			} 
		}
	}
        
    printf("max_pixel (%d, %d): %d, %d, %d\n",x_max,y_max,r,g,b);
	
	free_image_data(data);
	return ;
}

void min_pixel (char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;
    int somme=0;
	int x=0;
	int y=0;
	int x_min = 0;
	int y_min=0;
	int r;
	int g;
	int b;

    read_image_data(source_path, &data, &width, &height, &channel_count);

	pixelRGB *pixel_min;
	
    int somme_min = 255*3+1;
	for (y=0;y<width; y=y+1){
		for (x=0; x < height; x=x+1) {
			pixel_min=get_pixel(data, width, height, channel_count, x, y);
			
			somme= pixel_min->R + pixel_min->G + pixel_min->B ;
			
			
			if (somme < somme_min){
				somme_min=somme;
				r=pixel_min->R;
				g=pixel_min->G;
				b=pixel_min->B;
				
				x_min=x;
				y_min=y;
				
			} 
		}
	}
        
    printf("min_pixel (%d,%d): %d, %d, %d\n",x_min,y_min,r,g,b);
	
	free_image_data(data);
	return ;
}

void max_component(char *source_path, unsigned char component)
{
    int width = 0;
    int height =0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    int max_r=0;
    int max_g=0;
    int max_b=0;
    int x,y,xr=0,yr=0,xg=0,yg=0,xb=0,yb=0;
    pixelRGB *setpixel;
    for (y=0; y<height; y++){
        for (x=0; x<width; x++){
            setpixel = get_pixel(data, width, height, channel_count, x, y);
            if (setpixel->R > max_r) {
                max_r = setpixel->R;
                xr = x;
                yr = y;

            }
            if (setpixel->G > max_g) {
                max_g = setpixel->G;
                xg = x;
                yg = y;
            }
            if (setpixel->B > max_b) {
                max_b = setpixel->B;
                xb=x;
                yb=y;
            }
    }
    }
    if (component == 'R'){
        printf("max_component R (%d, %d): %d\n", xr, yr, max_r);
    }
    if (component == 'G') {
        printf("max_component G (%d, %d): %d\n", xg, yg, max_g);
    }
    if (component == 'B') {
        printf("max_component B (%d, %d): %d\n", xb, yb, max_b);
    }
    free_image_data(data);
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

void min_component (char *source_path, unsigned char component)
{
    int width = 0;
    int height =0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int min_r=255;
    int min_g=255;
    int min_b=255;
    int x,y,xr=0,yr=0,xg=0,yg=0,xb=0,yb=0;
    pixelRGB *setpixel;
    for (y=0; y<height; y++){
        for (x=0; x<width; x++){
            setpixel = get_pixel(data, width, height, channel_count, x, y);
            if (setpixel->R < min_r) {
                min_r = setpixel->R;
                xr = x;
                yr = y;

            }
            if (setpixel->G < min_g) {
                min_g = setpixel->G;
                xg = x;
                yg = y;
            }
            if (setpixel->B < min_b) {
                min_b = setpixel->B;
                xb=x;
                yb=y;
            }
    }
    }
    if (component == 'R'){
        printf("min_component R (%d, %d): %d\n", xr, yr, min_r);
    }
    if (component == 'G') {
        printf("min_component G (%d, %d): %d\n", xg, yg, min_g);
    }  
    if (component == 'B') {
        printf("min_component B (%d, %d): %d\n", xb, yb, min_b);
    }
    free_image_data(data);
    return;
}

void stat_report(char *source_path)
{
    FILE *report = NULL;
    const char* report_path = "rapport.txt";
    report = freopen(report_path, "w",stdout);
    if (report == NULL) {
       printf("Erreur dans l'ouverture du fichier de rapport...\n");
    }
    
    max_pixel(source_path);
    min_pixel(source_path);
    max_component(source_path, 'R');
    max_component(source_path, 'G');
    max_component(source_path, 'B');
    min_component(source_path, 'R');
    min_component(source_path, 'G');
    min_component(source_path, 'B');

    fclose (report);
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
    free_image_data(data);
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
    free_image_data(data);
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
    free_image_data(data);
    return;
}

void color_invert(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int i;
    for(i=0; i<width*height*3; i++)
    {
        data[i] = 255-data[i];
    }

    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
    return;
}

void rotate_cw(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    unsigned char *new_data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    read_image_data(source_path, &new_data, &width, &height, &channel_count);

    int i;
    int j;
    for(j=0; j<height; j++)
    {
        for(i=0; i<width; i++)
        {
        new_data[(i*height + (height -1 -j))*channel_count] = data[(j*width + i)*channel_count];
        new_data[(i*height + (height -1 -j))*channel_count +1] = data[(j*width + i)*channel_count +1];
        new_data[(i*height + (height -1 -j))*channel_count +2] = data[(j*width + i)*channel_count +2];
        }
    }

    write_image_data("image_out.bmp", new_data, height, width);
    free_image_data(data);
    free_image_data(new_data);
    return;
}

void rotate_acw(char *source_path)
{
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;

    unsigned char *new_data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    read_image_data(source_path, &new_data, &width, &height, &channel_count);

    int i;
    int j;
    for(j=0; j<height; j++)
    {
        for(i=0; i<width; i++)
        {
        new_data[((width -1 -i)*height +j)*channel_count] = data[(j*width + i)*channel_count];
        new_data[((width -1 -i)*height +j)*channel_count +1] = data[(j*width + i)*channel_count +1];
        new_data[((width -1 -i)*height +j)*channel_count +2] = data[(j*width + i)*channel_count +2];
        }
    }

    write_image_data("image_out.bmp", new_data, height, width);
    free_image_data(data);
    free_image_data(new_data);
    return;
}

void color_gray(char *source_path){
 
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
   
    int i;
    for(i=0; i<width*height*channel_count; i=i+3)
    {
        data[i] = (data[i]+data[i+1]+data[i+2])/3;
        data[i+1] = data[i];
        data[i+2] = data[i];
    }
 
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
 
    return;
}
void color_desaturate(char *source_path)
{
    int width=0, height=0;
    unsigned char* data;
    int channel_count;
    read_image_data(source_path, &data,&width,&height,&channel_count);
    int i, max, min;
    for (i=0; i<width*height*channel_count; i=i+channel_count)
    {
        if (data[i] > data[i + 1]) 
        {
            max = data[i];
            min = data[i + 1];
        } 
        else 
        {
            max = data[i + 1];
            min = data[i];
        }

        if (data[i + 2] > max) 
        {
            max = data[i + 2];
        } 
        else if (data[i + 2] < min) 
        {
            min = data[i + 2];
        }
        data[i]=(min+max)/2;
        data[i+1]=(min+max)/2;
        data[i+2]=(min+max)/2;

    }
    
    write_image_data("image_out.bmp", data, width, height);
    return;
}

void color_gray_luminance(char *source_path){
    int width = 0;
    int height = 0;
    unsigned char *data;
    int channel_count;
 
    read_image_data(source_path, &data, &width, &height, &channel_count);
   
    int i;
    for(i=0; i<width*height*channel_count; i=i+3){
        data[i]= (0.21*data[i]+0.72*data[i+1]+0.07*data[i+2]);
        data[i+1]= data[i];
        data[i+2]= data[i];
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
 
    return;
}

void mirror_horizontal(char *source_path)
{
    int width=0, height=0;
    unsigned char* data;
    unsigned char* new_data;
    int channel_count;
    pixelRGB *Pix1;
    pixelRGB *Pix2;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &new_data, &width, &height, &channel_count);
    int x,y;
    for (y=0; y<height;y++)
    {
        for (x=0; x<width; x++)
        {
            Pix1 = get_pixel(data, width, height, channel_count, x, y);
            Pix2 = get_pixel(new_data, width, height, channel_count, width-1-x, y);
            Pix2->R=Pix1->R;
            Pix2->G=Pix1->G;
            Pix2->B=Pix1->B;

        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free_image_data(data);
    return;
}

void mirror_vertical(char *source_path)
{int width=0, height=0;
    unsigned char* data;
    unsigned char* new_data;
    int channel_count;
    pixelRGB *Pix1;
    pixelRGB *Pix2;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    read_image_data(source_path, &new_data, &width, &height, &channel_count);
    int x,y;
    for (x=0; x<height;x++)
    {
        for (y=0; y<width; y++)
        {
            Pix1 = get_pixel(data, width, height, channel_count, x, y);
            Pix2 = get_pixel(new_data, width, height, channel_count, x, width-1-y);
            Pix2->R=Pix1->R;
            Pix2->G=Pix1->G;
            Pix2->B=Pix1->B;

        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free_image_data(data);
    return;
}

void mirror_total(char *source_path)
{
    mirror_horizontal(source_path);
    rename("image_out.bmp", "image_out_temp.bmp");
    mirror_vertical("image_out_temp.bmp");
    remove("image_out_temp.bmp");
    return;
}

void scale_nearest(char *source_path, float X)
{
    int width = 0;
    int height = 0;
    int i, j, x, y;
    unsigned char *data; 
    int channel_count;
    pixelRGB* Pix1;
    pixelRGB* Pix2;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int new_width = (int)(X*width);
    int new_height = (int)(X*height);
    unsigned char *new_data = malloc(new_width * new_height * channel_count);
    for (i=0; i<new_height; i++)
    {
        for (j=0; j<new_width;j++)
        {
            x=j/X;
            y=i/X;
            Pix1 = get_pixel(data, width, height, channel_count, x, y);
            Pix2 = get_pixel(new_data, new_width, new_height, channel_count, j, i);
            Pix2->R = Pix1->R;
            Pix2->G= Pix1->G;
            Pix2->B = Pix1->B;
        }
    }
    write_image_data("image_out.bmp", new_data, new_width, new_height);
    free_image_data(data);
    free(new_data);
    return;
}

void scale_crop(char *source_path, int center_x, int center_y, int width, int height){
    int old_width = 0;
    int old_height = 0;
    unsigned char *old_data;
    int channel_count;
 
    read_image_data(source_path, &old_data, &old_width, &old_height, &channel_count);
    unsigned char *data = malloc(width*height*channel_count);
    if(data == NULL)
    {
        printf("erreur : allocation mémoire");
        return;
    }

    int j; 
    for(j=0; j<width*height*channel_count; j++)
        data[j] = 0;

    int x, y,i;
    int first_x, first_y;
    for(y=0; y<height; y++){
        for(x=0; x<width; x++){
            first_x = center_x - width/2 + x;
            first_y = center_y - height/2 + y;

            if(first_x > 0 && first_x < old_width && first_y > 0 && first_y < old_height)
            {
                for(i=0; i<channel_count; i++)
                {
                    data[(y * width + x) * channel_count + i] = old_data[(first_y * old_width + first_x)*channel_count + i];
                }
            }
        }
    }

    write_image_data("image_out.bmp", data, width, height);
    free_image_data(old_data);
    free(data);
    return;
}

void scale_bilinear(char *source_path, float X)
{
    int width = 0;
    int height = 0;
    int i, j;
    unsigned char *data; 
    int channel_count;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    int new_width = (int)(X*width);
    int new_height = (int)(X*height);
    unsigned char *new_data = malloc(new_width * new_height * channel_count);
    
    float old_x = 0;
    float old_y = 0;
    int x_0 = 0;
    int y_0 = 0;
    int x_1 = 0;
    int y_1 = 0;
    float dx = 0;
    float dy = 0;

    pixelRGB* q11;
    pixelRGB* q12;
    pixelRGB* q21;
    pixelRGB* q22;

    float p1_R = 0;
    float p2_R = 0;
    float p1_G = 0;
    float p2_G = 0;
    float p1_B = 0;
    float p2_B = 0;
    
    float r_R = 0;
    float r_G = 0;
    float r_B = 0;

    for (i=0; i<new_height; i++)
    {
        for (j=0; j<new_width;j++)
        {
            old_x = j/X;
            old_y = i/X;
            x_0 = (int)old_x;
            y_0 = (int)old_y;
            x_1 = x_0 + 1;
            y_1 = y_0 + 1;
            dx = old_x - x_0;
            dy = old_y - y_0;

            if(x_1 >= width)
                x_1 = width -1;
            if(y_1 >= height)
                y_1 = height -1;
            if(x_0 < 0)
                x_0 = 0;
            if(y_0 < 0)
                y_0 = 0;

            q11 = get_pixel(data, width, height, channel_count, x_0, y_0);
            q12 = get_pixel(data, width, height, channel_count, x_0, y_1);
            q21 = get_pixel(data, width, height, channel_count, x_1, y_0);
            q22 = get_pixel(data, width, height, channel_count, x_1, y_1);

            p1_R = q11->R * (1-dx) + q21->R*dx;
            p2_R = q12->R * (1-dy) + q22->R*dy;
            p1_G = q11->G * (1-dx) + q21->G*dx;
            p2_G = q12->G * (1-dy) + q22->G*dy;
            p1_B = q11->B * (1-dx) + q21->B*dx;
            p2_B = q12->B * (1-dy) + q22->B*dy;

            r_R = p1_R * (1-dy) + p2_R*dy;
            r_G = p1_G * (1-dy) + p2_G*dy;
            r_B = p1_B * (1-dy) + p2_B*dy;

            new_data[(i*new_width + j)*channel_count] = (unsigned char)r_R;
            new_data[(i*new_width + j)*channel_count +1] = (unsigned char)r_G;
            new_data[(i*new_width + j)*channel_count +2] = (unsigned char)r_B;
        }
    }
    write_image_data("image_out.bmp", new_data, new_width, new_height);
    free_image_data(data);
    free(new_data);
    return;
}