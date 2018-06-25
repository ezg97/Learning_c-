// unique_pointers
#include <iostream>
#include <memory> //for smart pointers
#include <string>

using namespace std;

int serialNo = 1;
class Thing
{
	int instanceNumber;
public:
	Thing()
	{
		instanceNumber = serialNo++;
		cout<<"Thing " << instanceNumber << " created.\n";
	}
	~Thing()
	{
		cout<<"Thing "<<instanceNumber<<" destroyed.\n";
	}
	string to_string()
	{
		return "Thing " + std::to_string(instanceNumber) + ".\n"; //makes number to string and is able to call the correct number bc the smart ptr is an object
	}
};

int main()
{
	unique_ptr<Thing> ezg1(new Thing());	// 1
//	unique_ptr<Thing> ezg2(new Thing());	// 2
	unique_ptr<Thing> ezg2 = make_unique<Thing>(); //c++14 lets you create unique pointers like this!
	
	
	unique_ptr<Thing[]> ezgArr2(new Thing[2]);	// 3, 4
//  unique_ptr<Thing[]> ezgArr2 = make_unique<Thing[]>(2); // c++ 14, suggested bc you can use exceptions by declaring it this way
//  also notice how "new" doesn't need to be declared, it does that all by itself behind the scenes.
	unique_ptr<Thing> ezg5; 				//line 35 and 36 is an alternative way to creating a unique pointer
	ezg5 = unique_ptr<Thing>(new Thing());	//5
	unique_ptr<Thing> ezg6(new Thing());	//6
	
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
	
	return 0;
}
