// 14. Find length of loop/cycle in given Linked List

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

int contLengthOfCycle(ListNode *list)
{

    ListNode *slow = list;
    ListNode *fast = list->next;

    int count = 1;

    while (slow != fast)
    {
        fast = fast->next;

        if (fast)
        {
            fast = fast->next;
        }

        slow = slow->next;
    }

    slow = slow->next;

    while (slow != fast)
    {
        count++;
        slow = slow->next;
    }
    return count;
}

int main()
{
    ListNode *l1 = NULL;

    ListNode *newNode = new ListNode;
    newNode->data = 1;
    newNode->next = NULL;

    l1 = newNode;

    newNode = new ListNode;
    newNode->data = 2;
    newNode->next = NULL;

    l1->next = newNode;

    newNode = new ListNode;
    newNode->data = 3;
    newNode->next = NULL;

    l1->next->next = newNode;

    newNode = new ListNode;
    newNode->data = 4;
    newNode->next = NULL;

    l1->next->next->next = newNode;

    newNode = new ListNode;
    newNode->data = 5;
    newNode->next = NULL;

    l1->next->next->next->next = newNode;

    newNode->next = l1->next;

    // displayList(l1);

    cout << contLengthOfCycle(l1);

    return 0;
}