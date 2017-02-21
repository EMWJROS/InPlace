#include "Matrix.h"
#include <cassert>
#include <iostream>

int main(int argc, char* [])
{
        // Test 1: Simple matrix
	int Aa[] = {1,2,3, 4,5,6};
	Matrix A = Matrix(2, 3, Aa );
	int AT[] = {1,4, 2,5, 3,6};
	
	A.transpose();
	assert(A.equals(AT));

	// Test 2: Square matrix
	int Ba[] = {1,2,3,4};
	Matrix B = Matrix(2, 2, Ba);
	int BT[] = {1,3,2,4};

	B.transpose();
	assert(B.equals(BT));
	
	// Test 3: Larger random matrix
	int Ca[] =  {8,2,9,9,6,9, 1,7,9,3,5,2, 4,1,3,7,6,7, 9,7,1,8,8,3,
		     1,2,7,7,0,9, 1,4,5,7,3,4, 7,9,5,4,1,4};
	Matrix C = Matrix(7, 6, Ca);
	int CT[] = {8,1,4,9,1,1,7, 2,7,1,7,2,4,9, 9,9,3,1,7,5,5,
		    9,3,7,8,7,7,4, 6,5,6,8,0,3,1, 9,2,7,3,9,4,4};

	C.transpose();
	assert(C.equals(CT));

	// An even larger random matrix
	int D_data[] = { 6 , 6 , 8 , 5 , 9 , 9 , 9 , 0 , 3 ,
			 4 , 8 , 8 , 5 , 0 , 5 , 8 , 2 , 1 ,
			 8 , 0 , 1 , 0 , 6 , 0 , 8 , 3 , 5 ,
			 5 , 4 , 1 , 3 , 8 , 0 , 4 , 1 , 0 ,
			 7 , 8 , 5 , 8 , 5 , 8 , 2 , 1 , 2 ,
			 5 , 0 , 8 , 9 , 0 , 9 , 3 , 5 , 0 ,
			 4 , 2 , 2 , 9 , 9 , 9 , 7 , 9 , 8 ,
			 1 , 4 , 0 , 3 , 5 , 1 , 7 , 9 , 7 ,
			 8 , 5 , 1 , 2 , 0 , 8 , 7 , 0 , 8 ,
			 5 , 5 , 1 , 0 , 6 , 3 , 2 , 3 , 4 ,
			 0 , 9 , 2 , 1 , 7 , 2 , 7 , 7 , 1 };
	Matrix D = Matrix(11, 9, D_data);
	int D_expectedTranspose[] = 
	  { 6 , 4 , 8 , 5 , 7 , 5 , 4 , 1 , 8 , 5 , 0 ,
	    6 , 8 , 0 , 4 , 8 , 0 , 2 , 4 , 5 , 5 , 9 ,
	    8 , 8 , 1 , 1 , 5 , 8 , 2 , 0 , 1 , 1 , 2 ,
	    5 , 5 , 0 , 3 , 8 , 9 , 9 , 3 , 2 , 0 , 1 ,
	    9 , 0 , 6 , 8 , 5 , 0 , 9 , 5 , 0 , 6 , 7 ,
	    9 , 5 , 0 , 0 , 8 , 9 , 9 , 1 , 8 , 3 , 2 ,
	    9 , 8 , 8 , 4 , 2 , 3 , 7 , 7 , 7 , 2 , 7 ,
	    0 , 2 , 3 , 1 , 1 , 5 , 9 , 9 , 0 , 3 , 7 ,
	    3 , 1 , 5 , 0 , 2 , 0 , 8 , 7 , 8 , 4 , 1 };
	
	D.transpose();
	assert(D.equals(D_expectedTranspose));

	std::cout << "All tests were successful." << std::endl;
 	return 0;
}
