Node *sortedMerge(Node *first, Node *second)
{
    Node *third, *last, *temp;
    if (first->data < second->data)
    {
        third = last = first;
        temp = third;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        temp = third;
        second = second->next;
        last->next = NULL;
    }
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first != NULL)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}