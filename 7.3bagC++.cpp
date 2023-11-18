#include<iostream>
#include<algorithm>
using namespace std;
# define Max 101
int n,c;
int w[Max];//�������� 
int v[Max];//��ֵ����
int x[Max];//·����� 
int sum=0;//��ǰ������
int r;//ʣ��������
int sumval=0;//��ǰ��ֵ�� 
int bestval=0;//���ż�ֵ��
/*
��ʱ̫����
1. ��֦�Ż�
2. ��������ѡȡ�߼�ֵ��Ʒ 

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
        for (int j = 0; j < n-i-1; j++) //��0��ʼһֱ��len-i-1���������Ҫȷ�����ֵ����
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
	//����װ��
	if(i<n)
		b+= v[i]/w[i]*rw;
	return b;
}
void backtrack(int i){
	//��ֹ����,��Ҷ�ӽ�����жϸ�·��������ֵ�Ƿ�������� 
	if(i>=n)
	{
		if(sumval>bestval)
			bestval=sumval;
		return; 
	}

	//����Ҷ�ӽ�㣬��Ե�ǰ��չ������ 
	r-=w[i];//ʣ��ͼ�ȥ��չ������� 
	if(sum+w[i]<=c)//��ǰ�����ͽ��������С�ڳ��أ��򲻼����֧ 
	{
	
//	{	cout<<w[i]<<"���֧"<<sum+w[i]<<endl;
		x[i]=1;//���֧�ɽ�
		sum+=w[i];//��ǰ�����͸���
		sumval+=v[i];//��ǰ��ֵ�͸���
		backtrack(i+1);
		sum-=w[i];
		sumval-=v[i];
	} 
	//�ҷ�֧���� 

//	if(sum+r>=c)û���ǵ�������ƷҲ���õ���߼�ֵ 
//		cout<<w[i]<<"�ҷ�֧"<<endl; 
//	if(bound(i)>bestval)//�����ϱ߽� 
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
