#include "WireCellRootVis/CanvasApp.h"

#include <iostream>
using namespace std;


WireCellRootVis::CanvasApp::CanvasApp(const std::string& name, bool interactive,
				      int hsize, int vsize)
    : m_name(name), m_app(0), m_canvas(0), m_pdf_open(false), m_npad(-1)
{
    if (interactive) {
	m_app = new TApplication(name.c_str(), 0, 0);
    }
    std::string cname = "canvas_" + name;
    m_canvas = new TCanvas(cname.c_str(), cname.c_str(), hsize, vsize);
    
}
WireCellRootVis::CanvasApp::~CanvasApp ()
{
    delete m_canvas;
    m_canvas = 0;
    // leak app?
}
void WireCellRootVis::CanvasApp::pdf()
{
    std::string fn = m_name + ".pdf";
    if (!m_pdf_open) {
	std::string fninit = fn+"[";
	m_canvas->Print(fninit.c_str(),"pdf");
	m_pdf_open = true;
    }
    m_canvas->Print(fn.c_str(),"pdf");
}
void WireCellRootVis::CanvasApp::run()
{
    if (m_app) { m_app->Run(); }
    if (m_pdf_open) {
	cerr << "Final print to " << m_name << endl;
	std::string fnterm = m_name + ".pdf]";
	m_canvas->Print(fnterm.c_str(),"pdf");
	m_pdf_open = false;
    }

}
void WireCellRootVis::CanvasApp::divide(int nh, int nv)
{
    m_npad = 0;
    m_canvas->Clear();
    m_canvas->Divide(nh, nv);
}

TVirtualPad& WireCellRootVis::CanvasApp::pad(int n)
{
    if (n==0) {
	return *m_canvas;
    }
    if (n>0) {
	return *m_canvas->cd(n);
    }
    if (m_npad<0) {
	return *m_canvas;
    }
    return *m_canvas->cd(++m_npad);
}

TVirtualPad& WireCellRootVis::CanvasApp::clear()
{
    m_canvas->Clear();
    return *m_canvas;
}
