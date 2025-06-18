#ifndef FEATURES_H
#define FEATURES_H
 
 
void helloWorld();
 
void dimension(char *source_path);
 
void first_pixel (char *source_path);
 
void tenth_pixel (char *source_path);
 
void second_line (char *source_path);

void max_component (char *source_path, unsigned char component);

void min_component (char *source_path, unsigned char component);

void print_pixel(char *source_path, int x, int y);

void max_pixel (char *source_path);

void min_pixel (char *source_path);

void color_red(char *source_path);

void color_green(char *source_path);

void color_blue(char *source_path);

void invert(char *source_path);

void color_gray_luminance(char *source_path);

void rotate_cw(char *source_path);

void rotate_acw(char *source_path);

void color_gray(char *source_path);

void stat_report(char *source_path);

void color_desaturate(char *source_path);

void scale_crop(char *source_path, int center_x, int center_y, int width, int height);

#endif
 