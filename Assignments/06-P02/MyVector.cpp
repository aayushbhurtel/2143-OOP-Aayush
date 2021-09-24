/*****************************************************************************
*                    
*  Author:           Aayush Bhurtel
*  Email:            aayushbhurtel@gmail.com
*  Label:            06-P02
*  Title:            Robust MyVector class
*  Course:           2143 OOP
*  Semester:         Fall 2021
* 
*  Description:
*        Uses a singly linked list as the backend for an STL like "vector" 
*        class definition.
* 
*  Usage:
*        - move to file directory
*        - g++ main.cpp              (compile c++ source file)
*        - ./main                    (run compiled file)
* 
*  Files: 
*       - MyVector.cpp
*       - output.txt
*****************************************************************************/
#include <fstream>
#include <iostream>
#include <string>

#define INF 1000000000 // infinity

using namespace std;

/**
 * Node
 * 
 * Description:
 *      This class creates a Node which holds the data and its next pointer in the Singly-Linked-List.
 * 
 * Public Methods:
 *      - Node(int)
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 *      
 */
struct Node
{
    int data;

    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/**
 * MyVector
 * 
 * Description:
 *      This MyVector class creates a new singly-linked-list with user input values in a node or an array. 
 *      User is also able to perform addition, substraction, multiplication, division with multiple linked
 *      lists. Operator Overloading is implemented so any object could be manipulated to modify a lined list.
 * 
 * Public Methods:
 *      -               MyVector()    
 *      -               MyVector(int[], int)
 *      -               MyVector(const classObject&)
 *      -               Myvector(string File)
 *      - void          init()   
 *      - void          inorderPush(int)    
 *      - void          sortList()
 *      - void          pushFront(int)
 *      - void          pushFront(const classObject&)
 *      - void          pushRear(const classObject&)
 *      - void          pushRear(int)
 *      - void          pushAt(int, int)
 *      - int           listSize(class Node* head)
 *      - ostream       operator<<(ostream, classObject&)
 *      - ofstream      operator<<(ofstream, classObject&)
 *      - classobject   operator+(const classObject&)
 *      - classobject   operator-(const classObject&)
 *      - classobject   operator/(const classObject&)
 *      - classobject   operator*(const classObject&)
 *      - classobject   operator=(const classObject&)
 *      - bool          operator==(const classObject&)
 *      - int           operator[](const int)
 * 
 * Private Methods:
 *      - _inorderPush(int)
 * 
 * Usage: 
 *      - MyVector v1; 
 */
class MyVector
{
private:
    Node *head; // base pointer of list
    Node *tail; // tail pointer of list
    int size;
    static ofstream fout;
    string fileName;
    bool sorted;

    /**
     * private : _inorderPush
     * 
     * Description:
     *      Push a linkedList node in the correct order
     * 
     * Params:
     *      int     :  data to add
     * 
     * Returns:
     *      None
     */
    void _inorderPush(int x)
    {
        Node *tempPtr = new Node(x); // allocate new node
        Node *prev = head;           // get previous and next pointers
        Node *curr = head;

        while (curr->data > x)
        { // loop to find proper location
            prev = curr;
            curr = curr->next;
        }

        tempPtr->next = prev->next; // add new node in its proper position
        prev->next = tempPtr;

        size++; // add to size :)
    }

public:
    /**
     * Public : MyVector
     * 
     * Description:
     *      default constructor with initializes all variables
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      none
     */
    MyVector()
    {
        init();
    }

    /**
     * Public : MyVector
     * 
     * Description:
     *      Overloaded Constructor to push an array into a linked list
     * 
     * Params:
     *      int*    :  array of integers
     *      int     :  array size
     * 
     * Returns:
     *      None
     */
    MyVector(int A[], int aSize)
    {
        init();
        for (int i = 0; i < aSize; i++)
        {
            pushRear(A[i]);
        }
    }

    /**
     * Public : MyVector
     * 
     * Description:
     *      overloaded constructor to push an entire file into a linked list
     * 
     * Params:
     *      string  :  filename
     * 
     * Returns:
     *      None
     */
    MyVector(string FileName)
    {
        init();

        ifstream fin;
        int x = 0;

        fin.open(FileName);
        while (!fin.eof())
        {
            fin >> x;
            pushRear(x);
        }
    }

