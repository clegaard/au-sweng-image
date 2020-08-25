/*
 * Compute the the area of a rectangular polygon.
 */

#include <stdio.h>  /* scanf, printf */
#include <assert.h> /* assert */

/* Compute the distance between two consecutive
 * points as the absolute difference of
 * their changing dimension.
 * It returns the absolute difference between
 * p and q.
 */
int distance(int p, int q)
{
    return p > q ? p - q : q - p;
}

/* program body */
int main(void)
{
    int x[5]; /* x-coordinates of the polygon */
    int y[5]; /* x-coordinates of the polygon */
    int i;    /* counter variable */
    int dx;   /* x-side length */
    int dy;   /* y-side length */
    int area; /* area of the rectangular polygon */
    
    /* read input */
    for (i = 0; i < 4; i = i + 1)
    {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    x[4] = x[0];
    y[4] = y[0];
    
    /* precondition */
    /* true */
    
    /* postcondition */
    /* Determine wether the points describe a rectangular polygon */
    /* For all i with 0 <= i < 4,
     *   (x[i] == x[i+1] || y[i] == y[i+1]) &&
     *   (x == 0 ||
     *      ((x[i-1] != x[i] || x[i] != x[i+1]) &&
     *       (y[i-1] != y[i] || y[i] != y[i+1])))
     */ 
    for (i = 0; i < 4; i = i + 1)
    {   /* check whether the property does not hold for index i */
        if (!((x[i] == x[i+1] || y[i] == y[i+1]) &&
              (i == 0 ||
               ((x[i-1] != x[i] || x[i] != x[i+1]) &&
                (y[i-1] != y[i] || y[i] != y[i+1])))))
        { /* ... that case terminate with an error message */
            printf("Not a rectangular polygon.\n");
            return 0;
        } /* ... otherwise evaluate the next index */
    }
    /* Now, x and y describe a rectangular polygon.
     * Because of this, the lengths of the sides can be computed from
     * the first three points. 
     */
    if (x[0] != x[1])
    {   /* This implies also that y[1] != y[2] */
        dx = distance(x[0],x[1]);
        dy = distance(y[1],y[2]);
    }
    else
    {   /* we have x[0] == x[1]
         * hence, y[0] != y[1] and x[1] != x[2]
         */
        dx = distance(x[1],x[2]);
        dy = distance(y[0],y[1]);
    }
    /* dx and dy contain the lengths of the two sides */
    area = dx * dy;
    /* area contains the area of the rectangular polygon */
    /* print output */
    printf("Area of the rectangular polygon: %d\n", area);
    
    /* return from body and exit program */
    return 0;
}