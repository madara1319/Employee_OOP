#include <iostream>

using std::string;

class Employee {
	public:
		string Name;
		string Company;
		int Age;

	void IntroduceYourself()
	{
		std::cout<< "Name - " << Name << std::endl;
		std::cout<< "Company- " << Company << std::endl;
		std::cout<< "Age - " << Age << std::endl;
		
	}
};

int main()

{
	Employee employee1;
	employee1.Name = "Mateusz";
	employee1.Company = "NA-Engineering";
	employee1.Age = 26;
	employee1.IntroduceYourself();
}