    /**
     * Public : Myvector
     * 
     * Description:
     *      Overloaded constructor to add another linked list to rear of an existing linked list
     * 
     * Params:
     *      const Class   :  object  
     * 
     * Returns:
     *      None
     */
    MyVector(const MyVector &other)
    {
        init();

        Node *temp = other.head;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    /**
     * Public : init
     * 
     * Description:
     *      initializes class variables to avoid code repeatation on every constructor
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
    void init()
    {
        head = tail = NULL;
        fileName = "";
        size = 0;
        sorted = 0;
    }

    /**
     * Public : inorderPush
     * 
     * Description:
     *      Pushes a given data into a sorted list at correct order
     * 
     * Params:
     *      int     :  data
     * 
     * Returns:
     *     None
     */
    void inorderPush(int x)
    {
        if (!sorted)
        {
            sortList();
        }

        if (!head)
        {
            pushFront(x); // call push front for empty list (or pushRear would work)
        }
        else if (x < head->data)
        {
            pushFront(x); // call push front if x is less than head
        }
        else if (x > tail->data)
        {
            pushRear(x); // call push rear if x > tail
        }
        else
        {
            _inorderPush(x); // call private version of push in order
        }
    }

    /**
     * Public : sortList
     * 
     * Description:
     *      Sort the current values in the linked list.
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      None
     */
    void sortList()
    {
        Node *newFront = head;
        while (newFront->next)
        {
            Node *smallest = newFront;
            Node *current = newFront;
            int minimum = INF;
            while (current)
            {
                if (current->data < minimum)
                {
                    smallest = current;
                    minimum = current->data;
                }
                current = current->next;
            }
            smallest->data = newFront->data;
            newFront->data = minimum;
            newFront = newFront->next;
        }
        sorted = true;
    }

    /**
     * Public : pushFront
     * 
     * Description:
     *       Add value to front of list.
     * 
     * Params:
     *      int     :  data
     * 
     * Returns:
     *      None
     */
    void pushFront(int x)
    {
        Node *tempPtr = new Node(x);

        // empty list make head and tail
        // point to new value
        if (!head)
        {
            head = tail = tempPtr;
            // otherwise adjust head pointer
        }
        else
        {
            tempPtr->next = head;
            head = tempPtr;
        }
        size++;
    }

    /**
     * Public : pushFront
     * 
     * Description:
     *       This method loads values from 'other' list in 'this' list.
     *       It loads an array first so we can process the values in
     *       reverse so they end up on 'this' list in the proper order.
     *       If we didn't use the array, we would reverse the values
     *       from the 'other' list.
     * 
     * Params:
     *      const Class    :  other
     * 
     * Returns:
     *      None
     */
    void pushFront(const MyVector &other)
    {
        Node *otherPtr = other.head;         // get copy of other lists head
        int *tempData = new int[other.size]; // allocate memory to hold values

        // load other list into array
        int i = 0;
        while (otherPtr)
        {
            tempData[i] = otherPtr->data;
            otherPtr = otherPtr->next;
            ++i;
        }

        // process list in reverse in order to keep them
        // in their original order.
        for (int i = other.size - 1; i >= 0; i--)
        {
            pushFront(tempData[i]);
        }
    }

    /**
     * Public : pushRear
     * 
     * Description:
     *       Add 'other' list's values to end of 'this' list.
     * 
     * Params:
     *      const Class   :  other
     * 
     * Returns:
     *      None
     */
    void pushRear(const MyVector &other)
    {
        Node *otherPtr = other.head; // get copy of other lists head

        while (otherPtr)
        { // traverse and add
            pushRear(otherPtr->data);
            otherPtr = otherPtr->next;
        }
    }

    /**
     * Public : pushAt
     * 
     * Description:
     *       Push value onto list at soecified position, if it exists.
     * 
     * Params:
     *      int   :  index
     *      int   :  value 
     * 
     * Returns:
     *      bool
     */
    bool pushAt(int i, int x)
    {
        if (i >= size)
        {
            return false;
        }

        Node *tempPtr = new Node(x); // allocate new node
        Node *prev = head;           // get previous and next pointers
        Node *curr = head;

        while (i > 0)
        { // loop to find proper location
            prev = curr;
            curr = curr->next;
            i--;
        }

        tempPtr->next = prev->next; // add new node in its proper position
        prev->next = tempPtr;

        size++; // add to size :)
        return true;
    }

    /**
     * @brief - Add value to rear of list
     * 
     * @param int x - value to be added 
     * @return None
     */

    /**
     * Public : pushRear
     * 
     * Description:
     *       Add value to rear of list
     * 
     * Params:
     *      int   :  value 
     * 
     * Returns:
     *      none
     */
    void pushRear(int x)
    {
        Node *tempPtr = new Node(x);
        if (!head)
        {
            head = tail = tempPtr;
        }
        else
        {
            tail->next = tempPtr;
            tail = tempPtr;
        }
        size++; // add to size of list
    }

    /**
     * Public : listSize
     * 
     * Description:
     *       Calculates the size of a liked list using recursion
     * 
     * Params:
     *      Node*   :  head 
     * 
     * Returns:
     *      int
     */
    int listSize(class Node *head)
    {
        if (head == NULL)

            return 0;

        return 1 + listSize(head->next);
    }

    /**
     * Public : operator<<
     * 
     * Description:
     *       Overloads << operator to print user created objects into console
     * 
     * Params:
     *      ostream     :   os
     *      const class :   rhs
     * 
     * Returns:
     *      ostream
     */
    friend ostream &operator<<(ostream &os, const MyVector &rhs)
    {
        Node *temp = rhs.head; // temp pointer copies head
        os << "[";
        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            os << temp->data; // print data from Node
            if (temp->next)
            {
                os << ", ";
            }
            temp = temp->next; // move to next Node
        }

        os << "]";
        return os;
    }

