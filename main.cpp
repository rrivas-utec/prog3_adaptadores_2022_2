#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <functional>
using namespace std;

void ejemplo_1_stack() {
    stack<int> s1;
    s1.push(1);
    s1.push(15);
    s1.push(29);
    while(!s1.empty()) {
        cout << s1.top() << endl;
        s1.pop();
    }
}

void ejemplo_2_stack() {
    deque<int> dq = {1, 15, 29};
    stack<int> s1(dq);
    while(!s1.empty()) {
        cout << s1.top() << endl;
        s1.pop();
    }
}

void ejemplo_3_stack() {
    vector<int> vc = {1, 15, 29};
    stack<int, vector<int>> s1(vc);
    while(!s1.empty()) {
        cout << s1.top() << endl;
        s1.pop();
    }
}

void ejemplo_4_stack() {
    vector<int> vc = {1, 15, 29};
    stack<int> s1(begin(vc), end(vc));  // Internamente utiliza el deque
    while(!s1.empty()) {
        cout << s1.top() << endl;
        s1.pop();
    }
}

void ejemplo_1_prior_queue() {
    priority_queue<int> pq;
    vector<int> v = {2, 4, 1, 3, 11, 5, 6};
    for (const auto& item: v)
        pq.push(item);
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

bool mayor_que(int a, int b) {
    return a > b;
}

bool menor_que(int a, int b) {
    return a < b;
}

void ejemplo_2_prior_queue() {
    // less         --> Funciones objeto
    // greater
//    priority_queue<int, vector<int>, bool (*)(int a, int b)> pq(mayor_que);
//    priority_queue<int, vector<int>, function<bool(int, int)>> pq(mayor_que);
    priority_queue<int, vector<int>, greater<>> pq;
    vector<int> v = {2, 4, 1, 3, 11, 5, 6};
    for (const auto& item: v)
        pq.push(item);

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

struct Persona {
    string nombre;
    int edad = 0;
    bool operator>(const Persona& other) const {
        return nombre > other.nombre;
    }
    bool operator<(const Persona& other) const {
        return nombre < other.nombre;
    }
    friend ostream& operator<<(ostream& os, const Persona& p) {
        os << p.nombre << " " << p.edad;
        return os;
    }
};

void ejemplo_3_prior_queue() {
    priority_queue<Persona, vector<Persona>, greater<>> pq;
    vector<Persona> v = {
            Persona{"Jose", 10},
            Persona{"Ana", 15},
            Persona{"Alfredo", 65},
            Persona{"Carmela", 50}
    };
    for (const auto& item: v)
        pq.push(item);

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    cout << endl;
}


void ejemplo_4_prior_queue() {
    auto compare_mayor = [](const Persona& a, const Persona& b) {
        return a.edad > b.edad;
    };
    auto compare_menor = [](const Persona& a, const Persona& b) {
        return a.edad < b.edad;
    };

    priority_queue<Persona, vector<Persona>,
            function<bool(const Persona&, const Persona&)>> pq(compare_mayor);
    vector<Persona> v = {
            Persona{"Jose", 10},
            Persona{"Ana", 75},
            Persona{"Alfredo", 65},
            Persona{"Carmela", 50}
    };
    for (const auto& item: v)
        pq.push(item);

    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    cout << endl;
}

int main() {
//    ejemplo_4_stack();
//    ejemplo_1_prior_queue();
//    ejemplo_2_prior_queue();
//    ejemplo_3_prior_queue();
    ejemplo_4_prior_queue();
    return 0;
}
