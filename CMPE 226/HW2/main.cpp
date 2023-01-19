#include <iostream>

#include "LStack.h"

#include <string>

void split(string str)
{
  int i;
  bool firstdot = false;
  int firstdotloc, secdotloc;
  bool secdot = false;
  for (i = 0; i < str.length(); i++)
  {
    if ((str[i] == '.') && (!firstdot))
    {
      firstdot = true;
      firstdotloc = i;
    }
    else if ((str[i] == '.') && (firstdot))
    {
      secdot = true;
      secdotloc = i;
    }
    else
    {
      continue;
    }
  }

  for (i = firstdotloc + 1; i <= secdotloc - 1; i++)
  {
    cout << str[i];
  }
  if (!firstdot || !secdot)
  {
    cout << "[url parse error]";
    cout << str << endl;
  }
}
void visit_new_webpage(Stack<string> &history)
{
  string address;
  cout << "Enter the new page's address: ";
  cin >> address;
  cout << "You are currently visiting ";
  split(address);
  cout << ".\n";
  history.push(address);
}

void go_back_one_page(Stack<string> &forward, Stack<string> &history)
{
  string page_address;
  if (history.size() <= 1)
  {
    cout << "there is no backward page\n";
  }
  else
  {
    page_address = history.pop();
    forward.push(page_address);
    cout << "You are currently visiting ";
    split(history.peek());
    cout << "\n";
  }
}

void go_forward_one_page(Stack<string> &forward, Stack<string> &history)
{
  string page_address;
  if (forward.size() < 1)
  {
    cout << "Error! There is no Forward page.\n";
  }
  else
  {
    cout << "You have gone to the Forward page.\n";
    page_address = forward.pop();
    history.push(page_address);
    cout << "You are currently visiting ";
    split(page_address);
    cout << ".\n";
  }
}

int main()
{

  Stack<string> history;
  Stack<string> forward;
  string current_address;
  char flag;
  int ct = 0;
  do
  {
    cout << "Choose(N)ew page, go(B)ack one page, go(F)orward one page(Q)uit: ";
    cin >> flag;
    if (flag == 'N' || flag == 'n')
    {
      visit_new_webpage(history);
    }
    if (flag == 'B' || flag == 'b')
    {
      go_back_one_page(forward, history);
    }
    if (flag == 'F' || flag == 'f')
    {
      go_forward_one_page(forward, history);
    }
    if (flag == 'q' || flag == 'Q')
    {
      break;
    }
  } while (true);
  cout << "\n\tThank you for using this simple browser. Have a nice day.\n";
  system("PAUSE");
  return (0);
}