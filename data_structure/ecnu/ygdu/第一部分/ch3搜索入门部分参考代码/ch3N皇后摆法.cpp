#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=20;
int n; // ���̴�С
int ans = 0;  // ��ĸ���
bool a[maxn];  // ��ռ����������� i �б�ռ�ã��� a[i] = true������Ϊ false
bool x1[maxn];  // ����-���� �Խ��ߵ�ռ�����
bool y1[maxn];  // ����-���� �Խ��ߵ�ռ�����
void dfs(int deep) {  // deep ��ʾ��ǰ�������ڼ���
  if (deep >= n) {  // ���������һ�У�˵���ҵ���һ��Ϸ���
        ans++;
        return;  // ����
     }
     for (int i = 0; i < n; i++) {  // ö�ٵ�ǰ�еĻʺ���õ��� i ��
         if (x1[i + deep] == false && y1[i - deep + n] == false && a[i] == false) {  // �жϸûʺ��Ƿ����ѷ��õĻʺ�����ͻ
             // ���ûʺ� (deep, i)��һ����Ҫ�޸������������
             x1[deep + i] = true;
             y1[i - deep + n] = true;
             a[i] = true;
             dfs(deep + 1);  // ��ǰ��ö����ϣ�������һ��
             // �ָ����ûʺ� (deep, i) ǰ��״̬
             a[i] = false;
             x1[deep + i]=false;
             y1[i - deep + n] = false;
         }
     }
 }
int main() {
     scanf("%d", &n);
     memset(a, false, sizeof(a));
     memset(x1, false, sizeof(x1));
     memset(y1, false, sizeof(y1));
     dfs(0);
     printf("%d", ans);
     return 0;
}

