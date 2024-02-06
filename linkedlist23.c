NODE *sort(NODE *head)
{

    NODE *p_node = NULL, *c_node = head, *n_node = head;
    for (int i = 0; i <= count; i++)
    {
        n_node = head;
        for (int j = 0; j <= count - i - 1; j++)
        {
            n_node = n_node->next;
            if (c_node->data > n_node->data)
            {
                int temp = c_node->data;
                // t_node->next = p_node->next;
                c_node->data = n_node->data;
                // p_node->next = n_node->next;
                n_node->data = temp;
                // n_node->next = t_node->next;
            }
            p_node = c_node;
            c_node = c_node->next;
        }
        p_node = NULL;
        c_node = head;
        n_node = head;
    }
    return head;
}