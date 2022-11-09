#include <ncurses.h>
#include <unistd.h>  /* only for sleep() */



class OperatorController
{
public:
    OperatorController(void);
    void handle(void);
};

OperatorController::OperatorController()
{
    return;
}

void OperatorController::handle()
{
    char key = getch();
    
    printf("pressed: %c\n",key);
    
    if (key == 'w')
    {
        // TODO: move robot forward
    }
    if (key == 's')
    {
        // TODO: move robot backward
    }
    
    
    /** TODO: write code to turn left and right with 'a' and 'd' key **/
    
    
    
    
}


class Robot
{
public:
    Robot();
    double getDistance(void);
    double getAngle(void);
    void setDistance(double dist);
    void setAngle(double ang);
private:
    double m_Distance;
    double m_Angle;
};

Robot::Robot()
{
    m_Distance = 0.0;
    m_Angle = 0.0;
}

double Robot::getDistance()
{
    return m_Distance;
}

/** TODO: add remaining robot functions **/





int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    Robot* robot = new Robot();
    OperatorController* op = new OperatorController(); 
    
    // DO NOT TOUCH CODE BELOW
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
    while (1) {
        if (kbhit()) {
            op->handle();
            printf("distance traveled: %f\n",robot->getDistance());
            refresh();
        } else {
            refresh();
        }
        // sleep for 10ms
        sleep(0.01);
    }
}