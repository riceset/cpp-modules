#include <cstdlib>
#include <iostream>
#include <cctype>

#define DEFAULT_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << DEFAULT_MESSAGE << std::endl;
		return (EXIT_FAILURE);
	}

	for (int i = 1; i < argc; ++i) {
		for (int j = 0; argv[i][j] != '\0'; ++j) {
			argv[i][j] = std::toupper(static_cast<unsigned char>(argv[i][j]));
		}
		std::cout << argv[i];
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
