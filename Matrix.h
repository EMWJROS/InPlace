#define ARRAYSIZE 100
/******************************************************************************
 * Models a matrix
 *
 *****************************************************************************/
class Matrix 
{
	private:
		int NUMBER_OF_ROWS;
		int NUMBER_OF_COLUMNS;
		int array[ARRAYSIZE];
		int positionBeforeTransposition(int r, int c);
		int rowBeforeTransposition(int p);
		int columnBeforeTransposition(int p);
		int positionAfterTransposition(int r, int c);
		
	public:
		Matrix(int n, int m, int* a);
		bool equals(int *a);
		void transpose();
		void print();
};
