#include <stdio.h>
#include <stdbool.h>

// This is just the definition of a convolution
// refer to Number Theory (Rosen) for the mathematical formula,
// although this basically is it, for functions f, g
int convolution( unsigned int n, int f(unsigned int), int g(unsigned int)){
  int retVal = 0;

  for(unsigned int i = 1; i <= n; i++){
    if(n % i == 0){
      retVal += f(i) * g(n/i);
    }
  }

  return retVal;

}


// I love recursion
unsigned int gcd(unsigned int a, unsigned int b){
  if (a > b){
    return gcd(b, a);
  }
  if (a == 0){
    return b;
  }
  return gcd(b % a, a);
}


// bruh
int one(unsigned int a){
  return 1;
}

// Function to find the totient 
// without making me want to blow
// my brains out

int totient(unsigned int n){
  int retVal = 0;

  for(int i = 1; i <= n; i++){
    retVal += (gcd(i, n) == 1);
  }

  return retVal;
}

int sigma0(unsigned int n){
  int retVal = 0;

  for (int i = 1; i <= n; i++){
    retVal += (n % i == 0);
  }
  return retVal;
}
int sigma1(unsigned int n){
  int retVal = 0;

  for (int i = 1; i <= n; i++){
    retVal += (n % i == 0) * i;
  }
  return retVal;
}


int main(){
  int testVariable;
  while (true){
    printf("Put an integer here: ");
    scanf("%d", &testVariable);
    printf("%d\n", convolution(testVariable, one, sigma1) );
  }

  return 0;
}

