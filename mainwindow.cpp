#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QPushButton>
#include <QLabel>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QString>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include "thing.h"
#include "player.h"
#include "skateboarder.h"
#include "coffee.h"
#include "grades.h"
#include "food.h"
#include "extracredit.h"

using namespace std;

/** Constructor for MainWindow, which sets up the initial GUI menu, sets initial variables and images, and loads the menu screen for the user to enter their name and begin a game from.
 */
MainWindow::MainWindow(QWidget *parent) : QWidget(parent){

		/** Sets up the initial windows, scenes, and layouts */
		window = new QWidget();
   	gameScene = new QGraphicsScene();
   	gameView = new QGraphicsView(gameScene);
   	mainStackables = new QVBoxLayout();
   	iconStackables = new QHBoxLayout();
   	
   	/** Sets up layouts specifically for the veritical and horizontal boxes with the main menu item display */
   	skateboarderLayout = new QVBoxLayout();
   	trogroLayout = new QVBoxLayout();
   	gradesLayout = new QVBoxLayout();
   	foodLayout = new QVBoxLayout();
   	ecreditLayout = new QVBoxLayout();
   	
   	/** Set the window's size and title */
   	window->setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y);
   	window->setWindowTitle("Grant Derderian PA5 - SCtudents Qt Game");
		
		/** Sets up initial fonts for the GUI menu and gameplay menubar */
		QFont titlefont("Arial", 60, QFont::Bold);
		QFont instructionsFont("Arial", 11, QFont::Normal);
		QFont itemnameFont("Arial", 14, QFont::Bold);
		QFont itemdescFont("Arial", 12, QFont::Normal);
		QFont gamebarFont("Arial", 12, QFont::Bold);
		
		/** Menu screen title */
		gametitleLabel = new QLabel();
		gametitleLabel->setText("SCtudents");
		gametitleLabel->setFont(titlefont);
		gametitleLabel->setAlignment(Qt::AlignHCenter);
		mainStackables->addWidget(gametitleLabel);

		/** Welcome instructions label */
		instructionsLabel = new QLabel();
		instructionsLabel->setText("Welcome! Take a look at the items below and how they affect your character before beginning.");
		instructionsLabel->setFont(instructionsFont);
		instructionsLabel->setAlignment(Qt::AlignHCenter);
		mainStackables->addWidget(instructionsLabel);

		/** Basic directions label */
		directionsLabel = new QLabel();
		directionsLabel->setText("You have four lives. Use the space bar to jump, the arrow keys to side to side, and P to pause.");
		directionsLabel->setFont(instructionsFont);
		directionsLabel->setAlignment(Qt::AlignHCenter);
		mainStackables->addWidget(directionsLabel);
		
		/** Creates the skateboarder image, image title label, and description of the object, and adds them to a layout within the main menu GUI */
		skateboarder = new QLabel();
		QPixmap sb_img("images/skateboarder.png");
		skateboarder->setPixmap(sb_img.scaled(100,100,Qt::KeepAspectRatio));
		skateboarder->setAlignment(Qt::AlignHCenter);
		skateboardernameLabel = new QLabel();
		skateboardernameLabel->setText("Skateboarder");
		skateboardernameLabel->setFont(itemnameFont);
		skateboardernameLabel->setAlignment(Qt::AlignHCenter);
		skateboarderinfoLabel = new QLabel();
		skateboarderinfoLabel->setText("deducts points/lives");
		skateboarderinfoLabel->setFont(itemdescFont);
		skateboarderinfoLabel->setAlignment(Qt::AlignHCenter);
		skateboarderLayout->addWidget(skateboarder);
		skateboarderLayout->addWidget(skateboardernameLabel);
		skateboarderLayout->addWidget(skateboarderinfoLabel);
		iconStackables->addLayout(skateboarderLayout);
		
		/** Creates the coffee image, image title label, and description of the object, and adds them to a layout within the main menu GUI */
		trogro = new QLabel();
		QPixmap tg_img("images/coffee.png");
		trogro->setPixmap(tg_img.scaled(100,100,Qt::KeepAspectRatio));
		trogro->setAlignment(Qt::AlignHCenter);
		trogronameLabel = new QLabel();
		trogronameLabel->setText("TroGro Coffee");
		trogronameLabel->setFont(itemnameFont);
		trogronameLabel->setAlignment(Qt::AlignHCenter);
		trogroinfoLabel = new QLabel();
		trogroinfoLabel->setText("adds a life");
		trogroinfoLabel->setFont(itemdescFont);
		trogroinfoLabel->setAlignment(Qt::AlignHCenter);
		trogroLayout->addWidget(trogro);
		trogroLayout->addWidget(trogronameLabel);
		trogroLayout->addWidget(trogroinfoLabel);
		iconStackables->addLayout(trogroLayout);
		
		/** Creates the grades image, image title label, and description of the object, and adds them to a layout within the main menu GUI */
		grades = new QLabel();
		QPixmap g_img("images/grades.png");
		grades->setPixmap(g_img.scaled(100,100,Qt::KeepAspectRatio));
		grades->setAlignment(Qt::AlignHCenter);
		gradesnameLabel = new QLabel();
		gradesnameLabel->setText("Good Grades");
		gradesnameLabel->setFont(itemnameFont);
		gradesnameLabel->setAlignment(Qt::AlignHCenter);
		gradesinfoLabel = new QLabel();
		gradesinfoLabel->setText("add points");
		gradesinfoLabel->setFont(itemdescFont);
		gradesinfoLabel->setAlignment(Qt::AlignHCenter);
		gradesLayout->addWidget(grades);
		gradesLayout->addWidget(gradesnameLabel);
		gradesLayout->addWidget(gradesinfoLabel);
		iconStackables->addLayout(gradesLayout);

		/** Creates the food image, image title label, and description of the object, and adds them to a layout within the main menu GUI */
		food = new QLabel();
		QPixmap f_img("images/food.png");
		food->setPixmap(f_img.scaled(100,100,Qt::KeepAspectRatio));
		food->setAlignment(Qt::AlignHCenter);
		foodnameLabel = new QLabel();
		foodnameLabel->setText("Dining Hall Food");
		foodnameLabel->setFont(itemnameFont);
		foodnameLabel->setAlignment(Qt::AlignHCenter);
		foodinfoLabel = new QLabel();
		foodinfoLabel->setText("deducts points/lives");
		foodinfoLabel->setFont(itemdescFont);
		foodinfoLabel->setAlignment(Qt::AlignHCenter);
		foodLayout->addWidget(food);
		foodLayout->addWidget(foodnameLabel);
		foodLayout->addWidget(foodinfoLabel);
		iconStackables->addLayout(foodLayout);
		
		/** Creates the extra credit image, image title label, and description of the object, and adds them to a layout within the main menu GUI */
		ecredit = new QLabel();
		QPixmap ecdt_img("images/ecredit.png");
		ecredit->setPixmap(ecdt_img.scaled(100,100,Qt::KeepAspectRatio));
		ecredit->setAlignment(Qt::AlignHCenter);
		ecreditnameLabel = new QLabel();
		ecreditnameLabel->setText("Extra Credit");
		ecreditnameLabel->setFont(itemnameFont);
		ecreditnameLabel->setAlignment(Qt::AlignHCenter);
		ecreditinfoLabel = new QLabel();
		ecreditinfoLabel->setText("adds points");
		ecreditinfoLabel->setFont(itemdescFont);
		ecreditinfoLabel->setAlignment(Qt::AlignHCenter);
		ecreditLayout->addWidget(ecredit);
		ecreditLayout->addWidget(ecreditnameLabel);
		ecreditLayout->addWidget(ecreditinfoLabel);
		iconStackables->addLayout(ecreditLayout);

		/** Creates the label prompting the user to enter in their name */
		nameInstructions = new QLabel();
		nameInstructions->setText("Enter Your Name and Press Start Below to Begin!");
		nameInstructions->setFont(instructionsFont);
		nameInstructions->setAlignment(Qt::AlignHCenter);

		/** Creates the label to show the user a high score, if set */
		hScore = getHighScore();
		hscoreLabel = new QLabel();
		if (hScore != -1){
			string hScorer = getHighScorer();
			hscoreLabel->setText(QString::fromStdString("High Score ") + QString::number(hScore) + QString::fromStdString(" was set by ") + QString::fromStdString(hScorer));
		} else {
			hscoreLabel->setText("No high score has been achieved yet! Go play and set one!");
		}
		hscoreLabel->setFont(itemnameFont);
		hscoreLabel->setAlignment(Qt::AlignHCenter);

		/** Creates the text box for the user to enter in their name */
		nameBox = new QLineEdit();
		nameLayout = new QFormLayout();
		nameLayout->addRow("Your &Name:",nameBox);
		
		/** Adds the start button and connects it to the startGame() function */
		startgameButton = new QPushButton("Start Game");
		connect(startgameButton, SIGNAL(clicked()), this, SLOT(startGame()));		

		/** Adds the icons, instructions, name box, and start button to the main layout */
		mainStackables->addLayout(iconStackables);
		mainStackables->addWidget(nameInstructions);
		mainStackables->addWidget(hscoreLabel);
		mainStackables->addLayout(nameLayout);
		mainStackables->addWidget(startgameButton);
		window->setLayout(mainStackables);
		
		/** Creates the initial in-game menubar and layout */
		gameStackables = new QVBoxLayout();
		gameBar = new QHBoxLayout();
		menuBar = new QHBoxLayout();
		
		/** Creates the in-game username label, adds it to the layout, and justifies it properly */
		usernameLabel = new QLabel();
		usernameLabel->setText("User:");
		usernameLabel->setFont(gamebarFont);
		usernameLabel->setAlignment(Qt::AlignLeft);
		gameBar->addWidget(usernameLabel);
		
		/** Creates the in-game level name label, adds it to the layout, and justifies it properly */
		levelnameLabel = new QLabel();
		levelnameLabel->setText("Level:");
		levelnameLabel->setFont(gamebarFont);
		levelnameLabel->setAlignment(Qt::AlignHCenter);
		gameBar->addWidget(levelnameLabel);
		
		/** Creates the in-game user score label, adds it to the layout, and justifies it properly */
		scoreLabel = new QLabel();
		scoreLabel->setText("Score:");
		scoreLabel->setFont(gamebarFont);
		scoreLabel->setAlignment(Qt::AlignRight);
		gameBar->addWidget(scoreLabel);
		
		/** Creates the in-game user lives label, adds it to the layout, and justifies it properly */
		livesLabel = new QLabel();
		livesLabel->setText("Lives:");
		livesLabel->setFont(gamebarFont);
		livesLabel->setAlignment(Qt::AlignRight);
		gameBar->addWidget(livesLabel);
		
		/** Creates the in-game start/restart button */
		ingamestartButton = new QPushButton("Start Game");
		connect(ingamestartButton, SIGNAL(clicked()), this, SLOT(restartGame()));	
		menuBar->addWidget(ingamestartButton);

		/** Creates the in-game pause button */
		ingamepauseButton = new QPushButton("Pause Game");
		connect(ingamepauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
		menuBar->addWidget(ingamepauseButton);
		
		/** Creates the in-game quit button */
		ingamequitButton = new QPushButton("Quit Game");
		connect(ingamequitButton, SIGNAL(clicked()), this, SLOT(quitGame()));
		menuBar->addWidget(ingamequitButton);
		
		/** Adds the game menubar, view, and footer buttons to a larger layout */
		gameStackables->addLayout(gameBar);
		gameStackables->addWidget(gameView);
		gameStackables->addLayout(menuBar);

		/** Creates and initially sets and connects, but does not start, the main game timer */
		gameTimer = new QTimer();
		levelTimer = 50;
    gameTimer->setInterval(levelTimer);
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(handleTimer()));
		
		/** Seeds random and sets game started variable to not started */
		srand(time(NULL));
		gameStarted = false;

}

