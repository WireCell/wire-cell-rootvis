#include "WireCellRootVis/Drawers.h"

#include "WireCellUtil/BoundingBox.h"

#include "TPolyLine.h"
#include "TView.h"
#include "TGraph2D.h"

#include <iostream>

using namespace WireCell;
using namespace std;

static Ray bounds(const ICell::vector& cells)
{
    BoundingBox bbox;
    for (auto cell: cells) {
	bbox(cell->center());
    }
    return bbox.bounds();
}
void WireCellRootVis::draw2d(TVirtualPad& pad, const ICell::vector& cells)
{
    Ray bb = bounds(cells);
    const double enlarge = 1.2;
    pad.DrawFrame(enlarge*bb.first.z(), enlarge*bb.first.y(),
		  enlarge*bb.second.z(), enlarge*bb.second.y());

    int colors[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, -1};
    int ncolors=0;
    while (colors[ncolors] >= 0) { ++ncolors; }

    const double reduce = 0.8;
    int ncells = cells.size();

    for (int cind = 0; cind < ncells; ++cind) {
	ICell::pointer cell = cells[cind];

        WireCell::PointVector corners = cell->corners();
	const Point center = cell->center();

	size_t ncorners = corners.size();

	TPolyLine* pl = new TPolyLine;
	int ind=0;
	Point first_point;
	for (; ind<ncorners; ++ind) {
	    const Point& p = corners[ind];
	    const Point shrunk = reduce*(p - center) + center;
	    pl->SetPoint(ind, shrunk.z(), shrunk.y());
	    if (!ind) {
		first_point = shrunk;
	    }
	}
	pl->SetPoint(ind, first_point.z(), first_point.y());
	pl->SetFillColor(colors[cind%ncolors]);
	pl->SetLineWidth(0);
	pl->Draw("f");
    }

}

void WireCellRootVis::draw3d(TVirtualPad& pad, const WireCell::ICellSlice::vector& csv)
{
    TGraph2D* graph = new TGraph2D; // leak!
    BoundingBox bbox;
    for (auto cs : csv) {
	ICell::shared_vector cells = cs->cells();
	if (!cells) {
	    continue;
	}
	for (auto cell : *cells) {
	    Point c = cell->center();
	    Point p(cs->time(), c.y(), c.z());
	    bbox(p);
	    graph->SetPoint(graph->GetN(), p.x(), p.y(), p.z());
	}
    }
    Ray bb = bbox.bounds();

    TView* view = TView::CreateView(1);
    view->SetRange(bb.first.x(),bb.first.y(),bb.first.z(),
		   bb.second.x(),bb.second.y(),bb.second.z());
    view->ShowAxis();
    graph->Draw("P");
}
