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

    Node *head = NULL;
    Node *tale = NULL;

    public:
        
        void addLast(int item){
            Node *node = new Node(item);

            if (head == NULL)
                head = tale = node;
            else{
                tale->next = node;
                tale = node;
            }
        }

        void print(){
            for(Node *i = head; i; i = i->next)
                cout << i->value << " ";
            cout << endl;
        }

        void freeList(){
            Node *ptn = head;
            while (ptn){
                // the sequence is critical
                head = head->next;
                delete ptn;
                ptn = head;
            }
        }
/*
        int addFirst(int item){

            return 0;
        }

        deleteFirst(){

        }

        deleteLast(){

        }

        contains(){

        }

        indexOf(){

        }
*/

};


#endif 