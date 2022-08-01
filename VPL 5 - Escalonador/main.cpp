// NÃO ALTERE ESSA LINHA
//#include "avaliacao_basica_escalonador.hpp"
#include "ListaProcessos.hpp"
#include <string>


int main() {

    ListaProcessos lista;
    string input;

    while (cin >> input)
    {
        if(input == "a")
        {
            int id, prioridade;
            string nome;
            cin >> id;
            cin >> nome;
            cin >> prioridade;
            Processo* proc = new Processo(id, nome, prioridade);

            lista.adicionar_processo(proc);
        } 
        else if (input == "m")
            lista.remover_processo_maior_prioridade();

        else if (input == "n")
            lista.remover_processo_menor_prioridade();

        else if (input == "r")
        {
            int id;
            cin >> id;
            lista.remover_processo_por_id(id);
        }
        else if (input == "p")
            lista.imprimir_lista();

        //else if(input == "b")
           //avaliacao_basica();
    }
    

    return 0;
}