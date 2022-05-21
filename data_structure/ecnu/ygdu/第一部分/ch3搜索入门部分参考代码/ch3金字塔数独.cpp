#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10][10], //
     hang[10][10],lie[10][10],room[10][10];  //行、列、小九宫格标记是否访问过
int mx=0; //mx保存答案，初始值为0
int goal=0;int kong=0;
struct hnum{
    int h,num; //定义结构体，将行号h与0的个数num对应
    bool operator <(const hnum &A) const{  //用于按0个数升序排序
        return num<A.num;
    }
}h0[10]; //记录每行h0[i].h的0个数h0[i].num
int wh_room(int i,int j){//给出两个整型变量代表坐标（对应格子），返回此坐标的处于哪个小九宫格
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
int value(int i,int j){//给出两个整型变量代表坐标（对应格子），返回此格子的分值
    if(i==1||j==1||i==9||j==9)   return 6;
    if(i==2||j==2||i==8||j==8)   return 7;
    if(i==3||j==3||i==7||j==7)   return 8;
    if(i==4||j==4||i==6||j==6)   return 9;
    return 10;
}
void dfs(int x,int zero,int much,int jj,int k){
    if(much==kong){//合法填完了所有的空数
        if(mx<goal)mx=goal; //更大就更新
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
                if(!hang[x][i]&&!lie[j][i]&&!room[wh_room(x,j)][i]){//判断可以将i填入
                    hang[x][i]=1;lie[j][i]=1;room[wh_room(x,j)][i]=1; //填了后就将这个点的值在其所在行、列、格子标记
                    goal+=i*value(x,j);
                    dfs(x,zero-1,much+1,j,k);
                    goal-=i*value(x,j);  //回溯
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
            h0[i].h=i; //h0[i].h存其初始行号，排序后就不会丢失
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
