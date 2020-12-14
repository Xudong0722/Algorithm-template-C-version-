/*
 * Author: Moon-light
 * 并查集的启发式合并优化
 * 因为这里使用的是按集合大小合并，所以可以加上路径压缩
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lowbit(x) ((x)&(-x))
#define sz(x) ((int)x.size())
#define fr(x) freopen(x,'r',stdin)
#define fw(x) freopen(x,'w',stdout)
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) begin(a),end(a)
#define bitcnt(x) (__builtin_popcountll(x))
#define rep(i,a,b) for(int i = (a);i<=(b); ++i)
#define per(i,a,b) for(int i = (a);i>=(b); --i)
typedef long long LL;
typedef pair<int,int> PII;  
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VB;
typedef double db;

template <class T> void clear(T& a) { T().swap(a);}
template <class T,class S>
inline bool upmin(T& a,const S&b){ return a>b ? a=b,1:0;}
template <class T,class S>
inline bool upmax(T&a, const S&b){ return a<b? a=b,1:0;}

//fast read(improved by fread)
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int redi() {
    int ret = 0,f = 0;char ch = getc();
    while (!isdigit (ch)) {
        if (ch == '-') f = 1;
        ch = getc();
    }
    while (isdigit (ch)) {
        ret = ret * 10 + ch - 48;
        ch = getc();
    }
    return f?-ret:ret;
}

//global variable
const int N = 2e5+100;
const int mod = 1e9+7;
int n,q;
int p[N];
int a,b,op;
unordered_map<int,int> cs[N];
//functions
LL qmi(LL a,LL k,LL mod){
    LL res = 1;
    while(k){
        if(k&1) res = res*a%mod;
        k >>= 1;
        a = a*a%mod;
    }
    return mod;
}
int gcd(int a,int b) {
    return b==0? a:gcd(b,a%b);
}

int find(int x){
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}

void merge(int x,int y){
    int fa = find(x);
    int fb = find(y);
    if(fa == fb) return ;

    //小集合并到大集合上去
    if(cs[fa].size() > cs[fb].size()){
        swap(fa,fb);
    }
    p[fa] = fb;
    for(auto &x:cs[fa]){
        cs[fb][x.first] += x.second;
    }

}
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n>>q;

    int c;
    rep(i,1,n){
        cin>>c;
        cs[i][c] ++;
        p[i] = i;
    }

    rep(i,1,q){
        cin>>op>>a>>b;
        if(op == 1){
            merge(a,b);
        }else{
            int f = find(a);
            cout<<cs[f][b]<<endl;
        }
    }
    return 0;
}