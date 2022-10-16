#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int countSubsets(vector<int>& arr,int sum,int n){

    int t[n+1][sum+1];//DP Matrix

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j] = 0; // when array(i) is empty than there is no meaning of sum of elements so return count of subset as 0;
            }
            if(j==0){
                t[i][j] = 1; // when sum(j) is zero and there is always a chance of empty subset so return count as 1;
            }
        }
    }


    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){ //if number is less than than the required sum.
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j]; //either include it or exclude it and check if sum is possible or not.
                //here we have used + because we are returning the count.
            }else{
                t[i][j] = t[i-1][j]; //if number is greater than the sum required exclude that number.
            }
        }
    }
    return t[n][sum]; //return the last cell which has the answer.
}

int main()
{
    vector<int> arr = {2,3,5,6,8,10};
    int n = arr.size();
    int sum = 10;
    cout<<countSubsets(arr,sum,n)<<endl;
    return 0;
}

/*
Time Complexity: O(sum*n), where the sum is the ‘target sum’ and ‘n’ is the size of the array.
Auxiliary Space: O(sum*n), as the size of the 2-D array, is sum*n. 
*/