/** Starts the game by checking for name input errors (too long or missing), setting focus, setting initial game environmental variables, then clearing the main menu's items, setting up the game view, and adding the player and background image to the screen.
*/
void MainWindow::startGame()
{
	
	/** Checks to make sure the user-entered name is not blank or over 38 characters, which can cause layout issues */
	if (nameBox->text() == ""){
		 QMessageBox msgBox;
 			msgBox.setText("You must enter a username in order to proceed.");
 			msgBox.exec();
 			return;
	} else if ((nameBox->text()).length() >= 38) {
			QMessageBox msgBox;
 			msgBox.setText("Enter a shorter username, please!");
 			msgBox.exec();
 			return;
	}
	
	/** Sets focus and grabs the keyboard input for arrow key controls */
	setFocusPolicy(Qt::StrongFocus);
	grabKeyboard();
	
	/** Sets appropriate in-game variables */
	score = 0;
	lives = 4;
	level = 1;
	timerRuns = 1;
	cols_with_food = 0;
	cols_with_sboarders = 0;
	ecredit_rate = 450;
	food_rate = 100;
	goUp = false;
	goDown = false;
	goLeft = false;
	goRight = false;
	gameStarted = true;
	paused = false;
	
	/** Adds and sets the username label on the gameplay screen */
	userName = (nameBox->text()).toUtf8().constData();
	string uname = "User: " + userName;
	usernameLabel->setText(QString::fromStdString(uname));
	
	/** Adjusts and adds the level name, score, and lives labels to the gameplay scene/view */
	levelnameLabel->setText(QString::fromStdString("Level: ") + QString::number(level) + QString::fromStdString(" - Founders Park"));
	scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
	livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
	
	/** Deletes items from the main menu GUI because the game is started and they are not needed anymore */
	delete mainStackables;
	delete gametitleLabel;
  delete instructionsLabel;
  delete directionsLabel;
  delete skateboarder;
  delete skateboardernameLabel;
 	delete skateboarderinfoLabel;
  delete trogro;
  delete trogronameLabel;
  delete trogroinfoLabel;
  delete grades;
  delete gradesnameLabel;
  delete gradesinfoLabel;
  delete food;
  delete foodnameLabel;
  delete foodinfoLabel;
 	delete ecredit;
 	delete ecreditnameLabel;
 	delete ecreditinfoLabel;
  delete nameInstructions;
  delete nameBox;
  delete startgameButton;
  delete hscoreLabel;
  
  /** Changes the main layout of the screen to the game layout from that of the main menu */
	window->setLayout(gameStackables);
	
	/** Begins game timer (interval was previously set and begins at 50) */
	gameTimer->start();
	
	/** Adds the Trousdale Parkway background image to the main game scene */
	bg_img = new QGraphicsPixmapItem(QPixmap("images/founderspark.jpg").scaledToHeight(450));
	bg_img->setPos(0,0);
	gameScene->addItem(bg_img);
	
	/** Adds the user's character to the game screen */
	QPixmap player_img("images/sctudent.png");
	character = new Player(&player_img, 225, 225);
	gameScene->addItem(character);
	objects.push_back(character);
	
}
/** Shows the main window of the program. Called by Qtapplication or other main class.
*/
void MainWindow::show()
{
    window->show();
}

