#include<iostream>
#include<cstdlib>
using namespace std;
int v[21];//����Сľ������ֵ
int state[21];//����Сľ���Ƿ�ȡ��
int n;
int length;//�����εı߳�
//tmp:��¼�ϴ���ѡ��ľ���±꣬sum:��ǰ�ߵ��ܳ���,edge:��ѯ��ǰ�ı�
void dfs(int tmp,int sum,int edge){
    if(sum>length)   return;//�����ǰ�ߴ��������α߳�����֦
    if(sum==length&&edge<3) dfs(1,0,edge+1);//����һ�����бߣ��ڴ˻�������������
    if(sum==length&&edge==3){//����Ѿ��ҵ�==length�������ߣ����ĸ��߿ɺ���
        cout<<"Yes";
        exit(0);
    }

    for(int i=tmp;i<=n;++i){//һ���Ż�
        if(state[i]==1)     continue;
        state[i]=1;//��ѡ���ľ��״̬��1
        dfs(i+1,sum+v[i],edge);
        state[i]=0;//����
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
