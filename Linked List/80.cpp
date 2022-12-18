// 80. Check whether the length of given linked list is Even or Odd

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

bool isLengthofListEvenOrOdd(ListNode *list)
{
    int count = 0;

    while (list != NULL)
    {
        count++;
        list = list->next;
    }
    if (count % 2 == 0)
        return true;
    return false;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 3);
    appendNode(l1, 4);

    if (isLengthofListEvenOrOdd(l1))
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }

    return 0;
}