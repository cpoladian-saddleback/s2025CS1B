int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = getLength(head);
    k %= len;
    if (k == 0) return head;

    Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head; // Make circular

    int stepsToNewHead = len - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
