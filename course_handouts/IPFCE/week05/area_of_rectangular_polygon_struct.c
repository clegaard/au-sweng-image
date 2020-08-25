/*
 * Compute the the area of a rectangular polygon.
 */

#include <stdio.h>  /* scanf, printf */
#include <assert.h> /* assert */

typedef struct
{
    int x;
    int y;
} point;

/* Compute the distance between two consecutive points as the
 * absolute difference of their changing dimension.
 * It returns the absolute difference between p and q.
 */
int distance(int p, int q)
{
    return p > q ? p - q : q - p;
}

/* program body */
int main(void)
{
    point p[5]; /* points of the polygon */
    int i;    /* counter variable */
    int dx;   /* x-side length */
    int dy;   /* y-side length */
    int area; /* area of the rectangular polygon */
    
    /* read input */
    for (i = 0; i < 4; i = i + 1)
    {
        scanf("%d", &p[i].x);
        scanf("%d", &p[i].y);
    }
    p[4].x = p[0].x;
    p[4].y = p[0].y;
    
    /* precondition */
    /* true */
    
    /* postcondition */
    /* Determine wether the points describe a rectangular polygon */
    /* For all i with 0 <= i < 4,
     *   (p[i].x == p[i+1].x || p[i].y == p[i+1].y) &&
     *   (x == 0 ||
     *      ((p[i-1].x != p[i].x || p[i].x != p[i+1].x) &&
     *       (p[i-1].y != p[i].y || p[i].y != p[i+1].y)))
     */ 
    for (i = 0; i < 4; i = i + 1)
    {   /* check whether the property does not hold for index i */
        if (!((p[i].x == p[i+1].x || p[i].y == p[i+1].y) &&
              (i == 0 ||
               ((p[i-1].x != p[i].x || p[i].x != p[i+1].x) &&
                (p[i-1].y != p[i].y || p[i].y != p[i+1].y)))))
        { /* ... that case terminate with an error message */
            printf("Not a rectangular polygon.%d\n",i);
            return 0;
        } /* ... other evaluate the next index */
    }
    /* Now, x and y describe a rectangular polygon.
     * Because of this, the lengths of the sides can be computed from
     * the first three points. 
     */
    if (p[0].x != p[1].x)
    {   /* This implies also that y[1] != y[2] */
        dx = distance(p[0].x,p[1].x);
        dy = distance(p[1].y,p[2].y);
    }
    else
    {   /* we have x[0] == x[1]
         * hence, y[0] != y[1] and x[1] != x[2]
         */
        dx = distance(p[1].x,p[2].x);
        dy = distance(p[0].y,p[1].y);
    }
    /* dx and dy contain the lengths of the two sides */
    area = dx * dy;
    /* area contains the area of the rectangular polygon */
    /* print output */
    printf("Area of the rectangular polygon: %d\n", area);
    
    /* return from body and exit program */
    return 0;
}