#include<bits/stdc++.h>
using namespace std;
void quick_sort(int a[],int low,int high);
int partion(int a[],int low,int high); 
int main(){
	//����
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
int partion(int a[],int low,int high){
	int cor = a[low];//���λ�� 
	while(low<high){
		while(low<high&&a[low]<a[high]){
			--high;
		}//high�ϴ����� 
		if(low<high){
			int tmp = a[low];
			a[low] = a[high];
			a[high] = tmp;
		} //��ǰlowλ�õ�ֵΪ���ֵ�������ǰλ�õ�ֵ��Highλ�õ�ֵ��һЩ����/
			//low<high����Խ�����
		while(low<high&&a[high]>a[low]){
			++low;
		}//low ��С������ 
		if(low<high){
			int tmp = a[low];
			a[low]=a[high];
			a[high]=tmp;
		}//��ǰhighλ�õ�ֵΪ���ֵ�������ǰλ�õ�ֵ��lowСһЩ������//
		//low<high������ 
	}
	return low;//���������غϵ�λ�� 
	
}
void quick_sort(int a[],int low,int high){
	if(low<high){
		int cor  = partion(a,low,high);//���һ�λ��� 
		quick_sort(a,low,cor-1);//����벿�ֽ��п��� 
		quick_sort(a,cor+1,high); //���Ұ벿�ֽ��п��� 
	}//�ݹ����� 
			
}
 
