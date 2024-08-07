/*
    belcard_geographical.cpp
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

using namespace ::std;
using namespace ::belr;
using namespace ::belcard;

shared_ptr<BelCardTimezone> BelCardTimezone::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardTimezone>("TZ", input, v3);
}

void BelCardTimezone::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("TZ", make_fn(BelCardGeneric::createV3<BelCardTimezone>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("TZ-value", make_sfn(&BelCardProperty::setValue));
	} else {
		parser->setHandler("TZ", make_fn(BelCardGeneric::create<BelCardTimezone>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("PID-param", make_sfn(&BelCardProperty::setParamIdParam))
		    ->setCollector("PREF-param", make_sfn(&BelCardProperty::setPrefParam))
		    ->setCollector("TYPE-param", make_sfn(&BelCardProperty::setTypeParam))
		    ->setCollector("MEDIATYPE-param", make_sfn(&BelCardProperty::setMediaTypeParam))
		    ->setCollector("TZ-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardTimezone::BelCardTimezone(bool v3) : BelCardProperty(v3) {
	setName("TZ");
}

shared_ptr<BelCardGeo> BelCardGeo::parse(const string &input, bool v3) {
	return BelCardProperty::parseProperty<BelCardGeo>("GEO", input, v3);
}

void BelCardGeo::setHandlerAndCollectors(Parser<shared_ptr<BelCardGeneric>> *parser, bool v3) {
	if (v3) {
		parser->setHandler("GEO", make_fn(BelCardGeneric::createV3<BelCardGeo>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("GEO-value", make_sfn(&BelCardProperty::setValue));
	} else {
		parser->setHandler("GEO", make_fn(BelCardGeneric::create<BelCardGeo>))
		    ->setCollector("group", make_sfn(&BelCardProperty::setGroup))
		    ->setCollector("any-param", make_sfn(&BelCardProperty::addParam))
		    ->setCollector("VALUE-param", make_sfn(&BelCardProperty::setValueParam))
		    ->setCollector("ALTID-param", make_sfn(&BelCardProperty::setAlternativeIdParam))
		    ->setCollector("PID-param", make_sfn(&BelCardProperty::setParamIdParam))
		    ->setCollector("PREF-param", make_sfn(&BelCardProperty::setPrefParam))
		    ->setCollector("TYPE-param", make_sfn(&BelCardProperty::setTypeParam))
		    ->setCollector("MEDIATYPE-param", make_sfn(&BelCardProperty::setMediaTypeParam))
		    ->setCollector("GEO-value", make_sfn(&BelCardProperty::setValue));
	}
}

BelCardGeo::BelCardGeo(bool v3) : BelCardProperty(v3) {
	setName("GEO");
}