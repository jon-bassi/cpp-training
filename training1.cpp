#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


class Robot
{
public:
    Robot();

    void toggleArm(void);

private:
    bool m_armState;

    bool m_HoodState;

    int m_ConveyorState;

};

Robot::Robot()
{
    m_armState = false;
    m_HoodState = false;
    m_ConveyorState = false;
}

void Robot::toggleArm(void)
{
    m_armState = !m_armState;
    
    if (m_armState)
    {
        printf("arm is down\n");
    }
    else
    {
        printf("arm is up\n");
    }
}


int main()
{
    Robot robot = Robot();

    robot.toggleArm();

#ifdef _WIN32
    Sleep(250);
#else
    sleep(2);
#endif

    robot.toggleArm();

    return 0;
}