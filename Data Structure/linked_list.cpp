struct linked_list
{
    vector <int> val;
    vector <int> nxt;
    vector <int> prv;
    int begin;
 
    linked_list(const string& s)
    {
        int n = sz(s);
        val.resize(n);
        nxt.resize(n);
        prv.resize(n);
        for (int i=0; i<n; i++){
            val[i] = (int)(s[i] - '0');
            if (i < n-1){
                nxt[i] = i+1;
            }
            else{
                nxt[i] = -1;
            }
            if (i == 0){
                prv[i] = -1;
            }
            else{
                prv[i] = i-1;
            }
        }
        begin = 0;
    }
 
    void del(int pos)
    {
        if (pos==begin){
            begin = nxt[pos];
            return;
        }
        if (prv[pos] != -1){
            nxt[prv[pos]] = nxt[pos];
        }
        if (nxt[pos] != -1){
            prv[nxt[pos]] = prv[pos];
        }
        nxt[pos] = prv[pos] = -1;
    }
 
    void show()
    {
        for (int p=begin; p != -1; p = nxt[p]){
            cout << val[p];
        }
        cout <<'\n';
    }
};
