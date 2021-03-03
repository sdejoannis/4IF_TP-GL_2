#include "State.h"

bool State0::transition(Automate & automate,Symbole* s){
	switch(*s){
	case OPENPAR:
		automate.decalage(s,new State2());
		break;
	case INT:
		automate.decalage(s,new State3());
		break;
	/*case EXPR:
		automate.reduction(s,new State1);
		break;*/
	default:
    	automate.decalage(new Symbole(ERREUR), NULL);
		return false;
	}
	return true; 
}

bool State1::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State2::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State3::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State4::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State5::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State6::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State7::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State8::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State9::transition(Automate & automate,Symbole* s){
	switch(*s){
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}
