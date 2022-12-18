// 7.Find Length of a Linked List (Iterative and Recursive)

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

int getLength(ListNode *list)
{
    ListNode *tNode = list;
    int count = 0;

    while (tNode != NULL)
    {
        count++;
        tNode = tNode->next;
    }
    return count;
}

int getLengthOfList(ListNode *list)
{
    if (list == NULL)
        return 0;

    return 1 + getLengthOfList(list->next);
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 10);
    appendNode(l1, 20);
    appendNode(l1, 30);

    displayList(l1);

    cout << getLengthOfList(l1);

    return 0;
}