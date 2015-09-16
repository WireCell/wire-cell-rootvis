#ifndef WIRECELLROOTVIS_CANVASAPP
#define WIRECELLROOTVIS_CANVASAPP

#include "TCanvas.h"
#include "TApplication.h"

#include <memory>
#include <string>

namespace WireCellRootVis {

    class CanvasApp {
	std::string m_name;
	TApplication* m_app;
	TCanvas* m_canvas;
	bool m_pdf_open;
	int m_npad;
    public:
	CanvasApp(const std::string& name, bool interactive = false, int hsize=800, int vsize=800);
	~CanvasApp();

	TCanvas& canvas() { return *m_canvas; }

	/// Output current canvas contents to PDF.
	void pdf();

	/// Run the app, no-op if not interactive.  At end, do a final closing TCanvas::Print().
	void run();

	/// Divide the canvas into nh x nv pads
	void divide(int nh, int nv);

	/// Get the n'th pad.  If not divided return the canvas.  If
	/// n<0 advance to the next empty pad
	TVirtualPad& pad(int n=-1);

	/// Clear canvas and return it.  This also removes any divisions.
	TVirtualPad& clear();

    };

    
}

#endif
