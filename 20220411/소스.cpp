#include <iostream>
#include <string>


class Employee {
	std::string name;
	int age;

	std::string position;
	int rank;

	public:
		Employee(std::string name, int age, std::string position, int rank) :name(name), age(age), position(position), rank(rank) {}


		Employee(const Employee& employee) {
			name = employee.name;
			age = employee.age;
			position = employee.position;
			rank = employee.rank;
		}

		Employee() {}

		void print_info() {
			std::cout << name << "( " << position << " , " << age << " ) ==> " << calculate_pay() << " won" << std::endl;
		}

		int calculate_pay() {
			return 200 + rank * 50;
		}
};

class Employeelist {
	int alloc_employee;
	int current_employee;

	Employee** employee_list;

public:
	Employeelist(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num() {
		return current_employee;
	}

	void print_employee_info() {
		int total_pay = 0;

		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		std::cout << "total pay: " << total_pay << " won " << std::endl;

	}

	~Employeelist() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];

		}
		delete[] employee_list;
	}

};

int main() {
	Employeelist emp_list(10);

	emp_list.add_employee(new Employee("��", 34, "����", 1));
	emp_list.add_employee(new Employee("��", 34, "����", 1));

	emp_list.add_employee(new Employee("��", 41, "����", 7));
	emp_list.add_employee(new Employee("��", 43, "����", 4));
	emp_list.add_employee(new Employee("��", 43, "����", 5));

	emp_list.add_employee(new Employee("��", 36, "�븮", 2));
	emp_list.add_employee(new Employee("��", 36, "����", -2));
	
	emp_list.print_employee_info();

	return 0;
}