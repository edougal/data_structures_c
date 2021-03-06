
#include <stdlib.h> // malloc, free
#include <stdio.h> 	// printf
#include <stddef.h> // NULL 

#include "dynamic_array.h" 

#define DEFAULT_SIZE 8
#define GROWTH_FACTOR 3 / 2

// initialize array

dynamic_array_t * dynamic_array_init() {


	// allocate memory for the dynamic array struct; 
	dynamic_array_t * new_array = (dynamic_array_t *) malloc(sizeof(dynamic_array_t));

	// set the length and size variables

	new_array->length = 0;

	new_array->total_size = DEFAULT_SIZE; 

	// allocate memory for the array itself

	new_array->vals = (int64_t *) malloc(sizeof(int64_t) * DEFAULT_SIZE);

	return new_array; 

}

void dynamic_array_uninit(dynamic_array_t * array) {

	if(array == NULL) {
		return;
	} else {
		free(array->vals);
		free(array); 
	}
}

// get length

uint64_t dynamic_array_length(dynamic_array_t * array) {
	return array->length; 
}

// get element

int64_t dynamic_array_get(dynamic_array_t * array, uint64_t element_num) {
	if(element_num >= array->length) {
		return 0; 
	} else {
		return array->vals[element_num];
	}
}

// set element

void dynamic_array_set(dynamic_array_t * array, uint64_t element_num, int64_t element) {
	if(element_num >= array->length) {
		return; 
	} else {
		array->vals[element_num] = element;
	}
}

// append element

void dynamic_array_append(dynamic_array_t * array, int64_t element) {

	// set element
	array->vals[array->length] = element; 
	array->length++;

	// handle case where the array is getting too big
	if(array->length == array->total_size) {
		uint64_t new_size = array->total_size * GROWTH_FACTOR; 

		array->vals = (int64_t *) realloc(array->vals, sizeof(int64_t) * new_size);

		array->total_size = new_size; 
	}

	return;
}


// Remove last element and return it

int64_t dynamic_array_pop(dynamic_array_t * array) {
	if(array == NULL) {
		return 0; 
	} else {
		return array->vals[--array->length];		
	}
}

// Print array

void dynamic_array_print(dynamic_array_t * array) {
	if(array == NULL) {
		return; 
	}

	printf("array = [");
	for(int i = 0; i < dynamic_array_length(array)-1; i++) {
		printf(" %lli, ", dynamic_array_get(array, i));
	}
	printf(" %lli]\n", dynamic_array_get(array, dynamic_array_length(array)-1));
}


// test cases 

void dynamic_array_test() {




}


int main() {

	dynamic_array_t * array = dynamic_array_init(); 

	for(int i = 0; i < 50; i++) {
		dynamic_array_append(array, i);
	}

	dynamic_array_print(array); 

	printf("pop: %lli\n", dynamic_array_pop(array));
	printf("pop: %lli\n", dynamic_array_pop(array));
	printf("pop: %lli\n", dynamic_array_pop(array));
	printf("pop: %lli\n", dynamic_array_pop(array));
	printf("pop: %lli\n", dynamic_array_pop(array));

	dynamic_array_print(array); 


	return 0;
}

