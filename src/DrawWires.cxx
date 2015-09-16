#include "WireCellRootVis/Drawers.h"
#include "WireCellRootVis/Views.h"
#include "WireCellIface/IWireSelectors.h"
#include "WireCellUtil/Point.h"
#include "WireCellUtil/BoundingBox.h"

#include "TArrow.h"

using namespace WireCell;

void WireCellRootVis::draw2d(TVirtualPad& pad, const IWireVector& wires)
{    
    BoundingBox bbox;
    for (auto wire : wires) {
	bbox(wire->ray());
    }
    WireCellRootVis::view_zy(pad, bbox.bounds());

    int colors[3] = {2, 4, 1};

    IWireVector u_wires, v_wires, w_wires;
    std::copy_if(wires.begin(), wires.end(), back_inserter(u_wires), select_u_wires);
    std::copy_if(wires.begin(), wires.end(), back_inserter(v_wires), select_v_wires);
    std::copy_if(wires.begin(), wires.end(), back_inserter(w_wires), select_w_wires);
    size_t n_wires[3] = {
	u_wires.size(),
	v_wires.size(),
	w_wires.size()
    };

    for (auto wit = wires.begin(); wit != wires.end(); ++wit) {
	IWire::pointer wire = *wit;
	int iplane = wire->planeid().index();
	int index = wire->index();

	const Ray ray = wire->ray();

	TArrow* a_wire = new TArrow(ray.first.z(), ray.first.y(),
				    ray.second.z(), ray.second.y(), 0.01, "|>");
	a_wire->SetLineColor(colors[iplane]);
	//a_wire->SetLineWidth(width);
	a_wire->Draw();
    }
}
