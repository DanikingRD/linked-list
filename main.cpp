#include <iostream>

using namespace std;

/*
 * ENUNCIADO: LinkedList
 * INTEGRANTES: 1113684 - Clay Manuel Gomera Arias
 *              1114116 - Jean Carlos Araujo Molina
 *              1116906 - Gabriel Mejía Acosta
 *              1114441 - Rafael Eduardo Peralta Pimentel
 *              1114814 - Hadelin Maria García Cedano
 *              1114950 - Elian Gabriel Villegas Báez
 *              1116614 - Luis Daniel de la Cruz García
 *              1116623 - Aquilenyi Suero de los Santos
 * FECHA: 11/09/2023 <== Fecha de realización
 */

struct Node {
  int value;
  Node *next;
};

struct LinkedList {

private:
  // Puntero al nodo inicial.
  Node *head;
  // Cantidad de nodos
  unsigned int length;

public:
  LinkedList() {
    head = nullptr;
    length = 0;
  }

  /// Inserta un elemento a la lista.
  void insert(int value) {
    // 1) Creamor un nuevo nodo
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;

    // Nodo que recorre la lista
    Node *index = this->head;
    // Nodo previo al `index`
    Node *prev = nullptr;

    // 2) Recorrer la lista
    while (index != nullptr && index->value < value) {
      prev = index;
      index = index->next;
    }
    if (this->head == index) {
      // Solo ocurre cuando la lista esta vacia.
      this->head = newNode;
    } else {
      prev->next = newNode;
    }

    newNode->next = index;
    this->length++;
  }

  bool remove(int value) {
    if (isEmpty()) {
      return false;
    }
  
    Node *index = this->head;
    Node *prev = nullptr;
    bool removed = false;

    // If the index is null it means that either the list is empty
    // or we traversed the whole list and didn't find the value.
    while (index != nullptr) {

      if (index->value == value) {
        // Remove the current node because it matches the value
        Node *currentNode = index;

        // Move the index to the next node
        index = index->next;

        // If the previous node is null, its because this is the first node
        // In that case we can move the front.
        if (prev == nullptr) {
          this->head = index;
        } else {
          // Otherwise, update the previous node's next pointer
          prev->next = index;
        }
        delete currentNode;
        this->length--;
        removed = true;
      } else {
        // Otherwise move `prev` and `index` to the next node.
        prev = index;
        index = index->next;
      }
    }

    return removed;
  }

  bool contains(int val) {
    Node *i = this->head;
    while (i != nullptr && i->value <= val) {
      if (i->value == val) {
        return true;
      }
      i = i->next;
    }
    return false;
  }

  void clear() {
    while (this->head != nullptr) {
      Node *i = this->head;
      this->head = i->next;
      delete i;
    }
    this->length = 0;
  }

  bool isEmpty() const { return this->length == 0; }

  string toString() {
    if (isEmpty())
      return " * La lista esta vacia";
    string result;
    Node *i = this->head;

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

void makeRemove(LinkedList *list) {
  cout << "Ingrese el valor a eliminar: ";
  int value = readInt();
  if (list->remove(value)) {
    cout << " * El valor " << value << " ha sido eliminado de la lista."
         << endl;
  } else {
    cout << " * El valor " << value << " no se encuentra en la lista." << endl;
  }
}

void checkIfContains(LinkedList *list) {
  cout << "Ingrese el valor a buscar: ";
  int value = readInt();
  if (list->contains(value)) {
    cout << " * El valor " << value << " si se encuentra en la lista." << endl;
  } else {
    cout << " * El valor " << value << " no se encuentra en la lista." << endl;
  }
}
void clearList(LinkedList *list) {
  if (list->isEmpty())
    return;
  list->clear();
  cout << " * La lista ha sido limpiada. " << endl;
}
void run() {
  LinkedList *list = new LinkedList();
  while (true) {

    cout << "Presione: \n"
         << "   0) - Para salir del programa.\n"
         << "   1) - Para ingresar un elemento a la lista (insert).\n"
         << "   2) - Para eliminar un elemento de la lista (remove).\n"
         << "   3) - Para verificar si un elemento existe (contains).\n"
         << "   4) - Para mostrar los elementos de la lista (toString).\n"
         << "   5) - Para limpiar la lista (clear).\n"
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
    case 2:
      makeRemove(list);
      break;
    case 3:
      checkIfContains(list);
      break;
    case 4:
      break;
    case 5:
      clearList(list);
      break;
    default:
      cout << "La opcion " << option << " no existe\n.";
    }
    cout << list->toString() << endl;
    cout << endl;
  }
  delete list;
}

int main() {
  cout << "Bienvenido al programa de Listas Enlazadas." << endl;
  run();
  return 0;
}
