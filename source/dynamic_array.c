
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

#include "dynamic_array.h" 

#define DEFAULT_SIZE 8

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

// get length

uint64_t dynamic_array_length(dynamic_array_t * array) {
	return array->length; 
}

// get element

int64_t dynamic_array_get(dynamic_array_t * array, uint64_t element_num) {
	if(element_num > array->length) {
		return 0; 
	} else {
		return array->vals[element_num];
	}
}

// set element

void dynamic_array_set(dynamic_array_t * array, uint64_t element_num, int64_t element) {
	if(element_num > array->length) {
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
		uint64_t new_size = array->total_size * 2; 

		int64_t * new_vals = (int64_t *) malloc(sizeof(int64_t) * new_size);

		for(uint64_t i = 0; i < array->length - 1; i++) {
			new_vals[i] = array->vals[i]; 
		}

		free(array->vals); 
		array->vals = new_vals;  
		array->total_size = new_size; 
	}

	return;
}


// remove element


// test cases 

void dynamic_array_test() {



}


int main() {

	dynamic_array_t * array = dynamic_array_init(); 

	for(int i = 0; i < 22; i++) {
		dynamic_array_append(array, i);
	}

	printf("array = [");
	for(int i = 0; i < dynamic_array_length(array); i++) {
		printf(" %lli, ", dynamic_array_get(array, i));
	}
	printf("]\n");

	return 0;
}

