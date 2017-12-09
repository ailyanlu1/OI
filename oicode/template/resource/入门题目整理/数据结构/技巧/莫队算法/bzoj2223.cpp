#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 300005
#define LIM 10005
using namespace std;
/*
���ⲻ�ʺ�Ī��������ѯ����һ���������O(1)ά��
�������԰��ճ��ִ�������ð�ݵ�����
so���Ҳ�����д�ˣ���ЦЦ��ȥ�� 
*/
struct interval{
    int fr,to;
}a[LIM];
int ans[LIM],sor[LIM];
int half;//����һ��
int p[N];
int sequence[LIM];
int n,m,lim;
bool cmpfr(const int &a1,const int &b1){
    return a[a1].fr<a[b1].fr;
}
bool cmpen(const int &a1,const int &b1){
    return a[a1].to<a[b1].to;
}
int fr1,to1,fr2,to2;
void trans(){//ת��
    int ele=(to2-fr2+1)>>1;
    if(fr1<fr2){
        for(int i=fr1;i<fr2;i++){
            sequence[p[i]]--;
        }
    }else{
        for(int i=fr2;i<fr1;i++){
            sequence[p[i]]++;
            if(sequence[p[i]]>ele) half=p[i];
        }
    }
    if(to1<to2){
        for(int i=to1+1;i<=to2;i++){
            sequence[p[i]]++;
            if(sequence[p[i]]>ele) half=p[i];
        }
    }else{
        for(int i=to2+1;i<=to1;i++){
            sequence[p[i]]--;
        }
    }
}
int work(){
    if(sequence[half]>((to2-fr2+1)>>1)) return half;
    return 0;
}
int main(){
    scanf("%d%d",&n,&lim);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a[i].fr,&a[i].to);sor[i]=i;
    }
    sort(sor+1,sor+m+1,cmpfr);
    int k=sqrt(m);
    for(int i=1;i<m;i+=k){
        int end=min(i+k+1,m+1);
        sort(sor+i,sor+end,cmpen);
    }
    fr1=to1=0;
    for(int i=1;i<=m;i++){
        fr2=a[sor[i]].fr;to2=a[sor[i]].to;
        trans();
        ans[sor[i]]=work();
        fr1=fr2;to1=to2;
    }
    for(int i=1;i<=m;i++){
        if(ans[i]==0) printf("no\n");
        else printf("yes %d\n",ans[i]);
    }
    return 0;
}
