#include<iostream>
#include<string>
using namespace std;
class timein12
{
	private:
		bool pm;
		int hrs;
		int min;
	public:
		timein12()
		{
			pm=true;
			hrs=0;
			min=0;
		}
		timein12(bool ap,int h,int m)
		{
			pm=ap;
			hrs=h;
			min=m;
		}
		void display()const
		{
			cout<<hrs<<":";
			if(min<10)
				cout<<'0';
			cout<<min<<" ";
			string am_pm=pm?"p.m.":"a.m.";
			cout<<am_pm;
		}
};
class timein24
{
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		timein24()
		{
			hours=0;
			minutes=0;
			seconds=0;
		}
		timein24(int h,int m,int s)
		{
			hours=h;
			minutes=m;
			seconds=s;
		}
		void display()const
		{
			if(hours<10)
				cout<<'0';
			cout<<hours<<":";
			if(minutes<10)
				cout<<'0';
			cout<<minutes<<":";
			if(seconds<10)
				cout<<'0';
			cout<<seconds;
		}
		operator timein12()const;
};
timein24::operator timein12()const
{
	int hrs24=hours;
	bool pm=hours<12?false:true;
	int roundMins=seconds<30?minutes:minutes+1;
	if(roundMins==60)
	{
		roundMins=0;
		++hrs24;
		if(hrs24==12||hrs24==24)
			pm=(pm==true)?false:true;
	}
	int hrs12=(hrs24<13)?hrs24:hrs24-12;
	if(hrs12==0)
	{
		hrs12=12;
		pm=false;
	}
	return timein12(pm,hrs12,roundMins);
}
int main()
{
		int h,m,s;
		while(true)
		{
			cout<<"Enter 24-hour time:\n";
			cout<<"hours (0to 23):";
			cin>>h;
			if(h>23)
				return 1;
			cout<<"Minutes (0 to 59):";
			cin>>m;
			if(m>59)
				return 1;
			cout<<"Seconds (0 to 59):";
			cin>>s;
			if(s>59)
				return 1;
			timein24 t24(h,m,s);
			cout<<"You entered\n";
			t24.display();
			timein12 t12=t24;
			cout<<"\n12-hour time:";
			t12.display();
			cout<<"\n\n";
		}
		return 0;
}

