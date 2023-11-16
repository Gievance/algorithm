#include<iostream>
using namespace std;
#define max 1000

int n,c; //元素数,目标和
int csum,r;//当前和，剩余和
int x[max]={0};//元素数组
int w[max];//s数值数组

bool backtrack(int i)
{
	//终止：到叶节点
	if(i>=n)
	{
		if(csum==c) return true;
		else return false;
	}	
	r-=w[i];//除去i后的剩余和
	//约束左分支：当前和大于目标和，左分支可剪 
	if(csum+w[i]<=c)
	{
		x[i]=1;
		csum+=w[i];
		//判断左分支是否有解 
		if(backtrack(i+1))
			return true;
		csum-=w[i];
	} 
	
	//约束右分支：当前和加剩余和(不包括w[i])是否大于目标和，
	//是，则分支;不是，则剪枝（因为没意义）
	if(csum+r>=c)
	{
		x[i]=0;
		if(backtrack(i+1))
			return true;
	
	} 
	r+=w[i];
	return false; 
} 
 int main(){
 	cin>>n>>c;
 	int i;
 	for(i=0;i<n;i++){
 		cin>>w[i];
 		r+=w[i];
 	}
 	
 	if(backtrack(0))
 	{
 		int j;
 		for(j=0;j<n;j++)
 			if(x[j]==1)
 				cout<<w[j]<<" ";
	 }
	 else
	 	cout<<"No Solution!"<<endl;
	return 0;
 }
