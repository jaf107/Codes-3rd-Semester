#include<stdio.h>

#define WHITE 0
#define GREY 1
#define BLACK 2


int G[100][100];

int color[100], d[100],f[100], prev[100];
int front=0, rear=0;
int time=0;


int path_existence(int s, int v)
{
    if(s==v)
    {
        return 1;
    }

    else if(prev[v]==-1)
        return 0;
    else
    {
        path_existence(s,prev[v]);
    }

}

int tree_edge(int u,int v)
{
    if(u== prev[v]){
        return 1;
    }
        return 0;
}

int forward_edge(int u,int v)
{
    if((d[u]<d[v]) && path_existence(u,v)){
        return 1;
    }
        return 0;
}

int back_edge(int u,int v)
{
    if((d[u]>d[v]) && path_existence(v,u)){
        return 1;
    }
        return 0;
}

DFS_visit(int u,int n)
{

            time++;
            int v;
            d[u]=time;
            int i;
            color[u]=GREY;
            for(v=0;v<n;v++)
            {
                if(G[u][v]==1)
                {
                    if(color[v]==WHITE)
                    {
                        prev[v]=u;
                        DFS_visit(v,n);
                    }
                }
            }
            time++;
            f[u]=time;
            color[u]= BLACK;
}



void DFS(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        color[i]=WHITE;
        prev[i]=-1;

    }
    for(i=0;i<n;i++)
    {
        if(color[i]==WHITE)
        {
            DFS_visit(i,n);
        }

    }
}
int main()
{
    //n= node number e= edge number u,v= values, i= iterator
    int n,e,u,v,i,s,j;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Enter number of edges : ");
    scanf("%d",&e);


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }
    for(i=0;i<e;i++)
    {
        printf("Enter edges: ");
        scanf("%d %d",&u,&v);
        G[u][v]= 1;
    }

    DFS(n);
    //printf("%d %d",d[0],d[2]);
    getchar();
    char ch;
    printf("Enter 'a' to search 'e' to exit: ");
    scanf("%c",&ch);
    while(ch!='e')
    {
        int u1,u2;
        printf("Enter the edge: ");
        scanf("%d %d",&u1,&u2);
        //printf("%d ",prev[u2]);
        //tree_edge(u1,u2);
        if(tree_edge(u1,u2)==1)
        {
            printf("Tree edge!\n");
        }
        else if(forward_edge(u1,u2)==1)
        {
            printf("Forward edge!\n");
        }
        else if(back_edge(u1,u2)==1)
        {
            printf("Back edge!\n");
        }
        else
            printf("Cross edge!\n");
        getchar();
        printf("Enter 'a' to search 'e' to exit: ");
        scanf("%c",&ch);
    }
    return 0;
}
