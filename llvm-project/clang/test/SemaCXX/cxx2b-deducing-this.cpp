// RUN: %clang_cc1 -fsyntax-only -std=c++2b -Woverloaded-virtual %s -verify


// FIXME: can we improve these diagnostics?
void f(this); // expected-error{{variable has incomplete type 'void'}} \
              // expected-error{{invalid use of 'this' outside of a non-static member function}}

void g(this auto); // expected-error{{an explicit object parameter cannot appear in a non-member function}}

auto l1 = [] (this auto) static {}; // expected-error{{an explicit object parameter cannot appear in a static lambda}}
auto l2 = [] (this auto) mutable {}; // expected-error{{a lambda with an explicit object parameter cannot be mutable}}
auto l3 = [](this auto...){}; // expected-error {{the explicit object parameter cannot be a function parameter pack}}
auto l4 = [](int, this auto){}; // expected-error {{an explicit object parameter can only appear as the first parameter of the lambda}}

struct S {
    static void f(this auto); // expected-error{{an explicit object parameter cannot appear in a static function}}
    virtual void f(this S); // expected-error{{an explicit object parameter cannot appear in a virtual function}}

    // new and delete are implicitly static
    void *operator new(this unsigned long); // expected-error{{an explicit object parameter cannot appear in a static function}}
    void operator delete(this void*); // expected-error{{an explicit object parameter cannot appear in a static function}}

    void g(this auto) const; // expected-error{{explicit object member function cannot have 'const' qualifier}}
    void h(this auto) &; // expected-error{{explicit object member function cannot have '&' qualifier}}
    void i(this auto) &&; // expected-error{{explicit object member function cannot have '&&' qualifier}}
    void j(this auto) volatile; // expected-error{{explicit object member function cannot have 'volatile' qualifier}}
    void k(this auto) __restrict; // expected-error{{explicit object member function cannot have '__restrict' qualifier}}
    void l(this auto) _Nonnull; // expected-error{{explicit object member function cannot have '' qualifie}}


    void variadic(this auto...); // expected-error{{the explicit object parameter cannot be a function parameter pack}}
    void not_first(int, this auto); // expected-error {{an explicit object parameter can only appear as the first parameter of the function}}

    S(this auto); // expected-error {{an explicit object parameter cannot appear in a constructor}}
    ~S(this S) {} // expected-error {{an explicit object parameter cannot appear in a destructor}} \
                  // expected-error {{destructor cannot have any parameters}}
};

namespace Override {
struct A {
    virtual void f(); // expected-note 2{{here}}
    virtual void g(int); // expected-note {{here}}
    virtual void h() const; // expected-note 5{{here}}
};

// CWG2553
struct B : A {
    int f(this B&, int); // expected-warning {{hides overloaded virtual function}}
    int f(this B&);  // expected-error {{an explicit object parameter cannot appear in a virtual function}}
    int g(this B&); // expected-warning {{hides overloaded virtual function}}
    int h(this B&); // expected-error {{an explicit object parameter cannot appear in a virtual function}}
    int h(this B&&); // expected-error {{an explicit object parameter cannot appear in a virtual function}}
    int h(this const B&&); // expected-error {{an explicit object parameter cannot appear in a virtual function}}
    int h(this A&); // expected-error {{an explicit object parameter cannot appear in a virtual function}}
    int h(this int); // expected-error {{an explicit object parameter cannot appear in a virtual function}}
};
}

namespace DefaultArgs {
     struct Test { void f(this const auto& = Test{}); };
    // expected-error@-1 {{the explicit object parameter cannot have a default argument}}
    auto L = [](this const auto& = Test{}){};
    // expected-error@-1 {{the explicit object parameter cannot have a default argument}}
}

struct CannotUseThis {
    int fun();
    int m;
    void f(this auto) {
        this->fun(); // expected-error{{invalid use of 'this' in a function with an explicit object parameter}}
        fun(); // expected-error {{call to non-static member function without an object argument}}
        m = 0; // expected-error {{invalid use of member 'm' in explicit object member function}}
    }
};

struct CannotUseThisBase {
  void foo();
  int n;
  static int i;
};

