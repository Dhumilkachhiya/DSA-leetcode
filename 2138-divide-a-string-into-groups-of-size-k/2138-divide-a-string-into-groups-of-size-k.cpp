class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    vector<string>ans;
    int n=s.size();
    for(int i=0;i<s.size();i+=k){
        if(i+k-1<n){
            ans.push_back(s.substr(i,k));
        }
        else{
            ans.push_back(s.substr(i,n-i)+string(k-(n-i),fill));
            
        }
    }
    return ans;
    }
};