﻿#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
	string firstname;
	string lastname;
	string surname;
	int day;
	int month;
	int year;

public:
	Human()
	{
		firstname = "None";
		lastname = "None";
		surname = "None";
		day = -1;
		month = -1;
		year = -1;
	}
	Human(string firstname, string lastname, string surname, int day, int month, int year)
	{
		this->firstname = firstname;
		this->lastname = lastname;
		this->surname = surname;
		this->day = day;
		this->month = month;
		this->year = year;
	}
	Human(Human& old_human)
	{
		firstname = old_human.firstname;
		lastname = old_human.lastname;
		surname = old_human.surname;
		day = old_human.day;
		month = old_human.month;
		year = old_human.year;
	}

	void Show_Human()
	{
		cout << "Firstname = " << firstname << endl;
		cout << "Lastname = " << lastname << endl;
		cout << "Surname = " << surname << endl;
		cout << "Day = " << day << endl;
		cout << "Month = " << month << endl;
		cout << "Year = " << year << endl;
	}

	string Get_Firstname()
	{
		return firstname;
	}

	string Get_Lastname()
	{
		return lastname;
	}

	string Get_Surname()
	{
		return surname;
	}

	int Get_Day()
	{
		return day;
	}

	int Get_Month()
	{
		return month;
	}

	int Get_Year()
	{
		return year;
	}

	void Set_Firstname()
	{
		cout << "Enter firstname:\n";
		cin >> firstname;
	}

	void Set_Lastname()
	{
		cout << "Enter lastname:\n";
		cin >> lastname;
	}

	void Set_Surtname()
	{
		cout << "Enter surname:\n";
		cin >> surname;
	}

	void Set_Day()
	{
		cout << "Enter day:\n";
		cin >> day;
	}

	void Set_Month()
	{
		cout << "Enter month:\n";
		cin >> month;
	}

	void Set_Year()
	{
		cout << "Enter year:\n";
		cin >> year;
	}

	void Add_Person()
	{
		void(Human:: * p_methon[6])() = { &Human::Set_Firstname, &Human::Set_Lastname,  &Human::Set_Surtname, &Human::Set_Day, &Human::Set_Month, &Human::Set_Year };
		for (int i = 0; i < 6; i++)
		{
			(this->*p_methon[i])();
		}
	}
};

class Apartment
{
private:
	Human* people;
	int number_apartament;
	int floor;
	int counter_people;

public:
	Apartment()
	{
		people = nullptr;
		int number_apartament = -1;
		int floor = -1;
		int counter_people = -1;
	}
	Apartment(Human* people, int number_apartament, int floor, int counter_people)
	{
		if (people != nullptr)
		{
			this->people = new Human[counter_people];
			for (int i = 0; i < counter_people; i++)
			{
				this->people[i] = people[i];
			}
		}
		else
		{
			this->people = nullptr;
		}

		this->number_apartament = number_apartament;
		this->floor = floor;
		this->counter_people = counter_people;
	}
	Apartment(Apartment& old_apartment)
	{
		number_apartament = old_apartment.number_apartament;
		floor = old_apartment.floor;
		counter_people = old_apartment.counter_people;
		if (old_apartment.people != nullptr)
		{
			people = new Human[old_apartment.counter_people];
			for (int i = 0; i < counter_people; i++)
			{
				people[i] = old_apartment.people[i];
			}
		}
		else
		{
			people = nullptr;
		}

	}
	~Apartment()
	{
		if (people != nullptr)
		{
			delete[] people;
		}
	}

	void Show_Apartment()
	{
		for (int i = 0; i < counter_people; i++)
		{
			cout << "Human " << i + 1 << ":\n";
			people[i].Show_Human();
		}

		cout << "Number apartament = " << number_apartament << endl;
		cout << "Floor = " << floor << endl;
		cout << "Counter people = " << counter_people << endl;
	}

	Human* Get_People()
	{
		return people;
	}

	int Get_Number_Apartament()
	{
		return number_apartament;
	}

	int Floor()
	{
		return floor;
	}

	int Get_Counter_People()
	{
		return counter_people;
	}

