#include<iostream>
using namespace std;

#define INF 999

int main()
{
    int n;
    int cost[20][20];
    int visited[20] = {0};

    int edges = 0;
    int totalCost = 0;

    cout<< "Enter number of vertices:";
    cin>>n;

    cout<<"Enter the cost adjacency matrix:/n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            cin >> cost[i][j];

            if(cost[i][j] == 0)
            cost[i][j] = INF;
        }
    }
    

    visited[0] = 1;

    cout<< "\nEdges in Minimum Cost Spanning Tree:\n";

    while(edges < n - 1)
    {

        int min = INF;
        int u = -1;
        int v = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u == -1)
        {
            cout << "Graph is not connected.\n";
            return 0;
        }

        cout << u + 1 << "-" << v + 1 << " :  " << min << endl;
        totalCost += min;

        visited[v] = 1;
        edges++;
    }
    cout<< "\nMinimum Cost ="<< totalCost << endl;
    return 0;
}
