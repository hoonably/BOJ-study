#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
next_permutation 이용
*/

// set<char> s;
// int len;
// int remain[26];

// void backtracking(int depth, string res){
//     if (depth==len){
//         cout << res << '\n';
//     }
//     for (char c : s){
//         if (remain[c-'a']==0) continue;
//         remain[c-'a']--;
//         backtracking(depth+1, res+c);
//         remain[c-'a']++;
//     }
// }

// void init(){
//     memset(remain, 0, sizeof(remain));
//     s.clear();
// }

// void solve(){
//     init();
//     string str;
//     cin >> str;
//     len = str.size();
//     for (char c : str) {
//         s.emplace(c);
//         remain[c-'a']++;
//     }
//     backtracking(0,"");
// }

void solve(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    do {
        cout << s << '\n';
    } while (next_permutation(s.begin(), s.end()));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;
    while(N--){
        solve();
    }
    
    return 0;
}