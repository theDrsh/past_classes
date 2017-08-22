#include<iostream>
/**
 * @file doublylinkedlist.h
 *
 * @brief
 *    Template for doubly linked list class.
 *
 * @author Judy Challinger & Daniel Rush
 * @date 1/28/16
 */

#ifndef CSCI_311_DOUBLYLINKEDLIST_H
#define CSCI_311_DOUBLYLINKEDLIST_H

template <class T>
class DoublyLinkedList {

 public:
   DoublyLinkedList();
   ~DoublyLinkedList();
   void append(T* data);
   bool empty() const { return (head == nullptr); }
   void print();
   T* remove();
   T* first();
   T* next();

 private:
   class Node {
    public:
      Node();
      ~Node();
      Node(T* data);
      Node* next;
      Node* prev;
      T* data;
   };
   Node* head;
   Node* tail;
   Node* current;
};

/**
 * @brief   Node constructor.
 */
template <class T>
DoublyLinkedList<T>::Node::Node(T* data) {

    this->data = data;
    next = nullptr;
    prev = nullptr;

}

/**
 * @brief   Overloaded Node constructor.
 */
template <class T>
DoublyLinkedList<T>::Node::Node() {

    data = nullptr;
    next = nullptr;
    prev = nullptr;

}

/**
* @brief    Node destructor
*/
template<class T>
DoublyLinkedList<T>::Node::~Node()
{
    next = nullptr;
    prev = nullptr;
}
/**
 * @brief   DoublyLinkedList constructor.
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {

   head = nullptr;
   tail = nullptr;
   current = nullptr;

}

/**
 * @brief   DoublyLinkedList destructor.
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    
    current = head;
    if(head == nullptr)
    {
        return;
    }
    while(current != nullptr)
    {
        head = current->next;
        delete current->data;
        delete current;
        current = head;
    }

}

/**
 * @brief   Appends a new Node at the end of the DoublyLinkedList.
 * @param   data A pointer to the data to be stored in the new Node.
 * @return  Nothing.
 *
 * Creates a new Node to hold the data and appends the Node at the end
 * of the list. The current Node pointer is set to point to the newly
 * appended Node.
 */
template <class T>
void DoublyLinkedList<T>::append(T* data) {

    Node* newNode = new Node(data);
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        current = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        current = newNode;
        return;
    }

}

/**
 * @brief   Get the first thing on the list.
 * @return  A pointer to the data stored in the first Node on the list,
 *          or nullptr if the list is empty.
 *
 * The current pointer is set to point to the first Node in the list,
 * or nullptr if the list is empty.
 */
template <class T>
T* DoublyLinkedList<T>::first() {

    if(head == nullptr)
    {
        current = nullptr;
        return nullptr;
    }
    current = head;
    return current->data;
}

/**
 * @brief   Get the next thing on the list.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following whatever the current pointer is pointing
 *          to. If there is no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list,
 * or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::next() {
    if(head == nullptr)
    {
        return nullptr;
    }
    else if(head == tail)
    {
        return nullptr;
    }
    else if(current == tail)
    {
        return nullptr;
    }
    else
    {
        if(current == nullptr)
        {
            return nullptr;
        }
        if(current->next == nullptr)
        {
            return nullptr;
        }
        current = current->next;
        return current->data;
    }
    return nullptr;
}

/**
 * @brief   Remove the Node pointed to by the current pointer.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following the Node that was removed. If there is
 *          no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list, following
 * the Node that was removed, or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::remove()
{
    if(head == nullptr)
    {
        return nullptr;
    }
    else if(current == nullptr)
    {
        return nullptr;
    }
    else if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        return nullptr;
    }
    else if(current->next == nullptr)
    {
        current->prev->next = nullptr;
        tail = current->prev;
        delete current;
        current = nullptr;
        return nullptr;
    }
    else if(current->prev == nullptr)
    {
        if(current == nullptr || current->next == nullptr)
        {
            return nullptr;
        }
        current->next->prev = nullptr;
        head = current->next;
        delete current;
        current = head;
        return current->data;
    }
    else
    {
        if(current == nullptr || current->next == nullptr)
        {
            return nullptr;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        Node* temp = current->next;
        delete current;
        current = temp;
        return current->data;
     }
     return nullptr;
}

#endif // CSCI_311_DOUBLYLINKEDLIST_H
