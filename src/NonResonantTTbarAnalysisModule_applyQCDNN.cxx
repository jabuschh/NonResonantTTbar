#include <iostream>
#include <memory>
#include <fstream>

#include <UHH2/core/include/AnalysisModule.h>
#include <UHH2/core/include/Event.h>
#include <UHH2/core/include/Selection.h>
#include "UHH2/common/include/PrintingModules.h"

#include <UHH2/common/include/CleaningModules.h>
#include <UHH2/common/include/NSelections.h>
#include <UHH2/common/include/LumiSelection.h>
#include <UHH2/common/include/TriggerSelection.h>
#include <UHH2/common/include/JetCorrections.h>
#include <UHH2/common/include/ObjectIdUtils.h>
#include <UHH2/common/include/MuonIds.h>
#include <UHH2/common/include/ElectronIds.h>
#include <UHH2/common/include/JetIds.h>
#include <UHH2/common/include/TopJetIds.h>
#include <UHH2/common/include/TTbarGen.h>
#include <UHH2/common/include/Utils.h>
#include <UHH2/common/include/AdditionalSelections.h>
#include "UHH2/common/include/LuminosityHists.h"
#include <UHH2/common/include/MCWeight.h>
#include <UHH2/common/include/MuonHists.h>
#include <UHH2/common/include/ElectronHists.h>
#include <UHH2/common/include/JetHists.h>
#include <UHH2/common/include/EventHists.h>
#include <UHH2/common/include/TopPtReweight.h>
#include <UHH2/common/include/CommonModules.h>

#include <UHH2/NonResonantTTbar/include/ModuleBASE.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarSelections.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarModules.h>
#include <UHH2/NonResonantTTbar/include/TTbarLJHists.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarHists.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarGeneratorHists.h>
#include <UHH2/NonResonantTTbar/include/ZprimeCandidate.h>

//#include <UHH2/common/include/TTbarGen.h>
#include <UHH2/common/include/TTbarReconstruction.h>
#include <UHH2/common/include/ReconstructionHypothesisDiscriminators.h>

#include "UHH2/common/include/NeuralNetworkBase.hpp"

using namespace std;
using namespace uhh2;

/*
██████  ███████ ███████ ██ ███    ██ ██ ████████ ██  ██████  ███    ██
██   ██ ██      ██      ██ ████   ██ ██    ██    ██ ██    ██ ████   ██
██   ██ █████   █████   ██ ██ ██  ██ ██    ██    ██ ██    ██ ██ ██  ██
██   ██ ██      ██      ██ ██  ██ ██ ██    ██    ██ ██    ██ ██  ██ ██
██████  ███████ ██      ██ ██   ████ ██    ██    ██  ██████  ██   ████
*/

class NeuralNetworkModule: public NeuralNetworkBase {
public:
  explicit NeuralNetworkModule(uhh2::Context&, const std::string & ModelName, const std::string& ConfigName);
  virtual void CreateInputs(uhh2::Event & event) override;
protected:

  uhh2::Event::Handle<float> h_dR_jet_Ak8Puppijet;
  uhh2::Event::Handle<float> h_dR_mu_Ak8Puppijet;
  uhh2::Event::Handle<float> h_dR_mu_jet;
  uhh2::Event::Handle<float> h_deepjetbscore_jet;
  uhh2::Event::Handle<float> h_deepjetbscore_jet1;
  uhh2::Event::Handle<float> h_deepjetbscore_jet2;
  uhh2::Event::Handle<float> h_deepjetbscore_jet3;
  uhh2::Event::Handle<float> h_dphi_jet1_MET;
  uhh2::Event::Handle<float> h_dphi_mu_Ak8Puppijet1;
  uhh2::Event::Handle<float> h_dphi_mu_MET;
  uhh2::Event::Handle<float> h_dphi_mu_jet1;
  uhh2::Event::Handle<float> h_eta_Ak8Puppijet1;
  uhh2::Event::Handle<float> h_eta_Ak8Puppijet2;
  uhh2::Event::Handle<float> h_eta_Ak8Puppijet3;
  uhh2::Event::Handle<float> h_eta_Ak8Puppijets;
  uhh2::Event::Handle<float> h_eta_jet;
  uhh2::Event::Handle<float> h_eta_jet1;
  uhh2::Event::Handle<float> h_eta_jet2;
  uhh2::Event::Handle<float> h_eta_jet3;;
  uhh2::Event::Handle<float> h_eta_mu;
  uhh2::Event::Handle<float> h_mass_jet;
  uhh2::Event::Handle<float> h_mass_jet1;
  uhh2::Event::Handle<float> h_mass_jet2;
  uhh2::Event::Handle<float> h_mass_jet3;
  uhh2::Event::Handle<float> h_met_pt;
  uhh2::Event::Handle<float> h_npv_pt;
  uhh2::Event::Handle<float> h_phi_Ak8Puppijet1;
  uhh2::Event::Handle<float> h_phi_Ak8Puppijet2;
  uhh2::Event::Handle<float> h_phi_Ak8Puppijet3;
  uhh2::Event::Handle<float> h_phi_Ak8Puppijets;
  uhh2::Event::Handle<float> h_phi_jet;
  uhh2::Event::Handle<float> h_phi_jet1;
  uhh2::Event::Handle<float> h_phi_jet2;
  uhh2::Event::Handle<float> h_phi_jet3;
  uhh2::Event::Handle<float> h_phi_mu;
  uhh2::Event::Handle<float> h_pt_Ak8Puppijet1;
  uhh2::Event::Handle<float> h_pt_Ak8Puppijet2;
  uhh2::Event::Handle<float> h_pt_Ak8Puppijet3;
  uhh2::Event::Handle<float> h_pt_Ak8Puppijets;
  uhh2::Event::Handle<float> h_pt_jet;
  uhh2::Event::Handle<float> h_pt_jet1;
  uhh2::Event::Handle<float> h_pt_jet2;
  uhh2::Event::Handle<float> h_pt_jet3;
  uhh2::Event::Handle<float> h_pt_mu;
  uhh2::Event::Handle<float> h_ptrel_mu_jet;
  uhh2::Event::Handle<float> h_reliso_mu;
  uhh2::Event::Handle<float> h_s11;
  uhh2::Event::Handle<float> h_s12;
  uhh2::Event::Handle<float> h_s13;
  uhh2::Event::Handle<float> h_s22;
  uhh2::Event::Handle<float> h_s23;
  uhh2::Event::Handle<float> h_s33;
  uhh2::Event::Handle<float> h_st;
  uhh2::Event::Handle<float> h_st_jets;
  uhh2::Event::Handle<float> h_st_lep;

};

