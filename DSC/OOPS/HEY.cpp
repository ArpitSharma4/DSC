//Write a program of class employee with Employee number,name,basic salary.Write appropriate member function to read,display and to calculate net salary.Display it.
#include<iostream>
using namespace std;
class employee{
    int emp,salary;
    char name[20];
    public:
    void read(){
        cout<<"Enter the name,emp no and salary of the employee"<<endl;
        cin>>name;
        cin>>emp>>salary;
    }
    void display(){
        cout<<"Details of the employee are:"<<endl;
        cout<<name<<endl;
        cout<<emp<<endl;
        cout<<salary<<endl;
        cout<<"Net salary of the employee is:"<<endl;
    }
    float netsalary()
    {
        float nets;
        float DA,IT;
        DA=0.52*salary;
        IT=0.3*salary;
        nets=salary+DA-IT;
        return nets;
    }
};
    int main(){
        employee e1;
        e1.read();
        e1.display();
        float NS=e1.netsalary();
        cout<<NS;
        return 0;

    }
