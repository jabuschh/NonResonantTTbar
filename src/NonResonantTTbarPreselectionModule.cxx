#include <iostream>
#include <memory>

#include <UHH2/core/include/AnalysisModule.h>
#include <UHH2/core/include/Event.h>
#include <UHH2/core/include/Selection.h>
#include "UHH2/common/include/PrintingModules.h"

#include <UHH2/common/include/CleaningModules.h>
#include <UHH2/common/include/NSelections.h>
#include <UHH2/common/include/LumiSelection.h>
#include <UHH2/common/include/TriggerSelection.h>
#include <UHH2/common/include/JetCorrections.h>
#include <UHH2/common/include/JetCorrectionSets.h>
#include <UHH2/common/include/ObjectIdUtils.h>
#include <UHH2/common/include/MuonIds.h>
#include <UHH2/common/include/ElectronIds.h>
#include <UHH2/common/include/JetIds.h>
#include <UHH2/common/include/TopJetIds.h>
#include <UHH2/common/include/TTbarGen.h>
#include <UHH2/common/include/Utils.h>
#include <UHH2/common/include/AdditionalSelections.h>
#include "UHH2/common/include/LuminosityHists.h"
#include <UHH2/common/include/MuonHists.h>
#include <UHH2/common/include/ElectronHists.h>
#include <UHH2/common/include/JetHists.h>
#include <UHH2/common/include/EventHists.h>
#include <UHH2/common/include/CommonModules.h>

#include <UHH2/NonResonantTTbar/include/ModuleBASE.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarSelections.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarModules.h> // not needed
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarPreselectionHists.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarGeneratorHists.h>
#include <UHH2/NonResonantTTbar/include/TopJetCorrections.h>
#include <UHH2/NonResonantTTbar/include/TopPuppiJetCorrections.h>

using namespace std;

class NonResonantTTbarPreselectionModule : public ModuleBASE {

public:
  explicit NonResonantTTbarPreselectionModule(uhh2::Context&);
  virtual bool process(uhh2::Event&) override;
  void book_histograms(uhh2::Context&, vector<string>);
  void fill_histograms(uhh2::Event&, string);

protected:


  // Corrections
  std::unique_ptr<CommonModules> common;
  std::unique_ptr<TopJetCorrections> topjetCorr;
  std::unique_ptr<TopPuppiJetCorrections> toppuppijetCorr;

  // Cleaners
  std::unique_ptr<JetCleaner>    jet_IDcleaner, jet_cleaner1, jet_cleaner2;
  std::unique_ptr<TopJetCleaner> topjet_puppi_IDcleaner, topjet_puppi_cleaner, topjet_IDcleaner, topjet_cleaner;

  // Selections
  //std::unique_ptr<uhh2::AndSelection> metfilters_sel;
  std::unique_ptr<uhh2::Selection> genflavor_sel;
  std::unique_ptr<uhh2::Selection> jet1_sel;
  std::unique_ptr<uhh2::Selection> jet2_sel;
  std::unique_ptr<uhh2::Selection> met_sel;

  bool isMC, ispuppi;
  string Sys_PU;

  std::unique_ptr<Hists> lumihists;
  TString METcollection;

  bool is2016v2, is2016v3, is2017v2, is2018, isUL16preVFP, isUL16postVFP, isUL17, isUL18;

};

void NonResonantTTbarPreselectionModule::book_histograms(uhh2::Context& ctx, vector<string> tags){
  for(const auto & tag : tags){
    string mytag = tag+"_General";
    book_HFolder(mytag, new NonResonantTTbarPreselectionHists(ctx,mytag));
  }
}

void NonResonantTTbarPreselectionModule::fill_histograms(uhh2::Event& event, string tag){
  string mytag = tag+"_General";
  HFolder(mytag)->fill(event);
}



