#include <iostream>
#include <algorithm>
#include<iomanip>
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
 
bool cmp(T t1, T t2)
{
    return t1.devide > t2.devide; 
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
{
    if (i >= n) //递归终止条件
    {
        if (sumval > bestval)
        {
            bestval = sumval;
        }
        return;
    }
    if (sum + t[i].weight <= c)
    {
        sum += t[i].weight;
        sumval += t[i].value;
        Backtrack(i + 1);
        
        sumval -= t[i].value; 
        sum -= t[i].weight;
    }
	//通过边界，剪枝 
	double bound=Bound(i+1);
	
    if (sumval + bound > bestval)
    {	
        Backtrack(i + 1);
    }
}
 
int main()
{	
    cin >> n >> c;
    t = new T[n];
    for (int i = 0; i <n; i++)
    {
        cin >> t[i].weight >> t[i].value;
        t[i].devide = t[i].value / t[i].weight;
    }
    sort(t, t+n, cmp); //剪枝优化，采取价值高的优先 
    Backtrack(0);
    cout << bestval;
    return 0;
}
