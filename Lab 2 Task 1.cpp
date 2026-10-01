#include <iostream>
using namespace std;

struct Student{
	int id;
	float marks;
};

int main() {
	Student st[10];
	float sum = 0;
	
	cout<<"=====Enter Marks of 10 Students====="<<endl;
	for(int i=0; i<10; i++) {
		st[i].id = i + 1;
		cout<<"Enter Marks for Student "<<st[i].id<<": ";
		cin>>st[i].marks;
		sum += st[i].marks;
	}
	
	float max_marks = st[0].marks;
	float min_marks = st[0].marks;
	
	for(int i=0; i<10; i++) {
		if (st[i].marks > max_marks) {
			max_marks = st[i].marks;
		}
		if (st[i].marks < min_marks) {
			min_marks = st[i].marks;
		}
	}
	
	float avg = sum / 10;
	
	cout<<"Average Marks: "<<avg<<endl;
	cout<<"Maximum Marks: "<<max_marks<<endl;
	cout<<"Minimum Marks: "<<min_marks<<endl;
	
	return 0;
}