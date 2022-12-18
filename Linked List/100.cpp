// 100. Count rotations in sorted and rotated linked list

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

int countRotationInSortedAndRotatedList(ListNode *list)
{

    int count = 0;

    while (list->next != NULL)
    {
        if (list->data < list->next->data)
            count++;
        else
            return count + 1;
        list = list->next;
    }
    // return count;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 15);
    appendNode(l1, 18);
    appendNode(l1, 5);
    appendNode(l1, 8);
    appendNode(l1, 11);
    appendNode(l1, 12);

    displayList(l1);

    cout << countRotationInSortedAndRotatedList(l1) << endl;

    return 0;
}