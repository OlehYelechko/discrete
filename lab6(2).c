#include <stdio.h>

long fact(int n){
      if(n < 2)
        return 1;
      else
       return n * fact(n-1);

}

long comb(int k, int n){
    //returns n! / k!(n-k)!
    return (fact(n) / (fact(k)*fact(n-k)));
}


int main(){
    int n = 9;
    printf("x^9 ");
    for(int i =1, p = 8; i < 9;p--,i++){
        printf("+ %dx^%dy^%d ",comb(i,n),p,i);
    }


    printf("+ y^9");
}