	void Set_People()
	{
		int counter_user;
		cout << "Enter how many people in apartment:\n";
		cin >> counter_user;

		people = new Human[counter_user];
		for (int i = 0; i < counter_user; i++)
		{
			people[i].Add_Person();
		}
	}

	void Set_Number_Apartament()
	{
		cout << "Enter number apartament:\n";
		cin >> number_apartament;
	}

	void Set_Floor()
	{
		cout << "Enter floor:\n";
		cin >> floor;
	}

	void Set_Counter_People()
	{
		cout << "Enter how many people in apartment:\n";
		cin >> counter_people;
	}

	void Add_Apartment()
	{
		Set_People();
		Set_Number_Apartament();
		Set_Floor();
		Set_Counter_People();
	}
};

class House
{
private:
	Apartment* apartments;
	int number_house;
	int counter_apartments;
	string street;

public:
	House()
	{
		apartments = nullptr;
		number_house = -1;
		counter_apartments = -1;
		street = "None";
	}
	House(Apartment* apartments, int number_house, int counter_apartments, string street)
	{
		if (apartments != nullptr)
		{
			this->apartments = new Apartment[counter_apartments];
			for (size_t i = 0; i < counter_apartments; i++)
			{
				this->apartments[i] = apartments[i];
			}
		}
		else
		{
			this->apartments = nullptr;
		}

		this->number_house = number_house;
		this->counter_apartments = counter_apartments;
		this->street = street;
	}

	House(House& old_house)
	{
		if (old_house.apartments != nullptr)
		{
			this->apartments = new Apartment[old_house.counter_apartments];
			for (size_t i = 0; i < counter_apartments; i++)
			{
				this->apartments[i] = old_house.apartments[i];
			}
		}
		else
		{
			this->apartments = nullptr;
		}

		this->number_house = old_house.number_house;
		this->counter_apartments = old_house.counter_apartments;
		this->street = old_house.street;
	}

	~House()
	{
		if (apartments != nullptr)
		{
			delete[] apartments;
		}
	}

	void Show_House()
	{
		for (size_t i = 0; i < counter_apartments; i++)
		{
			cout << "Apartment " << i + 1 << ":\n";
			apartments[i].Show_Apartment();
		}

		cout << "Number house = " << number_house << endl;
		cout << "Counter apartments = " << counter_apartments << endl;
		cout << "Street = " << street << endl;
	}


	Apartment* Get_Apartment()
	{
		return apartments;
	}

	int Get_Number_House()
	{
		return number_house;
	}

	int Get_Counter_Apartments()
	{
		return counter_apartments;
	}

	string Get_Street()
	{
		return street;
	}

	void Set_Apartment()
	{
		int counter_user;
		cout << "Enter how many apartments in house:\n";
		cin >> counter_user;

		apartments = new Apartment[counter_user];
		for (int i = 0; i < counter_user; i++)
		{
			apartments[i].Add_Apartment();
		}
	}

	void Set_Number_House()
	{
		cout << "Enter number house:\n";
		cin >> number_house;
	}

	void Set_Counter_Apartments()
	{
		cout << "Enter how many apartments in house:\n";
		cin >> counter_apartments;
	}

	void Set_Street()
	{
		cout << "Enter street:\n";
		cin >> street;
	}

	void Add_House()
	{
		/*Set_Apartment();*/
		Set_Number_House();
		Set_Counter_Apartments();
		Set_Street();
	}
};

int main()
{
	//Human person("FDSfs", "DFSDAF", "sfsdf", 123,123,123);
	////person.Add_Person();
	//person.Show_Human();
	//Human person_1 = person;
	//person.Show_Human();

	/*Human person[3];
	for (int i = 0; i < 3; i++)
	{
		person[i].Show_Human();
	}

	Apartment apartment_human(person, 10, 4, 3);

	Apartment apartment_human_1 = apartment_human;

	apartment_human_1.Show_Apartment();

	apartment_human_1.Add_Apartment()
	apartment_human_1.Show_Apartment();*/

	Apartment apartment[3];

	House houses(apartment, 12, 3, "Hopa");
	House houses_1 = houses;
	houses_1.Show_House();
	houses_1.Add_House();
	houses_1.Show_House();

	return 0;
}