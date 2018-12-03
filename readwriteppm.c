#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

PPM_IMAGE *read_ppm(const char *file_name){
	FILE *file = fopen(file_name, "r");
	int width, height, maxcolour,r,g,b,index,base;
	fscanf(file, "P3\n%d %d\n%d\n", &width, &height, &maxcolour);
	
	PIXEL *arr = malloc(sizeof(PIXEL) * width * height);

	for (int row = 0; row < height; row++){
		base = row*width;
		for (int col = 0; col < width; col++){
			index = base + col;
			fscanf(file, "%d %d %d ", &r, &g, &b);
			arr[index].r = r;
			arr[index].g = g;
			arr[index].b = b;
		}
	}
	fclose(file);
	
	PPM_IMAGE *image = malloc(sizeof (PPM_IMAGE));
	(*image).data = arr;
	(*image).width = width;
	(*image).height = height;
	(*image).max_color = maxcolour;
	return image;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image){
	FILE *file = fopen(file_name, "w");
	int width = (*image).width;
	int height = (*image).height;
	fprintf(file, "P3\n%d %d\n%d\n", width, height, (*image).max_color);
	PIXEL *arr = (*image).data;

	for (int row = 0; row < height; row++){
		int base = row*width;
		for (int col = 0; col < width; col++){
			int index = base+col;
			PIXEL curr = arr[index];
			fprintf(file, "%d %d %d ", curr.r, curr.g, curr.b);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}
