#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum{

public:
	string eleman;
	int valueOfFactoriel;
	Dugum* ileri;
	Dugum(string, Dugum* ilr);
	Dugum(string, Dugum* llr, int)
};

#endif