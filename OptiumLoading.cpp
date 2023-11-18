#include <iostream>
using namespace std;
#define Max 101

int n,c1,c2;//集装箱数量,最大重量 
int w[Max]={0};//重量数组 
int a[Max];//方向数组  
int tw=0;//当前重量和 
int bestw=0;// 第一个集装箱最优承重 
int r=0;//货物总重 
void Backtrack(int i)
{	//终止条件 
	if(i>=n)
	{	cout<<"判断叶子"<<endl; 
		if(tw>bestw)
		{
			cout<<"判断最优："<<bestw<<"<"<<tw<<"?"<<endl; 
			bestw=tw;
		}
		return;
	}

	cout<<"进入"<<w[i]<<"左分支"<<endl;
	if(tw+w[i]<=c1) 
	{
		a[i]=1;
		tw+=w[i];
		Backtrack(i+1);
		tw-=w[i];
	}
	
	cout<<"进入"<<w[i]<<"右分支" <<endl;

	if(tw+(c1-tw)>=bestw)
	{
		a[i]=0;
		Backtrack(i+1);		
	}
	cout<<"结束"<<w[i]<<endl; 
}


int main()
{	cin>>n>>c1>>c2;
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
		r+=w[i]; 
	}
	Backtrack(0);
	cout<<bestw<<endl; 
	cout<<"C1船:"<<bestw<<" C2船:"<<r-bestw<<endl; 

	return 0;
}
