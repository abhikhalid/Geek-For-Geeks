// 66. Decimal Equivalent of Binary Linked List

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

int i = 0;
int decimalEquivalent(ListNode *list)
{
    if (list == NULL)
        return 0;

    return decimalEquivalent(list->next) + list->data * pow(2, i++);
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 0);
    appendNode(l1, 0);
    appendNode(l1, 0);
    appendNode(l1, 1);
    appendNode(l1, 1);
    appendNode(l1, 0);
    appendNode(l1, 0);
    appendNode(l1, 1);
    appendNode(l1, 0);

    displayList(l1);

    cout << decimalEquivalent(l1) << endl;

    return 0;
}