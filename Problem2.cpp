#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> takeAverage(vector<int>&arr){
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int sum = 0;
    for(int i = 0;i < arr.size();i++){
        sum = sum + arr[i];
    }
    int avg = sum / 100;
    a1 = avg * 50;
    a2 = avg * 30;
    a3 = avg * 20;
    vector<int> ans;
    ans.push_back(a1);
    ans.push_back(a2);
    ans.push_back(a3);
    return ans;
}

vector<int> minSubArray(int target, vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return {arr[i]};
        }
        int sum = arr[i];
        for (int j = i + 1; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == target) {
                vector<int> result(arr.begin() + i, arr.begin() + j + 1);
                return result;
            }
            if(sum>target){
                break;
            }
        }
    }
    return {};
}

int main(){
    vector<int> arr;
    for(int i = 0;i < 100;i++){
        int input;
        cout<<"Enter apple weight in gram (-1 to stop ) : ";
        cin>>input;
        if(input == -1){
            break;
        }
        else{
        arr.push_back(input);
        }
    }

    vector<int> averages = takeAverage(arr);
    
    int a1 = averages[0];
    vector<int> ans1 = minSubArray(a1,arr);
    
     for (int toDelete : ans1) {
        auto it = find(arr.begin(), arr.end(), toDelete);
        if (it != arr.end()) {
            arr.erase(it);
        }
    }
    
    int a2 = averages[1];
    vector<int> ans2 = minSubArray(a2,arr);
    
     for (int toDelete : ans2) {
        auto it = find(arr.begin(), arr.end(), toDelete);
        if (it != arr.end()) {
            arr.erase(it);
        }
    }
    
    int a3 = averages[2];
    vector<int> ans3 = minSubArray(a3,arr);
    
     for (int toDelete : ans3) {
        auto it = find(arr.begin(), arr.end(), toDelete);
        if (it != arr.end()) {
            arr.erase(it);
        }
    }
    
    cout<<"Ram :";
    for(int i = 0; i < ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    cout<<"Sham :";
    for(int i = 0; i < ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
    cout<<"Rahim :";
    for(int i = 0; i < ans3.size();i++){
        cout<<ans3[i]<<" ";
    }
}