struct CannotUseThisDerived : CannotUseThisBase {
  void bar(this auto) {
    foo(); // expected-error {{call to non-static member function without an object argument}}
    n = 12; // expected-error {{invalid use of member 'n' in explicit object member function}}
    i = 100;
  }
};

namespace ThisInLambdaWithCaptures {

struct Test {
    Test(auto&&);
};

void test() {

    [i = 0](this Test) { }();
    // expected-error@-1 {{invalid explicit object parameter type 'ThisInLambdaWithCaptures::Test' in lambda with capture; the type must be the same as, or derived from, the lambda}}

    struct Derived;
    auto ok = [i = 0](this const Derived&) {};
    auto ko = [i = 0](this const Test&) {};
    // expected-error@-1 {{invalid explicit object parameter type 'ThisInLambdaWithCaptures::Test' in lambda with capture; the type must be the same as, or derived from, the lambda}}

    struct Derived : decltype(ok){};
    Derived dok{ok};
    dok();

    struct DerivedErr : decltype(ko){};
    DerivedErr dko{ko};
    dko();

    auto alsoOk = [](this const Test &) {};
    alsoOk();
}

struct Frobble;
auto nothingIsOkay = [i = 0](this const Frobble &) {};  // expected-note {{candidate function not viable: requires 0 non-object arguments, but 1 was provided}}
struct Frobble {} f;
void test2()  {
    nothingIsOkay(f); // expected-error {{no matching function for call to object of type}}
}

}

struct Corresponding {
    void a(this Corresponding&); // expected-note 2{{here}}
    void a(); // expected-error{{cannot be redeclared}}
    void a() &; // expected-error{{cannot be redeclared}}
    void a(this Corresponding&, int);
    void a(this Corresponding&, double);

    void b(this const Corresponding&); // expected-note 2{{here}}
    void b() const; // expected-error{{cannot be redeclared}}
    void b() const &; // expected-error{{cannot be redeclared}}

    void c(this Corresponding&&); // expected-note {{here}}
    void c() &&; // expected-error{{cannot be redeclared}}

    void d(this Corresponding&);
    void d(this Corresponding&&);
    void d(this const Corresponding&);
    void d(this const int&);
    void d(this const int);
    void d(this int);

    void e(this const Corresponding&&); // expected-note {{here}}
    void e() const &&; // expected-error{{cannot be redeclared}}

};

template <typename T>
struct CorrespondingTpl {
    void a(this CorrespondingTpl&); // expected-note 2{{here}}
    void a(); // expected-error{{cannot be redeclared}}
    void a() &; // expected-error{{cannot be redeclared}}
    void a(this Corresponding&, int);
    void a(this Corresponding&, double);
    void a(long);


    void b(this const CorrespondingTpl&); // expected-note 2{{here}}
    void b() const; // expected-error{{cannot be redeclared}}
    void b() const &; // expected-error{{cannot be redeclared}}

    void c(this CorrespondingTpl&&); // expected-note {{here}}
    void c() &&; // expected-error{{cannot be redeclared}}

    void d(this Corresponding&);
    void d(this Corresponding&&);
    void d(this const Corresponding&);
    void d(this const int&);
    void d(this const int);
    void d(this int);

    void e(this const CorrespondingTpl&&); // expected-note {{here}}
    void e() const &&; // expected-error{{cannot be redeclared}}
};

struct C {
    template <typename T>
    C(T){}
};

void func(int i) {
    (void)[=](this auto&&) { return i; }();
    (void)[=](this const auto&) { return i; }();
    (void)[i](this C) { return i; }(); // expected-error{{invalid explicit object parameter type 'C'}}
    (void)[=](this C) { return i; }(); // expected-error{{invalid explicit object parameter type 'C'}}
    (void)[](this C) { return 42; }();
    auto l = [=](this auto&) {};
    struct D : decltype(l) {};
    D d{l};
    d();
}

