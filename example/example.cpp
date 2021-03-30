#include <iostream>
#include <string>
#include <sstream>

#include <langdetectpp/langdetectpp.h>

int main ()
{
    auto detector = langdetectpp::Detector::create();

    std::string line;
    while(std::getline(std::cin, line)) {
        if (line.empty() || line == "quit" || line == "q")
            break;

        auto lang = detector->detect(line);
        std::cout << line << "  ->  "
                  << langdetectpp::stringOfLanguage(lang) << std::endl;
    }
    return 0;
}