NeuralNetworkModule::NeuralNetworkModule(Context& ctx, const std::string & ModelName, const std::string& ConfigName): NeuralNetworkBase(ctx, ModelName, ConfigName){

  h_dR_jet_Ak8Puppijet = ctx.get_handle<float> ("dR_jet_Ak8Puppijet");
  h_dR_mu_Ak8Puppijet = ctx.get_handle<float> ("dR_mu_Ak8Puppijet");
  h_dR_mu_jet = ctx.get_handle<float> ("dR_mu_jet");
  h_deepjetbscore_jet = ctx.get_handle<float> ("deepjetbscore_jet");
  h_deepjetbscore_jet1 = ctx.get_handle<float> ("deepjetbscore_jet1");
  h_deepjetbscore_jet2 = ctx.get_handle<float> ("deepjetbscore_jet2");
  h_deepjetbscore_jet3 = ctx.get_handle<float> ("deepjetbscore_jet3");
  h_dphi_jet1_MET = ctx.get_handle<float> ("dphi_jet1_MET");
  h_dphi_mu_Ak8Puppijet1 = ctx.get_handle<float> ("dphi_mu_Ak8Puppijet1");
  h_dphi_mu_MET = ctx.get_handle<float> ("dphi_mu_MET");
  h_dphi_mu_jet1 = ctx.get_handle<float> ("dphi_mu_jet1");
  h_eta_Ak8Puppijet1 = ctx.get_handle<float> ("eta_Ak8Puppijet1");
  h_eta_Ak8Puppijet2 = ctx.get_handle<float> ("eta_Ak8Puppijet2");
  h_eta_Ak8Puppijet3 = ctx.get_handle<float> ("eta_Ak8Puppijet3");
  h_eta_Ak8Puppijets = ctx.get_handle<float> ("eta_Ak8Puppijets");
  h_eta_jet = ctx.get_handle<float> ("eta_jet");
  h_eta_jet1 = ctx.get_handle<float> ("eta_jet1");
  h_eta_jet2 = ctx.get_handle<float> ("eta_jet2");
  h_eta_jet3 = ctx.get_handle<float> ("eta_jet3");
  h_eta_mu = ctx.get_handle<float> ("eta_mu");
  h_mass_jet = ctx.get_handle<float> ("mass_jet");
  h_mass_jet1 = ctx.get_handle<float> ("mass_jet1");
  h_mass_jet2 = ctx.get_handle<float> ("mass_jet2");
  h_mass_jet3 = ctx.get_handle<float> ("mass_jet3");
  h_met_pt = ctx.get_handle<float> ("met_pt");
  h_npv_pt = ctx.get_handle<float> ("npv_pt");
  h_phi_Ak8Puppijet1 = ctx.get_handle<float> ("phi_Ak8Puppijet1");
  h_phi_Ak8Puppijet2 = ctx.get_handle<float> ("phi_Ak8Puppijet2");
  h_phi_Ak8Puppijet3 = ctx.get_handle<float> ("phi_Ak8Puppijet3");
  h_phi_Ak8Puppijets = ctx.get_handle<float> ("phi_Ak8Puppijets");
  h_phi_jet = ctx.get_handle<float> ("phi_jet");
  h_phi_jet1 = ctx.get_handle<float> ("phi_jet1");
  h_phi_jet2 = ctx.get_handle<float> ("phi_jet2");
  h_phi_jet3 = ctx.get_handle<float> ("phi_jet3");
  h_phi_mu = ctx.get_handle<float> ("phi_mu");
  h_pt_Ak8Puppijet1 = ctx.get_handle<float> ("pt_Ak8Puppijet1");
  h_pt_Ak8Puppijet2 = ctx.get_handle<float> ("pt_Ak8Puppijet2");
  h_pt_Ak8Puppijet3 = ctx.get_handle<float> ("pt_Ak8Puppijet3");
  h_pt_Ak8Puppijets = ctx.get_handle<float> ("pt_Ak8Puppijets");
  h_pt_jet = ctx.get_handle<float> ("pt_jet");
  h_pt_jet1 = ctx.get_handle<float> ("pt_jet1");
  h_pt_jet2 = ctx.get_handle<float> ("pt_jet2");
  h_pt_jet3 = ctx.get_handle<float> ("pt_jet3");
  h_pt_mu = ctx.get_handle<float> ("pt_mu");
  h_ptrel_mu_jet = ctx.get_handle<float> ("ptrel_mu_jet");
  h_reliso_mu = ctx.get_handle<float> ("reliso_mu");
  h_s11 = ctx.get_handle<float> ("s11");
  h_s12 = ctx.get_handle<float> ("s12");
  h_s13 = ctx.get_handle<float> ("s13");
  h_s22 = ctx.get_handle<float> ("s22");
  h_s23 = ctx.get_handle<float> ("s23");
  h_s33 = ctx.get_handle<float> ("s33");
  h_st = ctx.get_handle<float> ("st");
  h_st_jets = ctx.get_handle<float> ("st_jets");
  h_st_lep = ctx.get_handle<float> ("st_lep");

}

