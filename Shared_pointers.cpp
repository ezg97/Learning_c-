#include <iostream>
#include <memory> //for smart pointers
#include <string>




class Person 
{
	std::string name;
	int age;
public:
	std::string to_string()
	{
		return name + ", " + std::to_string(age) + "\n";
	}
	// constructor
	Person(){name="";age=0;}
	Person(const std::string& name, int age)
	{   this->name=name;
	    this->age=age;	}
};

int main()
{
	std::shared_ptr<Person> p1 = std::make_shared<Person>("John Axel Wayne",76);
    std::shared_ptr<Person> p2 = p1; // coppied the first shared pointer!
    std::shared_ptr<Person> p3;
    p3=p2;
    std::shared_ptr<Person> p4 = std::make_shared<Person>("Lil wey",21);
    
    
    std::cout<<"Person 1: "<<p1->to_string();	
    std::cout<<"Person 2: "<<p2->to_string();
    std::cout<<"Person 3: "<<p3->to_string();
    std::cout<<"Person 4: "<<p4->to_string();
    
	/*
	ezg5 = move(ezg6);	//destroy 5, ezg5 manages 6

//********* Checking if unique pointer ezg6 still exists ****************
	if (!ezg6)
	{
		cout<<"\n-----\tezg6 is no longer.\t-----\n\n";
	}
	
	ezg1.reset();	// destroy 1
	
	ezg1.reset(new Thing);	// ezg1 manages 7

	cout<< ezgArr2[0].to_string();
	cout<< ezgArr2[1].to_string();
	
	
	ezg1.release(); // only for unique pointers, it releases
	//ownership of the object.
	if (!ezg1)
	{
		cout<<"Thing 7 has been released.\n";
	}
	
	Thing* ptr = ezg5.release(); // releases Thing 6 from the managemnet of ezg5 and is now stored in the raw pointer "ptr"
	if (!ezg5)
	{
		cout<<"\n+++++ Thing 6 has been released from the unique pointer!\n\t and is now stored in the raw pointer 'ptr'! +++++\n";
		cout<<ptr->to_string()<<" this is the raw pointer!\n";
		ptr = nullptr; // pretty much the same affect as releasing a smart pointer but for raw pointers
		if(!ptr)
		{
			cout<<"Thing 6 destroyed.\n\n";
		}
	}
	// now all smart pointers will go out of scope
	*/
	return 0;
}
