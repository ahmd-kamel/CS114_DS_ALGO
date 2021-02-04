#ifndef LINKED_LIST
#define LINKED_LIST

class LinkedList{

    private:
    // node
    class Node{
        public:
        int value;
        Node *next;
        Node(int value){
            this->value = value;
            this->next = NULL;
        }
    };
    int size;
    int *array;
    Node *head;
    Node *tale;

    bool isEmpty(){
        return head == NULL;
    }

    Node* previousNode(Node *(*node)){
        for (Node *i = head; i; i = i->next)
            if (i->next == *node){
                return i;
            }
            return NULL;
    }


    public:

    LinkedList(){
        array = NULL;
        head = NULL;
        tale = NULL;
        size = 0;
    }
    
    void addLast(int item){
        Node *node = new Node(item);

        if (isEmpty())
            head = tale = node;
        else{
            tale->next = node;
            tale = node;
        }
        size++;
    }

    void addFirst(int item){
        Node *node = new Node(item);
        if (isEmpty())
            head = tale = node;
        else{
            node->next = head;
            head = node;
        }
        size++;
    }

    int indexOf(int item){
        int index = 0;
        for (Node *i = head; i; i = i->next){
            if (i->value == item)
                return index;
            index++;
        }
        return -1;
    }

    bool contains(int item){
        return indexOf(item) != -1;
    }

    void print(){
        for(Node *i = head; i; i = i->next)
            cout << i->value << " ";
        cout << endl;
    }

    void deleteFirst(){

        if (isEmpty())
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deleteLast(){
        if (isEmpty())
            return;
        
        if (head == tale){
            delete head;
            head = tale = NULL;
        }
        else{
            tale = previousNode(&tale);
            delete tale->next;
            tale->next = NULL;
        }
        size--;
    }

    int * convertToArray(){
        array = new int[size];
        int index = 0;
        for (Node *i = head; i; i = i->next){
            array[index++] = i->value;
        }
        return array;
    }

    void reverse(){
        if (isEmpty())
            return;

        Node *current, *previous;
        previous = head;
        current = head->next;

        while(current != NULL){
            Node *follow = current->next;
            current->next = previous;
            previous = current;
            current = follow;
        }
        tale = head;
        tale->next = NULL;
        head = previous;

    }

    int theKthNode(int k){

        if (isEmpty())
            throw invalid_argument("this is an empty array");
        if (k > size)
            throw invalid_argument("out of the list");
        if (k <= 0)
            throw invalid_argument("invalid node number");

        Node *a, *b;
        a = b = head;
        for (int i = 0; i < k; i++)
            b = b->next;
        while (b != NULL){
            a = a->next;
            b = b->next;
        }
        return a->value;

    }





    int sizeList(){
        return size;
    }

    void freeList(){
        Node *ptn = head;
        while (ptn){
            // the sequence is critical
            head = head->next;
            delete ptn;
            ptn = head;
        }
        if (array)
            delete []array;
    }

};


#endif 