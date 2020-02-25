#include<bits/stdc++.h>
using namespace std;
int graph[10][10]= {0},n,cost[10],prev[10],visited[10];
int extractMin()
{
    int minH = INT_MAX,u;
    for(int i=0; i<n; i++)
    {
        if(visited[i]==0 && cost[i]<minH)
        {
            minH = cost[i];
            u=i;
        }
    }
    return u;
}
void initializeSingleSource(int s)
{
    for(int i=0; i<n; i++)
    {
        cost[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }
    cost[s] = 0;
}
void relax(int u,int v)
{
    if(cost[v] > graph[u][v] && visited[v]==0)
    {
        cost[v] = graph[u][v];
        prev[v] = u;
    }
}

void prim(int s)
{
    int u;
    initializeSingleSource(s);
    while(true)
    {
        u = extractMin();
        visited[u] = 1;
        for(int v=0; v<n; v++)
        {
            if(graph[u][v] !=0)
            {
                relax(u,v);
            }

        }
        int i=0;
        for(; i<n; i++)
        {
            if(visited[i] == 0)
                break;
        }
        if(i==n)
            break;


    }

}
int main()
{
    int m,u,v,w;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    prim(0);
    int MST=0;

    cout<<cost[0];
    for(int i=1; i<n; i++)
    {
        cout<<" + "<<cost[i];
        MST+=cost[i];
    }
    cout<<endl;
    cout<<MST;
    return 0;
}
