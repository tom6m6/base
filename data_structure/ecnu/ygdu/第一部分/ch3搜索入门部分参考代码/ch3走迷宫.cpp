#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int ans=0;
char room[11][11];
int mark[11][11];
int cgx[5]={1,-1,0,0};
int cgy[5]={0,0,-1,1};
void dfs(int x,int y){
    if(room[x][y]==6){
        ans++;
        return;
    }
    mark[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+cgx[i];
        int yy=y+cgy[i];
       if(!mark[xx][yy]&&room[xx][yy]!=0)dfs(xx,yy);
    }
    mark[x][y]=0;
}
int main(){
    int n,m;cin>>n>>m;
    char ip1;int op2;
    int beg,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>ip1;
            if(ip1=='S'){
                beg=i;end=j;
                op2=5;
            }
            if(ip1=='T')op2=6;
            if(ip1=='.')op2=1;
            if(ip1=='#')op2=0;
            room[i][j]=op2;
        }
    }
    dfs(beg,end);
    cout<<ans<<endl;
    return 0;
}
