#include<iostream>
using namespace std;
#define Max 255
int n;//Ԫ�ظ���
int w[Max];
int x[Max];//Ԫ������

int count=0;//�Ӽ�����

void backtrack(int i)
{
    //��ֹ
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
    for(i=0;i<n;i++)//����Ԫ�� 
    {   
		cin>>x[i];
     }
    backtrack(1);//Ϊʲô��1��ʼ������ͼ��֪���� 
    cout<<count<<endl;
    return 0;
}
