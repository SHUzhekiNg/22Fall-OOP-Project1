#include "express.h"

ostream& operator<<(ostream& out, const Express& a)
{
	out << "ID:" << a.id_things << '\t' << a.name;
	return out;
}

istream& operator>>(istream& in, Express& a)
{
	in >> a.id_things >> a.name;
	return in;
}