#include "ANF_DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ANF_DetectorConstruction::ANF_DetectorConstruction(): G4VUserDetectorConstruction(){}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ANF_DetectorConstruction::~ANF_DetectorConstruction(){}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* ANF_DetectorConstruction::Construct()
{  
    // ----------------- Define World ----------------- // 

    G4double zet = 1.0;
    G4double amass = 1.01*CLHEP::g/CLHEP::mole;
    G4double density = CLHEP::universe_mean_density;
    G4double pressure = 3.0e-18*CLHEP::pascal;
    G4double temperature = 2.73*CLHEP::kelvin;
    G4Material * WorldMaterial = new G4Material("Galactic", zet, amass, density, 
                                                kStateGas, temperature, pressure);

    G4double worldXsize = 1.0*CLHEP::m;
    G4double worldYsize = 1.0*CLHEP::m;
    G4double worldZsize = 1.0*CLHEP::m;

    G4Box* worldSolid = new G4Box( "solid-world",       // name
                                    0.5*worldXsize,     // box half x-size
                                    0.5*worldYsize,     // box half y-size
                                    0.5*worldZsize     // box half z-size
                                     );

    G4LogicalVolume* worldLogical = new G4LogicalVolume( worldSolid,
                                                          WorldMaterial,
                                                          "logic-world" );

    G4VPhysicalVolume* worldPhysical = new G4PVPlacement( nullptr, 
                                                        G4ThreeVector(0.0,0.0,0.0),
                                                        worldLogical,
                                                        "world",
                                                        nullptr,
                                                        false, 
                                                        0.0);
  
  return worldPhysical;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
