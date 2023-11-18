#include <bits/stdc++.h>
using namespace std;

int partition(int profit[],int weight[], double ratio[],int s, int e){
    double pivot = ratio[e];
    int i=s-1;

    for(int j=s;j<e;j++){
        if(ratio[j] < pivot){
            i++;
            swap(ratio[j],ratio[i]);
            swap(profit[j], profit[i]);
            swap(weight[j],weight[i]);
        }
    }

    i++;
    swap(ratio[e],ratio[i]);
    swap(profit[e], profit[i]);
    swap(weight[e],weight[i]);
    return i;
}

void quick_sort(int profit[], int weight[], double ratio[], int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(profit,weight,ratio,s,e);
    quick_sort(profit,weight,ratio,s, p-1);
    quick_sort(profit,weight,ratio,p+1,e);
}

void fractional_knapsack(int profit[], int weight[],int w, int n){
    double ratio[n];
    for(int i=0;i<n;i++){
        ratio[i] = (double)profit[i]/weight[i];
    }

    quick_sort(profit, weight, ratio, 0,n-1);

    int cap = w;
    int tot = 0;
    cout<<"\n======================= Item selected ==============================="<<endl;
    cout<<"Profit"<<"\t\t"<<"weight"<<"\t\t"<<"% weight taken"<<"\t\t"<<"Cap remain"<<endl;
    for(int i=n-1;i>=0;i--){
        if(weight[i] <= cap){
            tot += profit[i];
            cap -= weight[i];
            cout<<profit[i]<<"\t\t"<<weight[i]<<"\t\t"<<"100%"<<"\t\t\t"<<cap<<endl;
        }
        else{
            tot += cap*ratio[i];
            cout<<profit[i]<<"\t\t"<<weight[i]<<"\t\t"<<cap*100/weight[i]<<"%"<<"\t\t\t";
            cap = 0;
            cout<<cap<<endl;
            break;
        }
    }

    cout<<"\nTotal profit is "<<tot<<endl;
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

    fractional_knapsack(profit, weight,w, n);
}