#include <iostream>
using namespace std;
#define Max 101

int n,c1,c2;//��װ������,������� 
int w[Max]={0};//�������� 
int a[Max];//��������  
int tw=0;//��ǰ������ 
int bestw=0;// ��һ����װ�����ų��� 
int r=0;//�������� 
void Backtrack(int i)
{	//��ֹ���� 
	if(i>=n)
	{	cout<<"�ж�Ҷ��"<<endl; 
		if(tw>bestw)
		{
			cout<<"�ж����ţ�"<<bestw<<"<"<<tw<<"?"<<endl; 
			bestw=tw;
		}
		return;
	}

	cout<<"����"<<w[i]<<"���֧"<<endl;
	if(tw+w[i]<=c1) 
	{
		a[i]=1;
		tw+=w[i];
		Backtrack(i+1);
		tw-=w[i];
	}
	
	cout<<"����"<<w[i]<<"�ҷ�֧" <<endl;

	if(tw+(c1-tw)>=bestw)
	{
		a[i]=0;
		Backtrack(i+1);		
	}
	cout<<"����"<<w[i]<<endl; 
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
	cout<<"C1��:"<<bestw<<" C2��:"<<r-bestw<<endl; 

	return 0;
}
