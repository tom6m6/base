#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxl 2010
using namespace std;
int n,m;
int a[maxl][maxl],vist[maxl][maxl][2];
int cg[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct point{
    int x;int y;int foot;int flag;
    point(int xx,int yy,int fot,int f){
        x=xx;y=yy;foot=fot;flag=f;
    }
};
int bfs(int x,int y){
    queue<point>q;
    q.push(point(x,y,0,0));
    vist[x][y][0]=1;
    while(!q.empty()){
        point po=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=po.x+cg[i][0];
            int ty=po.y+cg[i][1];
            if(a[tx][ty]!='#'&&!vist[tx][ty][po.flag]&&tx>0&&tx<=n&&ty>0&&ty<=m){
                vist[tx][ty][po.flag]=1;
                if(a[tx][ty]=='P'){
                    q.push(point(tx,ty,po.foot+1,1));
                }
                else if(a[tx][ty]=='T'&&po.flag){
                    return po.foot+1;
                }

                else q.push(point(tx,ty,po.foot+1,po.flag));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(vist,0,sizeof(vist));
    int bx,by;
    for(int i=1;i<=n;i++){
         getchar();
         for(int j=1;j<=m;j++){
              scanf("%c",&a[i][j]);
              if(a[i][j]=='S'){
                bx=i;by=j;
              }
         }
    }
    printf("%d\n",bfs(bx,by));
    return 0;
}
