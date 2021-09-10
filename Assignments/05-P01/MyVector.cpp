/*****************************************************************************
*                    
*  Author:           Aayush Bhurtel
*  Email:            abhurtel1118@my.msutexas.edu
*  Label:            05-P01
*  Title:            MyVector Class
*  Course:           2143 OOP
*  Semester:         Fall 2021
* 
*  Description:
*        describe program here thoroughly 
* 
*  Usage:
*       - compile this cpp file
*       - './MyVector' in terminal
* 
*  Files:            (list of all source files used in this program)
*****************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

/**
 * Node
 * 
 * Description:
 *      Node class 
 * 
 * Public Methods:
 *      
 * Private Methods:
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

/**
 * MyVector
 * 
 * Description:
 *      This class creates a linkedlist with various push and pull methods
 * 
 * Public Methods:
 *      -  void pushFront(int val)
 *      -  void pushFront(MyVector& V2)
 *      -  void pushRear(int val)
 *      -  void pushRear(MyVector V2)
 *      -  void inOrderPush(int val)
 *      -  int popFront() 
 *      -  int popRear() 
 *      -  int popAt(int loc) 
 *      -  int find(int val) 
 *      -  void print()
 * 
 * Private Methods:
 *      
 * 
 * Usage: 
 *  
 *      
 */
class MyVector {
    private:
        Node* head;

    public:
    /**
     * Public : MyVector
     * 
     * Description:
     *      default constructor that initializes head as NULL
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      
     */ 
        MyVector(){
            head = NULL;
        }

    /**
     * Public : MyVector
     * 
     * Description:
     *      overloaded constructor that populates the linkedlist from an Array A of size "size"
     * 
     * Params:
     *      - int* A
     *      - int size
     *
     * Returns:
     *      none
     */ 
        MyVector(int* A, int size){
            head = NULL;
            for(int i=1; i<size+1; i++){
                pushFront(A[size - i]);
            }

            // bubble sort
           for(int i = 0; i< size-1 ; i++ ){
               for(int j = 0 ; j < size-(i-1); j++){
                   if(A[j]>A[j+1]){
             // if current node is greater then next node
                        int temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                   }
               }
           }
        }

    /**
     * Public : MyVector
     * 
     * Description:
     *      overloaded constructor that opens a file and populates LinkedList with the contains of a file, one line at a time
     * 
     * Params:
     *      - string FileName
     * 
     * Returns:
     *     none
     *      
     */ 
        MyVector(string FileName){
          head = NULL;
          int a;
          ifstream fin;
          fin.open(FileName);
          while(!fin.eof()){
                  fin >> a;
                  pushRear(a);
          }
          
        }
    
    /**
     * Public : MyVector
     * 
     * Description:
     *      copy constructor to deep copy the contains of the class object
     * 
     * Params:
     *      - const MyVector& other
     * 
     * Returns:
     *     none
     *      
     */ 
        MyVector(const MyVector& other){
            
            this->head = new Node(*other.head);
            
           
        }

        /**
     * Public : ~MyVector
     * 
     * Description:
     *      destrctor to newly allocated head node
     * 
     * Params:
     *      none
     * 
     * Returns:
     *     none
     *      
     */ 
        ~MyVector(){delete head;}
    

    /**
     * Public : pushFront
     * 
     * Description:
     *      This adds the new Node to the front of currently existing linkedList. if the list is empty then it assigns a head
     * 
     * Params:
     *      - int val 
     * 
     * Returns:
     *      none
     */
        void pushFront(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

    /**
     * Public : pushFront
     * 
     * Description:
     *     This method takes in MyVetor object and add the list in the front of existing LinkedList.
     * 
     * Params:
     *      MyVector& V2
     * 
     * Returns:
     *      none
     */
         void pushFront(MyVector& V2){
           cout << "V2 head: " << V2.head->data<< endl;
           Node* h = V2.head;
           Node* temp = h->next;
           Node* curr = h;
           while(curr != NULL){
               if(h->next == nullptr){
                   return;
               }
                while(temp->next != NULL){
                temp = temp->next;
                curr = curr-> next;
            }
                pushFront(curr->data); // pushFront last element
                curr->next = nullptr;
                curr = h;
                temp = h->next;
           }
        }

    /**
     * Public : pushRear
     * 
     * Description:
     *     This method adds the new Node at the end of existing linedlist
     * 
     * Params:
     *      - int val
     * 
     * Returns:
     *      none
     */
        void pushRear(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = newNode;
            } else {
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
                //return;
            }
        }
        
