#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int f[N];//fail ����
char s[N], t[N]; //s ƥ�䴮  t ��ƥ�䴮
int ans[N];
int main()
{
	scanf("%s%s", s + 1, t + 1); //�±��1��ʼ����
	int lens = strlen(s + 1), lent = strlen(t + 1);
	f[1] = 0; //��һ������Ȼ�ǿ�

	for(int i = 2; i <= lens; i++) {
		//��ˮָ����fail��������
		//���ҵ����ǰ׺�ĺ�׺�����ԭ����ǰ׺
		int p = f[i - 1]; //����ˮһ�Σ���Ȼ������Լ�

		while(p != 0 && //û��������
		      s[p + 1] != s[i]) //û���ҵ���ȷ����ˮ��Ĵ�
			p = f[p]; //�Ǿͼ�����ˮ

		if(s[p + 1] == s[i]) //ƥ��ɹ�
			f[i] = p + 1; //��ô��ˮ��Ϊԭ�� s[1..p+1]
		else f[i] = 0; //�����ڵ�

	}

	/*����֮��һ������ôд��
	for(int i=2,p;i<=lens;i++){
		for(p=f[i-1];p!=0&&s[p+1]!=s[i];p=f[p]);
		f[i]=s[p+1]==s[i]? p+1:0;
	}
	*/

	puts("f[x]:");

	for(int i = 1; i <= lens; i++) printf("%d ", f[i]);

	puts("");

	//��ô��������ƥ��һ��T��

	for(int i = 1; i <= lent; i++) {
		ans[i] = ans[i - 1]; //�����ϴε�ƥ��

		if(ans[i] == lens) ans[i] = f[ans[i]]; //�ϴ�ƥ��ɹ�������Ȼ��Ҫ��ˮ

		while(ans[i] != 0 && s[ans[i] + 1] != t[i]) //ƥ��û�ɹ� ������ˮ
			ans[i] = f[ans[i]];

		if(s[ans[i] + 1] == t[i]) ans[i] = ans[i] + 1;
		else ans[i] = 0;
	}

	puts("T[x]:");

	for(int i = 1; i <= lent; i++) printf("%d ", ans[i]);

	puts("");

	return 0;
}
