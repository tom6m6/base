#include<iostream>
using namespace std;
typedef long long Long;

int n,k;
Long price[35]={0};
bool judge=false;

void dfs(int mon,int pos,int cnt)
/*mon����ǰ��Ǯ����pos����ǰ���ڿ��ǵ��Ǳ��飨ע�⣺�����ڿ��ǣ�
�������Ѿ����˻���û�򣩣�cnt����ǰ�Ѿ���������*/
{
    if(mon==0 && cnt==k)
        judge=true;
    if((mon>0) && (cnt<k)&&(pos<n)){
        dfs(mon-price[pos],pos+1,cnt+1);//ѡ����ǰ���飬Ȼ����һ��
        dfs(mon,pos+1,cnt);//ѡ����ǰ���飬Ȼ����һ��
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
