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

    Node *index = this->front;
    Node *prev = nullptr;

    while (index != nullptr && index->value < value) {
      // traverse all the nodes until you find one whose value is >= value
      // passed in
      prev = index;
      index = index->next;
    }
    // index points to the node that should be next to [value] (x >= value) in
    // ascending order.
    if (this->front == index) {
      // This only happens when the list is empty
      this->front = newNode;
    } else {
      prev->next = newNode;
    }
    newNode->next = index;
    this->length++;
  }

  void remove(int value) {
    
    
  }
  int indexOf(int value) {
    if (isEmpty())
      return -1;

    return 0;
  }

  bool isEmpty() const { return this->length == 0; }

  string toString() {

    string result;
    Node *i = this->front;

    while (i != nullptr) {
      result += ('[' + to_string(i->value) + ']');
      if (i->next != nullptr) {
        result += " -> ";
      } else {
        result += " -> [null]";
      }
      i = i->next;
    }
    return result;
  }
};

/*
 * Lee un valor entero. Si el valor ingresado no es un entero,
 * se solicita al usuario que ingrese un valor válido.
 */
int readInt() {
  int value;
  while (!(cin >> value)) {
    cout << "Ingrese un valor válido: ";
    cin.clear();
    cin.ignore(123, '\n');
  }
  return value;
}

void makeInsert(LinkedList *list) {
  cout << "Ingrese el valor a insertar: ";
  int value = readInt();
  list->insert(value);
  cout << " * El valor " << value << " ha sido insertado a la lista." << endl;
}

void run() {
  auto *list = new LinkedList();
  while (true) {

    cout << "Presione: \n"
         << "   0) - Para salir del programa.\n"
         << "   1) - Para ingresar un valor a la lista (insert).\n"
         << "Ingrese su opción: ";

    int option = readInt();
    cout << endl;

    switch (option) {
    case 0:
      cout << "Saliendo del programa...\n";
      exit(0);
      break;
    case 1:
      makeInsert(list);
      break;
    default:
      cout << "La opcion " << option << " no existe\n.";
    }

    cout << list->toString() << endl;
  }
  delete list;
}

int main() {
  cout << "Bienvenido al programa de Listas Enlazadas." << endl;
  run();
  return 0;
}
