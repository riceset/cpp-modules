/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:51:45 by tkomeno           #+#    #+#             */
/*   Updated: 2024/03/07 20:51:50 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
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
