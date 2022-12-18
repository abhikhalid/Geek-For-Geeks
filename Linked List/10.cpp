// 10. Program for Nth node from the end of a Linked List

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

int getNthNodeFromTheEndOfList(ListNode *list, int n)
{
    ListNode *slow = list;
    ListNode *fast = list;

    int count = 0;
    while (fast != NULL && count != n)
    {
        count++;
        fast = fast->next;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);
    appendNode(l1, 40);
    appendNode(l1, 50);

    displayList(l1);

    cout << getNthNodeFromTheEndOfList(l1, 3);

    return 0;
}