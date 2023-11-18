#include <iostream>
#include <algorithm>
using namespace std;
 
struct T
{
    double weight;
    double value;
    double devide;
};

int n;
double c; //n件物品和背包容量c
double sum = 0, sumval = 0, bestval = 0; //sum:当前重量 sumval:当前价值 bestval:最大价值
T* t; 
 
void swap(T *i,T *j){
	T temp=*i;
	*i=*j;
	*j=temp;
}
void sort(T *t)
{
 int i;
 for (i = 0; i < n-1; i++) //
    {
        for (int j = 0; j < n-i-1; j++) //从0开始一直到len-i-1的是这次需要确认最大值数量
            if (t[j].value < t[j+1].value)
            {
				swap(t[j],t[j+1]);
            }
	}	
}

int Bound(int y) //约束函数
{
    int i = y;
    double leftv = 0; 
    double leftw = c - sum;
    while (i < n && t[i].weight <= leftw) 
    {
        leftw -= t[i].weight;
        leftv += t[i].value;
        i++;
    }
    if (i < n) //背包装满 
    {
        leftv += t[i].devide*leftw;
    }
    return leftv;
}
 
void Backtrack(int i)
{	cout<<"当前结点"<<t[i].weight<<"\n";
    if (i >= n) //递归终止条件
    {	cout<<"判断叶子"<<endl; 
        if (sumval > bestval)
        {	cout<<"判断最优"<<endl; 
            bestval = sumval;
        }
        return;
    }
   
    cout<<"进入"<<t[i].weight<<"左分支"<<endl; 
    if (sum + t[i].weight <= c)
    {
        sum += t[i].weight;
        sumval += t[i].value;
        Backtrack(i + 1);
        
        sumval -= t[i].value; 
        sum -= t[i].weight;
    }
    cout<<"进入"<<t[i].weight<<"右分支"<<endl; 
	//通过边界，剪枝 
	double bound=Bound(i+1);
	
//	cout<<"bound="<<sumval+bound<<"  bestval="<<bestval<<"\n"; 
    if (sumval + bound > bestval)
    {	
        Backtrack(i + 1);
    }
    cout<<"结束"<<t[i].weight<<endl;
}
 
int main()
{	
    cin >> n >> c;
    t = new T[n+1];
    for (int i = 0; i <n; i++)
    {
        cin >> t[i].weight >> t[i].value;
        t[i].devide = t[i].value / t[i].weight;
    }
   
    sort(t); //剪枝优化，采取价值高的优先 
     cout<<"排序后："; 
    for(int i=0;i<n;i++)
	{
		cout<<t[i].weight<<" "<<t[i].value<<"\n";
	
	}
    Backtrack(0);
    cout << bestval;
    return 0;
}
