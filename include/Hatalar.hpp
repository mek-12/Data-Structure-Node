#ifndef HATALAR_HPP
#define HATALAR_HPP

#include "Hata.hpp"

class SinirDisi : public Hata{
public:
	SinirDisi(const string &msg):Hata(msg){}
};

class ElemanYok : public Hata{
public:
	ElemanYok(const string &msg):Hata(msg){ }
}
#endif