void NeuralNetworkModule::CreateInputs(Event & event){
  NNInputs.clear();
  NNoutputs.clear();

  string varname[55];
  string scal[55];
  string min[55];
  string max[55];
  double min_val[55];
  double max_val[55];
  ifstream normfile ("/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/KerasNN/NN_QCD_Titas/NormInfo_mu_withoutweight.txt", ios::in);
  if (normfile.is_open()){
    for(int i = 0; i < 55; ++i)
    {
      normfile >> varname[i] >> scal[i] >> min[i] >> max[i];
      min_val[i] = std::stod(min[i]);
      max_val[i] = std::stod(max[i]);
    }
    normfile.close();
  }


  NNInputs.push_back( tensorflow::Tensor(tensorflow::DT_FLOAT, {1, 55}));

  NNInputs.at(0).tensor<float, 2>()(0,0)  = (event.get(h_dR_jet_Ak8Puppijet)   - min_val[0]) / (max_val[0]-min_val[0]);
  NNInputs.at(0).tensor<float, 2>()(0,1)  = (event.get(h_dR_mu_Ak8Puppijet)    - min_val[1]) / (max_val[1]- min_val[1]);
  NNInputs.at(0).tensor<float, 2>()(0,2)  = (event.get(h_dR_mu_jet)            - min_val[2]) / (max_val[2])- min_val[2];
  NNInputs.at(0).tensor<float, 2>()(0,3)  = (event.get(h_deepjetbscore_jet)    - min_val[3]) / (max_val[3]- min_val[3]);
  NNInputs.at(0).tensor<float, 2>()(0,4)  = (event.get(h_deepjetbscore_jet1)   - min_val[4]) / (max_val[4]- min_val[4]);
  NNInputs.at(0).tensor<float, 2>()(0,5)  = (event.get(h_deepjetbscore_jet2)   - min_val[5]) / (max_val[5]- min_val[5]);
  NNInputs.at(0).tensor<float, 2>()(0,6)  = (event.get(h_deepjetbscore_jet3)   - min_val[6]) / (max_val[6]- min_val[6]);
  NNInputs.at(0).tensor<float, 2>()(0,7)  = (event.get(h_dphi_jet1_MET)        - min_val[7]) / (max_val[7]- min_val[7]);
  NNInputs.at(0).tensor<float, 2>()(0,8)  = (event.get(h_dphi_mu_Ak8Puppijet1) - min_val[8]) / (max_val[8]- min_val[8]);
  NNInputs.at(0).tensor<float, 2>()(0,9)  = (event.get(h_dphi_mu_MET)          - min_val[9]) / (max_val[9]- min_val[9]);
  NNInputs.at(0).tensor<float, 2>()(0,10)  = (event.get(h_dphi_mu_jet1)        - min_val[10]) / (max_val[10]- min_val[10]);
  NNInputs.at(0).tensor<float, 2>()(0,11)  = (event.get(h_eta_Ak8Puppijet1)    - min_val[11]) / (max_val[11]- min_val[11]);
  NNInputs.at(0).tensor<float, 2>()(0,12)  = (event.get(h_eta_Ak8Puppijet2)    - min_val[12]) / (max_val[12]- min_val[12]);
  NNInputs.at(0).tensor<float, 2>()(0,13)  = (event.get(h_eta_Ak8Puppijet3 )   - min_val[13]) / (max_val[13]- min_val[13]);
  NNInputs.at(0).tensor<float, 2>()(0,14)  = (event.get(h_eta_Ak8Puppijets)    - min_val[14]) / (max_val[14]- min_val[14]);
  NNInputs.at(0).tensor<float, 2>()(0,15)  = (event.get(h_eta_jet)             - min_val[15]) / (max_val[15]- min_val[15]);
  NNInputs.at(0).tensor<float, 2>()(0,16)  = (event.get(h_eta_jet1)            - min_val[16]) / (max_val[16]- min_val[16]);
  NNInputs.at(0).tensor<float, 2>()(0,17)  = (event.get(h_eta_jet2)            - min_val[17]) / (max_val[17]- min_val[17]);
  NNInputs.at(0).tensor<float, 2>()(0,18)  = (event.get(h_eta_jet3)            - min_val[18]) / (max_val[18]- min_val[18]);
  NNInputs.at(0).tensor<float, 2>()(0,19)  = (event.get(h_eta_mu)              - min_val[19]) / (max_val[19]- min_val[19]);
  NNInputs.at(0).tensor<float, 2>()(0,20)  = (event.get(h_mass_jet)            - min_val[20]) / (max_val[20]- min_val[20]);
  NNInputs.at(0).tensor<float, 2>()(0,21)  = (event.get(h_mass_jet1)           - min_val[21]) / (max_val[21]- min_val[21]);
  NNInputs.at(0).tensor<float, 2>()(0,22)  = (event.get(h_mass_jet2)           - min_val[22]) / (max_val[22]- min_val[22]);
  NNInputs.at(0).tensor<float, 2>()(0,23)  = (event.get(h_mass_jet3)           - min_val[23]) / (max_val[23]- min_val[23]);
  NNInputs.at(0).tensor<float, 2>()(0,24)  = (event.get(h_met_pt)              - min_val[24]) / (max_val[24]- min_val[24]);
  NNInputs.at(0).tensor<float, 2>()(0,25)  = (event.get(h_npv_pt)              - min_val[25]) / (max_val[25]- min_val[25]);
  NNInputs.at(0).tensor<float, 2>()(0,26)  = (event.get(h_phi_Ak8Puppijet1)    - min_val[26]) / (max_val[26]- min_val[26]);
  NNInputs.at(0).tensor<float, 2>()(0,27)  = (event.get(h_phi_Ak8Puppijet2)    - min_val[27]) / (max_val[27]- min_val[27]);
  NNInputs.at(0).tensor<float, 2>()(0,28)  = (event.get(h_phi_Ak8Puppijet3)    - min_val[28]) / (max_val[28]- min_val[28]);
  NNInputs.at(0).tensor<float, 2>()(0,29)  = (event.get(h_phi_Ak8Puppijets)    - min_val[29]) / (max_val[29]- min_val[29]);
  NNInputs.at(0).tensor<float, 2>()(0,30)  = (event.get(h_phi_jet)             - min_val[30]) / (max_val[30]- min_val[30]);
  NNInputs.at(0).tensor<float, 2>()(0,31)  = (event.get(h_phi_jet1)            - min_val[31]) / (max_val[31]- min_val[31]);
  NNInputs.at(0).tensor<float, 2>()(0,32)  = (event.get(h_phi_jet2)            - min_val[32]) / (max_val[32]- min_val[32]);
  NNInputs.at(0).tensor<float, 2>()(0,33)  = (event.get(h_phi_jet3)            - min_val[33]) / (max_val[33]- min_val[33]);
  NNInputs.at(0).tensor<float, 2>()(0,34)  = (event.get(h_phi_mu)              - min_val[34]) / (max_val[34]- min_val[34]);
  NNInputs.at(0).tensor<float, 2>()(0,35)  = (event.get(h_pt_Ak8Puppijet1)     - min_val[35]) / (max_val[35]- min_val[35]);
  NNInputs.at(0).tensor<float, 2>()(0,36)  = (event.get(h_pt_Ak8Puppijet2)     - min_val[36]) / (max_val[36]- min_val[36]);
  NNInputs.at(0).tensor<float, 2>()(0,37)  = (event.get(h_pt_Ak8Puppijet3)     - min_val[37]) / (max_val[37]- min_val[37]);
  NNInputs.at(0).tensor<float, 2>()(0,38)  = (event.get(h_pt_Ak8Puppijets)     - min_val[38]) / (max_val[38]- min_val[38]);
  NNInputs.at(0).tensor<float, 2>()(0,39)  = (event.get(h_pt_jet)              - min_val[39]) / (max_val[39]- min_val[39]);
  NNInputs.at(0).tensor<float, 2>()(0,40)  = (event.get(h_pt_jet1)             - min_val[40]) / (max_val[40]- min_val[40]);
  NNInputs.at(0).tensor<float, 2>()(0,41)  = (event.get(h_pt_jet2)             - min_val[41]) / (max_val[41]- min_val[41]);
  NNInputs.at(0).tensor<float, 2>()(0,42)  = (event.get(h_pt_jet3)             - min_val[42]) / (max_val[42]- min_val[42]);
  NNInputs.at(0).tensor<float, 2>()(0,43)  = (event.get(h_pt_mu)               - min_val[43]) / (max_val[43]- min_val[43]);
  NNInputs.at(0).tensor<float, 2>()(0,44)  = (event.get(h_ptrel_mu_jet)        - min_val[44]) / (max_val[44]- min_val[44]);
  NNInputs.at(0).tensor<float, 2>()(0,45)  = (event.get(h_reliso_mu)           - min_val[45]) / (max_val[45]- min_val[45]);
  NNInputs.at(0).tensor<float, 2>()(0,46)  = (event.get(h_s11)                 - min_val[46]) / (max_val[46]- min_val[46]);
  NNInputs.at(0).tensor<float, 2>()(0,47)  = (event.get(h_s12)                 - min_val[47]) / (max_val[47]- min_val[47]);
  NNInputs.at(0).tensor<float, 2>()(0,48)  = (event.get(h_s13)                 - min_val[48]) / (max_val[48]- min_val[48]);
  NNInputs.at(0).tensor<float, 2>()(0,49)  = (event.get(h_s22)                 - min_val[49]) / (max_val[49]- min_val[49]);
  NNInputs.at(0).tensor<float, 2>()(0,50)  = (event.get(h_s23)                 - min_val[50]) / (max_val[50]- min_val[50]);
  NNInputs.at(0).tensor<float, 2>()(0,51)  = (event.get(h_s33)                 - min_val[51]) / (max_val[51]- min_val[51]);
  NNInputs.at(0).tensor<float, 2>()(0,52)  = (event.get(h_st)                  - min_val[52]) / (max_val[52]- min_val[52]);
  NNInputs.at(0).tensor<float, 2>()(0,53)  = (event.get(h_st_jets)             - min_val[53]) / (max_val[53]- min_val[53]);
  NNInputs.at(0).tensor<float, 2>()(0,54)  = (event.get(h_st_lep)              - min_val[54]) / (max_val[54]-min_val[54]);

  if (NNInputs.size()!=LayerInputs.size()) throw logic_error("NeuralNetworkModule.cxx: Create a number of inputs diffetent wrt. LayerInputs.size()="+to_string(LayerInputs.size()));
}


