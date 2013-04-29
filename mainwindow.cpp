#include "mainwindow.h"
#include <iostream>
#include <string>
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

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent){

		window = new QWidget();
		
   	gameScene = new QGraphicsScene();
   	gameView = new QGraphicsView(gameScene);
   	//gameView->setFixedSize(650,550);
   	mainStackables = new QVBoxLayout();
   	iconStackables = new QHBoxLayout();
   	
   	skateboarderLayout = new QVBoxLayout();
   	trogroLayout = new QVBoxLayout();
   	gradesLayout = new QVBoxLayout();
   	foodLayout = new QVBoxLayout();
   	ecreditLayout = new QVBoxLayout();
   	
   	window->setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y);
   	window->setWindowTitle("Grant Derderian PA5 - SCtudents Qt Game");
		
		QFont titlefont("Arial", 60, QFont::Bold);
		QFont instructionsFont("Arial", 11, QFont::Normal);
		QFont itemnameFont("Arial", 14, QFont::Bold);
		QFont itemdescFont("Arial", 12, QFont::Normal);
		QFont gamebarFont("Arial", 12, QFont::Bold);
		
		gametitleLabel = new QLabel();
		gametitleLabel->setText("SCtudents");
		gametitleLabel->setFont(titlefont);
		gametitleLabel->setAlignment(Qt::AlignHCenter);
		mainStackables->addWidget(gametitleLabel);

		instructionsLabel = new QLabel();
		instructionsLabel->setText("Welcome! Take a look at the items below and how they affect your character before beginning.");
		instructionsLabel->setFont(instructionsFont);
		instructionsLabel->setAlignment(Qt::AlignHCenter);
		mainStackables->addWidget(instructionsLabel);

		directionsLabel = new QLabel();
		directionsLabel->setText("You have three lives. Use the space bar to jump, the arrow keys to side to side, and P to pause.");
		directionsLabel->setFont(instructionsFont);
		directionsLabel->setAlignment(Qt::AlignHCenter);
		mainStackables->addWidget(directionsLabel);
		
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

		nameInstructions = new QLabel();
		nameInstructions->setText("Enter Your Name and Press Start Below to Begin!");
		nameInstructions->setFont(instructionsFont);
		nameInstructions->setAlignment(Qt::AlignHCenter);

		nameBox = new QLineEdit();
		nameLayout = new QFormLayout();
		nameLayout->addRow("Your &Name:",nameBox);
		
		startgameButton = new QPushButton("Start Game");
		connect(startgameButton, SIGNAL(clicked()), this, SLOT(startGame()));		

		mainStackables->addLayout(iconStackables);
		mainStackables->addWidget(nameInstructions);
		mainStackables->addLayout(nameLayout);
		mainStackables->addWidget(startgameButton);
		window->setLayout(mainStackables);
		
		gameStackables = new QVBoxLayout();
		gameBar = new QHBoxLayout();
		menuBar = new QHBoxLayout();
		
		usernameLabel = new QLabel();
		usernameLabel->setText("User:");
		usernameLabel->setFont(gamebarFont);
		usernameLabel->setAlignment(Qt::AlignLeft);
		gameBar->addWidget(usernameLabel);
		
		levelnameLabel = new QLabel();
		levelnameLabel->setText("Level:");
		levelnameLabel->setFont(gamebarFont);
		levelnameLabel->setAlignment(Qt::AlignHCenter);
		gameBar->addWidget(levelnameLabel);
		
		scoreLabel = new QLabel();
		scoreLabel->setText("Score:");
		scoreLabel->setFont(gamebarFont);
		scoreLabel->setAlignment(Qt::AlignRight);
		gameBar->addWidget(scoreLabel);
		
		livesLabel = new QLabel();
		livesLabel->setText("Lives:");
		livesLabel->setFont(gamebarFont);
		livesLabel->setAlignment(Qt::AlignRight);
		gameBar->addWidget(livesLabel);
		
		ingamestartButton = new QPushButton("Start Game");
		connect(ingamestartButton, SIGNAL(clicked()), this, SLOT(restartGame()));	
		menuBar->addWidget(ingamestartButton);

		ingamepauseButton = new QPushButton("Pause Game");
		connect(ingamepauseButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
		menuBar->addWidget(ingamepauseButton);
		
		ingamequitButton = new QPushButton("Quit Game");
		connect(ingamequitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
		menuBar->addWidget(ingamequitButton);
		
		gameStackables->addLayout(gameBar);
		gameStackables->addWidget(gameView);
		gameStackables->addLayout(menuBar);

		gameTimer = new QTimer();
		levelTimer = 50;
    gameTimer->setInterval(levelTimer);
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(handleTimer()));

		setFocusPolicy(Qt::StrongFocus);
		
		srand(time(NULL));
		gameStarted = false;

}

void MainWindow::startGame()
{
	
	// Check for username setting
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
	
	setFocusPolicy(Qt::StrongFocus);
	grabKeyboard();
	
	// Set initial game variables
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
	
	// Set variables to the screen
	userName = (nameBox->text()).toUtf8().constData();
	string uname = "User: " + userName;
	usernameLabel->setText(QString::fromStdString(uname));
	
	levelnameLabel->setText(QString::fromStdString("Level: ") + QString::number(level) + QString::fromStdString(" - Founders Park"));
	scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
	livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
	
	// Change views/windows
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
 // delete ecredit;
 // delete ecreditnameLabel;
 // delete ecreditinfoLabel;
  delete nameInstructions;
  delete nameBox;
  delete startgameButton;
	window->setLayout(gameStackables);
	
	// Begin game timer
	gameTimer->start();
	setFocusPolicy(Qt::StrongFocus);
	
	bg_img = new QGraphicsPixmapItem(QPixmap("images/tdale_pkwy.jpg").scaledToHeight(450));
	bg_img->setPos(0,0);
	gameScene->addItem(bg_img);
	
	QPixmap player_img("images/sctudent.png");
	character = new Player(&player_img, 225, 225);
	gameScene->addItem(character);
	objects.push_back(character);
	
}

