#include "ANF_DetectorConstruction.hh"
#include "ANF_ActionInitialization.hh"

#include "G4RunManagerFactory.hh"
#include "G4PhysListFactory.hh"

#include "G4UImanager.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv){
  // Detect interactive mode (if no arguments) and define UI session

  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
      ui = new G4UIExecutive(argc, argv);
  }

  //  1. Construct the default run manager
  auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

  //  2.Set mandatory initialization classes
  //
  //        Detector construction
  runManager->SetUserInitialization(new ANF_DetectorConstruction());

  //        Physics list
    G4PhysListFactory physListFactory;
    const G4String plName = "FTFP_BERT_EMZ";
    G4VModularPhysicsList* pl = physListFactory.GetReferencePhysList(plName);
    runManager->SetUserInitialization(pl);
    
  //        User action initialization
  runManager->SetUserInitialization(new ANF_ActionInitialization());
  
  // Initialize visualization
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Process macro or start UI session
  //
  if ( ! ui ) { 
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else { 
    // interactive mode
    UImanager->ApplyCommand("/control/execute ../init_vis.mac");
    ui->SessionStart();
    delete ui;
  }

  // Job termination  
  delete visManager;
  delete runManager;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
