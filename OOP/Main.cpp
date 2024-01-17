#include<iostream>
#include<string>

class Person {
protected:
	std::string name;
	int age;
public:
	// Конструктор по умолчанию
	Person() {
		name = "noname";
		age = 18;
	}
	//Параметрический конструктор
	Person(std::string name,int age){

		this->name = name;
		this->age = age;

	}
	//Конструктор копирования
	Person(const Person& other) {
		name = other.name;
		age = other.age;
	}
	//Деструктор
	~Person() {
		std::cout << name << " destroed\n";
	}
	void introduce() {
		std::cout << "My name is " << name << std::endl;
	}

	void setName(std::string name) {
		this->name = name;
	}
	std::string getName() {
		return name;
	}
};

class Student : public Person {
private:
	std::string group;
	int grades_number;
	int* grades;
public:
	Student() : Person(){
		group = "undefinded";
		grades = nullptr;
		grades_number = 0;
	}
	Student(std::string name,int age,std::string group,int grades[],int grades_number) : Person(name,age) {
		this->group = group;
		this->grades = new int[grades_number] {};
		for (int i = 0; i < grades_number; i++)
			this->grades[i] = grades[i];
		this->grades_number = grades_number;
	}
	~Student() {
		delete[] grades;
	}
	void printGrades() {
		for (int i = 0; i < grades_number; i++)
			std::cout << grades[i] << ' ';
		std::cout << std::endl;
	}
};





int main(){
	setlocale(LC_ALL, "ru");
	//Создание объекта класса
	Person p1("Bob", 25);
	p1.introduce();

	if (true) {
		Person tmp("Mike", 50);
		tmp.introduce();
	}

	Person p2(p1);
	p2.setName("Tom");
	p2.introduce();
	std::cout << "Имя объекта: " << p2.getName() << std::endl;

	//Работа с классом наследника
	int grades[3]{ 10,12,9 };
	Student s1("Rodion",20,"БВ322",grades,3);
	s1.introduce();
	s1.printGrades();


	return 0;
}