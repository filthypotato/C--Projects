#include <iostream>
#include <string>



struct Node {
  std::string song{};
  Node* next{};
};

int main() {

  Node* first = new Node{"Song A", nullptr};
  Node* second = new Node{"Song B", nullptr};
  first->next = second;

  Node* current = first;
  Node* newSong = new Node{"New Song", nullptr};

  newSong->next = current->next;
  current->next = newSong;

  Node* playing = first;
  while (playing != nullptr) {
    std::cout << playing->song << std::endl;
    playing = playing->next;
  }

}
