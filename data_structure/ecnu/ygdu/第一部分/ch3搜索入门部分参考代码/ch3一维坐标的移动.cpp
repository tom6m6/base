#include <iostream>
#include <queue>
using namespace std;
long vis[5001]={0};
long tx,ty;
long MIN=0;
long long n,a,b;
struct point {
    int x;//坐标
    int s;//步数
    point(int xx,int ss){
        x=xx;
        s=ss;
    }
};
int bfs(int start,int end){
    queue<point> q;
    //int ss=0;
    q.push(point(start,0));
    int next[2]={1,-1};
    while (!q.empty()) {
        point p=q.front();
        q.pop();
        for (int i=0;i<3;i++) {//枚举3种移动规则
            if (i==2){
                tx=p.x*2;
            }else{
               tx=p.x+next[i];
            }
            if (tx<0 ||tx>n)continue;
            if (p.x==end) {
                    MIN=p.s;
                    return 1;
            }
            if (vis[tx]==0) {
                vis[tx]=1;
                q.push(point(tx,p.s+1));
            }
        }
    }
    return -1;
}
int main() {
    scanf("%lld%lld%lld",&n,&a,&b);
    if (bfs(a,b)>0){
        printf("%ld",MIN);
    }
}
