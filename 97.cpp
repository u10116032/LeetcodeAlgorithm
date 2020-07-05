/**************** DP ******************/
/*
To implement this method, we'll make use of a 2D boolean array dpdp. In this array dp[i][j]dp[i][j] implies if it is possible to obtain a substring of length (i+j+2)(i+j+2) which is a prefix of s3s3 by some interleaving of prefixes of strings s1s1 and s2s2 having lengths (i+1)(i+1) and (j+1)(j+1) respectively.
*/
class Solution {
public:
    // 2-D
    bool isInterleave(string s1, string s2, string s3)
    {
        /*
            check len(s3)=len(s1)+len(s2)
            3 ptr for s1/s2/s3
            interleave means each char in s3 must belong with s1 or s2.
            while finish iterating s3, our s1/s2 ptr must be in the end too.
            ------------ TLE ------------
            using DP for saving time.
            can we reduce this problem to below?
                return (s3 is subset of s1 && s3-s1 is equal to s2)
        */
        if (s3.length()!=s1.length()+s2.length()) return false;
        vector<vector<bool>> dp(s1.length()+1,vector<bool>(s2.length()+1,false));
        dp[0][0]=true;
        for (int i=1; i<=s1.length(); ++i) dp[i][0]=dp[i-1][0]&&s1[i-1]==s3[i-1];
        for (int i=1; i<=s2.length(); ++i) dp[0][i]=dp[0][i-1]&&s2[i-1]==s3[i-1];
        for (int i=1; i<=s1.length(); ++i) {
            for (int j=1; j<=s2.length(); ++j) {
                dp[i][j]=((s1[i-1]==s3[i+j-1])&&dp[i-1][j])||
                             ((s2[j-1]==s3[i+j-1])&&dp[i][j-1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
    // 1-D
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.length()!=s1.length()+s2.length()) return false;
        vector<bool> dp(s2.length()+1,false);
        dp[0]=true;
        for (int i=1; i<=s2.length(); ++i) dp[i]=dp[i-1]&&s2[i-1]==s3[i-1];
        for (int i=1; i<=s1.length(); ++i) {
            dp[0]=dp[0]&&s1[i-1]==s3[i-1];
            for (int j=1; j<=s2.length(); ++j) {
                dp[j]=((s1[i-1]==s3[i+j-1])&&dp[j])||
                      ((s2[j-1]==s3[i+j-1])&&dp[j-1]);
            }
        }
        return dp[s2.length()];
    }
};

/**************** recursive TLE ******************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        /*
            check len(s3)=len(s1)+len(s2)
            3 ptr for s1/s2/s3
            interleave means each char in s3 must belong with s1 or s2.
            while finish iterating s3, our s1/s2 ptr must be in the end too.
        */
        if (s3.length()!=s1.length()+s2.length()) return false;
        else if (s3.length()==0) return true;
        else if (s1.length()==0||s2.length()==0) return (s1==s3)||(s2==s3);
        else return help(s1,s2,s3,0,0,0);
    }

    bool help(string &s1, string &s2, string &s3, int p1, int p2, int p3)
    {
        if (p3==s3.length()) return p1==s1.length()&&p2==s2.length();
        if ((s3[p3]!=s1[p1])&&(s3[p3]!=s2[p2])) return false;
        bool left=false, right=false;
        if (p1<s1.length()&&s3[p3]==s1[p1]) left=help(s1,s2,s3,p1+1,p2,p3+1);
        if (p2<s2.length()&&s3[p3]==s2[p2]) right=help(s1,s2,s3,p1,p2+1,p3+1);
        return left||right;
    }
};

/*************** LCSequence Fail ***************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        /*
            check len(s3)=len(s1)+len(s2)
            3 ptr for s1/s2/s3
            interleave means each char in s3 must belong with s1 or s2.
            while finish iterating s3, our s1/s2 ptr must be in the end too.
            ------------ TLE ------------
            using DP for saving time.
            can we reduce this problem to below?
                return (s3 is subset of s1 && s3-s1 is equal to s2)
        */
        if (s3.length()!=s1.length()+s2.length()) return false;
        vector<int> idx=longestSubseq(s1,s3);

        for (int i=0; i<idx.size(); ++i) {
            cout<<idx[i]<<endl;
            s3.erase(idx[i],1);}
        cout<<s3<<endl;
        return s3==s2;
    }

    vector<int> longestSubseq(string &s1, string &s3)
    {
        int rows=s1.length(); int cols=s3.length();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        dp[0][0]=0;
        for (int row=1; row<=rows; ++row) {
            for (int col=1; col<=cols; ++col) {
                if (s1[row-1]==s3[col-1]) dp[row][col]=dp[row-1][col-1]+1;
                else dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
            }
        }
        vector<int> idx;
        int row=rows; int col=cols;
        if (dp[row][col]!=s1.length()) return idx;
        string tmp="";
        while(dp[row][col]!=0){
            if (s1[row-1]==s3[col-1]) {
                idx.push_back(col-1);
                tmp+=s3[col-1];
                row--; col--;

            }
            else if (dp[row-1][col]>dp[row][col-1]) row--;
            else col--;
        }
        reverse(tmp.begin(),tmp.end());
        cout<<tmp<<endl;
        return idx;
    }
};