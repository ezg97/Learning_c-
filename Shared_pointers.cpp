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
	Person(const std::string& name, int age);
	void printAddressAndValue();
};
Person :: Person(const std::string& name, int age)
{   this->name=name;
	    this->age=age;	}
void Person::printAddressAndValue()
{
	std::cout<<"The object at address "<<this<<" has a "
		 <<" value of: "<<(*this).age<<std::endl;
}

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
    
    std::cout<<"\nPerson 1: ";
    p1->printAddressAndValue();
    std::cout<<"\nAmount of shared pointers referring to hte same managed object as Person 1: "<<p1.use_count()<<std::endl<<std::endl; 
    
    std::cout<<"Person 3: ";
	p3->printAddressAndValue();
	p3.reset();
    std::cout<<"Person 3 has been reset...\n";
    std::cout<<"Person 3: ";
	if (!p3)
	{   std::cout<<"Empty\n";   }
	
	std::cout<<"\nAmount of shared pointers referring to hte same managed object as Person 1: "<<p1.use_count()<<std::endl<<std::endl; 

	p2.reset();
    std::cout<<"Person 2 has been reset...\n";
    std::cout<<"Person 2: ";
	if (!p2)
	{   std::cout<<"Empty\n";   }
    
    std::cout<<"\nAmount of shared pointers referring to hte same managed object as Person 1: "<<p1.use_count()<<std::endl<<std::endl; 
    
    p1.reset();
    std::cout<<"Person 1 has been reset...\n";
    std::cout<<"Person 1: ";
	if (!p1)
	{   std::cout<<"Empty\n";   }
    std::cout<<"\nAmount of shared pointers referring to the same managed object as Person 1: "<<p1.use_count()<<std::endl<<std::endl; 
	
	p1=std::make_shared<Person>("Lil John Wayne 2.0", 17);
	std::cout<<"Person 1: "<<p1->to_string();	
	
	std::cout<<"\nAmount of shared pointers referring to the same managed object as Person 1: "<<p1.use_count()<<std::endl<<std::endl; 

    std::cout<<"Person 1 was moved to Person 2\n";
    p2=move(p1);
    std::cout<<"Person 1: ";
	if (!p1)
	{   std::cout<<"Empty\n";   }
    std::cout<<"Person 2: "<<p2->to_string();	
	
	
	return 0;
}
