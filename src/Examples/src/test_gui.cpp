// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/Aurora.h>
using namespace Aurora;


GUIApplication *MyGUIApp;
GUIWindow *FirstWindow;
GUILabel *HelloLabel;

arslot_t slot_MyWindow_on_open()
{
	HelloLabel->setText("Hello, World!");
	HelloLabel->setSelectable(true);
}

arslot_t slot_MyGUIApp_on_open()
{
	FirstWindow = new GUIWindow("First Window", 800, 600, GUIWindow::NonePosition, GUIWindow::ToplevelWindow);
	HelloLabel = new GUILabel(FirstWindow, "Hello World!");
	FirstWindow->start(slot_MyWindow_on_open);
}

int main(int argc, char * argv[])
{
	MyGUIApp = new GUIApplication("org.aurora.example", GUIApplication::NoneFlag, slot_MyGUIApp_on_open, argc, argv);
	return MyGUIApp->AppStatus;

}