#include<stdio.h>
#define N 512
#define A 0.0   //積分区間下端
#define B 1.0   //積分区間上端

double f(double x){     //積分する関数f(x)
    return 4/(1 + x*x);
}

int main(){
    double n, a, delta, value;     //n:分割数  delta:台形の幅 value:積分値
    int i;
    n = 2;
    while(n <= N){      //N分割の積分値まで順に計算
        value = 0.0;
        delta = (B - A) / n;
        for(i = 0; i < n; i++){    
            a = A + i * delta;
            value += ((f(a) + f(a + delta) + 4.0 * f(a + delta / 2.0)) * delta) / 6.0;       
        }
        printf("%.14f\n", value);
        n *= 2;
    }
}