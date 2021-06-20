template<long long Mod>struct modInt
{
	long long x;
	constexpr modInt()noexcept:x(){}
	template<typename T>
	constexpr modInt(T v=0)noexcept:x(v%Mod){if(x<0)x+=Mod;}
	constexpr long long getval()const noexcept{return x;}
	constexpr modInt operator-()const noexcept{return x?Mod-x:0;}
	constexpr modInt operator+(const modInt&r)const noexcept{return modInt(*this)+=r;}
	constexpr modInt operator-(const modInt&r)const noexcept{return modInt(*this)-=r;}
	constexpr modInt operator*(const modInt&r)const noexcept{return modInt(*this)*=r;}
	constexpr modInt operator/(const modInt&r)const noexcept{return modInt(*this)/=r;}
	constexpr modInt&operator+=(const modInt&r)noexcept{x+=r.x;if(x>=Mod)x-=Mod;return*this;}
	constexpr modInt&operator-=(const modInt&r)noexcept{x-=r.x;if(x<0)x+=Mod;return*this;}
	constexpr modInt&operator*=(const modInt&r)noexcept{x=x*r.x%Mod;return*this;}
	constexpr modInt&operator/=(const modInt&r)noexcept{x=x*r.inv();return*this;}
	constexpr modInt powm(long long n)noexcept
	{
		if(n<0)return powm(-n).inv();
		modInt x=*this,r=1;
		for(;n;x*=x,n>>=1)if(n&1)r*=x;
		return r;
	}
	constexpr modInt inv()const noexcept
	{
		long long a=x,b=Mod,u=1,v=0;
		while(b)
		{
			long long t=a/b;
			a-=t*b;swap(a,b);
			u-=t*v;swap(u,v);
		}
		return modInt(u);
	}
	constexpr bool operator==(const modInt&r){return this->x==r.x;}
	constexpr bool operator!=(const modInt&r){return this->x!=r.x;}
	friend ostream&operator<<(ostream&os,const modInt<Mod>&a){return os<<a.x;}
	friend istream&operator>>(istream&is,modInt<Mod>&a){long long v;is>>v;a=modInt<Mod>(v);return is;} 
};

//const long long mod=1000000007;
//using mint=modInt<mod>;