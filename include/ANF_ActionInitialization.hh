#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class ANF_ActionInitialization : public G4VUserActionInitialization
{
  public:
    ANF_ActionInitialization();
    virtual ~ANF_ActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

    
