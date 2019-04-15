#include <stdio.h>
#define M 5
#define N 5

void matrixzero(int mat[M][N])
{
	int i;
	int j;
	int row[M];
	int col[N];
	

	for (i = 0; i < M ; i++)
	{
		for (j = 0; j < N ; j++)
		{
			if (mat[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for (i = 0; i < M; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            if ( row[i] == 1 || col[j] == 1) 
            { 
                mat[i][j] = 0; 
            } 
        } 
    } 
}
void printmatrix(int mat[M][N])
{
	int i;
	int j;
	for (i = 0; i < M; i++)
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
	int mat[M][N] = 
	{ {1, 0, 1, 1, 0}, 
      {0, 1, 1, 1, 0},
      {1, 1, 1, 1, 1,}, 
      {1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1}};
	matrixzero(mat);
	printmatrix(mat);

}
