#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    // --- Teste 1: vector com elemento existente ---
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(42);
    vec.push_back(7);
    vec.push_back(99);

    std::cout << "=== Teste com vector ===" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Encontrado: " << *it << std::endl; // *it desreferencia o iterador
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 2: vector sem elemento (deve lançar exceção) ---
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 1000);
        std::cout << "Encontrado: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // --- Teste 3: list — mesmo template, container diferente ---
    // Aqui fica claro o poder do template: easyfind não sabe que é uma list,
    // só precisa que T tenha begin(), end() e seja compatível com std::find
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::cout << "\n=== Teste com list ===" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Encontrado: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 4: list sem elemento ---
    try
    {
        std::list<int>::iterator it = easyfind(lst, 99);
        std::cout << "Encontrado: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    return 0;
}
