#include "List.hpp"
int main() {

    List lista;
    lista.insertNode(111);
    lista.insertNode(222);
    lista.display();
    cout << "Valor 222 existe? " << lista.verifyNode(222) << endl;

    lista.removeNode(222);
    lista.display();
    cout << "Valor 222 existe?" << lista.verifyNode(222) << endl;

    return 0;
}