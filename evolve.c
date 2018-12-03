#include <stdlib.h>
#include "a4.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

static int cmpfunc(const void *a, const void *b){
	double af = (*((Individual *)a)).fitness;
	double bf = (*((Individual *)b)).fitness;
	return (int)(af - bf);
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
	srand(time(NULL));
	int indsize = sizeof(Individual);
	Individual *pop = generate_population(population_size, (*image).width, (*image).height, (*image).max_color);
	comp_fitness_population((*image).data, pop, population_size);
	qsort(pop, population_size,indsize, cmpfunc);

	for (int i = 0; i < num_generations; i++){
		//printf("At gen %d\n", i);
		crossover(pop, population_size);
		mutate_population(pop, population_size, rate);
		comp_fitness_population((*image).data, pop, population_size);
		qsort(pop, population_size, indsize, cmpfunc);
		//printf("%f\n", pop[0].fitness);
	}

	PPM_IMAGE *ret = malloc(sizeof(PPM_IMAGE));
	(*ret).data = (pop[0].image).data;
	(*ret).width = (*image).width;
	(*ret).height = (*image).height;
	(*ret).max_color = (*image).max_color;
	for (int i = 1; i < population_size; i++){
		free(pop[i].image.data);
	}
	free(pop);
	return ret;
}

void free_image(PPM_IMAGE *p){
	free((*p).data);
	free(p);
}
