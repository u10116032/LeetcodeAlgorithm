/***** Seventh Visit *****/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1,0);
        dp[0]=1;
        for (int i=1; i<=n; ++i) {
            for (string &word:wordDict) {
                if (i<word.length()) continue;
                string substr=s.substr(i-word.length(),word.length());
                if (substr==word) dp[i]=dp[i]|dp[i-word.length()];
            }
        }
        return dp[n];
    }
};

/***** Sixth Visit *****/
/*
    dp[i] denotes if s[0-i] canbe segmented into word break
    T:O(nkm)/S:O(km)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n=s.length();
        vector<bool> dp(n+1,0); dp[0]=1;
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        for (int i=1; i<=n; ++i) {
            for (auto word:words) {
                int k=word.size();
                if (i-k<0) continue;
                string t=s.substr(i-k,k);
                if (t==word) dp[i]=dp[i]||dp[i-k];
            }
        }
        return dp.back();
    }
};

/***** Fifth Visit *****/
/*
    dp[i] denotes if s[0-i] can be segmented into word break
    Maintain a hashtable with
    key: word length, value: unordered_set<string> words
    dp[i]=dp[i-k]&&s[k~i] is in map[k]
    T:O(n+k)/S:O(k)
*/

/***** Fourth Visit *****/
/*
    dp[k][i] denotes s[0-i] is wordbreak or not with wordDict[0-k]
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> sets(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,0);
        dp[0]=true;
        for (int i=1; i<=n; ++i) {
            for (string word:wordDict) {
                if (i-(int)word.length()<0) continue;
                string sub=s.substr(i-word.length(),word.length());
                dp[i]=(sets.count(sub)!=0)&&dp[i-word.length()];
                if (dp[i]) break;
            }
        }
        return dp[n];
    }
};

// TRIE RECURSIVE, TLE!!!
class Solution {
public:
    struct Node {
        string val="";
        Node *children[26]={0};
        Node(string val="") {}
    };

    bool wordBreak(string s, vector<string>& wordDict)
    {
        Node *root=new Node();
        for (string word:wordDict) {
            Node *cur=root;
            for (char c:word) {
                if (!cur->children[c-'a'])
                    cur->children[c-'a']=new Node();
                cur=cur->children[c-'a'];
            }
            cur->val=word;
        }
        bool ans=false;
        help(root,root,0,s,ans);
        return ans;
    }

    void help(Node *root, Node *cur, int i, string s, bool &ans)
    {
        if (i==s.length()) {ans=cur->val!=""; return;}
        else if (!cur->children[s[i]-'a']) return;
        cur=cur->children[s[i]-'a'];
        if (cur->val!="")
            help(root,root,i+1,s,ans);
        if(!ans) help(root,cur,i+1,s,ans);
    }
};

/***** Third Visit *****/
/*
    1-d dp solution
    T:O(mn)/S:O(m)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set words(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,0);
        dp[0]=1;
        for (int i=1; i<=n; ++i) {
            for (string word:words) {
                if (i-(int)word.length()<0) continue;
                string sub=s.substr(i-word.length(),word.length());
                dp[i]=dp[i-(int)word.length()]&&(words.count(sub)!=0);
                if (dp[i]) break;
            }
        }
        return dp[n];
    }
};

/*
    backtracking on position
    TLE!!
*/
class Solution {
public:
    bool ans=false;
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set words(wordDict.begin(),wordDict.end());
        help(s,0,"",words);
        return ans;
    }

    void help(string s, int i, string subs, unordered_set<string> words)
    {
        if (ans) return;
        else if (i>=s.length()) {
            ans|=(words.count(subs)!=0);
            return;
        }
        if (words.count(subs)!=0)
            help(s,i+1,string(1,s[i]),words);
        help(s,i+1,subs+s[i],words);
    }
};

/***** Second Visit *****/
// T:O(m*n*k)/S:O(nk)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,0);
        dp[0]=1;
        for (int i=1; i<=n; ++i) {
            for(string word:words) {
                if (word.length()<=i) {
                    if (!dp[i-word.length()]) continue;
                    string sub=s.substr(i-word.length(),word.length());
                    if(words.count(sub)!=0) dp[i]=1;
                }
                if (dp[i]) break;
            }
        }
        return dp[n];
    }
};

