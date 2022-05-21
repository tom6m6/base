#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=20;
int n; // 棋盘大小
int ans = 0;  // 解的个数
bool a[maxn];  // 列占用情况，若第 i 列被占用，则 a[i] = true，否则为 false
bool x1[maxn];  // 左下-右上 对角线的占用情况
bool y1[maxn];  // 左上-右下 对角线的占用情况
void dfs(int deep) {  // deep 表示当前搜索到第几行
  if (deep >= n) {  // 搜索完最后一行，说明找到了一组合法解
        ans++;
        return;  // 回溯
     }
     for (int i = 0; i < n; i++) {  // 枚举当前行的皇后放置到第 i 列
         if (x1[i + deep] == false && y1[i - deep + n] == false && a[i] == false) {  // 判断该皇后是否与已放置的皇后发生冲突
             // 放置皇后 (deep, i)，一共需要修改三个标记数组
             x1[deep + i] = true;
             y1[i - deep + n] = true;
             a[i] = true;
             dfs(deep + 1);  // 当前行枚举完毕，搜索下一行
             // 恢复放置皇后 (deep, i) 前的状态
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

