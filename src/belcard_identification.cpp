/*
    belcard_identification.cpp
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

#include "belcard/belcard.hpp"
#include "belcard/belcard_utils.hpp"

using namespace ::std;
using namespace ::belr;
using namespace ::belcard;

shared_ptr<BelCardFullName> BelCardFullName::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardFullName>("FN", input, v3);
}

void BelCardFullName::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("FN", make_fn(BelCardGeneric::createV3<BelCardFullName>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("FN-value", make_sfn(&BelCardProperty::setValue));
	} else {
		parser->setHandler("FN", make_fn(BelCardGeneric::create<BelCardFullName>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("TYPE-param", make_sfn(&BelCardProperty::setTypeParam))
		    ->setCollector("LANGUAGE-param", make_sfn(&BelCardProperty::setLanguageParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("PID-param", make_sfn(&BelCardProperty::setParamIdParam))
		    ->setCollector("PREF-param", make_sfn(&BelCardProperty::setPrefParam))
		    ->setCollector("FN-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardFullName::BelCardFullName(bool v3) : BelCardProperty(v3) {
	setName("FN");
}

shared_ptr<BelCardName> BelCardName::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardName>("N", input, v3);
}

void BelCardName::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("N", make_fn(BelCardGeneric::createV3<BelCardName>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("N-fn", make_sfn(&BelCardName::setFamilyName))
		    ->setCollector("N-gn", make_sfn(&BelCardName::setGivenName))
		    ->setCollector("N-an", make_sfn(&BelCardName::setAdditionalName))
		    ->setCollector("N-prefixes", make_sfn(&BelCardName::setPrefixes))
		    ->setCollector("N-suffixes", make_sfn(&BelCardName::setSuffixes));
	} else {
		parser->setHandler("N", make_fn(BelCardGeneric::create<BelCardName>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("SORT-AS-param", make_sfn(&BelCardProperty::setSortAsParam))
		    ->setCollector("LANGUAGE-param", make_sfn(&BelCardProperty::setLanguageParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("N-fn", make_sfn(&BelCardName::setFamilyName))
		    ->setCollector("N-gn", make_sfn(&BelCardName::setGivenName))
		    ->setCollector("N-an", make_sfn(&BelCardName::setAdditionalName))
		    ->setCollector("N-prefixes", make_sfn(&BelCardName::setPrefixes))
		    ->setCollector("N-suffixes", make_sfn(&BelCardName::setSuffixes));
	}
}

BelCardName::BelCardName(bool v3) : BelCardProperty(v3) {
	setName("N");
}

void BelCardName::setFamilyName(const string &value) {
	_family_name = belcard_unescape_string(value);
}
const string &BelCardName::getFamilyName() const {
	return _family_name;
}

void BelCardName::setGivenName(const string &value) {
	_given_name = belcard_unescape_string(value);
}
const string &BelCardName::getGivenName() const {
	return _given_name;
}

void BelCardName::setAdditionalName(const string &value) {
	_additional_name = belcard_unescape_string(value);
}
const string &BelCardName::getAdditionalName() const {
	return _additional_name;
}

void BelCardName::setPrefixes(const string &value) {
	_prefixes = belcard_unescape_string(value);
}
const string &BelCardName::getPrefixes() const {
	return _prefixes;
}

void BelCardName::setSuffixes(const string &value) {
	_suffixes = belcard_unescape_string(value);
}
const string &BelCardName::getSuffixes() const {
	return _suffixes;
}

void BelCardName::serialize(ostream &output) const {
	if (getGroup().length() > 0) {
		output << getGroup() << ".";
	}

	output << getName();
	for (auto it = getParams().begin(); it != getParams().end(); ++it) {
		output << ";" << (**it);
	}
	output << ":" << belcard_escape_string(getFamilyName()) << ";" << belcard_escape_string(getGivenName()) << ";"
	       << belcard_escape_string(getAdditionalName()) << ";" << belcard_escape_string(getPrefixes()) << ";"
	       << belcard_escape_string(getSuffixes()) << "\r\n";
}

shared_ptr<BelCardNickname> BelCardNickname::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardNickname>("NICKNAME", input, v3);
}

void BelCardNickname::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("NICKNAME", make_fn(BelCardGeneric::createV3<BelCardNickname>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("NICKNAME-value", make_sfn(&BelCardProperty::setValue));
	} else {
		parser->setHandler("NICKNAME", make_fn(BelCardGeneric::create<BelCardNickname>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("TYPE-param", make_sfn(&BelCardProperty::setTypeParam))
		    ->setCollector("LANGUAGE-param", make_sfn(&BelCardProperty::setLanguageParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("PID-param", make_sfn(&BelCardProperty::setParamIdParam))
		    ->setCollector("PREF-param", make_sfn(&BelCardProperty::setPrefParam))
		    ->setCollector("NICKNAME-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardNickname::BelCardNickname(bool v3) : BelCardProperty(v3) {
	setName("NICKNAME");
}

shared_ptr<BelCardBirthday> BelCardBirthday::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardBirthday>("BDAY", input, v3);
}

void BelCardBirthday::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("BDAY", make_fn(BelCardGeneric::createV3<BelCardBirthday>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("BDAY-value", make_sfn(&BelCardProperty::setValue));
	} else {
		parser->setHandler("BDAY", make_fn(BelCardGeneric::create<BelCardBirthday>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("LANGUAGE-param", make_sfn(&BelCardProperty::setLanguageParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("CALSCALE-param", make_sfn(&BelCardProperty::setCALSCALEParam))
		    ->setCollector("BDAY-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardBirthday::BelCardBirthday(bool v3) : BelCardProperty(v3) {
	setName("BDAY");
}

shared_ptr<BelCardAnniversary> BelCardAnniversary::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardAnniversary>("ANNIVERSARY", input, v3);
}

void BelCardAnniversary::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (!v3) {
		parser->setHandler("ANNIVERSARY", make_fn(BelCardGeneric::create<BelCardAnniversary>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("CALSCALE-param", make_sfn(&BelCardProperty::setCALSCALEParam))
		    ->setCollector("ANNIVERSARY-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardAnniversary::BelCardAnniversary(bool v3) : BelCardProperty(v3) {
	setName("ANNIVERSARY");
}

shared_ptr<BelCardGender> BelCardGender::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardGender>("GENDER", input, v3);
}

void BelCardGender::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (!v3) {
		parser->setHandler("GENDER", make_fn(BelCardGeneric::create<BelCardGender>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("GENDER-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardGender::BelCardGender(bool v3) : BelCardProperty(v3) {
	setName("GENDER");
}

shared_ptr<BelCardPhoto> BelCardPhoto::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardPhoto>("PHOTO", input, v3);
}

void BelCardPhoto::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("PHOTO", make_fn(BelCardGeneric::createV3<BelCardPhoto>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("TYPE-param", make_sfn(&BelCardProperty::setTypeParam))
		    ->setCollector("PHOTO-value", make_sfn(&BelCardProperty::setValue));
	} else {
		parser->setHandler("PHOTO", make_fn(BelCardGeneric::create<BelCardPhoto>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("TYPE-param", make_sfn(&BelCardProperty::setTypeParam))
		    ->setCollector("MEDIATYPE-param", make_sfn(&BelCardProperty::setMediaTypeParam))
		    ->setCollector("PREF-param", make_sfn(&BelCardProperty::setPrefParam))
		    ->setCollector("PID-param", make_sfn(&BelCardProperty::setParamIdParam))
		    ->setCollector("PHOTO-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardPhoto::BelCardPhoto(bool v3) : BelCardProperty(v3) {
	setName("PHOTO");
}

shared_ptr<BelCardDisplayName> BelCardDisplayName::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardDisplayName>("NAME", input, v3);
}

void BelCardDisplayName::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("NAME", make_fn(BelCardGeneric::createV3<BelCardDisplayName>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("NAME-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardDisplayName::BelCardDisplayName(bool v3) : BelCardProperty(v3) {
	setName("NAME");
}

shared_ptr<BelCardSortString> BelCardSortString::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardSortString>("SORT-STRING", input, v3);
}

void BelCardSortString::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("SORT-STRING", make_fn(BelCardGeneric::createV3<BelCardSortString>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("SORT-STRING-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardSortString::BelCardSortString(bool v3) : BelCardProperty(v3) {
	setName("SORT-STRING");
}