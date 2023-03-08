#include "Poly.h"
#include <cmath>
#include <iostream>

using namespace std;

Poly::Poly()
{
	head = new PolyNode (-1, 0, NULL);
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
	PolyNode* temp = head->next;

	while(head->next != NULL) {
		temp = temp->next;
		delete head->next;
		head->next = temp;
	}

	delete head;
}

void Poly::addMono(int i, double c)
{
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
	PolyNode* current = head->next;

	if(c == 0) {
		this->makeEmpty();
	} else {
		while(current != NULL) {
			current->coeff *= c;
			current->deg += i;
			current = current->next;
		}
	}
}

void Poly::multiplyPoly(const Poly& p)
{
	if(head->next == NULL) {
		return;
	}

	PolyNode* current = p.head->next;
	Poly product;
	Poly copy;

	duplicate(copy);
	makeEmpty();

	while(current != NULL) {
		copy.duplicate(product);
		product.multiplyMono(current->deg, current->coeff);
		addPoly(product);
		product.makeEmpty();
		current = current->next;
	}
}

void Poly::makeEmpty() {
	PolyNode* temp = head->next;

	while(head->next != NULL) {
		temp = temp->next;
		delete head->next;
		head->next = temp;
	}

	head->next = NULL;
}

void Poly::duplicate(Poly& outputPoly)
{
	PolyNode* current = head;
	while(current->next!=NULL){
		outputPoly.addMono(current->next->deg, current->next->coeff);
		current=current->next;
	}
}

int Poly::getDegree()
{
	if(head->next == NULL) {
		return -1;
	} else {
		return head->next->deg;
	}
}

int Poly::getTermsNo()
{
	int count = 0;
	PolyNode* current = head;

	while(current->next != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

double Poly::evaluate(double x)
{
	PolyNode* current = head;
	double eval=0;

	while(current->next!=NULL){
		eval+=(current->next->coeff)*(std::pow(x,current->next->deg));
		current=current->next;
	}

	return eval;
}

std::string Poly::toString()
{
	PolyNode* current = head->next;
	string str = "degree = " + to_string(getDegree());

	while(current != NULL) {
		str += "; a(" + to_string(current->deg) + ") = " + to_string(current->coeff);
		current = current->next;
	}

	return str;
}
