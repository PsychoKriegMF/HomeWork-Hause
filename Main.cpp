#include <iostream>
#include <string>
#include <vector>

class human 
{
public:
	std::string name;
	int age;
	human() {};
	~human() {};
};

class apartment
{
public:
	apartment() {};
	~apartment() {};
	int number;
	int number_room;

	void add_human(std::string name_, int age_) 
	{
		human* new_human = new human;
		new_human->name = name_;
		new_human->age = age_;
		obj_human.push_back(new_human);
	}
	void print_parametrs_apartment()
	{
		std::cout << "Квартира с номером " << number << " имеет комнат: " << number_room << std::endl;
	}
	void print_apartment()
	{
		std::cout << "Проживают: \n";
		for (int i = 0; i < obj_human.size(); i++)
		{
			std::cout << "Имя: " << obj_human[i]->name << "\nВозраст: " << obj_human[i]->age << std::endl;
		}
		std::cout << std::endl;
	}
private:
	std::vector<human*>obj_human;
};

class house 
{
	int number_house;
	int quantity_apartment;
public:
	house(int num_house) 
	{
		number_house = num_house;
	}
	~house() {};
	void add_apartment(int number_, int number_room_)
	{
		apartment* new_apartment = new apartment;
		new_apartment->number = number_;
		new_apartment->number_room = number_room_;
		obj_apartment.push_back(new_apartment);
		quantity_apartment++;
	}
	void print_num_house()
	{
		std::cout << "Номер дома: " << number_house << " Количество квартир: " << quantity_apartment << std::endl;
	}
	void print_house()
	{
		for (int i = 0; i < obj_apartment.size(); i++)
		{
			std::cout << "Номер квартиры: " << obj_apartment[i]->number << " Количество комнат: " << obj_apartment[i]->number_room << std::endl;
		}
		std::cout << std::endl;
	}
private:
	std::vector<apartment*>obj_apartment;
};

int main() {
	setlocale(LC_ALL, "ru");
	
	house house_1(12);
	apartment apartment_1;
	apartment_1.number = 179;
	apartment_1.number_room = 3;
	apartment apartment_2;
	apartment_2.number = 203;
	apartment_2.number_room = 3;

	house_1.add_apartment(179, 3);
	house_1.add_apartment(203, 3);

	house_1.print_num_house();
	house_1.print_house();

	apartment_1.print_parametrs_apartment();
	apartment_1.add_human("Михаил", 29);
	apartment_1.add_human("Ксения", 27);
	apartment_1.print_apartment();

	apartment_2.print_parametrs_apartment();
	apartment_2.add_human("Алексей", 29);
	apartment_2.add_human("Снежана", 29);
	apartment_2.add_human("Вера", 2);
	apartment_2.print_apartment();
	



	return 0;
}