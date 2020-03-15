#include <iostream>

using namespace std;

void handleHelp(); // -h
void handleIR(); // -r
void handleParsing(); // -p
void handleScanning(); // -s

int main(int argc, char* argv[]) {
    /// Handle command line arguments
    char priorityFlag = 's';
    ++argv; // Skip name of executable

    if (argc == 1) { // No flag specified
        priorityFlag = 'p'; // Default to parsing
    } else {
        while (*argv) {
            char *curr_flag = *argv;

            while (*curr_flag && priorityFlag != 'h') {
                if (*curr_flag == '-') {} // Skip over expected -
                else if (*curr_flag == 'h' || *curr_flag == 'r')
                    priorityFlag = *curr_flag;
                else if (*curr_flag == 'p' && priorityFlag != 'r')
                    priorityFlag = *curr_flag;
                else // Handle unexpected character by displaying expected usage with help command
                    priorityFlag = 'h';

                curr_flag++;
            }

            argv++;
        }
    }
    cout << "FLAG: " << priorityFlag << endl;

    switch (priorityFlag) {
        case 'h': // Handle help
            handleHelp();
            break;
        case 'r': // Handle IR display
            handleIR();
            break;
        case 'p': // Handle parsing
            handleParsing();
            break;
        case 's': // Handle scanning of tokens
            handleScanning();
            break;
        default:
            cerr << "Improper input!!!" << endl;
            handleHelp();
            break;
    }
}

void handleHelp() {
    cout << "OVERVIEW: ILOC compiler" << endl << endl;
    cout << "USAGE: ilc [options] file..." << endl << endl;
    cout << "OPTIONS:" << endl;
    cout << "\t-h           \t\tProduces list of valid command-line arguments." << endl;
    cout << "\t-s <filename>\t\tPrints a list of tokens encountered by the scanner to stdout" << endl;
    cout << "\t-p <filename>\t\tReports whether or not the input file could be successfully parsed and its IR built." << endl;
    cout << "\t-r <filename>\t\tPrints the intermediate representation of the input program to stdout" << endl;
    cout << "\t <filename>  \t\tWithout a flag specified, the compiler will default to parsing." << endl;
}

void handleIR() {

}

void handleParsing() {

}

void handleScanning() {

}