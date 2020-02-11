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
			//可以向前跑,向前 
			r+=vr;
			if(r-w>=t)//不管当前这一秒跑没跑，检查兔子当前应该处于什么状态，每秒兔子跑完后就思考 
				sleep=s;	
		}else{
			--sleep;
			if(sleep==0&&r-w>=t)//如果第一个睡觉时间结束，兔子的决定,当兔子在等待的时候不用判断，可能出现当前没有睡觉但是和乌龟之间的距离大于t米 
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
