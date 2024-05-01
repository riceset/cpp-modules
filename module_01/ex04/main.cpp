#include <fstream>
#include <iostream>
#include <stdexcept>

typedef enum errors {
	USAGE_ERROR = 1,
	FILE_ERROR
} errors;

void handleArgs(int argc, char **argv) {
	if (argc != 4 || strcmp(argv[1], "") == 0 || strcmp(argv[2], "") == 0 ||
	strcmp(argv[3], "") == 0) {
		std::cout << "usage: ./sedisforlosers <filename> s1 s2" << std::endl;
		exit(USAGE_ERROR);
	}
}

void openFile(const std::string& filename, std::ifstream &file) {
	try {
		file.open(filename);
		if (!file.is_open()) {
			throw std::runtime_error("file couldn't be opened!");
		}
	}
	catch (const std::runtime_error& error) {
		std::cerr << "error: " << error.what() << std::endl;
		exit(FILE_ERROR);
	}
}

bool foundSubstring(const std::string& toSearch, const std::string &line) {
	size_t pos;

	pos = line.find(toSearch);
	
	if (pos == std::string::npos)
		return (false);
	return (true);
}

void replaceAndPrint(const std::string& line, const std::string& toSearch, const std::string& replaceWith, std::ofstream& outfile) {
    size_t pos = 0;
    std::string result;
    size_t lastPos = 0;

    while ((pos = line.find(toSearch, lastPos)) != std::string::npos) {
        result += line.substr(lastPos, pos - lastPos) + replaceWith;
        lastPos = pos + toSearch.length();
    }
    result += line.substr(lastPos);

    outfile << result << std::endl;
}

int main(int argc, char **argv) {
	handleArgs(argc, argv);

	std::string infileName = argv[1];
	std::ifstream infile;

	openFile(infileName, infile);

	std::string outfileName = infileName + ".replace";
	std::ofstream outfile(outfileName, std::ofstream::out);

	std::string line;

	while (getline(infile, line)) {
		if (foundSubstring(argv[2], line)) {
			replaceAndPrint(line, argv[2], argv[3], outfile);
		} else {
			outfile << line << std::endl;
		}
	}

	infile.close();
	outfile.close();

	return (0);
}
