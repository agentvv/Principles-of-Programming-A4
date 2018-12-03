#include <stdlib.h>
#include "a4.h"
#include <stdio.h>

PIXEL *generate_random_image(int width, int height, int max_color){
	int size = height * width;
	PIXEL *arr = malloc(sizeof(PIXEL) * size);
	int max = max_color + 1;
	for (int i = 0; i < size; i++){
		PIXEL *curr = &(arr[i]);
		(*curr).r = rand() % max;
		(*curr).g = rand() % max;
		(*curr).b = rand() % max;
	}
	return arr;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
	Individual *arr = malloc(sizeof(Individual) * population_size);
	PPM_IMAGE curr;

	for (int i = 0; i < population_size; i++){
		curr.data = generate_random_image(width, height, max_color);
		curr.width = width;
		curr.height = height;
		curr.max_color = max_color;
		arr[i].image = curr;
	}
	return arr;
}
