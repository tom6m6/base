#include <bits/stdc++.h>
using namespace std;
int n,m,k,d;
int  mmap[110][110][1010];//mmap数组保存多个状态下的地图状态
bool visit[110][110][1010];//visit数组
int sx,sy,ex,ey;
int dir[5][2]={{1,0},{0,1},{-1,0},{0,-1},{0,0}};
struct point{
    int x;
    int y;
    int step;
};
void bfs(int step)
{
    queue<point>Q;
    point s;s.x=sx,s.y=sy,s.step=0;Q.push(s);
    visit[sx][sy][0]=true;
    while(!Q.empty()){
        point now = Q.front();Q.pop();
        point next;
        for(int i=0;i<5;i++){
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            next.step=now.step+1;

            if(next.x>=0&&next.x<=n&&next.y>=0&&next.y<=m
            &&mmap[next.x][next.y][next.step]!=1&&!visit[next.x][next.y][next.step]){
                if(next.step>d){
                    cout<<"Bad luck!"<<endl;
                    return ;
                }
                if(next.x==ex&&next.y==ey){
                    cout<<next.step<<endl;
                    return ;
                }
                visit[next.x][next.y][next.step]=true;
                Q.push(next);
            }
        }
    }

}

int main()
{
    cin>>n>>m>>k>>d;
    memset(visit,false,sizeof(visit));
    memset(mmap,0,sizeof(mmap));
    sx=0,sy=0,ex=n,ey=m;
    for(int i=0;i<k;i++){
        char f;
        int t,v,x,y;
        cin>>f>>t>>v>>x>>y;
        for(int i=0;i<=d;i++) mmap[x][y][i]=1;
        if(f=='W'){
            int tmp=y;
            while((tmp-=v)>=0){
                mmap[x][tmp][(y-tmp)/v]=1;
                int tt=0;
                while(tt=tt+t){
                    if(tt+(y-tmp)/v>d) break;
                    mmap[x][tmp][(y-tmp)/v+tt]=1;
                }
            }
        }
        if(f=='N'){
            int tmp=x;
            while((tmp-=v)>=0){
                mmap[tmp][y][(x-tmp)/v]=1;
                int tt=0;
                while(tt=tt+t){
                    if(tt+(x-tmp)/v>d) break;
                    mmap[tmp][y][(x-tmp)/v+tt]=1;
                }
            }
        }
        if(f=='E'){
            int tmp=y;
            while(tmp+=v){
                if(tmp>m) break;
                mmap[x][tmp][(y+tmp)/v]=1;
                int tt=0;
                while(tt=tt+t){
                    if(tt+(y+tmp)/v>d) break;
                    mmap[x][tmp][(y+tmp)/v+tt]=1;
                }
            }
        }
        if(f=='S'){
            int tmp=x;
            while(tmp+=v){
                if(tmp>m) break;
                mmap[tmp][y][(x+tmp)/v]=1;
                int tt=0;
                while(tt=tt+t){
                    if(tt+(x+tmp)/v>d) break;
                    mmap[tmp][y][(x+tmp)/v+tt]=1;
                }
            }
        }


    }
    bfs(0);
    return 0;
}
