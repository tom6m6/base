#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10][10], //
     hang[10][10],lie[10][10],room[10][10];  //�С��С�С�Ź������Ƿ���ʹ�
int mx=0; //mx����𰸣���ʼֵΪ0
int goal=0;int kong=0;
struct hnum{
    int h,num; //����ṹ�壬���к�h��0�ĸ���num��Ӧ
    bool operator <(const hnum &A) const{  //���ڰ�0������������
        return num<A.num;
    }
}h0[10]; //��¼ÿ��h0[i].h��0����h0[i].num
int wh_room(int i,int j){//�����������ͱ����������꣨��Ӧ���ӣ������ش�����Ĵ����ĸ�С�Ź���
    if(i<=3){
        if(j<=3)return 1;
        else if(j>3&&j<=6)return 2;
               else return 3;
   }
   else if(i>3&&i<=6){
        if(j<=3)return 4;
        else if(j>3&&j<=6)return 5;
               else return 6;
    }
    else {
        if(j<=3)return 7;
        else if(j>3&&j<=6)return 8;
               else return 9;
    }
}
int value(int i,int j){//�����������ͱ����������꣨��Ӧ���ӣ������ش˸��ӵķ�ֵ
    if(i==1||j==1||i==9||j==9)   return 6;
    if(i==2||j==2||i==8||j==8)   return 7;
    if(i==3||j==3||i==7||j==7)   return 8;
    if(i==4||j==4||i==6||j==6)   return 9;
    return 10;
}
void dfs(int x,int zero,int much,int jj,int k){
    if(much==kong){//�Ϸ����������еĿ���
        if(mx<goal)mx=goal; //����͸���
        return;
    }
    if(zero==0){
        k++;
        x=h0[k].h;zero=h0[k].num;
        jj=0;
    }
    for(int j=jj+1;j<=9;j++){
        if(!a[x][j]){
            for(int i=1;i<=9;i++){
                if(!hang[x][i]&&!lie[j][i]&&!room[wh_room(x,j)][i]){//�жϿ��Խ�i����
                    hang[x][i]=1;lie[j][i]=1;room[wh_room(x,j)][i]=1; //���˺�ͽ�������ֵ���������С��С����ӱ��
                    goal+=i*value(x,j);
                    dfs(x,zero-1,much+1,j,k);
                    goal-=i*value(x,j);  //����
                    hang[x][i]=0;lie[j][i]=0;room[wh_room(x,j)][i]=0;
                }
            }
        return;
        }
    }
}
int main(){
    int ip1;
    for(int i=1;i<=9;i++)
      for(int j=1;j<=9;j++){
         scanf("%d",&ip1);
         if(ip1==0){
            h0[i].h=i; //h0[i].h�����ʼ�кţ������Ͳ��ᶪʧ
            h0[i].num++;
            kong++;
          }
         else {
            a[i][j]=ip1;
            goal+=ip1*value(i,j);
            hang[i][ip1]=1;lie[j][ip1]=1;
            room[wh_room(i,j)][ip1]=1;
          }
     }
     sort(h0+1,h0+10);
     dfs(h0[1].h,h0[1].num,0,0,1);
     printf("%d",mx);
     return 0;
}
