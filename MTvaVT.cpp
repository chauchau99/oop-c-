#include<iostream>
#include<math.h>
using namespace std;
class MT{
	private:
	double a[20][20];
	int n;
	public:
		MT();
		MT(double a1[20][20],int n1);
		MT(const MT &b);
		friend istream & operator>> (istream &cin,MT &b);
		friend ostream & operator<< (ostream &cout,MT &b);
	    friend MT operator + ( MT x1, MT x2);
	    friend MT operator * ( MT x1, MT x2);
	    friend MT operator - ( MT x1, MT x2);
};
class VT{
	private:
		double b[20];
		int n;
	public:
		VT();
		VT(double b1[20],int n2);
		VT(const VT &c);
		friend istream &operator>>(istream &cin,VT &b);
		friend ostream &operator<<(ostream &cout,VT &b);
		
};
MT::MT(){
 {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                a[i][j] = 0;
            }
        }
    }
}
MT::MT(double a1[20][20],int n1){
	n=n1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=a1[i][j];
		}
	}
}
MT::MT(const MT &b){
	n=b.n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=b.a[i][j];
		}
	}
}
istream& operator>>(istream &cin,MT &b)
{
	do
	{
		cout<<"Nhap vao cap mat tran: "; cin>>b.n;
	}while(b.n<0||b.n>20);
	for(int i=0;i<b.n;i++)
	  for(int j=0;j<b.n;j++)
	  {
	  	cout<<"Nhap vao phan tu thu ["<<i<<"]["<<j<<"]: ";
	  	cin>>b.a[i][j];
	  }
}
ostream& operator<<(ostream &cout,MT &b)
{
	for(int i=0;i<b.n;i++){
	for(int j=0;j<b.n;j++){
		cout<<b.a[i][j]<<'\t';
	}cout<<endl;
    }
}
MT operator + ( MT x1, MT x2){
	
	MT c;
	int n=x1.n;
	c.n=n;
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c.a[i][j]=x1.a[i][j]+x2.a[i][j];
		}}
	return c;
}
MT operator * ( MT x1, MT x2)
{
	MT d;
	int n=x1.n;
	d.n=n;
	for(int i = 0; i<n ; i++)
   	for(int k = 0; k<n ; k++)
   	{
      	d.a[i][k] = 0;
    	for(int j = 0; j<n ; j++)
        	d.a[i][k] = d.a[i][k] + x1.a[i][j]*x2.a[j][k];
   	}

	return d;
}
MT operator - ( MT x1, MT x2){
	
	MT c;
	int n=x1.n;
	c.n=n;
	if(x1.n == x2.n)
		for(int i=0;i<x1.n;i++)
		for(int j=0;j<x1.n;j++)
		{
			c.a[i][j]=x1.a[i][j]-x2.a[i][j];
		}
	else cout<<"khong tru duoc"<<endl;
	return c;
}
main()
{
	MT a,b,c,d;
	cin>>a;
	cout<<a;
	cin>>b;
	cout<<b;
	//c=a+b;
	//cout<<"a+b"<<endl;
	//cout<<c;
	//d=b*a;
	//cout<<"b*a"<<endl;
	//cout<<d;
	c = a - b;
	cout<<"MT sau khi tru: ";
	cout<<c; 
	
}
