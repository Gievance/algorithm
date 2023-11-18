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
double c; //n����Ʒ�ͱ�������c
double sum = 0, sumval = 0, bestval = 0; //sum:��ǰ���� sumval:��ǰ��ֵ bestval:����ֵ
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
        for (int j = 0; j < n-i-1; j++) //��0��ʼһֱ��len-i-1���������Ҫȷ�����ֵ����
            if (t[j].value < t[j+1].value)
            {
				swap(t[j],t[j+1]);
            }
	}	
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
{	cout<<"��ǰ���"<<t[i].weight<<"\n";
    if (i >= n) //�ݹ���ֹ����
    {	cout<<"�ж�Ҷ��"<<endl; 
        if (sumval > bestval)
        {	cout<<"�ж�����"<<endl; 
            bestval = sumval;
        }
        return;
    }
   
    cout<<"����"<<t[i].weight<<"���֧"<<endl; 
    if (sum + t[i].weight <= c)
    {
        sum += t[i].weight;
        sumval += t[i].value;
        Backtrack(i + 1);
        
        sumval -= t[i].value; 
        sum -= t[i].weight;
    }
    cout<<"����"<<t[i].weight<<"�ҷ�֧"<<endl; 
	//ͨ���߽磬��֦ 
	double bound=Bound(i+1);
	
//	cout<<"bound="<<sumval+bound<<"  bestval="<<bestval<<"\n"; 
    if (sumval + bound > bestval)
    {	
        Backtrack(i + 1);
    }
    cout<<"����"<<t[i].weight<<endl;
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
   
    sort(t); //��֦�Ż�����ȡ��ֵ�ߵ����� 
     cout<<"�����"; 
    for(int i=0;i<n;i++)
	{
		cout<<t[i].weight<<" "<<t[i].value<<"\n";
	
	}
    Backtrack(0);
    cout << bestval;
    return 0;
}
