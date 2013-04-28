#include <iostream>
#include <cstdlib>
#include <deque>
#include <cmath>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include "mainwindow.h"

using namespace std;

/** @mainpage Grant Derderian's CS102 Programming Assignment #4
*		@section purpose Overview
*		This program allows a user to play a sliding tile puzzle game through an interactive GUI, and be able to run an A* algorithm on their game to get a list of solutions to solve the puzzle.
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
*		./puzzle_gderderi
*/
int main(int argc, char *argv[])
{
		/** Initialize the QApplication and a MainWindow, and show the window appropriately */
		QApplication app(argc, argv);
		MainWindow w;
    w.show();
    return app.exec();
  
}
