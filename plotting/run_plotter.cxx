{
  // options
  bool logyaxis   = true;
  TString channel = "electron"; // electron or muon

  // colors
  // SM backgrounds: filled histograms
  int color_ttbar   = 810;
  int color_wjets   = 416;
  int color_dy      = 400;
  int color_st      = 860;
  int color_qcd     = 867;
  int color_diboson = 880;
  // signal: line only
  int color_signal  = kBlack;


  // axes
  // x axis range
  double x_axis_lowerBound = 0;
  double x_axis_upperBound = 5000;
  // y axis range
  double y_axis_lowerBound = 1;
  double y_axis_upperBound = 100000;



  cout << endl;
  cout << "----- plotting options -----" << endl;
  cout << "             channel: " + channel << endl;
  if(logyaxis) cout << "log scale for y axis: true" << endl; else cout << "log scale for y axis: false" << endl;

  cout << endl;



  //
  TString dir      = "/nfs/dust/cms/user/jabuschh/NonResonantTTbar/RunII_102X_v2/2018/Analysis/" + channel + "/NOMINAL/";
  TString histname = "M_Zprime_rebin2";

  // ALP interference
  TFile *file_ALPinterference = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.ALP_ttbar_interference_UL18.root");
  file_ALPinterference->cd("Chi2_General");
  TH1F *h_ALPinterference = (TH1F*) gDirectory->Get(histname);
  h_ALPinterference->SetLineColor(kGray);
  h_ALPinterference->SetLineWidth(2);
  h_ALPinterference->SetLineStyle(2);
  h_ALPinterference->Scale(28.2);

  TFile *file_ALPsignal = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.ALP_ttbar_signal_UL18.root");
  file_ALPsignal->cd("Chi2_General");
  TH1F *h_ALPsignal = (TH1F*) gDirectory->Get(histname);
  h_ALPsignal->SetLineColor(kBlack);
  h_ALPsignal->SetLineWidth(2);
  h_ALPsignal->SetLineStyle(2);
  h_ALPsignal->Scale(7.051);


  // TTbar
  TFile *file_ttbar = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.TTbar.root");
  file_ttbar->cd("Chi2_General");
  TH1F *h_ttbar = (TH1F*) gDirectory->Get(histname);
  h_ttbar->SetLineColor(color_ttbar);
  h_ttbar->SetFillColor(color_ttbar);
  // WJets
  TFile *file_wjets = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.WJets.root");
  file_wjets->cd("Chi2_General");
  TH1F *h_wjets = (TH1F*) gDirectory->Get(histname);
  h_wjets->SetLineColor(color_wjets);
  h_wjets->SetFillColor(color_wjets);
  // DY
  TFile *file_dy = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.DY.root");
  file_dy->cd("Chi2_General");
  TH1F *h_dy = (TH1F*) gDirectory->Get(histname);
  h_dy->SetLineColor(color_dy);
  h_dy->SetFillColor(color_dy);
  // ST
  TFile *file_st = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.ST.root");
  file_st->cd("Chi2_General");
  TH1F *h_st = (TH1F*) gDirectory->Get(histname);
  h_st->SetLineColor(color_st);
  h_st->SetFillColor(color_st);
  // QCD
  TFile *file_qcd = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.QCD.root");
  file_qcd->cd("Chi2_General");
  TH1F *h_qcd = (TH1F*) gDirectory->Get(histname);
  h_qcd->SetLineColor(color_qcd);
  h_qcd->SetFillColor(color_qcd);
  // Diboson
  TFile *file_diboson = TFile::Open(dir + "uhh2.AnalysisModuleRunner.MC.Diboson.root");
  file_diboson->cd("Chi2_General");
  TH1F *h_diboson = (TH1F*) gDirectory->Get(histname);
  h_diboson->SetLineColor(color_diboson);
  h_diboson->SetFillColor(color_diboson);
  // stack backgrounds
  THStack stack("stack","SM backgrounds");
  stack.Add(h_diboson);
  stack.Add(h_qcd);
  stack.Add(h_st);
  stack.Add(h_dy);
  stack.Add(h_wjets);
  stack.Add(h_ttbar);


  TH1F *h_bkg = (TH1F*) h_ttbar->Clone();
  h_bkg->Add(h_wjets);
  h_bkg->Add(h_dy);
  h_bkg->Add(h_st);
  h_bkg->Add(h_qcd);
  h_bkg->Add(h_diboson);


  double c_i_over_f_a = 2.;
  TH1F *h_bkgplusALP = (TH1F*) h_ALPinterference->Clone();
  h_bkgplusALP->Scale(c_i_over_f_a);
  h_bkgplusALP->Add(h_ttbar);
  h_bkgplusALP->Add(h_wjets);
  h_bkgplusALP->Add(h_dy);
  h_bkgplusALP->Add(h_st);
  h_bkgplusALP->Add(h_qcd);
  h_bkgplusALP->Add(h_diboson);
  h_bkgplusALP->Add(h_ALPsignal,c_i_over_f_a*c_i_over_f_a);
  h_bkgplusALP->SetLineColor(color_signal);
  h_bkgplusALP->SetLineWidth(2);
  h_bkgplusALP->SetLineStyle(2);


  // ratio as hist
  TH1F *h_ratio = (TH1F*) h_bkgplusALP->Clone();
  h_ratio->Divide(h_bkg);
  h_ratio->SetLineColor(kBlack);
  h_ratio->SetLineWidth(2);
  h_ratio->SetLineStyle(1);



  // lumi tag
  double x_pos = 0.95;
  double y_pos = 0.957;
  TLatex *lumitag = new TLatex(3.5,24,"59.7 fb^{-1} (13 TeV)");
  lumitag->SetNDC();
  lumitag->SetTextAlign(31);
  lumitag->SetX(x_pos);
  lumitag->SetY(y_pos);
  lumitag->SetTextFont(42);
  lumitag->SetTextSize(0.032);
  // channel tag
  x_pos = 0.144;
  y_pos = 0.957;
  TLatex *channeltag = new TLatex(3.5,24, channel + " channel: 2018 SM + UL18 signal");
  channeltag->SetNDC();
  channeltag->SetTextAlign(11);
  channeltag->SetX(x_pos);
  channeltag->SetY(y_pos);
  channeltag->SetTextFont(62);
  channeltag->SetTextSize(0.028);
  channeltag->SetLineColor(kBlack);
  channeltag->SetLineWidth(1);
  // legend
  x_pos  = 0.49;
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
  legend->AddEntry(h_ttbar          ,"TTbar"                                      ,"f");
  legend->AddEntry(h_wjets          ,"W#plusJets"                                 ,"f");
  legend->AddEntry(h_dy             ,"DY"                                         ,"f");
  legend->AddEntry(h_st             ,"ST"                                         ,"f");
  legend->AddEntry(h_qcd            ,"QCD"                                        ,"f");
  legend->AddEntry(h_diboson        ,"Diboson"                                    ,"f");
  // legend->AddEntry(h_ALPinterference,"ALP pure interference #times (-1)"          ,"l");
  // legend->AddEntry(h_ALPsignal      ,"ALP pure signal"                            ,"l");
  legend->AddEntry(h_bkgplusALP     ,"SM + ALP incl. interference (c_{i}/f_{a}=2)","l");



  // h_ALPinterference->Scale(-1.);

  // plotting
  TCanvas *c1 = new TCanvas("c1","c1",0,0,800,800);

  // upper pad
  double upperpad_titlesize    = 0.04;
  double upperpad_topmargin    = 0.05;
  double upperpad_leftmargin   = 0.14;
  double upperpad_rightmargin  = 0.05;
  double upperpad_bottommargin = 0.25;
  double upperpad_width  = 1 - upperpad_leftmargin - upperpad_rightmargin;
  double upperpad_height = 1 - upperpad_topmargin - upperpad_bottommargin;

  TPad *upperPad = new TPad("upperPad","upperPad",0,0,1,1);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(kFALSE);
  upperPad->Draw();
  upperPad->SetTitle("upperPad");
  upperPad->SetTopMargin(upperpad_topmargin);
  upperPad->SetLeftMargin(upperpad_leftmargin);
  upperPad->SetRightMargin(upperpad_rightmargin);
  upperPad->SetBottomMargin(upperpad_bottommargin);
  upperPad->SetTicks();
  if(logyaxis) upperPad->SetLogy();
  upperPad->cd();
  // draw
  stack             .Draw("hist");
  // h_ALPinterference->Draw("hist same");
  // h_ALPsignal      ->Draw("hist same");
  h_bkgplusALP     ->Draw("hist same");
  lumitag          ->Draw("same");
  channeltag       ->Draw("same");
  legend           ->Draw("same");
  // x axis
  stack.GetXaxis()->SetRangeUser(x_axis_lowerBound,x_axis_upperBound);
  stack.GetXaxis()->SetNdivisions(50205);
  // y axis
  stack.GetYaxis()->SetTitle("Events");
  stack.GetYaxis()->SetTitleOffset(1.6);
  if(logyaxis){
    stack.SetMinimum(y_axis_lowerBound);
    stack.SetMaximum(y_axis_upperBound);
  }
  else{
    stack.SetMaximum(7E+4);
  }

  // lower pad
  TPad *lowerPad = new TPad ("lowerPad","lowerPad",0.,0.,1,0.24);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(kFALSE);
  lowerPad->Draw();
  lowerPad->SetTitle("lowerPad");
  lowerPad->SetTopMargin(0.0);
  lowerPad->SetLeftMargin(upperpad_leftmargin);
  lowerPad->SetRightMargin(upperpad_rightmargin);
  lowerPad->SetBottomMargin(0.35);
  lowerPad->SetTicks();
  // lowerPad->SetLogy();
  lowerPad->cd();




  // line at ratio = 1
  TLine *line1;
  line1 = new TLine (x_axis_lowerBound,1,x_axis_upperBound,1);
  line1->SetLineColor(kBlack);
  line1->SetLineWidth(1);
  line1->SetLineStyle(2);
  // draw
  h_ratio->Draw("hist");
  line1  ->Draw("same");
  // x axis
  h_ratio->GetXaxis()->SetTitle("m_{t#bar{t}} [GeV]");
  h_ratio->GetXaxis()->SetTitleSize(upperpad_titlesize * 10/3);
  h_ratio->GetXaxis()->SetTitleOffset(1.2);
  h_ratio->GetXaxis()->SetLabelSize(upperpad_titlesize * 10/3);
  h_ratio->GetXaxis()->SetRangeUser(x_axis_lowerBound,x_axis_upperBound);
  h_ratio->GetXaxis()->SetNdivisions(50205);
  h_ratio->GetXaxis()->SetTickLength(0.1);

  // y axis
  // TLatex yaxis_title =
  h_ratio->GetYaxis()->SetTitle("signal/bkg");
  h_ratio->GetYaxis()->CenterTitle(true);
  h_ratio->GetYaxis()->SetTitleSize(upperpad_titlesize * 10/3);
  h_ratio->GetYaxis()->SetTitleOffset(0.4);
  h_ratio->GetYaxis()->SetLabelSize(upperpad_titlesize * 10/3);
  h_ratio->GetYaxis()->SetNdivisions(-502);
  h_ratio->GetYaxis()->SetRangeUser(0.5,1.5);
  // h_ratio->SetMinimum(0.3);
  // h_ratio->SetMaximum(1.7);

  c1->Modified();

  // saving
  TString save_dir = "/nfs/dust/cms/user/jabuschh/UHH2_UL_10_6_28/CMSSW_10_6_28/src/UHH2/NonResonantTTbar/plots/";
  if(logyaxis) c1->SaveAs(save_dir + "mttbar_" + channel + "_logscale.pdf");
  else c1->SaveAs(save_dir + "mttbar_" + channel + ".pdf");
  c1->Close();
}
