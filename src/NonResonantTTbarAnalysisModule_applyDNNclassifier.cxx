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
#include <UHH2/common/include/TTbarReconstruction.h>
#include <UHH2/common/include/ReconstructionHypothesisDiscriminators.h>
#include "UHH2/common/include/NeuralNetworkBase.hpp"

#include <UHH2/NonResonantTTbar/include/ModuleBASE.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarSelections.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarModules.h>
#include <UHH2/NonResonantTTbar/include/TTbarLJHists.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarHists.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarMulticlassNNHists.h>
#include <UHH2/NonResonantTTbar/include/NonResonantTTbarGeneratorHists.h>
#include <UHH2/NonResonantTTbar/include/ZprimeCandidate.h>

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

  uhh2::Event::Handle<float> h_Ak4_j1_E;
  uhh2::Event::Handle<float> h_Ak4_j1_deepjetbscore;
  uhh2::Event::Handle<float> h_Ak4_j1_eta;
  uhh2::Event::Handle<float> h_Ak4_j1_m;
  uhh2::Event::Handle<float> h_Ak4_j1_phi;
  uhh2::Event::Handle<float> h_Ak4_j1_pt;

  uhh2::Event::Handle<float> h_Ak4_j2_E;
  uhh2::Event::Handle<float> h_Ak4_j2_deepjetbscore;
  uhh2::Event::Handle<float> h_Ak4_j2_eta;
  uhh2::Event::Handle<float> h_Ak4_j2_m;
  uhh2::Event::Handle<float> h_Ak4_j2_phi;
  uhh2::Event::Handle<float> h_Ak4_j2_pt;

  uhh2::Event::Handle<float> h_Ak4_j3_E;
  uhh2::Event::Handle<float> h_Ak4_j3_deepjetbscore;
  uhh2::Event::Handle<float> h_Ak4_j3_eta;
  uhh2::Event::Handle<float> h_Ak4_j3_m;
  uhh2::Event::Handle<float> h_Ak4_j3_phi;
  uhh2::Event::Handle<float> h_Ak4_j3_pt;

  uhh2::Event::Handle<float> h_Ak4_j4_E;
  uhh2::Event::Handle<float> h_Ak4_j4_deepjetbscore;
  uhh2::Event::Handle<float> h_Ak4_j4_eta;
  uhh2::Event::Handle<float> h_Ak4_j4_m;
  uhh2::Event::Handle<float> h_Ak4_j4_phi;
  uhh2::Event::Handle<float> h_Ak4_j4_pt;

  uhh2::Event::Handle<float> h_Ak4_j5_E;
  uhh2::Event::Handle<float> h_Ak4_j5_deepjetbscore;
  uhh2::Event::Handle<float> h_Ak4_j5_eta;
  uhh2::Event::Handle<float> h_Ak4_j5_m;
  uhh2::Event::Handle<float> h_Ak4_j5_phi;
  uhh2::Event::Handle<float> h_Ak4_j5_pt;

  uhh2::Event::Handle<float> h_Ak4_j6_E;
  uhh2::Event::Handle<float> h_Ak4_j6_deepjetbscore;
  uhh2::Event::Handle<float> h_Ak4_j6_eta;
  uhh2::Event::Handle<float> h_Ak4_j6_m;
  uhh2::Event::Handle<float> h_Ak4_j6_phi;
  uhh2::Event::Handle<float> h_Ak4_j6_pt;

  uhh2::Event::Handle<float> h_Ak8_j1_E;
  uhh2::Event::Handle<float> h_Ak8_j1_eta;
  uhh2::Event::Handle<float> h_Ak8_j1_mSD;
  uhh2::Event::Handle<float> h_Ak8_j1_phi;
  uhh2::Event::Handle<float> h_Ak8_j1_pt;
  uhh2::Event::Handle<float> h_Ak8_j1_tau21;
  uhh2::Event::Handle<float> h_Ak8_j1_tau32;

  uhh2::Event::Handle<float> h_Ak8_j2_E;
  uhh2::Event::Handle<float> h_Ak8_j2_eta;
  uhh2::Event::Handle<float> h_Ak8_j2_mSD;
  uhh2::Event::Handle<float> h_Ak8_j2_phi;
  uhh2::Event::Handle<float> h_Ak8_j2_pt;
  uhh2::Event::Handle<float> h_Ak8_j2_tau21;
  uhh2::Event::Handle<float> h_Ak8_j2_tau32;

  uhh2::Event::Handle<float> h_Ak8_j3_E;
  uhh2::Event::Handle<float> h_Ak8_j3_eta;
  uhh2::Event::Handle<float> h_Ak8_j3_mSD;
  uhh2::Event::Handle<float> h_Ak8_j3_phi;
  uhh2::Event::Handle<float> h_Ak8_j3_pt;
  uhh2::Event::Handle<float> h_Ak8_j3_tau21;
  uhh2::Event::Handle<float> h_Ak8_j3_tau32;

  uhh2::Event::Handle<float> h_MET_phi;
  uhh2::Event::Handle<float> h_MET_pt;

  uhh2::Event::Handle<float> h_Mu_E;
  uhh2::Event::Handle<float> h_Mu_eta;
  uhh2::Event::Handle<float> h_Mu_phi;
  uhh2::Event::Handle<float> h_Mu_pt;

  uhh2::Event::Handle<float> h_N_Ak4;
  uhh2::Event::Handle<float> h_N_Ak8;
};


NeuralNetworkModule::NeuralNetworkModule(Context& ctx, const std::string & ModelName, const std::string& ConfigName): NeuralNetworkBase(ctx, ModelName, ConfigName){


  h_Ak4_j1_E             = ctx.get_handle<float>("Ak4_j1_E");
  h_Ak4_j1_deepjetbscore = ctx.get_handle<float>("Ak4_j1_deepjetbscore");
  h_Ak4_j1_eta           = ctx.get_handle<float>("Ak4_j1_eta");
  h_Ak4_j1_m             = ctx.get_handle<float>("Ak4_j1_m");
  h_Ak4_j1_phi           = ctx.get_handle<float>("Ak4_j1_phi");
  h_Ak4_j1_pt            = ctx.get_handle<float>("Ak4_j1_pt");

  h_Ak4_j2_E             = ctx.get_handle<float>("Ak4_j2_E");
  h_Ak4_j2_deepjetbscore = ctx.get_handle<float>("Ak4_j2_deepjetbscore");
  h_Ak4_j2_eta           = ctx.get_handle<float>("Ak4_j2_eta");
  h_Ak4_j2_m             = ctx.get_handle<float>("Ak4_j2_m");
  h_Ak4_j2_phi           = ctx.get_handle<float>("Ak4_j2_phi");
  h_Ak4_j2_pt            = ctx.get_handle<float>("Ak4_j2_pt");

  h_Ak4_j3_E             = ctx.get_handle<float>("Ak4_j3_E");
  h_Ak4_j3_deepjetbscore = ctx.get_handle<float>("Ak4_j3_deepjetbscore");
  h_Ak4_j3_eta           = ctx.get_handle<float>("Ak4_j3_eta");
  h_Ak4_j3_m             = ctx.get_handle<float>("Ak4_j3_m");
  h_Ak4_j3_phi           = ctx.get_handle<float>("Ak4_j3_phi");
  h_Ak4_j3_pt            = ctx.get_handle<float>("Ak4_j3_pt");

  h_Ak4_j4_E             = ctx.get_handle<float>("Ak4_j4_E");
  h_Ak4_j4_deepjetbscore = ctx.get_handle<float>("Ak4_j4_deepjetbscore");
  h_Ak4_j4_eta           = ctx.get_handle<float>("Ak4_j4_eta");
  h_Ak4_j4_m             = ctx.get_handle<float>("Ak4_j4_m");
  h_Ak4_j4_phi           = ctx.get_handle<float>("Ak4_j4_phi");
  h_Ak4_j4_pt            = ctx.get_handle<float>("Ak4_j4_pt");

  h_Ak4_j5_E             = ctx.get_handle<float>("Ak4_j5_E");
  h_Ak4_j5_deepjetbscore = ctx.get_handle<float>("Ak4_j5_deepjetbscore");
  h_Ak4_j5_eta           = ctx.get_handle<float>("Ak4_j5_eta");
  h_Ak4_j5_m             = ctx.get_handle<float>("Ak4_j5_m");
  h_Ak4_j5_phi           = ctx.get_handle<float>("Ak4_j5_phi");
  h_Ak4_j5_pt            = ctx.get_handle<float>("Ak4_j5_pt");

  h_Ak4_j6_E             = ctx.get_handle<float>("Ak4_j6_E");
  h_Ak4_j6_deepjetbscore = ctx.get_handle<float>("Ak4_j6_deepjetbscore");
  h_Ak4_j6_eta           = ctx.get_handle<float>("Ak4_j6_eta");
  h_Ak4_j6_m             = ctx.get_handle<float>("Ak4_j6_m");
  h_Ak4_j6_phi           = ctx.get_handle<float>("Ak4_j6_phi");
  h_Ak4_j6_pt            = ctx.get_handle<float>("Ak4_j6_pt");

  h_Ak8_j1_E     = ctx.get_handle<float>("Ak8_j1_E");
  h_Ak8_j1_eta   = ctx.get_handle<float>("Ak8_j1_eta");
  h_Ak8_j1_mSD   = ctx.get_handle<float>("Ak8_j1_mSD");
  h_Ak8_j1_phi   = ctx.get_handle<float>("Ak8_j1_phi");
  h_Ak8_j1_pt    = ctx.get_handle<float>("Ak8_j1_pt");
  h_Ak8_j1_tau21 = ctx.get_handle<float>("Ak8_j1_tau21");
  h_Ak8_j1_tau32 = ctx.get_handle<float>("Ak8_j1_tau32");

  h_Ak8_j2_E     = ctx.get_handle<float>("Ak8_j2_E");
  h_Ak8_j2_eta   = ctx.get_handle<float>("Ak8_j2_eta");
  h_Ak8_j2_mSD   = ctx.get_handle<float>("Ak8_j2_mSD");
  h_Ak8_j2_phi   = ctx.get_handle<float>("Ak8_j2_phi");
  h_Ak8_j2_pt    = ctx.get_handle<float>("Ak8_j2_pt");
  h_Ak8_j2_tau21 = ctx.get_handle<float>("Ak8_j2_tau21");
  h_Ak8_j2_tau32 = ctx.get_handle<float>("Ak8_j2_tau32");

  h_Ak8_j3_E     = ctx.get_handle<float>("Ak8_j3_E");
  h_Ak8_j3_eta   = ctx.get_handle<float>("Ak8_j3_eta");
  h_Ak8_j3_mSD   = ctx.get_handle<float>("Ak8_j3_mSD");
  h_Ak8_j3_phi   = ctx.get_handle<float>("Ak8_j3_phi");
  h_Ak8_j3_pt    = ctx.get_handle<float>("Ak8_j3_pt");
  h_Ak8_j3_tau21 = ctx.get_handle<float>("Ak8_j3_tau21");
  h_Ak8_j3_tau32 = ctx.get_handle<float>("Ak8_j3_tau32");

  h_MET_phi = ctx.get_handle<float>("MET_phi");
  h_MET_pt  = ctx.get_handle<float>("MET_pt");

  h_Mu_E   = ctx.get_handle<float>("Mu_E");
  h_Mu_eta = ctx.get_handle<float>("Mu_eta");
  h_Mu_phi = ctx.get_handle<float>("Mu_phi");
  h_Mu_pt  = ctx.get_handle<float>("Mu_pt");

  h_N_Ak4 = ctx.get_handle<float>("N_Ak4");
  h_N_Ak8 = ctx.get_handle<float>("N_Ak8");
}