void TestMutationInLambda() {
    [i = 0](this auto &&){ i++; }();
    [i = 0](this auto){ i++; }();
    [i = 0](this const auto&){ i++; }(); // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}

    int x;
    const auto l1 = [x](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
    const auto l2 = [=](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}

    const auto l3 = [&x](this auto&) {
        const auto l3a = [x](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l3a(); // expected-note {{in instantiation of}}
    };

    const auto l4 = [&x](this auto&) {
        const auto l4a = [=](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l4a(); // expected-note {{in instantiation of}}
    };

    const auto l5 = [x](this auto&) {
        const auto l5a = [x](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l5a(); // expected-note {{in instantiation of}}
    };

    const auto l6 = [=](this auto&) {
        const auto l6a = [=](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l6a(); // expected-note {{in instantiation of}}
    };

    const auto l7 = [x](this auto&) {
        const auto l7a = [=](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l7a(); // expected-note {{in instantiation of}}
    };

    const auto l8 = [=](this auto&) {
        const auto l8a = [x](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l8a(); // expected-note {{in instantiation of}}
    };

    const auto l9 = [&](this auto&) {
        const auto l9a = [x](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l9a(); // expected-note {{in instantiation of}}
    };

    const auto l10 = [&](this auto&) {
        const auto l10a = [=](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
        l10a(); // expected-note {{in instantiation of}}
    };

    const auto l11 = [x](this auto&) {
        const auto l11a = [&x](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}} expected-note {{while substituting}}
        l11a();
    };

    const auto l12 = [x](this auto&) {
        const auto l12a = [&](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}} expected-note {{while substituting}}
        l12a();
    };

    const auto l13 = [=](this auto&) {
        const auto l13a = [&x](this auto&) { x = 42; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}} expected-note {{while substituting}}
        l13a();
    };

    struct S {
        int x;
        auto f() {
            return [*this] (this auto&&) {
                x = 42; // expected-error {{read-only variable is not assignable}}
                [*this] () mutable { x = 42; } ();
                [*this] (this auto&&) { x = 42; } ();
                [*this] () { x = 42; } (); // expected-error {{read-only variable is not assignable}}
                const auto l = [*this] (this auto&&) { x = 42; }; // expected-error {{read-only variable is not assignable}}
                l(); // expected-note {{in instantiation of}}

                struct T {
                    int x;
                    auto g() {
                        return [&] (this auto&&) {
                            x = 42;
                            const auto l = [*this] (this auto&&) { x = 42; }; // expected-error {{read-only variable is not assignable}}
                            l(); // expected-note {{in instantiation of}}
                        };
                    }
                };

                const auto l2 = T{}.g();
                l2(); // expected-note {{in instantiation of}}
            };
        }
    };

    const auto l14 = S{}.f();

    l1(); // expected-note {{in instantiation of}}
    l2(); // expected-note {{in instantiation of}}
    l3(); // expected-note {{in instantiation of}}
    l4(); // expected-note {{in instantiation of}}
    l5(); // expected-note {{in instantiation of}}
    l6(); // expected-note {{in instantiation of}}
    l7(); // expected-note {{in instantiation of}}
    l8(); // expected-note {{in instantiation of}}
    l9(); // expected-note {{in instantiation of}}
    l10(); // expected-note {{in instantiation of}}
    l11(); // expected-note {{in instantiation of}}
    l12(); // expected-note {{in instantiation of}}
    l13(); // expected-note {{in instantiation of}}
    l14(); // expected-note 3 {{in instantiation of}}

    {
      const auto l1 = [&x](this auto&) { x = 42; };
      const auto l2 = [&](this auto&) { x = 42; };
      l1();
      l2();
    }

    // Check that we don't crash if the lambda has type sugar.
    const auto l15 = [=](this auto&&) [[clang::annotate_type("foo")]] [[clang::annotate_type("bar")]] {
        return x;
    };

    const auto l16 = [=]() [[clang::annotate_type("foo")]] [[clang::annotate_type("bar")]] {
        return x;
    };

    l15();
    l16();
}

struct Over_Call_Func_Example {
    void a();
    void b() {
        a(); // ok, (*this).a()
    }

    void f(this const Over_Call_Func_Example&); // expected-note {{here}}
    void g() const {
        f();       // ok: (*this).f()
        f(*this);  // expected-error{{too many non-object arguments to function call}}
        this->f(); // ok
    }

    static void h() {
        f();       // expected-error{{call to non-static member function without an object argument}}
        f(Over_Call_Func_Example{});   // expected-error{{call to non-static member function without an object argument}}
        Over_Call_Func_Example{}.f();   // ok
    }

    void k(this int);
    operator int() const;
    void m(this const Over_Call_Func_Example& c) {
        c.k();     // ok
    }
};

struct AmbiguousConversion {
  void f(this int); // expected-note {{candidate function}}
  void f(this float); // expected-note {{candidate function}}

  operator int() const;
  operator float() const;

  void test(this const AmbiguousConversion &s) {
    s.f(); // expected-error {{call to member function 'f' is ambiguous}}
  }
};

struct IntToShort {
  void s(this short);
  operator int() const;
  void test(this const IntToShort &val) {
    val.s();
  }
};

struct ShortToInt {
  void s(this int);
  operator short() const;
  void test(this const ShortToInt &val) {
    val.s();
  }
};

namespace arity_diagnostics {
struct S {
    void f(this auto &&, auto, auto); // expected-note {{requires 2 non-object arguments, but 0 were provided}}
    void g(this auto &&, auto, auto); // expected-note {{requires 2 non-object arguments, but 3 were provided}}
    void h(this auto &&, int, int i = 0); // expected-note {{requires at least 1 non-object argument, but 0 were provided}}
    void i(this S&&, int); // expected-note 2{{declared here}}
};

int test() {
    void(*f)(S&&, int, int) = &S::f;
    f(S{}, 1, 2);
    f(S{}, 1); // expected-error {{too few arguments to function call, expected 3, have 2}}
    f(S{}); // expected-error {{too few arguments to function call, expected 3, have 1}}
    f(S{}, 1, 2, 3); //expected-error {{too many arguments to function call, expected 3, have 4}}

    S{}.f(1, 2);
    S{}.f(); //  expected-error{{no matching member function for call to 'f'}}
    S{}.g(1,2,3); // expected-error {{no matching member function for call to 'g'}}
    S{}.h(); // expected-error {{no matching member function for call to 'h'}}
    S{}.i(); // expected-error {{too few non-object arguments to function call, expected 1, have 0}}
    S{}.i(1, 2, 3); // expected-error {{too many non-object arguments to function call, expected 1, have 3}}
}

}

namespace AddressOf {

struct s {
    static void f(int);
    void f(this auto &&) {}
    void g(this s &&) {};

    void test_qual() {
        using F = void(s&&);
        F* a = &f; // expected-error {{must explicitly qualify name of member function when taking its address}}
        F* b = &g; // expected-error {{must explicitly qualify name of member function when taking its address}}
        F* c = &s::f;
        F* d = &s::g;
    }
};

void test() {
    using F = void(s&&);
    F* a = &s::f;
    F* b = &s::g;
    a(s{});
    b(s{});
}

}

namespace std {
  struct strong_ordering {
    int n;
    constexpr operator int() const { return n; }
    static const strong_ordering equal, greater, less;
  };
  constexpr strong_ordering strong_ordering::equal = {0};
  constexpr strong_ordering strong_ordering::greater = {1};
  constexpr strong_ordering strong_ordering::less = {-1};
}

namespace operators_deduction {

template <typename T, typename U>
constexpr bool is_same = false;

template <typename T>
constexpr bool is_same<T, T> = true;

template <template <typename> typename T>
struct Wrap {
void f();
struct S {
    operator int(this auto&& self) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    Wrap* operator->(this auto&& self) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return new Wrap();
    }
    int operator[](this auto&& self, int) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    int operator()(this auto&& self, int) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    int operator++(this auto&& self, int) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    int operator++(this auto&& self) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    int operator--(this auto&& self, int) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    int operator--(this auto&& self) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    int operator*(this auto&& self) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return 0;
    }
    bool operator==(this auto&& self, int) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return false;
    }
    bool operator<=>(this auto&& self, int) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return false;
    }
    bool operator<<(this auto&& self, int b) {
        static_assert(is_same<decltype(self), typename T<S>::type>);
        return false;
    }
};
};

template <typename T>
struct lvalue_reference {
    using type = T&;
};
template <typename T>
struct const_lvalue_reference {
    using type = const T&;
};
template <typename T>
struct volatile_lvalue_reference {
    using type = volatile T&;
};
template <typename T>
struct rvalue_reference {
    using type = T&&;
};
template <typename T>
struct const_rvalue_reference {
    using type = const T&&;
};


void test() {
    {
        Wrap<lvalue_reference>::S s;
        s++;
        s.operator++(0);
        ++s;
        s.operator++();
        s--;
        s.operator--(0);
        --s;
        s.operator--();
        s[0];
        s.operator[](0);
        s(0);
        s.operator()(0);
        *s;
        s.operator*();
        s->f();
        s.operator->();
        int i = s;
        (void)(s << 0);
        s.operator<<(0);
        (void)(s == 0);
        s.operator==(0);
        (void)(s <=> 0);
        s.operator<=>(0);
    }
    {
        const Wrap<const_lvalue_reference>::S s;
        s++;
        s.operator++(0);
        ++s;
        s.operator++();
        s--;
        s.operator--(0);
        --s;
        s.operator--();
        s[0];
        s.operator[](0);
        s(0);
        s.operator()(0);
        *s;
        s.operator*();
        s->f();
        s.operator->();
        int i = s;
        (void)(s << 0);
        s.operator<<(0);
        (void)(s == 0);
        s.operator==(0);
        (void)(s <=> 0);
        s.operator<=>(0);
    }
    {
        volatile Wrap<volatile_lvalue_reference>::S s;
        s++;
        s.operator++(0);
        ++s;
        s.operator++();
        s--;
        s.operator--(0);
        --s;
        s.operator--();
        s[0];
        s.operator[](0);
        s(0);
        s.operator()(0);
        *s;
        s.operator*();
        s->f();
        s.operator->();
        int i = s;
        (void)(s << 0);
        s.operator<<(0);
        (void)(s == 0);
        s.operator==(0);
        (void)(s <=> 0);
        s.operator<=>(0);
    }
    {
        Wrap<rvalue_reference>::S s;
        using M = Wrap<rvalue_reference>::S&&;
        ((M)s)++;
        ((M)s).operator++(0);
        ++((M)s);
        ((M)s).operator++();
        ((M)s)--;
        ((M)s).operator--(0);
        --((M)s);
        ((M)s).operator--();
        ((M)s)[0];
        ((M)s).operator[](0);
        ((M)s)(0);
        ((M)s).operator()(0);
        *((M)s);
        ((M)s).operator*();
        ((M)s)->f();
        ((M)s).operator->();
        int i = ((M)s);
        (void)(((M)s) << 0);
        ((M)s).operator<<(0);
        (void)(((M)s) == 0);
        ((M)s).operator==(0);
        (void)(((M)s) <=> 0);
        ((M)s).operator<=>(0);
    }
}
}

namespace conversions {
//[over.best.ics]
struct Y { Y(int); }; //expected-note 3{{candidate}}
struct A { operator int(this auto&&); };  //expected-note {{candidate}}
Y y1 = A();   // expected-error{{no viable conversion from 'A' to 'Y'}}

struct X { X(); }; //expected-note 3{{candidate}}
struct B { operator X(this auto&&); };
B b;
X x{{b}}; // expected-error{{no matching constructor for initialization of 'X'}}

struct T{}; // expected-note 2{{candidate constructor}}
struct C {
    operator T (this int); // expected-note {{candidate function not viable: no known conversion from 'C' to 'int' for object argument}}
    operator int() const; // expected-note {{candidate function}}
};

void foo(C c) {
   T d = c; // expected-error {{no viable conversion from 'C' to 'T'}}
}

}

namespace surrogate {
using fn_t = void();
struct C {
    operator fn_t * (this C const &);
};

void foo(C c) {
   c();
}

}


namespace GH69838 {
struct S {
  S(this auto &self) {} // expected-error {{an explicit object parameter cannot appear in a constructor}}
  virtual void f(this S self) {} // expected-error {{an explicit object parameter cannot appear in a virtual function}}
  void g(this auto &self) const {} // expected-error {{explicit object member function cannot have 'const' qualifier}}
  void h(this S self = S{}) {} // expected-error {{the explicit object parameter cannot have a default argument}}
  void i(int i, this S self = S{}) {} // expected-error {{an explicit object parameter can only appear as the first parameter of the function}}
  ~S(this S &&self); // expected-error {{an explicit object parameter cannot appear in a destructor}} \
                     // expected-error {{destructor cannot have any parameters}}

  static void j(this S s); // expected-error {{an explicit object parameter cannot appear in a static function}}
};

void nonmember(this S s); // expected-error {{an explicit object parameter cannot appear in a non-member function}}

int test() {
  S s;
  s.f();
  s.g();
  s.h();
  s.i(0);
  s.j({});
  nonmember(S{});
}

}

namespace GH69962 {
struct S {
    S(const S&);
};

struct Thing {
    template<typename Self, typename ... Args>
    Thing(this Self&& self, Args&& ... args) { } // expected-error {{an explicit object parameter cannot appear in a constructor}}
};

class Server : public Thing {
    S name_;
};
}

namespace GH69233 {
struct Base {};
struct S : Base {
    int j;
    S& operator=(this Base& self, const S&) = default;
    // expected-warning@-1 {{explicitly defaulted copy assignment operator is implicitly deleted}}
    // expected-note@-2 {{function is implicitly deleted because its declared type does not match the type of an implicit copy assignment operator}}
    // expected-note@-3 {{explicitly defaulted function was implicitly deleted here}}
};

struct S2 {
    S2& operator=(this int&& self, const S2&);
    S2& operator=(this int&& self, S2&&);
    operator int();
};

S2& S2::operator=(this int&& self, const S2&) = default;
// expected-error@-1 {{the type of the explicit object parameter of an explicitly-defaulted copy assignment operator should match the type of the class 'S2'}}

S2& S2::operator=(this int&& self, S2&&) = default;
// expected-error@-1 {{the type of the explicit object parameter of an explicitly-defaulted move assignment operator should match the type of the class 'S2'}}

struct Move {
    Move& operator=(this int&, Move&&) = default;
    // expected-warning@-1 {{explicitly defaulted move assignment operator is implicitly deleted}}
    // expected-note@-2 {{function is implicitly deleted because its declared type does not match the type of an implicit move assignment operator}}
    // expected-note@-3 {{copy assignment operator is implicitly deleted because 'Move' has a user-declared move assignment operator}}
};

void test() {
    S s;
    s = s; // expected-error {{object of type 'S' cannot be assigned because its copy assignment operator is implicitly deleted}}
    S2 s2;
    s2 = s2;

    Move m;
    m = Move{}; // expected-error {{object of type 'Move' cannot be assigned because its copy assignment operator is implicitly deleted}}
}

}


namespace GH75732 {
auto serialize(auto&& archive, auto&& c){ }
struct D {
    auto serialize(this auto&& self, auto&& archive) {
        serialize(archive, self); // expected-error {{call to explicit member function without an object argument}}
    }
};
}

namespace GH80971 {
struct S {
  auto f(this auto self...) {  }
};

int bug() {
  S{}.f(0);
}
}

namespace GH84163 {
struct S {
  int x;

  auto foo() {
    return [*this](this auto&&) {
      x = 10; // expected-error {{read-only variable is not assignable}}
    };
  }
};

int f() {
  S s{ 5 };
  const auto l = s.foo();
  l(); // expected-note {{in instantiation of}}

  const auto g = [x = 10](this auto&& self) { x = 20; }; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}}
  g(); // expected-note {{in instantiation of}}
}
}

