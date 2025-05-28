#include<iostream>
#include<vector>

using namespace std;

int binarysearch(vector<int>arr,int start, int end, int key)
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
    
    
}


int main(){
    
    int choice;
    int ch;

    do
    {
        cout << "Enter 1 to linklist " << endl;
        cout << "Enter 2 to Binary Search " << endl;
        cout << "Enter 3 to Quick sort " << endl;
        cout << "Enter 4 to exit " << endl;
        cin >> choice;

        switch (choice)
        {
            case 1 :{
                do
                {
                    cout << "Enter 1 to add at start " << endl;
                    cout << "Enter 2 to display " << endl;
                    cout << "Enter 3 to update at any potison  " << endl;
                    cout << "Enter 4 to delet at any postion " << endl;
                    cout << "Enter 5 to exit " << endl;
                    cin >> ch;
                    switch (ch)
                    {
                        case 1 :{
                            break;
                        }
                        case 2 :{
                            break;
                        }
                        case 3 :{
                            break;
                        }
                        case 4 :{
                            break;
                        }
                        case 5 :{
                            cout << "Thank you for using linklist......" << endl;
                            break;
                        }
                        default :{
                            cout << "Invalide Choice...." << endl;
                        }
                    }
                } while (ch != 0);
                
                break;
            }
            case 2 :{
                break;
            }
            case 3 :{
                break;
            }
            case 4 :{
                cout << "Thank you visit again......." << endl;
                break;
            }
            default :{
                cout << "Invalide Choice...." << endl;
            }

        }
    } while (choice != 0);
    
    return 0;
}


////////12