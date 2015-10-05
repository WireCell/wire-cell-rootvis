#include "WireCellRootVis/Converters.h"


TPolyMarker3D* WireCellRootVis::polymarker3d(const WireCell::IDepo::vector& depos,
					     int color, int marker_type)
{
    TPolyMarker3D* pm = new TPolyMarker3D(depos.size(), marker_type);
    int indx=0;
    for (auto depo : depos) {
	const WireCell::Point& p = depo->pos();
	pm->SetPoint(indx++, p.x(), p.y(), p.z());
    }
    pm->SetMarkerColor(color);
    return pm;
}


TArrow* WireCellRootVis::arrow(const WireCell::Ray& ray, int color)
{

    TArrow* ar = new TArrow(ray.first.z(), ray.first.y(),
			    ray.second.z(), ray.second.y(), 0.01, "|>");
    ar->SetLineColor(color);
    return ar;
}

