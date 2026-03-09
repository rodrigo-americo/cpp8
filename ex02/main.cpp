#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    // --- Teste 1: Exemplo do enunciado (obrigatório) ---
    std::cout << "=== Teste 1: Exemplo do enunciado ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl; // 17
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl; // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // o enunciado pede isso: MutantStack deve poder inicializar um std::stack
    std::stack<int> s(mstack);

    // --- Teste 2: Comparação com std::list (exigido pelo enunciado) ---
    // A saída deve ser idêntica ao teste 1
    std::cout << "\n=== Teste 2: Mesma sequência com std::list ===" << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(3);   // depois do pop do 17, sobrou 5, depois push 3, 5, 737, 0
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    // --- Teste 3: empty() e size() ---
    std::cout << "\n=== Teste 3: empty e size ===" << std::endl;
    MutantStack<int> ms2;
    std::cout << "Vazio: " << ms2.empty() << std::endl; // 1 (true)
    ms2.push(42);
    ms2.push(99);
    std::cout << "Size: " << ms2.size() << std::endl;    // 2
    std::cout << "Top: " << ms2.top() << std::endl;      // 99

    // --- Teste 4: Cópia e atribuição ---
    std::cout << "\n=== Teste 4: Cópia e atribuição ===" << std::endl;
    MutantStack<int> ms3(ms2);  // construtor cópia gerado pelo compilador
    std::cout << "Cópia - Top: " << ms3.top() << std::endl; // 99

    MutantStack<int> ms4;
    ms4 = ms2;  // operator= gerado pelo compilador
    std::cout << "Atribuido - Top: " << ms4.top() << std::endl; // 99

    // --- Teste 5: Iteração com range-based feel (incremento/decremento) ---
    std::cout << "\n=== Teste 5: Iteradores avançados ===" << std::endl;
    MutantStack<int> ms5;
    ms5.push(10);
    ms5.push(20);
    ms5.push(30);
    ms5.push(40);
    ms5.push(50);

    MutantStack<int>::iterator fw = ms5.begin();
    MutantStack<int>::iterator bk = ms5.end();
    --bk; // aponta pro último elemento

    std::cout << "Primeiro: " << *fw << std::endl; // 10
    std::cout << "Último:   " << *bk << std::endl; // 50

    std::cout << "\n=== Todos os testes concluídos ===" << std::endl;
    return 0;
}