/*
    string:
    1. KMP
    2. TRIE
    3. treat it as array
    Multiple words -> TRIE.
    T:O(2^m*k)/S:O(nk) ----> TLE
*/
class Solution {

struct TrieNode {
    TrieNode *children[26];
    string word;
    TrieNode()
    {
        for(int i=0; i<26; ++i) children[i]=0;
        word="";
    }
};

public:
    TrieNode *root=0;
    bool wordBreak(string s, vector<string>& wordDict)
    {
        root=new TrieNode();
        for(string word:wordDict){
            TrieNode *cur=root;
            for(int i=0; i<word.length(); ++i){
                if(!cur->children[word[i]-'a'])
                    cur->children[word[i]-'a']=new TrieNode();
                cur=cur->children[word[i]-'a'];
            }
            cur->word=word;
        }
        return help(s,0,root);
    }

    bool help(string s, int idx, TrieNode* node)
    {
        if (idx==s.length()&&node&&node->word!="") return true;
        else if (idx==s.length()||!node) return false;

        node=node->children[s[idx]-'a'];
        bool found = help(s,idx+1,node);
        if(!found&&node&&node->word!="")
            found|=help(s,idx+1,root);
        return found;
    }
};

/***** First Visit *****/
/*************** 1-D DP ***************/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.length()+1,false);
        dp[0]=1;
        for (int i=1; i<=s.length(); ++i) {
            for (auto it=wordSet.begin();it!=wordSet.end();++it){
                if (it->length()<=i) {
                    if (!dp[i-it->length()]) continue;
                    string sub=s.substr(i-it->length(),it->length());
                    if(wordSet.find(sub)!=wordSet.end()) dp[i]=true;
                }
                if(dp[i]) break;
            }
        }
        return dp[s.length()];
    }
};

/*************** Backtracking hashmap TLE ***************/
class Solution {
public:
    // T(n)=T(n-1)+T(n-2)+...+T(1)
    // T(n)=O(2^n)
    unordered_set<string> worddict;
    bool wordBreak(string s, vector<string>& wordDict)
    {
        /*
            use a set to store wordDict
            Backtracking:
                start from index, check wheter index+1...index+length-index is
                found in a set or not.
        */
        worddict = unordered_set<string>(wordDict.begin(),wordDict.end());
        return help(s,0);
    }

    bool help(string &s, int index)
    {
        if (index==s.length()) return true;
        for (int i=index+1; i<=s.length(); ++i) {
            string sub=s.substr(index,i-index);
            if(worddict.find(sub)!=worddict.end()) {
                if(help(s,i)) return true;
            }
        }
        return false;
    }
};

/*************** Backtracking TRIE TLE ***************/
class Solution {
public:
    struct Node {
        Node *children[255];
        string word;
        Node():word(""){
            for (int i=0; i<255; ++i) {
                children[i]=0;
            }
        }
    };

    bool wordBreak(string s, vector<string>& wordDict)
    {
        /*
            use a set to store wordDict
            Backtracking:
                start from index, check wheter index+1...index+length-index is
                found in a set or not.
            ----TLE---
            use a TRIE
        */
        // Build a trie
        Node *root = new Node();
        for(string word:wordDict) {
            Node* cur=root;
            for (int i=0; i<word.length(); ++i) {
                if(!cur->children[word[i]]) {
                    Node *node=new Node();
                    cur->children[word[i]]=node;
                }
                cur=cur->children[word[i]];
            }
            cur->word=word;
        }

        return help(s,root,root,0);
    }

    bool help(string &s, Node *root, Node* cur, int index)
    {
        if (index=s.length()-1) return cur->word!="";
        if (!cur->children[s[index]]) return false;
        cur=cur->children[s[index]];
        bool found=false;
        if (cur->word!="") {
            // cout<<cur->word<<endl;
            found=found||help(s,root,root,index+1);
        }
        found=found||help(s,root,cur,index+1);

        return found;
    }
};
