#include<iostream>
#include<cmath>
using namespace std;
class Degree
{
	int degval;
	public:
		Degree(){degval=0;}
		Degree(int val){degval=val;}
		void readdeg(){cin>>degval;}
		void displaydeg(){cout<<"Degree: "<<degval<<endl;}
		int fetchdegval(){return degval;}
};
class Radian
{
	float radval;
	public:
		Radian(){radval=0.0;}
		Radian(Degree d)
		{
			cout<<"\nConstructor Called\n";
			radval=d.fetchdegval()*M_PI/180;
		}
		void readrad(){cin>>radval;}
		void displayrad(){cout<<"Radian: "<<radval<<endl;}
		operator Degree() const;
};
Radian::operator Degree()const
{
	cout<<"\nConversion operator called\n";
	int degree;
	degree=int (round(radval*180/M_PI));
	return Degree(degree);
}
int main()
{
	Degree davg;
	cout<<"\nEnter an angle in degrees\n";
	davg.readdeg();
	davg.displaydeg();
	cout<<"\nDegree to Radian conversion\n";
	Radian ravg(davg);
	ravg.displayrad();
	cout<<"\nRadian to degree conversion\n";
	Degree newavg=static_cast<Radian>(ravg);
	newavg.displaydeg();
	return 0;
}

