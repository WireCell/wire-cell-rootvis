#include "WireCellRootVis/Drawers.h"
#include "WireCellUtil/BoundingBox.h"

#include "TPolyLine.h"

#include <iostream>

using namespace WireCell;
using namespace std;

void WireCellRootVis::draw2d(TVirtualPad& pad, const ICellVector& cells)
{
    BoundingBox bbox;
    for (auto cell: cells) {
	bbox(cell->center());
    }

    const Ray bb = bbox.bounds();
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
