#include<iostream>
#define MAX 50
using namespace std;

class DronePriority
{
private:
	int DroneArray[MAX];
	int top;

public:
	DronePriority()
	{
		top = -1;
	}

	bool isEmpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == MAX - 1;
	}
	void push(int x)
	{
		if (isFull())
		{
			cout << "Stack is Full can not add more drones in it." << endl;
			return;
		}
		DroneArray[++top] = x;
		for (int i = 0; i <= top; i++)
		{
			for (int j = i + 1; j <= top; j++)
			{
				if (DroneArray[i] < DroneArray[j])
				{
					int temp = DroneArray[i];
					DroneArray[i] = DroneArray[j];
					DroneArray[j] = temp;
				}
			}
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "No Drones to Send" << endl;
			return -1;
		}
		int highest = DroneArray[0];
		for (int i = 0; i < top; i++)
		{
			DroneArray[i] = DroneArray[i + 1];
		}
		top--;
		return highest;
	}
	void display()
	{
		if (isEmpty())
		{
			cout << "No Drones" << endl;
			return;
		}
		cout << "Drones:";
		for (int i =0;i<=top;i++)
		{
			cout << DroneArray[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	DronePriority stk;
	stk.push(1);
	stk.push(4);
	stk.push(3);
	stk.push(2);
	stk.push(5);

	stk.display();
	cout << "Send drone with priority: " << stk.pop() << endl;
	cout << "Send drone with priority: " << stk.pop() << endl;
	cout << "Send drone with priority: " << stk.pop() << endl;
	stk.display();

	return 0;
}


