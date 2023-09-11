#include <iostream>

using namespace std;

struct Node {
  int value;
  Node *next;
};

struct LinkedList {

private:
  Node *front;
  unsigned int length;

public:
  LinkedList() {
    front = nullptr;
    length = 0;
  }

  void insert(int value) {
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;
    // Maintain an ascending order.

    Node *i = this->front;

    while (i->next != nullptr) {
      int nodeValue = i->value;
      i = i->next;
    }

    this->length++;
  }

  void remove(int value) { this->length--; }
  int indexOf(int value) {
    if (isEmpty())
      return -1;

    return 0;
  }

  bool isEmpty() const { return this->length == 0; }

  string toString() { return ""; }
};

int main() {

  LinkedList *list = new LinkedList();

  delete list;
}
