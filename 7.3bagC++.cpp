#include<iostream>
#include<algorithm>
using namespace std;
# define Max 101
int n,c;
int w[Max];//重量数组 
int v[Max];//价值数组
int x[Max];//路径标记 
int sum=0;//当前重量和
int r;//剩余重量和
int sumval=0;//当前价值和 
int bestval=0;//最优价值解
/*
耗时太长：
1. 剪枝优化
2. 排序，优先选取高价值物品 

*/
void swap(int i,int j){
	int temp=i;
	i=j;
	j=temp;
}
void sort(int W[Max],int V[Max],int n)
{
 int i;
 for (i = 0; i < n-1; i++) //
    {
        for (int j = 0; j < n-i-1; j++) //从0开始一直到len-i-1的是这次需要确认最大值数量
            if (W[j] > W[j + 1])
            {
				swap(W[j], W[j + 1]);
                swap(V[j],V[j+1]);
            }
	}	
}
float bound(int i){
	float rw=r;
	float b=sumval;
	while(i<n&&w[i]<=rw)
	{
		rw-=w[i];
		b+=v[i];
		i++;
	}
	//背包装满
	if(i<n)
		b+= v[i]/w[i]*rw;
	return b;
}
void backtrack(int i){
	//终止：无,到叶子结点则判断该路径的最大价值是否大于最优 
	if(i>=n)
	{
		if(sumval>bestval)
			bestval=sumval;
		return; 
	}

	//不是叶子结点，则对当前扩展结点进行 
	r-=w[i];//剩余和减去扩展结点重量 
	if(sum+w[i]<=c)//当前重量和结点重量和小于承重，则不剪左分支 
	{
	
//	{	cout<<w[i]<<"左分支"<<sum+w[i]<<endl;
		x[i]=1;//左分支可进
		sum+=w[i];//当前重量和更新
		sumval+=v[i];//当前价值和更新
		backtrack(i+1);
		sum-=w[i];
		sumval-=v[i];
	} 
	//右分支不剪 

//	if(sum+r>=c)没考虑到少量物品也能拿到最高价值 
//		cout<<w[i]<<"右分支"<<endl; 
//	if(bound(i)>bestval)//计算上边界 
//	{
	  
		x[i]=0;
		backtrack(i+1);
//	}
	r+=w[i];
	
}
int main()
{	
	cin>>n>>c;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
		r+=w[i];
	}
	sort(w,v,n);
	backtrack(0);
	cout<<bestval<<endl;
	return 0;
}