class NonResonantTTbarAnalysisModule_applyQCDNN : public ModuleBASE {

public:
  explicit NonResonantTTbarAnalysisModule_applyQCDNN(uhh2::Context&);
  virtual bool process(uhh2::Event&) override;
  void book_histograms(uhh2::Context&, vector<string>);
  void fill_histograms(uhh2::Event&, string);

protected:

  bool debug;

  // Cleaners (to make sure the pre-selection did everything right)
  std::unique_ptr<MuonCleaner> muon_cleaner;
  std::unique_ptr<ElectronCleaner> electron_cleaner;

  // Scale Factors -- Systematics
  unique_ptr<MCMuonScaleFactor> MuonID_module, MuonTrigger_module;
  //unique_ptr<MCElecScaleFactor> EleID_module, EleTrigger_module;

  // AnalysisModules
  unique_ptr<AnalysisModule> LumiWeight_module, PUWeight_module, printer_genparticles, BTagWeight_module; //, TopPtReweight_module, MCScale_module;

  // Taggers
  unique_ptr<AK8PuppiTopTagger> TopTaggerPuppi;

  // Mass reconstruction
  unique_ptr<ZprimeCandidateBuilder> CandidateBuilder;

  // Chi2 discriminator
  unique_ptr<ZprimeChi2Discriminator> Chi2DiscriminatorZprime;
  unique_ptr<ZprimeCorrectMatchDiscriminator> CorrectMatchDiscriminatorZprime;

  // Selections
  unique_ptr<Selection> Trigger1_selection, Trigger2_selection, NMuon1_selection, NMuon2_selection, NElectron_selection, TwoDCut_selection, Jet1_selection, Jet2_selection, Met_selection, Chi2_selection, TTbarMatchable_selection, Chi2CandidateMatched_selection, ZprimeTopTag_selection, BlindData_selection;
  std::unique_ptr<uhh2::Selection> met_sel;
  std::unique_ptr<uhh2::Selection> htlep_sel;
  std::unique_ptr<Selection> sel_1btag, sel_2btag;
  std::unique_ptr<Selection> TopJetBtagSubjet_selection;
  std::unique_ptr<Selection> HEM_selection;

  // NN variables handles
  //unique_ptr<Variables_NN> Variables_module;

  //Handles
  Event::Handle<bool> h_is_zprime_reconstructed_chi2, h_is_zprime_reconstructed_correctmatch;
  Event::Handle<float> h_chi2;  Event::Handle<float> h_weight;
  Event::Handle<float> h_MET;   Event::Handle<int> h_NPV;
  Event::Handle<float> h_lep1_pt; Event::Handle<float> h_lep1_eta;
  Event::Handle<float> h_ak4jet1_pt; Event::Handle<float> h_ak4jet1_eta;
  Event::Handle<float> h_ak8jet1_pt; Event::Handle<float> h_ak8jet1_eta;
  Event::Handle<float> h_Mttbar;

  uhh2::Event::Handle<ZprimeCandidate*> h_BestZprimeCandidateChi2;

  // Configuration
  bool isMC, ispuppi, islooserselection;
  string Sys_MuonID, Sys_MuonTrigger, Sys_PU, Sys_btag; //Sys_EleID, Sys_EleTrigger
  TString sample;
  int runnr_oldtriggers = 299368;

  bool is2016v2, is2016v3, is2017v2, is2018;
  bool isMuon, isElectron;

  Event::Handle<float> h_dR_jet_Ak8Puppijet;
  Event::Handle<float> h_dR_mu_Ak8Puppijet;
  Event::Handle<float> h_dR_mu_jet;
  Event::Handle<float> h_deepjetbscore_jet;
  Event::Handle<float> h_deepjetbscore_jet1;
  Event::Handle<float> h_deepjetbscore_jet2;
  Event::Handle<float> h_deepjetbscore_jet3;
  Event::Handle<float> h_dphi_jet1_MET;
  Event::Handle<float> h_dphi_mu_Ak8Puppijet1;
  Event::Handle<float> h_dphi_mu_MET;
  Event::Handle<float> h_dphi_mu_jet1;
  Event::Handle<float> h_eta_Ak8Puppijet1;
  Event::Handle<float> h_eta_Ak8Puppijet2;
  Event::Handle<float> h_eta_Ak8Puppijet3;
  Event::Handle<float> h_eta_Ak8Puppijets;
  Event::Handle<float> h_eta_jet;
  Event::Handle<float> h_eta_jet1;
  Event::Handle<float> h_eta_jet2;
  Event::Handle<float> h_eta_jet3;;
  Event::Handle<float> h_eta_mu;
  Event::Handle<float> h_mass_jet;
  Event::Handle<float> h_mass_jet1;
  Event::Handle<float> h_mass_jet2;
  Event::Handle<float> h_mass_jet3;
  Event::Handle<float> h_met_pt;
  Event::Handle<float> h_npv_pt;
  Event::Handle<float> h_phi_Ak8Puppijet1;
  Event::Handle<float> h_phi_Ak8Puppijet2;
  Event::Handle<float> h_phi_Ak8Puppijet3;
  Event::Handle<float> h_phi_Ak8Puppijets;
  Event::Handle<float> h_phi_jet;
  Event::Handle<float> h_phi_jet1;
  Event::Handle<float> h_phi_jet2;
  Event::Handle<float> h_phi_jet3;
  Event::Handle<float> h_phi_mu;
  Event::Handle<float> h_pt_Ak8Puppijet1;
  Event::Handle<float> h_pt_Ak8Puppijet2;
  Event::Handle<float> h_pt_Ak8Puppijet3;
  Event::Handle<float> h_pt_Ak8Puppijets;
  Event::Handle<float> h_pt_jet;
  Event::Handle<float> h_pt_jet1;
  Event::Handle<float> h_pt_jet2;
  Event::Handle<float> h_pt_jet3;
  Event::Handle<float> h_pt_mu;
  Event::Handle<float> h_ptrel_mu_jet;
  Event::Handle<float> h_reliso_mu;
  Event::Handle<float> h_s11;
  Event::Handle<float> h_s12;
  Event::Handle<float> h_s13;
  Event::Handle<float> h_s22;
  Event::Handle<float> h_s23;
  Event::Handle<float> h_s33;
  Event::Handle<float> h_st;
  Event::Handle<float> h_st_jets;
  Event::Handle<float> h_st_lep;

