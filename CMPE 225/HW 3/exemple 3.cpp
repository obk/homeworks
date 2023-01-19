
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//exception class for insufficient balance

class InsufficientDeposit
{
};

//class bank account

class BankAccount
{

	//member variables
	int num1 = 0, num2 = 0, num3 = 0;

	int account_id;

	string name;

	float deposit;

protected:
	float interest_rate;

public:
	virtual const void report();

	//constructor

	BankAccount(int a_id, string nm, float dep, float i_rate)
	{

		account_id = a_id;

		name = nm;

		deposit = dep;

		interest_rate = i_rate;
	}
	//save function

	virtual void save()
	{

		ofstream account_file(name + ".dat", ios::out | ios::binary);

		account_file.write((const char *)this, sizeof(BankAccount));
	}

	//load function

	virtual void load(string filename)
	{

		ifstream account_file;

		account_file.open(filename, ios::in | ios::binary);

		account_file.read((char *)this, sizeof(BankAccount));
	}

	//draw function

	float draw(float amount)
	{

		try
		{

			if (amount > deposit)

				throw InsufficientDeposit();

			deposit -= amount;

			return deposit;
		}
		catch (InsufficientDeposit exc)
		{
			cout << "InsufficientDeposit exception catched.";
			cout << "\n";
		}
		catch (const int x)
		{
			cout << "Error no: int";
		}
		catch (const string str1)
		{
			cout << "Error no: str";
		}
		catch (const float y)
		{
			cout << "Error no: float";
		}
		catch (const double z)
		{
			cout << "Error no: double";
		}
	}

	//apply interest function

	void apply_interest()
	{
		deposit *= (1 + interest_rate / 100);
	}
};

//derived class : PersonalBankAccount

class PersonalBankAccount : public BankAccount

{

public:
	PersonalBankAccount(int a_id, string nm, float dep)

		: BankAccount(a_id, nm, dep, 18.0)
	{
	}
};

//derived class : BusinessBankAccount

class BusinessBankAccount : public BankAccount

{

public:
	BusinessBankAccount(int a_id, string nm, float dep)

		: BankAccount(a_id, nm, dep, 6.5)

	{
	}
};

//creating report function

const void BankAccount::report()

{

	if (PersonalBankAccount *child = dynamic_cast<PersonalBankAccount *>(this))
	{
		cout << "\n";
		cout << "TYPE: PERSONAL";
		cout << "\n";
	}

	else if (BusinessBankAccount *child = dynamic_cast<BusinessBankAccount *>(this))
	{
		cout << "\n";
		cout << "TYPE: BUSINESS";
		cout << "\n";
	}

	cout << "===============================";
	cout << "\n";

	cout << "Account ID: " << account_id;
	cout << "\n";

	cout << "Account Name: " << name;
	cout << "\n";

	cout << "Deposit: " << deposit;
	cout << "\n";

	cout << "Interest Rate: " << interest_rate << "%";
	cout << "\n";

	cout << "===============================";
	cout << "\n";
}

int main()
{
	cout << "HW3";
	cout << "\n";
	cout << "Omer Bahadir Kundak";
	cout << "\n";
	cout << "17243510020";
	cout << "\n";
	int y = 0;

	//swapping personal accounts

	PersonalBankAccount a1 = PersonalBankAccount(5421, "PersonalAcc1", 8000.0);

	PersonalBankAccount a2 = PersonalBankAccount(1234, "PersonalAcc2", 5856.0);

	cout << "\n";
	cout << "=============================";
	cout << "Before swapping accounts";
	cout << "========================== ";
	cout << "\n";

	a1.report();

	a2.report();

	a1.save();

	a2.save();

	a1.load("PersonalAcc2.dat");

	a2.load("PersonalAcc1.dat");

	cout << "\n";
	cout << "=============================";
	cout << "After swapping accounts";
	cout << "========================== ";
	cout << "\n";

	a1.report();

	a2.report();

	//business account

	BusinessBankAccount ba = BusinessBankAccount(5555, "BusinessAcc", 70000.0);

	ba.draw(70000.1);

	ba.report();

	for (int x = 0; x < 10; x++)
	{
		x++;
	}
	for (int i = 0; i < 10; i++)
	{
		i++;
	}
	do
	{
		y++;
	} while (y < 10);
}
