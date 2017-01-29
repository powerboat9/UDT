#if defined (__unix__)
#if _POSIX_VERSION >= 200112L
#include <sys/select.h>
#else
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#endif
#include <stdio.h>

int con = -1;

FILE *getTempFile() {
    return tmpfile();
}

void wait(long miliseconds) {
    tv.secs = (int) (miliseconds / 1000);
    tv.usecs = (int) (miliseconds % 1000);
    select(0, NULL, NULL, NULL, &tv);
}

int initPlay()
    if (con != -1) {
        close(con);
    }
    if ((con = open("dev/console", O_WRONLY)) == -1) {
        printf("Failed to init sound (Linux)");
        return -1;
    }
    return 0;
}

int playTone(double freq, double duration) {
    if ((con == -1) && (initPlay() == -1)) {
        return -1;
    }
    if (ioctl(con, KIOCSOUND, round(1193180/freq)) < 0) {
        printf("Failed to start sound (Linux)");
        return -1;
    }
    wait(duration);
    ioctl(con, KIOCSOUND, 0);
}

void closePlay() {
    close(con);
}
#elif defined (__APPLE__)

#elif defined (_WIN32)
#include <iostream>
#include <windows.h>

void initPlay() {
}

void playTone(double freq, double duration) {
    Beep((DWORD) freq, (DWORD) duration);
}

void closePlay() {
}
#else
#include <stdio.h>

printf("OS not supported");
exit(-1);
#endif
