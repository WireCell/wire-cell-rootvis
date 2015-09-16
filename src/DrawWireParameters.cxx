#include "WireCellRootVis/Drawers.h"

#include "TH1F.h"
#include "TArrow.h"

using namespace WireCell;

void WireCellRootVis::draw2d(TVirtualPad& pad, IWireParameters::pointer wp)
{
    TH1F* frame = pad.DrawFrame(0,-10, 20,10);
    frame->SetTitle("Pitch (thick) and wire (thin) red=U, blue=V, +X (-drift) direction into page");
    frame->SetXTitle("Transverse Z direction");
    frame->SetYTitle("Transverse Y (W) direction");

    int colors[3] = {2, 4, 1};

    const Vector xaxis(1,0,0);
    const Ray pitch_rays[3] = { wp->pitchU(), wp->pitchV(), wp->pitchW() };

    for (int ind=0; ind<3; ++ind) {
	Ray r_pitch = pitch_rays[ind];
	r_pitch.first.x(0.0);
	r_pitch.second.x(0.0);


	const Vector d_pitch = ray_vector(r_pitch).norm();
	const Vector d_wire = d_pitch.cross(xaxis).norm();
	const Ray r_wire(r_pitch.second - d_wire,
			 r_pitch.second + d_wire);

	TArrow* a_pitch = new TArrow(r_pitch.first.z(), r_pitch.first.y(),
				     r_pitch.second.z(), r_pitch.second.y(), 0.01, "|>");
	a_pitch->SetLineColor(colors[ind]);
	a_pitch->SetLineWidth(2);

	TArrow* a_wire = new TArrow(r_wire.first.z(), r_wire.first.y(),
				    r_wire.second.z(), r_wire.second.y(), 0.01);
	a_wire->SetLineColor(colors[ind]);

	a_pitch->Draw();
	a_wire->Draw();
    }
    
    
}


