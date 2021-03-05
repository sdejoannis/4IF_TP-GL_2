#include <string>
#include "Automate.h"
#include "Symbole.h"

using namespace std;

class Automate;

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

class State6 : public State {
public:
  State6():State("S6"){};
  bool transition(Automate &automate, Symbole *s);
  ~State6(){};
};

class State7 : public State {
public:
  State7():State("S7"){};
  bool transition(Automate &automate, Symbole *s);
  ~State7(){};
};

class State8 : public State {
public:
  State8():State("S8"){};
  bool transition(Automate &automate, Symbole *s);
  ~State8(){};
};

class State9 : public State {
public:
  State9():State("S9"){};
  bool transition(Automate &automate, Symbole *s);
  ~State9(){};
};