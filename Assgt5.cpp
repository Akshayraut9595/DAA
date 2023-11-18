#include <bits/stdc++.h>
using namespace std;

bool flag = 0;

void SubsetSum(int i, int n, int set[], int targetSum,vector<int>& subset){
    if (targetSum == 0) {
        flag = 1;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << "]\n";
        return;
    }
 
    if (i == n) {
        return;
    }

    SubsetSum(i + 1, n, set, targetSum, subset);

    if (set[i] <= targetSum) {
        subset.push_back(set[i]);
        SubsetSum(i + 1, n, set, targetSum - set[i],subset);
        subset.pop_back();
    }
}

int main(){
    int set[] = {5, 7, 10, 12, 15, 18, 20};
    int target = 35;
    vector<int>ans;
    SubsetSum(0,7,set,target,ans);
}