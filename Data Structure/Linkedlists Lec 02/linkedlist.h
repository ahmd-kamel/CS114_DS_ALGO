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
    // check if the list is empty
    bool isEmpty(){
        return head == NULL;
    }
    // return the node pervious to the given
    Node* previousNode(Node *(*node)){
        for (Node *i = head; i; i = i->next)
            if (i->next == *node){
                return i;
            }
            return NULL;
    }


    public:
    // constructor
    LinkedList(){
        array = NULL;
        head = NULL;
        tale = NULL;
        size = 0;
    }
    // appending item
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
    // appending item in the first
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
    // return the index of an item
    int indexOf(int item){
        int index = 0;
        for (Node *i = head; i; i = i->next){
            if (i->value == item)
                return index;
            index++;
        }
        return -1;
    }
    // check if the list contains a certain item
    bool contains(int item){
        return indexOf(item) != -1;
    }
    // print all items of the list
    void print(){
        for(Node *i = head; i; i = i->next)
            cout << i->value << " ";
        cout << endl;
    }
    // delete the first item
    void deleteFirst(){

        if (isEmpty())
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    // delete the lsat element
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
    // converte linked list to array
    int * convertToArray(){
        array = new int[size];
        int index = 0;
        for (Node *i = head; i; i = i->next){
            array[index++] = i->value;
        }
        return array;
    }
    // reverse the list sequence
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
        // last process current is Null so head is 
        head = previous;

    }

    int theKthNode(int k){

        if (isEmpty())
            throw invalid_argument("this is an empty array");
        if (k > size)
            throw invalid_argument("out of the list");
        if (k <= 0)
            throw invalid_argument("invalid node number");

        Node *first, *second;
        first = second = head;
        for (int i = 0; i < k; i++)
            second = second->next;
        while (second != NULL){
            first = first->next;
            second = second->next;
        }
        return first->value;
    }

    // return the middle item
    void printMiddel(){

        if (isEmpty())
            throw invalid_argument("this is an empty array");
        
        Node *first, *second;
        first = second = head;
        while (second != tale && second->next != tale){
            second = second->next->next;
            first = first->next;
        }

        if (second == tale){
            cout << first->value << endl;
            return;
        }
        cout << first->value << ", " << first->next->value << endl;
        return;
    }

    int hasLoop(){
        tale->next = head;
        Node *first, *second;
        first = second = head;
        while (second != NULL && second->next != NULL){
            second = second->next->next;
            first = first->next;
            if(second == first){
                return true;
            }
        }
        return false;
    }

    // return the size of the list
    int sizeList(){
        return size;
    }
    // free the memory of the list
    void freeList(){
        Node *ptn = head;
        int list_len = sizeList();
        for (int i = 0; i < list_len; i++){
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