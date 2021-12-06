#!/bin/bash

#where UHH2 code installed
pathGL_code=/nfs/dust/cms/user/jabuschh/UHH2_UL_10_6_28/CMSSW_10_6_28/src/UHH2/
#where (NOT MERGED) trees after preselection stored
path_data=/nfs/dust/cms/user/jabuschh/NonResonantTTbar/RunII_106X_v2/UL18/Analysis/muon/workdir_NonResonantTTbar_Analysis_UL18_muon/uhh2.AnalysisModuleRunner.

mkdir $pathGL_code/NonResonantTTbar/data/Skimming_datasets_UL18_afterDNNclassifier
cd $pathGL_code/NonResonantTTbar/data/Skimming_datasets_UL18_afterDNNclassifier


# MC
for sample_name in ALP_ttbar_signal_UL18 ALP_ttbar_interference_UL18

do
    echo $sample_name

       $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"MC."${sample_name}"*.root" MC_$sample_name.xml
       python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 MC_$sample_name.xml True
done

# for now: tke data from 2018, not UL18
# # DATA
# for sample_name in DATA_EGamma_Run2018A DATA_EGamma_Run2018B DATA_EGamma_Run2018C DATA_EGamma_Run2018D DATA_SingleMuon_Run2018A DATA_SingleMuon_Run2018B DATA_SingleMuon_Run2018C DATA_SingleMuon_Run2018D
#
# do
#     echo $sample_name
#     $pathGL_code/scripts/create-dataset-xmlfile ${path_data}"DATA."${sample_name}"*.root" DATA_$sample_name.xml
#     python $pathGL_code/scripts/crab/readaMCatNloEntries.py 10 DATA_$sample_name.xml True
#
# done

pwd
cd $pathGL_code/NonResonantTTbar/macros
