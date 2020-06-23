#include <bits/stdc++.h> 
using namespace std;
#define ll long long
ll power(ll x, ll y, ll m); 
  
// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
ll ModInverse(ll a, ll mod) 
{ 
        // If a and m are relatively prime, then 
        // modulo inverse is a^(m-2) mode m 
        return power(a, mod - 2, mod); 
} 
  
// To compute x^y under modulo m 
ll power(ll x, ll y,  ll mod) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, mod) % mod; 
    p = (p * p) % mod; 
  
    return (y % 2 == 0) ? p : (x * p) % mod; 
} 
int prec(char c) 
{ 
    if((c=='^')||(c=='&')||(c=='|')) 
    return 1; 
    else 
    return -1;
} 
int main()
{ 
    ll t;
    ll mod=998244353;
    cin>>t;
    while(t--)
    {
        string s,snh;
        ll i;
        ll z,o,a,A,z1,o1,a1,A1;
        ll q=4;
        cin>>s;
        ll n=s.length();
        stack<ll>values;
        stack<char>op;
        for(i=0;i<n;i++)
        {
            if(s[i]=='(')
            continue;
            else if(s[i]=='#')
            {
             values.push(1);
             values.push(1);
             values.push(1);
             values.push(1);
            }
            else if((s[i]=='&')||(s[i]=='|')||(s[i]=='^'))
            {
                op.push(s[i]);
            }
            else if(s[i]==')')
            {
                A=values.top();
                values.pop();
                a=values.top();
                values.pop();
                o=values.top();
                values.pop();
                z=values.top();
                values.pop();
                A1=values.top();
                values.pop();
                a1=values.top();
                values.pop();
                o1=values.top();
                values.pop();
                z1=values.top();
                values.pop();
                char c=op.top();
                op.pop();
                if(c=='&')
                {
                    q=((q%mod)*4)%mod;
                    ll z2=z;
                    ll o2=o;
                    z=((z2%mod)*(z1%mod))%mod;
                    z+=((o%mod)*(z1%mod))%mod;
                    z+=((a%mod)*(z1%mod))%mod;
                    z+=((A%mod)*(z1%mod))%mod;
                    z+=((z2%mod)*(o1%mod))%mod;
                    z+=((z2%mod)*(a1%mod))%mod;
                    z+=((A%mod)*(a1%mod))%mod;
                    z+=((z2%mod)*(A1%mod))%mod;
                    z+=((a%mod)*(A1%mod))%mod;
                    o=(o2%mod*o1%mod)%mod;
                    ll a2=a;
                    a=((a2%mod)*(o1%mod))%mod;
                    a+=((o2%mod)*(a1%mod))%mod;
                    a+=((a2%mod)*(a1%mod))%mod;
                    A=a;
                    values.push(z);
                    values.push(o);
                    values.push(a);
                    values.push(A);
                }
                 else if(c=='|')
                {
                    q=((q%mod)*4)%mod;
                    ll o2=o;
                    ll z2=z;
                    o=((o2%mod)*(z1%mod))%mod;
                    o+=((z%mod)*(o1%mod))%mod;
                    o+=((o2%mod)*(o1%mod))%mod;
                    o+=((a%mod)*(o1%mod))%mod;
                    o+=((A%mod)*(o1%mod))%mod;
                    o+=((o2%mod)*(a1%mod))%mod;
                    o+=((A%mod)*(a1%mod))%mod;
                    o+=((o2%mod)*(A1%mod))%mod;
                    o+=((a%mod)*(A1%mod))%mod;
                    z=(z%mod*z1%mod)%mod;
                    ll a2=a;
                    a=((a2%mod)*(z1%mod))%mod;
                    a+=((a2%mod)*(a1%mod))%mod;
                    a+=((z2%mod)*(a1%mod))%mod;
                    A=a;
                    values.push(z);
                    values.push(o);
                    values.push(a);
                    values.push(A);
                }
                else if(c=='^')
                {
                    q=((q%mod)*4)%mod;
                    ll z2=z;
                    z=((z%mod)*(z1%mod))%mod;
                    z+=((o%mod)*(o1%mod))%mod;
                    z+=((a%mod)*(a1%mod))%mod;
                    z+=((A%mod)*(A1%mod))%mod;
                    ll o2=o;
                    o=((o%mod)*(z1%mod))%mod;
                    o+=((z2%mod)*(o1%mod))%mod;
                    o+=((A%mod)*(a1%mod))%mod;
                    o+=((a%mod)*(A1%mod))%mod;
                    a=((a%mod)*(z1%mod))%mod;
                    a+=((A%mod)*(o1%mod))%mod;
                    a+=((z2%mod)*(a1%mod))%mod;
                    a+=((o2%mod)*(A1%mod))%mod;
                    A=a;
                    ll r=__gcd(q,__gcd(z,__gcd(o,__gcd(a,A))));
                    q=q/r;
                    z=z/r;
                    o=o/r;
                    a=a/r;
                    A=A/r;
                    values.push(z);
                    values.push(o);
                    values.push(a);
                    values.push(A);
                }
                
            }
        }
        A=values.top();
        values.pop();
        a=values.top();
        values.pop();
        o=values.top();
        values.pop();
        z=values.top();
        values.pop();
        //cout<<q<<endl;
        q=ModInverse(q,mod);
        ll ans1=((z%mod)*(q%mod))%mod;
        ll ans2=((o%mod)*(q%mod))%mod;
        ll ans3=((a%mod)*(q%mod))%mod;
        ll ans4=((A%mod)*(q%mod))%mod;
        //cout<<z<<" "<<o<<" "<<a<<" "<<A<<endl;
        cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
    }
    return 0; 
} 