/** Handles each iteration of the master game timer by checking for game end state, creating new objects as necesary, advancing the level as necessary, moving all objects on the screen, checking for collisions to add and decuct points or lives as necessary, and moving the main player's character if required.
*/
void MainWindow::handleTimer()
{

	/** Stop gameplay if the user has lost a game via a score of <=0 or a number of lives <=0. Inform the user by replacing the level label with a game over message.*/
	if ((gameStarted == true && lives <= 0) || (gameStarted == true && score < 0)){
		gameTimer->stop();
		levelnameLabel->setText(QString::fromStdString("Game Over!"));
	}
	
	/** Create game object images (pixmaps) */
	QPixmap trogro_img("images/coffee.png");
	QPixmap grades_img("images/grades.png");
	QPixmap food_img("images/food.png");
	QPixmap sboarder_img("images/skateboarder.png");
	QPixmap ecredit_img("images/ecredit.png");
	
	/** Generate random numbers for positioning items */
	int rand_x = rand() % 600;
	int rand_y = rand() % 325;
	
	/** Adds a new grades item every 50 iterations and pushes it to the main objects vector */
	if (timerRuns % 50 == 0){
		grade = new Grades(&grades_img, 0, rand_y);
		gameScene->addItem(grade);
		objects.push_back(grade);
	}
	
	/** Adds a new skatebaorder item every 100 iterations and pushes it to the main objects vector */
	if (timerRuns % 100 == 0){
		boarder = new Skateboarder(&sboarder_img, 550, rand_y);
		gameScene->addItem(boarder);
		objects.push_back(boarder);
	}
	
	/** Adds a new dining hall food item every 100 iterations and pushes it to the main objects vector */
	if (timerRuns % food_rate == 0){
		eat = new Food(&food_img, rand_x, 350);
		gameScene->addItem(eat);
		objects.push_back(eat);
	}
	
	/** Adds a coffee (life) item every 750 iterations and pushes it to the main objects vector */
	if (timerRuns % 750 == 0){
		starbucks = new Coffee(&trogro_img, 550, rand_y);
		gameScene->addItem(starbucks);
		objects.push_back(starbucks);
	}
	
	/** Adds a new extra credit item every 450 iterations and pushes it to the main objects vector */
	if (timerRuns % ecredit_rate == 0){
		ec = new ExtraCredit(&ecredit_img, 550, rand_y);
		gameScene->addItem(ec);
		objects.push_back(ec);
	}
	
	/** Moves all objects as necessary at each timer iteration by looping through the objects vector */
	for (unsigned int i=0; i < objects.size(); i++) {
		if (timerRuns % 1 == 0){
			objects.at(i)->move();
		}
	}
	
	/** Advanced the game to a new level every 500 iterations */
	if (timerRuns % 500 == 0){
			
			/** Increases level counter and decreases timer interval */
			level++;
			levelTimer = levelTimer - 10;
			gameTimer->setInterval(levelTimer);
			
			/** Sets level name */
			if (level == 1){
				levelname = "Founders Park";
				bg_img->setPixmap(QPixmap("images/founderspark.jpg").scaledToHeight(450));
			} else if (level == 2){
				levelname = "Alumni Park";
				bg_img->setPixmap(QPixmap("images/alumnipark.jpg").scaledToHeight(450));
			} else if (level == 3){
				levelname = "Parkside";
				bg_img->setPixmap(QPixmap("images/parkside.jpg").scaledToHeight(450));
				ecredit_rate = ecredit_rate - 10;  /** Make the levels increasingly difficult by making it harder to get points */
				food_rate = food_rate + 5;  /** Makes the levels inceasingly difficult by making more bad food items appear towards the user */
			} else if (level == 4){
				levelname = "e-Quad";
				bg_img->setPixmap(QPixmap("images/equad.jpg").scaledToHeight(450));
				ecredit_rate = ecredit_rate - 10;  /** Make the levels increasingly difficult by making it harder to get points */
				food_rate = food_rate + 5;  /** Makes the levels inceasingly difficult by making more bad food items appear towards the user */
			} else if (level == 5){
				levelname = "McCarthy Quad";
				bg_img->setPixmap(QPixmap("images/mccarthy.jpg").scaledToHeight(450));
				ecredit_rate = ecredit_rate - 10;  /** Make the levels increasingly difficult by making it harder to get points */
				food_rate = food_rate + 5;  /** Makes the levels inceasingly difficult by making more bad food items appear towards the user */
			} else if (level == 6){
				levelname = "Trousdale Parkway";
				bg_img->setPixmap(QPixmap("images/tdale_pkwy.jpg").scaledToHeight(450));
				ecredit_rate = ecredit_rate - 10; /** Make the levels increasingly difficult by making it harder to get points */
				food_rate = food_rate + 5;  /** Makes the levels inceasingly difficult by making more bad food items appear towards the user */
			} else {
			 	levelname = "Secret Impossible Level!";
			 	ecredit_rate = ecredit_rate - 10; /** Make the levels increasingly difficult by making it harder to get points */
			 	food_rate = food_rate + 5;  /** Makes the levels inceasingly difficult by making more bad food items appear towards the user */
			}
			
			/** Sets new label on the level name */
			levelnameLabel->setText(QString::fromStdString("Level: ") + QString::number(level) + QString::fromStdString(" - ") + QString::fromStdString(levelname));

	}
	
	/** Check for collisions by looping through all items and comparing them to the user/player */
	for (unsigned int i = 0; i < objects.size(); i++) {
		Thing* itemA = objects.at(i);
			Thing* itemB = character;
			if (itemA == itemB) {
				continue;
			}
			if (itemA->collidesWithItem(itemB)) {
			
				/** Switch statement to compare objects that crash into user. Gets the preset type of object through getKey() */
				switch(itemA->getKey()){
					case 1: /** Skatebaorder collision, dock 5 points and check if they have already hit a boarder 3+ times */
						cols_with_sboarders++;
						score = score - 5;
						if (score <= 0) {
							scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(0));
						} else {
							scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						}
						if (cols_with_sboarders >= 3){
							lives--;
							if (lives <= 0){
								livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(0));
							} else {
								livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
							}
							cols_with_sboarders = 0;
						}
						break;
					case 2: /** Grades collision, add between 16-20 points */
						score += rand() % (16-12) + 12;
						scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						break;
					case 3: /** Food collision, dock 5 points and take away a life if they user has hit food 4+ times already */
						cols_with_food++;
						score = score - 5;
						if (score <= 0){
							scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(0));
						} else {
							scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						}
						if (cols_with_food >= 4){	
							lives--;
							if (lives <= 0){
								livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(0));
							} else {
								livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
							}
							cols_with_food = 0;
						}
						break;
					case 4: /** Coffee collision, add a life */
						lives++;
						livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
						break;
					case 5: /** Extra credit, add 15-20 points */
						score += rand() % (20-15) + 15;
						scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						break;
				}
			
				/** Removes items that have been crashed into */
				itemA->hide();
				delete objects.at(i);
				objects.erase(objects.begin() + i);
			}
	}
	
	/** Advance timer counter */
	timerRuns++;
	
	/** Move user 10 pixels up, down, left, or right, by checking if the keypress indicator has been set */
	if (goUp == true){
		if (character->getY() > 5){
			character->setY(character->getY() - 10);
		}
	} else if (goDown == true){
		if (character->getY() <= (300)){
			character->setY(character->getY() + 10);
		}
	} else if (goLeft == true){
		if (character->getX() > 5){
			character->setX(character->getX() - 10);
		}
	} else if (goRight == true){
		if (character->getX() <= (620)){
			character->setX(character->getX() + 10);
		}
	}
	
}

