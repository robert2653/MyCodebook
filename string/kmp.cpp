#include <bits/stdc++.h>
using namespace std;
struct KMP {
    string s;
    vector<int> failure;
    KMP(string s) {
        this->s = s;
        failure.resize(s.size(), -1);
    }
    void buildFailFunction() {
        for(int i = 1; i < s.size(); i++) {
            int now = failure[i - 1];
            while(now != -1 && s[now + 1] != s[i]) now = failure[now];
            if (s[now + 1] == s[i]) failure[i] = now + 1;
        }
    }
    void KMPmatching(string &sub) {
        for(int i = 0, now = -1; i < s.size(); i++) {
            // now 是 b 現在匹配成功的長度 -1
            while (s[i] != sub[now + 1] && now != -1) now = failure[now];
            // f 儲存了如果匹對失敗，要移去哪裡
            if (s[i] == sub[now + 1]) now++;
            if (now + 1 == sub.size()) {
                cout << "found a match start at position " << i - now << endl;
                now = failure[now];
            }
        }
    }
};
int main(){
    string s = "BABA";
    string sub = "BA";
    KMP kmp(s);
    kmp.buildFailFunction();
    kmp.KMPmatching(sub);
}