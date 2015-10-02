#include "WireCellRootVis/Drawers.h"
#include "WireCellUtil/BoundingBox.h"

#include "TView.h"
#include "TPolyMarker3D.h"
#include "TColor.h"

using namespace WireCell;

void WireCellRootVis::draw2d(TVirtualPad& pad, const WireCell::IDepo::vector& depos)
{
    BoundingBox bbox;
    double tmin=-1, tmax=-1;
    for (auto depo : depos) {
	bbox(depo->pos());
	if (tmin<0 && tmax<0) {
	    tmin = tmax = depo->time();
	    continue;
	}
	tmin = std::min(tmin, depo->time());
	tmax = std::max(tmax, depo->time());
    }
    const Ray bb = bbox.bounds();

    TView* view = TView::CreateView(1);
    view->SetRange(bb.first.x(),bb.first.y(),bb.first.z(),
		   bb.second.x(),bb.second.y(),bb.second.z());
    view->ShowAxis();

    for (auto depo : depos) {
	if (!depo) { break; }

	TPolyMarker3D* pm = new TPolyMarker3D(1,8);
	const Point& p = depo->pos();
	pm->SetPoint(0, p.x(), p.y(), p.z());

	double rel = depo->time()/(tmax-tmin);
	int col = TColor::GetColorPalette( int(rel*TColor::GetNumberOfColors()) );
	pm->SetMarkerColor(col);

	pm->Draw();
    }
    
}
