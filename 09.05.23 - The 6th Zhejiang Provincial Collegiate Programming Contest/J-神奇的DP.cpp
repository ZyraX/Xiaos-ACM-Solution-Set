#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,l,tt,cas,ans;
typedef struct {int a,b;} treetype;
treetype t[300];
int f[300][300];
bool cmp(const treetype a,const treetype b){
    return a.b<b.b;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d%d",&n,&m);
    LOOP(i,1,n){
        scanf("%d",&t[i].a);
        memset(f[i],0,sizeof(f[i]));
    }
    LOOP(i,1,n)
        scanf("%d",&t[i].b);
    sort(t+1,t+1+n,cmp);
    
    LOOP(i,1,n){
        LOOP(j,1,m){
            f[i][j]=MAX(f[i-1][j-1]+t[i].a+t[i].b*(j-1),f[i-1][j]);
        }
    }
    ans=-1;
    LOOP(i,1,n){
        ans=MAX(ans,f[i][m]);
    }
    cout<<ans<<endl;
}
}
