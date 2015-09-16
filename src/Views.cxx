#include "WireCellRootVis/Views.h"


std::shared_ptr<TH1F> WireCellRootVis::view_zy(TVirtualPad& pad,
					       const WireCell::Ray& bounds,
					       const char* title,
					       const char* xtitle,
					       const char* ytitle)
{
    std::shared_ptr<TH1F> frame(pad.DrawFrame(bounds.first.z(), bounds.first.y(),
					      bounds.second.z(), bounds.second.y()));
    if (!title) {
	title = "red=U, blue=V, +X (-drift) direction into page";
    }
    if (!xtitle) {
	xtitle = "Transverse Z direction";
    }
    if (!ytitle) {
	ytitle = "Transverse Y (W) direction";
    }

    frame->SetTitle(title);
    frame->SetXTitle(xtitle);
    frame->SetYTitle(ytitle);
    return frame;
}
