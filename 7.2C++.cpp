#include<iostream>
using namespace std;
#define Max 255
int n;//元素个数
int w[Max];
int x[Max];//元素数组

int count=0;//子集个数

void backtrack(int i)
{
    //终止
    if(i>n)
    {
        count++;
    }else{
    	w[i]=1;
    	backtrack(i+1);
    	w[i]=0;
    	backtrack(i+1);
	}
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)//输入元素 
    {   
		cin>>x[i];
     }
    backtrack(1);//为什么从1开始，画个图就知道了 
    cout<<count<<endl;
    return 0;
}
