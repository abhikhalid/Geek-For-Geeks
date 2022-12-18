// 13. Detect loop in a linked list

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

bool hasCycle(ListNode *&list)
{
    ListNode *slow = list;
    ListNode *fast = list->next;

    while (slow != fast)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }
        else
        {
            return false;
        }

        slow = slow->next;
    }
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);

    ListNode *newNode = new ListNode;
    newNode->data = 5;

    ListNode *tNode = l1;
    while (tNode->next != NULL)
    {
        tNode = tNode->next;
    }
    tNode->next = newNode;
    newNode->next = l1->next;

    // displayList(l1);

    if (hasCycle(l1))
    {
        cout << "Cycle present" << endl;
    }
    else
    {
        cout << "Cycle not found!" << endl;
    }

    return 0;
}