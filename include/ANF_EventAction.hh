#include "G4UserEventAction.hh"
#include "globals.hh"

class ANF_EventAction : public G4UserEventAction
{
  public:
    ANF_EventAction();
    virtual ~ANF_EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


    