void NeuralNetworkModule::CreateInputs(Event & event){
  NNInputs.clear();
  NNoutputs.clear();

  string varname[65];
  string scal[65];
  string mean[65];
  string std[65];
  double mean_val[65];
  double std_val[65];
  ifstream normfile ("/nfs/dust/cms/user/jabuschh/UHH2_UL_10_6_28/CMSSW_10_6_28/src/UHH2/NonResonantTTbar/DNN_models/DNN_layers_512_512__batchsize_131072__classes_3_TTbar_ST_WJets+DY__regmethod_dropout__regrate_050000__batchnorm_False__epochs_500__learningrate_000050__runonfraction_100__eqweight_False__preprocess_StandardScaler__priorSigma_100/NormInfo.txt", ios::in);
  if (normfile.is_open()){
    for(int i = 0; i < 65; ++i){
      normfile >> varname[i] >> scal[i] >> mean[i] >> std[i];
      mean_val[i] = std::stod(mean[i]);
      std_val[i] = std::stod(std[i]);
    }
    normfile.close();
  }

  NNInputs.push_back( tensorflow::Tensor(tensorflow::DT_FLOAT, {1, 65}));

  NNInputs.at(0).tensor<float, 2>()(0,0) = (event.get(h_Ak4_j1_E)             - mean_val[0]) / (std_val[0]);
  NNInputs.at(0).tensor<float, 2>()(0,1) = (event.get(h_Ak4_j1_deepjetbscore) - mean_val[1]) / (std_val[1]);
  NNInputs.at(0).tensor<float, 2>()(0,2) = (event.get(h_Ak4_j1_eta)           - mean_val[2]) / (std_val[2]);
  NNInputs.at(0).tensor<float, 2>()(0,3) = (event.get(h_Ak4_j1_m)             - mean_val[3]) / (std_val[3]);
  NNInputs.at(0).tensor<float, 2>()(0,4) = (event.get(h_Ak4_j1_phi)           - mean_val[4]) / (std_val[4]);
  NNInputs.at(0).tensor<float, 2>()(0,5) = (event.get(h_Ak4_j1_pt)            - mean_val[5]) / (std_val[5]);

  NNInputs.at(0).tensor<float, 2>()(0,6)  = (event.get(h_Ak4_j2_E)             - mean_val[6]) / (std_val[6]);
  NNInputs.at(0).tensor<float, 2>()(0,7)  = (event.get(h_Ak4_j2_deepjetbscore) - mean_val[7]) / (std_val[7]);
  NNInputs.at(0).tensor<float, 2>()(0,8)  = (event.get(h_Ak4_j2_eta)           - mean_val[8]) / (std_val[8]);
  NNInputs.at(0).tensor<float, 2>()(0,9)  = (event.get(h_Ak4_j2_m)             - mean_val[9]) / (std_val[9]);
  NNInputs.at(0).tensor<float, 2>()(0,10) = (event.get(h_Ak4_j2_phi)           - mean_val[10]) / (std_val[10]);
  NNInputs.at(0).tensor<float, 2>()(0,11) = (event.get(h_Ak4_j2_pt)            - mean_val[11]) / (std_val[11]);

  NNInputs.at(0).tensor<float, 2>()(0,12) = (event.get(h_Ak4_j3_E)   - mean_val[12]) / (std_val[12]);
  NNInputs.at(0).tensor<float, 2>()(0,13) = (event.get(h_Ak4_j3_deepjetbscore) - mean_val[13]) / (std_val[13]);
  NNInputs.at(0).tensor<float, 2>()(0,14) = (event.get(h_Ak4_j3_eta) - mean_val[14]) / (std_val[14]);
  NNInputs.at(0).tensor<float, 2>()(0,15) = (event.get(h_Ak4_j3_m)   - mean_val[15]) / (std_val[15]);
  NNInputs.at(0).tensor<float, 2>()(0,16) = (event.get(h_Ak4_j3_phi) - mean_val[16]) / (std_val[16]);
  NNInputs.at(0).tensor<float, 2>()(0,17) = (event.get(h_Ak4_j3_pt)  - mean_val[17]) / (std_val[17]);

  NNInputs.at(0).tensor<float, 2>()(0,18) = (event.get(h_Ak4_j4_E)             - mean_val[18]) / (std_val[18]);
  NNInputs.at(0).tensor<float, 2>()(0,19) = (event.get(h_Ak4_j4_deepjetbscore) - mean_val[19]) / (std_val[19]);
  NNInputs.at(0).tensor<float, 2>()(0,20) = (event.get(h_Ak4_j4_eta)           - mean_val[20]) / (std_val[20]);
  NNInputs.at(0).tensor<float, 2>()(0,21) = (event.get(h_Ak4_j4_m)             - mean_val[21]) / (std_val[21]);
  NNInputs.at(0).tensor<float, 2>()(0,22) = (event.get(h_Ak4_j4_phi)           - mean_val[22]) / (std_val[22]);
  NNInputs.at(0).tensor<float, 2>()(0,23) = (event.get(h_Ak4_j4_pt)            - mean_val[23]) / (std_val[23]);

  NNInputs.at(0).tensor<float, 2>()(0,24) = (event.get(h_Ak4_j5_E)             - mean_val[24]) / (std_val[24]);
  NNInputs.at(0).tensor<float, 2>()(0,25) = (event.get(h_Ak4_j4_deepjetbscore) - mean_val[25]) / (std_val[25]);
  NNInputs.at(0).tensor<float, 2>()(0,26) = (event.get(h_Ak4_j5_eta)           - mean_val[26]) / (std_val[26]);
  NNInputs.at(0).tensor<float, 2>()(0,27) = (event.get(h_Ak4_j5_m)             - mean_val[27]) / (std_val[27]);
  NNInputs.at(0).tensor<float, 2>()(0,28) = (event.get(h_Ak4_j5_phi)           - mean_val[28]) / (std_val[28]);
  NNInputs.at(0).tensor<float, 2>()(0,29) = (event.get(h_Ak4_j5_pt)            - mean_val[29]) / (std_val[29]);

  NNInputs.at(0).tensor<float, 2>()(0,30) = (event.get(h_Ak4_j6_E)             - mean_val[30]) / (std_val[30]);
  NNInputs.at(0).tensor<float, 2>()(0,31) = (event.get(h_Ak4_j6_deepjetbscore) - mean_val[31]) / (std_val[31]);
  NNInputs.at(0).tensor<float, 2>()(0,32) = (event.get(h_Ak4_j6_eta)           - mean_val[32]) / (std_val[32]);
  NNInputs.at(0).tensor<float, 2>()(0,33) = (event.get(h_Ak4_j6_m)             - mean_val[33]) / (std_val[33]);
  NNInputs.at(0).tensor<float, 2>()(0,34) = (event.get(h_Ak4_j6_phi)           - mean_val[34]) / (std_val[34]);
  NNInputs.at(0).tensor<float, 2>()(0,35) = (event.get(h_Ak4_j6_pt)            - mean_val[35]) / (std_val[35]);

  NNInputs.at(0).tensor<float, 2>()(0,36) = (event.get(h_Ak8_j1_E)     - mean_val[36]) / (std_val[36]);
  NNInputs.at(0).tensor<float, 2>()(0,37) = (event.get(h_Ak8_j1_eta)   - mean_val[37]) / (std_val[37]);
  NNInputs.at(0).tensor<float, 2>()(0,38) = (event.get(h_Ak8_j1_mSD)   - mean_val[38]) / (std_val[38]);
  NNInputs.at(0).tensor<float, 2>()(0,39) = (event.get(h_Ak8_j1_phi)   - mean_val[39]) / (std_val[39]);
  NNInputs.at(0).tensor<float, 2>()(0,40) = (event.get(h_Ak8_j1_pt)    - mean_val[40]) / (std_val[40]);
  NNInputs.at(0).tensor<float, 2>()(0,41) = (event.get(h_Ak8_j1_tau21) - mean_val[41]) / (std_val[41]);
  NNInputs.at(0).tensor<float, 2>()(0,42) = (event.get(h_Ak8_j1_tau32) - mean_val[42]) / (std_val[42]);

  NNInputs.at(0).tensor<float, 2>()(0,43) = (event.get(h_Ak8_j2_E)     - mean_val[43]) / (std_val[43]);
  NNInputs.at(0).tensor<float, 2>()(0,44) = (event.get(h_Ak8_j2_eta)   - mean_val[44]) / (std_val[44]);
  NNInputs.at(0).tensor<float, 2>()(0,45) = (event.get(h_Ak8_j2_mSD)   - mean_val[45]) / (std_val[45]);
  NNInputs.at(0).tensor<float, 2>()(0,46) = (event.get(h_Ak8_j2_phi)   - mean_val[46]) / (std_val[46]);
  NNInputs.at(0).tensor<float, 2>()(0,47) = (event.get(h_Ak8_j2_pt)    - mean_val[47]) / (std_val[47]);
  NNInputs.at(0).tensor<float, 2>()(0,48) = (event.get(h_Ak8_j2_tau21) - mean_val[48]) / (std_val[48]);
  NNInputs.at(0).tensor<float, 2>()(0,49) = (event.get(h_Ak8_j2_tau32) - mean_val[49]) / (std_val[49]);

  NNInputs.at(0).tensor<float, 2>()(0,50) = (event.get(h_Ak8_j3_E)     - mean_val[50]) / (std_val[50]);
  NNInputs.at(0).tensor<float, 2>()(0,51) = (event.get(h_Ak8_j3_eta)   - mean_val[51]) / (std_val[51]);
  NNInputs.at(0).tensor<float, 2>()(0,52) = (event.get(h_Ak8_j3_mSD)   - mean_val[52]) / (std_val[52]);
  NNInputs.at(0).tensor<float, 2>()(0,53) = (event.get(h_Ak8_j3_phi)   - mean_val[53]) / (std_val[53]);
  NNInputs.at(0).tensor<float, 2>()(0,54) = (event.get(h_Ak8_j3_pt)    - mean_val[54]) / (std_val[54]);
  NNInputs.at(0).tensor<float, 2>()(0,55) = (event.get(h_Ak8_j3_tau21) - mean_val[55]) / (std_val[55]);
  NNInputs.at(0).tensor<float, 2>()(0,56) = (event.get(h_Ak8_j3_tau32) - mean_val[56]) / (std_val[56]);

  NNInputs.at(0).tensor<float, 2>()(0,57) = (event.get(h_MET_phi) - mean_val[57]) / (std_val[57]);
  NNInputs.at(0).tensor<float, 2>()(0,58) = (event.get(h_MET_pt)  - mean_val[58]) / (std_val[58]);

  NNInputs.at(0).tensor<float, 2>()(0,59) = (event.get(h_Mu_E)   - mean_val[59]) / (std_val[59]);
  NNInputs.at(0).tensor<float, 2>()(0,60) = (event.get(h_Mu_eta) - mean_val[60]) / (std_val[60]);
  NNInputs.at(0).tensor<float, 2>()(0,61) = (event.get(h_Mu_phi) - mean_val[61]) / (std_val[61]);
  NNInputs.at(0).tensor<float, 2>()(0,62) = (event.get(h_Mu_pt)  - mean_val[62]) / (std_val[62]);

  NNInputs.at(0).tensor<float, 2>()(0,63) = (event.get(h_N_Ak4) - mean_val[63]) / (std_val[63]);
  NNInputs.at(0).tensor<float, 2>()(0,64) = (event.get(h_N_Ak8) - mean_val[64]) / (std_val[64]);

  if(NNInputs.size() != LayerInputs.size()) throw logic_error("NeuralNetworkModule.cxx: Create a number of inputs diffetent wrt. LayerInputs.size()="+to_string(LayerInputs.size()));
}


