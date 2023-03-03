#include "Poly.h"

Poly::Poly()
{
	// TODO	
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	head = new PolyNode(-1, 0, NULL);
	PolyNode* current = head;

	for(int i = 0; i < deg.size(); i++) {
		current->next = new PolyNode(deg.at(i), coeff.at(i), NULL);
	}
}

Poly::~Poly()
{
	// TODO
}

void Poly::addMono(int i, double c)
{
	// TODO
}

void Poly::addPoly(const Poly& p)
{
	// TODO
}

void Poly::multiplyMono(int i, double c)
{
	// TODO
}

void Poly::multiplyPoly(const Poly& p)
{
	// TODO
}

void Poly::duplicate(Poly& outputPoly)
{
	// TODO
}

int Poly::getDegree()
{
	// TODO
	return -2;//change this after completing this function
}

int Poly::getTermsNo()
{
	// TODO
	return -1;//change this after completing this function
}

double Poly::evaluate(double x)
{
	// TODO
	return -1;//change this after completing this function
}

std::string Poly::toString()
{
	// TODO
	return "";//change this after completing this function
}
