#include <stdlib.h>
#include "a4.h"
#include <stdio.h>

void mutate(Individual *individual, double rate){
	PPM_IMAGE *img = &((*individual).image);
	int size = (*img).width * (*img).height;
	int mut = (rate/100) * size;
	int max = (*img).max_color + 1;
	PIXEL *arr = (*img).data;
	for (int i = 0; i < mut; i++){
		int pick = rand() % size;
		PIXEL *curr = arr + pick;
		(*curr).r = rand() % max;
		(*curr).g = rand() % max;
		(*curr).b = rand() % max;
	}
}

void mutate_population(Individual *individual, int population_size, double rate){
	for (int i = population_size/4; i < population_size; i++){
		mutate(individual + i, rate);
	}
}
