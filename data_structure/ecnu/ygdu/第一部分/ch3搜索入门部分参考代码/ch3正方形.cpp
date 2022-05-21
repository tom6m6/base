#include<iostream>
#include<cstdlib>
using namespace std;
int v[21];//保存小木棍的数值
int state[21];//保存小木棍是否被取走
int n;
int length;//正方形的边长
//tmp:记录上次所选的木棍下标，sum:当前边的总长度,edge:查询当前的边
void dfs(int tmp,int sum,int edge){
    if(sum>length)   return;//如果当前边大于正方形边长，剪枝
    if(sum==length&&edge<3) dfs(1,0,edge+1);//发现一个可行边，在此基础上找其他边
    if(sum==length&&edge==3){//如果已经找到==length的三个边，第四个边可忽略
        cout<<"Yes";
        exit(0);
    }

    for(int i=tmp;i<=n;++i){//一个优化
        if(state[i]==1)     continue;
        state[i]=1;//将选择的木棍状态置1
        dfs(i+1,sum+v[i],edge);
        state[i]=0;//回溯
    }
}
int main(){
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i){cin>>v[i];sum+=v[i];}

    if(sum%4!=0){cout<<"No";return 0;}
    length=sum/4;
    dfs(1,0,1);
    cout<<"No";
}
