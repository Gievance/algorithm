#include<iostream>
using namespace std;
#define max 1000

int n,c; //Ԫ����,Ŀ���
int csum,r;//��ǰ�ͣ�ʣ���
int x[max]={0};//Ԫ������
int w[max];//s��ֵ����

bool backtrack(int i)
{
	//��ֹ����Ҷ�ڵ�
	if(i>=n)
	{
		if(csum==c) return true;
		else return false;
	}	
	r-=w[i];//��ȥi���ʣ���
	//Լ�����֧����ǰ�ʹ���Ŀ��ͣ����֧�ɼ� 
	if(csum+w[i]<=c)
	{
		x[i]=1;
		csum+=w[i];
		//�ж����֧�Ƿ��н� 
		if(backtrack(i+1))
			return true;
		csum-=w[i];
	} 
	
	//Լ���ҷ�֧����ǰ�ͼ�ʣ���(������w[i])�Ƿ����Ŀ��ͣ�
	//�ǣ����֧;���ǣ����֦����Ϊû���壩
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
