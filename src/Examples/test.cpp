// ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
// ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
// ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
//  Copyright (c) 2016 - Luís Ferreira. All right reserved
//  More information in: https://github.com/ljmf00/ (Github Page)

#include <Aurora/Aurora.h>

using namespace std;

arslot_t slot_MyApp_on_open()
{
	GUIWindow *FirstWindow = new GUIWindow();
	AuroraShell::Log::Information(to_string(AuroraInfo::RAM::getTotalVirtualMemory()));
	FirstWindow->start();
}

int main(int argc, char * argv[])
{
	GUIApplication *MyApp = new GUIApplication("org.aurora.example", GUIApplication::NoneFlag, slot_MyApp_on_open, argc, argv);
	return MyApp->AppStatus;
}
