#include "Poly.h"
#include <cmath>

Poly::Poly()
{
	head = new PolyNode (-1, 0, NULL);
	// TODO	
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff)
{
	head = new PolyNode(-1, 0, NULL);
	PolyNode* current = head;

	for(int i = 0; i < deg.size(); i++) {
		current->next = new PolyNode(deg.at(i), coeff.at(i), NULL);
		current=current->next;
	}
}

Poly::~Poly()
{
	// TODO
}

void Poly::addMono(int i, double c)
{
	// TODO
	PolyNode* current = head;
	PolyNode* tmp = NULL;
	int flag = 0;

	while(current->next!=NULL){
		if(i==current->next->deg){
			if(((current->next->coeff)+c)==0){
				tmp=current->next;
				current->next=current->next->next;
				delete tmp;
				flag=1;
				break;
			}
			else{
				current->next->coeff+=c;
				flag=1;
				break;
			}

		}
		else if(i>current->next->deg){
			current->next = new PolyNode(i, c, current->next);
			flag=1;
			break;
		}
		current=current->next;
	}
	if(flag==0){
		current->next = new PolyNode(i, c, current->next);
	}
}

void Poly::addPoly(const Poly& p)
{
	PolyNode* current = p.getHead();
	while(current->next!=NULL){
		addMono(current->next->deg, current->next->coeff);
		current=current->next;
	}
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
	PolyNode* current = head;
	while(current->next!=NULL){
		outputPoly.addMono(current->next->deg, current->next->coeff);
		current=current->next;
	}
	// TODO
}

int Poly::getDegree()
{
	// TODO
	if(head->next == NULL) {
		return -1;
	} else {
		return head->next->deg;
	}
}

int Poly::getTermsNo()
{
	// TODO
	int count = 0;
	PolyNode* current = head;

	while(current->next != NULL) {
		count++;
		current = current->next;
	}

	return count;//change this after completing this function
}

double Poly::evaluate(double x)
{
	PolyNode* current = head;
	PolyNode* tmp = NULL;
	double eval=0;

	while(current->next!=NULL){
		eval+=(current->next->coeff)*(std::pow(x,current->next->deg));
		current=current->next;
	}
	// TODO
	return eval;//change this after completing this function
}

std::string Poly::toString()
{
	// TODO
	return "";//change this after completing this function
}
