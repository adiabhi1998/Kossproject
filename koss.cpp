#include <bits/stdc++.h>
#define inf 1000000

using namespace std;
int nodes,edges;
char station[100][100];

int floyd[100][100];
int parent[100][100];
int next[100][100];
void floyd_warshall(int a[][100])//using floyd warshall algorithm, as we need multiple source shortest paths,here a[][100] can be either cost or time
{
	
	for(int i=1;i<=nodes;i++)
	for(int j=1;j<=nodes;j++)
	{
		floyd[i][j]=a[i][j];
		next[i][j]=j;//for backtracking the shortest path,using a simple recursion
	}
	for(int k=1;k<=nodes;k++)
	{
		for(int i=1;i<=nodes;i++)
		{
			for(int j=1;j<=nodes;j++)
			{int initial=floyd[i][j];
						floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
						if(initial!=floyd[i][j])
						next[i][j]=next[i][k];//if the shortest path involves the vertex k, we update the backtracking array next.
						
		}
		}
	}
	
	
	
}



int main()
{
    //adjacency matrix for a weighted graph of stations
    int a[100][100];
    int t[100][100];
cout<<"enter number of stations";    
    cin>>nodes;
  cout<<"enter the number of connections";
  
    int edges;
    cin>>edges;
    for(int i=1;i<=nodes;i++)
for(int j=1;j<=nodes;j++)
{
	if(i==j)
	a[i][j]=t[i][j]=0;
	else
	a[i][j]=t[i][j]=inf;
}
    for(int i=0;i<edges;i++)
    {int x,b;
    cin>>x>>b;
    cout<<"enter cost of ticket and time of journey in minutes";
    int cost;
    cin>>cost;
    int time;
    cin>>time;
    a[x][b]=a[b][x]=cost;//assuming that trains travel both ways
    t[x][b]=t[b][x]=time;
    
}

    cout<<"enter stations for shortest path";
    int x1,x2;
    cin>>x1>>x2;
    if(a[x1][x2]!=inf)
    cout<<"There is a direct train between the two stations costing rs."<<a[x1][x2]<<"and taking time "<<t[x1][x2]<<" mins";
    
    cout<<"do you want to minimize time or cost?press t for time and c for cost\n "
    ;char ch;
    cin>>ch;
    
    if(ch=='c')
    {
	
    floyd_warshall(a);
    cout<<" smallest cost is\n"<<floyd[x1][x2];
    cout<<"\nshortest path is\n";
    int k=x1;
    cout<<k<<"->";

    do{k=next[k][x2];
    	cout<<k<<"->";
    	
	}while(k!=x2);
}
else
{
	floyd_warshall(t);
    cout<<" fastest time is\n"<<floyd[x1][x2];
    cout<<"\nshortest time path is\n";
    int k=x1;
    cout<<k<<"->";

    do{k=next[k][x2];
    	cout<<k<<"->";
    	
	}while(k!=x2);
	
}
        
        
    }
    
    
    

