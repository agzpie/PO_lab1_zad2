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
        void addToBeginning(int key);
        void addToBeginning(ListElement &element) {

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

        ListElement* getElement(int key);
        bool contains(int key);
        void removeKey(int key);
        void clearAll();
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

    myList.printList();


    return 0;
}

