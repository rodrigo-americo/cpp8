# C++ Module 08 — Containers Templateados, Iteradores, Algoritmos

## Sobre o Módulo

Este módulo marca a liberação completa da STL. Após sete módulos de proibição, agora o uso de containers (`vector`, `list`, `map`) e algoritmos (`<algorithm>`) não só é permitido como **obrigatório**. Código que funcione sem usar a STL recebe nota ruim.

O fio condutor dos três exercícios é um só: **iteradores são a linguagem universal da STL**. Qualquer função do `<algorithm>` fala com qualquer container através deles.

---

## Exercícios

### ex00 — Easy Find

Função template que busca a primeira ocorrência de um inteiro em qualquer container STL.

**Conceitos:** `template <typename T>`, `std::find`, `typename T::iterator`, `std::runtime_error`

**A chave:** `std::find` não conhece containers — só recebe `begin()` e `end()`. Por isso a função aceita `vector`, `list` ou qualquer outro container sem mudar uma linha.

```
easyfind(container, valor) → iterator ou exception
```

---

### ex01 — Span

Classe que armazena até N inteiros e calcula a menor e maior distância entre eles.

**Conceitos:** `std::vector<int>` no lugar de `int*`, `std::sort`, `std::min_element`, `std::distance`, `_numbers.insert()` com range de iteradores

**Métodos:**
- `addNumber(int n)` — adiciona um número, lança exceção se cheio
- `shortestSpan()` — ordena e percorre pares vizinhos buscando a menor diferença
- `longestSpan()` — `back() - front()` após ordenar
- `addRange(begin, end)` — bônus: adiciona vários números via range de iteradores em uma única chamada

**Por que vector e não int\*:**
Sem `new`, sem `delete`, sem gerenciar memória. O `vector` cuida de tudo e ainda fornece `begin()`/`end()` para os algoritmos da STL.

---

### ex02 — Abominação Mutada (MutantStack)

`std::stack` é um dos únicos containers STL **sem iteradores** — decisão intencional para forçar disciplina LIFO. Este exercício quebra essa restrição.

**Conceitos:** herança de container STL, membro protegido `c`, `typedef typename`

**A sacada:** `std::stack` usa `std::deque` internamente como membro protegido chamado `c`. O `std::deque` *tem* `begin()` e `end()` — o `std::stack` só se recusava a expô-los. `MutantStack` herda e abre essa porta.

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return this->c.begin(); }
        iterator end()   { return this->c.end();   }
};
```

Como nenhum membro novo foi adicionado, a forma canônica ortodoxa é gerada automaticamente pelo compilador.

---

## Compilação

```bash
# ex00
cd ex00 && make

# ex01
cd ex01 && make

# ex02
cd ex02 && make
```

## Regras do Módulo

- STL **obrigatória** — containers e `<algorithm>` sempre que aplicável
- C++98 — sem C++11 ou Boost
- Forma Canônica Ortodoxa em todas as classes
- Sem `printf`, `*alloc`, `free`
- Sem `using namespace` e `friend`
- Headers com include guards obrigatórios
- Implementações de template no `.hpp` ou `.tpp` (nunca em `.cpp`)