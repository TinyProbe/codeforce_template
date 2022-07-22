#include <bits/stdc++.h>

#define s_c         static_cast
#define d_c         dynamic_cast
#define c_c         const_cast
#define r_c         reinterpret_cast
#define m_u         make_unique
#define m_s         make_shared
#define m_p         make_pair
#define mmap        multimap
#define mset        multiset
#define u_map       unordered_map
#define u_set       unordered_set
#define u_mmap      unordered_multimap
#define u_mset      unordered_multiset
#define x           first
#define y           second
#define fastio      cin.tie(nullptr)->sync_with_stdio(false)
#define setpre(d)   cout << fixed << setprecision(d)
#define pass

using namespace std;

template <class T>          T           rand(const T& = T(1), const T& = T(100));
template <class T = string> T           scan();
template <class T = string> vector<T>   scan_vector(const int&);
template <class T = string> void        print(const T& = T(), const string& = "\n");
template <class T>          void        print_vector(const vector<T>&, const string& = " ");
template <class T>          void        swap(T&, T&);
template <class T>          T           gcd(T, T);
template <class T>          T           lcm(const T&, const T&);
template <class T>          T           psum(const T&);

template <class T> T rand(const T& mn, const T& mx) {
    static mt19937 gnt((random_device())());
    return (uniform_int_distribution<T>(mn, mx))(gnt);
}
template <class T> T scan() {
    static T tmp;
    cin >> tmp;
    return tmp;
}
template <class T> vector<T> scan_vector(const int& n) {
    vector<T> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = scan<T>();
    return v;
}
template <class T> void print(const T& obj, const string& end) {
    cout << obj << end;
}
template <class T> void print_vector(const vector<T>& v, const string& end) {
    for (int i = 0; i < (int)v.size(); ++i)
        print(v[i], end);
    if (end != "\n")
        print();
}
template <class T> void swap(T& a, T& b) {
    if (&a == &b)
        return ;
    a ^= b;
    b ^= a;
    a ^= b;
}
template <class T> T _gcd(T a, T b) {
    if (a < b)
        _swap(a, b);
    while (b) {
        a %= b;
        _swap(a, b);
    }
    return a;
}
template <class T> T _lcm(const T& a, const T& b) {
    return a * b / _gcd(a, b);
}
template <class T> T _ps(const T& n) {
    return (n * n + n) / 2;
}

int	main(void)
{
    fastio;
    setpre(10);
    for (int tc = (0 ? 1 : scan<int>()); tc; --tc)
    {
        auto n = scan<int>();
        auto a = scan_vector(n);
        print_vector(a);
    }
}
