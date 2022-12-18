// 12. Write a function that counts the number of times a given int occurs in a Linked List

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

// int getOccurenceOfaGivenValue(ListNode *list, int value)
// {
//     int count = 0;

//     ListNode *tNode = list;

//     while (tNode != NULL)
//     {
//         if (tNode->data == value)
//             count++;
//         tNode = tNode->next;
//     }
//     return count;
// }

int getOccurenceOfaGivenValue(ListNode *list, int value)
{
    if (list == NULL)
        return 0;

    if (list->data == value)
    {
        return 1 + getOccurenceOfaGivenValue(list->next, value);
    }
    else
    {
        return 0 + getOccurenceOfaGivenValue(list->next, value);
    }
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);
    appendNode(l1, 40);
    appendNode(l1, 50);
    appendNode(l1, 60);

    displayList(l1);

    return 0;
}