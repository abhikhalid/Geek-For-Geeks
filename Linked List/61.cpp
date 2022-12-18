// 61. Check if a linked list of strings forms a palindrome

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    string data;
    ListNode *next;
};

void appendNode(ListNode *&list, string value)
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

bool isPalindrome(ListNode *list)
{
    string str = "";

    while (list != NULL)
    {
        str.append(list->data);
        list = list->next;
    }

    // now check if the string is palindrome or not

    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    ListNode *l1 = NULL;

    appendNode(l1, "a");
    appendNode(l1, "bc");
    appendNode(l1, "d");
    appendNode(l1, "dcb");
    appendNode(l1, "a");

    displayList(l1);

    if (isPalindrome(l1))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}