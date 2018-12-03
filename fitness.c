#include <stdlib.h>
#include "a4.h"
#include <stdio.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
	double sum = 0;
	int i, sumr, sumg, sumb;
	int rem = image_size & 0x7;
	image_size -= rem;
	PIXEL currA;
	PIXEL currB;
	for (i = 0; i < image_size; i+=8){
		currA = A[i];
		currB = B[i];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
		currA = A[i+1];
		currB = B[i+1];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
		currA = A[i+2];
		currB = B[i+2];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
		currA = A[i+3];
		currB = B[i+3];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
		currA = A[i+4];
		currB = B[i+4];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
		currA = A[i+5];
		currB = B[i+5];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
		currA = A[i+6];
		currB = B[i+6];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
		currA = A[i+7];
		currB = B[i+7];
		sumr = currA.r - currB.r;
		sumg = currA.g - currB.g;
		sumb = currA.b - currB.b;
		sum += sumr*sumr + sumg*sumg + sumb*sumb;
	}
	switch (rem) {
		case 7: sum += (A[i+7].r - B[i+7].r)*(A[i+7].r - B[i+7].r) + (A[i+7].g - B[i+7].g)*(A[i+7].g - B[i+7].g) + (A[i+7].b - B[i+7].b)*(A[i+7].b - B[i+7].b);
		case 6: sum += (A[i+6].r - B[i+6].r)*(A[i+6].r - B[i+6].r) + (A[i+6].g - B[i+6].g)*(A[i+6].g - B[i+6].g) + (A[i+6].b - B[i+6].b)*(A[i+6].b - B[i+6].b);
		case 5: sum += (A[i+5].r - B[i+5].r)*(A[i+5].r - B[i+5].r) + (A[i+5].g - B[i+5].g)*(A[i+5].g - B[i+5].g) + (A[i+5].b - B[i+5].b)*(A[i+5].b - B[i+5].b);
		case 4: sum += (A[i+4].r - B[i+4].r)*(A[i+4].r - B[i+4].r) + (A[i+4].g - B[i+4].g)*(A[i+4].g - B[i+4].g) + (A[i+4].b - B[i+4].b)*(A[i+4].b - B[i+4].b);
		case 3: sum += (A[i+3].r - B[i+3].r)*(A[i+3].r - B[i+3].r) + (A[i+3].g - B[i+3].g)*(A[i+3].g - B[i+3].g) + (A[i+3].b - B[i+3].b)*(A[i+3].b - B[i+3].b);
		case 2: sum += (A[i+2].r - B[i+2].r)*(A[i+2].r - B[i+2].r) + (A[i+2].g - B[i+2].g)*(A[i+2].g - B[i+2].g) + (A[i+2].b - B[i+2].b)*(A[i+2].b - B[i+2].b);
		case 1: sum += (A[i+1].r - B[i+1].r)*(A[i+1].r - B[i+1].r) + (A[i+1].g - B[i+1].g)*(A[i+1].g - B[i+1].g) + (A[i+1].b - B[i+1].b)*(A[i+1].b - B[i+1].b);
		default:;
	}

	return sqrt(sum);
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
	int size = (individual[0].image).width * (individual[0].image).height;
	for (int i = 0; i < population_size; i++){
		individual[i].fitness = comp_distance(image, (individual[i].image).data, size);
	}
}
