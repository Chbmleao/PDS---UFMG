#include "ListaProcessos.hpp"

void ListaProcessos::adicionar_processo(Processo* proc){

    Processo* current = head;
    Processo* previous = nullptr;

    if (head == nullptr){
        head = proc;
        tail = proc;
        return;
    }

    while(current != nullptr){
        if (proc->_prioridade > head->_prioridade){ //prioridade maior que head
            proc->next = head;
            head = proc;
            return;
        } else if(proc->_prioridade > current->_prioridade){
            proc->next = previous->next;
            previous->next = proc;
            return;
        } else if(proc->_prioridade <= tail->_prioridade) {
            tail->next = proc;
            tail = proc;
            return;
        }
        previous = current;
        current = current->next;
    }
}

Processo* ListaProcessos::remover_processo_maior_prioridade(){
    Processo* aux = head;
    head = head->next;
    return aux;
}

Processo* ListaProcessos::remover_processo_menor_prioridade(){
    Processo* final = tail;
    Processo* aux = head;
    while (aux != nullptr){
        if(aux->next == tail){
            tail = aux;
            aux->next = nullptr;
            break;
        }    
        aux = aux->next;
    }
    return final;
}

Processo* ListaProcessos::remover_processo_por_id(int id){
    Processo* aux = head;
    Processo* anterior = nullptr;
    Processo* posterior = nullptr;

    while (aux != nullptr)
    {
        if(aux->_id == id && aux == head) //quando remove o head
            return remover_processo_maior_prioridade();
        
        if (aux->_id == id && aux == tail) // quando remove o tail    
            return remover_processo_menor_prioridade();
        
        if(aux->next != nullptr && aux->next->_id == id )
            anterior = aux;
        if(aux->_id == id)
        {
            posterior = aux->next;
            anterior->next = posterior;
            return aux;
        }
        aux = aux->next;
    }
    return nullptr;
}

void ListaProcessos::imprimir_lista(){
    Processo *aux = head;
    while (aux != nullptr)
    {
        aux->imprimir_dados();
        aux = aux->next;
    }
}