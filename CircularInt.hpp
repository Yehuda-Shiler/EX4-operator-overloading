
#include <string>
#include <iostream>
using namespace std;



class CircularInt {
public: int min, max, hour;

		CircularInt(int x, int y) {
			this->min = x;
			this->max = y;
			this->hour = rand() % (this->max) + this->min;
		}
		CircularInt(CircularInt &D)
		{
			this->hour = D.hour;
			this->max = D.max;
			this->min = D.min;
		}

		int normal(int a)
		{
			while (a<this->min || a>this->max)
			{
				if (a < this->min)
					a += this->max;
				else
					a -= this->max;
			}
			return a;
		}

		CircularInt& operator =(int m);
		friend CircularInt operator+(int a, CircularInt &D);
		friend CircularInt operator+(CircularInt &D, int a);
		CircularInt operator+(CircularInt &D);
		friend CircularInt operator-(int a, CircularInt &D);
		friend CircularInt operator-(CircularInt &D, int a);
		CircularInt operator-(CircularInt &D);
		int operator-();
		friend CircularInt operator*(int a, CircularInt &D);
		friend CircularInt operator*(CircularInt &D, int a);
		CircularInt operator*(CircularInt &D);
		friend CircularInt operator/(CircularInt &D, int a);
		friend CircularInt operator/(int a,CircularInt &D);
		CircularInt operator/(CircularInt &D);
		friend CircularInt operator%(CircularInt &D, int a);
		const CircularInt operator ++(int);
		CircularInt& operator ++();
		const CircularInt operator --(int);
		CircularInt& operator --();
		CircularInt& operator +=(int m);
		CircularInt&  operator +=(CircularInt &D);
		CircularInt operator -=(int m);
		CircularInt&  operator -=(CircularInt &D);
		CircularInt& operator *=(int m);
		CircularInt&  operator *=(CircularInt &D);
		CircularInt& operator /=(int m);
		CircularInt&  operator /=(CircularInt &D);
		bool operator==(int a);
		bool  operator==(CircularInt &D);
		friend int operator==(const int a,const CircularInt &D);
		friend int operator!=(const int a, const CircularInt &D);
		bool operator!=(int a);
		bool  operator!=(CircularInt &D);
		bool operator>(int a);
		bool operator>(CircularInt &D);
		friend int operator>(const int a, const CircularInt &D);
		bool operator<(int a);
		bool operator<(CircularInt &D);
		friend int operator<(const int a, const CircularInt &D);
		bool operator>=(int a);
		bool operator>=(CircularInt &D);
		friend int operator>=(const int a, const CircularInt &D);
		bool operator<=(int a);
		bool operator<=(CircularInt &D);
		friend int operator<=(const int a, const CircularInt &D);
		friend ostream &operator<<(ostream &output, const CircularInt &D);
		friend istream& operator>>(istream& is, CircularInt &D);

		};




		CircularInt& CircularInt:: operator =(int m)	//hour=10
		{
			this->hour = this->normal(m);
			return *this;
		}

		

		 CircularInt  operator+(int a, CircularInt &D)	//10+hour
		{
			CircularInt temp(D);
			temp.hour = temp.normal(D.hour + a);
			return temp;
		}

		 CircularInt  operator+(CircularInt &D, int a)   //hour+10
		{
			CircularInt temp(D);
			temp.hour = temp.normal(D.hour + a);
			return temp;
		}

		CircularInt CircularInt:: operator+(CircularInt &D)  //hour1+hour2
		{
			CircularInt temp(D);
			temp.hour = temp.normal(this->hour + D.hour);
			return temp;
		}

		 CircularInt  operator-(int a, CircularInt &D)   //10-hour
		{
			CircularInt temp(D);
			temp.hour = temp.normal(a - (D.hour));
			return temp;
		}
		 CircularInt operator-(CircularInt &D, int a)   //hour-10
		{
			CircularInt temp(D);
			temp.hour = temp.normal((D.hour)-a);
			return temp;
		}
		CircularInt CircularInt:: operator-(CircularInt &D)  //hour1-hour2
		{
			CircularInt temp(D);
			temp.hour = temp.normal(this->hour - D.hour);
			return temp;
		}
		int CircularInt:: operator-()                //-hour
		{
			int a = this->normal(-1 * this->hour);
			return a;
		}

		CircularInt operator*(int a, CircularInt &D)   //10*hour
		{
			CircularInt temp(D);
			temp.hour = temp.normal(a * (D.hour));
			return temp;
		}
		 CircularInt  operator*( CircularInt &D, int a)   // hour*10
		{
			CircularInt temp(D);
			temp.hour = temp.normal((D.hour)*a);
			return temp;
		}

		 CircularInt CircularInt:: operator*(CircularInt &D)   //hour1*hour2
		 {
			 CircularInt temp(D);
			 temp.hour = temp.normal((D.hour)*this->hour);
			 return temp;
		 }
		 CircularInt operator/(CircularInt &D, int a)   // hour/10
		{
			CircularInt temp(D);
			for (int i = temp.min; i < temp.max; ++i)
			{
				if ((i*a) % D.max == D.hour%D.max)
				{
					temp.hour = i;
					return temp;
				}
			}
			throw string("There is no number x in {1,12} such that x*" + to_string(a) + "=" + to_string(D.hour));
		}

		 CircularInt operator/(int a, CircularInt &D)   // 10/hour
		 {
			 CircularInt temp(D);
			 for (int i = temp.min; i < temp.max; ++i)
			 {
				 if ((i*a) % D.max == D.hour%D.max)
				 {
					 temp.hour = i;
					 return temp;
				 }
			 }
			 throw string("There is no number x in {1,12} such that x*" + to_string(a) + "=" + to_string(D.hour));
		 }

		 CircularInt CircularInt:: operator/(CircularInt &D)   // hour1/hour2
		 {
			 CircularInt temp(D);
		 for (int i = temp.min; i < temp.max; ++i)
		 {
			 if ((i*D.hour) % D.max == D.hour%D.max)
			 {
				 temp.hour = i;
				 return temp;
			 }
		 }
		 throw string("There is no number x in {1,12} such that x*" + to_string(this->hour) + "=" + to_string(D.hour));
		}

		 CircularInt operator%(CircularInt &D, int a)    //hour%10
		{
			CircularInt temp(D);
			temp.hour = temp.normal(D.hour%a);
			return temp;
		}

		const CircularInt CircularInt:: operator ++(int)  //hour++
		{
			CircularInt oldhour(*this);
			int a;

			if (this->hour == this->max) {
				a = this->min;
			}
			else
				a = this->hour + 1;
			this->hour = a;
			return oldhour;
		}
		CircularInt& CircularInt:: operator ++()     //++hour
		{
			int a;
			if (this->hour == this->max) {
				a = this->min;
				this->hour = a;
			}
			else
				a = this->hour + 1;
			this->hour = a;

			return *this;
		}

		const CircularInt CircularInt:: operator --(int)  //hour--
		{
			CircularInt oldhour(*this);
			int a;

			if (this->hour == this->min) {
				a = this->max;
			}
			else
				a = this->hour - 1;
			this->hour = a;
			return oldhour;
		}

		CircularInt& CircularInt:: operator --()     //--hour
		{
			int a;
			if (this->hour == this->min) {
				a = this->max;
				this->hour = a;
			}
			else
				a = this->hour - 1;
			this->hour = a;

			return *this;
		}
		CircularInt& CircularInt:: operator +=(int m)  // hour+=10
		{
			int a = (this->hour + m) % this->max;
			if (a == 0) {
				this->hour = this->max;
			}
			else
			{
				this->hour = a;
			}
			return *this;
		}

		CircularInt& CircularInt:: operator +=(CircularInt &D)  // hour1+=hour2
		{
			this->hour = this->normal(this->hour + D.hour);
			return *this;
		}

		CircularInt CircularInt:: operator -=(int m)    // hour-=10
		{
			int ans, a = this->hour - m;
			a = a % (this->max) + this->min;
			if (a > 0) {
				ans = a;
			}
			else
				ans = this->max + a;

			this->hour = ans;
			return *this;
		}

		CircularInt& CircularInt:: operator -=(CircularInt &D)  // hour1-=hour2
		{
			this->hour = this->normal(this->hour - D.hour);
			return *this;
		}

		CircularInt& CircularInt:: operator *=(int m)    //// hour*=10
		{
			int a = (this->hour * m) % this->max;
			if (a == 0) {
				this->hour = this->max;
			}
			else {
				this->hour = a;
			}
			return *this;
		}

		CircularInt& CircularInt:: operator *=(CircularInt &D)    //// hour1*=hour2
		{
			this->hour = this->normal(this->hour * D.hour);
			return *this;
		}

		CircularInt& CircularInt:: operator /=(int m)    // hour/=10
		{
			for (int i = this->min; i < this->max; ++i)
			{
				if ((i*m) % this->max == this->hour%this->max)
				{
					this->hour = i;
					return *this;
				}
			}
			throw string("There is no number x in {1,12} such that x*" + to_string(m) + "=" + to_string(this->hour));
		}

		CircularInt& CircularInt:: operator /=(CircularInt &D)    //// hour1*=hour2
		{
			for (int i = this->min; i < this->max; ++i)
			{
				if ((i*D.hour) % this->max == this->hour%this->max)
				{
					this->hour = i;
					return *this;
				}
			}
			throw string("There is no number x in {1,12} such that x*" + to_string(D.hour) + "=" + to_string(this->hour));
		}
		
		bool CircularInt:: operator==(int a)  //hour==10
		{
			if (this->hour == this->normal(a))
				return true;
			else
				return false;
		}
		 int  operator==(const int a, CircularInt &D)  //10==hour
		{
			if (D.hour == D.normal(a))
				return true;
			else
				return false;
		}

		bool CircularInt:: operator==(CircularInt &D)  //hour1==hour2
		{
			if (this->hour == D.hour&&this->max == D.max&&this->min == D.min)
				return true;
			else
				return false;
		}

		bool CircularInt:: operator!=(int a)     //hour!=10
		{
			if (this->hour != this->normal(a))
				return true;
			else
				return false;
		}

		int  operator!=(const int a, CircularInt &D)  //10!=hour
		{
			if (D.hour != D.normal(a))
				return true;
			else
				return false;
		}
		bool CircularInt:: operator!=(CircularInt &D)  //hour1!=hour2
		{
			if (this->hour != D.hour||this->max != D.max||this->min != D.min)
				return true;
			else
				return false;
		}

		bool CircularInt:: operator>(int a)           //hour>10
		{
			if (this->hour > this->normal(a))
				return true;
			else
				return false;
		}

		bool CircularInt:: operator>(CircularInt &D)           //hour1>hour2
		{
			if (this->hour > D.hour)
				return true;
			else
				return false;
		}

		 int operator>(const int a, const CircularInt &D)     //10>hour
		{
			if (a > D.hour)
				return true;
			else
				return false;
		}
		bool CircularInt:: operator<(int a)                 //hour<10
		{
			if (this->hour < this->normal(a))
				return true;
			else
				return false;
		}

		bool CircularInt:: operator<(CircularInt &D)           //hour1<hour2
		{
			if (this->hour < D.hour)
				return true;
			else
				return false;
		}

		int operator<(const int a, const CircularInt &D)      //10<hour
		{
			if (a < D.hour)
				return true;
			else
				return false;
		}
		bool CircularInt:: operator>=(int a)
		{
			if (this->hour >= this->normal(a))
				return true;
			else
				return false;
		}

		bool CircularInt:: operator>=(CircularInt &D)
		{
			if (this->hour >= D.hour)
				return true;
			else
				return false;
		}


		int operator>=(const int a, const CircularInt &D)      //10>=hour
		{
			if (a>= D.hour)
				return true;
			else
				return false;
		}

		bool CircularInt:: operator<=(int a)
		{
			if (this->hour <= this->normal(a))
				return true;
			else
				return false;
		}

		bool CircularInt:: operator<=(CircularInt &D)
		{
			if (this->hour <= D.hour)
				return true;
			else
				return false;
		}

		int operator<=(const int a, const CircularInt &D)      //10<=hour
		{
			if (a <= D.hour)
				return true;
			else
				return false;
		}

		ostream &operator<<(ostream &output, const CircularInt &D) //output
		{
			output << D.hour;
			return output;
		}

		 istream& operator>>(istream& is, CircularInt &D)     //input
		{
			is >> D.hour;
			return is;
		}


		

		

		