namespace GH86054 {
template<typename M>
struct unique_lock {
  unique_lock(M&) {}
};
int f() {
  struct mutex {} cursor_guard;
  [&cursor_guard](this auto self) {
    unique_lock a(cursor_guard);
  }();
}
}

namespace GH86398 {
struct function {}; // expected-note 2 {{not viable}}
int f() {
  function list;
  [&list](this auto self) {
    list = self; // expected-error {{no viable overloaded '='}}
  }(); // expected-note {{in instantiation of}}
}

struct function2 {
  function2& operator=(function2 const&) = delete; // expected-note {{candidate function not viable}}
};
int g() {
  function2 list;
  [&list](this auto self) {
    list = self; // expected-error {{no viable overloaded '='}}
  }(); // expected-note {{in instantiation of}}
}

struct function3 {
  function3& operator=(function3 const&) = delete; // expected-note {{has been explicitly deleted}}
};
int h() {
  function3 list;
  [&list](this auto self) {
    list = function3{}; // expected-error {{selected deleted operator '='}}
  }();
}
}

namespace GH92188 {
struct A {
  template<auto N>
  void operator+=(this auto &&, const char (&)[N]);
  void operator+=(this auto &&, auto &&) = delete;

  void f1(this A &, auto &);
  void f1(this A &, auto &&) = delete;

