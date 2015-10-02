#ifndef WIRECELLROOTVIS_DRAWERS
#define WIRECELLROOTVIS_DRAWERS


#include "WireCellIface/IWireParameters.h"
#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"
#include "WireCellIface/IDepo.h"
#include "WireCellIface/IDiffusion.h"
#include "WireCellIface/ICellSlice.h"

#include "TPad.h"
#include <vector>

namespace WireCellRootVis {

    void draw2d(TVirtualPad& pad, const WireCell::IWireParameters& wire_parameters);

    void draw2d(TVirtualPad& pad, const WireCell::IWire::vector& wires,
		const std::vector<int>& colors = {2,4,1});

    void draw2d(TVirtualPad& pad, const WireCell::ICell::vector& cells);

    void draw2d(TVirtualPad& pad, const WireCell::IDepo::vector& depos);

    void draw2d(TVirtualPad& pad, const WireCell::IDiffusion::vector& diffusions);


    void draw3d(TVirtualPad& pad, const WireCell::ICellSlice::vector& csv);
}


#endif

