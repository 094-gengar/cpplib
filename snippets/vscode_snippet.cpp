#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstring>
#include<deque>
#include<functional>
#include<iostream>
#include<iomanip>
#include<map>
#include<numeric>
#include<optional>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<tuple>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#pragma GCC target("avx512f")
#pragma GCC optimize("O3")
#define int long long
#define itn int
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define I32(...) i32 __VA_ARGS__;in(__VA_ARGS__)
#define I64(...) i64 __VA_ARGS__;in(__VA_ARGS__)
#define U32(...) u32 __VA_ARGS__;in(__VA_ARGS__)
#define U64(...) u64 __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vt(tp) vector<tp>
#define vvt(tp) vector<vector<tp>>
#define vvt2(nm,tp,h,w,n) vector<vector<tp>>nm((h),vector<tp>(w,n))
#define P pair<int,int>
#define all(x) x.begin(),x.end()
#define rsort(x) sort(all(x));reverse(all(x))
#define unq(v) v.erase(unique(all(v)),v.end())
#define l_b(c,x) distance(c.begin(),lower_bound(all(c),(x)))
#define u_b(c,x) distance(c.begin(),upper_bound(all(c),(x)))
#define fi first
#define se second
#define mkpr make_pair
#define pb push_back
#define eb emplace_back
#define spc ' '
#define pass 
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a),__B_SIZE__=(b);i<__B_SIZE__;i++)
#define _per(i,n) peri(i,n,0)
#define peri(i,a,b) for(int i=(a),__B_SIZE__=(b);i>=__B_SIZE__;i--)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define per(...) _overload3(__VA_ARGS__,peri,_per,)(__VA_ARGS__)
#define bitshift(n) (1LL<<(n))
#define myceil(a,b) ((a)+((b)-1))/(b)
#define scale(n) cout<<fixed<<setprecision(n)
namespace gengar094
{
	using i32=std::int32_t;
	using i64=std::int64_t;
	using u32=std::uint32_t;
	using u64=std::uint64_t;
	using isize=std::ptrdiff_t;
	using usize=std::size_t;
	using ll=long long;
	using ull=unsigned long long;
	
	int Scan(){return getchar();}
	void Scan(signed&a){scanf("%d",&a);}
	void Scan(unsigned&a){scanf("%u",&a);}
	void Scan(long&a){scanf("%ld",&a);}
	void Scan(long long&a){scanf("%lld",&a);}
	void Scan(unsigned long long&a){scanf("%llu",&a);}
	void Scan(char&a){do{a=getchar();}while(a==' '||a=='\n');}
	void Scan(float&a){scanf("%f",&a);}
	void Scan(double&a){scanf("%lf",&a);}
	void Scan(long double&a){scanf("%Lf",&a);}
	void Scan(std::string&a){std::cin>>a;}
	template<class T>void Scan(std::vector<T>&);
	template<class T,class U>void Scan(std::pair<T,U>&);
	template<class T>void Scan(std::vector<T>&a){for(auto&&i:a)Scan(i);}
	template<class T,class U>void Scan(std::pair<T,U>&a){Scan(a.first);Scan(a.second);}
	template<class T>void Scan(T&a){std::cin>>a;}
	void in(){}
	template<class Car,class...Cdr>void in(Car&&car,Cdr&&...cdr){Scan(car);in(std::forward<Cdr>(cdr)...);}
	
	void Print(){putchar(' ');}
	void Print(signed a){printf("%d",a);}
	void Print(bool a){printf("%d",a);}
	void Print(unsigned a){printf("%u",a);}
	void Print(long a){printf("%ld",a);}
	void Print(long long a){printf("%lld",a);}
	void Print(unsigned long long a){printf("%llu",a);}
	void Print(char a){printf("%c",a);}
	void Print(float a){printf("%f",a);}
	void Print(double a){printf("%lf",a);}
	void Print(long double a){printf("%Lf",a);}
	void Print(const std::string&a){for(auto&&i:a)Print(i);}
	template<class T>void Print(const std::vector<T>&);
	template<class T,class U>void Print(const std::pair<T,U>&);
	template<class T>void Print(const std::vector<T>&a){if(a.empty())return;Print(a[0]);for(auto i=a.begin();++i!=a.end();){putchar(' ');Print(*i);}}
	template<class T,class U>void Print(const std::pair<T,U>&a){Print(a.first);putchar(' ');Print(a.second);}
	template<class T>void Print(const T&a){std::cout<<a;}
	void out(){}
	template<class T>void out(const T&t){Print(t);putchar('\n');}
	template<class Car,class...Cdr>void out(Car&car,Cdr&...cdr){Print(car);putchar(' ');out(std::forward<Cdr>(cdr)...);}
	
	void yn(bool fl=true){out(fl?"Yes":"No");}
	template<class T>void drop(T x){std::cout<<(x)<<std::endl;exit(0);}
	void dYes(){std::flush(std::cout);puts("Yes");std::flush(std::cout);exit(0);}
	void dNo(){std::flush(std::cout);puts("No");std::flush(std::cout);exit(0);}
	int gcd(int a,int b){return b?gcd(b,a%b):a;}
	int lcm(int a,int b){return a/gcd(a,b)*b;}
	int fact(int n,int m){int f=n;for(int i=n-1;i>=1;i--){f*=i;f%=m;}return f;}
	template<typename T>std::vector<std::pair<T,T>>prime_factor(T n)
	{
		std::vector<std::pair<T,T>>ret;
		for(T i=2;i*i<=n;i++)
		{if(n%i!=0)continue;T tmp=0;
		while(n%i==0){tmp++;n/=i;}ret.push_back(make_pair(i,tmp));}
		if(n!=1)ret.push_back(make_pair(n,1));
		return ret;
	}
	template<class T>int chmin(T&a,const T&b){if(b<a){a=b;return 1;}return 0;}
	template<class T>int chmax(T&a,const T&b){if(a<b){a=b;return 1;}return 0;}
	const ll inf=0x1fffffffffffffff;
	const double pi=acos(-1);
	const int mod=1000000007;//998244353
	
	auto _main=[]()
	{
		using namespace std;
		
	};
}


std::int32_t main()
{
	//std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	gengar094::_main();
	return 0;
}