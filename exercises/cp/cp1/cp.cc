/*
This is the function you need to implement. Quick reference:
- input rows: 0 <= y < ny
- input columns: 0 <= x < nx
- element at row y and column x is stored in data[x + y*nx]
- correlation between rows i and row j has to be stored in result[i + j*ny]
- only parts with 0 <= j <= i < ny need to be filled
*/

/*
 * Steps - 
 * 1. Calculate mean of each row. Each row is treated like an array.
 * 2. Calculate deviation from mean for each element and store it in the result the same way data is stored. Don't need to store it just do a += since we have to sum the deviation for the row and summation of their squares, dev_sum_ri, dev_sum_rj, dev_sq_sum_ri, dev_sq_sum_rj.
 * 3. 
 * */

#include <stdlib.h>

#define GET_DATA(y, x) data[x + y*nx]
#define PUT_DATA(y, x, val) 	{	\
	result[x + y*nx] = val;		\
}

#define corr(i, j, val)	{	\
	result[i + j*ny] = val;	\
}				

void correlate(int ny, int nx, const float *data, float *result) {
	int i, j;
	j = i = 0;
	/* calculate mean for each row 
	 * ny: rows
	 * nx: cols
	 **/
	// no of element in each row = no of col
	int x, y, nyi = 0;
	double *mean = calloc(ny, sizeof(double));
	double row_sum = 0.0f;
	for (y = 0; y < ny; y++)
	{
		for (x = 0; x < nx; x++)
			row_sum += GET_DATA(y, x);	
		mean[nyi] = (row_sum / ny); 
		for (x = 0; x < nx; x++)
		{
			/* calculate deviation */
			float elem = GET_DATA(y, x);
			double dev = elem - mean[nyi];			
			PUT_DATA(y, x, dev);
		}
		nyi++;
	}
}


