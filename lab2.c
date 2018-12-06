#include <stdio.h>
#define size 10


int main(){
char Uni[size] = {'a','b','c','d','e','f','g','h','i','j'};
int setA[size];
int setB[size];
int setAbuff[size];
int setBbuff[size];
for(int i = 0; i < 10;i++){
    printf("Enter if '%c' is in A set(1 or 0):\n",Uni[i], i+1);
    scanf("%d", &setA[i]);
    while(setA[i] != 1 && setA[i] != 0){
        printf("Please enter 1 or 0:");
        scanf("%d", &setA[i]);
    }
}
for(int i = 0; i < 10;i++){
    printf("Enter if '%c' is in B set(1 or 0):\n",Uni[i], i+1);
    scanf("%d", &setB[i]);
    while(setB[i] != 1 && setB[i] != 0){
        printf("Please enter 1 or 0:");
        scanf("%d", &setB[i]);
    }
}
printf("Set A as a binary:");
for(int i = 0; i < size; i++)
    printf("%d", setA[i]);
printf("\n");
printf("Set A:");
for(int i = 0; i < size;i++){
    if(setA[i] == 1)
        printf("%c",Uni[i]);
}
printf("\n");
printf("Set B as a binary:");
for(int i = 0; i < size; i++)
    printf("%d", setB[i]);
printf("\n");
printf("Set B:");
for(int i = 0; i < size;i++){
    if(setB[i] == 1)
        printf("%c",Uni[i]);
}
printf("\n");
printf("The complementation of setA and setB as binary:");
for(int i = 0; i < size; i++)
    printf("%d", setA[i] & ~setB[i]);
printf("\n");
printf("The complementation of setA and setB:");
 for(int i = 0; i < size;i++){
    if((setA[i] & ~setB[i]) == 1)
        printf("%c",Uni[i]);
}
}
