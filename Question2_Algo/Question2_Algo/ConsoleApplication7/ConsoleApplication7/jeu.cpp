#pragma once
#include "stdafx.h"
#include "jeu.h"
#include <math.h>
#include "tableau.h"

std::vector<Monstre> programmationDynamique(const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue) {
	unsigned int dimensions[2] = { monstres.size(), magie_rouge };
	Tableau<std::string> t(std::vector<unsigned int>(dimensions, dimensions + 2));


	return std::vector<Monstre>();
}
