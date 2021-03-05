#include "State.h"

string State::to_string(){
  return "     current state: " + name;
}

bool State0::transition(Automate & automate,Symbole* s){
  cout<<this->to_string() << endl;
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
  cout<<this->to_string() << endl;
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
  cout<<this->to_string() << endl;
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
  cout<<this->to_string() << endl;
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
  case FIN:
    automate.reduction(new Symbole(FIN),1);
    automate.isAccepted = true;
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State4::transition(Automate & automate,Symbole* s){
  cout<<this->to_string() << endl;
	switch(*s){
  case INT:
    automate.decalage(s,new State3());
    break;
  case OPENPAR:
    automate.decalage(s,new State2());
    break;
  case EXPR:
    automate.decalage(s,new State7());
  break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State5::transition(Automate & automate,Symbole* s){
  cout<<this->to_string() << endl;
	switch(*s){
  case INT:
    automate.decalage(s,new State3());
    break;
  case OPENPAR:
    automate.decalage(s,new State2());
    break;
  case EXPR:
    automate.decalage(s,new State8());
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State6::transition(Automate & automate,Symbole* s){
  cout<<this->to_string() << endl;
	switch(*s){
  case PLUS:
    automate.decalage(s,new State4());
     break;
  case MULT:
    automate.decalage(s,new State5());
    break;
  case CLOSEPAR:
    automate.decalage(s,new State9());
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State7::transition(Automate & automate,Symbole* s){
  cout<<this->to_string() << endl;
	switch(*s){
  case PLUS:
    automate.reduction(new Symbole(PLUS),3);
    break;
  case MULT:
    automate.decalage(s,new State5());
    break;
  case CLOSEPAR:
    automate.reduction(new Symbole(CLOSEPAR),3);
    break;
  case FIN:
    automate.reduction(new Symbole(FIN),3);
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State8::transition(Automate & automate,Symbole* s){
  cout<<this->to_string() << endl;
	switch(*s){
  case PLUS:
    automate.reduction(new Symbole(PLUS),3);
    break;
  case MULT:
    automate.reduction(new Symbole(MULT),3);
    break;
  case CLOSEPAR:
    automate.reduction(new Symbole(CLOSEPAR),3);
    break;
  case FIN:
    automate.reduction(new Symbole(FIN),3);
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State9::transition(Automate & automate,Symbole* s){
  cout<<this->to_string() << endl;
	switch(*s){
  case PLUS:
    automate.reduction(new Symbole(PLUS),3);
    break;
  case MULT:
    automate.reduction(new Symbole(MULT),3);
    break;
  case CLOSEPAR:
    automate.reduction(new Symbole(CLOSEPAR),3);
    break;
  case FIN:
    automate.reduction(new Symbole(FIN),3);
    break;
	default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}
