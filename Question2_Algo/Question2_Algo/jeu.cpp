#pragma once
#include "stdafx.h"
#include "jeu.h"
#include <math.h>
#include "tableau.h"
#include <algorithm>
#include <iostream>

std::vector<Monstre> programmationDynamique(const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue) {
	unsigned int dimensions[2] = { monstres.size()+1, magie_rouge+1 };
	Tableau<unsigned int> t(std::vector<unsigned int>(dimensions, dimensions +2));
	std::vector<unsigned int> degatsVec(monstres.size());
	std::vector<unsigned int> magie_rougeVec(monstres.size());

	for (int i = 0; i < monstres.size(); i++) {
		degatsVec[i] = monstres[i].degat();
	}
	for (int i = 0; i < monstres.size(); i++) {
		magie_rougeVec[i] = monstres[i].magieRouge();
	}
	for (int i = 0; i < monstres.size(); i++) {
		t.at(i, 0) = 0;
	}
	for (int i = 0; i < magie_rouge; i++) {
		t.at(0, i) = 0;
	}
	for (int i = 1; i <= monstres.size(); i++) {
		for (int j = 1; j <= magie_rouge; j++) {
			int inter = j - magie_rougeVec[i];
			if (inter >= 0) {
				int degat = degatsVec[i];
				int jee = j;
				int iee = i;
				int magierouge = magie_rougeVec[i];
				int valeur = t.at(i, j - magie_rougeVec[i]);
				t.at(i, j) = std::max((unsigned) t.at(i - 1, j), degatsVec[i] + t.at(i, j - magie_rougeVec[i]));
			}
			else {
				t.at(i, j) = t.at(i - 1, j);
			}
		}
	}
	for (int i = 0; i < monstres.size() +1; i++) {
		for (int j = 0; j < magie_rouge; j++) {
			std::cout << t.at(i, j) << " ";
		}
		std::cout << "\n";
	}
	return std::vector<Monstre>();
}
