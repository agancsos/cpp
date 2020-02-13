#include "tokengenerator.h"
namespace amgcommon {
    namespace auth {
        TokenGenerator::TokenGenerator() {
            this->numbers = "0123456789";
            this->constanants = "bcdfghjklmnpqrstvwxz";
            this->vowels = "aeiouy";
        }

        TokenGenerator::~TokenGenerator() {
            
        }
            
        BasicTokenGenerator::BasicTokenGenerator(int a) : TokenGenerator() {
            this->length = a;
        }

        BasicTokenGenerator::~BasicTokenGenerator() {

        }

        string BasicTokenGenerator::generate() {
            vector<string> allCharacters = AMGString((numbers + vowels + constanants)).split("");
            string result = "";
            for (int i = 0; i < this->length; i++) {
                int randIndex = (rand() % allCharacters.size()) + 1;
                result += allCharacters[randIndex];
            }
            return result;
        }
    }
}