  void f2(this auto&);
  void f2(this auto&&) = delete;

  void f3(auto&) &;
  void f3(this A&, auto&&) = delete;

  void f4(auto&&) & = delete;
  void f4(this A&, auto&);

  static void f5(auto&);
  void f5(this A&, auto&&) = delete;

  static void f6(auto&&) = delete;
  void f6(this A&, auto&);

  void implicit_this() {
    int lval;
    operator+=("123");
    f1(lval);
    f2();
    f3(lval);
    f4(lval);
    f5(lval);
    f6(lval);
  }

  void operator-(this A&, auto&&) = delete;
  friend void operator-(A&, auto&);

  void operator*(this A&, auto&);
  friend void operator*(A&, auto&&) = delete;
};

void g() {
  A a;
  int lval;
  a += "123";
  a.f1(lval);
  a.f2();
  a.f3(lval);
  a.f4(lval);
  a.f5(lval);
  a.f6(lval);
  a - lval;
  a * lval;
}
}

namespace P2797 {

int bar(void) { return 55; }
int (&fref)(void) = bar;

struct C {
  void c(this const C&);    // #first
  void c() &;               // #second
  static void c(int = 0);   // #third

  void d() {
    c();                // expected-error {{call to member function 'c' is ambiguous}}
                        // expected-note@#first {{candidate function}}
                        // expected-note@#second {{candidate function}}
                        // expected-note@#third {{candidate function}}

    (C::c)();           // expected-error {{call to member function 'c' is ambiguous}}
                        // expected-note@#first {{candidate function}}
                        // expected-note@#second {{candidate function}}
                        // expected-note@#third {{candidate function}}

    (&(C::c))();        // expected-error {{cannot create a non-constant pointer to member function}}
    (&C::c)(C{});
    (&C::c)(*this);     // expected-error {{call to non-static member function without an object argument}}
    (&C::c)();

    (&fref)();
  }
};
}

