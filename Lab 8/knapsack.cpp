#include<iostream>
using namespace std;
int knapsack(int weight[],int profit[],int cap,int i)
{
    int mat[i][cap+1];
    for(int u=i-1;u>=0;u--)
    {
        if(u==i-1)
        {
            for(int v=0;v<=cap;v++)
            {
                if(weight[u]<=v)
                mat[u][v]=profit[u];
                else
                mat[u][v]=0;
            }
        }
        else
        {
            for(int v=0;v<=cap;v++)
            {
                if(weight[u]>v)
                    mat[u][v]=mat[u+1][v];
                else
                    mat[u][v]=max(mat[u+1][v],mat[u+1][v-weight[u]]+profit[u]);
            }
        }
    }
    int k=0,l=cap;
    cout<<endl;
    while(k<i && l>=0)
    {
        if(mat[k][l]!=mat[k+1][l] && l-weight[k]>=0)
        {
            cout<<k<<" selected"<<endl;
            l-=weight[k];
        }
        k++;
    }
    cout<<endl<<"Tablulation: \n";
    for(int u=i-1;u>=0;u--)
    {
        for(int j=0;j<=cap;j++)
        cout<<mat[u][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return mat[0][cap];
}
int main()
{
    int num,cap;
    cout<<"\nEnter the number of items: ";
    cin>>num;
    int weight[num],profit[num];
    cout<<"\nEnter the weight and profit respectively: ";
    for(int i=0;i<num;i++)
        cin>>weight[i]>>profit[i];
    cout<<"\nEnter the capacity: ";
    cin>>cap;
    cout<<"\nMaximum profit achieveable: "<<knapsack(weight,profit,cap,num);
    return 0;
}