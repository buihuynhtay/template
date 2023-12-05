struct Trie{
    struct Node{
        int child[26];
        Node(){
            memset(child, 0, sizeof child);
        }
    };
    const int size_trie = 3e6 + 5;
    Node t[size_trie];
    int cnt = 0;

    void add(string s){
        int u = 0;
        for(int i = 0; i < Size(s); i++){
            int x = s[i] - 'a';
            if(t[u].child[x] == 0)
                t[u].child[x] = ++cnt;
            u = t[u].child[x];
        }
    }
};
