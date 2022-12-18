// Search an element in a Linked List (Iterative and Recursive)

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

bool isPresent(ListNode *list, int value)
{
    ListNode *tNode = list;

    while (tNode != NULL)
    {
        if (tNode->data == value)
            return true;
        tNode = tNode->next;
    }
    return false;
}

bool searchElement(ListNode *list, int value)
{
    if (list == NULL)
        return false;

    if (list->data == value)
        return true;

    return searchElement(list->next, value);
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);

    displayList(l1);

    if (searchElement(l1, 300))
        cout << "yes";
    else
        cout << "no";

    return 0;
}