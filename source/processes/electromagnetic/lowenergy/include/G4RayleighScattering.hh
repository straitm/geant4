//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: G4RayleighScattering.hh,v 1.2 2009/03/18 13:45:51 pandola Exp $
// GEANT4 tag $Name: geant4-09-03 $
//
//------------------ G4RayleighScattering physics process -----------------------
//
// 19-12-2008, first implementation, Luciano Pandola 
// 18-03-2009, clean up according to Vladimir's suggestions, Luciano Pandola
// -----------------------------------------------------------------------------

// class description
//
// Class to implement Rayleigh scattering as a physics process. The default model 
// used for the process is G4LivermoreRayleighModel

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef G4RayleighScattering_h
#define G4RayleighScattering_h 1

#include "G4VEmProcess.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4RayleighScattering : public G4VEmProcess

{
public:  // with description

  G4RayleighScattering(const G4String& processName ="Rayl",
		      G4ProcessType type = fElectromagnetic);

  virtual ~G4RayleighScattering();

  // true for Gamma only.  
  G4bool IsApplicable(const G4ParticleDefinition&);
  
  // Print few lines of informations about the process: validity range,
  virtual void PrintInfo();


protected:

  virtual void InitialiseProcess(const G4ParticleDefinition*);

private:
     
  G4bool       isInitialised;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
  
#endif
 