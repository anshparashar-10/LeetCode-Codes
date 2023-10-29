class Solution {
public:
    int minChanges(string s) {
        vector<int>ans;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(i>0 && s[i]!=s[i-1])
            {
                ans.push_back(count);
                count=0;
            }
            count++;
        }
        ans.push_back(count);
        
        for(auto i:ans)cout<<i<<" ";
        
    int final=0;
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]%2==0) continue;
            final++;
            if(i<ans.size()-1) ans[i+1]--;
        }
        if(ans[ans.size()-1]==0) return final;
        if(ans[ans.size()-1]%2!=0) final++;
        
        return final;
        
        
        return 0;    
    }
};
