#include "WireCellRootVis/Drawers.h"
#include <limits> 

#include "TH2F.h"

void WireCellRootVis::draw2d(TVirtualPad& pad, const WireCell::IDiffusionVector& diffusions)
{
    double lmin, lmax, tmin, tmax;
    lmin = tmin = std::numeric_limits<double>::max();
    lmax = tmax = std::numeric_limits<double>::min();

    for (auto diff : diffusions) {
	lmin = std::min(lmin, diff->lbegin());
	lmax = std::max(lmax, diff->lend());
	tmin = std::min(tmin, diff->tbegin());
	tmax = std::max(tmax, diff->tend());
    }

    TH2F* hist = new TH2F("diffusion","diffusion",
			  (lmax-lmin)/diffusions[0]->lbin(), lmin, lmax,
			  (tmax-tmin)/diffusions[0]->tbin(), tmin, tmax);
    hist->SetXTitle("Longitudinal direction (drift time)");
    hist->SetYTitle("Transverse direction (pitch)");

    for (auto smear : diffusions) {
	for (int tind = 0; tind < smear->tsize(); ++tind) {
	    for (int lind = 0; lind < smear->lsize(); ++lind) {
		double val = smear->get(lind, tind);
		if (val == 0.0) { continue; }
		hist->Fill(smear->lpos(lind,0.5), smear->tpos(tind,0.5), val);
	    }
	}
    }

    hist->Draw("colz");
}
