//Joseh Madden, Nathaniel Kell
#ifndef _SORT_H_
#define _SORT_H_

#include <vector>
#include <set>
using namespace std;


        /**
         * Several sorting routines.
         * Arrays are rearranged with smallest item first.
         */

        /**
         * Simple insertion sort.
         */
        template <class Comparable>
        void insertionsort( vector<Comparable> & a ){
            int j;
/* 1*/      for( int p = 1; p < a.size( ); p++ ){
/* 2*/          Comparable tmp = a[ p ];
/* 3*/          for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )
/* 4*/              a[ j ] = a[ j - 1 ];
/* 5*/          a[ j ] = tmp;
            }
        }

        /**
         * Shellsort, using Shell's (poor) increments.
         */
        template <class Comparable>
        void shellsort( vector<Comparable> & a ){
            int j;
/* 1*/      for( int gap = a.size( ) / 2; gap > 0; gap /= 2 )
/* 2*/          for( int i = gap; i < a.size( ); i++ ){
/* 3*/              Comparable tmp = a[ i ];
/* 4*/              for( j = i; j >= gap && tmp < a[ j - gap ]; j -= gap )
/* 5*/                  a[ j ] = a[ j - gap ];
/* 6*/              a[ j ] = tmp;
                }
        }

		template <class Comparable>
		void hibbardsort(vector<Comparable> x) {      //SHELL SORT - HIBBARD'S INCREMENTS
			int i, j, k, increment, temp;
			int val;
			val = log(x.size()) / log(2);
			increment = pow(2, val) - 1;
			while (increment > 0){
				for (i = 0;i<increment;i++){
					for (j = 0;j< x.size(); j += increment){
						temp = x[j];
						for (k = j - increment;k >= 0 && temp<x[k];k -= increment){
							x[k + increment] = x[k];
						}
						x[k + increment] = temp;
					}
				}
				val--;
				if (increment != 1) increment = pow(2, val) - 1;
				else increment = 0;
			}
		}

       
        /**
         * Mergesort algorithm (driver).
         */
        template <class Comparable>
        void mergesort( vector<Comparable> & a ){
            vector<Comparable> tmpArray(a.size( ));
            mergeSort( a, tmpArray, 0, a.size( ) - 1 );
        }


		 /**
         * Internal method that merges two sorted halves of a subarray.
         * a is an array of Comparable items.
         * tmpArray is an array to place the merged result.
         * leftPos is the left-most index of the subarray.
         * rightPos is the index of the start of the second half.
         * rightEnd is the right-most index of the subarray.
         */
        template <class Comparable>
        void merge( vector<Comparable> & a, vector<Comparable> & tmpArray,
               int leftPos, int rightPos, int rightEnd ){
            int leftEnd = rightPos - 1;
            int tmpPos = leftPos;
            int numElements = rightEnd - leftPos + 1;

            // Main loop
            while( leftPos <= leftEnd && rightPos <= rightEnd )
                if( a[ leftPos ] <= a[ rightPos ] )
                    tmpArray[ tmpPos++ ] = a[ leftPos++ ];
                else
                    tmpArray[ tmpPos++ ] = a[ rightPos++ ];

            while( leftPos <= leftEnd )    // Copy rest of first half
                tmpArray[ tmpPos++ ] = a[ leftPos++ ];

            while( rightPos <= rightEnd )  // Copy rest of right half
                tmpArray[ tmpPos++ ] = a[ rightPos++ ];

            // Copy tmpArray back
            for( int i = 0; i < numElements; i++, rightEnd-- )
                a[ rightEnd ] = tmpArray[ rightEnd ];
        }


        /**
         * Internal method that makes recursive calls.
         * a is an array of Comparable items.
         * tmpArray is an array to place the merged result.
         * left is the left-most index of the subarray.
         * right is the right-most index of the subarray.
         */
        template <class Comparable>
		void mergeSort(vector<Comparable> & a,
			vector<Comparable> & tmpArray, int left, int right) {
			if (left < right){
				int center = (left + right) / 2;
				mergeSort(a, tmpArray, left, center);
				mergeSort(a, tmpArray, center + 1, right);
				merge(a, tmpArray, left, center + 1, right);
			}
		}
#endif
