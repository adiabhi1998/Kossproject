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
	cout<<"Welcome.This program computes shortest paths between two stations based on cost and time when there is no direct train\n between the two.If there is, it reports the time and cost of the direct train,else it uses Floyd Warshall\n algorithm to compute the shortest path\n"
    
    ;int a[100][100];//adjacency matrix for a weighted graph of stations to maintain cost
    int t[100][100];//same as above, for maintaing times of travel between stations
    char ch3;//to be used later as a choice for continuing the program or exiting
	cout<<"enter number of stations";    
    cin>>nodes;
  cout<<"enter the number of trains\n";
  
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
    cout<<"enter two station codes of travel for train "<<i+1<<"(station codes are between 1 to "<<nodes<<")";
    cin>>x>>b;
    
    if(x>nodes||b>nodes||x<=0|b<=0)
    {
    	cout<<"\n enter valid station codes\n";
    	cin>>x>>b;
	}
    cout<<"\nenter cost of ticket and time of journey in minutes\n";
    int cost;
    cin>>cost;
    int time;
    cin>>time;
    
    a[x][b]=a[b][x]=cost;//assuming that trains travel both ways
    t[x][b]=t[b][x]=time;
	}
	
    
do{


    cout<<"\nenter stations for shortest path\n";
    int x1,x2;
    cin>>x1>>x2;
    if(a[x1][x2]!=inf)
   {
	 cout<<"\nThere is a direct train between the two stations costing rs."<<a[x1][x2]<<"and taking time "<<t[x1][x2]<<" mins";
	  cout<<"\n do you want to continue querying for more shortest/cheapest paths?Enter y for yes, any other key to exit \n";
    char ch2;
    cin>>ch2;
    if(ch2=='y')
    continue;
    else
    break;

}
    cout<<"do you want to minimize time or cost?press t for time and c for cost\n "
    ;char ch;
    cin>>ch;
    
    if(ch=='c')
    {
	
    floyd_warshall(a);
    if(floyd[x1][x2]==inf)
    {
    	cout<<"\n no route exists between the two stations";
    cout<<"\n do you want to continue querying for more shortest/cheapest paths?Enter y for yes, any other key to exit \n";
    char ch2;
    cin>>ch2;
    if(ch2=='y')
    continue;
    else
    break;
	}

    cout<<"\n smallest cost is\n"<<floyd[x1][x2];
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
	if(floyd[x1][x2]==inf)
	{
		 	cout<<"\n no route exists between the two stations";
    cout<<"\n do you want to continue querying for more shortest/cheapest paths?Enter y for yes, any other key to exit \n";
    char ch2;
    cin>>ch2;
    if(ch2=='y')
    continue;
    else
    break;

	}
    cout<<"\n fastest time is\n"<<floyd[x1][x2]/60<<" hours "<<floyd[x1][x2]%60<<" minutes";
    cout<<"\nshortest time path is\n";
    int k=x1;
    cout<<k<<"->";

    do{k=next[k][x2];
    	cout<<k<<"->";
    	
	}while(k!=x2);
	
}

cout<<"\n do you want to continue querying for more shortest/cheapest paths?(press y for yes, any other key to exit)";
cin>>ch3;
;}while(ch3=='y');
        
        
    }
    
    
    