/** Pauses the user's game by starting or stopping the main timer (i.e. reverse's the timer's condition) and changes the label on the game menu bar as necessary.
*/
void MainWindow::pauseGame(){

	if (paused == true){
		gameTimer->start();
		ingamepauseButton->setText("Pause Game");
		paused = false;
	} else {
		gameTimer->stop();
		ingamepauseButton->setText("Unpause Game");
		paused = true;
	}
	
}

/** Restarts the user's game by stopping the game timer, resetting game environmental variables, clearing objects from the screen, and restarting the timer once again.
*/
void MainWindow::restartGame(){

	/** Stops game timer from continuing */
	gameTimer->stop();
	
	/** Resets all game variables back to their defailts */
	score = 0;
	lives = 4;
	level = 1;
	timerRuns = 1;
	cols_with_food = 0;
	cols_with_sboarders = 0;
	goUp = false;
	goDown = false;
	goLeft = false;
	goRight = false;
	gameStarted = true;
	paused = false;
	
	/** Resets level name, score label, and lives labels to their defaults */
	levelnameLabel->setText(QString::fromStdString("Level: ") + QString::number(level) + QString::fromStdString(" - Founders Park"));
	scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
	livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
	
	/** Resets timer back to its initial state and begins it again */
	levelTimer = 50;
  gameTimer->setInterval(levelTimer);
	gameTimer->start();
	setFocusPolicy(Qt::StrongFocus);
	
	/** Clears the view of old objects before new ones get created */
	for (unsigned int i = 0; i < objects.size(); i++){
		if (objects.at(i)->getKey() != -1){
			objects.at(i)->hide();
			delete objects.at(i);
			objects.erase(objects.begin() + i);
		}
	}
	
	//objects.clear();

}

