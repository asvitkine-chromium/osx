// Build don't link:
// Here is another program from the net.

class B;

class A {
  private:
    A(B *);			// ERROR - 
  public:
    A(long);			// ERROR - 
};

A a(0); // ERROR - should be ambigious
