#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int MaxSize=100;
 
class  MGraph
{
public:
    MGraph(char a[],int n,int e);
    ~MGraph(){}
    friend void Floyd(MGraph G);
private:
    char   vertex[MaxSize];             //节点数组
    int  arc[MaxSize][MaxSize];      //矩阵
    int vertexNum,arcNum;            //节点数与边数
    int visited[MaxSize];            //访问记录
};
 
MGraph::MGraph(char a[],int n,int e)
{
    int i,j,k;
    vertexNum=n;
    arcNum=e;
    for(i=0;i<vertexNum;i++)
    {
        vertex[i]=a[i];
    }
 
    for(i=0;i<vertexNum;i++)
        for(j=0;j<vertexNum;j++)
    {
        arc[i][j]=0;
    }
 
    for(int p=0;p<arcNum;p++)
    {
        std::cout<<"输入第"<<p+1<<"条边及权值："<<std::endl;
        std::cin>>i>>j>>k;
        arc[i][j]=k;
    }
 
}
 
void Floyd(MGraph G)
{
    int i,j,k;
    int dist[MaxSize][MaxSize]={0};
    for(i=0;i<G.vertexNum;i++)                 //初始化最短路径数组，使两点间路径初始为直接权值
        for(j=0;j<G.vertexNum;j++)
    {
        dist[i][j]=G.arc[i][j];
    }
    for(k=0;k<G.vertexNum;k++)
        for(j=0;j<G.vertexNum;j++)
            for(i=0;i<G.vertexNum;i++)
                if((dist[i][k]+dist[k][j]<dist[i][j]&&dist[i][k]!=0&&dist[k][j]!=0&&dist[i][j]!=0)||dist[i][j]==0)
    {
        dist[i][j]=dist[i][k]+dist[k][j];
    }
    for(i=0;i<G.vertexNum;i++)
        for(j=0;j<G.vertexNum;j++)
            if(i!=j)
        {
            std::cout<<G.vertex[i]<<"到"<<G.vertex[j]<<"的最短路径为："<<dist[i][j]<<std::endl;
        }
}
int main()
{
 
    int e,n;
    std::cout<<"点的个数："<<"  ";
    std::cin>>e;
 
    std::cout<<"边的个数："<<"  ";
    std::cin>>n;
 
    char  s[e];
    for(int i=0;i<e;i++)
    {
        std::cout<<"输入第"<<i+1<<"个点：";
        std::cin>>s[i];
    }
    MGraph m(s,e,n);
    Floyd(m);
    return 0;
}
————————————————
版权声明：本文为CSDN博主「六月沨」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/lyf3010572059/article/details/80967579