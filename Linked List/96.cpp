// 96. Insert node into the middle of the linked list

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

ListNode *insertMiddleList(ListNode *list, int x)
{
    ListNode *slow = list;
    ListNode *fast = list->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;

        if (fast)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }

    ListNode *newNode = new ListNode;
    newNode->data = x;
    newNode->next = NULL;

    ListNode *temp = slow->next;

    slow->next = newNode;
    newNode->next = temp;

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    // appendNode(l1, 5);
    // appendNode(l1, 10);
    // appendNode(l1, 4);
    // appendNode(l1, 32);
    // appendNode(l1, 16);

    // displayList(l1);

    // displayList(insertMiddleList(l1, 41));

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 4);
    appendNode(l1, 5);

    displayList(l1);

    displayList(insertMiddleList(l1, 3));

    return 0;
}