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
double c; //n����Ʒ�ͱ�������c
double sum = 0, sumval = 0, bestval = 0; //sum:��ǰ���� sumval:��ǰ��ֵ bestval:����ֵ
T* t; 
 
bool cmp(T t1, T t2)
{
    return t1.devide > t2.devide; 
}
 
int Bound(int y) //Լ������
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
    if (i < n) //����װ�� 
    {
        leftv += t[i].devide*leftw;
    }
    return leftv;
}
 
void Backtrack(int i)
{
    if (i >= n) //�ݹ���ֹ����
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
	//ͨ���߽磬��֦ 
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
    sort(t, t+n, cmp); //��֦�Ż�����ȡ��ֵ�ߵ����� 
    Backtrack(0);
    cout << bestval;
    return 0;
}
