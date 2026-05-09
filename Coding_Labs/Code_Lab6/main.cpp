/*
Date: 04/25/26
Program: Asks user for linked list size, user inputs data, inserts, deletes, and displays given data

Revisions:
*/

#include <iostream>

// Node struct
struct Node {
  int data{};
  Node* next;
};

// fwd declarations
void createLinkedList(Node*& head, int size);
void displayLinkedList(Node* head);
void insertNode(Node*& head, int position, int data);
void deleteNode(Node*& head, int position);


// Main function
int main() {
  Node* head = nullptr;

  int size{};
  int position{};
  int data{};

  std::cout << "Enter size of linked list: ";
  std:: cin >> size;

  createLinkedList(head, size);

  std::cout << std::endl;
  displayLinkedList(head);

  std::cout << "\nEnter position for insertion: ";
  std::cin >> position;

  std::cout << "\nEnter data: ";
  std::cin >> data;

  insertNode(head, position, data);

  std::cout << "\nAfter insertion:\n";
  displayLinkedList(head);

  std::cout << "\nEnter position to delete: ";
  std::cin >> position;

  deleteNode(head, position);

  std::cout << "\nAfter deletion:\n";
  displayLinkedList(head);

  return 0;

}


// Functions

// Creates linked list with user input
void createLinkedList(Node*& head, int size) {
  Node* newNode;
  Node* last = nullptr;

  for (int i = 0; i < size; i++) {
    newNode = new Node;

    std::cout << "Enter integer " << i + 1 << ": ";
    std::cin >> newNode->data;

    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
      last = newNode;
    } else {
      last->next = newNode;
      last = newNode;
    }
  }
}

// Displays the linked list
void displayLinkedList(Node* head) {
  Node* current = head;

  std::cout << "Linked list: ";

  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }

  std::cout << std::endl;
}

// Insert new node
void insertNode(Node*& head, int position, int data) {
  // added safe guard for if user inputs anything less than 1.
  if (position < 1) {
    std::cout << "Invalid position, Node could not be inserted." << std::endl;
    return;
  }

  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;

  // Inserts at the beginning
  if (position == 1) {
    newNode->next = head;
    head = newNode;
    return;
  }

  Node* current = head;

  // Moves to node before insertion
  for (int i = 1; i < position - 1 && current != nullptr; i++) {
    current = current->next;
  }

  if (current == nullptr) {
    std::cout << "Invalid position. Node could not be inserted" << std::endl;
    delete newNode;
  } else {
    newNode->next = current->next;
    current->next = newNode;
  }
}

void deleteNode(Node*& head, int position) {
  if (head == nullptr) {
    std::cout << "List is empty." << std::endl;
    return;
  }

  Node* temp;

  // Deletes the first node
  if (position == 1) {
    temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node* current = head;

  // moves to the current node before deleting
  for (int i = 1; i < position - 1 && current != nullptr; i++) {
    current = current->next;
  }

  if (current == nullptr || current->next == nullptr) {
    std::cout << "Invalid position. Could not delete Node." << std::endl;
  } else {
    temp = current->next;
    current->next = temp->next;
    delete temp;
  }
}



