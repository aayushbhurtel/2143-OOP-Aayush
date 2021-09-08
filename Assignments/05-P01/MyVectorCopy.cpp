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
    // overloaded constructor
        MyVector(int* A, int size){
            head = NULL;
            for(int i=0; i<size; i++){
                pushFront(A[i]);
            }
        }
    // overloaded constructor

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
         void pushFront(MyVector V2){
           
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
                return;
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
        // void pushRear(MyVector V2){

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
        // void inOrderPush(int val){

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
        // int popFront(){
          
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
        // int popRear(){

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
        // int popAt(int loc){

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
        // int find(int val){

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
}