class NonResonantTTbarAnalysisModule_applyDNNclassifier : public ModuleBASE {

public:
  explicit NonResonantTTbarAnalysisModule_applyDNNclassifier(uhh2::Context&);
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
  unique_ptr<MCElecScaleFactor> EleID_module, EleTrigger_module;

  // AnalysisModules
  unique_ptr<AnalysisModule> LumiWeight_module, PUWeight_module, printer_genparticles, BTagWeight_module, TopPtReweight_module, MCScale_module;
  unique_ptr<AnalysisModule> Corrections_module;

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
  unique_ptr<Variables_NN> Variables_module;

  //Handles
  Event::Handle<bool>  h_is_zprime_reconstructed_chi2, h_is_zprime_reconstructed_correctmatch;
  Event::Handle<float> h_chi2;
  Event::Handle<float> h_weight;
  Event::Handle<float> h_MET;
  Event::Handle<int>   h_NPV;
  Event::Handle<float> h_lep1_pt;
  Event::Handle<float> h_lep1_eta;
  Event::Handle<float> h_ak4jet1_pt;
  Event::Handle<float> h_ak4jet1_eta;
  Event::Handle<float> h_ak8jet1_pt;
  Event::Handle<float> h_ak8jet1_eta;
  Event::Handle<float> h_Mttbar;
  Event::Handle<float> h_muonrecoSF_nominal;
  Event::Handle<float> h_muonrecoSF_up;
  Event::Handle<float> h_muonrecoSF_down;

  uhh2::Event::Handle<ZprimeCandidate*> h_BestZprimeCandidateChi2;

  // DNN multiclass output hist
  std::unique_ptr<Hists> h_MulticlassNN_output;

  // Configuration
  bool isMC, ispuppi, islooserselection;
  string Sys_MuonID, Sys_MuonTrigger, Sys_PU, Sys_btag, Sys_EleID, Sys_EleTrigger;
  TString sample;
  int runnr_oldtriggers = 299368;

  bool is2016v2, is2016v3, is2017v2, is2018, isUL16preVFP, isUL16postVFP, isUL17, isUL18;
  bool isMuon, isElectron;

  Event::Handle<float> h_Ak4_j1_E;
  Event::Handle<float> h_Ak4_j1_deepjetbscore;
  Event::Handle<float> h_Ak4_j1_eta;
  Event::Handle<float> h_Ak4_j1_m;
  Event::Handle<float> h_Ak4_j1_phi;
  Event::Handle<float> h_Ak4_j1_pt;

  Event::Handle<float> h_Ak4_j2_E;
  Event::Handle<float> h_Ak4_j2_deepjetbscore;
  Event::Handle<float> h_Ak4_j2_eta;
  Event::Handle<float> h_Ak4_j2_m;
  Event::Handle<float> h_Ak4_j2_phi;
  Event::Handle<float> h_Ak4_j2_pt;

  Event::Handle<float> h_Ak4_j3_E;
  Event::Handle<float> h_Ak4_j3_deepjetbscore;
  Event::Handle<float> h_Ak4_j3_eta;
  Event::Handle<float> h_Ak4_j3_m;
  Event::Handle<float> h_Ak4_j3_phi;
  Event::Handle<float> h_Ak4_j3_pt;

  Event::Handle<float> h_Ak4_j4_E;
  Event::Handle<float> h_Ak4_j4_deepjetbscore;
  Event::Handle<float> h_Ak4_j4_eta;
  Event::Handle<float> h_Ak4_j4_m;
  Event::Handle<float> h_Ak4_j4_phi;
  Event::Handle<float> h_Ak4_j4_pt;

  Event::Handle<float> h_Ak4_j5_E;
  Event::Handle<float> h_Ak4_j5_deepjetbscore;
  Event::Handle<float> h_Ak4_j5_eta;
  Event::Handle<float> h_Ak4_j5_m;
  Event::Handle<float> h_Ak4_j5_phi;
  Event::Handle<float> h_Ak4_j5_pt;

  Event::Handle<float> h_Ak4_j6_E;
  Event::Handle<float> h_Ak4_j6_deepjetbscore;
  Event::Handle<float> h_Ak4_j6_eta;
  Event::Handle<float> h_Ak4_j6_m;
  Event::Handle<float> h_Ak4_j6_phi;
  Event::Handle<float> h_Ak4_j6_pt;

  Event::Handle<float> h_Ak8_j1_E;
  Event::Handle<float> h_Ak8_j1_eta;
  Event::Handle<float> h_Ak8_j1_mSD;
  Event::Handle<float> h_Ak8_j1_phi;
  Event::Handle<float> h_Ak8_j1_pt;
  Event::Handle<float> h_Ak8_j1_tau21;
  Event::Handle<float> h_Ak8_j1_tau32;

