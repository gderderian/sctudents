#include <iostream>
#include <cstdlib>
#include <deque>
#include <cmath>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include "mainwindow.h"

using namespace std;

/** @mainpage Grant Derderian's CS102 Programming Assignment #5
*		@section purpose Overview
*		SCtudents allows a player to model the fictional life of a student at USC by dodging obstacles and gaining lives and points as they progress through a part of campus to reach Tommy Trojan on each level.
*		@section requirements Program Requirements and Compiling Instructions
*		To compile the program only, run the following commands
*		 qmake -project
*		 qmake
*		 make
*		To generate doxygen documentation for the program, run the following commands
*		 doxygen -g config.txt
*		 doxygen config.txt
*		@section gameplay Gameplay Instructions
*		To run the program and begin the interactive GUI, run the following command
*		./game_gderderi
*/
int main(int argc, char *argv[])
{
		/** Initialize the QApplication and a MainWindow, and show the window appropriately */
		QApplication app(argc, argv);
		MainWindow w;
    w.show();
    return app.exec();
  
}
