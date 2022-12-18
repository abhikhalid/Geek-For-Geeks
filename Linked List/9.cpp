// 9. Write a function to get Nth node in a Linked List

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

void appendNode(ListNode *&list, int value)
{
    // creating a new node
    ListNode *newNode = new ListNode;
    newNode->data = value;
    newNode->next = NULL;

    if (list == NULL)
    {
        list = newNode;
    }
    else
    {
        ListNode *tNode = list;

        while (tNode->next != NULL)
        {
            tNode = tNode->next;
        }
        tNode->next = newNode;
    }
}

void displayList(ListNode *list)
{
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        cout << tNode->data << "->";
        tNode = tNode->next;
    }
    cout << "NULL" << endl;
}

// int GetNth(ListNode *list, int n)
// {
//     ListNode *tNode = list;
//     int count = 0;

//     while (tNode != NULL && count != n)
//     {
//         count++;
//         tNode = tNode->next;
//     }
//     if (tNode != NULL)
//         return tNode->data;
// }

int GetNtH(ListNode *list, int n)
{
    if (list == NULL)
        return -1;

    if (n == 0)
        return list->data;

    return GetNtH(list->next, n--);
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);

    displayList(l1);

    return 0;
}