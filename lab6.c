#include <stdio.h>
int main(){
    int a1[3] ={1,2,3};
    int a2[3] ={2,3,4};
    int a3[3] ={3,4,5};
    int a4[3] ={4,5,6};
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++){
            for(int k =0; k < 3; k++){
                for(int l =0; l < 3; l++){
                   if(a1[i]<a2[j] &&a2[j]<a3[k]&& a3[k]<a4[l])
                    printf("%d%d%d%d\n",a1[i],a2[j],a3[k],a4[l]);
                }
            }
        }
    }


}
