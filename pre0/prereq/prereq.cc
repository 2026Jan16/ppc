struct Result {
    float avg[3];
};

/*
This is the function you need to implement. Quick reference:
- x coordinates: 0 <= x < nx
- y coordinates: 0 <= y < ny
- horizontal position: 0 <= x0 < x1 <= nx
- vertical position: 0 <= y0 < y1 <= ny
- color components: 0 <= c < 3
- input: data[c + 3 * x + 3 * nx * y]
- output: avg[c]

1,2,0,0,1,1
*/
Result calculate(int ny, int nx, const float *data, int y0, int x0, int y1, int x1) {
    Result result{{0.0f, 0.0f, 0.0f}};
    double csum[3] = {0.0f, 0.0f, 0.0f};
    int npixels = ((x1 - x0) * (y1 - y0));
    for (int c = 0; c < 3; c++)
    {
	    for (int x = x0; (x < x1) && (x1 <= nx); x++)
	    {
		    for (int y = y0; (y < y1) && (y1 <= ny); y++)
		    {
			    csum[c] += data[c + (3 * x) + (3 * nx * y)];
		    }
	    }
    }
    result.avg[0] = csum[0] / npixels; 
    result.avg[1] = csum[1] / npixels;
    result.avg[2] = csum[2] / npixels;
    return result;
}
