#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(vector<int>& arr,int sum,int n){

    bool t[n+1][sum+1]; //DP Matrix

    // here we are setting 1st row and 1st column 
    // i denotes the size of the array 
    // j denotes the target sum (subset sum)
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=false; // when array[i] is empty than there is no meaning of sum of elements so return false.
            }
            else if(j==0){
                t[i][j]=true; // when array[i] is not empty but sum is 0 it is possible that subset can be empty so return true.
            }
        }
    }

    // start from 1 since 1st row and column is already done
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array 
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j]; 
                //here we had taken or(||) because we can not 
                //return maximum of true or false so we used or operator true || false => true. 
            }else{ 
                t[i][j] = t[i-1][j];  // if sum is less than array size just leave and increment 
            }
        }
    }

    return t[n][sum];

}


int main(){

    vector<int> arr = {2,3,7,8,10};
    int sum = 10;
    int n=arr.size();
    cout<<subsetSum(arr,sum,n)<<endl;

}

/*
Complexity Analysis: 
Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
*/