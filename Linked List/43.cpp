// 43. Sort a linked list of 0s, 1s and 2s

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

// 1st method (cont 0, 1, 2)

ListNode *sortList(ListNode *&list)
{
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    ListNode *tNode = list;

    while (tNode != NULL)
    {
        if (tNode->data == 0)
        {
            countZero++;
        }
        else if (tNode->data == 1)
        {
            countOne++;
        }
        else if (tNode->data == 2)
        {
            countTwo++;
        }
        tNode = tNode->next;
    }

    tNode = list;

    while (tNode != NULL)
    {

        if (countZero > 0)
        {
            tNode->data = 0;
            countZero--;
        }
        else if (countOne > 0)
        {
            tNode->data = 1;
            countOne--;
        }
        else if (countTwo > 0)
        {
            tNode->data = 2;
            countTwo--;
        }

        tNode = tNode->next;
    }

    return list;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 1);
    appendNode(l1, 1);
    appendNode(l1, 2);
    appendNode(l1, 0);
    appendNode(l1, 2);
    appendNode(l1, 0);
    appendNode(l1, 1);

    displayList(l1);

    displayList(sortList(l1));

    return 0;
}