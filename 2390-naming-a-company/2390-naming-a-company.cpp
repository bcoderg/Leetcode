class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        map<char , vector<string>>mp;
        for (string &x : ideas)
        {
            char firstLetter = x[0];
            string suffixString = x.substr(1);
            mp[firstLetter].push_back(suffixString);
        }
        long long ans = 0;
        for (char c1 = 'a'; c1 <= 'z'; c1++)
        {
            for (char c2 = 'a'; c2 <= 'z'; c2++)
            {
                if (c1 == c2 || ( mp[c1].empty() && mp[c2].empty() ) )continue;
                //check both c1,c2 chars corresponding is empty in map
                int commonSuffixes = 0;
                unordered_set<string>s2(mp[c2].begin() , mp[c2].end());

                for (string &str : mp[c1]) {
                    //how to find if there are any matching strings in mp[c1] , mp[c2]
                    if (s2.count(str) > 0 ) {
                        commonSuffixes++;
                    }
                }
                int count1 = mp[c1].size() , count2 = mp[c2].size();
                ans += ((count1 - commonSuffixes) * (count2 - commonSuffixes));
            }
        }

        return ans;
    }
};