#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>
#include "Span.hpp"

int main()
{
    std::srand(std::time(NULL));

    // --- Teste 1: Adição básica e spans ---
    std::cout << "=== Teste 1: Adição básica ===" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try
    {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // 6 - 3 = 3
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;    // 17 - 3 = 14
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 2: Tentar adicionar além do limite ---
    std::cout << "\n=== Teste 2: Exceção ao exceder limite ===" << std::endl;
    try
    {
        sp.addNumber(20);
    }
    catch (std::exception &e)
    {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // --- Teste 3: Span vazio ---
    std::cout << "\n=== Teste 3: Span vazio ===" << std::endl;
    Span sp2(10);
    try
    {
        sp2.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // --- Teste 4: Span com um elemento ---
    std::cout << "\n=== Teste 4: Span com um elemento ===" << std::endl;
    sp2.addNumber(42);
    try
    {
        sp2.longestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // --- Teste 5: Números negativos ---
    std::cout << "\n=== Teste 5: Números negativos ===" << std::endl;
    Span sp3(7);
    sp3.addNumber(-5);
    sp3.addNumber(10);
    sp3.addNumber(-3);
    sp3.addNumber(0);
    sp3.addNumber(8);
    sp3.addNumber(-10);
    sp3.addNumber(20);

    try
    {
        std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp3.longestSpan() << std::endl;   // 20 - (-10) = 30
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 6: Teste de performance com 10.000 números ---
    std::cout << "\n=== Teste 6: Performance com 10.000 números ===" << std::endl;
    Span sp4(10000);
    for (int i = 0; i < 10000; i++)
    {
        sp4.addNumber(std::rand() % 100000);
    }
    
    try
    {
        std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 7: Teste com 50.000 números ---
    std::cout << "\n=== Teste 7: Performance com 50.000 números ===" << std::endl;
    Span sp5(50000);
    for (int i = 0; i < 50000; i++)
    {
        sp5.addNumber(std::rand() % 1000000);
    }
    
    try
    {
        std::cout << "Shortest Span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp5.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 8: Cópia e atribuição ---
    std::cout << "\n=== Teste 8: Cópia de objetos ===" << std::endl;
    Span sp6(sp);  // Cópia via construtor
    try
    {
        std::cout << "Shortest Span (cópia): " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest Span (cópia): " << sp6.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    Span sp7(3);
    sp7.addNumber(1);
    sp7.addNumber(2);
    sp7.addNumber(3);
    
    Span sp8(5);
    sp8 = sp7;  // Atribuição
    try
    {
        std::cout << "Shortest Span (atribuído): " << sp8.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 9: addRange com vector ---
    std::cout << "\n=== Teste 9: addRange com vector ===" << std::endl;
    std::vector<int> vec = {5, 12, 3, 8, 15};
    Span sp9(10);
    try
    {
        sp9.addRange(vec.begin(), vec.end());
        std::cout << "Shortest Span: " << sp9.shortestSpan() << std::endl;  // 5 - 3 = 2
        std::cout << "Longest Span: " << sp9.longestSpan() << std::endl;    // 15 - 3 = 12
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 10: addRange com list ---
    std::cout << "\n=== Teste 10: addRange com list ===" << std::endl;
    std::list<int> lst = {100, 50, 75};
    Span sp10(5);
    try
    {
        sp10.addRange(lst.begin(), lst.end());
        std::cout << "Shortest Span: " << sp10.shortestSpan() << std::endl;  // 75 - 50 = 25
        std::cout << "Longest Span: " << sp10.longestSpan() << std::endl;    // 100 - 50 = 50
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 11: addRange excedendo limite ---
    std::cout << "\n=== Teste 11: addRange excedendo limite ===" << std::endl;
    std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7};
    Span sp11(5);
    try
    {
        sp11.addRange(vec2.begin(), vec2.end());
    }
    catch (std::exception &e)
    {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    // --- Teste 12: addRange com grande volume (10.000 números) ---
    std::cout << "\n=== Teste 12: addRange com 10.000 números ===" << std::endl;
    std::vector<int> largeVec;
    for (int i = 0; i < 10000; i++)
    {
        largeVec.push_back(std::rand() % 100000);
    }
    Span sp12(10000);
    try
    {
        sp12.addRange(largeVec.begin(), largeVec.end());
        std::cout << "Shortest Span: " << sp12.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp12.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    // --- Teste 13: Combinando addNumber e addRange ---
    std::cout << "\n=== Teste 13: Combinando addNumber e addRange ===" << std::endl;
    std::vector<int> vec3 = {20, 30, 40};
    Span sp13(8);
    sp13.addNumber(10);
    sp13.addNumber(5);
    try
    {
        sp13.addRange(vec3.begin(), vec3.end());
        std::cout << "Shortest Span: " << sp13.shortestSpan() << std::endl;  // 10 - 5 = 5
        std::cout << "Longest Span: " << sp13.longestSpan() << std::endl;    // 40 - 5 = 35
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n=== Todos os testes concluídos ===" << std::endl;
    return 0;
}

