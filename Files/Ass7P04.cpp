void splitCircularList(Node* head, Node** head1, Node** head2) {
    if (!head) return;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1 = head;
    *head2 = slow->next;

    fast = (fast->next == head) ? fast : fast->next;

    fast->next = *head2;
    slow->next = *head1;
}
