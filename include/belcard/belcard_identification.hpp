/*
    belcard_identification.hpp
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

#ifndef belcard_identification_hpp
#define belcard_identification_hpp

#include "belcard_property.hpp"
#include "belcard_utils.hpp"
#include <belr/abnf.h>
#include <belr/grammarbuilder.h>

#include <list>
#include <sstream>
#include <string>

namespace belcard {
class BelCardFullName : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardFullName> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardFullName(bool v3);
};

class BelCardName : public BelCardProperty {
private:
	std::string _family_name;
	std::string _given_name;
	std::string _additional_name;
	std::string _prefixes;
	std::string _suffixes;

public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardName> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardName(bool v3);

	BELCARD_PUBLIC void setFamilyName(const std::string &value);
	BELCARD_PUBLIC const std::string &getFamilyName() const;

	BELCARD_PUBLIC void setGivenName(const std::string &value);
	BELCARD_PUBLIC const std::string &getGivenName() const;

	BELCARD_PUBLIC void setAdditionalName(const std::string &value);
	BELCARD_PUBLIC const std::string &getAdditionalName() const;

	BELCARD_PUBLIC void setPrefixes(const std::string &value);
	BELCARD_PUBLIC const std::string &getPrefixes() const;

	BELCARD_PUBLIC void setSuffixes(const std::string &value);
	BELCARD_PUBLIC const std::string &getSuffixes() const;

	BELCARD_PUBLIC void serialize(std::ostream &output) const override;
};

class BelCardNickname : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardNickname> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardNickname(bool v3);
};

class BelCardBirthday : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardBirthday> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardBirthday(bool v3);
};

class BelCardAnniversary : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardAnniversary> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardAnniversary(bool v3);
};

class BelCardGender : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardGender> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardGender(bool v3);
};

class BelCardPhoto : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardPhoto> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardPhoto(bool v3);
};

class BelCardDisplayName : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardDisplayName> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardDisplayName(bool v3);
};

class BelCardSortString : public BelCardProperty {
public:
	BELCARD_PUBLIC static std::shared_ptr<BelCardSortString> parse(const std::string &input, bool v3);
	BELCARD_PUBLIC static void setHandlerAndCollectors(belr::Parser<std::shared_ptr<BelCardGeneric>> *parser,
	                                                   bool v3 = false);

	BELCARD_PUBLIC BelCardSortString(bool v3);
};
} // namespace belcard

#endif