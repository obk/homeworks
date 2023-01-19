#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

class MathProblem
{
public:
    bool isanswercorrect = false;
    virtual void setproblem() {}       // Number generator
    virtual void askuserforanswer() {} // Input + Check
    virtual void displayproblem() {}   // Output
};

class IntegerProblem : public MathProblem
{

public:
    int n1, n2, ca, ua;

    void setproblem()
    {
        n1 = rand() % 100; // Random Number
        n2 = rand() % 100; // Random Number
        ca = n1 + n2;      // Correct Answer
    }

    void askuserforanswer()
    {
        cout << "\nEnter answer:";
        cin >> ua; // User's input
        if (ua == ca)
        {
            isanswercorrect = true; // Correct
            cout << "Good Job!";
        }
        else
        {
            cout << "Sorry! The correct answer is " << ca;
            isanswercorrect = false; // Wrong
        }
    }

    void displayproblem()
    {
        cout << "Question is: " << n1 << " + " << n2 << " =?"; // Output Question
    }
};

class FractionProblem : public MathProblem
{ // I took the all functitions for this class from StackOverflow

public:
    int n1, n2, d1, d2, cn, cd, un, ud;

    void setproblem()
    { // Random Number for Numerators and Denominators
        n1 = rand() % 10;
        d1 = rand() % 10;
        n2 = rand() % 10;
        d2 = rand() % 10;
        cn = n1 * d2 + n2 * d1;
        cd = d1 * d2;
    }

    void askuserforanswer()
    {
        string str1;
        string str2;
        cout << "\nEnter answer:";
        cin >> str1;                                // User's answer as a string
        str2 = to_string(cn) + "/" + to_string(cd); // Convert the correct answer to string type

        if (str1 == str2)
        { // For Correct Answer
            isanswercorrect = true;
            cout << "Good Job!";
        }
        else
        { // For Wrong Answer
            isanswercorrect = false;
            cout << "Sorry! The correct answer is " << str2;
        }
    }
    void displayproblem()
    {
        cout << "Question is: " << n1 << "/" << d1 << " + " << n2 << "/" << d2 << " =?";
    }
};

int main()
{

    MathProblem mp;
    IntegerProblem ip;
    FractionProblem fp;

    int choice = 0;
    while (choice != 3)
    {

        cout << "\n \nPlease choose type of addition problem:\n1. Fraction\n2. Integer\n3. Quit";
        cout << "\nChoice:";
        cin >> choice; // Input for Question type

        if (choice == 1)
        {
            fp.setproblem();
            fp.displayproblem();
            fp.askuserforanswer();
        }

        if (choice == 2)
        {
            ip.setproblem();
            ip.displayproblem();
            ip.askuserforanswer();
        }

        if (choice == 3)
        {
            cout << "\nGood Bye!";
            break; // Quit
        }

        if (choice != 1 && choice != 2 && choice != 3)
        { // For integers but 1, 2 or 3
            cout << "\nInvalid choice";
            cout << "\n Please input only 1, 2 or 3";
        }
    }
    return 0;
}