NonResonantTTbarPreselectionModule::NonResonantTTbarPreselectionModule(uhh2::Context& ctx){

  for(auto & kv : ctx.get_all()){
    cout << " " << kv.first << " = " << kv.second << endl;
  }

  //// CONFIGURATION
  const TString METcollection = ctx.get("METName");
  isMC     = ctx.get("dataset_type") == "MC";
  ispuppi  = (ctx.get("is_puppi") == "true");
  Sys_PU   = ctx.get("Sys_PU");
  is2016v2      = (ctx.get("dataset_version").find("2016v2")      != std::string::npos);
  is2016v3      = (ctx.get("dataset_version").find("2016v3")      != std::string::npos);
  is2017v2      = (ctx.get("dataset_version").find("2017v2")      != std::string::npos);
  is2018        = (ctx.get("dataset_version").find("2018")        != std::string::npos);
  isUL16preVFP  = (ctx.get("dataset_version").find("UL16preVFP")  != std::string::npos);
  isUL16postVFP = (ctx.get("dataset_version").find("UL16postVFP") != std::string::npos);
  isUL17        = (ctx.get("dataset_version").find("UL17")        != std::string::npos);
  isUL18        = (ctx.get("dataset_version").find("UL18")        != std::string::npos);

  if(ispuppi){
    cout << "is_puppi = true" << endl;
  }
  else{
    cout << "is_puppi = false" << endl;
  }

  ElectronId eleID;  MuonId muID;

  if(is2016v2 || is2016v3){
    //eleID = ElectronID_Summer16_tight_noIso; //ToDo: compare cutBased without iso and MVA-based via wp in UHH2
    //muID      = MuonID(Muon::Highpt);
    eleID = ElectronID_Summer16_medium_noIso;
    muID  = MuonID(Muon::CutBasedIdTight); // see more muonIDs https://github.com/cms-sw/cmssw/blob/master/DataFormats/MuonReco/interface/Muon.h#L201
  }
  if(is2017v2 || is2018){
    eleID = ElectronID_Fall17_tight_noIso; //ToDo: compare cutBased without iso and MVA-based via wp in UHH2
    muID  = MuonID(Muon::CutBasedIdGlobalHighPt);
  }
  if(isUL16preVFP || isUL16postVFP){
    eleID = ElectronID_Summer16_medium_noIso;
    muID  = MuonID(Muon::CutBasedIdTight);
  }
  if(isUL17 || isUL18){
    eleID = ElectronID_Fall17_tight_noIso;
    muID  = MuonID(Muon::CutBasedIdGlobalHighPt);
  }

  double electron_pt(50.);
  double muon_pt(55.);
  double jet1_pt(50.);
  double jet2_pt(20.);
  double MET(50.);


  // // just as information:
  // // MET filters
  // metfilters_sel.reset(new uhh2::AndSelection(ctx, "metfilters"));
  // if(!isMC){
  //  metfilters_sel->add<TriggerSelection>("1-good-vtx", "Flag_goodVertices");
  //  metfilters_sel->add<TriggerSelection>("globalTightHalo2016Filter", "Flag_globalTightHalo2016Filter");
  //  metfilters_sel->add<TriggerSelection>("HBHENoiseFilter", "Flag_HBHENoiseFilter");
  //  metfilters_sel->add<TriggerSelection>("HBHENoiseIsoFilter", "Flag_HBHENoiseIsoFilter");
  //  metfilters_sel->add<TriggerSelection>("EcalDeadCellTriggerPrimitiveFilter", "Flag_EcalDeadCellTriggerPrimitiveFilter");
  //  if(!isMC)  metfilters_sel->add<TriggerSelection>("eeBadScFilter", "Flag_eeBadScFilter");
  //  metfilters_sel->add<TriggerSelection>("chargedHadronTrackResolutionFilter", "Flag_chargedHadronTrackResolutionFilter");
  //  metfilters_sel->add<TriggerSelection>("muonBadTrackFilter", "Flag_muonBadTrackFilter");
  // }


  // GEN Flavor selection [W+jets flavor-splitting]
  if(ctx.get("dataset_version").find("WJets") != std::string::npos){
    if     (ctx.get("dataset_version").find("_B") != std::string::npos) genflavor_sel.reset(new GenFlavorSelection("b"));
    else if(ctx.get("dataset_version").find("_C") != std::string::npos) genflavor_sel.reset(new GenFlavorSelection("c"));
    else if(ctx.get("dataset_version").find("_L") != std::string::npos) genflavor_sel.reset(new GenFlavorSelection("l"));
    else genflavor_sel.reset(new uhh2::AndSelection(ctx));
  }
  else genflavor_sel.reset(new uhh2::AndSelection(ctx));


  // Cleaning: Mu, Ele, Jets
  const MuonId muonID(AndId<Muon>(PtEtaCut(muon_pt, 2.4), muID));
  const ElectronId electronID(AndId<Electron>(PtEtaSCCut(electron_pt, 2.5), eleID));
  const JetPFID jetID_CHS(JetPFID::WP_TIGHT_CHS);
  const JetPFID jetID_PUPPI(JetPFID::WP_TIGHT_PUPPI);

  jet_IDcleaner.reset(new JetCleaner(ctx, jetID_PUPPI));
  jet_cleaner1.reset(new JetCleaner(ctx, 15., 3.0));
  jet_cleaner2.reset(new JetCleaner(ctx, 30., 2.4));
  topjet_IDcleaner.reset(new TopJetCleaner(ctx, jetID_CHS, "topjets"));
  topjet_cleaner.reset(new TopJetCleaner(ctx, TopJetId(PtEtaCut(400., 2.4)), "topjets"));
  topjet_puppi_IDcleaner.reset(new TopJetCleaner(ctx, jetID_PUPPI, "toppuppijets"));
  topjet_puppi_cleaner.reset(new TopJetCleaner(ctx, TopJetId(PtEtaCut(400., 2.4)), "toppuppijets"));



  // common modules
  common.reset(new CommonModules());
  common->switch_jetlepcleaner(true);
  common->disable_pvfilter();
  common->disable_jetpfidfilter();
  common->switch_jetPtSorter(true);
  common->switch_metcorrection(true);
  common->set_muon_id(muonID);
  common->set_electron_id(electronID);
  common->init(ctx, Sys_PU);

  topjetCorr.reset(new TopJetCorrections());
  topjetCorr->init(ctx);

  toppuppijetCorr.reset(new TopPuppiJetCorrections());
  toppuppijetCorr->init(ctx);

  //// EVENT SELECTION
  jet1_sel.reset(new NJetSelection(1, -1, JetId(PtEtaCut(jet1_pt, 2.4))));
  jet2_sel.reset(new NJetSelection(2, -1, JetId(PtEtaCut(jet2_pt, 2.4))));
  met_sel .reset(new METCut  (MET   , uhh2::infinity));

  // Book histograms
  vector<string> histogram_tags = {"Input", "CommonModules", "Lepton1", "JetID", "JetCleaner1", "JetCleaner2", "TopjetCleaner", "Jet1", "Jet2", "MET"};
  book_histograms(ctx, histogram_tags);

  lumihists.reset(new LuminosityHists(ctx, "lumi"));
}