  Event::Handle<std::vector<tensorflow::Tensor> > h_NNoutput;
  Event::Handle<double> h_NNoutput0;

  std::unique_ptr<NeuralNetworkModule> NNModule;



};

void NonResonantTTbarAnalysisModule_applyQCDNN::book_histograms(uhh2::Context& ctx, vector<string> tags){
  for(const auto & tag : tags){
    string mytag = tag + "_Skimming";
    mytag = tag+"_General";
    book_HFolder(mytag, new NonResonantTTbarHists(ctx,mytag));
  }
}

void NonResonantTTbarAnalysisModule_applyQCDNN::fill_histograms(uhh2::Event& event, string tag){
  string mytag = tag + "_Skimming";
  mytag = tag+"_General";
  HFolder(mytag)->fill(event);
}

/*
█  ██████  ██████  ███    ██ ███████ ████████ ██████  ██    ██  ██████ ████████  ██████  ██████
█ ██      ██    ██ ████   ██ ██         ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██
█ ██      ██    ██ ██ ██  ██ ███████    ██    ██████  ██    ██ ██         ██    ██    ██ ██████
█ ██      ██    ██ ██  ██ ██      ██    ██    ██   ██ ██    ██ ██         ██    ██    ██ ██   ██
█  ██████  ██████  ██   ████ ███████    ██    ██   ██  ██████   ██████    ██     ██████  ██   ██
*/

