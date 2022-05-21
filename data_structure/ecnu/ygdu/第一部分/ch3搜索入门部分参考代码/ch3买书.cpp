#include<iostream>
using namespace std;
typedef long long Long;

int n,k;
Long price[35]={0};
bool judge=false;

void dfs(int mon,int pos,int cnt)
/*mon代表当前的钱数，pos代表当前正在考虑的那本书（注意：是正在考虑，
而不是已经买了或者没买），cnt代表当前已经买书数量*/
{
    if(mon==0 && cnt==k)
        judge=true;
    if((mon>0) && (cnt<k)&&(pos<n)){
        dfs(mon-price[pos],pos+1,cnt+1);//选择买当前的书，然后下一步
        dfs(mon,pos+1,cnt);//选择不买当前的书，然后下一步
    }
}

int main()
{
    Long m;
    cin>>m>>n>>k;
    judge=false;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    dfs(m,0,0);
    if(judge){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