void MainWindow::show()
{
    window->show();
}

void MainWindow::handleTimer()
{

	// Check if player has lost the game
	if ((gameStarted == true && lives <= 0) || (gameStarted == true && score < 0)){
		gameTimer->stop();
	}
	
	// Add in new game objects by creating images
	QPixmap trogro_img("images/coffee.png");
	QPixmap grades_img("images/grades.png");
	QPixmap food_img("images/food.png");
	QPixmap sboarder_img("images/skateboarder.png");
	QPixmap ecredit_img("images/ecredit.png");
	
	int rand_x = rand() % 600;
	int rand_y = rand() % 325;
	
	if (timerRuns % 50 == 0){
		grade = new Grades(&grades_img, 0, rand_y);
		gameScene->addItem(grade);
		objects.push_back(grade);
	}
	
	if (timerRuns % 100 == 0){
		boarder = new Skateboarder(&sboarder_img, 550, rand_y);
		gameScene->addItem(boarder);
		objects.push_back(boarder);
	}
	
	if (timerRuns % 100 == 0){
		eat = new Food(&food_img, rand_x, 350);
		gameScene->addItem(eat);
		objects.push_back(eat);
	}
	
	if (timerRuns % 750 == 0){
		starbucks = new Coffee(&trogro_img, 550, rand_y);
		gameScene->addItem(starbucks);
		objects.push_back(starbucks);
	}
	
	if (timerRuns % 450 == 0){
		ec = new ExtraCredit(&ecredit_img, 550, rand_y);
		gameScene->addItem(ec);
		objects.push_back(ec);
	}
	
	for (unsigned int i=0; i < objects.size(); i++) {
		if (timerRuns % 1 == 0){
			objects.at(i)->move();
		}
	}
	
	if (timerRuns % 500 == 0){
			
			level++;
			levelTimer =  levelTimer - 10;
			gameTimer->setInterval(levelTimer);
			
			if (level == 1){
				levelname = "Founders Park";
			} else if (level == 2){
				levelname = "Alumni Park";
			} else if (level == 3){
				levelname = "Parkside";
			} else if (level == 4){
				levelname = "e-Quad";
			} else if (level == 5){
				levelname = "McCarthy Quad";
			} else if (level == 6){
				levelname = "Trousdale Parkway";
			} else {
			 	levelname = "Secret Impossible Level!";
			}
						
			levelnameLabel->setText(QString::fromStdString("Level: ") + QString::number(level) + QString::fromStdString(" - ") + QString::fromStdString(levelname));

	}
	
	for (unsigned int i = 0; i < objects.size(); i++) {
		Thing* itemA = objects.at(i);
			Thing* itemB = character;
			if (itemA == itemB) {
				continue;
			}
			if (itemA->collidesWithItem(itemB)) {
			
				switch(itemA->getKey()){
					case 1: // Collided with skateboarder
						cols_with_sboarders++;
						score = score - 5;
						scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						if (cols_with_sboarders >= 3){
							lives--;
							livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
							cols_with_sboarders = 0;
						}
						break;
					case 2: // Collided with grades
						score += rand() % (16-12) + 12;
						scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						break;
					case 3: // Collided with food
						cols_with_food++;
						score = score - 5;
						scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						if (cols_with_food >= 4){	
							lives--;
							livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
							cols_with_food = 0;
						}
						break;
					case 4: // Collided with coffee
						lives++;
						livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
						break;
					case 5: // Collided with extra credit
						score += rand() % (20-15) + 15;
						scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
						break;
				}
			
				itemA->hide();
				objects.erase(objects.begin() + i);
			}
	}
	
	timerRuns++;
	
	if (goUp == true){
		if (character->getY() > 0){
			character->setY(character->getY() - 10);
		}
	} else if (goDown == true){
		if (character->getY() <= (450 - 145)){
			character->setY(character->getY() + 10);
		}
	} else if (goLeft == true){
		if (character->getX() > 0){
			character->setX(character->getX() - 10);
		}
	} else if (goRight == true){
		if (character->getX() <= (625)){
			character->setX(character->getX() + 10);
		}
	}
	
}

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

void MainWindow::restartGame(){

	gameTimer->stop();
	
	// Set initial game variables
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
	
	// Set variables to the screen
	levelnameLabel->setText(QString::fromStdString("Level: ") + QString::number(level) + QString::fromStdString(" - Founders Park"));
	scoreLabel->setText(QString::fromStdString("Score: ") + QString::number(score));
	livesLabel->setText(QString::fromStdString("Lives: ") + QString::number(lives));
	
	// Begin game timer
	levelTimer = 50;
  gameTimer->setInterval(levelTimer);
	gameTimer->start();
	setFocusPolicy(Qt::StrongFocus);
	
	for (unsigned int i = 0; i < objects.size(); i++){
		if (objects.at(i)->getKey() != -1){
			objects.at(i)->hide();
			objects.erase(objects.begin() + i);
		}
	}
	

}

MainWindow::~MainWindow()
{
    
}
