/* Assignment1 - Polyeval
 * by Josh Betz (Lecture 1) and John Zancanaro (Lecture 1)
 *
 * This program takes in a polynomial as command line arguments
 * and evaluates it at a certain "x" value.
 */

#include <stdio.h>
int getXValue( char *argument, int *x );
int storeCoef( char *cmdline[], int numcoef, int coefficients[] );
void printPoly( int coefficients[], int degree );
int evaluate( int coefficients[], int degree, int x );
int power( int x, int y );

#define ARRAYSIZE 5

main( int argc, char *argv[] ) {
  int x, *px;
  px = &x;
  
  int xValueIsGood;
  xValueIsGood = getXValue(argv[argc-1], px);/*make sure x= # is there*/
  
  if( argc < 3 || argc > ARRAYSIZE || xValueIsGood == -1 ) {
    if( argc < 3 ) {
      printf("Not enough coefficients. ");
    } else if( argc > ARRAYSIZE ) {
      printf("Too many coefficients. ");
    }
    if( xValueIsGood == -1 ) {
      printf("Bad command line.\n");
    } else {
      printf("\n");
    }
        
    return;/*If it gets here, it is bad*/
  }
  
  int degree = argc-3;
  
  int coefs[degree + 1];/*Storing Coefs*/
  storeCoef(argv, degree + 1, coefs);
  
  printPoly(coefs, degree);
  
  int eval;
  eval = evaluate(coefs, degree, x);
  printf("f(%d) = %d\n", x, eval); /*final print part*/
}

/* getXValue returns -1 if *argument is bad, 0 otherwise
 * Parameters:
 *  argument: pointer to a string
 *  x: value to evaluate polynomial at
 */
int getXValue( char *argument, int *x ) {
  /* check that *argument starts with "x=" */
  if( *argument == 'x' ) { 
    argument++;
    if( *argument == '=' ) {
      argument++;
      *x = atoi(argument);
      return 0;
    }
  }
  return -1;
}


/* storeCoef extracts the integer coefficents and
 *   returns degree of polynomail, or -1 on error 
 * Parameters:
 *  numcoef: number of coefs to extract
 *  coefficients[]: array to put coefs into
 */
int storeCoef( char *cmdline[], int numcoef, int coefficients[] )  {
  int i;
  for( i=0; i<numcoef; i++ ) {
    coefficients[i] = atoi(cmdline[i+1]);
  }
  return numcoef - 1;
}

/* printPoly prints the polynomial
 * Parameters:
 *  coefficients[]: what to put in front of x 
 *  degree: used to know what to raise x to
 */
void printPoly( int coefficients[], int degree ) {
  printf("Polynomial entered:\n");
  int count;
  count = 0;
  
  /* Print part before first "+" */
  printf("%dx^%d", coefficients[count], degree);
  count++;
  degree--;
  
  /* Print part after first "+" */
  while( degree >= 0 ){
    printf(" + %dx^%d", coefficients[count], degree);
    count++;
    degree--;
  }
  printf("\n");
}

/* evaluate evaluates the polynomial
 * Parameters:
 *  coefficients[]: the nuber that gets multiplied to the x^power
 *  degree: power of the functions
 *  x: base of the function
 */
int evaluate( int coefficients[], int degree, int x ) {
  int count, sum;
  count = 0;
  sum = 0;
  
  while ( degree >= 0 ) {
    sum += coefficients[count] * power(x,degree);
    count++;
    degree--;
  }
  return sum;
}

/* returns value of x^y
 * Parameters:
 *  x: base of the function
 *  y: exponent of the function
 */
int power( int x, int y ) {
  int i, sum;
  sum = 1;
  for( i=0; i<y; i++ ) {
    sum *= x;
   }
  return sum;
}

