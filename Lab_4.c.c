#include<stdio.h>
#define MAX 30
#define VERT 11

typedef struct edge
{
    int u,v,w;
}edge;

typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;

edgelist elist;
//matrix of adjacency
int G[11][11] = {{0,4,3,2,0,0,0,0,0,0,0},
                  {4,0,0,0,2,0,1,0,0,0,0},
                  {3,0,0,0,6,7,0,0,0,0,0},
                  {2,0,0,0,0,2,7,0,0,0,0},
                  {0,2,6,0,0,0,0,4,7,0,0},
                  {0,0,7,2,0,0,0,4,0,3,0},
                  {0,1,0,7,0,0,0,0,5,5,0},
                  {0,0,0,0,4,4,0,0,0,0,4},
                  {0,0,0,0,7,0,5,0,0,0,1},
                  {0,0,0,0,0,3,5,0,0,0,3},
                  {0,0,0,0,0,0,0,4,1,3,0}};
int G1[11][11] = {{0,3,6,1,0,0,0,0,0,0,0},
                  {3,0,0,0,3,0,2,0,0,0,0},
                  {6,0,0,0,7,5,0,0,0,0,0},
                  {1,0,0,0,0,2,2,0,0,0,0},
                  {0,3,7,0,0,0,0,7,1,0,0},
                  {0,0,5,2,0,0,0,4,0,3,0},
                  {0,2,0,2,0,0,0,0,4,4,0},
                  {0,0,0,0,7,4,0,0,0,5,0},
                  {0,0,0,0,1,0,4,0,0,0,4},
                  {0,0,0,0,0,3,4,0,0,0,7},
                  {0,0,0,0,0,0,0,5,4,7,0}};
int n;
edgelist spanlist;

void kruskal();
int find(int belongs[],int vertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void print();

int main()
{
    int i,j,total_cost;
    printf("         Kruskal Algorithm         \n");
    n = VERT;
    kruskal();
    print();
    }

void kruskal()
{
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;

    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(G[i][j]!= 0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }

    sort();

    for(i=0;i<n;i++)
        belongs[i]=i;

    spanlist.n=0;

    for(i=0;i<elist.n;i++)
    {
        cno1=find(belongs,elist.data[i].u);
        cno2=find(belongs,elist.data[i].v);

        if(cno1!=cno2)
        {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n=spanlist.n+1;
            union1(belongs,cno1,cno2);
        }
    }
}

int find(int belongs[],int vertexno)
{
    return(belongs[vertexno]);
}

void union1(int belongs[],int c1,int c2)
{
    int i;

    for(i=0;i<n;i++)
        if(belongs[i]==c2)
            belongs[i]=c1;
}

void sort()
{
    int i,j;
    edge temp;

    for(i=1;i<elist.n;i++)
        for(j=0;j<elist.n-1;j++)
            if(elist.data[j].w>elist.data[j+1].w)
            {
                temp=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=temp;
            }
}

void print()
{
    int i,cost=0;

    for(i=0;i<spanlist.n;i++)
    {
        printf("\n[%d]--->[%d] = %d",spanlist.data[i].u+1,spanlist.data[i].v+1,spanlist.data[i].w);
        cost=cost+spanlist.data[i].w;
    }

    printf("\n\nCost of the spanning tree=%d",cost);
}
