#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define data dataa
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int N=250010;
const int R=510;
int a[R][R],id[R][R],num[N],nowans,ans,tmpC[N],fa[N],r,c;
bool vis[N],onC[N];
vector<int>g[N],V[N];
void add(int x,int y)
{
    num[x]+=y;
    if(y==1&&num[x]==1)nowans++;
    if(y==-1&&num[x]==0)nowans--;
}
void dfs(int p)
{
    vis[p]=1;
    for(auto x:V[p])add(x,1);
    ans=max(ans,nowans);
    for(auto x:g[p])dfs(x);
    for(auto x:V[p])add(x,-1);
}
void work(int x)
{
    for(;fa[x]&&!vis[x];vis[x]=1,x=fa[x]);
    if(!fa[x]){dfs(x);return;}
    int cnt=0;
    for(;!onC[x];onC[x]=1,tmpC[++cnt]=x,x=fa[x]);
    rep(i,cnt)for(auto x:V[tmpC[i]])add(x,1);
    ans=max(ans,nowans);
    rep(i,cnt)for(auto x:g[tmpC[i]])if(!onC[x])dfs(x);
    rep(i,cnt)for(auto x:V[tmpC[i]])add(x,-1);
}
int main()
{
    scanf("%d%d",&r,&c);
    int tmp=0;
    rep(i,r)rep(j,c)id[i][j]=++tmp;
    rep(i,r)
    {
        char s[510];
        scanf("%s",s+1);
        rep(j,c)
        if(s[j]=='>')a[i][j]=0;
        else if(s[j]=='v')a[i][j]=1;
        else if(s[j]=='<')a[i][j]=2;
        else if(s[j]=='^')a[i][j]=3;
        else if(s[j]=='#')a[i][j]=4;
        else a[i][j]=5;
    }
    rep(i,r)rep(j,c)
    {
        if(a[i][j]>3)continue;
        for(int dir=0;dir<4;dir++)
        {
            int nx=i+dx[dir],ny=j+dy[dir];
            int nid=1<=nx&&nx<=r&&1<=ny&&ny<=c?id[nx][ny]:0;
            if(dir==a[i][j]&&nid)g[nid].pb(id[i][j]),fa[id[i][j]]=nid;
            if(nid&&a[nx][ny]==4)V[id[i][j]].pb(nid);
        }
    }
    rep(i,r)rep(j,c)if(a[i][j]<4&&!vis[id[i][j]])work(id[i][j]);
    printf("%d\n",ans);
    return 0;
}