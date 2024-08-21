#include <iostream>
#include<algorithm>

using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int value)
    {
        size += 1;
        int i = size;
        arr[i] = value;

        while (i > 1)
        {
            int p = i / 2;

            if (arr[p] < arr[i])
            {
                swap(arr[p], arr[i]);
                i = p;
            }
            else
                return;
        }
    }

    void heapify(int arr[], int size, int index){
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && arr[largest] < arr[left]){
            largest = left;
        }
        if (right <= size && arr[largest] < arr[right]){
            largest = right;
        }

        if (largest != index){
            swap(arr[index],arr[largest]);
            heapify(arr,size,largest);
        }
    }

    void deleteelement(){
        if (size == 0){
            cout<<"Nothing to delete.!"<<endl;
            return ;
        }

        arr[1] = arr[size];
        size--;

        // ///by STL function 
        // make_heap(arr+1,arr+size);

        // ///by itratively
        // int i = 1;

        // while (i < size){
        //     int left = 2 * i ;
        //     int right = 2 * i + 1;

        //     if (left <= size && arr[left] > arr[i] && arr[left] > arr[right]){
        //         swap(arr[left],arr[i]);
        //         i = left;
        //     }
        //     else if (right <= size && arr[right] > arr[i]){
        //         swap(arr[right],arr[i]);
        //         i = right;
        //     }
        //     else return ;
        // }

        /// by heapify 
        heapify(arr,size,1);

    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void isHeap(int *arr, int size){
        int index = size/2;

        for (int i = index;i>0;i--){
           int left = 2 * i;
           int right = 2*i + 1;

           if (left <= size && arr[left] > arr[i]){
             cout<<"NO!"<<endl;
             return;
           }
           if (right <= size && arr[right] > arr[i]){
            cout<<"NO!"<<endl;
            return ;
           }
        }

        cout<<"Yes!.. It's a heap."<<endl;
        return ;
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(60);

    h.display();

    h.deleteelement();
    h.display();

    return 0;
}



/*
//// For Min heap implementation 

#include <iostream>
#include<algorithm>

using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int value)
    {
        size += 1;
        int i = size;
        arr[i] = value;

        while (i > 1)
        {
            int p = i / 2;

            if (arr[p] > arr[i])
            {
                swap(arr[p], arr[i]);
                i = p;
            }
            else
                return;
        }
    }

    void heapify(int arr[], int size, int index){
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && arr[largest] > arr[left]){
            largest = left;
        }
        if (right <= size && arr[largest] > arr[right]){
            largest = right;
        }

        if (largest != index){
            swap(arr[index],arr[largest]);
            heapify(arr,size,largest);
        }
    }

    void deleteelement(){
        if (size == 0){
            cout<<"Nothing to delete.!"<<endl;
            return ;
        }

        arr[1] = arr[size];
        size--;

        // ///by STL function 
        // make_heap(arr+1,arr+size);

        // ///by itratively
        // int i = 1;

        // while (i < size){
        //     int left = 2 * i ;
        //     int right = 2 * i + 1;

        //     if (left <= size && arr[left] > arr[i] && arr[left] > arr[right]){
        //         swap(arr[left],arr[i]);
        //         i = left;
        //     }
        //     else if (right <= size && arr[right] > arr[i]){
        //         swap(arr[right],arr[i]);
        //         i = right;
        //     }
        //     else return ;
        // }

        /// by heapify 
        heapify(arr,size,1);

    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(60);

    h.display();

    h.deleteelement();
    h.display();

    return 0;
}

*/