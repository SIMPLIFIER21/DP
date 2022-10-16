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

bool targetSum(vector<int>& arr,int n){

    int sum = 0;

    //calculate the sum of the array elements.
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    // if the sum of the array elemenst is the even then the array can be divided in partitions. 
    if(sum%2!=0){
        return false; // return if sum is odd.
    }else{
        return subsetSum(arr,(sum/2),n); // if sum is even find the subset with sum equals to sum/2 with sunsetSum.
    }

    //e.g if sum is 30 we divide in two parts 15 - 15 and if subset of 15 is 
    //present then the another subset also will be 15 as the are forming equal sum

}


int main()
{   
    
    vector<int> arr = {1,5,11,5};
    int n = arr.size();
    cout<<targetSum(arr,n)<<endl;
     
    return 0;
}