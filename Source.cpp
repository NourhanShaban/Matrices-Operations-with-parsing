#include<iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <math.h>
#define stop cout<<"ERROR";
using namespace std;

//////////////////////////////GET ROWS FOR STRING MATRIX////////////////////////////////////

int get_rows (string Mat1)
{
	int counter=0;
	for(int i=0;i<Mat1.length();i++)
	{
		if(Mat1[i]==';')
		{
			counter++;
		}
	}
	counter++;
	return counter;
}

/////////////////////////// GET COLUMNS FOR STRING MATRIX////////////////////////////////////////////
int get_columns(string Mat1)
{
	int counter=0;
	string z="";
	int y=Mat1.find(";");
	z=Mat1.substr(0,y);
	for(int i=0;i<z.length();i++)
	{
		if(Mat1[i]==' ')
		{
			counter++;
		}
	}
	counter++;
	return counter;
}
//////// /////////////////////INPUT A STRING MATRIX AND GET FLOAT ONE FOR OPERATIONS///////////////
void get_array(string Mat1,float arr1[100][100],int &rn,int &cn)
{
    int s=0;
	int i=0;
	string row="";
	int j=0;
	string item="";
	
  int x;
    int p;
   int counter=0;
   string r="";
	string z="";
	int y=Mat1.find(";");
	z=Mat1.substr(0,y);
	for(int i=0;i<z.length();i++)
	{
		if(z[i]==' ')
		{
			counter++;
		}
	}
	x=counter;
	p=y+1;
	
	while(p<Mat1.length())
	{
		int f=Mat1.find(";",p);
		if(f!=-1)
		{
			r=Mat1.substr(p,f-p);
			p=f+1;
		}
		else
		{
			r=Mat1.substr(p,Mat1.length()-p);
			p=Mat1.length();
		}
		int counter1=0;
		for(int q=0;q<r.length();q++)
		{
			if(r[q]==' ')
			{
				counter1++;
			}
		}
		if(counter1!=x)
		{
			stop;
			exit(0);
		}
	}
	if(Mat1[0]!='['||Mat1[Mat1.length()-1]!=']')
	{
		stop;
		exit(0);
	}
	
	else
	{
		Mat1.erase(0,1);
		Mat1.erase(Mat1.length()-1,1);
	}
		 rn=get_rows(Mat1);
		 cn=get_columns(Mat1);
		while(s<rn) 
		{
 				int w = 0;
				while(i<Mat1.length())
				{
					int y=Mat1.find(";",i);
					if(y!=-1)
					{
						row=Mat1.substr(i,y-i);
						i=y+1;
					}
					else
					{
						row=Mat1.substr(i,Mat1.length()-i);
				    	i=Mat1.length();
					}
					j=0;
			
					while(j<row.length())
					{
						int f=row.find(" ",j);
							if(f!=-1)
							{
								item=row.substr(j,f-j);
								j=f+1;
							}
							else
							{
								item=row.substr(j,row.length()-j);
								j = row.length();
								
							}
							float val=atof(item.c_str());

							arr1[s][w++]=val;
							if(w>=cn)
							{
								s++;
								w=0;
							}	
					}					
				}				
		}
		
		for(int y=0;y<rn;y++)
		{
			for(int k=0;k<cn;k++)
			{
			  arr1[y][k];
			}
		}

		
}
int main()
{   
   float result [100][100];
	string u;
	string  Matrix1;
	getline (cin,Matrix1);
	float Mat1 [100][100];
	int row,col;
	get_array(Matrix1,Mat1,row,col);

	getline(cin,u);
	
if(u=="+")
{
      int e,s,h,l;
  	string  Matrix2;
	float Mat2 [100][100];
	getline (cin,Matrix2);
	
	get_array(Matrix2,Mat2,h,l);
	
	e=row;
	s=col;
	h=get_rows(Matrix2);
	l=get_columns(Matrix2);
	
	if(e==h && s==l)
	{
		cout<<"[";
		for(int u=0;u<e;u++)
		{
			for(int d=0;d<s;d++)
			{ 
			 result [u][d]=Mat1[u][d]+Mat2[u][d];
		
	         string str;
	        ostringstream ss;
	        ss<<result[u][d];
			str=ss.str();
			if(u==e-1&&d==s-1)
			{
				cout<<str<<"]";
			}
				else if(d==s-1)
			{ 
				
				cout<<str<<";";
			}
		
				else
				
		
			cout<<str<<" ";
	       
				
			}
		}
	
	}

	else
	{
		stop;
		exit(0);
	}
}
else if(u=="-")
{
      int f,t,o,p;
	 float result1 [100][100];
  	string  Matrix3;
	float Mat3 [100][100];
	getline (cin,Matrix3);	
	get_array(Matrix3,Mat3,o,p);
	
	f=row;
	t=col;
	o=get_rows(Matrix3);
	p=get_columns(Matrix3);
	
	if(f==o && t==p)
	{
		cout<<"[";
		for(int i=0;i<f;i++)
		{
			for(int y=0;y<t;y++)
			{ 
				 result1 [i][y]=Mat1[i][y]-Mat3[i][y];
		
	         string os;
	        ostringstream s;
	        s<<result1[i][y];
			os=s.str();
			if(i==f-1&&y==t-1)
			{
				cout<<os<<"]";
			}
				else if(y==t-1)
			{ 
				
				cout<<os<<";";
			}
		
				else
			
			cout<<os<<" ";
	       
				
			}
		}
	}
	else
	{
		stop;
		exit(0);
	}
}
else if(u=="*")
{   float result2 [100][100];
	int b,k,w,m;
	float Mat4 [100][100];
	string Matrix4;
	getline(cin,Matrix4);
	get_array(Matrix4,Mat4,w,m);
	b=row;
	k=col;
	w=get_rows(Matrix4);
	m=get_columns(Matrix4);
	if (k==w)
	{   cout<<"[";
		for(int j=0;j<b;j++)
		{   
			for(int r=0;r<m;r++)
			{ 
				 result2[j][r]=0;
				for(int g=0;g<k;g++)
				{
					result2 [j][r]=result2 [j][r]+Mat1[j][g]*Mat4[g][r];
				}
				
				 string ot;
	        ostringstream so;
	        so<<result2[j][r];
			ot=so.str();
			if(j==b-1&&r==m-1)
			{
				cout<<ot<<"]";
			}
				else if(r==m-1)
			{ 
				
				cout<<ot<<";";
			}
		
				else
			
			cout<<ot<<" ";


			}
		}
	}


	else
	{
		stop;
		exit(0);
	}
}
 
else if(u=="T")
{
	
	float result5 [100][100];
	int x,n;
	x=row;
	n=col;
	cout<<"[";
	for(int a=0;a<n;a++)
	{
		for(int v=0;v<x;v++)
		{
			
			
			result5[a][v]=Mat1[v][a];
			

				 string stp;
	        ostringstream sp;
	        sp<<result5[a][v];
			stp=sp.str();
			if(v==x-1&&a==n-1)
			{
				cout<<stp<<"]";
			}
				else if(v==x-1)
			{ 
				
				cout<<stp<<";";
			}
		
				else
				
		
			cout<<stp<<" ";
	       
		}
	}
}
}
