class Solution {
public:
    int  mapit(unordered_map<char,int> &mp,string str,vector<int>&score){
        int count = 0;
        for(int i = 0;i < str.size();++i){
            count+=score[str[i]-'a'];
            mp[str[i]]++;
        }
        return count;
    }
    int fun(vector<string>&words,int i,unordered_map<char,int>&mp,vector<int>&score){
        if(i==words.size())return 0;
        bool flag = true;
        unordered_map<char,int>temp;
        int count = mapit(temp,words[i],score);
        for(auto &t : temp){
            if(!(mp.count(t.first) && t.second <= mp[t.first])){
                flag =false;break;
            }
        }
        int ans = 0;
        if(flag){
            
            for(auto &t : temp){
                mp[t.first]-=t.second;
            }
            ans+= fun(words,i+1,mp,score)+count;
            for(auto &t : temp){
                mp[t.first]+=t.second;
            }
        }

        ans = max(ans, fun(words,i+1,mp,score));

        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
      unordered_map<char,int> mp;
      for(int i = 0;i < letters.size();++i) mp[letters[i]]++;
      return fun(words,0,mp,score);  
    }
};