    /**
     * Public : operator<<
     * 
     * Description:
     *       Overloads << operator to print user created objects into external file
     * 
     * Params:
     *      ostream     :   os
     *      const class :   rhs
     * 
     * Returns:
     *      ostream
     */
    friend ofstream &operator<<(ofstream &os, const MyVector &rhs)
    {
        Node *temp = rhs.head; // temp pointer copies head
        os << "[";
        while (temp)
        { // this loops until temp is NULL
            // same as `while(temp != NULL)`

            os << temp->data; // print data from Node
            if (temp->next)
            {
                os << ", ";
            }
            temp = temp->next; // move to next Node
        }

        os << "]";
        return os;
    }

    /**
     * Public : operator+
     * 
     * Description:
     *       Overloads + operator to add two user defined objects
     * 
     * Params:
     *      const class     :   other
     * 
     * Returns:
     *      classObject     :   newList
     */

    MyVector operator+(const MyVector &other)
    {
        // create a new linked list
        MyVector newList;
        Node *temp = other.head;

        Node *curr = this->head;
        // loop
        while (temp)
        {
            newList.pushRear(curr->data + temp->data);
            curr = curr->next;
            temp = temp->next;
            if (temp == nullptr)
            {
                while (curr)
                {
                    newList.pushRear(curr->data);
                    curr = curr->next;
                }
            }
        }
        return newList;
    }

    /**
     * Public : operator-
     * 
     * Description:
     *       Overloads - operator to subtract two user defined objects
     * 
     * Params:
     *      const class     :   other
     * 
     * Returns:
     *      classObject     :   newList
     */
    MyVector operator-(const MyVector &other)
    {
        // create a new linked list
        MyVector newList;
        Node *temp = other.head;
        Node *curr = this->head;

        if (listSize(temp) > listSize(curr))
        { // if temp > curr in size
            while (temp)
            {
                newList.pushRear(curr->data - temp->data);
                curr = curr->next;
                temp = temp->next;
                if (curr == nullptr)
                {
                    while (temp)
                    {
                        newList.pushRear(temp->data);
                        temp = temp->next;
                    }
                    return newList;
                }
            }
        }
        else
        { // if curr > temp
            while (curr)
            {
                newList.pushRear(curr->data - temp->data);
                curr = curr->next;
                temp = temp->next;
                if (temp == nullptr)
                {
                    while (curr)
                    {
                        newList.pushRear(curr->data);
                        curr = curr->next;
                    }
                    return newList;
                }
            }
        }
        return newList;
    }

    /**
     * Public : operator/
     * 
     * Description:
     *       Overloads / operator to divide two user defined objects
     * 
     * Params:
     *      const class     :   other
     * 
     * Returns:
     *      classObject     :   newList
     */
    MyVector operator/(const MyVector &other)
    {
        // create a new linked list
        MyVector newList;
        Node *temp = other.head;
        Node *curr = this->head;

        if (listSize(temp) > listSize(curr))
        { // if temp > curr in size
            while (temp)
            {
                newList.pushRear(curr->data / temp->data);
                curr = curr->next;
                temp = temp->next;
                if (curr == nullptr)
                {
                    while (temp)
                    {
                        newList.pushRear(temp->data);
                        temp = temp->next;
                    }
                    return newList;
                }
            }
        }
        else
        { // if curr > temp
            while (curr)
            {
                newList.pushRear(curr->data / temp->data);
                curr = curr->next;
                temp = temp->next;
                if (temp == nullptr)
                {
                    while (curr)
                    {
                        newList.pushRear(curr->data);
                        curr = curr->next;
                    }
                    return newList;
                }
            }
        }
        return newList;
    }

