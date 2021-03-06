//
// Selection Sort example in C99
// First v. 24 Oct 2016 Dr Anton Gerdelan, Trinity College Dublin
// <gerdela@scss.tcd.ie>
//

#include <stdio.h>	// printf()
#include <stdlib.h> // rand()
#include <time.h>		// for seeding rand() with time()
#include <stdbool.h> // bool - only needed in C99

void randomise_array( int *array, int length ) {
	for ( int i = 0; i < length; i++ ) {
		array[i] = rand() % 100; // max value 100 so it's easier to read
	}
}

void print_array( int *array, int length ) {
	for ( int i = 0; i < length; i++ ) {
		printf( "%i ", array[i] );
	}
	printf( "\n" );
}

void selection_sort( int *array, int length ) {
	for ( int pass = 0; pass < length - 1; pass++ ) {
		int min_idx = pass;
		for ( int i = pass + 1; i < length; i++ ) {
			if ( array[i] < array[min_idx] ) {
				min_idx = i;
			}
		}
		int tmp = array[min_idx];
		array[min_idx] = array[pass];
		array[pass] = tmp;
	}
}

void insertion_sort( int *array, int length ) {
	for ( int pass = 0; pass < length - 1; pass++ ) {
		for ( int i = pass + 1; i > 0; i-- ) {
			if ( array[i - 1] > array[i] ) {
				int temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
			} else {
				break;
			}
		}
	}
}

void bubble_sort( int *array, int length ) {
	bool sorted = false;
	while ( !sorted ) {
		sorted = true;
		for ( int i = 0; i < length - 1; i++ ) {
			if ( array[i + 1] < array[i] ) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				sorted = false;
			}
		}
	}
}

int main() {
	srand( time( NULL ) );

	int array[64];
	randomise_array( array, 64 );
	print_array( array, 64 );

	printf( "--sorted:--\n" );
	// selection_sort( array, 64 );
	// insertion_sort( array, 64 );
	bubble_sort( array, 64 );
	print_array( array, 64 );

	return 0;
}