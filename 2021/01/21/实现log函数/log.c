#include <stdio.h>
#include <math.h>
#define SQRT2 1.4142135623730950488016887242097
#define SQRT2D2 0.70710678118654752440084436210485
#define LN2H 6.93147180369123816490e-01
#define LN2L 1.90821492927058770002e-10

double ln(double x){  
    int k=0;
    if(x>SQRT2){
        do
        {
            x/=2;
            k++;
        } while (x>SQRT2);
    }else if(x<SQRT2D2){
        do
        {
            x*=2;
            k--;
        } while (x<SQRT2D2);
    }
    double res=k*LN2H+k*LN2L;
    x-=1;
    x=x/(2+x);
    for(int i=1;i<14;i+=2){
        double s=x;
        for(int c=1;c<i;c++){
            s*=x;
        }
        res+=2*s/i;
    }
    return res;
}

double mylog(double b,double a){
    return ln(b)/ln(a);
}

int main(){
    printf("%lf %lf",mylog(15,2),log(15)/log(2));
    return 0;
}
