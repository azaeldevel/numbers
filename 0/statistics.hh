
#ifndef OCTETOS_NUMBERS_V0_STATISTICS_HH
#define OCTETOS_NUMBERS_V0_STATISTICS_HH

/**
 *
 *  This file is part of octetos-core.
 *  octetos-core is a core C/C++ Octeto's library.
 *  Copyright (C) 2018  Azael Reyes
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * */


#include "common.hh"
#if defined(__linux__)

#elif defined(_WIN32) || defined(_WIN64)
	#include <core/src/defines.hh>
#else
	#error "Plataforma desconocida"
#endif


namespace oct::nums::v0
{
	//>>>Media
	template<core::real Data> Data media(size_t length, const Data* n)
	{
		//std::cout << "media<T>(...)\n";
		Data v = Data(0);
		for (size_t i = 0; i < length; i++)
		{
			v += n[i];
		}
		//std::cout << "media<T>(...)  sigma : " << sigma << "\n";
		Data m = v / Data(length);
		//std::cout << "media<T>(...)  m : " << m << "\n";
		return m;
	}
	template<class Container,core::real Data> double media(size_t length, const Container* data, const Data Container::* member)
	{
		//std::cout << "media<T>(...)\n";
		double v = double(0);
		for (size_t i = 0; i < length; i++)
		{
			v += data[i].*member;
		}
		//std::cout << "media<T>(...)  sigma : " << v << "\n";
		double m = v / double(length);
		//std::cout << "media<T>(...)  m : " << m << "\n";
		return m;
	}
	//https://www.scs.stanford.edu/~dm/blog/param-pack.html,https://iamsorush.com/posts/cpp-variadic-template/
	template<core::real T, typename ...Args> T media(Args... args)
	{
		//std::cout << "media<T>(...)\n";
		T sigma = (args + ...);
		//std::cout << "media<T>(...)  sigma : " << sigma << "\n";
		T m = sigma / T(sizeof...(args));
		//std::cout << "media<T>(...)  m : " << m << "\n";
		return m;
	}
	template<core::real T, Number R, typename ...Args> R media(Args... args)
	{
		//std::cout << "media<T>(...)\n";
		T sigma = (args + ...);
		//std::cout << "media<T>(...)  sigma : " << sigma << "\n";
		R m = R(sigma) / R(sizeof...(args));
		//std::cout << "media<T>(...)  m : " << m << "\n";
		return m;
	}


	//desviacion estandar
	template<core::real Data> Data desv(size_t length, const Data* numbers)
	{
		//std::cout << "media<T>(...)\n";
		Data m = media<Data>(length, numbers);
		Data v = Data(0);
		for (size_t i = 0; i < length; i++)
		{
			v += pow(numbers[i] - m, 2);
		}
		//std::cout << "media<T>(...)  sigma : " << sigma << "\n";
		v = v / Data(length);
		//std::cout << "media<T>(...)  m : " << m << "\n";
		v = sqrt(v);
		return v;
	}
	template<typename Container,core::real Data> Data desv(size_t length, const Container* data, const Data Container::* member)
	{
		//std::cout << "media<T>(...)\n";
		Data m = media<Container>(length, data, member);
		Data v = Data(0);
		for (size_t i = 0; i < length; i++)
		{
			v += pow(data[i].*member - m, 2);
		}
		//std::cout << "media<T>(...)  sigma : " << sigma << "\n";
		v = v / Data(length);
		//std::cout << "media<T>(...)  m : " << m << "\n";
		v = sqrt(v);
		return v;
	}
	template<core::real T, typename ...Args> T desv(Args... args)
	{
		//std::cout << "desv<T>(...)\n";
		T m = media<T>(args...);
		//std::cout << "media : " << m << "\n";

		T sigma = (pow(args - m, T(2)) + ...);
		//std::cout << "sigma : " << sigma << "\n";
		T d = sigma / sizeof...(args);
		d = sqrt(d);

		return d;
	}
	template<core::real T, Number R, typename ...Args> R desv(Args... args)
	{
		//std::cout << "desv<T>(...)\n";
		R m = media<T, R>(args...);
		//std::cout << "media : " << m << "\n";

		R sigma = (pow(args - m, R(2)) + ...);
		//std::cout << "sigma : " << sigma << "\n";
		R d = sigma / sizeof...(args);
		d = sqrt(d);

		return d;
	}
}

#endif
