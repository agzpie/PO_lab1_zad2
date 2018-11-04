#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

class ListElement {
private:
    int key;
    ListElement *next;

public:
    int getKey() {
        return key;
    }

    ListElement* getNext() {
        return next;
    }

    void setNext(ListElement *element) {
        this->next = element;
    }

    ListElement(int key) {
        this->next = NULL;
        this->key = key;
    }

    ~ListElement() {}
};

class List {
    private:
        ListElement *firstElement;
        int size;

    public:
        void addToBeginning(ListElement *element) {
            if (firstElement == NULL) {
                firstElement = element;
                size++;
                return;
            }

            ListElement *node = firstElement;
            element->setNext(node);
            firstElement = element;
            size++;
        }

        void addToBeginning(int key) {
            ListElement* element = new ListElement(key);
            this->addToBeginning(element);
        }

        void addToEnd(ListElement *element) {
            if (firstElement == NULL) {
                firstElement = element;
                size++;
                return;
            }

            ListElement *node = firstElement;

            while (node->getNext() != NULL) {
                node = node->getNext();
            }
            node->setNext(element);

            size++;
        }

        void addToEnd(int key) {
            ListElement* element = new ListElement(key);
            this->addToEnd(element);
        }

        ListElement* getElement(int key) {
            if (firstElement == NULL) {
                return NULL;
            }
            ListElement *node = firstElement;
            do {
                if (node->getKey() == key) {
                    return node;
                }
                node = node->getNext();
            } while (node != NULL);
            return NULL;
        }

        bool contains(int key) {
            if (firstElement == NULL) {
                return false;
            }
            ListElement *node = firstElement;
            do {
                if (node->getKey() == key) {
                    return true;
                }
                node = node->getNext();
            } while (node != NULL);
            return false;
        }
        void removeKey(int key) {
            if (firstElement == NULL) {
                return;
            }

            ListElement *node = firstElement;
            ListElement *nextNode;

            if (firstElement->getKey() == key) {
                nextNode = node->getNext();
                firstElement = nextNode;
                delete node;
                size--;
                return;
            }

            do {
                nextNode = node->getNext();

                if (nextNode->getKey() == key) {
                    node->setNext(nextNode->getNext());
                    delete nextNode;
                    size--;
                    return;
                }

                node = node->getNext();
            } while (node != NULL);
        }

        void clearAll() {
            if (firstElement == NULL) {
                return;
            }
            ListElement *node = firstElement;
            ListElement *nextNode;

            do {
                nextNode = node->getNext();
                delete node;
                node = nextNode;
                size--;
            } while (node != NULL);

            this->firstElement = NULL;
        }

        void printList() {
            if (firstElement == NULL) {
                cout << "List = [] size = 0" << endl;
                return;
            }

            ListElement *node = firstElement;
            cout << "List = [ ";
            do {
                cout << node->getKey() << ", ";
                node = node->getNext();
            } while (node != NULL);

        cout << "]\tSize = " << this->size << endl;
        }

    List() {
        this->firstElement = NULL;
        this->size = 0;
    }
    ~List() {}
};

int main() {

    List myList;

    myList.addToEnd(1);
    myList.addToEnd(2);
    myList.addToEnd(3);
    myList.addToEnd(4);

    cout << "LISTA:" << endl;
    myList.printList();

    myList.clearAll();
    cout << "deleteing it all:" << endl;
    myList.printList();

    myList.addToEnd(5);
    myList.addToEnd(6);
    myList.addToEnd(7);
    myList.addToEnd(8);
    myList.printList();
    cout << "does it contain? ";
    cout << myList.contains(5) << endl;
    cout << "get element: ";
    ListElement* elelel = myList.getElement(7);
    cout << elelel->getKey() << endl;

    cout << "deleting a key" << endl;
    myList.removeKey(8);
    myList.printList();

    cout << "adding to the beginning" << endl;
    myList.addToBeginning(1);
    myList.printList();




    return 0;
}

