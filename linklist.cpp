#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
public:
int data;
Node *link;
}*start=NULL;
Node *cn()	// creating node
{
	Node *tmp;
	tmp=new(Node);
	cout<<"Enter no:";
	cin>>tmp->data;
	tmp->link=NULL;
	return(tmp);
}
int pn(int k)	//print node & count node
{
	Node *t=start;
	int cnt=0;
        if(start==NULL)
        {
        	cout<<"\nNo node available";
     	}
     	while(t!=NULL)
     	{
        	if(k==1)
		{
            		cout<<t->data<<" ";
        	}
     		t=t->link;
     		cnt++;
     	}
	return(cnt);
}
void inl()	//insert node at last
{
	if(start!=NULL)
    	{
    		Node *t=start;
		while(t->link!=NULL)
		{
	        	t=t->link;
		}
		t->link=cn();
    	}
    	else
    	{
    		start=cn();
	}
}
void ina()		//insert at anywhere
{
	int n;
	Node *t=start;
	cout<<"Enter N:";  // enter node no where u want to insert
	cin>>n;  
	if(n==1)
        {
            t=cn();
            t->link=start;
            start=t;
        }
        else
        if( !(n<=(pn(2)+1)))	// condition shows you have given the value which is greater than number of nodes available
        {
            cout<<"\nInvalid Location";
        }
        else
 	{
        	Node *t1;
		while(n>2)
            	{
                	t=t->link;
                	n--;
            	}
            	t1=cn();
           	t1->link=t->link;
	        t->link=t1;
        }
}


void dan()	//delete any node
{
	int n;
	cout<<"Enter N:";
	cin>>n;//cnt =3
     	if(!(n<=pn(2))&&n>0)
     	{
        	cout<<"\nInvalid Node no";
     	}
     	else
     	{
     		Node *t=start;
     		Node *t1;
          	if(n==1)
          	{
               		start=start->link;
               		t->link=NULL;
               		delete(t);
          		cout<<"\nDelete Node";
		}
          	else
          	{
               		while(n>2)
               		{
               			t=t->link;
              	 		n--;
               		}
          		t1=t->link;
          		t->link=t1->link;
          		t1->link=NULL;
          		delete(t1);
          		cout<<"\nDelete Node";
          	}
     	}
}
void sn(int k,int r)	//search Node // & replace node
{
	int n;
	Node *t=start;
	cout<<"\nEnter N:";
	cin>>n;
	if(t==NULL)
	{
	     cout<<"Data not Found";
	}
  	while(t!=NULL)
	{
        	if(t->data==n&&k==2)
               	{
                	t->data=r;
                   	break;
		}
		if(t->data==n)
               	{
            		cout<<"Data find";
                    	break;
               	}
               	else if(t->link==NULL)
                {
                	cout<<"Not Found";
                }
          	t=t->link;
	}
}
void snd()	//search node & delete
{
	int n;
	Node *t=start,*t1;
	cout<<"Enter N:";
	cin>>n;
	if(t->data==n)
	{
		start=start->link;
	     	t->link=NULL;
	        delete(t);
      	        cout<<"\nDelete Element";
	}
	else
	{
		while(t->link->data!=n)
		{
			t=t->link;
		}
		t1=t->link;
		t->link=t1->link;
		t1->link=NULL;
		delete(t1);
		cout<<"\nDelete Element";
	}
}

void pr()	//print reverse
{
	Node *t=start;
	int z=pn(2),k;//4
	while(z>0)
	{
		t=start;
	     	k=z;
		while(k>1)
		{
			t=t->link;
		        k--;
		 }
		cout<<t->data<<" ";
	     	z--;
	}
}

void st()	//sort nodes
{
	int n=pn(2);
	Node *t=start;
	int tmp;
	while(n>1)
	{
		t=start;
		while(t->link!=NULL)
		{
			if(t->data > t->link->data )
			{
				tmp=t->data;
				t->data=t->link->data;
				t->link->data=tmp;
			}
			t=t->link;
		}
		n--;
	}
}

int main()
{
	int ch;
	while(1)
	{
		  cout<<"\nMenu:";
		  cout<<"\n1.Insert at last";
		  cout<<"\n2.Print Node";
		  cout<<"\n3.Count Node";
		  cout<<"\n4.Insert at anywhere";
		  cout<<"\n5.Delete  Any Node";
		  cout<<"\n6.Search Node";
		  cout<<"\n7.Search Element & delete it";
		  cout<<"\n8.Replace Element";
		  cout<<"\n9.Print reverse";
		  cout<<"\n10.Sort";
		  cout<<"\n11.Exit";
		  cout<<"\nEnter choice:";
		  cin>>ch;
		       switch(ch)
		       {
			    case 1:
			    {
			    inl();
			    break;
			    }
			    case 2:
				 {
				      pn(1);//1 is for print
				      break;
				 }
			    case 3:
				 {
				 int z;
				      z=pn(2);//2 is for cnt
				      cout<<"\nTotal no of node:"<<z;
				      break;
				 }
			    case 4:
				 {
				      ina();
				      break;
				 }
			    case 5:
				 {
				      dan();
				      break;
				 }
			    case 6:
				 {
				      sn(1,0);//search node// 0 is for .. no replacement
				      break;
				 }
			    case 7:
				 {
				      snd();
				      break;
				 }
			    case 8:
				 {
				 int r;
				 cout<<"Enter replace element:";
				 cin>>r;//30
				      sn(2,r);//replace node
				      break;
				 }
			    case 9:
				 {
				      pr();
				      break;
				 }
			    case 10:
				 {
				      st();//sort
				      break;
				 }
			    case 11:
				 {
				      exit(0);
				 }
			    default:
				 {
				      cout<<"Invalid choice";
				 }
		       }
	}
}


