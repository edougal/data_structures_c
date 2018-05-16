
#include <stdio.h> 	// printf
#include <stddef.h> // NULL 
#include <stdint.h>	// int64_t


#if HEAP_USE_IMPLICIT_DATASTRUCTURE == 1
//implicit implementation






#else
// explicit implementation

typedef struct heap_node_s {	
	struct heap_node_s * left;
	struct heap_node_s * right; 
	int64_t val; 
} heap_node_t; 





#endif 

int main() {


	return 0; 
}