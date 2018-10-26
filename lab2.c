#include <stdio.h>
#include <cs50.h>


int main(){
 printf("Enter number elements of setA:");
int a = get_int();
char setA[a];
for(int i = 0; i < a; i++){
  printf("Enter element of setA(that not repeat):");
  setA[i] = get_char();
}

printf("Enter number elements of setB:");
int b = get_int();

char setB[b];
for(int i = 0; i < b; i++){
 printf("Enter element of setB(that not repeat):");
 setB[i] = get_char();
}
//char setA[5] = {'a','b','c','d','e'};
//char setB[5] = {'f','g','e','c','b'};

//char setnotB[2] = {'a','b'};
char setnotBprot[a+b];
int t = 0;
for(int i = 0; i<a;i++){
 for(int j = 0; j< b;j++){
  if(setA[i] ==setB[j]){
   setnotBprot[t] = setA[i];
   t++;
  }
 }
}

for(int i = 0; i < a; i++){
 for(int j = 0; j < t; j++){
   if(setA[i] ==setnotBprot[j]){
     setA[i]= 0;
   }
 }
}
char setnotB[a-t];
int f = 0;
for(int i = 0; i < a; i++){
 if(setA[i] != 0){
  setnotB[f] = setA[i];
  f++;
 }
}
int power = 0;
for(int i = 0; i < 5-t; i++){
 printf("Difference and complement elements:%c\n",setnotB[i]);
 power++;
}
printf("Power is:%d\n", power);

}
