#include "output.h"

/**
 * @brief typeWriter - Takes in some text and outputs them in a typewriter style
 * 
 * @param text      Text to display
 * @param delay_ms  The delay inbetween each character and the next
 */
void typeWriter(string text, int delay_ms=0) {
    for (char c : text) {
        cout << c << flush;
        sleep_ms(delay_ms);
    }
}

/**
 * @brief eraseText - Takes in the length of the text to erase and removes it
 * 
 * @param length    Length of the text
 * @param delay_ms  The delay at which characters disappear
 */
void eraseText(int length, int delay_ms) {
    cout << "\r";

    for (size_t i = 0; i < length; ++i) {
        cout << " ";
        sleep_ms(delay_ms);
    }

    cout << "\r" << flush;
}

/**
 * @brief clearCLI - Uses the system command to clear the terminal
 */
void clearCLI() { system("cls"); }

/**
 * @brief pauseCLI - Uses the system command to pause the terminal
 */
void pauseCLI() { system("pause"); }

/**
 * @brief hideCursor - Hides the cursors using ANSI
 */
void hideCursor() { cout << "\033[?251" << flush; }

/**
 * @brief showCursor - Shows the cursors using ANSI
 */
void showCursor() { cout << "\033[?25h" << flush; }

/**
 * @brief typeAndErase - This function combines the duality of typeWriter and eraseText
 * 
 * @param text           The text to display then later erae
 * @param type_delay     The typing speed, ideally 30-60 ms
 * @param hold_delay     The time to leave the text before erasing
 * @param erase_delay    The erasing speed, ideally 20-40 ms
 */
void typeAndErase(string text, int type_delay, int hold_delay, int erase_delay) {
    typeWriter(text, type_delay);
    sleep_ms(hold_delay);
    eraseText(text.length(), erase_delay);
}

/**
 * @brief progressBar - Displays a progress bar
 * 
 * @param delay_ms  The time at which the bar is filled
 */
void progressBar(int delay_ms=30) {
    const int barWidth = 40;

    hideCursor();

    for (int percent = 0; percent <= 100; ++percent) {
        int filled = barWidth * percent / 100;

        std::cout << "\rLoading [";

        for (int i = 0; i < barWidth; ++i) {
            if (i < filled)
                std::cout << "#";
            else
                std::cout << " ";
        }

        std::cout << "] " << percent << "%" << std::flush;

        sleep_ms(delay_ms);
    }

    std::cout << "\rDone!                                                      " << std::endl;

    showCursor();
}

/**
 * @brief printLogo - Displays the program logo "Bebo CLI Tools" in red
 */
void printLogo() {
    SetConsoleOutputCP(CP_UTF8);

    cout << "\e[0;31m";
    typeWriter("======================================================================================================== \n");
    sleep_ms(1);
    typeWriter("██████╗ ███████╗██████╗  ██████╗      ██████╗██╗     ██╗     ████████╗ ██████╗  ██████╗ ██╗     ███████╗ \n");
    sleep_ms(1);
    typeWriter("██╔══██╗██╔════╝██╔══██╗██╔═══██╗    ██╔════╝██║     ██║     ╚══██╔══╝██╔═══██╗██╔═══██╗██║     ██╔════╝ \n");
    sleep_ms(1);
    typeWriter("██████╔╝█████╗  ██████╔╝██║   ██║    ██║     ██║     ██║        ██║   ██║   ██║██║   ██║██║     ███████╗ \n");
    sleep_ms(1);
    typeWriter("██╔══██╗██╔══╝  ██╔══██╗██║   ██║    ██║     ██║     ██║        ██║   ██║   ██║██║   ██║██║     ╚════██║ \n");
    sleep_ms(1);
    typeWriter("██████╔╝███████╗██████╔╝╚██████╔╝    ╚██████╗███████╗██║        ██║   ╚██████╔╝╚██████╔╝███████╗███████║ \n");
    sleep_ms(1);
    typeWriter("╚═════╝ ╚══════╝╚═════╝  ╚═════╝      ╚═════╝╚══════╝╚═╝        ╚═╝    ╚═════╝  ╚═════╝ ╚══════╝╚══════╝ \n");
    sleep_ms(1);
    typeWriter("======================================================================================================== \n\n");
    cout << "\033[0m";
}