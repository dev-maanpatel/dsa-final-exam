#include <iostream>
#include <vector>

using namespace std;

int binarysearch(vector<int> &arr, int start, int end, int key)
{
    int mid = (start + end) / 2;
    if (start > end)
    {
        return -1;
    }
    if (key == arr[mid])
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return binarysearch(arr, mid + 1, end, key);
    }
    else
    {
        return binarysearch(arr, start, mid - 1, key);
    }
}
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0, temp;
    for (int i = start; i <= end; i++)
    {
        if (pivot > arr[i])
        {
            count++;
        }
    }
    int pivotIdx = start + count;
    temp = arr[start];
    arr[start] = arr[pivotIdx];
    arr[pivotIdx] = temp;
    int i = start;
    int j = end;
    while (i < pivotIdx && j > pivotIdx)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIdx && j > pivotIdx)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    return pivotIdx;
}
void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int idx = partition(arr, start, end);
    quickSort(arr, start, idx - 1);
    quickSort(arr, idx + 1, end);
}

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class Linkedlist
{
public:
    int count;
    Node *Head;

    Linkedlist()
    {
        this->count = 0;
        this->Head = nullptr;
    }

    void addAtStart(int data)
    {
        Node *newNode = new Node(data);
        if (count == 0)
        {
            this->Head = newNode;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
        this->count++;
    }
    void viewAll()
    {
        Node *temp = Head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void update(int data, int positon)
    {
        Node *temp = Head;
        for (int i = 0; i < (positon); i++)
        {
            temp = temp->next;
        }
        temp->data = data;
    }
    void deleteAtAny(int positon)
    {
        if (positon == 0)
        {
            Node* temp = Head;
            Head = Head->next;
            delete temp;

            temp = nullptr;
            return;
        }
        

        Node *current = Head;
        Node *prev = Head;

        for (int i = 0; i < positon; i++)
        {
            current = current->next;
        }
        for (int i = 0; i < (positon - 1); i++)
        {
            prev = prev->next;
        }
        prev->next = current->next;
        delete current;
        current = nullptr;

        prev = nullptr;
        delete prev;
    }
};

int main()
{

    Linkedlist l1;

    int choice;
    do
    {
        cout << "-----------------------------"<<endl;
        cout << "Enter 1 For LinkedList : " << endl;
        cout << "Enter 2 For BinerySearch : " << endl;
        cout << "Enter 3 For Quick sort : " << endl;
        cout << "Enter 4 For Exit : " << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        cout << "-----------------------------"<<endl;

        switch (choice)
        {
        case 1:
        {
            int ch;
            do
            {
                cout << "-----------------------------"<<endl;
                cout << "Enter 1 For Add At Start in linklist : " << endl;
                cout << "Enter 2 For Update linklist: " << endl;
                cout << "Enter 3 For Delete At Any postion of linklist : " << endl;
                cout << "Enter 4 For View All data of linklist : " << endl;
                cout << "Enter 5 For Exit in LinkedList : " << endl;
                cout << "Enter choice : " << endl;
                cin >> ch;
                cout << "-----------------------------"<<endl;
                switch (ch)
                {
                case 1:
                {
                    int data;
                    cout << "Enter Data : ";
                    cin >> data;
                    l1.addAtStart(data);
                    break;
                }
                case 2:
                {
                    int positon, data;
                    cout << "Enter positon : ";
                    cin >> positon;
                    cout << "Enter Data : ";
                    cin >> data;
                    l1.update(data, positon);
                    break;
                }
                case 3:
                {
                    int positon;
                    cout << "Enter positon : ";
                    cin >> positon;
                    l1.deleteAtAny(positon);
                    break;
                }
                case 4:
                {
                    l1.viewAll();
                    break;
                }
                case 5:
                {
                    cout << "Thank you For Using LinkedList : " << endl;
                    break;
                }

                default:
                    cout << "Invalide choice....." << endl;
                    break;
                }
            } while (choice != 5);

            break;
        }
        case 2:
        {
            int size;
            cout << "Enter Size : ";
            cin >> size;
            vector<int> arr(size);
            for (int i = 0; i < size; i++)
            {
                cout << "enter Element : ";
                cin >> arr[i];
            }
            quickSort(arr,0,size-1);
            for (int val : arr)
            {
               
                cout << val << " ";
               
            }
            cout << endl;
            

            int key;
            cout << "Enter Key : ";
            cin >> key;
            int idx = binarysearch(arr, 0, size - 1, key);
            if (idx == -1)
            {
                cout << "Element Is Not Found ! " << endl;
            }
            else
            {
                cout << "Element Is Founded ON index " << idx << endl;
            }

            break;
        }
        case 3:
        {
            int size;
            cout << "Enter Size : ";
            cin >> size;
            vector<int> arr(size);
            for (int i = 0; i < size; i++)
            {
                cout << "enter Element For SortIng : ";
                cin >> arr[i];
            }
            cout << "After : "<<endl;
            for (int val : arr)
            {
                
                cout << val << " ";
                
            }
            cout << endl;
            quickSort(arr, 0, size - 1);
            cout << "Before : "<<endl;
            for (int val : arr)
            {
                
                cout << val << " ";
                
            }
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Thank You For Visit : "<<endl;
            break;
        }

        default:
        cout << "Invalide choice !! ";
            break;
        }
    } while (choice != 4);

    return 0;
}