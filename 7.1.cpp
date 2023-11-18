#include<iostream>
using namespace std;
#define N 255
//int S[N];//元素数组 
//int X[N];//结果 
//int n,C;//元素个数，目标和 


//测试

int n;
int C;
int w[N];
int count=0;
/*
	i:当前节点
	C：目标和	
*/

bool backtrack(int tw,int rw,int X[N],int i)
{   if(tw==C) return true;
	//遍历到叶节点 
	if(i>n) return false;
	

	if(tw+w[i]<=C)
	{
		X[i]=1;
		if(backtrack(tw+w[i],rw-w[i],X,i+1)) return true;
	}
	if(tw+rw>C)
	{
		X[i]=0;
		if(backtrack(tw,rw-w[i],X,i+1)) return true;
		else return false;
	}
		
	
}




int main()
{	int i;
	int rw=0;
	cin>>n>>C;
	for(i=0;i<n;i++)
		cin>>w[i];
	int X[n];
	
	for(i=1;i<=n;i++)//计算剩余和 
		rw+=w[i];
	if(!backtrack(0,rw,X,0))
		cout<<"No Solution"<<endl;
	else{
		for(i=0;i<n;i++)
			if(X[i]==1) cout<<w[i]<<" "; 
	} 
	return 0;	
 } 
