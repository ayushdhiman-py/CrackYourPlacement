string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>pat(26,0),str(26,0);
        for(auto x:p)
            pat[x-'a']++;
        int j=0,match=0;
        string ans="",temp="";
        for(int i=0;i<s.size();i++)
        {
            str[s[i]-'a']++;
            temp+=s[i];
            if(pat[s[i]-'a']>0&&str[s[i]-'a']<=pat[s[i]-'a'])
                match++;
            while(match==p.size())
            {
                if(ans=="")
                    ans=temp;
                temp.erase(temp.begin());
                str[s[j]-'a']--;
                if(str[s[j]-'a']<pat[s[j]-'a'])
                {
                    match--;
                }
                else
                {
                    if(temp.size()<ans.size())
                        ans=temp;
                }
                
                j++;
            }
        }
        if(ans.size()==0)
            return "-1";
        return ans;
    }