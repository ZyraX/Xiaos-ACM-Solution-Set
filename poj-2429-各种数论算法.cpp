#include <algorithm>
#include <iostream>
using namespace std;

typedef __int64 L;
typedef unsigned __int64 UL;

const int COUNT=6;

L allFactor[65],nFactor;

L fMultiModular(const L & a,L b,const L & n)
{
 L back(0),tmp(a%n);
 while(b>0)
 {
   if(b & 0x1)
   {
    if((back=back+tmp)>n)
     back-=n;
   }
   if((tmp<<=1)>n)
    tmp-=n;
   b>>=1;
 }
 return back;
}

L modular_exp(const L & a,L b,const L & n)
{
 L d(1),tmp(a%n);
 while(b)
 {
   if(b&1)
    d=fMultiModular(d,tmp,n);
   tmp=fMultiModular(tmp,tmp,n);
   b>>=1;
 }
 return d;
}

L GCD(L a,L b)
{
 L c;
 while(b)
 {
   c=b;
   b=a%b;
   a=c;
 }
 return a;
}

L pollard_rho(const L & c,const L & num)
{
 int i(1),k(2);
 L x=rand()%num;
 L y=x,comDiv;
 do
 {
   i++;
   if((x=fMultiModular(x,x,num)-c)<0)
    x+=num;
   if(x==y)
    break;
   comDiv=GCD((y-x+num)%num,num);
   if(comDiv>1 && comDiv<num)
    return comDiv;
   if(i==k)
   {
    y=x;
    k<<=1;
   }
 }
 while(1);
 return num;
}

bool fWitNess(const L & a,const L & n,char t,const L & u)
{
 L x,y;
 x=modular_exp(a,u,n);
 while(t--)
 {
   y=fMultiModular(x,x,n);
   if(y==1 && x!=1 && x!=n-1)
    return true;
   x=y;
 }
 return y!=1;
}

bool miller_rabin(const L & n,int cnt)
{
 if(n==1)
   return false;
 if(n==2)
   return true;
 L a,u;
 char t(0);
 for(u=n-1;! (u & 0x1);u>>=1)
   t++;
 for(int i=1;i<=cnt;i++)
 {
   a=rand()%(n-1)+1;
   if(fWitNess(a,n,t,u))
    return false;
 }
 return true;
}

void fFindFactor(const L & num)
{
 if(miller_rabin(num,COUNT))
 {
   allFactor[++nFactor]=num;
   return ;
 }
 L factor;
 do
 {
   factor=pollard_rho(rand()%(num-1)+1,num);
 }
 while(factor>=num);
 fFindFactor(factor);
 fFindFactor(num/factor);
}

UL NumFactor[650];
int Num[65],Len;

void Factorize(const L & N)
{
 L tmp=N;
 Len=0;
 memset(Num,0,sizeof(Num));
 nFactor=0;
 fFindFactor(tmp);
 sort(allFactor+1,allFactor+nFactor+1);
 NumFactor[0]=allFactor[1];
 Num[0]=1;
 for(int i=2;i<=nFactor;i++)
 {
   if(NumFactor[Len]!=allFactor[i])
    NumFactor[++Len]=allFactor[i];
   Num[Len]++;
 }
}

UL key,a,b,mmin,gcd,lcm,res_a,res_b;
UL num1Factor[650];
int num1[65],len1;

void DFS(int cur,UL value)
{
 UL s=1;
 if(cur==len1+1)
 {
   a=value;
   b=key/value;
   if(GCD(a,b)==1)
   {
    a*=gcd;
    b*=gcd;
    if(a+b<mmin)
    {
     mmin=a+b;
     res_a=a<b ? a : b;
     res_b=a>b ? a : b;
    }
   }
   return ;
 }
 for(int i=0;i<=num1[cur];i++)
 {
   if(value*s>=mmin)
    return ;
   DFS(cur+1,value*s);
   s*=num1Factor[cur];
 }
}

int main()
{
/* while(scanf("%I64u%I64u",&gcd,&lcm)!=EOF)
 {
   if(gcd==lcm)
   {
    printf("%I64u %I64u\n",gcd,lcm);
    continue;
   }
   key=lcm/gcd;
   memset(num1Factor,0,sizeof(num1Factor));
   memset(num1,0,sizeof(num1));
   len1=0;
   Factorize(key);
   memcpy(num1Factor,NumFactor,sizeof(NumFactor));
   memcpy(num1,Num,sizeof(Num));
   len1=Len;
   mmin=-1;
   DFS(0,1);
   printf("%I64u %I64u\n",res_a,res_b);
 }
 return 0;*/
 #ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
 Factorize(19211474955331441LL);
 for(int i=1;i<=nFactor;i++){
        cout<<allFactor[i]<<' ';
    }
}
