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
	--n;//从n-1开始
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
		--n;//减小 
	}
	*/
	int i,j;
	int temp=0;
	int carry=0,q=1;//q为当前数的位数 
	a[1] = 1;//初始化为a[1]=1 
	for(i=2;i<=n;i++)
    {
        for(j=1,carry=0;j<=q;j++)
    	{
    		//temp存储当前一位乘以各位数后的中间结果
			//carry为进位数 
        	temp=a[j]*i+carry;
        	a[j]=temp%10;//每一位必须为0-9的数
        	carry=temp/10;//进位
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
//做乘法，判断是否为0，是否为1 
void chengF(int a[],int &len,int x){
	if(x==1||x==0) return ;
	else{
		//对每个数做乘法 
		for(int i=len-1;i>=0;i--){
			a[i]*=x;
		}
		//做进位操作 
		int i=0,j=0;
		int tmp = 0;
		for( i=0;i<len;i++){
			j=1;
			//判断是否需要进位 
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
		//更新位长 
		while(a[i]!=0)i++;
		len = i;
		
	}
	
}

