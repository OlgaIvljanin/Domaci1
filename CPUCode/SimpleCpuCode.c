/* Neka je f(x)=x^3-x-1, nula se nalazi u intervalu (1,2) jer je f(1) = -1 a f(2)=5.
Pretpostavimo da je x0=1.5 i tacnost na 13 decimalnih mesta. 
Maksimalan broj iteracija je 10.
*/
#include <stdio.h>
#include <math.h>

#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

double f(double x){
    return x*x*x-x-1;
   // return x*x - cos(x);
}

double df(double x){
   return 3*x*x-1;
   // return 2*x+sin(x);
}

int main(){
int maxiter = 10;
int i;
double e =0.0000000000001; //0.0001;  
double x0=1.5;              //1;
double h,x1;

for(i = 1; i<= maxiter;i++){
    h = f(x0)/df(x0);
    x1=x0-h;
    printf("At iteration no. %d, x= %15.13f\n",i, x1);
    x0=x1;
}
 if (fabs(h) < e){
    printf("After %d iterations , root = %15.13f \n", i-1, x1);
        
    }
else{
  printf("The required solution does not converge or iterations are insufficient\n");
}
return 0;}

/*
Primer ako zelimo da nam prekine izvrsavanje programa cim nadje odgovarajuce resenje.

#include <stdio.h>
#include <math.h>

#include <MaxSLiCInterface.h>
#include "Maxfiles.h"

double f(double x){
    return x*x*x-x-1;
   // return x*x - cos(x);
}

double df(double x){
   return 3*x*x-1;
   // return 2*x+sin(x);
}

int main(){
int maxiter = 100;
int i;
double e =0.0000000000001; //0.0001;  
double x0=1.5;              //1;
double h,x1;

for(i = 1; i< maxiter;i++){
    h = f(x0)/df(x0);
    x1=x0-h;
    printf("At iteration no. %d, x= %15.13f\n",i, x1);

   if (fabs(h) < e){
    printf("After %d iterations , root = %15.13f \n", i, x1);
    return 0;
        
    }
  
    x0=x1;
}

  printf("The required solution does not converge or iterations are insufficient\n");

}


*/