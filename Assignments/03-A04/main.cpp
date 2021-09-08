/*****************************************************************************
*                    
*  Author:           Aayush Bhurtel
*  Email:            abhurtel1118@my.msutexas.edu
*  Label:            03-A04
*  Title:            Commenting Code
*  Course:           OOP 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This is a program where Circular Queue data structure is implemented.
*        CircularArrayQue is a class which allows a list of node to be pushed or poped 
*        using an array.
* 
*  Usage:
*        - Fork this repo 
*        - ./main filename
*        - use above command in terminal to run
* 
*  Files:            main.cpp
*****************************************************************************/
#include <iostream>

using namespace std;

/*
*    Class Name: CircularArrayQue
*
*    Description:
*        This class impliments Queue data structure which can push and pop items from the Queue.
*        
*    Public Methods:
*                       CircularArrayQue() 
*                       CircularArrayQue(int size)  
*        void           Push(int item) 
*        int            Pop()
*        ostream        &operator<<(ostream &os,const CircularArrayQue &other)
*
*    Private Methods:
*        void           _init(int size = 0) 
*        bool           _Full()
*
*    Usage:
*        - Create a class object
*        - insert or delete nodes from the Queue
*
*/
class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
/**
 * Private :  void init
 *
 * Description:
 *            - initialize front, rear, current size to 0
 *            - initialize QueSize to 0 
 *
 * Params:
 *          - int size = 0
 *
 * 
 * Returns:
 *          - NULL
 */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

/**
 * Private :  bool Full
 *
 * Description:
 *            - If the Queue is full then assign a QueSize to CurrtentSize
 *
 * Params:
 *          - NULL
 *
 * 
 * Returns:
 *          - bool currentSize
 */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
/**
 * Public :  CircularArrayQue
 *
 * Description:
 *            This is a Default Constructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
/**
 * Public :  CircularArrayQue
 *
 * Description:
 *            Parameterizes contructor
 *
 * Params:
 *          - int size
 *
 * Returns:
 *          - NULL
 */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
/**
 * Public :  Push
 *
 * Description:
 *            This function inserts a node into the Queue and if its full, displays FULL.
 *
 * Params:
 *          - int item
 *
 * Returns:
 *          - NULL
 */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
/**
 * Public :  Pop
 *
 * Description:
 *           This function deletes the node from the Queue.
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - int temp
 */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
 * Public : ostream
 * 
 * Description:
 *      overloading the cout operator to print an object
 * 
 * Params:
 *      - ostream &os, const CircularArrayQue &other
 * 
 * Returns:
 *      string os
 */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
