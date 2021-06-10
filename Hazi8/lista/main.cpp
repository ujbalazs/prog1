
#include <iostream>
#include <stdexcept>

// -----------------------------
template<typename Elem> struct Link {
    Elem val;
    Link* succ;
    Link(const Elem& v = Elem{0}, Link* s = nullptr)
        : val{v}, succ{s} { }
};
// ------------------------------
template<typename Elem> class slist {
    Link<Elem>* first;
public:
    slist() : first{nullptr} { }

    ~slist()
    {
        for (Link<Elem>* p = first; p != nullptr; p = p->succ) {
            std::cout << p->val << " deleted\n";
            delete p;
        }
    }

    class iterator;

    iterator begin() { return iterator(first); }
    iterator end() { return iterator(nullptr); }

    iterator insert(iterator p, const Elem& v);
    iterator erase(iterator p);

    void push_front(const Elem& v);
    void push_back(const Elem& v);
    void pop_front();
    void pop_back();

    Elem& front();
    //Elem& back();
};
// ------------------------------
template<typename Elem>         
class slist<Elem>::iterator {
    Link<Elem>* curr;           
public:
    iterator(Link<Elem>* p) : curr{p} { }

    iterator& operator++() {curr = curr->succ; return *this; }  
    Elem& operator*() { return curr->val; }     
    Link<Elem>* operator->() { return curr; }   

    bool operator==(const iterator& b) const { return curr == b.curr; }
    bool operator!=(const iterator& b) const { return curr != b.curr; }
};
// ------------------------------
template<typename Elem>
typename slist<Elem>::iterator slist<Elem>::insert(slist<Elem>::iterator p,
        const Elem& v)
    
{
    Link<Elem>* q = new Link<Elem>{v, p->succ};
    p->succ = q;
    return iterator(q);
}
// ------------------------------
template<typename Elem>
typename slist<Elem>::iterator slist<Elem>::erase(slist<Elem>::iterator p)
{
    
}
// ------------------------------
template<typename Elem> void slist<Elem>::push_front(const Elem& v)
{
    first = new Link<Elem>{v, first};
}
// ------------------------------
template<typename Iter>
Iter high(Iter first, Iter last)
{
    Iter high = first;
    for (Iter p = first; p != last; ++p)
        if (*high < *p) high = p;
    return high;
}

void f()
{
    slist<int> lst; for (int x; std::cin >> x; ) lst.push_front(x);

    slist<int>::iterator p = high(lst.begin(), lst.end());
    std::cout << "A legnagyobb érték " << *p << '\n';
}
// ------------------------------

int main()
{
    slist<char> slc;
    slc.push_front('k');
    slc.push_front('g');
    slc.push_front('l');
    slc.push_front('u');
    slc.push_front('i');
    slc.push_front('b');
    slc.push_front('c');

    std::cout << "Original lista:\n";
    for (auto a : slc)
        std::cout << a << ' ';
    std::cout << '\n';

    std::cout << "Uj lista:\n";
    auto pi = slc.begin();
    ++pi; ++pi;
    slc.insert(pi, 'y');

    for (auto a : slc)
        std::cout << a << ' ';
    std::cout << '\n';

    //f();

}