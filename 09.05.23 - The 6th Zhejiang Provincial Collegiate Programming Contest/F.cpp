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
int i,j,k,a,m,n,s,t,l,tt,cas;
map<string,int> keyword;
string tmp;
map<string,int>::iterator iter;
inline void findoradd(string tmp){
    iter=keyword.find(tmp);
    if(iter!=keyword.end())
        return;
    keyword.insert(pair<string,int>(tmp,1));
}

inline bool find(string tmp){
    iter=keyword.find(tmp);
    if(iter!=keyword.end())
        return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
keyword.clear();
scanf("%d",&n);
while(n--){
    cin>>tmp;
    findoradd(tmp);
}
scanf("%d",&m);
while(m--){
    tt=0;
    scanf("%d",&n);
    while(n--){
        cin>>tmp;
        if(find(tmp))
            tt++;
    }
    printf("%d\n",tt);
}
}
