
#ifndef __DYNAMIC_ARRAY__H
#define __DYNAMIC_ARRAY__H

#include <stdint.h>

typedef struct {
	int64_t * vals; 
	uint64_t length; 
	uint64_t total_size;
} dynamic_array_t;

dynamic_array_t * dynamic_array_init();

uint64_t dynamic_array_length(dynamic_array_t * array);

int64_t dynamic_array_get(dynamic_array_t * array, uint64_t element_num);

void dynamic_array_set(dynamic_array_t * array, uint64_t element_num, int64_t element);

void dynamic_array_append(dynamic_array_t * array, int64_t element);

void dynamic_array_print(dynamic_array_t * array);

int64_t dynamic_array_pop(dynamic_array_t * array);

#endif 