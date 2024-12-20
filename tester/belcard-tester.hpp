/*
	belcard-tester.hpp
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

#ifndef belcard_tester_hpp
#define belcard_tester_hpp

#include <bctoolbox/logging.h>
#include <bctoolbox/tester.h>

#include <string>
#include <memory>
#include <sstream>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

extern test_suite_t vcard_general_properties_test_suite;
extern test_suite_t vcard_identification_properties_test_suite;
extern test_suite_t vcard_addressing_properties_test_suite;
extern test_suite_t vcard_communication_properties_test_suite;
extern test_suite_t vcard_geographical_properties_test_suite;
extern test_suite_t vcard_organizational_properties_test_suite;
extern test_suite_t vcard_explanatory_properties_test_suite;
extern test_suite_t vcard_security_properties_test_suite;
extern test_suite_t vcard_calendar_properties_test_suite;
extern test_suite_t vcard_rfc6474_properties_test_suite;
extern test_suite_t vcard_test_suite;

void belcard_tester_init(void(*ftester_printf)(int level, const char *fmt, va_list args));
void belcard_tester_uninit(void);

#ifdef __cplusplus
};
#endif

template<typename T>
void test_property(const std::string& input, bool v3 = false, const std::string& allowedOutput = "") {
	std::shared_ptr<T> ptr = T::parse(input, v3);
	BC_ASSERT_TRUE(ptr!=NULL);
	if (ptr == NULL) {
		bctbx_error("Couldn't parse [%s]", input.c_str());
	} else {
		std::string str = ptr->toString();
		int compare = input.compare(str);
		if (compare != 0) {
			if (allowedOutput != "") {
				compare = allowedOutput.compare(str);
				BC_ASSERT_EQUAL(compare, 0, int, "%d");
				if (compare != 0) {
					std::cout << "Expected " << input << " but got " << str << std::endl;
				}
			} else {
				BC_ASSERT_EQUAL(compare, 0, int, "%d");
				bctbx_error("Expected [%s] but got [%s]", input.c_str(), str.c_str());
			}
		}
	}
}

#endif
