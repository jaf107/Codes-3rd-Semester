#include<bits/stdc++.h>
using namespace std;
int G[100][100];
int inDegree[100],myQueue[100],front=0,rear=0;
int result[100],countSorted=0;
int main()
{
    int n,e;

    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        inDegree[i]=0;
    }

    cout<<"Enter edges: \n";
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u][v]=1;
        inDegree[v]++;
    }
    for(int i=0;i<n;i++)
    {
        if(inDegree[i]==0)
        {
            myQueue[rear++]= i;

        }
    }


    while(front <= rear)
    {
        int dequed = myQueue[front++];
        result[countSorted++]= dequed;

        for(int i=0;i<n;i++)
        {
            if(G[dequed][i]==1)
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                {
                    myQueue[rear++]= i;
                }
            }
        }

    }
    if(countSorted-1 == n)
    {
        printf("Topological Sort: ");
        for(int i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
    }
    else
    {
        printf("Hoilona :3  ");
    }
}
