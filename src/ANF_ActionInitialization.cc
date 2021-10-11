#include "ANF_ActionInitialization.hh"
#include "ANF_PrimaryGeneratorAction.hh"
#include "ANF_RunAction.hh"
#include "ANF_EventAction.hh"
#include "ANF_SteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ANF_ActionInitialization::ANF_ActionInitialization()
 : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ANF_ActionInitialization::~ANF_ActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ANF_ActionInitialization::BuildForMaster() const
{
  ANF_RunAction* runAction = new ANF_RunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ANF_ActionInitialization::Build() const
{
  SetUserAction(new ANF_PrimaryGeneratorAction);

  ANF_RunAction* runAction = new ANF_RunAction();
  SetUserAction(runAction);
  
  ANF_EventAction* eventAction = new ANF_EventAction();
  SetUserAction(eventAction);
  
  ANF_SteppingAction* stepAction = new ANF_SteppingAction();
  SetUserAction(stepAction);
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
