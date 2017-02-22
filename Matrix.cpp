#include "Matrix.h"
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
 * Gives the memory position of an array element
 *
 * @param r Row
 * @param c Column
 *
 *****************************************************************************/
int Matrix::position(int r, int c)
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
	return p % NUMBER_OF_ROWS;
}

/******************************************************************************
 * Gives the column of an array element before transposition
 *
 * @param p Memory position
 * @return Column
 *****************************************************************************/
int Matrix::columnBeforeTransposition(int p)
{
	return p / NUMBER_OF_ROWS;
}

/******************************************************************************
 * Gives positin of an array element before transposition
 *
 * @param p Memory position
 * @return Previous position
 *****************************************************************************/
int Matrix::positionBeforeTransposition(int p)
{
  int previousC = columnBeforeTransposition(p);
  int previousR = rowBeforeTransposition(p);
  return position(previousR, previousC);
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
	  int pos1 = position(r,c);
	  int firstPos = pos1;
	  			
	  // Store away first number
	  int tmp = array[pos1];
	  beenThere[pos1] = true;

	  // Find the array element that will be moved into pos1
	  // during transposition

	  int pos2 = positionBeforeTransposition(pos1);

	  while (!beenThere[pos2])
	    {
	      // Shift values

	      array[pos1] = array[pos2];
	      beenThere[pos2] = true;
	      pos1 = pos2;

	      pos2 = positionBeforeTransposition(pos1);

	    };

	  // Back at the beginning? (We possibly never left ...)
	  if (pos2 == firstPos)
	  {
	      // This is where we need the value we stored
	      array[pos1] = tmp;
	  };
     };
  };
		
  int tmp = NUMBER_OF_ROWS;
  NUMBER_OF_ROWS = NUMBER_OF_COLUMNS;
  NUMBER_OF_COLUMNS = tmp;
};
