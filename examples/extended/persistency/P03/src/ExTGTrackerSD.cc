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
// $Id: ExTGTrackerSD.cc,v 1.2 2010/11/05 08:52:34 gcosmo Exp $
// GEANT4 tag $Name: geant4-09-04 $
//
// ---------------------------------------------------------------------------

#include "ExTGTrackerSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

// ---------------------------------------------------------------------------

ExTGTrackerSD::ExTGTrackerSD(G4String name)
:G4VSensitiveDetector(name)
{
  G4String HCname;
  collectionName.insert(HCname="trackerCollection");
}

// ---------------------------------------------------------------------------

ExTGTrackerSD::~ExTGTrackerSD()
{
}

// ---------------------------------------------------------------------------

void ExTGTrackerSD::Initialize(G4HCofThisEvent* HCE)
{
  trackerCollection = new ExTGTrackerHitsCollection
                          (SensitiveDetectorName,collectionName[0]); 
  static G4int HCID = -1;
  if ( HCID<0 )
  {
    HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  }
  HCE->AddHitsCollection( HCID, trackerCollection ); 
}

// ---------------------------------------------------------------------------

G4bool ExTGTrackerSD::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
  G4double edep = aStep->GetTotalEnergyDeposit();

  if(edep==0.)  { return false; }

  ExTGTrackerHit* newHit = new ExTGTrackerHit();
  newHit->SetTrackID  (aStep->GetTrack()->GetTrackID());
  newHit->SetChamberNb(aStep->GetPreStepPoint()->GetTouchableHandle()
                                               ->GetCopyNumber());
  newHit->SetEdep     (edep);
  newHit->SetPos      (aStep->GetPostStepPoint()->GetPosition());
  trackerCollection->insert( newHit );
  
  //newHit->Print();
  //newHit->Draw();

  return true;
}

// ---------------------------------------------------------------------------

void ExTGTrackerSD::EndOfEvent(G4HCofThisEvent*)
{
   G4int NbHits = trackerCollection->entries();
   G4cout << "\n-------->Hits Collection: in this event there are " << NbHits 
          << " hits in the tracker chambers: " << G4endl;
   for (G4int i=0;i<NbHits;i++)
   {
     (*trackerCollection)[i]->Print();
   }
}

// ---------------------------------------------------------------------------