#include "mainwindow.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <QPushButton>
#include <QLabel>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QString>
#include <QStringList>
#include <QStringListModel>
#include <QPixmap>
#include <time.h>
#include "thing.h"
#include "graphicwindow.h"
#include "player.h"
#include "skateboarder.h"
#include "coffee.h"
#include "grades.h"
#include "food.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent){

		window = new QWidget();
		
   	gameScene = new QGraphicsScene();
   	gameView = new QGraphicsView(gameScene);
   	mainStackables = new QVBoxLayout();
   	iconStackables = new QHBoxLayout();
   	
   	skateboarderLayout = new QVBoxLayout();
   	trogroLayout = new QVBoxLayout();
   	gradesLayout = new QVBoxLayout();
   	foodLayout = new QVBoxLayout();
   	
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
		connect(ingamestartButton, SIGNAL(clicked()), this, SLOT(startGame()));	
		menuBar->addWidget(ingamestartButton);

		ingamepauseButton = new QPushButton("Pause Game");
		connect(ingamepauseButton, SIGNAL(clicked()), this, SLOT(startGame()));
		menuBar->addWidget(ingamepauseButton);
		
		ingamequitButton = new QPushButton("Quit Game");
		connect(ingamequitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
		menuBar->addWidget(ingamequitButton);
		
		gameStackables->addLayout(gameBar);
		gameStackables->addWidget(gameView);
		gameStackables->addLayout(menuBar);

		gameTimer = new QTimer();
    gameTimer->setInterval(5);
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(handleTimer()));

		setFocusPolicy(Qt::StrongFocus);
		//grabKeyboard();
		//setFocus();
		
		srand(time(NULL));

}

void MainWindow::startGame()
{
	
	setFocusPolicy(Qt::StrongFocus);
	//setFocus();
	
	// Set initial game variables
	score = 0;
	lives = 4;
	level = 1;
	timerRuns = 0;
	
	// Set variables to the screen
	userName = (nameBox->text()).toUtf8().constData();
	string uname = "User: " + userName;
	usernameLabel->setText(QString::fromStdString(uname));
	
	levelnameLabel->setText(QString::fromStdString("Level: ") + QString::number(level));
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
  delete nameInstructions;
  delete nameBox;
  delete startgameButton;
	window->setLayout(gameStackables);
	
	// Begin game timer
	gameTimer->start();
	
	setFocusPolicy(Qt::StrongFocus);
	//setFocus();
	
	if (this->hasFocus())
	{
		cout << "I HAVE FOCUS!" << endl;
	} else {
		cout << "Hello world!" << endl;
	}
	
}

void MainWindow::show()
{
    window->show();
}

void MainWindow::handleTimer()
{
	
	// Add in new game objects by creating images
	QPixmap player_img("images/coffee.png");
	QPixmap trogro_img("images/coffee.png");
	QPixmap grades_img("images/grades.png");
	QPixmap food_img("images/food.png");
	QPixmap sboarder_img("images/skateboarder.png");
	
	
	
	int rand_x = rand() % 651;
	int rand_y = rand() % 451;
	
	grade = new Grades(&grades_img, 25, 25);
	gameScene->addItem(grade);
	objects.push_back(grade);
	
	timerRuns++;
	
}

void MainWindow::keyPressEvent(QKeyEvent *e){

	cout << "keypressevent triggered" << endl;

	switch (e->key()) {
		case Qt::Key_Left:
			cout << "moving left" << endl;
		case Qt::Key_Right:
			cout << "moving right" << endl;
		default:
			QWidget::keyPressEvent(e);
	}


}

MainWindow::~MainWindow()
{
    
}
