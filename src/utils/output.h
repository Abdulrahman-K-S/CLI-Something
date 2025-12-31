// Includes
#include <iostream>
#include <string>
#include <windows.h>

// namespaces
using namespace std;

// For cross-platform usage
#ifdef _WIN32
    #include <windows.h>
    void sleep_ms(int ms) { Sleep(ms); }
#else
    #include <unistd.h>
    void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

// =========================================
// =               Functions               =
// =========================================

void typeWriter(string, int);
void lineWriter(string, int);
void eraseText(int, int);
void clearCLI();
void pauseCLI();
void typeAndErase(string, int, int, int);

void hideCursor();
void showCursor();

void progressBar(int);
void printLogo();
