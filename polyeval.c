/* Assignment1 - Polyeval
 * by Josh Betz
 *
 * This program takes in a polynomial as command line arguments
 * and evaluates it at a certain "x" value.
 */

#include <stdio.h>

#define ARRAYSIZE 5

/*
EXAMPLE:
  polyeval  1 -6   80000  x=12
  Polynomial entered:
  1x^2 + -6x^1 + 80000x^0
  f(12) = 80072
*/

main( int argc, char *argv[] ) {
  if( argc < 3 ) {
    printf("Not enough coefficients. Bad command line\n");
    return;
  } else if( argc > 5 ) {
    printf("Too many coefficients. Bad command line.\n");
    return;
  } else if(getXValue(/*last argument*/) == -1){
    printf("Bad command line.\n");
    return;
  }

  /* TODO: implement rest of `main()` */
}

/* getXValue returns -1 if *argument is bad, 0 otherwise
 * Parameters:
 *  argument:
 *  x: 
 */
int getXValue( char *argument, int *x ) {
  /* TODO: check that *argument starts with "x=" */
  /* TODO: turn everything after "x=" into an integer with `atoi()` */

}


/* storeCoef extracts the integer coefficents and
 *   returns degree of polynomail, or -1 on error 
 * Parameters:
 *  numcoef: number of coefs to extract
 *  coefficients[]: array to put coefs into
 */
int storeCoef( char *cmdline[], int numcoef, int coefficients[] )  {
  
}

/* printPoly prints the polynomial
 * Parameters:
 *  coefficients[]: 
 *  degree: 
 */
void printPoly( int coefficients[], int degree ) {
  printf("Polynomial entered:\n");
  int count, *pcount;
  count = 0;
  pcount = count;
  
  degree--;/*Do the initial line*/
  printf("%dx^%d" coefficients[pcount],degree);
  pcount++;
  while(degree > 1){
    degree--;
    printf(" + %dx^%d" coefficients[pcount],degree);
    pcount++;
  }
  /*int x = getXValue();*/  /* figure out what goes into getXValue()*/
  /*int *px = x*/
  printf("f(%d) = %d\n" /*px*/, evaluate(coefficients[], degree, /*px*/); 
}

/* evaluate evaluates the polynomial
 * Parameters:
 *  coefficients[]: 
 *  degree: 
 *  x:
 */
int evaluate( int coefficients[], int degree, int x ) {
  int sum, *psum;
  sum =0;
  psum = sum;
  int count, *pcount;
  count = 0;
  pcount = count
  while (degree != 0){
    degree--;
    psum += (coefficients[count]^degree)* x;
    count++;
  }
  return sum;
}
