// 98. Insert a node after the n-th node from the end

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

ListNode *insertNthFromTheEnd(ListNode *&list, int n, int x)
{
    ListNode *slow = list;
    ListNode *fast = list;

    int count = 1;

    while (count != n && fast != NULL)
    {
        count++;
        fast = fast->next;
    }

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *newNode = new ListNode;
    newNode->data = x;
    newNode->next = NULL;

    ListNode *slowNext = slow->next;
    slow->next = newNode;
    newNode->next = slowNext;

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    // appendNode(l1, 1);
    // appendNode(l1, 3);
    // appendNode(l1, 4);
    // appendNode(l1, 5);

    // displayList(l1);

    // displayList(insertNthFromTheEnd(l1, 4, 2));

    appendNode(l1, 10);
    appendNode(l1, 8);
    appendNode(l1, 3);
    appendNode(l1, 12);
    appendNode(l1, 5);
    appendNode(l1, 18);

    displayList(l1);

    displayList(insertNthFromTheEnd(l1, 2, 11));

    return 0;
}