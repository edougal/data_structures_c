
#include <stdio.h> 	// printf
#include <stddef.h> // NULL 
#include <stdint.h>	// int64_t
#include <stdlib.h> // malloc, free

#include "heap.h"
#include "dynamic_array.h" 


static uint8_t check_valid_heap(heap_t * heap) {

	for(uint64_t i = 0; i < dynamic_array_length(heap) / 2; i++) {
		uint64_t left = 2 * i + 1;
		uint64_t right = 2 * i + 2; 
		int64_t current_element = dynamic_array_get(heap, i);
		int64_t current_left = dynamic_array_get(heap, left);
		int64_t current_right = dynamic_array_get(heap, right);

		if(current_left > current_element || current_right > current_element) {
			return 0;
		}
	}

	return 1;
}



static void heap_heapify(heap_t * heap, uint64_t idx, uint64_t max) {

	uint64_t left_idx = 2 * idx + 1;
	uint64_t right_idx = 2 * idx + 2;

	dynamic_array_t * array = (dynamic_array_t *) heap;

	int64_t largest; 

	if(left_idx < max && dynamic_array_get(array, left_idx) > dynamic_array_get(array, idx)) {
		largest = left_idx;
	} else {
		largest = idx; 
	}

	if(right_idx < max && dynamic_array_get(array, right_idx) > dynamic_array_get(array, largest)) {
		largest = right_idx;
	}

	if(largest != idx) {
		dynamic_array_swap(array, idx, largest);		
		heap_heapify((heap_t *) array, largest, max); 
	}

	return; 
}


static heap_t * heap_build_heap(int64_t * vals, uint64_t length) {


	dynamic_array_t * array = dynamic_array_init_with_vals(vals, length); 

	for(uint64_t i = length/2; i > 0; i--) {
		heap_heapify(array, i, length);
	}

	heap_heapify(array, 0, length);

	return (heap_t *) array; 
}


void heap_heapsort(heap_t * heap) {

	dynamic_array_t * array = heap; 
	uint64_t length = dynamic_array_length(array); 

	if(!check_valid_heap(heap)) {
		for(uint64_t i = length/2; i > 0; i--) {
			heap_heapify(array, i, length);
		}
		heap_heapify(array, 0, length);
	} 
	for(int64_t i = 0; i < length; i++) {
		dynamic_array_swap(array, 0, length-i-1); 
		heap_heapify(array, 0, length-i-1); 
	}

}


int main() {


	int64_t vals[] = {0,6,4,2,1,63,6,1,8,9,4,1};

	printf("Before: "); 
	dynamic_array_t * array = dynamic_array_init_with_vals(vals, sizeof(vals)/ sizeof(int64_t));
	dynamic_array_print(array); 
	if(check_valid_heap(array)) {
		printf("valid heap!\n"); 
	} else {
		printf("invalid heap\n"); 
	}


	heap_t * heap = heap_build_heap(vals, sizeof(vals)/ sizeof(int64_t));

	printf("After: "); 
	dynamic_array_print(heap); 
	if(check_valid_heap(heap)) {
		printf("valid heap!\n"); 
	} else {
		printf("invalid heap\n"); 
	}

	heap_heapsort(heap); 

	printf("Sorted "); 
	dynamic_array_print(heap); 



	return 0; 
}