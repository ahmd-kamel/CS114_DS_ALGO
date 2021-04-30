#ifndef Stack_H
#define Stack_H
// this is stack approch with linked lists
// you have to define type of the stack elements in the main
        // typedef char stackType;

class Stack{
    private:
        int size;
        struct Node{
            stackType data;
            struct Node *last;
        };
        Node *top;

    public:
        Stack(){
            size = 0;
            top = NULL;
        }

        void push(stackType element){
            Node *temp = new Node();
            if (!temp)
                throw invalid_argument("heap overflow");

            if (element != '\0'){
                temp->data = element;
                temp->last = top;
                top = temp;
                size++;
            }
            else{
                throw invalid_argument("invalid element");
            }
        }

        stackType pop(){
            if (empty())
                throw invalid_argument("this is an empty stack");
            Node *temp = new Node();
            stackType element = top->data;
            temp = top;
            top = top->last;
            temp->last = NULL;
            delete(temp);
            size--;
            return element;

        }

        int empty(){
            if (size == 0)
                return 1;
            return 0;
        } 
        stackType peek(){
            if (empty())
                throw invalid_argument("this is an empty stack");
            return top->data;
        }

        int stackSize(){
            return size;
        }

        void printStack(){
            if (empty())
                throw invalid_argument("this is an empty stack");
            Node *temp = top;
            while (temp != NULL){
                cout << temp->data << " ";
                temp = temp->last;
            }
            cout << endl;
        }

        void destroyStack(){
            Node *temp = top;
            while (top != NULL){
                top = top->last;
                delete(temp);
                temp = top;
            }
        }

};


// this is stack approch with array implementation

// you have to define type of the stack elements and size in the main

        //typedef char stackType;
        //const int maxLength = 100;
/*
class Stack{
    private:
        int size;
        stackType data[maxLength];
    public:
        Stack(){
            size = 0;
            data[maxLength] = {0};
        }

        void push(stackType element){
            if (size >= maxLength)
                throw invalid_argument("this is a full stack");
            if (element != '\0'){
                data[size] = element;
                size++;
            }
            else{
                throw invalid_argument("invalid element");
            }
        }
        
        stackType pop(){
            if (empty())
                throw invalid_argument("this is an empty stack");
            return data[--size];
        }

        int empty(){
            if (size == 0)
                return 1;
            return 0;
        }

        stackType peek(){
            if (empty())
                throw invalid_argument("this is an empty stack");
            return data[size - 1];
        }

        int stackSize(){
            return size;
        }

        void printStack(){
            if (empty())
                throw invalid_argument("this is an empty stack");
            for (int i = 0; i < size; i++)
                cout << data[i] << " ";
            cout << endl;
        }

        void destroyStack(){
            size = 0;
        }

};

*/

#endif 