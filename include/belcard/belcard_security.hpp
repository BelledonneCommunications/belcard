/*
    belcard_security.hpp
    Copyright (C) 2015  Belledonne Communications SARL

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef belcard_security_hpp
#define belcard_security_hpp

#include "belcard_property.hpp"
#include "belcard_utils.hpp"
#include <belr/abnf.h>
#include <belr/grammarbuilder.h>

#include <string>

namespace belcard {
class BelCardKey : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardKey> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardKey(bool v3);
};

class BelCardClass : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardClass> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardClass(bool v3);
};
} // namespace belcard

#endif
