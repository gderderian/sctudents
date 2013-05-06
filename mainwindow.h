#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QRadioButton>
#include <QListView>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cstdlib>
#include <deque>
#include <cmath>
#include <vector>
#include <QFormLayout>
#include <QStringList>
#include <QStringListModel>
#include <string>
#include "thing.h"
#include "player.h"
#include "skateboarder.h"
#include "coffee.h"
#include "grades.h"
#include "food.h"
#include "extracredit.h"

#define WINDOW_MAX_X 750
#define WINDOW_MAX_Y 550

using namespace std;

/** Represents the MainWindow responsible for controlling all aspects of gameplay and the main player GUI menu. */
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void show();
    int getHighScore();
    string getHighScorer();
private:
		/** main program window */
		QWidget *window;
		/** main menu scene */
    QGraphicsScene *menuScene;
    /** main menu view */
    QGraphicsView *menuView;
    /** gameplay scene */
    QGraphicsScene *gameScene;
    /** gameplay view */
    QGraphicsView *gameView;
    /** gameplay layout */
    QVBoxLayout *gameStackables;
    /** main menu layout */
    QVBoxLayout *mainStackables;
    /** icon layout for main menu help screen */
    QHBoxLayout *iconStackables;
    /** layout for gameplay display of lives, level, name, and score */
    QHBoxLayout *gameBar;
    /** gameplay lower menu bar with appropraite buttons */
    QHBoxLayout *menuBar;
    /** Skatebaorder graphics layout in main menu */
    QVBoxLayout *skateboarderLayout;
    /** Coffee/TroGro graphics layout in main menu */
    QVBoxLayout *trogroLayout;
    /** Good Grades graphics layout in main menu */
    QVBoxLayout *gradesLayout;
    /** Food graphics layout in main menu */
    QVBoxLayout *foodLayout;
    /** Extra Credit graphics layout in main menu */
    QVBoxLayout *ecreditLayout;
    /** Name entry layout in main menu */
    QFormLayout *nameLayout;
    /** Main menu game title label */
    QLabel *gametitleLabel;
    /** Main menu welcome text label */
    QLabel *instructionsLabel;
    /** Main menu instructions layout */
    QLabel *directionsLabel;
    /** Main menu skateboarder image label */
    QLabel *skateboarder;
    /** Main menu skateboarder title label */
    QLabel *skateboardernameLabel;
    /** Main menu skateboarder description label */
    QLabel *skateboarderinfoLabel;
    /** Main menu coffee image label */
    QLabel *trogro;
    /** Main menu coffee title label */
    QLabel *trogronameLabel;
    /** Main menu coffee description label */
    QLabel *trogroinfoLabel;
    /** Main menu grades image label */
    QLabel *grades;
    /** Main menu grades title label */
    QLabel *gradesnameLabel;
    /** Main menu grades description label */
    QLabel *gradesinfoLabel;
    /** Main menu food image label */
    QLabel *food;
    /** Main menu food title label */
    QLabel *foodnameLabel;
    /** Main menu food description label */
    QLabel *foodinfoLabel;
    /** Main menu extra credit image label */
    QLabel *ecredit;
    /** Main menu extra credit title label */
    QLabel *ecreditnameLabel;
    /** Main menu extra credit description label */
    QLabel *ecreditinfoLabel;
    /** Main menu name entry instructions label */
    QLabel *nameInstructions;
    /** Main menu username entry text box */
    QLineEdit *nameBox;
    /** Main menu start game button */
    QPushButton *startgameButton;
    /** In-game start/restart button */
    QPushButton *ingamestartButton;
    /** In-game pause/unpause button */
    QPushButton *ingamepauseButton;
    /** In-game quit button */
    QPushButton *ingamequitButton;
    /** String to store the user's entered name */
		string userName;
		/** In-game label for the user's name */
		QLabel *usernameLabel;
		/** In-game label for the current level name */
		QLabel *levelnameLabel;
		/** In-game label for the user's score */
		QLabel *scoreLabel;
		/** Main menu high score display */
		QLabel *hscoreLabel;
		/** In-game label for the user's lives */
		QLabel *livesLabel;
		/** Main game timer */
		QTimer *gameTimer;
		/** User's current score */
		int score;
		/** User's remaining lives */
		int lives;
		/** User's current numeric level number */
		int level;
		/** Interval value for the current level */
		int levelTimer;
		/** Counter for the number of timer iterations that have gone by */
		int timerRuns;
		/** Number of user collisions with skateboarders */
		int cols_with_sboarders;
		/** Number of user collisions with food */
		int cols_with_food;
		/** Previous high score as read in from file, if applicable */
		int hScore;
		/** Timer iterations at which the extra credit items appear throughout the game (decreases) */
		int ecredit_rate;
		/** Timer iterations at which the food items appear throughout the game (increases) */
		int food_rate;
		/** Boolean for if the user should be moved up at the next handletimer() call */
		bool goUp;
		/** Boolean for if the user should be moved down at the next handletimer() call */
		bool goDown;
		/** Boolean for if the user should be moved left at the next handletimer() call */
		bool goLeft;
		/** Boolean for if the user should be moved right at the next handletimer() call */
		bool goRight;
		/** Boolean for if a game has begun */
		bool gameStarted;
		/** Boolean for if the game is currently paused */
		bool paused;
		/** String name for the name of the current level */
		string levelname;
		/** Pixmap represeting the main backgroundimage of the game */
		QGraphicsPixmapItem *bg_img;
		/** Instance of Player that the user controls */
		Player *character;
		/** Instance of a good grade object */
		Grades *grade;
		/** Instance of a skateboarder object */
		Skateboarder *boarder;
		/** Instance of a coffee object */
		Coffee *starbucks;
		/** Instance of a food object */
		Food *eat;
		/** Instance of an extra credit object */
		ExtraCredit *ec;
		/** Vector of Thing* to store and keep track of things currently on the screen */
		vector<Thing*> objects;
public:

protected:
		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
public slots:
		void startGame();
		void pauseGame();
		void handleTimer();
		void restartGame();
		void quitGame();
};

#endif // MAINWINDOW_H
