#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,s,vr,vw,l;
	cin>>vr>>vw>>t>>s>>l;
	int r=0,w=0;
	int time=0;
	int sleep=0;
	char res;
	while(1){
		++time;
		w+=vw;
		if(sleep<=0){
			//������ǰ��,��ǰ 
			r+=vr;
			if(r-w>=t)//���ܵ�ǰ��һ����û�ܣ�������ӵ�ǰӦ�ô���ʲô״̬��ÿ������������˼�� 
				sleep=s;	
		}else{
			--sleep;
			if(sleep==0&&r-w>=t)//�����һ��˯��ʱ����������ӵľ���,�������ڵȴ���ʱ�����жϣ����ܳ��ֵ�ǰû��˯�����Ǻ��ڹ�֮��ľ������t�� 
				sleep=s;
		}
		
			
		if(r>=l&&w<l){
			res='R';
			break;
		}else if(w>=l&&r<l){
			res='T';
			break;
		}else if(r>=l&&w>=l){
			res='D';
			break;
		}
	}
	cout<<res<<"\n"<<time;
	return 0;
}
