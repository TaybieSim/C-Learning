#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
// prints a table of values for sine and cosine between (0, 1)
int main(void)
{ 
    double interval;
    int i;

    for(i = 0; i <10; i++)
    {
        interval = i/10.0; //interval ranges from 0 to 1;

        printf("sin( %lf ) = %lf\t", interval, sin(interval));
        printf("cos( %lf ) = %lf\n", interval, cos(interval));
        

    }
    
    
    
    printf("\n+++++++\n");
    return 0;
}