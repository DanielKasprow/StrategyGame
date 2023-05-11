//
// Created by Daniel kasprow on 10.05.23.
//
#include <iostream>
#include <vector>

bool formatChecking(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

std::vector<std::string> argToVector(int argc, char **argv) {
    std::vector<std::string> files;
    for (int i = 1; i < argc; i++)
        files.emplace_back(argv[i]);

    if (argc < 4) {
        cout << "Za malo argumentow";
        exit(0);
    }

    //checking file format, if end with .txt
    for (int i = 0; i < 3; i++) {
        if (!formatChecking(files[i], ".txt")) {
            cout << "Zly format plikow";
            exit(0);
        }

    }
    return files;
}

int getTimePerRound(const basic_string<char> &time) {
    int timePerSecond = 5;
    if (!time.empty()) {
        char *p;
        strtol(time.c_str(), &p, 10);
        if (*p) {
            cout << "Blednie podany czas";
            exit(0);
        } else {
            timePerSecond = stoi(time);
        }
    }
    return timePerSecond;
}