#include<bits/stdc++.h>
using namespace std;
void lYi(int a[],int &len,int j);
void chengF(int a[],int &len,int x);
int main(){
	int n;
	cin>>n;
	int a[10000];
	
	for(int i=0;i<10000;i++)
		a[i]=0;
	int tmp = n;
	int len=0;
	/*
	while(tmp!=0){
		a[len++] = tmp%10;
		tmp/=10;
	}
	--n;//��n-1��ʼ
	while(n>0){
		tmp = n;
		int j=0;
		while(tmp!=0){
			int t = tmp%10;
			if(t>=10){
				chengF(a,len,t);
				lYi(a,len,j);	
			}else
				chengF(a,len,t);
			
			j++;
			tmp/=10;
		}
		--n;//��С 
	}
	*/
	int i,j;
	int temp=0;
	int carry=0,q=1;//qΪ��ǰ����λ�� 
	a[1] = 1;//��ʼ��Ϊa[1]=1 
	for(i=2;i<=n;i++)
    {
        for(j=1,carry=0;j<=q;j++)
    	{
    		//temp�洢��ǰһλ���Ը�λ������м���
			//carryΪ��λ�� 
        	temp=a[j]*i+carry;
        	a[j]=temp%10;//ÿһλ����Ϊ0-9����
        	carry=temp/10;//��λ
    	}
    	while(carry)
    	{
        	a[++q]=carry%10;
    	    carry=carry/10;
	    }
   }

	for(i=q;i>0;i--)
		cout<<a[i];
	return 0;
}
void lYi(int a[],int &len,int j){
	for(int t=0;t<j;t++){
		for(int i=len;i>0;i--){
			a[i]=a[i-1];
		}
		a[0]=0;
		++len;	
	}
	
}
//���˷����ж��Ƿ�Ϊ0���Ƿ�Ϊ1 
void chengF(int a[],int &len,int x){
	if(x==1||x==0) return ;
	else{
		//��ÿ�������˷� 
		for(int i=len-1;i>=0;i--){
			a[i]*=x;
		}
		//����λ���� 
		int i=0,j=0;
		int tmp = 0;
		for( i=0;i<len;i++){
			j=1;
			//�ж��Ƿ���Ҫ��λ 
			if(a[i]>=10){
				 
				tmp = a[i];
				a[i] %=10;
				tmp /=10; 
				while(tmp!=0){
					a[i+j]+=tmp%10;
					++j;
					tmp/=10;
				}
			}
			
		}
		//����λ�� 
		while(a[i]!=0)i++;
		len = i;
		
	}
	
}

