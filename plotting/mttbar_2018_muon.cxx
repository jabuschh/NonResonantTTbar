{
  bool logyaxis = false;
  if(logyaxis) cout << "log scale for y axis: true" << endl;
  else         cout << "log scale for y axis: false" << endl;

  //
  TString dir      = "/nfs/dust/cms/user/jabuschh/NonResonantTTbar/RunII_102X_v2/Analysis_2018/muon/NOMINAL/";
  TString histname = "M_Zprime_rebin2";

  // ALP interference
  TFile *file_ALPinterference = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.ALP_interference_SMlike_UL18.root");
  file_ALPinterference->cd("Chi2_General");
  TH1F *h_ALPinterference = (TH1F*) gDirectory->Get(histname);
  h_ALPinterference->SetLineColor(kBlack);
  h_ALPinterference->SetLineWidth(2);
  h_ALPinterference->SetLineStyle(2);
  h_ALPinterference->Scale(28.2);


  // TTbar
  TFile *file_ttbar = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.TTbar.root");
  file_ttbar->cd("Chi2_General");
  TH1F *h_ttbar = (TH1F*) gDirectory->Get(histname);
  h_ttbar->SetLineColor(810);
  h_ttbar->SetFillColor(810);
  // WJets
  TFile *file_wjets = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.WJets.root");
  file_wjets->cd("Chi2_General");
  TH1F *h_wjets = (TH1F*) gDirectory->Get(histname);
  h_wjets->SetLineColor(416);
  h_wjets->SetFillColor(416);
  // DY
  TFile *file_dy = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.DY.root");
  file_dy->cd("Chi2_General");
  TH1F *h_dy = (TH1F*) gDirectory->Get(histname);
  h_dy->SetLineColor(400);
  h_dy->SetFillColor(400);
  // ST
  TFile *file_st = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.ST.root");
  file_st->cd("Chi2_General");
  TH1F *h_st = (TH1F*) gDirectory->Get(histname);
  h_st->SetLineColor(860);
  h_st->SetFillColor(860);
  // QCD
  TFile *file_qcd = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.QCD.root");
  file_qcd->cd("Chi2_General");
  TH1F *h_qcd = (TH1F*) gDirectory->Get(histname);
  h_qcd->SetLineColor(867);
  h_qcd->SetFillColor(867);
  // Diboson
  TFile *file_diboson = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.Diboson.root");
  file_diboson->cd("Chi2_General");
  TH1F *h_diboson = (TH1F*) gDirectory->Get(histname);
  h_diboson->SetLineColor(880);
  h_diboson->SetFillColor(880);
  // stack backgrounds
  THStack stack("stack","SM backgrounds");
  stack.Add(h_diboson);
  stack.Add(h_qcd);
  stack.Add(h_st);
  stack.Add(h_dy);
  stack.Add(h_wjets);
  stack.Add(h_ttbar);



  TH1F *h_bkgplusALP = (TH1F*) h_ALPinterference->Clone();
  h_bkgplusALP->Add(h_ttbar);
  h_bkgplusALP->Add(h_wjets);
  h_bkgplusALP->Add(h_dy);
  h_bkgplusALP->Add(h_st);
  h_bkgplusALP->Add(h_qcd);
  h_bkgplusALP->Add(h_diboson);
  h_bkgplusALP->SetLineColor(kBlue);
  h_bkgplusALP->SetLineWidth(2);
  h_bkgplusALP->SetLineStyle(2);




  // lumi tag
  double x_pos = 0.95;
  double y_pos = 0.985;
  TLatex *lumitag = new TLatex(3.5,24,"59.7 fb^{-1} (13 TeV)");
  lumitag->SetNDC();
  lumitag->SetTextAlign(33);
  lumitag->SetX(x_pos);
  lumitag->SetY(y_pos);
  lumitag->SetTextFont(42);
  lumitag->SetTextSize(0.032);
  // paper tag
  x_pos = 0.4;
  y_pos = 0.978;
  TLatex *channeltag = new TLatex(3.5,24,"2018 muon channel");
  channeltag->SetNDC();
  channeltag->SetTextAlign(33);
  channeltag->SetX(x_pos);
  channeltag->SetY(y_pos);
  channeltag->SetTextFont(62);
  channeltag->SetTextSize(0.028);
  // legend
  x_pos  = 0.55;
  y_pos  = 0.65;
  double x_width =  0.3;
  double y_width =  0.25;
  TLegend *legend;
  legend = new TLegend(x_pos,y_pos,x_pos+x_width,y_pos+y_width);
  legend->SetBorderSize(1);
  legend->SetTextSize(0.025);
  legend->SetLineColor(0);
  legend->SetFillColor(0);
  legend->SetFillStyle(1001);
  legend->SetNColumns(1);
  legend->AddEntry(h_ttbar          ,"TTbar"                             ,"f");
  legend->AddEntry(h_wjets          ,"W#plusJets"                        ,"f");
  legend->AddEntry(h_dy             ,"DY"                                ,"f");
  legend->AddEntry(h_st             ,"ST"                                ,"f");
  legend->AddEntry(h_qcd            ,"QCD"                               ,"f");
  legend->AddEntry(h_diboson        ,"Diboson"                           ,"f");
  legend->AddEntry(h_ALPinterference,"ALP pure interference #times (-1)" ,"l");
  // legend->AddEntry(h_bkgplusALP     ,"all backgrounds + ALP interference","l");



  h_ALPinterference->Scale(-1.);

  // plotting
  cout << "plotting..." << endl;
  TCanvas *c1 = new TCanvas("c1","c1",0,0,800,800);
  c1->SetTitle("TCanvas c1");
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(kFALSE);
  gPad->SetTicks();
  gPad->SetTopMargin(0.05);
  gPad->SetLeftMargin(0.14);
  gPad->SetRightMargin(0.05);
  gPad->SetBottomMargin(0.14);
  if(logyaxis) gPad->SetLogy();
  // draw
  stack             .Draw("hist");
  h_ALPinterference->Draw("hist same");
  // h_bkgplusALP     ->Draw("hist same");
  lumitag          ->Draw("same");
  channeltag       ->Draw("same");
  legend           ->Draw("same");

  // x axis
  stack.GetXaxis()->SetTitle("m_{t#bar{t}} [GeV]");
  stack.GetXaxis()->SetTitleOffset(1.5);
  stack.GetXaxis()->SetRangeUser(0., 4000.);
  // y axis
  stack.GetYaxis()->SetTitle("Events");
  // stack.GetYaxis()->SetRangeUser(1E+1, 1E+5);
  if(logyaxis){
    stack.SetMinimum(2E+1);
    stack.SetMaximum(1E+5);
  }
  else{
    stack.SetMaximum(7E+4);
  }

  c1->Modified();

  // saving
  TString save_dir = "/nfs/dust/cms/user/jabuschh/UHH/CMSSW_10_2_17/src/UHH2/NonResonantTTbar/plotting/";
  if(logyaxis) c1->SaveAs(save_dir + "mttbar" + "_logscale.pdf");
  else c1->SaveAs(save_dir + "mttbar" + ".pdf");
  c1->Close();
}
