#ifndef WIRECELLROOTVIS_VIEWS
#define WIRECELLROOTVIS_VIEWS

#include "WireCellUtil/Point.h"

#include "TCanvas.h"
#include "TH1F.h"

#include <memory>

namespace WireCellRootVis {

    std::shared_ptr<TH1F> view_zy(TVirtualPad& pad,
				  const WireCell::Ray& bounds,
				  const char* title = nullptr,
				  const char* xtitle = nullptr,
				  const char* ytitle = nullptr);
    
}

#endif
