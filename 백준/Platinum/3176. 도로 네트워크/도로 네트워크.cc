#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 100'001

/*
x의 2^k(2의 k승)번째 조상을 parent[x][k]
최소거리와 최대거리 출력
*/

int N, M;
const int TREE_HIGH = 17;  // 최대는 log2(100000) = 16.xx
int MAXK;  // N에 따른 최대 높이
int parent[TREE_HIGH][MAX];  
int depth[MAX];

// minDist[k][x] : x부터 위로 2^k 만큼 올라갔을때 최소거리
int minDist[TREE_HIGH][MAX];
int maxDist[TREE_HIGH][MAX];
vector<pii> v[MAX];

// 트리를 만들면서 각각의 parent, depth, 자신의 부모와의 거리 구하기
void makeTree(int par, int now, int dep, int cost){

    parent[0][now] = par;   // 부모 노드 기록 [ 2^0 (1)번째 조상 ]
    depth[now] = dep;  // 현재 노드의 깊이 기록
    minDist[0][now] = maxDist[0][now] = cost;  // 부모와의 거리 기록

    for(pii child : v[now]){
        // 부모가 아니라면 자식일 수 밖에 없으므로 재귀
        if(child.first != par) makeTree(now, child.first, dep+1, child.second);
    }
}

// 부모 배열과 거리배열 채워줌
void fillParentDist() {  
    for (int k = 1; k <= MAXK; k++)
        for (int i = 1; i <= N; i++) {
            parent[k][i] = parent[k-1][parent[k-1][i]];
            minDist[k][i] = min(minDist[k-1][i], minDist[k-1][parent[k-1][i]]);
            maxDist[k][i] = max(maxDist[k-1][i], maxDist[k-1][parent[k-1][i]]);
        }
}

// dist 찾기
void getDist(int a, int b) {
    int mini = 1e9;
    int maxi = 0;
    
    if (depth[a] < depth[b]) swap(a, b);
    
    int dif = depth[a] - depth[b];

    // a와 b의 높이차를 없애주기 위해
    // a를 높이차 만큼의 부모로 변경
    for(int i=0; dif>0 ; ++i){
        if(dif%2==1) {
            mini = min(mini, minDist[i][a]);
            maxi = max(maxi, maxDist[i][a]);
            a = parent[i][a];
        }
        dif >>= 1;
    }
 
    if (a == b) {
        cout << mini << ' ' << maxi << '\n';
        return;
    }

    for (int k = MAXK; k >= 0; k--) {
        if (parent[k][a] != parent[k][b]) {
            mini = min({mini, minDist[k][a], minDist[k][b]});
            maxi = max({maxi, maxDist[k][a], maxDist[k][b]});
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    mini = min({mini, minDist[0][a], minDist[0][b]});
    maxi = max({maxi, maxDist[0][a], maxDist[0][b]});
    // 이러면 a와 b의 바로 위의 부모가 같아짐

    cout << mini << ' ' << maxi << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    MAXK = log2(N);

    for (int i=0; i<N-1; i++){
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s].push_back({e,cost});
        v[e].push_back({s,cost});
    }

    // 1을 root로 잡고 트리 생성
    makeTree(1, 1, 0, 0);
    fillParentDist();

    cin >> M;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        getDist(a, b);
    }
    
    return 0;
}