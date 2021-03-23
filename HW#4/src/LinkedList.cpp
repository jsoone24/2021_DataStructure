#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int size;
};

linkedList GenerateList(int n)
{
    linkedList ll;
    Node *temp;

    for (int i = 0; i < n; i++)
    {
        temp = (Node *)malloc(sizeof(Node));

        if (ll.head == NULL)
        {
            ll.head = temp;
            ll.tail = temp;
            ll.size = 0;
        }

        temp->data = i;
        temp->next = NULL;

        ll.tail->next = temp;
        ll.tail = temp;
        ll.size++;
    }

    return ll;
}

void CopyLS2DA(int *array, linkedList ll)
{
    Node *point = ll.head;

    for (int i = 0; i < ll.size; i++)
    {
        array[i] = point->data;
        point = point->next;
    }
}

int main()
{
    linkedList LinkedList;
    int *Array;

    LinkedList = GenerateList(4);
    Array = new int[LinkedList.size];
    CopyLS2DA(Array, LinkedList);

    printf("Array = {");
    for (int i = 0; i < LinkedList.size; i++)
    {
        if (i + 1 == LinkedList.size)
            printf(" %d ", Array[i]);
        else
            printf(" %d,", Array[i]);
    }
    printf("}\n");

    delete Array;

    return 0;
}