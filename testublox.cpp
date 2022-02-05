#include <iostream>
#include "unistd.h"
#include "fcntl.h"

using namespace std;
int main(void)
{
    int fd;

    fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
    if (fd == -1) /* Error Checking */
    {
        printf("\n  Error! in Opening ttyACM0\n\n");
        close(fd); /* Close the serial port */
        return 0;
    }
    else
    {
        cout << "Sucess" << endl;
    }

    char receive_buffer[256] = {0};
    char recv_bf;

    int receive_count = 0;

    while (fd)
    {
        read(fd, &recv_bf, 1);

        if (recv_bf == '\n')
        {
            for (int i = 0; i < receive_count; i++)
            {
                cout << receive_buffer[i];
            }
            cout << endl;
            receive_count = 0;
        }
        else
        {
            receive_buffer[receive_count] = recv_bf;
            receive_count++;
            continue;
        }
    }
    return 0;
}