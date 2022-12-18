// 81. Multiply two numbers represented by Linked Lists

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

int multiplyOfTwoList(ListNode *list1, ListNode *list2)
{
    int number1 = 0;
    int number2 = 0;

    while (list1 != NULL)
    {
        number1 = (number1 * 10) + list1->data;
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        number2 = (number2 * 10) + list2->data;
        list2 = list2->next;
    }

    return number1 * number2;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, 3);
    appendNode(l1, 2);
    appendNode(l1, 1);

    ListNode *l2 = NULL;

    appendNode(l2, 1);
    appendNode(l2, 2);

    cout << multiplyOfTwoList(l1, l2);

    return 0;
}