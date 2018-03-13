#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "Usage: autocomple_gen [source_file] [new_file_name]" << std::endl;
        return EXIT_FAILURE;
    }

    std::fstream file_read(argv[1]);
    if (!file_read.is_open()) {
        std::cerr << "Error: File " << argv[1] << " does not exist" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line, tag;
    std::vector<std::string> content;
    while (getline(file_read, line, '\n')) {
        if ((line.find("tag") != std::string::npos) && (line.find("=")) != std::string::npos) {
            tag = line.substr(line.find("\""), line.rfind("\"") - line.find("\""));
        } else if ((line.find("class") != std::string::npos) && (line.find("{") != std::string::npos)) {
            content.size() == 0 ? content.push_back("{\"scope\": \"source.sqf\", \"completions\": [") : content.push_back(",");
            content.push_back(tag + 
                "_fnc_" + 
                line.substr(line.find("class ") + std::strlen("class "), line.rfind("{") - line.find("class ") - 1 - std::strlen("class ")) +
                "\""
            );
        }
    }
    file_read.close();
    content.push_back("]}");

    const std::string n_file(argv[2]);
    std::ofstream file_write("./outputs/" + n_file + ".sublime-completions");
    for (std::string n : content) {
        file_write << n;
    }
    file_write.close();

    std::cout << "Done" << std::endl;
    return EXIT_SUCCESS;
}
