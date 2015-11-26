#ifndef belcard_parser_hpp
#define belcard_parser_hpp

#include "belcard.hpp"

#include <belr/grammarbuilder.hh>
#include <belr/abnf.hh>

using namespace::belr;

namespace belcard {
	class BelCardParser {
	private:
		ABNFGrammarBuilder _grammar_builder;
		shared_ptr<Grammar> _grammar;
		
	public:
		BelCardParser();
		~BelCardParser();
		
		shared_ptr<BelCard> parse(const string &input);
		string dumpVCard(const shared_ptr<BelCard> &card);
		
		string fold(string input);
		string unfold(string input);
	};
}

#endif