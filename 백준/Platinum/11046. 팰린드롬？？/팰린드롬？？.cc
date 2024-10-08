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
https://www.acmicpc.net/problem/11046

Manacher's Algorithm
문자열의 부분 문자열이 팰린드롬인지 O(n)에 판단하는 manacher 알고리즘

문자열 S에 대한 배열 A를 구할 수 있다.

A[i] : i번째 문자를 중심으로 하는 가장 긴 회문의 반지름 크기를 의미한다.

ex) bananac에서 A[4]는 b<anana>c 최대 반지름인 2가 된다.

어떤 문자열 S에서 A[i]가 존재한다면, 
i - A[i]에서 i + A[i]까지는 팰린드롬이고, 
i - A[i] - 1에서 i + A[i] + 1까지는 팰린드롬이  아니다.

이 과정을 이용하여 bananac라는 문자열에 대한 배열 A를 알아보자.


*/

#define MAX 1'000'000

int S[2*MAX+2];
int A[2*MAX+2];

void manachers(int N){
    int r = 0, p = 0;
    for (int i = 0; i < N; i++){
        //   i ≤ r이라면, i는 p를 중심으로 한 회문에 속한다. 따라서 그 회문에서 i의 대칭점을 i′라 하자. 즉, i′=2p - i가 된다.
        //  그리고 A[i]의 초기값은 min(r - i, A[i′])이다. (즉, r은 중심점 p를 기준으로 하는 p + A[p]를 의미하게 된다.)
        if (i <= r) A[i] = min(A[2 * p - i], r - i);

        //  i > r이라면, A[i]의 초기값은 0이다.
        else A[i] = 0;

        // S[i - A[i]]와 S[i + A[i]]가 같을 때까지 A[i]를 증가시킨다.
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N){
            if (S[i - A[i] - 1] == S[i + A[i] + 1]) A[i]++;
            else break;
        }

        // 갱신
        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N;

    N = 2*N+1;

    // 사이사이 0 넣어주기
    for (int i=1; i<N; i+=2){
        cin >> S[i];
    }

    // for (int i : S) cout << i << ' ';

    manachers(N);

    cin >> M;
    while(M--){
        int s, e;
        cin >> s >> e;

        // 2~3이라면
        // 중간에 0을 넣었기 때문에 2배하고 1 뺀 값이 idx이므로
        // 실제로는 3~5 임
        // s+e/2 에서의 팰린드롬 최대길이가 e-s 이상이면 그 부분은 팰린드롬임
        if (A[s+e-1] >= e-s) cout << "1\n";
        else cout << "0\n";
    }
    
    return 0;
}