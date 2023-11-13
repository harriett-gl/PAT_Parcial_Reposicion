#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    Node<char>* current = head;
    Node<char>* next = nullptr;
    Node<char>* prev = nullptr;
    int sz = 0;

    Node<char>* temp = head;
    while (temp != nullptr && sz < k) {
        temp = temp->next;
        sz++;
    }


    if (sz == k) {
        while (sz > 0) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            sz--;
        }


        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
    else {
        return head;
    }
}