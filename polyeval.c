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

/*
EXAMPLE:
  polyeval  1 -6   80000  x=12
  Polynomial entered:
  1x^2 + -6x^1 + 80000x^0
  f(12) = 80072
*/

main( int argc, char *argv[] ) {
  int x, *px;
  px = &x;
  
  int xValueIsGood;
  xValueIsGood = getXValue(argv[argc-1], px);
  
  if( argc < 3 || argc > 5 || xValueIsGood == -1 ) {
    if( argc < 3 ) {
      printf("Not enough coefficients. ");
    } else if( argc > 5 ) {
      printf("Too many coefficients. ");
    }
    if( xValueIsGood == -1 ) {
      printf("Bad command line.\n");
    } else {
      printf("\n");
    }
        
    return;
  }
  
  int degree = argc-3;
  
  int coefs[degree + 1];
  storeCoef(argv, degree + 1, coefs);
  
  printPoly(coefs, degree);
  
  int eval;
  eval = evaluate(coefs, degree, x);
  printf("f(%d) = %d\n", x, eval);
}

/* getXValue returns -1 if *argument is bad, 0 otherwise
 * Parameters:
 *  argument: pointer to a string
 *  x: value to evaluate polynomial at
 */
int getXValue( char *argument, int *x ) {
  /* TODO: check that *argument starts with "x=" */
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
 *  coefficients[]: 
 *  degree: 
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
 *  coefficients[]: 
 *  degree: 
 *  x:
 */
int evaluate( int coefficients[], int degree, int x ) {
  int count, sum;
  count = 0;
  sum = 0;
  
  /* TODO: fix pow */
  while ( degree >= 0 ) {
    sum += coefficients[count] * power(x,degree);
    count++;
    degree--;
  }
  return sum;
}

int power( int x, int y ) {
  int i, sum;
  sum = 1;
  for( i=0; i<y; i++ ) {
    sum *= x;
   }
  return sum;
}

