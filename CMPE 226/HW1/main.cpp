#include "iostream"
#include "LinkedList.h"
#include "string"
using namespace std;

struct RunnerInfo
{
    int distance;
    int running_time;
};
class Runner
{
public:
    Runner(){};
    string name;
    float BART = 9999.0;
    LinkedList<RunnerInfo> ScoreInfo;

    void GetScore(int Number_of_Score)
    {
        RunnerInfo flag;
        float av;
        cout << "Enter " << name << "'s scores \n"
             << "-----------------------\n";
        for (int i = 0; i < Number_of_Score; i++)
        {
            cout << "Run " << i + 1;
            cout << "\nDistance(km):";
            cin >> flag.distance;
            cout << "Running Time(minutes): ";
            cin >> flag.running_time;
            ScoreInfo.insertLast(flag);
            av = float(flag.running_time) / float(flag.distance);
            if (av < BART)
                BART = av;
        }

        cout << "\n---------------------------------------------\n";
    }

    void Print()
    {
        RunnerInfo flag;
        cout << name << "'s Run:\n";
        while (!ScoreInfo.isEmpty())
        {
            flag = ScoreInfo.front();
            ScoreInfo.deleteFirst();
            cout << "Distance(km): " << flag.distance << "          Running Time(minutes): " << flag.running_time << endl;
        };
    }
};
int main()
{

    int size;
    int pr;
    cout << "How many runner information will you enter: ";
    cin >> size;
    Runner info[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Name of the Runner " << i + 1 << ": ";
        cin >> info[i].name;
        cout << "How many previous run does " << info[i].name << " have: ";
        cin >> pr;
        info[i].GetScore(pr);
    }
    for (int i = 0; i < size; i++)
    {
        info[i].Print();
    }
    for (int i = 0; i < size; i++)
    {
        cout << endl
             << info[i].name << "'s best average running time for 1 km: " << info[i].BART << endl;
    }
    system("PAUSE");
    return 0;
}