    /**
     * Public : operator*
     * 
     * Description:
     *       Overloads * operator to multiply two user defined objects
     * 
     * Params:
     *      const class     :   other
     * 
     * Returns:
     *      classObject     :   newList
     */
    MyVector operator*(const MyVector &other)
    {
        // create a new linked list
        MyVector newList;
        Node *temp = other.head;
        Node *curr = this->head;

        if (listSize(temp) > listSize(curr))
        { // if temp > curr in size
            while (temp)
            {
                newList.pushRear(curr->data * temp->data);
                curr = curr->next;
                temp = temp->next;
                if (curr == nullptr)
                {
                    while (temp)
                    {
                        newList.pushRear(temp->data);
                        temp = temp->next;
                    }
                    return newList;
                }
            }
        }
        else
        { // if curr > temp
            while (curr)
            {
                newList.pushRear(curr->data * temp->data);
                curr = curr->next;
                temp = temp->next;
                if (temp == nullptr)
                {
                    while (curr)
                    {
                        newList.pushRear(curr->data);
                        curr = curr->next;
                    }
                    return newList;
                }
            }
        }
        return newList;
    }

    /**
     * Public : operator=
     * 
     * Description:
     *       Overloads assignment (=) operator to copy and replace one list with another list
     * 
     * Params:
     *      const class     :   rhs
     * 
     * Returns:
     *      classObject     :   *this
     */
    MyVector operator=(const MyVector &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        this->head = rhs.head;
        this->tail = rhs.tail;
        return *this;
    }

    /**
     * Public : operator==
     * 
     * Description:
     *       Overloads == operator to compare two list and return a true or false
     * 
     * Params:
     *      const class     :   rhs
     * 
     * Returns:
     *      bool            :   true/false
     */

    bool operator==(const MyVector &rhs)
    {
        // check if the contents are same or not
        Node *list1 = this->head;
        Node *list2 = rhs.head;
        if (listSize(list1) != listSize(list2))
        {
            return false;
        }
        else
        {
            while (list1)
            {
                // check if the nodes data are same
                if (list1->data == list2->data)
                {
                    list1 = list1->next;
                    list2 = list2->next;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * Public : operator-
     * 
     * Description:
     *       Overloads subscript ([]) operator to get the indexed element from a list
     * 
     * Params:
     *      const int     :   index
     * 
     * Returns:
     *      int           :   data
     */
    // overloading subscript to get index element
    int &operator[](const int index)
    {
        int count = 0;
        Node *temp = this->head;
        while (count != index)
        {
            temp = temp->next;
            count++;
        }
        return temp->data;
    }
};

int main()
{

    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {10, 20, 30};

    ofstream ofile;
    ofile.open("output.txt");

    MyVector v1(a1, sizeof(a1) / sizeof(a1[0]));
    MyVector v2(a2, sizeof(a2) / sizeof(a2[0]));

    cout << v1[2] << endl;
    // writes out 3

    v1[4] = 9;
    // v1 now = [1,2,3,4,9]

    cout << v1 << endl;
    // writes out [1,2,3,4,9] to console.

    ofile << v1 << endl;
    // writes out [1,2,3,4,9] to your output file.

    MyVector v3 = v1 + v2;
    cout << v3 << endl;
    // writes out [11,22,33,4,9] to console.

    v3 = v1 - v2;
    cout << v3 << endl;
    // writes out [-9,-18,-27,4,9] to console.

    v3 = v2 - v1;
    cout << v3 << endl;
    // writes out [9,18,27,4,9] to console.

    v3 = v2 * v1;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.

    v3 = v1 * v2;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.

    v3 = v1 / v2;
    cout << v3 << endl;
    // writes out [0,0,0,4,9] to console.

    v3 = v2 / v1;
    cout << v3 << endl;
    // writes out [10,10,10,4,9] to console.

    cout << (v2 == v1) << endl;
    // writes 0 to console (false) .

    MyVector v4 = v1;
    cout << (v4 == v1) << endl;
    // writes 1 to console (true) .
}