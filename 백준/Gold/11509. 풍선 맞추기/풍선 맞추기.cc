#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 1'000'001

int N;
int ans;
int cnt[MAX];  // 그 높이에 몇개가 날아가고 있는지

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    int h;
    for(int i=0; i<N; i++) {
        cin >> h;
        if (cnt[h]) {
            cnt[h]--; 
            cnt[h-1]++;
        }
        else {
            cnt[h-1]++;
            ans++;
        }
    }
    cout << ans;

    return 0;
}