#include <iostream>
#include<string>
using namespace std;

class Buffer
{
private:
    string* currentBuffer;
    int currentCapacity;
    int currentSize;
    
    string* oldBuffer;
    int oldSize;
    int oldCap;

    void ResizeCurrentBuffer()
    {
        int newCap = currentCapacity * 2;
        string* newbuffer = new string[newCap];
        for (int i = 0; i < currentSize; i++)
        {
            newbuffer[i] = currentBuffer[i];
        }
        delete[] currentBuffer;
        currentBuffer = newbuffer;
        currentCapacity = newCap;
    }
    void ResizeOldBuffer()
    {
        int newCap = oldCap * 2;
        string* newDiscard = new string[newCap];
        for (int i = 0; i < oldSize; i++)
        {
            newDiscard[i] = oldBuffer[i];
        }
        delete[] oldBuffer;
        oldBuffer = newDiscard;
        oldCap = newCap;
    }
    void ShiftBufferCommands()
    {
        if (oldSize == oldCap)
        {
            ResizeOldBuffer();
        }
        oldBuffer[oldSize++] = currentBuffer[0];
        for (int i = 1; i < currentSize; i++)
        {
            currentBuffer[i - 1] = currentBuffer[i];
        }
        currentSize--;
    }
public:
    Buffer() 
    {
        currentCapacity = 4;
        currentSize = 0;
        currentBuffer = new string[currentCapacity];

        oldCap = 10;
        oldSize = 0;
        oldBuffer = new string[oldCap];
    }
    ~Buffer() 
    {
        delete[] currentBuffer;
        delete[] oldBuffer;
    }
    void addNewCommand(const string& command) 
    {
        if (currentSize == 10)
        {
            ShiftBufferCommands();
        }
        if (currentSize == currentCapacity)
        {
            ResizeCurrentBuffer();
        }
        currentBuffer[currentSize++] = command;
    }
    void printOldBuffer() 
    {
        cout << "Old Commands in Buffer:" << endl;
        for (int i = 0; i < oldSize; i++)
        {
           
            cout << oldBuffer[i] << endl;
        }
        cout << "<<----------------------------------------------------------------------->>" << endl;
    }
    void printCurrent()
    {
        cout << "Current 10 Commands in Buffer:" << endl;
        for (int i = 0; i < currentSize; i++) 
        {

            cout << currentBuffer[i] << endl;
        }
    }
};
int main() 
{
    Buffer robot;
    robot.addNewCommand("JUMP");
    robot.addNewCommand("DRIVE");
    robot.addNewCommand("MOVE 45");
    robot.addNewCommand("TURN LEFT");
    robot.addNewCommand("MOVE 90");
    robot.addNewCommand("GO STRAIGHT");
    robot.addNewCommand("STOP");
    robot.addNewCommand("TURN AROUND");
    robot.addNewCommand("DANCE");
    robot.addNewCommand("SAY HELLO!");
    robot.addNewCommand("MOVE 45");
    robot.addNewCommand("TURN RIGHT");
    robot.addNewCommand("SIT");
    robot.addNewCommand("STAND");
    robot.addNewCommand("RUN");
    robot.addNewCommand("ROLL");
    robot.addNewCommand("CLIMB");
    robot.addNewCommand("MOVE 180");
    robot.addNewCommand("LAY DOWN");
    robot.addNewCommand("PLAY");

    robot.printOldBuffer();
    robot.printCurrent();

    return 0;
}   