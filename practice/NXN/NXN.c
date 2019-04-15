#include <stdio.h>
#define N 6
void rotatematrix(int mat[][N])
{
	int temp;
	for (int x = 0; x < N / 2; x++)
	{
		//consider element in groups of four
		for (int y = x; y < N - x - 1; y++)
		{
			// store current value in a temp buffer
			temp = mat[x][y];

			//move element from right to top
			mat[x][y] = mat[y][N-1-x];

			//move element from buttom to right
			mat[y][N-1-x] = mat[N-1-x][N-1-y];

			//move element from left to buttom
			mat[N-1-x][N-1-y] = mat[N-1-y][x];

			mat[N-1-y][x] = temp;
		}
	}

}

void printmatrix(int mat[N][N])
{
	int i;
	int j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d", mat[i][j]);

		}
		printf("\n");
	}
	printf("\n");
}

int main ()
{
	int mat[N][N] = 
    { 
        {1, 2, 3, 4, 0}, 
        {5, 6, 7, 8, 1}, 
        {9, 10, 11, 12, 2}, 
        {13, 14, 15, 16, 3} 
    }; 
    int mat2[N][N] = 
    { 
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9} 
     }; 
    rotatematrix(mat);
    printmatrix(mat);
}