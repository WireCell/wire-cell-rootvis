#ifndef WIRECELLROOTVIS_DRAWERS
#define WIRECELLROOTVIS_DRAWERS


#include "WireCellIface/IWireParameters.h"
#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"
#include "WireCellIface/IDepo.h"
#include "WireCellIface/IDiffusion.h"

#include "TPad.h"

namespace WireCellRootVis {

    void draw2d(TVirtualPad& pad, WireCell::IWireParameters::pointer wire_parameters);

    void draw2d(TVirtualPad& pad, const WireCell::IWireVector& wires);

    void draw2d(TVirtualPad& pad, const WireCell::ICellVector& cells);

    void draw2d(TVirtualPad& pad, const WireCell::IDepoVector& depos);

    void draw2d(TVirtualPad& pad, const WireCell::IDiffusionVector& diffusions);

}


#endif

