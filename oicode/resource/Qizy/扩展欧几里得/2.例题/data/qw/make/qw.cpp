#include<iostream> 
#include<cstdio>
#include<cmath>
using namespace std;

long long gcd(long long a,long long b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}

void exgcd(long long a,long long b,long long &m,long long &n)
{
   if(b==0)
   {
      m=1;
      n=0;
      return ;
   }
   exgcd(b,a%b,m,n);
   long long t;
   t=m;
   m=n;
   n=t-a/b*n;
}

int main()
{
   freopen("qw.in","r",stdin);
   freopen("qw.out","w",stdout);
   long long x,y,m,n,l,a,b,c,k1,k2,r,t;
   while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
   {
      a=n-m;
      b=l;
      c=x-y;
      r=gcd(a,b);
      if(c%r)
      {
         printf("Impossible\n");
         continue;
      }
      a/=r;
      b/=r;
      c/=r;
      exgcd(a,b,k1,k2);
      t=c*k1/b;            //ע
      k1=c*k1-t*b;
      if(k1<0)
        if (b>0) k1+=b;
      printf("%I64d\n",k1);
   }
   return 0;
}

/*
ע��
��ʱ���̵����н�Ϊ��x=c*k1-b*t,x����С�Ŀ���ֵ��0��
��x=0�������x��Сʱ��t��ȡֵ��������x=0�ǿ��ܵ���Сȡֵ��
ʵ���Ͽ���x����ȡ����0����ô�ɼ������ȡ��������֪��
�� t=c*k1/b�����t������x=c*k1-b*t�У������x���ܻ�С��0��
��ʱ��t=t+1�������x�ش���0��������غ�x���Ǵ��ڵ���0�ģ�
��ô����Ҫ����������
*/ 
