#include <iostream>
#include <cstring> 
#include "stdio.h"
using namespace std;

#define MOD %1000000007
long long map[51][51][15][15];
long long g[51][51];
int m,n,num;
 
long long dfs(long long x, long long y ,long long k, long long v) 
 {
 	long long s = 0,t;
 	if(map[x][y][k][v+1] != -1)
 		return map[x][y][k][v+1];
 	
 	if(x == m && y == n)
 	{
 		if(k == num)
 			return map[x][y][k][v+1] = 1;
 		else if(k == num-1 && g[x][y] > v)
 			return map[m][n][k][v+1] = 1;
 		else
 			return map[x][y][k][v+1] = 0;
 	}
 	else 
 	{
 		if(g[x][y] > v)
 		{
 			t = g[x][y];
 			if(x+1<=m)
 				s=(s+dfs(x+1,y,k+1,t)MOD + dfs(x+1,y,k,v)MOD)MOD;
			if(y+1<=n)
 				s=(s+dfs(x,y+1,k+1,t)MOD + dfs(x,y+1,k,v)MOD)MOD;	 	
 		}
 		else
 		{
 			if(x+1<=m)
 				s=(s+dfs(x+1,y,k,v)MOD)MOD;
 			if(y+1<=n)
 				s=(s+dfs(x,y+1,k,v)MOD)MOD;
 		}
 		return map[x][y][k][v+1] = s MOD;
 	}
 }
 
int main()
{
	memset(map,-1,sizeof(map));
	long long i,j;
   	cin>>m>>n>>num;
   	for(i = 1 ; i <= m ; i++)
   		for(j = 1 ; j <= n ; j++)
   			cin>>g[i][j]; 			
   	dfs(1,1,0,-1);
	cout<<map[1][1][0][0]<<endl;
    return 0;
}
