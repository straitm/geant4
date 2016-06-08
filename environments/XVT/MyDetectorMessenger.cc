// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: MyDetectorMessenger.cc,v 2.2 1998/07/13 17:29:39 urbi Exp $
// GEANT4 tag $Name: geant4-00 $
//

#include "MyDetectorMessenger.hh"

#include "MyDetectorConstruction.hh"
#include "G4UIcommand.hh"
#include "G4UIparameter.hh"
#include "globals.hh"

#include "G4ios.hh"

MyDetectorMessenger::MyDetectorMessenger(MyDetectorConstruction * myDC)
:myDetector(myDC)
{
  G4UIcommand * command;
  G4UIparameter * param;
  G4String defParam;

  command = new G4UIcommand("/init/SelectDetector",this);
  command->SetGuidance("Select Detector Setup.");
  command->SetGuidance("  Choice : SimpleBox / Honeycomb ");
  param = new G4UIparameter("Choice",'c',true);
  param->SetGuidance("SimpleBox is default.");
  param->SetDefaultValue("SimpleBox");
  myDetector->SelectDetector(defParam="SimpleBox");
  command->SetParameter(param);
  AddUIcommand(command);

  command = new G4UIcommand("/init/SelectMaterial",this);
  command->SetGuidance("Select Material of the SimpleBox.");
  command->SetGuidance("  Choice : Air, Al, Pb (default)");
  param = new G4UIparameter("Choice",'c',true);
  param->SetGuidance("Material choice");
  param->SetDefaultValue("Pb");
  myDetector->SelectMaterial(defParam="Pb");
  command->SetParameter(param);
  AddUIcommand(command);
}

void MyDetectorMessenger::SetNewValue(G4UIcommand * command,G4String newValues)
{
  if( command->GetCommandName() == "SelectDetector" )
  {
    myDetector->SelectDetector(newValues);
  }
  if( command->GetCommandName() == "SelectMaterial" )
  {
    myDetector->SelectMaterial(newValues);
  }
  return;
}
