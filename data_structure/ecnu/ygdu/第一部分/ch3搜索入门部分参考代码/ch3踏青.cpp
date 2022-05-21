#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int room[105][105];
int mark[105][105];
int ans=0;
int chgx[5]={0,1,-1,0,0};
int chgy[5]={0,0,0,1,-1};
void dfs(int x,int y){
    mark[x][y]=1;
    for(int i=1;i<=4;i++){
        int xx=x+chgx[i];
        int yy=y+chgy[i];
        if(room[xx][yy]==1&&mark[xx][yy]==0)dfs(xx,yy);
    }
    return;
}
int main(){
    int n,m;cin>>n>>m;
    char ip1;int op2;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++){
         cin>>ip1;
         if(ip1=='.')op2=0;
         else op2=1;
         room[i][j]=op2;
     }
     for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++){
        if(room[i][j]==1&&mark[i][j]==0){
            dfs(i,j);
            ans++;
           }
       }
     cout<<ans<<endl;
    return 0;
}
