#include "G4UserSteppingAction.hh"
#include "globals.hh"

class ANF_EventAction;
class G4LogicalVolume;



class ANF_SteppingAction : public G4UserSteppingAction{
  public:
    ANF_SteppingAction();
    virtual ~ANF_SteppingAction();

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
