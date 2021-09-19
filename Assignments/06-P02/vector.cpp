//Using code from repl.it create a more robust MyVector class that includes some added functionality.
#include <iostream>
 
 using namespace std;

 template <class T>
 struct Node{
     T data;
     Node<T>* next;
     Node(T d){
        data =d;
        next = NULL;
     }
 };
 
 template <class T>
 class MyVector {
    private:
        Node<T> *head;
    public:
        MyVector(){
            head = NULL;
        }

        ~MyVector(){}

        void push_back(T val){
          Node<T>* n = new Node<T>(val);
          if(head == NULL){
            head = n;
          } else {
            Node<T>* curr = head;
            while(curr->next != NULL){
              curr = curr->next;
            }
            curr->next = n;
          }
        }

        // overloaded push_back method to accept array of values
        void push_back(T* arr, T size){   
           for(int i=0; i<size; i++){
             if(head == NULL){
                Node<T>* n = new Node<T>(arr[i]);
                return;
             } else {
               Node<T>* curr = head;
              while(curr->next != NULL){
              curr = curr->next;
             }
             Node<T>* n = new Node<T>(arr[i]);
             curr->next = n;
           }
          }
        }
        
        // print method to print all the data in the linked list
        void print()
        {
             Node<T>* temp = head;
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

        int getSize(Node<T>* h){
            int count = 0;
            Node<T>* temp = h;
            while(temp){
                temp = temp->next;
                count++;
            }
            return count;
        }

        // overload assignment (=) operator 
        MyVector &operator=(const MyVector& rhs){
          Node<T>* temp = rhs.head;
          Node<T>* curr = this->head;
          if(getSize(this->head) > getSize(rhs.head)){ // basically if (v1.size > v2.size)
            // not in this test case
            while(temp != NULL){
                curr->data = temp->data;
                curr = curr->next;
                temp = temp->next;
            }
            return *this;
          } else {
             return *this;

            }

        }
        
        //overload + operator to add two MyVector Objects
        MyVector &operator+(const MyVector& other){
            Node<T>* tempOther = other.head;
            Node<T>* tempThis = this->head;
            while (tempOther != NULL){ // this loop will add the values until one linked list ends
              tempThis->data = tempThis->data + tempOther->data;
              tempThis = tempThis->next;
              tempOther = tempOther->next;
            }
          return *this;
        }

        //overload * operator to Multiply linkedList with constant value
        MyVector& operator*(int val){
          Node<T>* tempThis = this->head;
            while (tempThis != NULL){ // this loop will add the values until one linked list ends
              tempThis->data = tempThis->data * val;
              tempThis = tempThis->next;
            }
            return *this;
        }

        //overload * operator to multiply two linkedList Nodes
        MyVector& operator*(const MyVector& other){
          Node<T>* tempThis = this->head;
          Node<T>* tempOther = other.head;
            while (tempThis != NULL){ // this loop will add the values until one linked list ends
              tempThis->data = tempThis->data * tempOther->data;
              tempThis = tempThis->next;
              tempOther = tempOther->next;
            }
            return *this;
        }

        

        //overload + operator to add two  
        friend ostream& operator<<(ostream &out, const MyVector& other){
        Node<T>* temp = other.head;
        out << "[" ; 
        while(temp != NULL){
          out << temp->data ;
          temp = temp->next;
          if(temp == NULL){
            break;
          } else {
            out << ", ";
          }
        }
        out << ']';
        return out;
        }

        // overload subscripting operator to get the specific index of linked list
         T& operator[](const T index){
          int count=0;
          Node<T>* temp = this->head;
          while(count != index){
            temp = temp->next;
            count++;
          }
          return temp->data;
        }

 };

 int main(){

     MyVector<int> v1;
     MyVector<int> v2;

     v1.push_back(8);
     v1.print();
    // v1 contains: [8]

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.print();
    // v2 contains: [10,20,30]

    // Declare some int array
    int A[] = {1,2,3,4,5};

    v1.push_back(A,5);
    v1.print();
    // v1 contains: [8,1,2,3,4,5]

    v1 = v1 + v2;
    v1.print();
    // v1 contains: [18,21,32,3,4,5]

     cout<<v1<<endl;
    // would print: [18,21,32,3,4,5] to standard out.

    cout<<v1[2]<<endl;
    // would print: 32 to standard out.

    v2 = v2 * 3;
    cout << v2 << endl;
    // v2 contains: [30,60,90]

    v2 = v2 * v1;
    cout << v2 << endl;
    // v2 contains: [540,1260,2880]

    v2[2] = 100;
    cout << v2 << endl;
    // v2 contains: [540,1260,100]

    // What about strings??
    MyVector<string> v3;
    v3.push_back("string");
    v3.print();

     return 0;
 }