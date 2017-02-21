#include "Matrix.h"
#include <iostream>
#include <cassert>
#include <cstring>

/******************************************************************************
 * Constructs a Matrix object from an array of ints
 *
 * @param n Number of rows
 * @param m Number of colums
 * @param a Array of ints to fill matrix with in rows
 *
 *****************************************************************************/
Matrix::Matrix(int n, int m, int* a)
{
        assert(n*m <= ARRAYSIZE);
	NUMBER_OF_ROWS = n;
	NUMBER_OF_COLUMNS = m;
	memcpy(array, a, NUMBER_OF_ROWS*NUMBER_OF_COLUMNS*sizeof(int));
}

/******************************************************************************
 * Checks if a matrix equals an array of ints
 *
 * @param a Array of ints to compare with
 *
 *****************************************************************************/
bool Matrix::equals(int* a)
{
	bool result = true;

	for (int i=0; i<NUMBER_OF_ROWS*NUMBER_OF_COLUMNS; ++i)
	{
		result &= (array[i] == *(a+i));
	}	

	return result;
}

/******************************************************************************
 * Gives the memory position of an array element before transposition
 *
 * @param r Row
 * @param c Column
 *
 *****************************************************************************/
int Matrix::positionBeforeTransposition(int r, int c)
{
	return NUMBER_OF_COLUMNS*r+c;
}

/******************************************************************************
 * Gives the row of an array element before transposition
 *
 * @param p Memory position
 * @return Row
 *****************************************************************************/
int Matrix::rowBeforeTransposition(int p)
{
	return p / NUMBER_OF_COLUMNS;
}

/******************************************************************************
 * Gives the column of an array element before transposition
 *
 * @param p Memory position
 * @return Column
 *****************************************************************************/
int Matrix::columnBeforeTransposition(int p)
{
	return p % NUMBER_OF_COLUMNS;
}

/******************************************************************************
 * Gives the memory position of an array element after transposition
 *
 * @param r Row
 * @param c Column
 * @return Position in the memory
 *****************************************************************************/
int Matrix::positionAfterTransposition(int r, int c)
{
	return NUMBER_OF_ROWS*r+c;
}

/******************************************************************************
 * Transposes the matrix
 *
 *****************************************************************************/
void Matrix::transpose()
{
  bool beenThere[ARRAYSIZE] = {false};

  for (int r=0; r < NUMBER_OF_ROWS; ++r)
    {
      for (int c=0; c < NUMBER_OF_COLUMNS; ++c)
	{
	  int pos1 = positionBeforeTransposition(r,c);
	  int pos2 = positionAfterTransposition(c,r);
				
	  // Store away first number
	  int previousValue = array[pos1];
	  beenThere[pos1] = true;
	  int memory;

	  while (!beenThere[pos2])
	    {
	      // Shift values
	      memory = array[pos2];
	      array[pos2] = previousValue;
	      beenThere[pos2] = true;

	      int newC = columnBeforeTransposition(pos2);
	      int newR = rowBeforeTransposition(pos2);
	      previousValue = memory;
		  
	      pos2 = positionAfterTransposition(newC, newR);

	    };

	  // Back at the beginning? (We possibly never left.)
	  if (pos2==pos1)
	  {
	      array[pos2] = previousValue;
	  };
     };
  };
		
  int tmp = NUMBER_OF_ROWS;
  NUMBER_OF_ROWS = NUMBER_OF_COLUMNS;
  NUMBER_OF_COLUMNS = tmp;
};