/** Key press event trigger slot for MainWindow, which starts the left, right, up, or down motion of a character when an arrow key is released. The booleans set in this function are acted upon by handletimer().
		@param e A pointer to a QKeyEvent sent automatically to this function by the Qt framework.
*/
void MainWindow::keyPressEvent(QKeyEvent *e){

	switch (e->key()) {
		case Qt::Key_Left:
			goLeft = true;
		break;
		case Qt::Key_Right:
			goRight = true;
		break;
		case Qt::Key_Up:
			goUp = true;
		break;
		case Qt::Key_Down:
			goDown = true;
		break;
	}

}

/** Key release event trigger slot for MainWindow, which stops the left, right, up, or down motion of a character when an arrow key is released. The booleans set in this function are acted upon by handletimer().
		@param e A pointer to a QKeyEvent sent automatically to this function by the Qt framework.
*/
void MainWindow::keyReleaseEvent(QKeyEvent *e){

	switch (e->key()) {
		case Qt::Key_Left:
			goLeft = false;
		break;
		case Qt::Key_Right:
			goRight = false;
		break;
		case Qt::Key_Up:
			goUp = false;
		break;
		case Qt::Key_Down:
			goDown = false;
		break;
	}

}

/** Game quit slot which saves the user's (possible) high score to an external text file */
void MainWindow::quitGame()
{

	/** Read scores.txt file first to determine if this user's score is a high score */
	ifstream scorefile("scores.txt");
	if (scorefile.good()) { /** File exists, check the high score and re-write a new one if necessary */
  	
  	/** Check if user actually achieved a high score */
  	if (score > hScore){ /** User achieved a new high score! Write it and their name to the scores.txt file */
  		ofstream ofile;
  		ofile.open("scores.txt");
  		ofile << userName << endl;
  		if (score < 0){
  			score = 0;
  		}
  		ofile << score << endl;
			ofile.close();
  	}
  	
	} else { /** File does NOT exist, create and write to a new one to save this user's score as the new high score */
		  ofstream ofile;
  		ofile.open("scores.txt");
  		ofile << userName << endl;
  		if (score < 0){
  			score = 0;
  		}
  		ofile << score << endl;
			ofile.close();
	}
	
	exit(0);
	
	
	/*
	string score;
	bool is_blank = true;
  ifstream scorefile ("scores.txt");
  if (scorefile.is_open())
  {
    while (scorefile.good()){ 
    {
      getline (scorefile,score);
      if (score != ""){
      	bool 
      }
    }
    scorefile.close();
  } else {
  	cout << "Unable to open file";
  }

	*/

}

int MainWindow::getHighScore()
{
	
	string hsName;
	string hsScore;

	/** Read scores.txt file first to determine if this user's score is a high score */
	ifstream scorefile("scores.txt");
	if (scorefile.good()) { /** File exists, check the high score and re-write a new one if necessary */
      getline(scorefile,hsName);
      getline(scorefile,hsScore);
    	scorefile.close();
  		int highscore = 0;
  		stringstream(hsScore) >> highscore;
  		return highscore;
	} else {
		return -1;
	}
	return -1;
}

string MainWindow::getHighScorer()
{
	
	string hsName;
	string hsScore;

	/** Read scores.txt file first to determine if this user's score is a high score */
	ifstream scorefile("scores.txt");
	if (scorefile.good()) { /** File exists, check the high score and re-write a new one if necessary */
      getline(scorefile,hsName);
      getline(scorefile,hsScore);
    	scorefile.close();
  		return hsName;
	} else {
		return "";
	}
	return "";
}


/** Destructor for MainWindow */
MainWindow::~MainWindow()
{
}