  Event::Handle<float> h_Ak8_j2_E;
  Event::Handle<float> h_Ak8_j2_eta;
  Event::Handle<float> h_Ak8_j2_mSD;
  Event::Handle<float> h_Ak8_j2_phi;
  Event::Handle<float> h_Ak8_j2_pt;
  Event::Handle<float> h_Ak8_j2_tau21;
  Event::Handle<float> h_Ak8_j2_tau32;

  Event::Handle<float> h_Ak8_j3_E;
  Event::Handle<float> h_Ak8_j3_eta;
  Event::Handle<float> h_Ak8_j3_mSD;
  Event::Handle<float> h_Ak8_j3_phi;
  Event::Handle<float> h_Ak8_j3_pt;
  Event::Handle<float> h_Ak8_j3_tau21;
  Event::Handle<float> h_Ak8_j3_tau32;

  Event::Handle<float> h_MET_phi;
  Event::Handle<float> h_MET_pt;

  Event::Handle<float> h_Mu_E;
  Event::Handle<float> h_Mu_eta;
  Event::Handle<float> h_Mu_phi;
  Event::Handle<float> h_Mu_pt;

  Event::Handle<float> h_N_Ak4;
  Event::Handle<float> h_N_Ak8;



  Event::Handle<std::vector<tensorflow::Tensor> > h_NNoutput;
  Event::Handle<double> h_NNoutput0;
  Event::Handle<double> h_NNoutput1;
  Event::Handle<double> h_NNoutput2;

  std::unique_ptr<NeuralNetworkModule> NNModule;

};

void NonResonantTTbarAnalysisModule_applyDNNclassifier::book_histograms(uhh2::Context& ctx, vector<string> tags){
  for(const auto & tag : tags){
    string mytag = tag + "_Skimming";
    mytag = tag+"_General";
    book_HFolder(mytag, new NonResonantTTbarHists(ctx,mytag));
  }
}

