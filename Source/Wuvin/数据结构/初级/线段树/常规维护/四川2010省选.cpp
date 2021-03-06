#include<cstdio>

/*
***四川2010省选  序列操作
0 a b 把[a, b]区间内的所有数全变成0
1 a b 把[a, b]区间内的所有数全变成1
2 a b 把[a,b]区间内的所有数全部取反，也就是说把所有的0变成1，把所有的1变成0
3 a b 询问[a, b]区间内总共有多少个1
4 a b 询问[a, b]区间内最多有多少个连续的1 
*/
using namespace std;
struct node{
	int left,right,mid;//区间 (left,mid)  (mid+1,right) 
	int index;//序号  左儿子index*2 右儿子index*2+1 
	int cz[3];//四种操作 1 2 3   1要操作 最多有一个是1 0-not nessary 
	void addcz(int *t){}//操作叠�
		if(t[0]==1){//归零 
			cz[1]=0;cz[0]=1;cz[2]=0;
		}else if(t[1]==1){//归一 
			cz[0]=0;cz[1]=1;cz[2]=0;
		}else if(t[2]==1){//取反 
			if(cz[0]==1){
				cz[0]=0;cz[1]=1;cz[2]=0;
			}else if(cz[1]==1){
				cz[0]=1;cz[1]=0;cz[2]=0;
			}else if(cz[2]==1){
				cz[0]=0;cz[1]=0;cz[2]=0;
			}else{
				cz[0]=0;cz[1]=0;cz[2]=1;
			} 
		}
		return;
	}
	int yi,ling;//1和0的个数
	int l1,r1,l0,r0;//最左最右连续的0 1
	int long1,long0;//中间最长0 1
	int qing;//清一色 0【=10】 还是 1【=11】  
	void doit(){}//进行操作
		if(cz[0]){
			l0=r0=right-left+1;
			l1=r1=0;
			long1=0;long0=l0;
			yi=0;ling=l0;
		}else if(cz[1]){
			l1=r1=right-left+1;
			l0=r0=0;
			long1=l1;long0=0;
			yi=long1;ling=0;
		}else if(cz[2]){
			swap(l0,l1);swap(r0,r1);swap(long0,long1);swap(yi,ling);
		}
		int len=right-left+1;
		if((l0==len)||(r0==len)){
			qing=10;
		}else if((l1==len)||(r1==len)){
			qing=11;
		}else{
			qing=0;
		}
		return 0;
	}
	void fresh(const node& lson,const node& rson){//根据子节点刷新 
		if(left==right){
			return;
		}
		yi=lson.yi+rson.yi;ling=lson.ling+rson.ling;
		if(lson.qing==11){//左侧全1 
			l1=lson.l1+rson.l1;l0=0;
			if(rson.qing==11){
				r1=l1;r0=0;
				long1=l1;long0=0;qing=11;
			}else{
				r1=rson.r1;r0=rson.r0;
				long1=rson.l1+lson.l1;long0=rson.long0;qing=0;
			}
		}else if(lson.qing==10){//左侧全0 
			l0
		} 
	}
}; 
int main(){
	
	return 0;
}
