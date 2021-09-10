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
*        how to use the program if necessary
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
 *      Description of your class and what it does
 * 
 * Public Methods:
 *      - A list of 
 *      - each public method
 *      - with return types
 * 
 * Private Methods:
 *      - A list of 
 *      - each private method
 *      - with return types
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */
class MyVector {
    private:
        Node* head;

    public:
    // constructor 
        MyVector(){
            head = NULL;
        }
    // overloaded constructor [needs modification]
        MyVector(int* A, int size){
            head = NULL;
            for(int i=1; i<size+1; i++){
                pushFront(A[size - i]);
            }

            // sort linked list
           for(int i = 0; i< size-1 ; i++ ){
               for(int j = 0 ; j < size-(i-1); j++){
                   if(A[j]>A[j+1]){ // if current node is greater then next node
                        int temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                   }
               }
           }
        }

    // overloaded contructor for external file
        MyVector(string FileName){
          int a;
          ifstream fin;
          fin.open(FileName);
          while(!fin.eof()){
                  fin >> a;
                  pushRear(a);
          }
          
        }
    
    // copy constructor
        MyVector(const MyVector& other){
            
           head = other.head;
           
        }
    

    /**
     * Public/Private/Protected : pushFront
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      int :   integers 
     * 
     * Returns:
     *      - void
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
     * Public/Private/Protected : pushFront
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      MyVector    :   object
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
         void pushFront(MyVector& V2){
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
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
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
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
        void pushRear(MyVector V2){
            // cout << this->head->data << endl; //25
            // cout << V2.head->data << endl; // 9
            Node* temp = V2.head;
            while(temp != NULL){
                pushRear(temp->data);
                temp = temp->next;
            }
            // Node* temp = head;
            // while(temp!=NULL){
            //     temp=temp->next;
            // }
            // // temp is the last element
            // Node* curr = V2.head;
            // while(curr!=NULL){
            //     pushRear(curr->data);
            //     curr = curr->next;
            // }
            
        }
    /**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
        // void pushAt(int loc, int val){

        // }

    /**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
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
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
        int popFront(){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            return temp->data;
            
          }
        
    /**
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
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
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
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
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
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
     * Public/Private/Protected : function_name
     * 
     * Description:
     *      Describe the functions purpose
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
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
v4.pushRear(v3);
v4.print();
// // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
 }
