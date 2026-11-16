#include<iostream>
using namespace std;

class PQ{
	private:
		int Id[5];
		string Name[5];
		int pri[5];
	
		int size;
		int cap;
		
		public:
			PQ()
			{
				size=0;
				cap=5;
			}
			
		void enqueue(int id, string na, int pr)
		{
			if(size==cap)
			{
				cout<<"Queue is Full"<<endl;
				return;
			}
			
			Id[size]=id;
			Name[size]=na;
			pri[size]=pr;
			
			size++;
			cout<<"====== Data Added ======"<<endl;
		}
		
		void dequeue()
		{
			if(size==0)
			{
				cout<<"Queue is Empty"<<endl;
				return;
			}
			int max=0;
			
			for(int i=1; i<size; i++)
			{
				if(pri[i]<pri[max])
				{
					max=i;
				}
				
				
			}
			cout<<"==============================="<<endl;
			cout<<"Priority wise List"<<endl;
			cout<<"ID of Student :"<<Id[max]<<endl;
			cout<<"Name of Student :"<<Name[max]<<endl;
			cout<<"Priority of Student :"<<pri[max]<<endl;
			cout<<"==============================="<<endl;
			
			for(int i=max; i<size; i++)
			{
				Id[i]=Id[i+1];
				Name[i]=Name[i+1];
				pri[i]=pri[i+1];
				
				
			}
			size--;
		}
	
	void peek()
	{
		if(size==0)
			{
				cout<<"Queue is Empty"<<endl;
				return;
			}
			
			int high=0;
				for(int i=1; i<size; i++)
			{
				if(pri[i]<pri[high])
				{
					high=i;
				}
				
			}
			cout<<"Next Record"<<endl;
			cout<<"ID "<<Id[high]<<endl;
			cout<<"Name "<<Name[high]<<endl;
			cout<<"Priority "<<pri[high]<<endl;
	
	}
	void display()
	{
		if(size==0)
		{
			cout<<"Queue is empty"<<endl;
			return;
		}
		for(int i=0; i<size; i++)
		{
			cout<<"Overall Students"<<endl;
			cout<<"ID "<<Id[i]<<endl;
			cout<<"Name "<<Name[i]<<endl;
			cout<<"Priority"<<pri[i]<<endl;
				
			
		}
		
	}
	
};

int main()
{
	
	PQ cl;
	int choice, id,p;
	string name;
	
	do{
		
		cout<<"University Priority System"<<endl;
		cout<<"1. Add Record"<<endl;
		cout<<"2. Read Record"<<endl;
		cout<<"3. View Record"<<endl;
		cout<<"4. Display all record"<<endl;
		cout<<"5. Exit"<<endl;
		
		cout<<"Enter your Choice: ";
		cin>>choice;
		cout<<"==============================="<<endl;
		switch(choice)
		{
			case 1:	cout<<"Enter id: ";
					cin>>id;
					cout<<"Enter Name: ";
					cin>>name;
					cout<<"Enter your Priority: ";
					cin>>p;
					if(p<1||p>3)
					{
						cout<<"invaild Priority Number"<<endl;
					}
					else
					{
						cl.enqueue(id,name,p);
					}
					break;
			case 2:
					cl.dequeue();
					break;
			case 3:	cl.peek();
					break;
			case 4: cl.display();
					break;
			case 5:	cout<<"We are leaving system"<<endl;
					break;
				defult:
					cout<<"Invalid Choice"<<endl;
			
		}
		
		
	}while(choice!=5);
	
	
	return 0;
}


