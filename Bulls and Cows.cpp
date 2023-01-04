class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0,y = 0;
        map<char,int>m;
        set<char> s;

        for (int i = 0; i < secret.size(); i++) {
            s.insert(secret[i]);
            m[secret[i]]++;
        }

        for (int i = 0; i < secret.size();i++) {
            if (secret[i] == guess[i]) x++,m[secret[i]]--;
        }

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i] && s.find(guess[i]) != s.end()) {
                if (m[guess[i]] > 0) {
                    y++;
                    m[guess[i]]--;
                }
            }
        }

        string ans;
        vector<char> x1;
        if (x==0)ans.push_back('0');
        while(x != 0) {
            int tmp = x % 10;
            x/=10;
            x1.push_back(tmp+'0');
        }
        reverse(x1.begin(),x1.end());
        
        for(int i =0;i < x1.size();i++) {
            ans.push_back(x1[i]);
        }
        ans.push_back('A');
        if (y==0)ans.push_back('0');
        vector<char> y1;
        while(y != 0) {
            int tmp = y % 10;
            y/=10;
            y1.push_back(tmp+'0');
        }
        reverse(y1.begin(),y1.end());
        
        for(int i =0;i < y1.size();i++) {
            ans.push_back(y1[i]);
        }
        ans.push_back('B');

        return ans;
    }
};