NonResonantTTbarAnalysisModule_applyQCDNN::NonResonantTTbarAnalysisModule_applyQCDNN(uhh2::Context& ctx){
  //  debug = true;
  debug = false;
  for(auto & kv : ctx.get_all()){
    cout << " " << kv.first << " = " << kv.second << endl;
  }
  // Configuration
  isMC = (ctx.get("dataset_type") == "MC");
  ispuppi = (ctx.get("is_puppi") == "true");
  TString mode = "chs";
  if(ispuppi) mode = "puppi";
  string tmp = ctx.get("dataset_version");
  sample = tmp;
  is2016v2 = (ctx.get("dataset_version").find("2016v2") != std::string::npos);
  is2016v3 = (ctx.get("dataset_version").find("2016v3") != std::string::npos);
  is2017v2 = (ctx.get("dataset_version").find("2017v2") != std::string::npos);
  is2018 = (ctx.get("dataset_version").find("2018") != std::string::npos);

  // Important selection values
  islooserselection = (ctx.get("is_looser_selection") == "true");
  double muon_pt(55.);
  double elec_pt(80.);
  double jet1_pt(100.);
  double jet2_pt(50.);
  double chi2_max(30.);
  double mtt_blind(3000.);
  int nmuon_min1, nmuon_max1;
  int nmuon_min2, nmuon_max2;
  int nele_min, nele_max;
  string trigger1,trigger2;
  double MET_cut, HT_lep_cut;
  isMuon = false; isElectron = false;
  if(ctx.get("channel") == "muon") isMuon = true;
  if(ctx.get("channel") == "electron") isElectron = true;

  if(isMuon){//semileptonic muon channel
    trigger1 = "HLT_Mu50_v*";
    if(is2016v2 || is2016v3)
    //trigger2 = "HLT_TkMu50_v*";
    trigger2 = "HLT_Mu50_v*"; //TkMu path does not exist in 2017/2018 and RunB 2016
    else
    trigger2 = "HLT_Mu50_v*"; //TkMu path does not exist in 2017/2018
    nmuon_min1 = 1, nmuon_max1 = -1;
    nmuon_min2 = 1, nmuon_max2 = 1;
    nele_min = 0; nele_max = 0;
    MET_cut = 50;
    jet1_pt = 100.;
    HT_lep_cut = 150;
  }
  if(isElectron){//semileptonic electron channel
    nmuon_min1 = 0; nmuon_max1 = 0;
    nmuon_min2 = 0; nmuon_max2 = 0;
    nele_min = 1; nele_max = 1;
    trigger1 = "HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_v*";
    trigger2 = "HLT_Ele115_CaloIdVT_GsfTrkIdT_v*";
    MET_cut = 120;
    jet1_pt = 185.;
    HT_lep_cut = 0;
  }


  double TwoD_dr = 0.4, TwoD_ptrel = 25.;
  if(islooserselection){
    jet1_pt = 100.;
    TwoD_dr = 0.2;
    TwoD_ptrel = 10.;
  }
  const MuonId muonID(PtEtaCut(muon_pt, 2.4));
  const ElectronId electronID(PtEtaSCCut(elec_pt, 2.5));



  Sys_MuonID = ctx.get("Sys_MuonID");
  Sys_MuonTrigger = ctx.get("Sys_MuonTrigger");
  //  Sys_EleID = ctx.get("Sys_EleID");
  //  Sys_EleTrigger = ctx.get("Sys_EleTrigger");
  Sys_PU = ctx.get("Sys_PU");
  Sys_btag = ctx.get("Sys_BTagSF");

  BTag::algo btag_algo = BTag::DEEPJET;
  BTag::wp btag_wp_tight = BTag::WP_TIGHT;
  JetId id_btag = BTag(btag_algo, btag_wp_tight);

  double a_toppt = 0.0615; // par a TopPt Reweighting
  double b_toppt = -0.0005; // par b TopPt Reweighting

  // Modules
  printer_genparticles.reset(new GenParticlesPrinter(ctx));
  muon_cleaner.reset(new MuonCleaner(muonID));
  electron_cleaner.reset(new ElectronCleaner(electronID));
  LumiWeight_module.reset(new MCLumiWeight(ctx));
  PUWeight_module.reset(new MCPileupReweight(ctx, Sys_PU));
  BTagWeight_module.reset(new MCBTagDiscriminantReweighting(ctx, btag_algo, "jets", Sys_btag));
  //TopPtReweight_module.reset(new TopPtReweight(ctx, a_toppt, b_toppt));
  //MCScale_module.reset(new MCScaleVariation(ctx));


  if((is2016v3 || is2016v2) && isMuon){
    MuonID_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/analysis/CMSSW_10_2_10/src/UHH2/common/data/2016/MuonID_EfficienciesAndSF_average_RunBtoH.root", "MC_NUM_TightID_DEN_genTracks_PAR_pt_eta", 0., "MuonID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/analysis/CMSSW_10_2_10/src/UHH2/common/data/2016/MuonTrigger_EfficienciesAndSF_average_RunBtoH.root", "IsoMu50_OR_IsoTkMu50_PtEtaBins", 0.5, "MuonTrigger", true, Sys_MuonTrigger));
  }
  if(is2017v2 && isMuon){
    MuonID_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/RunII_102X_v2/CMSSW_10_2_16/src/UHH2/common/data/2017/MuonID_94X_RunBCDEF_SF_ID.root", "NUM_HighPtID_DEN_genTracks_pair_newTuneP_probe_pt_abseta", 0., "HighPtID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/RunII_102X_v2/CMSSW_10_2_16/src/UHH2/common/data/2017/MuonTrigger_EfficienciesAndSF_RunBtoF_Nov17Nov2017.root", "Mu50_PtEtaBins/pt_abseta_ratio", 0.5, "Trigger", true, Sys_MuonTrigger));
  }
  if(is2018 && isMuon){
    MuonID_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/RunII_102X_v2/CMSSW_10_2_17/src/UHH2/common/data/2018/Muon_ID_SF_RunABCD.root", "NUM_HighPtID_DEN_TrackerMuons_pair_newTuneP_probe_pt_abseta", 0., "HighPtID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/RunII_102X_v2/CMSSW_10_2_17/src/UHH2/common/data/2018/Muon_Trigger_Eff_SF_AfterMuonHLTUpdate.root", "Mu50_OR_OldMu100_OR_TkMu100_PtEtaBins/pt_abseta_ratio", 0.5, "Trigger", true, Sys_MuonTrigger));
    //    EleID_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/RunII_102X_v2/CMSSW_10_2_16/src/UHH2/common/data/2018/2018_ElectronTight.root", 0., "TightID", Sys_EleID));
    //    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/deleokse/RunII_102X_v2/CMSSW_10_2_16/src/UHH2/common/data/2018/SF_2018.root", 0.5, "Trigger", Sys_EleTrigger));
  }

  // Selection modules
  Trigger1_selection.reset(new TriggerSelection(trigger1));
  Trigger2_selection.reset(new TriggerSelection(trigger2));
  NMuon1_selection.reset(new NMuonSelection(nmuon_min1, nmuon_max1));
  NMuon2_selection.reset(new NMuonSelection(nmuon_min2, nmuon_max2));
  NElectron_selection.reset(new NElectronSelection(nele_min, nele_max));
  TwoDCut_selection.reset(new TwoDCut(TwoD_dr, TwoD_ptrel));
  Jet1_selection.reset(new NJetSelection(1, -1, JetId(PtEtaCut(jet1_pt, 2.4))));
  Jet2_selection.reset(new NJetSelection(2, -1, JetId(PtEtaCut(jet2_pt, 2.4))));
  met_sel.reset(new METCut  (MET_cut   , uhh2::infinity));
  htlep_sel.reset(new HTlepCut(HT_lep_cut, uhh2::infinity));

  Chi2_selection.reset(new Chi2Cut(ctx, 0., chi2_max));
  TTbarMatchable_selection.reset(new TTbarSemiLepMatchableSelection());
  Chi2CandidateMatched_selection.reset(new Chi2CandidateMatchedSelection(ctx));
  ZprimeTopTag_selection.reset(new ZprimeTopTagSelection(ctx));
  BlindData_selection.reset(new BlindDataSelection(ctx, mtt_blind));

  HEM_selection.reset(new HEMSelection(ctx)); // HEM issue in 2018, veto on leptons and jets

  //Variables_module.reset(new Variables_NN(ctx)); // variables for NN

  // Taggers
  TopTaggerPuppi.reset(new AK8PuppiTopTagger(ctx));

  // Zprime candidate builder
  CandidateBuilder.reset(new ZprimeCandidateBuilder(ctx, mode));

  // Zprime discriminators
  Chi2DiscriminatorZprime.reset(new ZprimeChi2Discriminator(ctx));
  h_is_zprime_reconstructed_chi2 = ctx.get_handle<bool>("is_zprime_reconstructed_chi2");
  CorrectMatchDiscriminatorZprime.reset(new ZprimeCorrectMatchDiscriminator(ctx));
  h_is_zprime_reconstructed_correctmatch = ctx.get_handle<bool>("is_zprime_reconstructed_correctmatch");
  h_BestZprimeCandidateChi2 = ctx.get_handle<ZprimeCandidate*>("ZprimeCandidateBestChi2");
  h_chi2 = ctx.declare_event_output<float> ("rec_chi2");
  h_MET = ctx.declare_event_output<float> ("met_pt");
  h_Mttbar = ctx.declare_event_output<float> ("Mttbar");
  h_lep1_pt = ctx.declare_event_output<float> ("lep1_pt");
  h_lep1_eta = ctx.declare_event_output<float> ("lep1_eta");
  h_ak4jet1_pt = ctx.declare_event_output<float> ("ak4jet1_pt");
  h_ak4jet1_eta = ctx.declare_event_output<float> ("ak4jet1_eta");
  h_ak8jet1_pt = ctx.declare_event_output<float> ("ak8jet1_pt");
  h_ak8jet1_eta = ctx.declare_event_output<float> ("ak8jet1_eta");

  h_NPV = ctx.declare_event_output<int> ("NPV");
  h_weight = ctx.declare_event_output<float> ("weight");

  sel_1btag.reset(new NJetSelection(1, 1, id_btag));
  sel_2btag.reset(new NJetSelection(2,-1, id_btag));


  TopJetBtagSubjet_selection.reset(new ZprimeBTagFatSubJetSelection(ctx));

  // Book histograms
  vector<string> histogram_tags = {"Weights", "Weights_MuonID", "Weights_PU", "Weights_Lumi", "Weights_BTag", "Weights_TopPt", "Weights_MCScale", "Muon1", "TriggerMuon", "Muon2", "Electron1", "TriggerEle", "TwoDCut", "Jet1", "Jet2", "MET", "HTlep", "NNInputsBeforeReweight_out0", "NNInputsBeforeReweight_out1", "MatchableBeforeChi2Cut", "NotMatchableBeforeChi2Cut", "CorrectMatchBeforeChi2Cut", "NotCorrectMatchBeforeChi2Cut", "Chi2", "Matchable", "NotMatchable", "CorrectMatch", "NotCorrectMatch", "TopTagReconstruction", "NotTopTagReconstruction", "Btags2", "Btags1","TopJetBtagSubjet", "DNN_output0", "DNN_output1"};
  book_histograms(ctx, histogram_tags);


  h_dR_jet_Ak8Puppijet = ctx.get_handle<float> ("dR_jet_Ak8Puppijet");
  h_dR_mu_Ak8Puppijet = ctx.get_handle<float> ("dR_mu_Ak8Puppijet");
  h_dR_mu_jet = ctx.get_handle<float> ("dR_mu_jet");
  h_deepjetbscore_jet = ctx.get_handle<float> ("deepjetbscore_jet");
  h_deepjetbscore_jet1 = ctx.get_handle<float> ("deepjetbscore_jet1");
  h_deepjetbscore_jet2 = ctx.get_handle<float> ("deepjetbscore_jet2");
  h_deepjetbscore_jet3 = ctx.get_handle<float> ("deepjetbscore_jet3");
  h_dphi_jet1_MET = ctx.get_handle<float> ("dphi_jet1_MET");
  h_dphi_mu_Ak8Puppijet1 = ctx.get_handle<float> ("dphi_mu_Ak8Puppijet1");
  h_dphi_mu_MET = ctx.get_handle<float> ("dphi_mu_MET");
  h_dphi_mu_jet1 = ctx.get_handle<float> ("dphi_mu_jet1");
  h_eta_Ak8Puppijet1 = ctx.get_handle<float> ("eta_Ak8Puppijet1");
  h_eta_Ak8Puppijet2 = ctx.get_handle<float> ("eta_Ak8Puppijet2");
  h_eta_Ak8Puppijet3 = ctx.get_handle<float> ("eta_Ak8Puppijet3");
  h_eta_Ak8Puppijets = ctx.get_handle<float> ("eta_Ak8Puppijets");
  h_eta_jet = ctx.get_handle<float> ("eta_jet");
  h_eta_jet1 = ctx.get_handle<float> ("eta_jet1");
  h_eta_jet2 = ctx.get_handle<float> ("eta_jet2");
  h_eta_jet3 = ctx.get_handle<float> ("eta_jet3");
  h_eta_mu = ctx.get_handle<float> ("eta_mu");
  h_mass_jet = ctx.get_handle<float> ("mass_jet");
  h_mass_jet1 = ctx.get_handle<float> ("mass_jet1");
  h_mass_jet2 = ctx.get_handle<float> ("mass_jet2");
  h_mass_jet3 = ctx.get_handle<float> ("mass_jet3");
  h_met_pt = ctx.get_handle<float> ("met_pt");
  h_npv_pt = ctx.get_handle<float> ("npv_pt");
  h_phi_Ak8Puppijet1 = ctx.get_handle<float> ("phi_Ak8Puppijet1");
  h_phi_Ak8Puppijet2 = ctx.get_handle<float> ("phi_Ak8Puppijet2");
  h_phi_Ak8Puppijet3 = ctx.get_handle<float> ("phi_Ak8Puppijet3");
  h_phi_Ak8Puppijets = ctx.get_handle<float> ("phi_Ak8Puppijets");
  h_phi_jet = ctx.get_handle<float> ("phi_jet");
  h_phi_jet1 = ctx.get_handle<float> ("phi_jet1");
  h_phi_jet2 = ctx.get_handle<float> ("phi_jet2");
  h_phi_jet3 = ctx.get_handle<float> ("phi_jet3");
  h_phi_mu = ctx.get_handle<float> ("phi_mu");
  h_pt_Ak8Puppijet1 = ctx.get_handle<float> ("pt_Ak8Puppijet1");
  h_pt_Ak8Puppijet2 = ctx.get_handle<float> ("pt_Ak8Puppijet2");
  h_pt_Ak8Puppijet3 = ctx.get_handle<float> ("pt_Ak8Puppijet3");
  h_pt_Ak8Puppijets = ctx.get_handle<float> ("pt_Ak8Puppijets");
  h_pt_jet = ctx.get_handle<float> ("pt_jet");
  h_pt_jet1 = ctx.get_handle<float> ("pt_jet1");
  h_pt_jet2 = ctx.get_handle<float> ("pt_jet2");
  h_pt_jet3 = ctx.get_handle<float> ("pt_jet3");
  h_pt_mu = ctx.get_handle<float> ("pt_mu");
  h_ptrel_mu_jet = ctx.get_handle<float> ("ptrel_mu_jet");
  h_reliso_mu = ctx.get_handle<float> ("reliso_mu");
  h_s11 = ctx.get_handle<float> ("s11");
  h_s12 = ctx.get_handle<float> ("s12");
  h_s13 = ctx.get_handle<float> ("s13");
  h_s22 = ctx.get_handle<float> ("s22");
  h_s23 = ctx.get_handle<float> ("s23");
  h_s33 = ctx.get_handle<float> ("s33");
  h_st = ctx.get_handle<float> ("st");
  h_st_jets = ctx.get_handle<float> ("st_jets");
  h_st_lep = ctx.get_handle<float> ("st_lep");

  h_NNoutput = ctx.get_handle<std::vector<tensorflow::Tensor>>("NNoutput");
  h_NNoutput0 = ctx.declare_event_output<double>("NNoutput0");
  NNModule.reset( new NeuralNetworkModule(ctx,
    "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/KerasNN/NN_QCD_Titas/model_withoutweight.pb",
    "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/KerasNN/NN_QCD_Titas/model_withoutweight.config.pbtxt"));


  }

  /*
  ██████  ██████   ██████   ██████ ███████ ███████ ███████
  ██   ██ ██   ██ ██    ██ ██      ██      ██      ██
  ██████  ██████  ██    ██ ██      █████   ███████ ███████
  ██      ██   ██ ██    ██ ██      ██           ██      ██
  ██      ██   ██  ██████   ██████ ███████ ███████ ███████
  */

  bool NonResonantTTbarAnalysisModule_applyQCDNN::process(uhh2::Event& event){

    if(debug)   cout << "++++++++++++ NEW EVENT ++++++++++++++" << endl;
    if(debug)   cout<<" run.event: "<<event.run<<". "<<event.event<<endl;
    // Initialize reco flags with false
    event.set(h_is_zprime_reconstructed_chi2, false);
    event.set(h_is_zprime_reconstructed_correctmatch, false);
    event.set(h_chi2,-100);
    event.set(h_MET,-100);
    event.set(h_Mttbar,-100);
    event.set(h_lep1_pt,-100);
    event.set(h_lep1_eta,-100);
    event.set(h_ak4jet1_pt,-100);
    event.set(h_ak4jet1_eta,-100);
    event.set(h_ak8jet1_pt,-100);
    event.set(h_ak8jet1_eta,-100);
    event.set(h_NPV,-100);
    event.set(h_weight,-100);
    // Printing
    // if(!event.isRealData) printer_genparticles->process(event);

    // TODO Apply things that should've been done in the pre-selection already... Fix pre-selection and then remove these steps
    if(isMuon) muon_cleaner->process(event);
    if(isElectron) electron_cleaner->process(event);
    if(debug)  cout<<"Muon and Electron cleaner ok"<<endl;


    if(!HEM_selection->passes(event)){
      if(!isMC) return false;
      else event.weight = event.weight*(1-0.64774715284); // calculated following instructions ar https://twiki.cern.ch/twiki/bin/view/CMS/PdmV2018Analysis
    }

    // Run top-tagging
    TopTaggerPuppi->process(event);
    if(debug) cout<<"Top Tagger ok"<<endl;

    fill_histograms(event, "Weights");

    // Weight modules
    if(isMuon){
      MuonID_module->process(event);
      if(debug)  cout<<"MuonID ok"<<endl;
    }
    fill_histograms(event, "Weights_MuonID");
    // if(isElectron){
    //   EleID_module->process(event);
    //   if(debug)  cout<<"EleID ok"<<endl;
    // }
    PUWeight_module->process(event);
    if(debug)  cout<<"PUWeight ok"<<endl;
    fill_histograms(event, "Weights_PU");

    LumiWeight_module->process(event);
    if(debug)  cout<<"LumiWeight ok"<<endl;
    fill_histograms(event, "Weights_Lumi");

    //  TopPtReweight_module->process(event);
    //  fill_histograms(event, "Weights_TopPt");
    //
    //  MCScale_module->process(event);
    //  fill_histograms(event, "Weights_MCScale");

    BTagWeight_module->process(event);
    fill_histograms(event, "Weights_BTag");
    //  if(!(Trigger1_selection->passes(event)|| Trigger2_selection->passes(event))) return false;
    if(isMuon){
      if(!NMuon1_selection->passes(event)) return false;
      fill_histograms(event, "Muon1");
      MuonTrigger_module->process_onemuon(event, 0);
      fill_histograms(event, "TriggerMuon");
      if(!NMuon2_selection->passes(event)) return false;
      fill_histograms(event, "Muon2");
    }
    //  if(isElectron){
    //    if(!NElectron_selection->passes(event)) return false;
    //    fill_histograms(event, "Electron1");
    //    //EleTrigger_module->process(event);
    //    //fill_histograms(event, "TriggerEle");
    //  }
    //  if((event.muons->size()+event.electrons->size()) != 1) return false; //veto events without leptons or with too many
    //  if(debug) cout<<"N leptons ok: Nelectrons="<<event.electrons->size()<<" Nmuons="<<event.muons->size()<<endl;
    ////  if(!TwoDCut_selection->passes(event)) return false;
    //  fill_histograms(event, "TwoDCut");

    // Here, the Zprime must be reconstructed (we ensured to have >= 2 AK4 jets, >= 1 muon)
    // Only consider well-separated AK4 jets
    // //FixME:
    // for(const TopJet & chsjet : *event.topjets){
    //   int n_separatedjets = 0;
    //   for(unsigned int k = 0; k < event.jets->size(); k++){
    //     if(deltaR(event.jets->at(k), chsjet) > 1.2) n_separatedjets++;
    //   }
    //   //    cout<<"n_separatedjets = "<<n_separatedjets<<endl;
    //   if(n_separatedjets<1) return false;
    // }

    CandidateBuilder->process(event);
    if(debug) cout<<"CandidateBuilder is ok"<<endl;
    Chi2DiscriminatorZprime->process(event);
    if(debug)  cout<<"Chi2DiscriminatorZprime is ok"<<endl;
    CorrectMatchDiscriminatorZprime->process(event);
    if(debug) cout<<"CorrectMatchDiscriminatorZprime is ok"<<endl;
    if(sample.Contains("_blinded")){
      if(!BlindData_selection->passes(event)) return false;
    }
    //  if(!Jet1_selection->passes(event)) return false;
    //  if(debug) cout<<"Jet1_selection is ok"<<endl;
    //  fill_histograms(event, "Jet1");
    //
    //  if(!Jet2_selection->passes(event)) return false;
    //  if(debug) cout<<"Jet2_selection is ok"<<endl;
    //  fill_histograms(event, "Jet2");
    //
    //  // MET selection
    //  if(!met_sel->passes(event)) return false;
    //  if(debug) cout<<"MET is ok"<<endl;
    //  fill_histograms(event, "MET");
    //  if(isMuon){
    //    if(!htlep_sel->passes(event)) return false;
    //    fill_histograms(event, "HTlep");
    //    if(debug) cout<<"HTlep is ok"<<endl;
    //  }

    /*  //  Variables for NN
    Variables_module->process(event);
    fill_histograms(event, "NNInputsBeforeReweight");

    if(TTbarMatchable_selection->passes(event)) fill_histograms(event, "MatchableBeforeChi2Cut");
    else fill_histograms(event, "NotMatchableBeforeChi2Cut");
    if(debug) cout<<"TTbarMatchable_selection is ok"<<endl;

    if(Chi2CandidateMatched_selection->passes(event)) fill_histograms(event, "CorrectMatchBeforeChi2Cut");
    else fill_histograms(event, "NotCorrectMatchBeforeChi2Cut");
    if(debug) cout<<"Chi2CandidateMatched_selection is ok"<<endl;

    if(!Chi2_selection->passes(event)) return false;
    fill_histograms(event, "Chi2");

    if(debug) cout<<"Chi2_selection is ok"<<endl;

    if(TTbarMatchable_selection->passes(event)) fill_histograms(event, "Matchable");
    else fill_histograms(event, "NotMatchable");
    if(debug) cout<<"TTbarMatchable_selection is ok"<<endl;

    if(Chi2CandidateMatched_selection->passes(event)) fill_histograms(event, "CorrectMatch");
    else fill_histograms(event, "NotCorrectMatch");
    if(debug) cout<<"Chi2CandidateMatched_selection is ok"<<endl;

    if(ZprimeTopTag_selection->passes(event)) fill_histograms(event, "TopTagReconstruction");
    else fill_histograms(event, "NotTopTagReconstruction");
    if(debug) cout<<"ZprimeTopTag_selection is ok"<<endl;

    //Test with b-tagging
    if(sel_2btag->passes(event)) fill_histograms(event, "Btags2");
    if(sel_1btag->passes(event)) fill_histograms(event, "Btags1");
    if(debug) cout<<"Btags1 is ok"<<endl;
    if(TopJetBtagSubjet_selection->passes(event)) fill_histograms(event, "TopJetBtagSubjet");
    if(debug) cout<<"TopJetBtagSubjet_selection is ok"<<endl;

    //Fill some vars for monitoring and comparison
    bool is_zprime_reconstructed_chi2 = event.get(h_is_zprime_reconstructed_chi2);
    if(is_zprime_reconstructed_chi2){
    ZprimeCandidate* BestZprimeCandidate = event.get(h_BestZprimeCandidateChi2);
    //    float chi2 = BestZprimeCandidate->discriminator("chi2_total");
    event.set(h_chi2,BestZprimeCandidate->discriminator("chi2_total"));
    event.set(h_Mttbar,BestZprimeCandidate->Zprime_v4().M());
  }
  if(debug) cout<<"Set ttbar reconstruction vars for monitoring"<<endl;

  event.set(h_weight,event.weight);
  event.set(h_MET,event.met->pt());
  if(isMuon){
  event.set(h_lep1_pt,event.muons->at(0).pt());
  event.set(h_lep1_eta,event.muons->at(0).eta());
}
if(isElectron){
event.set(h_lep1_pt,event.electrons->at(0).pt());
event.set(h_lep1_eta,event.electrons->at(0).eta());
}
if(event.jets->size()>0){
event.set(h_ak4jet1_pt,event.jets->at(0).pt());
event.set(h_ak4jet1_eta,event.jets->at(0).eta());
}
if(event.topjets->size()>0){
event.set(h_ak8jet1_pt,event.topjets->at(0).pt());
event.set(h_ak8jet1_eta,event.topjets->at(0).eta());
}
event.set(h_NPV,event.pvs->size());
if(debug) cout<<"Set some vars for monitoring"<<endl;
*/

// NN module
NNModule->process(event);
std::vector<tensorflow::Tensor> NNoutputs = NNModule->GetOutputs();

event.set(h_NNoutput0, (double)(NNoutputs[0].tensor<float, 2>()(0,0)));
event.set(h_NNoutput, NNoutputs);

double out0 = (double)(NNoutputs[0].tensor<float, 2>()(0,0));

if( out0 >= 0.5 ){ // QCD node
  fill_histograms(event, "DNN_output0");
}

if( out0 < 0.5 ){ // other backgrounds
  fill_histograms(event, "DNN_output1");
}

if( out0 >= 0.5 )  return false;

return true;
}

UHH2_REGISTER_ANALYSIS_MODULE(NonResonantTTbarAnalysisModule_applyQCDNN)
