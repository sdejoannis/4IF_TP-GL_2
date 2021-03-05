#include "State.h"

bool State0::transition(Automate & automate,Symbole* s){
	switch(*s){
	case OPENPAR:
		automate.decalage(s,new State2());
		break;
	case INT:
		automate.decalage(s,new State3());
		break;
	case EXPR:
		automate.decalage(s, new State1());
		break;
	default:
    	automate.decalage(new Symbole(ERREUR), NULL);
		  return false;
	}
	return true; 
}

bool State1::transition(Automate & automate,Symbole* s){
	switch(*s){
  case PLUS:
    automate.decalage(s,new State4());
    break;
  case MULT:
    automate.decalage(s,new State5());
    break;
  case FIN:
    return false;
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State2::transition(Automate & automate,Symbole* s){
	switch(*s){
  case INT:
    automate.decalage(s,new State3());
    break;
  case OPENPAR:
    automate.decalage(s,new State2());
    break;
  case EXPR:
    automate.decalage(s,new State6());
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State3::transition(Automate & automate,Symbole* s){
	switch(*s){
  case PLUS:
    automate.reduction(new Symbole(PLUS),1);
    break; 
  case MULT:
    automate.reduction(new Symbole(MULT),1);
    break;
  case CLOSEPAR:
    automate.reduction(new Symbole(CLOSEPAR),1);
    break;
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
