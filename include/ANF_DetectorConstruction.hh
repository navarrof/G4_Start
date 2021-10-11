#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.

class ANF_DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    ANF_DetectorConstruction();
    virtual ~ANF_DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

};