bool NonResonantTTbarPreselectionModule::process(uhh2::Event& event){
  // cout << "event number: " << event.event << endl;

  //debug
  //if(event.event==97559444 || event.event==23){
  // if(event.event!=500494653) return false;
  // cout << "Event number = " << event.event << endl;
  //
  //   cout<<"Getting started... "<<event.event<<endl;
  //
  // uint jetI= 0;
  // for (const Jet & jet: *event.jets) {
  //   cout << "-- Ak4 jet pt = " << jet.pt() << "	"  << "jet eta = " << jet.eta() << "     "  << "jet phi = " << jet.phi() << "	" << "for jet#" << jetI << endl;
  //   jetI++;
  // }
  // uint jetInd = 0;
  // for (const TopJet & toppuppijet: *event.toppuppijets) {
  //   cout << "-- PUPPI Top jet pt = " << toppuppijet.pt()  << "     "  << "jet eta = " << toppuppijet.eta()<< "     "  << "jet phi = " << toppuppijet.phi() << "	"  << "for jet#" << jetInd << endl;
  //   jetInd++;
  // }
  // uint chsjetInd = 0;
  // for (const TopJet & topjet: *event.topjets) {
  //   cout << "--- CHS Top jet pt = " << topjet.pt() << "     "  << "jet eta = " << topjet.eta()<< "     "  << "jet phi = " << topjet.phi()  << "	" << "for jet#" << chsjetInd << endl;
  //   chsjetInd++;
  // }


  // cout << "Getting started... " << event.event << endl;
  fill_histograms(event, "Input");

  bool commonResult = common->process(event); // error appears here! -> see CommonModules.cxx
  if (!commonResult) return false;
  sort_by_pt<Muon>(*event.muons);
  sort_by_pt<Electron>(*event.electrons);
  if(ispuppi){
    toppuppijetCorr->process(event);
  } else {
    topjetCorr->process(event);
  }
  // cout<<"TopJEC_JLC ... "<<event.event<<endl;
  // cout<<"Common Modules... "<<event.event<<endl;

  fill_histograms(event, "CommonModules");


  // MET filters
  // if(!metfilters_sel->passes(event)) return false;
  // fill_histograms(event, "Metfilters");
  // cout<<"Met filters ... "<<event.event<<endl;

  // GEN ME quark-flavor selection
  if(!event.isRealData){
    if(!genflavor_sel->passes(event)) return false;
  }

  //cout<<"GEN ME quark-flavor selection ... "<<event.event<<endl;

  const bool pass_lep1 = ((event.muons->size() >= 1) || (event.electrons->size() >= 1));
  if(!pass_lep1) return false;
  fill_histograms(event, "Lepton1");

  jet_IDcleaner->process(event);
  fill_histograms(event, "JetID");

  jet_cleaner1->process(event);
  sort_by_pt<Jet>(*event.jets);
  fill_histograms(event, "JetCleaner1");
  //cout<<"JetCleaner1 ... "<<event.event<<endl;

  // Lepton-2Dcut variables
  for(auto& muo : *event.muons){

    float    dRmin, pTrel;
    std::tie(dRmin, pTrel) = drmin_pTrel(muo, *event.jets);

    muo.set_tag(Muon::twodcut_dRmin, dRmin);
    muo.set_tag(Muon::twodcut_pTrel, pTrel);
  }

  for(auto& ele : *event.electrons){

    float    dRmin, pTrel;
    std::tie(dRmin, pTrel) = drmin_pTrel(ele, *event.jets);

    ele.set_tag(Electron::twodcut_dRmin, dRmin);
    ele.set_tag(Electron::twodcut_pTrel, pTrel);
  }

  jet_cleaner2->process(event);
  sort_by_pt<Jet>(*event.jets);
  fill_histograms(event, "JetCleaner2");
  //cout<<"JetCleaner2 ... "<<event.event<<endl;

  topjet_IDcleaner->process(event);
  topjet_cleaner->process(event);
  sort_by_pt<TopJet>(*event.topjets);

  topjet_puppi_IDcleaner->process(event);
  topjet_puppi_cleaner->process(event);
  sort_by_pt<TopJet>(*event.toppuppijets);
  fill_histograms(event, "TopjetCleaner");
  //cout<<"TopjetCleaner ... "<<event.event<<endl;

  // 1st AK4 jet selection
  const bool pass_jet1 = jet1_sel->passes(event);
  if(!pass_jet1) return false;
  fill_histograms(event, "Jet1");

  // 2nd AK4 jet selection
  const bool pass_jet2 = jet2_sel->passes(event);
  if(!pass_jet2) return false;
  fill_histograms(event, "Jet2");

  // MET selection
  const bool pass_met = met_sel->passes(event);
  if(!pass_met) return false;
  fill_histograms(event, "MET");

  return true;
}

UHH2_REGISTER_ANALYSIS_MODULE(NonResonantTTbarPreselectionModule)
