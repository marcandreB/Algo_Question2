#pragma once
#include "stdafx.h"
#include "jeu.h"
#include <math.h>
#include "tableau.h"
#include <algorithm>
#include <iostream>

std::vector<Monstre> programmationDynamique(const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue) {
	unsigned int dimensions[2] = { monstres.size(), magie_rouge };
	Tableau<int> t(std::vector<unsigned int>(dimensions, dimensions + 2));

	for (int i = 0; i < monstres.size(); i++) {
		t.at(i, 0) = 0;
	}
	for (int i = 0; i < magie_rouge; i++) {
		t.at(0, i) = 0;
	}
	for (int i = 1; i < monstres.size(); i++) {
		for (int j = 1; j < magie_rouge; j++) {
			if (j - monstres.at(i).magieRouge() >= 0) {
				t.at(i, j) = std::max((unsigned) t.at(i - 1, j), monstres.at(i).degat() + t.at(i - 1, j - monstres.at(i).magieRouge()));
			}
			else {
				t.at(i, j) = t.at(i - 1, j);
			}
		}
	}
	for (int i = 0; i < monstres.size(); i++) {
		for (int j = 0; j < magie_rouge; j++) {
			std::cout << t.at(i, j);
		}
		std::cout << "\n";
	}
	return std::vector<Monstre>();
}
