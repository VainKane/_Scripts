#include <bits/stdc++.h>
#define tl 1007
#define nl 100007


using namespace std;


int n , k , a[nl] ;
vector<int> g[nl] ;
void Input() {

    cin >> n >> k ;
    for( int i = 1 ; i <= n ; i ++ ) {

        int p ;
        cin >> p >> a[i] ;
        g[p].push_back(i) ;
    }
}

int dp[nl][tl] , ou[nl] , w[nl] , node = 0 ;
void dfs( int u ) {

    int lc = ++ node ;
    w[lc] = u ;
    for( int v : g[u] ) dfs(v) ;
    ou[lc] = node ;
}


void Solve() {

    // Check

        int leaf = 0 ;
        for( int i = 1 ; i <= n ; i ++ ) leaf += ( ! g[i].size() ) ;
        if( k > leaf ) {

            cout << 0 << '\n' ;
            return ;
        }

    //


    dfs( g[0][0] ) ;

    int ans = 0 , ma ;
    for( int j = 1 ; j <= k ; j ++ ) {

        ma = 0 ;
        for( int i = 1 ; i <= n ; i ++ ) {

            dp[ou[i]][j] = max( dp[ou[i]][j] , a[w[i]] + ma ) ;
            ma = max( ma , dp[i][j-1] ) ;
            ans = max( ans , dp[i][k] ) ;
        }
    }
    cout << ans << '\n' ;

    // Reset

        node = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= k ; j ++ ) dp[i][j] = 0 ;
        for( int i = 0 ; i <= n ; i ++ ) g[i].clear() ;
    //
}


 int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0) ;

    short test ;
    cin >> test ;

    while( test -- ) {

        Input() ;
        Solve() ;
    }
}