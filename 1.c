#include <stdio.h>
void    input_arr (int    arr[100],    int   n) {
    int    i;
    for (i = 0; i < n; i++) {
    printf ("Enter a number: "); 
    scanf ("%d", &arr[i]);
} }
void   print_arr (int    arr[100],    int   n) {
    int    i;
    printf ("Entered numbers are "); for (i = 0; i < n; i++) 
    printf ("%d    ", arr[i]); printf ("\n");
}
void   get_max_min (int    arr[100],    int    n,    int * max,   int * min) {     
//  배열에    저장된    n 개의    정수    중에서,  최대값을    *max 에    최소값을    *min 에    저장한다. 
    int    i;
    *max = arr[0];
    for (i = 1; i < n; i++) 
    { 
        if (*max < arr[i]) 
        *max = arr[i]; 
    }
    *min = arr[0];
    for (i = 1; i < n; i++) 
    { 
        if (*min > arr[i])
        *min = arr[i]; 
    }
}
int main (void) {
    int    A[100];
    int    N,   x,   y; 
    printf ("Enter   N : ");
    scanf ("%d", &N); 
    input_arr (A, N);
    print_arr (A, N); x = 0; y = 0;
    get_max_min (A, N, &x, &y); 
    printf ("x = %d \n", x);                
    printf ("y = %d \n", y);
return 0;
}