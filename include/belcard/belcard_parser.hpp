/*
    belcard_parser.hpp
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

#ifndef belcard_parser_hpp
#define belcard_parser_hpp

#include "belcard_utils.hpp"
#include <belr/abnf.h>
#include <belr/grammarbuilder.h>

namespace belcard {
class BelCardGeneric;
class BelCardList;
class BelCard;

class BelCardParser {
	friend class BelCardProperty;

private:
	belr::Parser<std::shared_ptr<BelCardGeneric>> *_parser;
	bool _v3 = false;

protected:
	std::shared_ptr<BelCardGeneric> _parse(const std::string &input, const std::string &rule);

public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardParser> getInstance(bool useVCard3Grammar = false);
	BELCARD_PUBLIC BelCardParser(bool useVCard3Grammar = false);
	BELCARD_PUBLIC ~BelCardParser();
	BELCARD_PUBLIC bool isUsingV3Grammar() const;

	BELCARD_PUBLIC std::shared_ptr<BelCard> parseOne(const std::string &input);
	BELCARD_PUBLIC std::shared_ptr<BelCardList> parse(const std::string &input);
	BELCARD_PUBLIC std::shared_ptr<BelCardList> parseFile(const std::string &filename);
};
} // namespace belcard

#endif
