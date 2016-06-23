#include "General/General.h"
#include "ServerCommunication/LogIn.h"
#include "Kagan/Home.h"
int main(int argc, char ** argv)
{
    InitEverythingGeneral();

    LogIn logIn;
    if(logIn.Status() == LOG_IN_SUCCESS)
    {
        delete(&logIn);
        Home HomePage;
    }
    return 0;
}
