// 11. Find the middle of a given linked list

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

int findMiddleOfLinkedList(ListNode *list)
{
    ListNode *slow = list;
    ListNode *fast = list->next;

    while (fast != NULL)
    {

        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
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
    appendNode(l1, 60);

    displayList(l1);

    cout << findMiddleOfLinkedList(l1);

    return 0;
}