    /**
     * Public : pushRear
     * 
     * Description:
     *     This method takes in MyVetor object and add the list at the end of existing LinkedList.
     * 
     * Params:
     *      - MyVector V2
     * 
     * Returns:
     *      none
     */
        void pushRear(MyVector V2){
            
            Node* temp = V2.head;
            while(temp != NULL){
                pushRear(temp->data);
                temp = temp->next;
            }
            
            
        }
    /**
     * Public : pushAt
     * 
     * Description:
     *      This method addes a new node at the specific location
     * 
     * Params:
     *      - int loc
     *      - int val
     *
     * Returns:
     *      none
     */
        // void pushAt(int loc, int val){

        // }

    /**
     * Public : inOrderPush
     * 
     * Description:
     *      This method will adds the new node in existing LinkedList at the appropriate position
     * 
     * Params:
     *      - int val
     * 
     * Returns:
     *      none
     */
        void inOrderPush(int val){

            Node* tempp = head->next;
            Node* curr = head;
             // check if the head node is greater then the val
                if (head->data > val){
                    // prepend the val in linked list
                    Node* n = new Node(val);
                    n->next = head;
                    head = n;
                }
            while(curr != NULL){
               
                if (tempp->data > val){
                    // insert new node before temp node
                    Node* newNode = new Node(val);
                    newNode-> next = tempp;
                    curr -> next = newNode;
                     return;
                }
                curr = curr -> next;
                tempp = tempp -> next;
                
            }

        }
        
    
    /**
     * Public : popFront
     * 
     * Description:
     *      This will remove an node from a front of linkedlist
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      - integer
     */
        int popFront(){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            return temp->data;
            
          }
        
    /**
     * Public : popRear
     * 
     * Description:
     *      This will remove an node from a rear of linkedlist
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      none
     */
        int popRear(){
            Node* temp; Node* current;
            temp = head ->next;
            current = head;
            
            while(temp->next != NULL){
                temp = temp -> next;
                current = current -> next;
            }
            current->next = nullptr;
            return temp->data;
        }

    /**
     * Public : popAt
     * 
     * Description:
     *      This method removes a node from a specific location
     * 
     * Params:
     *      - int loc
     * 
     * Returns:
     *      - int
     */
        int popAt(int loc){
            Node* curr = head;
            Node* temp = head->next;
            for(int i=1; i<loc; i++){
                curr = curr->next;
                temp = temp->next;
            }
            curr->next = curr->next->next;
            temp->next = NULL;
            return temp->data;
        }
        
    /**
     * Public : find
     * 
     * Description:
     *      This method searches the node from specific data(value) and returns that value
     * 
     * Params:
     *      - int val
     * 
     * Returns:
     *      - int
     */
        int find(int val){
            int count = 0;
            bool exist = false;
            Node* temp = head;
            while(temp != NULL){
                // check if val exist
                if(temp->data == val){
                    return count;
                } else {
                    temp = temp -> next;
                    count++;
                }
            }
            return -1;
        }

    /**
     * Public : print
     * 
     * Description:
     *      - this method prints the LinkedList
     *
     * Params:
     *      
     * 
     * Returns:
     *      None
     */
        void print(){
            Node* temp = head;
            cout << "[";
            while(temp){
                cout<<temp->data;
                if(temp->next){
                    cout << ", ";
                }
                temp = temp->next;
            }
            cout<< "]" << endl;
        }


};

int main(){
// main driver class
int x = 0;

MyVector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print();
// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};
MyVector v2(A,5);
v2.print();
// [11, 25, 33, 47, 51]

v2.pushFront(9);
v2.inOrderPush(27);
v2.pushRear(63);
v2.print();
// [9, 11, 25, 27, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print();
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
cout<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33]
cout<<x<<endl;
// 47

x = v2.popAt(3);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]
cout<<x<<endl;
// 27

x = v2.find(51);
cout<<x<<endl;
// // 5

x = v2.find(99);
cout<<x<<endl;
// // -1

MyVector v3(v1);
v3.print();
// // [18, 20, 25, 9, 11, 25, 27, 33]

v3.pushFront(v2);
v3.print();
// //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

MyVector v4("input.dat");
v4.print();
v4.pushRear(v3);
v4.print();
// // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
 }