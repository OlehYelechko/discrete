#include <stdio.h>
#include <cs50.h>
int main(){
 bool a, b;
 int x, y, z;
 bool d = a == b;
  do{
     printf("x: ");
     x = GetInt();
     }while(x != 0 && x != 1);
  do{
     printf("y: ");
     y = GetInt();
     }while(y != 0 && y != 1);
  do{
     printf("z: ");
     z = GetInt();
     }while(z != 0 && z != 1);
    if(x == !(y && z)){
         a = 1;
    }else{
         a = 0;
    }
    if(x == (y && z)){
         b = 1;
    }else{
        b = 0;
    }
    printf("Answer is: %d\n", d);
}