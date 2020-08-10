std::map<TString, TString> ang_labels = {{"ptD","p_{T}^{D}"},{"multiplicity","Multiplicity"},{"LHA","LHA"},{"mass","Mass"},{"width","Width"}};
std::map<TString, TString> samp_labels = {{"dijets","Dijets"},{"zplusjets","Z+jets"},{"H2qqbar","H #rightarrow q#bar{q}"},{"H2qqbar_ee","H #rightarrow q#bar{q} (e^{+}e^{-})"},{"H2gg","H #rightarrow gg"},{"H2gg_ee","H #rightarrow gg (e^{+}e^{-})"},{"gg2Hg","gg #rightarrow Hg"},{"qqbar2Zg","q#bar{q} #rightarrow Zg"}};
TString analysis_path = "/global/homes/s/sambt/Jets/qg_tagging_topology_project/analysis/analysis_output";

TH1F* integrand(TH1F *h1, TH1F *h2) {
  TH1F *denom = (TH1F*)h1->Clone();
  denom->Add(h2);
  TH1F *num = (TH1F*)h1->Clone();
  num->Add(h2,-1);
  num->Multiply(num);
  num->Divide(denom);
  return num;
}
