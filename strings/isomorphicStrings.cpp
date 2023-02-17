
  class Solution {
public:
//     bool isIsomorphic(string s, string t) {
//         int m1[256] = {0}, m2[256] = {0}, n = s.size();
//         for (int i = 0; i < n; ++i) {
            
//             if (m1[s[i]] != m2[t[i]]) return false;
//             m1[s[i]] = i + 1;
//             m2[t[i]] = i + 1;
//             cout<<m1[s[i]]<<" "<<m2[t[i]]<<endl;
//         }
//         return true;
//     }
      bool helper(string s,string t){
    map<char,char>mp;//this one is better solution
    for(int i=0;i<s.size();i++){
        if(mp.find(s[i])!=mp.end()){
            if(mp[s[i]]!=t[i]) return false;
        }
        else  mp[s[i]]=t[i];
    }
    return true;
}

bool isIsomorphic(string s, string t) {
    return helper(s,t) && helper(t,s);
}
};
