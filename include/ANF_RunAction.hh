#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class ANF_RunAction : public G4UserRunAction
{
  public:
    ANF_RunAction();
    ~ANF_RunAction();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);
    
};


