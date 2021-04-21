#ifndef ARRAY_H
#define ARRAY_H

class Array
{
    private:
    int *arr;
    int size;
    int initLength;

    public:
    Array(int length){

        arr = new int[length];

        initLength = length;

        for (int i = 0; i < length; i++)
            arr[i] = 0;

        size = 0;
    }

    void insert(int element){

        if (initLength == size){

            int *newItems = new int[size * 2];

            for (int i = 0; i < initLength; i++){
                newItems[i] = arr[i];
            }
            delete [] arr;
            arr = newItems;
            initLength = initLength * 2;
        }

        arr[size++] = element;
        return;
    }

    int max(){

        int max  = arr[0];
        for (int i = 1; i < size; i++){
            if (max < arr[i])
                max = arr[i];
        }
        return max;
    }

    void reverse(){
        int len = size / 2;
        int temp = 0;
        for (int i = 0; i < len; i++){
            temp = arr[size - 1 - i];
            arr[size - 1 - i] = arr[i];
            arr[i] = temp;
        }
        return;
    }

    void deleteIndex(int index){

        if(index < 0 || index > size)
            throw "The index out of the array";

        size--;
        for (int i = index; i < size; i++)
            arr[i] = arr[i + 1];
        return;
    }

    Array intersectAt(Array arr2)
    {

        for (int i = 0; i < arr2.size; i++){
            for (int j = i + 1; j < arr2.size; j++){
                if (arr2.arr[i] == arr2.arr[j]){
                    arr2.deleteIndex(j);
                    j--;
                }
            }
        }

        Array commElements(arr2.size);

        for (int i = 0; i < arr2.size; i++){
            for (int j = 0; j < size; j++){
                if (arr[j] == arr2.arr[i]){
                    commElements.insert(arr[j]);
                    break;
                }
            }
        }

        return commElements;
    }

    void insertAt(int index, int item){

        if(index < 0 || index > size)
            throw "The index out of the array";

        arr[index] = item;
        return; 
    }

    int indexOf(int item){
        for (int i = 0; i < size; i++)
            if (item == arr[i])
                return i;
        return -1;        
    }

    void print(){
        for (int i = 0; i < size; i++)
            cout << arr[i] << endl;
        return;    
    }

    void removeArr(){
        size = 0;
        delete [] arr;
    }




};



#endif