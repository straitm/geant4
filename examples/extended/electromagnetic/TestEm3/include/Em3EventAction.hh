// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em3EventAction.hh,v 1.2 1999/12/15 14:49:01 gunter Exp $
// GEANT4 tag $Name: geant4-02-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em3EventAction_h
#define Em3EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class Em3RunAction;
class Em3DetectorConstruction;
class Em3EventActionMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em3EventAction : public G4UserEventAction
{
  public:
  
    Em3EventAction(Em3RunAction*,Em3DetectorConstruction*);
   ~Em3EventAction();

    void BeginOfEventAction(const G4Event*);
    void   EndOfEventAction(const G4Event*);
    
    void SetDrawFlag   (G4String val)  {drawFlag    = val;};
    void SetPrintModulo(G4int    val)  {printModulo = val;};
        
  private:
  
    Em3RunAction*             Em3Run;
    Em3DetectorConstruction*  Detector;
    G4int                     calorimeterCollID;  // Hits collection ID
    G4String                  drawFlag;           // draw/print the event
    G4int                     printModulo;         
    Em3EventActionMessenger*  eventMessenger;
};

#endif

    