#include <stdio.h>
#include <math.h>

int main(){

    /* Enter arrays A and B */
    int size;
    printf("Enter size of arrays: ");
    scanf("%d", &size);
    printf("Enter array A\n");
    int A[size];
    for(int i=0; i<size; i++){
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    int B[size];
    printf("\nEnter array B\n");
    for(int i=0; i<size; i++){
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }
    printf("\nA = ");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("B = ");
    for(int i=0; i<size; i++){
        printf("%d ", B[i]);
    }
    printf("\n");


    /* Generate the binary matrix */
    int matr[size][size];
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            if(A[r] <( 2*B[c] + 1))
                matr[r][c] = 1;
            else
                matr[r][c] = 0;
        }
    }


    /* Print generated binary matrix */
    printf("\n");
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            printf("%d ", matr[r][c]);
            if(c==size-1)
                printf("\n");
        }
    }


    /* Generate the inverse matrix */
    int antimatr[size][size];
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            antimatr[r][c] = matr[c][r];
        }
    }


    /* Check for 0 */
    int flag7 = 0;
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            if(matr[r][c]== 1)
                flag7 = 1;
        }
    }



    /* Check for reflexivity */
    printf("\n");
    int flag1=1;
    for(int i=0; i<size; i++){
        if (matr[i][i]==0)
            flag1=0;
    }
    if(flag1==1)
        printf("This relation is reflexive.\n");
    else if(flag1==0)
        printf("This relation is not reflexive.\n");


    /* Check for antireflexivity */
    int flag2=0;
    for(int i=0; i<size; i++){
        if (matr[i][i]==1)
            flag2=1;
    }
    if(flag2==0)
        printf("This relation is antireflexive.\n");
    else if(flag2==1)
        printf("This relation is not antireflexive.\n");


    /* Check for symmetry */
    int flag3=1;
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            if((r!=c) && (antimatr[r][c]!=matr[r][c]))
                flag3 = 0;
        }
    }

    if(flag3==1)
        printf("This relation is symmetric\n");
    else if(flag3==0)
        printf("This relation is not symmetric\n");


    /* Check for antisymmetry */
    int flag4=0;
    for(int r=0; r<size; r++){
        for(int c=0; c<size; c++){
            if((r!=c) && (antimatr[r][c]==matr[r][c]))
                flag4 = 1;
        }
    }
    if(flag4==0)
        printf("This relation is antisymmetric\n");
    else if(flag4==1)
        printf("This relation is not antisymmetric\n");


    /* Check for transitivity */
    int Asize = pow(size, 3);
    int Aflag[Asize];
    int ai=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            for(int k=0; k<size; k++){
                if((i!=j && i!=k && j!=k) && (matr[i][j] == 0 || matr[j][k] == 0))
                    Aflag[ai]=1;
                else if((i!=j && i!=k && j!=k) && (matr[i][j] == 1 && matr[j][k] == 1 && matr[i][k] == 1))
                    Aflag[ai]=1;
                else if ((i!=j && i!=k && j!=k) && (matr[i][j] == 1 && matr[j][k] == 1 && matr[i][k] == 0))
                    Aflag[ai]=0;
                else
                    Aflag[ai]=1;
                ai++;
            }
        }
    }
    int flag5 = 1;
    for (int i=0; i<Asize; i++){
        if(Aflag[i]==0)
            flag5=0;
    }
    if(flag7 == 0)
        flag5 = 0;
    if(flag5==1)
        printf("This relation is transitive\n");
    else if(flag5==0)
        printf("This relation is not transitive\n");


    /* Check for antitransitivity */
    int Bsize = pow(size, 3);
    int Bflag[Bsize];
    int bi=0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            for(int k=0; k<size; k++){
                if((i!=j && i!=k && j!=k) && (matr[i][j] == 0 || matr[j][k] == 0))
                    Bflag[bi]=1;
                else if((i!=j && i!=k && j!=k) && (matr[i][j] == 1 && matr[j][k] == 1 && matr[i][k] == 1))
                    Bflag[bi]=0;
                else if ((i!=j && i!=k && j!=k) && (matr[i][j] == 1 && matr[j][k] == 1 && matr[i][k] == 0))
                    Bflag[bi]=1;
                else
                    Bflag[bi]=1;
                bi++;
            }
        }
    }
    int flag6 = 1;
    for (int i=0; i<Bsize; i++){
        if(Bflag[i]==0)
            flag6=0;
    }
    if(flag7 == 0 || flag5==1)
        flag6 = 0;
    if(flag6==1)
        printf("This relation is antitransitive\n");
    else if(flag6==0)
        printf("This relation is not antitransitive\n");

    printf("\n");
}
