#include "Automate.h"
#include <string.h>

using namespace std;

class State1;
class State1;
class State2;
class State3;
class State4;
class State5;

class State {
public:
    State(string name):name(name){};
    virtual ~State(){};
    virtual bool transition(Automate& automate, Symbole *s) = 0;

protected:
    string name;
};

class State0 : public State {
public:
  State0():State("S0"){};
  bool transition(Automate &automate, Symbole *s);
  ~State0(){};
};

class State1 : public State {
public:
  State1():State("S1"){};
  bool transition(Automate &automate, Symbole *s);
  ~State1(){};
};

class State2 : public State {
public:
  State2():State("S2"){};
  bool transition(Automate &automate, Symbole *s);
  ~State2(){};
};

class State3 : public State {
public:
  State3():State("S3"){};
  bool transition(Automate &automate, Symbole *s);
  ~State3(){};
};

class State4 : public State {
public:
  State4():State("S4"){};
  bool transition(Automate &automate, Symbole *s);
  ~State4(){};
};

class State5 : public State {
public:
  State5():State("S5"){};
  bool transition(Automate &automate, Symbole *s);
  ~State5(){};
};