void NonResonantTTbarAnalysisModule_applyDNNclassifier::fill_histograms(uhh2::Event& event, string tag){
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

NonResonantTTbarAnalysisModule_applyDNNclassifier::NonResonantTTbarAnalysisModule_applyDNNclassifier(uhh2::Context& ctx){
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
  is2016v2      = (ctx.get("dataset_version").find("2016v2")      != std::string::npos);
  is2016v3      = (ctx.get("dataset_version").find("2016v3")      != std::string::npos);
  is2017v2      = (ctx.get("dataset_version").find("2017v2")      != std::string::npos);
  is2018        = (ctx.get("dataset_version").find("2018")        != std::string::npos);
  isUL16preVFP  = (ctx.get("dataset_version").find("UL16preVFP")  != std::string::npos);
  isUL16postVFP = (ctx.get("dataset_version").find("UL16postVFP") != std::string::npos);
  isUL17        = (ctx.get("dataset_version").find("UL17")        != std::string::npos);
  isUL18        = (ctx.get("dataset_version").find("UL18")        != std::string::npos);

  // Important selection values
  islooserselection = (ctx.get("is_looser_selection") == "true");
  double muon_pt(55.);
  double elec_pt(80.);
  double jet1_pt(150.);
  double jet2_pt(50.);
  double chi2_max(30.);
  // double mtt_blind(2000.);
  int nmuon_min1, nmuon_max1;
  int nmuon_min2, nmuon_max2;
  int nele_min, nele_max;
  string trigger1,trigger2;
  double MET_cut, HT_lep_cut;
  isMuon = false; isElectron = false;
  if(ctx.get("channel") == "muon") isMuon = true;
  if(ctx.get("channel") == "electron") isElectron = true;

  if(isMuon){ //semileptonic muon channel
    trigger1 = "HLT_Mu50_v*";
    trigger2 = "HLT_Mu50_v*";
    nmuon_min1 = 1, nmuon_max1 = -1;
    nmuon_min2 = 1, nmuon_max2 = 1;
    nele_min = 0; nele_max = 0;
    MET_cut = 50;
    jet1_pt = 150.;
    HT_lep_cut = 150;
  }
  if(isElectron){ //semileptonic electron channel
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



  Sys_MuonID      = ctx.get("Sys_MuonID");
  Sys_MuonTrigger = ctx.get("Sys_MuonTrigger");
  Sys_EleID       = ctx.get("Sys_EleID");
  Sys_EleTrigger  = ctx.get("Sys_EleTrigger");
  Sys_PU          = ctx.get("Sys_PU");
  Sys_btag        = ctx.get("Sys_BTagSF");

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
  //BTagWeight_module.reset(new MCBTagDiscriminantReweighting(ctx, btag_algo, "jets", Sys_btag));
  TopPtReweight_module.reset(new TopPtReweight(ctx, a_toppt, b_toppt));
  MCScale_module.reset(new MCScaleVariation(ctx));
  Corrections_module.reset(new NLOCorrections(ctx));


  // Muon
  if((is2016v3 || is2016v2) && isMuon){
    MuonID_module     .reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2016/MuonID_EfficienciesAndSF_average_RunBtoH.root"     , "NUM_TightID_DEN_genTracks_eta_pt", 1.0, "MuonID"     , true, Sys_MuonID)); // NUM_TightID_DEN_genTracks_eta_pt ? old: MC_NUM_TightID_DEN_genTracks_PAR_pt_eta
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2016/MuonTrigger_EfficienciesAndSF_average_RunBtoH.root", "IsoMu50_OR_IsoTkMu50_PtEtaBins"  , 0.5, "MuonTrigger", true, Sys_MuonTrigger));
  }
  if(is2017v2 && isMuon){
    MuonID_module     .reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2017/MuonID_94X_RunBCDEF_SF_ID.root"                         , "NUM_HighPtID_DEN_genTracks_pair_newTuneP_probe_pt_abseta", 1.0, "HighPtID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2017/MuonTrigger_EfficienciesAndSF_RunBtoF_Nov17Nov2017.root", "Mu50_PtEtaBins/pt_abseta_ratio"                          , 0.5, "Trigger" , true, Sys_MuonTrigger));
  }
  if(is2018 && isMuon){
    MuonID_module     .reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2018/Muon_ID_SF_RunABCD.root"                    , "NUM_HighPtID_DEN_TrackerMuons_pair_newTuneP_probe_pt_abseta", 1.0, "HighPtID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2018/Muon_Trigger_Eff_SF_AfterMuonHLTUpdate.root", "Mu50_OR_OldMu100_OR_TkMu100_PtEtaBins/pt_abseta_ratio"      , 0.5, "Trigger" , true, Sys_MuonTrigger));
  }
  if(isUL16preVFP && isMuon){
    MuonID_module     .reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL16preVFP/Efficiencies_muon_generalTracks_Z_Run2016_UL_HIPM_ID.root"                , "NUM_TightID_DEN_TrackerMuons_abseta_pt"                                , 1.0, "TightID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL16preVFP/Efficiencies_muon_generalTracks_Z_Run2016_UL_HIPM_SingleMuonTriggers.root", "NUM_Mu50_or_TkMu50_DEN_CutBasedIdGlobalHighPt_and_TkIsoLoose_abseta_pt", 0.5, "Trigger", true, Sys_MuonTrigger));
  }
  if(isUL16postVFP && isMuon){
    MuonID_module     .reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL16postVFP/Efficiencies_muon_generalTracks_Z_Run2016_UL_ID.root"                , "NUM_TightID_DEN_TrackerMuons_abseta_pt"                                , 1.0, "TightID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL16postVFP/Efficiencies_muon_generalTracks_Z_Run2016_UL_SingleMuonTriggers.root", "NUM_Mu50_or_TkMu50_DEN_CutBasedIdGlobalHighPt_and_TkIsoLoose_abseta_pt", 0.5, "Trigger", true, Sys_MuonTrigger));
  }
  if(isUL17 && isMuon){
    MuonID_module     .reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL17/Efficiencies_muon_generalTracks_Z_Run2017_UL_ID.root"                , "NUM_HighPtID_DEN_TrackerMuons_abseta_pt"                                            , 1.0, "HighPtID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL17/Efficiencies_muon_generalTracks_Z_Run2017_UL_SingleMuonTriggers.root", "NUM_Mu50_or_OldMu100_or_TkMu100_DEN_CutBasedIdGlobalHighPt_and_TkIsoLoose_abseta_pt", 0.5, "Trigger" , true, Sys_MuonTrigger));
  }
  if(isUL18 && isMuon){
    MuonID_module     .reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL18/Efficiencies_muon_generalTracks_Z_Run2018_UL_ID.root"                , "NUM_HighPtID_DEN_TrackerMuons_abseta_pt"                                            , 1.0, "HighPtID", true, Sys_MuonID));
    MuonTrigger_module.reset(new MCMuonScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/common/data/UL18/Efficiencies_muon_generalTracks_Z_Run2018_UL_SingleMuonTriggers.root", "NUM_Mu50_or_OldMu100_or_TkMu100_DEN_CutBasedIdGlobalHighPt_and_TkIsoLoose_abseta_pt", 0.5, "Trigger" , true, Sys_MuonTrigger));
  }


  // Electron
  if((is2016v3 || is2016v2) && isElectron){
    EleID_module     .reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2016/egammaEffi.txt_EGM2D_CutBased_Medium_ID.root", 1.0, "MediumID", Sys_EleID));
    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/data/SF_Ele50_Ele115_2016.root"              , 0.5, "Trigger" , Sys_EleTrigger, "electrons", "abseta_pt_ratio"));
  }
  if(is2017v2 && isElectron){
    EleID_module     .reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2017/2017_ElectronTight.root"       , 1.0, "TightID", Sys_EleID));
    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/data/SF_Ele50_Ele115_2017.root", 0.5, "Trigger", Sys_EleTrigger, "electrons", "abseta_pt_ratio"));
  }
  if(is2018 && isElectron){
    EleID_module     .reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/common/data/2018/2018_ElectronTight.root"       , 1.0, "TightID", Sys_EleID));
    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/data/SF_Ele50_Ele115_2018.root", 0.5, "Trigger", Sys_EleTrigger, "electrons", "abseta_pt_ratio"));
  }
  if(isUL16preVFP && isElectron){
    EleID_module     .reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/NonResonantTTbar/data/ElectronSFs_UL/UL16preVFP/egammaEffi.txt_Ele_Medium_preVFP_EGM2D.root", 1.0, "MediumID", Sys_EleID));
    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/data/SF_Ele50_Ele115_2016.root"                                               , 0.5, "Trigger" , Sys_EleTrigger, "electrons", "abseta_pt_ratio")); // update needed!
  }
  if(isUL16postVFP && isElectron){
    EleID_module     .reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/NonResonantTTbar/data/ElectronSFs_UL/UL16postVFP/egammaEffi.txt_Ele_Medium_preVFP_EGM2D.root", 1.0, "MediumID", Sys_EleID));
    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/data/SF_Ele50_Ele115_2016.root"                                                , 0.5, "Trigger" , Sys_EleTrigger, "electrons", "abseta_pt_ratio")); // update needed!
  }
  if(isUL17 && isElectron){
    EleID_module     .reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/NonResonantTTbar/data/ElectronSFs_UL/UL17/egammaEffi.txt_EGM2D_Tight_UL17.root", 1.0, "TightID", Sys_EleID));
    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/data/SF_Ele50_Ele115_2017.root"                                  , 0.5, "Trigger", Sys_EleTrigger, "electrons", "abseta_pt_ratio")); // update needed!
  }
  if(isUL18 && isElectron){
    EleID_module     .reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH_UL/CMSSW_10_6_13/src/UHH2/NonResonantTTbar/data/ElectronSFs_UL/UL18/egammaEffi.txt_Ele_Tight_EGM2D.root", 1.0, "TightID", Sys_EleID));
    EleTrigger_module.reset(new MCElecScaleFactor(ctx, "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/data/SF_Ele50_Ele115_2018.root"                                 , 0.5, "Trigger", Sys_EleTrigger, "electrons", "abseta_pt_ratio")); // update needed!
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
  // BlindData_selection.reset(new BlindDataSelection(ctx, mtt_blind));

  HEM_selection.reset(new HEMSelection(ctx)); // HEM issue in 2018, veto on leptons and jets

  Variables_module.reset(new Variables_NN(ctx)); // variables for NN

  // Taggers
  TopTaggerPuppi.reset(new AK8PuppiTopTagger(ctx));

  // Zprime candidate builder
  CandidateBuilder.reset(new ZprimeCandidateBuilder(ctx, mode));

  // Zprime discriminators
  Chi2DiscriminatorZprime.reset(new ZprimeChi2Discriminator(ctx));
  h_is_zprime_reconstructed_chi2 = ctx.get_handle<bool>("is_zprime_reconstructed_chi2");
  CorrectMatchDiscriminatorZprime.reset(new ZprimeCorrectMatchDiscriminator(ctx));
  h_is_zprime_reconstructed_correctmatch = ctx.get_handle<bool>("is_zprime_reconstructed_correctmatch");
  h_BestZprimeCandidateChi2              = ctx.get_handle<ZprimeCandidate*>("ZprimeCandidateBestChi2");
  h_chi2                                 = ctx.declare_event_output<float> ("rec_chi2");
  h_MET                                  = ctx.declare_event_output<float> ("met_pt");
  h_Mttbar                               = ctx.declare_event_output<float> ("Mttbar");
  h_lep1_pt                              = ctx.declare_event_output<float> ("lep1_pt");
  h_lep1_eta                             = ctx.declare_event_output<float> ("lep1_eta");
  h_ak4jet1_pt                           = ctx.declare_event_output<float> ("ak4jet1_pt");
  h_ak4jet1_eta                          = ctx.declare_event_output<float> ("ak4jet1_eta");
  h_ak8jet1_pt                           = ctx.declare_event_output<float> ("ak8jet1_pt");
  h_ak8jet1_eta                          = ctx.declare_event_output<float> ("ak8jet1_eta");

  h_NPV    = ctx.declare_event_output<int> ("NPV");
  h_weight = ctx.declare_event_output<float> ("weight");

  h_muonrecoSF_nominal = ctx.declare_event_output<float> ("muonrecSF_nominal");
  h_muonrecoSF_up      = ctx.declare_event_output<float> ("muonrecSF_up");
  h_muonrecoSF_down    = ctx.declare_event_output<float> ("muonrecSF_down");

  sel_1btag.reset(new NJetSelection(1, 1, id_btag));
  sel_2btag.reset(new NJetSelection(2,-1, id_btag));


  TopJetBtagSubjet_selection.reset(new ZprimeBTagFatSubJetSelection(ctx));

  // Book histograms
  vector<string> histogram_tags = {
    "Weights",
    "Weights_MuonID",
    "Weights_EleID",
    "Weights_PU",
    "Weights_Lumi",
    "Weights_TopPt",
    "Weights_MCScale",
    "NLOCorrections",
    "Muon1",
    "TriggerMuon",
    "Muon2",
    "Electron1",
    "TriggerEle",
    "TwoDCut",
    "Jet1",
    "Jet2",
    "MET",
    "HTlep",
    "NNInputsBeforeReweight",
    "MatchableBeforeChi2Cut",
    "NotMatchableBeforeChi2Cut",
    "CorrectMatchBeforeChi2Cut",
    "NotCorrectMatchBeforeChi2Cut",
    "Chi2",
    "Matchable",
    "NotMatchable",
    "CorrectMatch",
    "NotCorrectMatch",
    "TopTagReconstruction",
    "NotTopTagReconstruction",
    "Btags2",
    "Btags1",
    "TopJetBtagSubjet",
    "DNN_output0",
    "DNN_output0_TopTag",
    "DNN_output0_NoTopTag",
    "DNN_output1",
    "DNN_output1_TopTag",
    "DNN_output1_NoTopTag",
    "DNN_output2",
    "DNN_output2_TopTag",
    "DNN_output2_NoTopTag"
  };
  book_histograms(ctx, histogram_tags);

  h_MulticlassNN_output.reset(new NonResonantTTbarMulticlassNNHists(ctx, "MulticlassNN"));

  h_Ak4_j1_E             = ctx.get_handle<float>("Ak4_j1_E");
  h_Ak4_j1_deepjetbscore = ctx.get_handle<float>("Ak4_j1_deepjetbscore");
  h_Ak4_j1_eta           = ctx.get_handle<float>("Ak4_j1_eta");
  h_Ak4_j1_m             = ctx.get_handle<float>("Ak4_j1_m");
  h_Ak4_j1_phi           = ctx.get_handle<float>("Ak4_j1_phi");
  h_Ak4_j1_pt            = ctx.get_handle<float>("Ak4_j1_pt");

  h_Ak4_j2_E             = ctx.get_handle<float>("Ak4_j2_E");
  h_Ak4_j2_deepjetbscore = ctx.get_handle<float>("Ak4_j2_deepjetbscore");
  h_Ak4_j2_eta           = ctx.get_handle<float>("Ak4_j2_eta");
  h_Ak4_j2_m             = ctx.get_handle<float>("Ak4_j2_m");
  h_Ak4_j2_phi           = ctx.get_handle<float>("Ak4_j2_phi");
  h_Ak4_j2_pt            = ctx.get_handle<float>("Ak4_j2_pt");

  h_Ak4_j3_E             = ctx.get_handle<float>("Ak4_j3_E");
  h_Ak4_j3_deepjetbscore = ctx.get_handle<float>("Ak4_j3_deepjetbscore");
  h_Ak4_j3_eta           = ctx.get_handle<float>("Ak4_j3_eta");
  h_Ak4_j3_m             = ctx.get_handle<float>("Ak4_j3_m");
  h_Ak4_j3_phi           = ctx.get_handle<float>("Ak4_j3_phi");
  h_Ak4_j3_pt            = ctx.get_handle<float>("Ak4_j3_pt");

  h_Ak4_j4_E             = ctx.get_handle<float>("Ak4_j4_E");
  h_Ak4_j4_deepjetbscore = ctx.get_handle<float>("Ak4_j4_deepjetbscore");
  h_Ak4_j4_eta           = ctx.get_handle<float>("Ak4_j4_eta");
  h_Ak4_j4_m             = ctx.get_handle<float>("Ak4_j4_m");
  h_Ak4_j4_phi           = ctx.get_handle<float>("Ak4_j4_phi");
  h_Ak4_j4_pt            = ctx.get_handle<float>("Ak4_j4_pt");

  h_Ak4_j5_E             = ctx.get_handle<float>("Ak4_j5_E");
  h_Ak4_j5_deepjetbscore = ctx.get_handle<float>("Ak4_j5_deepjetbscore");
  h_Ak4_j5_eta           = ctx.get_handle<float>("Ak4_j5_eta");
  h_Ak4_j5_m             = ctx.get_handle<float>("Ak4_j5_m");
  h_Ak4_j5_phi           = ctx.get_handle<float>("Ak4_j5_phi");
  h_Ak4_j5_pt            = ctx.get_handle<float>("Ak4_j5_pt");

  h_Ak4_j6_E             = ctx.get_handle<float>("Ak4_j6_E");
  h_Ak4_j6_deepjetbscore = ctx.get_handle<float>("Ak4_j6_deepjetbscore");
  h_Ak4_j6_eta           = ctx.get_handle<float>("Ak4_j6_eta");
  h_Ak4_j6_m             = ctx.get_handle<float>("Ak4_j6_m");
  h_Ak4_j6_phi           = ctx.get_handle<float>("Ak4_j6_phi");
  h_Ak4_j6_pt            = ctx.get_handle<float>("Ak4_j6_pt");

  h_Ak8_j1_E     = ctx.get_handle<float>("Ak8_j1_E");
  h_Ak8_j1_eta   = ctx.get_handle<float>("Ak8_j1_eta");
  h_Ak8_j1_mSD   = ctx.get_handle<float>("Ak8_j1_mSD");
  h_Ak8_j1_phi   = ctx.get_handle<float>("Ak8_j1_phi");
  h_Ak8_j1_pt    = ctx.get_handle<float>("Ak8_j1_pt");
  h_Ak8_j1_tau21 = ctx.get_handle<float>("Ak8_j1_tau21");
  h_Ak8_j1_tau32 = ctx.get_handle<float>("Ak8_j1_tau32");

  h_Ak8_j2_E     = ctx.get_handle<float>("Ak8_j2_E");
  h_Ak8_j2_eta   = ctx.get_handle<float>("Ak8_j2_eta");
  h_Ak8_j2_mSD   = ctx.get_handle<float>("Ak8_j2_mSD");
  h_Ak8_j2_phi   = ctx.get_handle<float>("Ak8_j2_phi");
  h_Ak8_j2_pt    = ctx.get_handle<float>("Ak8_j2_pt");
  h_Ak8_j2_tau21 = ctx.get_handle<float>("Ak8_j2_tau21");
  h_Ak8_j2_tau32 = ctx.get_handle<float>("Ak8_j2_tau32");

  h_Ak8_j3_E     = ctx.get_handle<float>("Ak8_j3_E");
  h_Ak8_j3_eta   = ctx.get_handle<float>("Ak8_j3_eta");
  h_Ak8_j3_mSD   = ctx.get_handle<float>("Ak8_j3_mSD");
  h_Ak8_j3_phi   = ctx.get_handle<float>("Ak8_j3_phi");
  h_Ak8_j3_pt    = ctx.get_handle<float>("Ak8_j3_pt");
  h_Ak8_j3_tau21 = ctx.get_handle<float>("Ak8_j3_tau21");
  h_Ak8_j3_tau32 = ctx.get_handle<float>("Ak8_j3_tau32");

  h_MET_phi = ctx.get_handle<float>("MET_phi");
  h_MET_pt  = ctx.get_handle<float>("MET_pt");

  h_Mu_E   = ctx.get_handle<float>("Mu_E");
  h_Mu_eta = ctx.get_handle<float>("Mu_eta");
  h_Mu_phi = ctx.get_handle<float>("Mu_phi");
  h_Mu_pt  = ctx.get_handle<float>("Mu_pt");

  h_N_Ak4 = ctx.get_handle<float>("N_Ak4");
  h_N_Ak8 = ctx.get_handle<float>("N_Ak8");

  h_NNoutput  = ctx.get_handle<std::vector<tensorflow::Tensor>>("NNoutput");
  h_NNoutput0 = ctx.declare_event_output<double>("NNoutput0");
  h_NNoutput1 = ctx.declare_event_output<double>("NNoutput1");
  h_NNoutput2 = ctx.declare_event_output<double>("NNoutput2");
  NNModule.reset(new NeuralNetworkModule(ctx, "/nfs/dust/cms/user/jabuschh/NonResonantTTbar/DNNClassifier_py2/output/StandardScaler/DNN_layers_512_512__batchsize_131072__classes_3_TTbar_ST_WJets+DY__regmethod_dropout__regrate_050000__batchnorm_False__epochs_500__learningrate_000050__runonfraction_100__eqweight_False__preprocess_StandardScaler__priorSigma_100/model.pb", "/nfs/dust/cms/user/jabuschh/NonResonantTTbar/DNNClassifier_py2/output/StandardScaler/DNN_layers_512_512__batchsize_131072__classes_3_TTbar_ST_WJets+DY__regmethod_dropout__regrate_050000__batchnorm_False__epochs_500__learningrate_000050__runonfraction_100__eqweight_False__preprocess_StandardScaler__priorSigma_100/model.config.pbtxt"));
}

/*
██████  ██████   ██████   ██████ ███████ ███████ ███████
██   ██ ██   ██ ██    ██ ██      ██      ██      ██
██████  ██████  ██    ██ ██      █████   ███████ ███████
██      ██   ██ ██    ██ ██      ██           ██      ██
██      ██   ██  ██████   ██████ ███████ ███████ ███████
*/

bool NonResonantTTbarAnalysisModule_applyDNNclassifier::process(uhh2::Event& event){

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
  event.set(h_muonrecoSF_nominal,-100);
  event.set(h_muonrecoSF_up,-100);
  event.set(h_muonrecoSF_down,-100);

  event.set(h_NNoutput0, 0);
  event.set(h_NNoutput1, 0);
  event.set(h_NNoutput2, 0);

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
  if(isElectron){
    EleID_module->process(event);
    if(debug)  cout<<"EleID ok"<<endl;
  }
  fill_histograms(event, "Weights_EleID");
  PUWeight_module->process(event);
  if(debug)  cout<<"PUWeight ok"<<endl;
  fill_histograms(event, "Weights_PU");

  LumiWeight_module->process(event);
  if(debug)  cout<<"LumiWeight ok"<<endl;
  fill_histograms(event, "Weights_Lumi");

  TopPtReweight_module->process(event);
  fill_histograms(event, "Weights_TopPt");

  MCScale_module->process(event);
  fill_histograms(event, "Weights_MCScale");

  // Higher order corrections - EWK & QCD NLO
  Corrections_module->process(event);
  fill_histograms(event, "NLOCorrections");

  if(!(Trigger1_selection->passes(event)|| Trigger2_selection->passes(event))) return false;
  if(isMuon){
    if(!NMuon1_selection->passes(event)) return false;
    fill_histograms(event, "Muon1");
    MuonTrigger_module->process_onemuon(event, 0);
    fill_histograms(event, "TriggerMuon");
    if(!NMuon2_selection->passes(event)) return false;
    fill_histograms(event, "Muon2");
  }
  if(isElectron){
    if(!NElectron_selection->passes(event)) return false;
    fill_histograms(event, "Electron1");
    EleTrigger_module->process(event);
    fill_histograms(event, "TriggerEle");
  }

  if((event.muons->size()+event.electrons->size()) != 1) return false; //veto events without leptons or with too many
  if(debug) cout<<"N leptons ok: Nelectrons="<<event.electrons->size()<<" Nmuons="<<event.muons->size()<<endl;

  // No TwoD cut -> QCD removed with QCD NN
  if(!TwoDCut_selection->passes(event)) return false;
  fill_histograms(event, "TwoDCut");

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
  if(debug) cout << "CandidateBuilder is ok" << endl;

  Chi2DiscriminatorZprime->process(event);
  if(debug) cout << "Chi2DiscriminatorZprime is ok" << endl;

  CorrectMatchDiscriminatorZprime->process(event);
  if(debug) cout << "CorrectMatchDiscriminatorZprime is ok" << endl;

  if(sample.Contains("_blinded")){
    if(!BlindData_selection->passes(event)) return false;
  }

  if(!Jet1_selection->passes(event)) return false;
  if(debug) cout<<"Jet1_selection is ok"<<endl;
  fill_histograms(event, "Jet1");

  if(!Jet2_selection->passes(event)) return false;
  if(debug) cout<<"Jet2_selection is ok"<<endl;
  fill_histograms(event, "Jet2");

  // MET selection
  if(!met_sel->passes(event)) return false;
  if(debug) cout<<"MET is ok"<<endl;
  fill_histograms(event, "MET");
  if(isMuon){
    if(!htlep_sel->passes(event)) return false;
    fill_histograms(event, "HTlep");
    if(debug) cout<<"HTlep is ok"<<endl;
  }

  //  Variables for NN
  Variables_module->process(event);
  fill_histograms(event, "NNInputsBeforeReweight");


  // NN module
  NNModule->process(event);
  std::vector<tensorflow::Tensor> NNoutputs = NNModule->GetOutputs();

  event.set(h_NNoutput0, (double)(NNoutputs[0].tensor<float, 2>()(0,0)));
  event.set(h_NNoutput1, (double)(NNoutputs[0].tensor<float, 2>()(0,1)));
  event.set(h_NNoutput2, (double)(NNoutputs[0].tensor<float, 2>()(0,2)));
  event.set(h_NNoutput, NNoutputs);

  double out0 = (double)(NNoutputs[0].tensor<float, 2>()(0,0));
  double out1 = (double)(NNoutputs[0].tensor<float, 2>()(0,1));
  double out2 = (double)(NNoutputs[0].tensor<float, 2>()(0,2));
  vector<double> out_event = {out0, out1, out2};

  h_MulticlassNN_output->fill(event);

  double max_score = 0.0;
  for(int i=0; i<3; i++){
    if(out_event[i] > max_score){
      max_score = out_event[i];
    }
  }

  if(out0 == max_score){
    fill_histograms(event, "DNN_output0");
    if(ZprimeTopTag_selection->passes(event)) fill_histograms(event, "DNN_output0_TopTag");
    else fill_histograms(event, "DNN_output0_NoTopTag");
  }

  if(out1 == max_score){
    fill_histograms(event, "DNN_output1");
    if(ZprimeTopTag_selection->passes(event)) fill_histograms(event, "DNN_output1_TopTag");
    else fill_histograms(event, "DNN_output1_NoTopTag");
  }

  if(out2 == max_score){
    fill_histograms(event, "DNN_output2");
    if(ZprimeTopTag_selection->passes(event)) fill_histograms(event, "DNN_output2_TopTag");
    else fill_histograms(event, "DNN_output2_NoTopTag");
  }


  // if(TTbarMatchable_selection->passes(event)) fill_histograms(event, "MatchableBeforeChi2Cut");
  // else fill_histograms(event, "NotMatchableBeforeChi2Cut");
  // if(debug) cout<<"TTbarMatchable_selection is ok"<<endl;
  //
  // if(Chi2CandidateMatched_selection->passes(event)) fill_histograms(event, "CorrectMatchBeforeChi2Cut");
  // else fill_histograms(event, "NotCorrectMatchBeforeChi2Cut");
  // if(debug) cout<<"Chi2CandidateMatched_selection is ok"<<endl;
  //
  // if(!Chi2_selection->passes(event)) return false;
  // fill_histograms(event, "Chi2");
  //
  // if(debug) cout<<"Chi2_selection is ok"<<endl;
  //
  // if(TTbarMatchable_selection->passes(event)) fill_histograms(event, "Matchable");
  // else fill_histograms(event, "NotMatchable");
  // if(debug) cout<<"TTbarMatchable_selection is ok"<<endl;
  //
  // if(Chi2CandidateMatched_selection->passes(event)) fill_histograms(event, "CorrectMatch");
  // else fill_histograms(event, "NotCorrectMatch");
  // if(debug) cout<<"Chi2CandidateMatched_selection is ok"<<endl;
  //
  // if(ZprimeTopTag_selection->passes(event)) fill_histograms(event, "TopTagReconstruction");
  // else fill_histograms(event, "NotTopTagReconstruction");
  // if(debug) cout<<"ZprimeTopTag_selection is ok"<<endl;
  //
  // //Test with b-tagging
  // if(sel_2btag->passes(event)) fill_histograms(event, "Btags2");
  // if(sel_1btag->passes(event)) fill_histograms(event, "Btags1");
  // if(debug) cout<<"Btags1 is ok"<<endl;
  // if(TopJetBtagSubjet_selection->passes(event)) fill_histograms(event, "TopJetBtagSubjet");
  // if(debug) cout<<"TopJetBtagSubjet_selection is ok"<<endl;
  //
  // //Fill some vars for monitoring and comparison
  // bool is_zprime_reconstructed_chi2 = event.get(h_is_zprime_reconstructed_chi2);
  // if(is_zprime_reconstructed_chi2){
  //   ZprimeCandidate* BestZprimeCandidate = event.get(h_BestZprimeCandidateChi2);
  //   //    float chi2 = BestZprimeCandidate->discriminator("chi2_total");
  //   event.set(h_chi2,BestZprimeCandidate->discriminator("chi2_total"));
  //   event.set(h_Mttbar,BestZprimeCandidate->Zprime_v4().M());
  // }
  // if(debug) cout<<"Set ttbar reconstruction vars for monitoring"<<endl;
  //
  // event.set(h_weight,event.weight);
  // event.set(h_MET,event.met->pt());
  // if(isMuon){
  //   event.set(h_lep1_pt,event.muons->at(0).pt());
  //   event.set(h_lep1_eta,event.muons->at(0).eta());
  // }
  // if(isElectron){
  //   event.set(h_lep1_pt,event.electrons->at(0).pt());
  //   event.set(h_lep1_eta,event.electrons->at(0).eta());
  // }
  // if(event.jets->size()>0){
  //   event.set(h_ak4jet1_pt,event.jets->at(0).pt());
  //   event.set(h_ak4jet1_eta,event.jets->at(0).eta());
  // }
  // if(event.topjets->size()>0){
  //   event.set(h_ak8jet1_pt,event.topjets->at(0).pt());
  //   event.set(h_ak8jet1_eta,event.topjets->at(0).eta());
  // }
  // event.set(h_NPV,event.pvs->size());
  // if(debug) cout<<"Set some vars for monitoring"<<endl;

  // Muon Reco SF: high-pT muons
  // https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonPOG#User_Recommendations
  if(isMC){
    if(isMuon){
      float pt_mu    = event.muons->at(0).pt();
      float eta_mu   = event.muons->at(0).eta();
      float abs_p_mu = pt_mu * cosh(eta_mu); // muon reco SFs depend on muon momentum p, not pT!

      if(is2016v2 || is2016v3 || isUL16preVFP || isUL16postVFP){
        if(abs(eta_mu) < 1.6){
          if     (abs_p_mu <=   50.){cout << "Muon Reco SF: muon abs(eta) < 1.6, but momentum p < 50 GeV -> no muon reco SF applied" << endl;}
          else if(abs_p_mu <=  100.){event.set(h_muonrecoSF_nominal, 0.9914); event.set(h_muonrecoSF_up, 0.9914+0.0008); event.set(h_muonrecoSF_down, 0.9914-0.0008);}
          else if(abs_p_mu <=  150.){event.set(h_muonrecoSF_nominal, 0.9936); event.set(h_muonrecoSF_up, 0.9936+0.0009); event.set(h_muonrecoSF_down, 0.9936-0.0009);}
          else if(abs_p_mu <=  200.){event.set(h_muonrecoSF_nominal, 0.993 ); event.set(h_muonrecoSF_up, 0.993 +0.001 ); event.set(h_muonrecoSF_down, 0.993 -0.001 );}
          else if(abs_p_mu <=  300.){event.set(h_muonrecoSF_nominal, 0.993 ); event.set(h_muonrecoSF_up, 0.993 +0.002 ); event.set(h_muonrecoSF_down, 0.993 -0.002 );}
          else if(abs_p_mu <=  400.){event.set(h_muonrecoSF_nominal, 0.990 ); event.set(h_muonrecoSF_up, 0.990 +0.004 ); event.set(h_muonrecoSF_down, 0.990 -0.004 );}
          else if(abs_p_mu <=  600.){event.set(h_muonrecoSF_nominal, 0.990 ); event.set(h_muonrecoSF_up, 0.990 +0.003 ); event.set(h_muonrecoSF_down, 0.990 -0.003 );}
          else if(abs_p_mu <= 1500.){event.set(h_muonrecoSF_nominal, 0.989 ); event.set(h_muonrecoSF_up, 0.989 +0.004 ); event.set(h_muonrecoSF_down, 0.989 -0.004 );}
          else if(abs_p_mu <= 3500.){event.set(h_muonrecoSF_nominal, 0.8   ); event.set(h_muonrecoSF_up, 0.8   +0.3   ); event.set(h_muonrecoSF_down, 0.8   -0.3   );}
          else                      {cout << "muon momentum p > 3500 Gev -> no muon reco SF applied" << endl;}
        }
        else if(1.6 <= abs(eta_mu) && abs(eta_mu) < 2.4){
          if     (abs_p_mu <=  100.){cout << "Muon Reco SF: 1.6 < muon abs(eta) < 2.4, but momentum p < 100 GeV -> no muon reco SF applied" << endl;}
          else if(abs_p_mu <=  150.){event.set(h_muonrecoSF_nominal, 0.993); event.set(h_muonrecoSF_up, 0.993+0.001); event.set(h_muonrecoSF_down, 0.993-0.001);}
          else if(abs_p_mu <=  200.){event.set(h_muonrecoSF_nominal, 0.991); event.set(h_muonrecoSF_up, 0.991+0.001); event.set(h_muonrecoSF_down, 0.991-0.001);}
          else if(abs_p_mu <=  300.){event.set(h_muonrecoSF_nominal, 0.985); event.set(h_muonrecoSF_up, 0.985+0.001); event.set(h_muonrecoSF_down, 0.985-0.001);}
          else if(abs_p_mu <=  400.){event.set(h_muonrecoSF_nominal, 0.981); event.set(h_muonrecoSF_up, 0.981+0.002); event.set(h_muonrecoSF_down, 0.981-0.002);}
          else if(abs_p_mu <=  600.){event.set(h_muonrecoSF_nominal, 0.979); event.set(h_muonrecoSF_up, 0.979+0.004); event.set(h_muonrecoSF_down, 0.979-0.004);}
          else if(abs_p_mu <= 1500.){event.set(h_muonrecoSF_nominal, 0.978); event.set(h_muonrecoSF_up, 0.978+0.005); event.set(h_muonrecoSF_down, 0.978-0.005);}
          else if(abs_p_mu <= 3500.){event.set(h_muonrecoSF_nominal, 0.9  ); event.set(h_muonrecoSF_up, 0.9  +0.2  ); event.set(h_muonrecoSF_down, 0.9  -0.2  );}
          else                      {cout << "muon momentum p > 3500 Gev -> no muon reco SF applied" << endl;}
        }
        else cout << "absolute value of muon eta larger than 2.4 -> no muon reco SF applied" << endl;
      }
      else if(is2017v2 || isUL17){
        if(abs(eta_mu) < 1.6){
          if     (abs_p_mu <=   50.){cout << "Muon Reco SF: muon abs(eta) < 1.6, but momentum p < 50 GeV -> no muon reco SF applied" << endl;}
          else if(abs_p_mu <=  100.){event.set(h_muonrecoSF_nominal, 0.9938); event.set(h_muonrecoSF_up, 0.9938+0.0006); event.set(h_muonrecoSF_down, 0.9938-0.0006);}
          else if(abs_p_mu <=  150.){event.set(h_muonrecoSF_nominal, 0.9950); event.set(h_muonrecoSF_up, 0.9950+0.0007); event.set(h_muonrecoSF_down, 0.9950-0.0007);}
          else if(abs_p_mu <=  200.){event.set(h_muonrecoSF_nominal, 0.996 ); event.set(h_muonrecoSF_up, 0.996 +0.001 ); event.set(h_muonrecoSF_down, 0.996 -0.001 );}
          else if(abs_p_mu <=  300.){event.set(h_muonrecoSF_nominal, 0.996 ); event.set(h_muonrecoSF_up, 0.996 +0.001 ); event.set(h_muonrecoSF_down, 0.996 -0.001 );}
          else if(abs_p_mu <=  400.){event.set(h_muonrecoSF_nominal, 0.994 ); event.set(h_muonrecoSF_up, 0.994 +0.001 ); event.set(h_muonrecoSF_down, 0.994 -0.001 );}
          else if(abs_p_mu <=  600.){event.set(h_muonrecoSF_nominal, 1.003 ); event.set(h_muonrecoSF_up, 1.003 +0.006 ); event.set(h_muonrecoSF_down, 1.003 -0.006 );}
          else if(abs_p_mu <= 1500.){event.set(h_muonrecoSF_nominal, 0.987 ); event.set(h_muonrecoSF_up, 0.987 +0.003 ); event.set(h_muonrecoSF_down, 0.987 -0.003 );}
          else if(abs_p_mu <= 3500.){event.set(h_muonrecoSF_nominal, 0.9   ); event.set(h_muonrecoSF_up, 0.9   +0.1   ); event.set(h_muonrecoSF_down, 0.9   -0.1   );}
          else                      {cout << "muon momentum p > 3500 Gev -> no muon reco SF applied" << endl;}
        }
        else if(1.6 <= abs(eta_mu) && abs(eta_mu) < 2.4){
          if     (abs_p_mu <=  100.){cout << "Muon Reco SF: 1.6 < muon abs(eta) < 2.4, but momentum p < 100 GeV -> no muon reco SF applied" << endl;}
          else if(abs_p_mu <=  150.){event.set(h_muonrecoSF_nominal, 0.993); event.set(h_muonrecoSF_up, 0.993+0.001); event.set(h_muonrecoSF_down, 0.993-0.001);}
          else if(abs_p_mu <=  200.){event.set(h_muonrecoSF_nominal, 0.989); event.set(h_muonrecoSF_up, 0.989+0.001); event.set(h_muonrecoSF_down, 0.989-0.001);}
          else if(abs_p_mu <=  300.){event.set(h_muonrecoSF_nominal, 0.986); event.set(h_muonrecoSF_up, 0.986+0.001); event.set(h_muonrecoSF_down, 0.986-0.001);}
          else if(abs_p_mu <=  400.){event.set(h_muonrecoSF_nominal, 0.989); event.set(h_muonrecoSF_up, 0.989+0.001); event.set(h_muonrecoSF_down, 0.989-0.001);}
          else if(abs_p_mu <=  600.){event.set(h_muonrecoSF_nominal, 0.983); event.set(h_muonrecoSF_up, 0.983+0.003); event.set(h_muonrecoSF_down, 0.983-0.003);}
          else if(abs_p_mu <= 1500.){event.set(h_muonrecoSF_nominal, 0.986); event.set(h_muonrecoSF_up, 0.986+0.006); event.set(h_muonrecoSF_down, 0.986-0.006);}
          else if(abs_p_mu <= 3500.){event.set(h_muonrecoSF_nominal, 1.01 ); event.set(h_muonrecoSF_up, 1.01 +0.01 ); event.set(h_muonrecoSF_down, 1.01 -0.01 );}
          else                      {cout << "muon momentum p > 3500 Gev -> no muon reco SF applied" << endl;}
        }
        else cout << "absolute value of muon eta larger than 2.4 -> no muon reco SF applied" << endl;
      }
      else if(is2018 || isUL18){
        if(abs(eta_mu) < 1.6){
          if     (abs_p_mu <=   50.){cout << "Muon Reco SF: muon abs(eta) < 1.6, but momentum p < 50 GeV -> no muon reco SF applied" << endl;}
          else if(abs_p_mu <=  100.){event.set(h_muonrecoSF_nominal, 0.9943); event.set(h_muonrecoSF_up, 0.9943+0.0007); event.set(h_muonrecoSF_down, 0.9943-0.0007);}
          else if(abs_p_mu <=  150.){event.set(h_muonrecoSF_nominal, 0.9948); event.set(h_muonrecoSF_up, 0.9948+0.0007); event.set(h_muonrecoSF_down, 0.9948-0.0007);}
          else if(abs_p_mu <=  200.){event.set(h_muonrecoSF_nominal, 0.9950); event.set(h_muonrecoSF_up, 0.9950+0.0009); event.set(h_muonrecoSF_down, 0.9950-0.0009);}
          else if(abs_p_mu <=  300.){event.set(h_muonrecoSF_nominal, 0.994 ); event.set(h_muonrecoSF_up, 0.994 +0.001 ); event.set(h_muonrecoSF_down, 0.994 -0.001 );}
          else if(abs_p_mu <=  400.){event.set(h_muonrecoSF_nominal, 0.9914); event.set(h_muonrecoSF_up, 0.9914+0.0009); event.set(h_muonrecoSF_down, 0.9914-0.0009);}
          else if(abs_p_mu <=  600.){event.set(h_muonrecoSF_nominal, 0.993 ); event.set(h_muonrecoSF_up, 0.993 +0.002 ); event.set(h_muonrecoSF_down, 0.993 -0.002 );}
          else if(abs_p_mu <= 1500.){event.set(h_muonrecoSF_nominal, 0.991 ); event.set(h_muonrecoSF_up, 0.991 +0.004 ); event.set(h_muonrecoSF_down, 0.991 -0.004 );}
          else if(abs_p_mu <= 3500.){event.set(h_muonrecoSF_nominal, 1.0   ); event.set(h_muonrecoSF_up, 1.0   +0.1   ); event.set(h_muonrecoSF_down, 1.0   -0.1   );}
          else                      {cout << "muon momentum p > 3500 Gev -> no muon reco SF applied" << endl;}

        }
        else if(1.6 <= abs(eta_mu) && abs(eta_mu) < 2.4){
          if     (abs_p_mu <=  100.){cout << "Muon Reco SF: 1.6 < muon abs(eta) < 2.4, but momentum p < 100 GeV -> no muon reco SF applied" << endl;}
          else if(abs_p_mu <=  150.){event.set(h_muonrecoSF_nominal, 0.993); event.set(h_muonrecoSF_up, 0.993+0.001); event.set(h_muonrecoSF_down, 0.993-0.001);}
          else if(abs_p_mu <=  200.){event.set(h_muonrecoSF_nominal, 0.990); event.set(h_muonrecoSF_up, 0.990+0.001); event.set(h_muonrecoSF_down, 0.990-0.001);}
          else if(abs_p_mu <=  300.){event.set(h_muonrecoSF_nominal, 0.988); event.set(h_muonrecoSF_up, 0.988+0.001); event.set(h_muonrecoSF_down, 0.988-0.001);}
          else if(abs_p_mu <=  400.){event.set(h_muonrecoSF_nominal, 0.981); event.set(h_muonrecoSF_up, 0.981+0.002); event.set(h_muonrecoSF_down, 0.981-0.002);}
          else if(abs_p_mu <=  600.){event.set(h_muonrecoSF_nominal, 0.983); event.set(h_muonrecoSF_up, 0.983+0.003); event.set(h_muonrecoSF_down, 0.983-0.003);}
          else if(abs_p_mu <= 1500.){event.set(h_muonrecoSF_nominal, 0.978); event.set(h_muonrecoSF_up, 0.978+0.006); event.set(h_muonrecoSF_down, 0.978-0.006);}
          else if(abs_p_mu <= 3500.){event.set(h_muonrecoSF_nominal, 0.98 ); event.set(h_muonrecoSF_up, 0.98 +0.03 ); event.set(h_muonrecoSF_down, 0.98 -0.03 );}
          else                      {cout << "muon momentum p > 3500 Gev -> no muon reco SF applied" << endl;}
        }
        else cout << "absolute value of muon eta larger than 2.4 -> no muon reco SF applied" << endl;
      }
      else{
        throw runtime_error("In NonResonantTTbarAnalysisModule::process: muon reco SF could not find year");
      }
    }
  }


  return true;
}

UHH2_REGISTER_ANALYSIS_MODULE(NonResonantTTbarAnalysisModule_applyDNNclassifier)