namespace GH85992 {
namespace N {
struct A {
  int f(this A);
};

int f(A);
}

struct S {
  int (S::*x)(this int); // expected-error {{an explicit object parameter can only appear as the first parameter of a member function}}
  int (*y)(this int); // expected-error {{an explicit object parameter can only appear as the first parameter of a member function}}
  int (***z)(this int); // expected-error {{an explicit object parameter can only appear as the first parameter of a member function}}

  int f(this S);
  int ((g))(this S);
  friend int h(this S); // expected-error {{an explicit object parameter cannot appear in a non-member function}}
  int h(int x, int (*)(this S)); // expected-error {{an explicit object parameter can only appear as the first parameter of a member function}}

  struct T {
    int f(this T);
  };

  friend int T::f(this T);
  friend int N::A::f(this N::A);
  friend int N::f(this N::A); // expected-error {{an explicit object parameter cannot appear in a non-member function}}
  int friend func(this T); // expected-error {{an explicit object parameter cannot appear in a non-member function}}
};

using T = int (*)(this int); // expected-error {{an explicit object parameter can only appear as the first parameter of a member function}}
using U = int (S::*)(this int); // expected-error {{an explicit object parameter can only appear as the first parameter of a member function}}
int h(this int); // expected-error {{an explicit object parameter cannot appear in a non-member function}}

int S::f(this S) { return 1; }

namespace a {
void f();
};
void a::f(this auto) {} // expected-error {{an explicit object parameter cannot appear in a non-member function}}
}
