#include<iostream>
#include<vector>

using namespace std;
class Solution{
    public:
    vector<int>tmp;
    void sol(int target, vector<int>&candidate, vector<vector<int>>&r, int idx){
        if(target==0){
            r.push_back(tmp);
            return;
        }
        for(int i=idx;i<candidate.size();i++){
            tmp.push_back(candidate[i]);
            if(target-candidate[i]>=0){
                sol(target-candidate[i],candidate,r,i);
            }
            tmp.pop_back();
        }
    }
    vector<vector<int>>combinationSum(vector<int>&candidates, int target){
        vector<vector<int>>res;
        sol(target,candidates,res,0);
        return res;
    }
};
int main(){
    int target,n;
    cin>>target>>n;
    vector<int>candidates(n);
    for(int i=0;i<n;i++){
        cin>>candidates[i];
    }
    vector<vector<int>>a=combinationSum(candidates,target);
    for(auto it: a){
        cout<<a<<" ";
    }
    return 0;
}