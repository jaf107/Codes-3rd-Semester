#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

int sccC[100];
int G[100][100],TG[100][100];
int color[100], d[100], f[100], prev[100];
int timeT;
stack<int> ftimeT;

void print_path(int s, int v)
{
    if(s==v)
    {
        printf("%d->",s);
    }
    else if(prev[v]==-1)
    {
        printf("No Path");
    }
    else
    {
        print_path(s,prev[v]);
        printf("%d->",v);
    }
}

void DFS_visit(int u, int n)
{
    timeT++;
    d[u]=timeT;
    color[u]=GRAY;
    for(int v=0; v<n; v++)
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
    timeT++;
    f[u]=timeT;
    ftimeT.push(u);
    color[u]=BLACK;
}
void DFS_visit2(int u, int n,int c)
{
    sccC[u] = c;


    color[u]=GRAY;
    for(int v=0; v<n; v++)
    {
        if(TG[u][v]==1)
        {
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visit2(v,n,c);
            }
        }
    }
    color[u]=BLACK;
}
void DFS(int n)
{
    for(int i=0; i<n; i++)
    {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0; u<n; u++)
    {
        if(color[u]==WHITE)
        {
            DFS_visit(u,n);
        }
    }
}
void DFS2(int n)
{
    int c=1;

    for(int i=0; i<n; i++)
    {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=ftimeT.top(); !ftimeT.empty(); ftimeT.pop())
    {
        if(color[u]==WHITE)
        {
            DFS_visit2(u,n,c);
            c++;
        }

    }
}

int main()
{
    int n, e, u, v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        TG[v][u]=1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    DFS(n);
    DFS2(n);


    for(int i=0; i<n; i++)
    {
        printf("%d ",sccC[i]);
    }
    printf("\n");
    /*
    for(int i=0; i<n; i++)
    {
        printf("%d ",d[i]);
    }

    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ",f[i]);
    }

    printf("\n");

    for(int i=0; i<n; i++)
    {
        printf("%d ",prev[i]);
    }

    printf("\n");
    print_path(0,5);*/
    return 0;
}
