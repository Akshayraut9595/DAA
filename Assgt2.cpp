#include <bits/stdc++.h>
using namespace std;

void Zero_One_knapsack(int profit[], int weight[], int w, int n){
    int dp[n+1][w+1];
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }

    for(int i=0;i<w+1;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int v = profit[i-1];
            int wt = weight[i-1];

            int incProf = v + dp[i-1][j-wt];
            int excProf = dp[i-1][j];
            if(wt <= j){
                dp[i][j] = max(incProf,excProf);
            }
            else{
                dp[i][j] = excProf;
            }
        }
    }

    cout<<"\n==================== DP Matrix =============================="<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n"<<endl;
    }

    cout<<"\nTotoal Profit is "<<dp[n][w]<<endl;
    cout<<"\n\nItems selected "<<endl;
    int k = w;
    int i = n;

    cout<<"Profit"<<"\t\t"<<"Weight"<<endl;
    while(k>0 && i>=0){
        if(dp[i][k] != dp[i-1][k]){
            cout<<profit[i-1]<<"\t\t"<<weight[i-1]<<endl;
            k -= weight[i-1];
        }
        i--;
    }
}


int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;

    int profit[n];
    int weight[n];

    for(int i=0;i<n;i++){
        cout<<"\nEnter the profit of "<<i<<" item: ";
        cin>>profit[i];
        cout<<"Enter the weight of "<<i<<" item: ";
        cin>>weight[i];
    }

    int w;
    cout<<"\nEnter the capacity of bag: ";
    cin>>w;

    Zero_One_knapsack(profit,weight,w,n);
}