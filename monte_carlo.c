#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float frandom(){
  long int q = random();
  float r = (float)q/(float)RAND_MAX;
  return r;
}

float mc_pi(int n){
int incirc=0,i=0;
float x,y,d,pi;

for(i=0;i<n;i++)
{
x=frandom();
y=frandom();
d=((x*x)+(y*y));
if(d<=1){
incirc++;
}
}
pi=4*(float)incirc/n;
return pi;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}




