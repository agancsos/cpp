#ifndef __TOKENGENERATOR_H_INCLUDED__
#define __TOKENGENERATOR_H_INCLUDED__
#include <iostream>
#include <string>
#include <vector>
#include "../string.h"
using namespace std;

namespace amgcommon {
    namespace auth {
        class TokenGenerator {
            protected:
                string numbers;
                string constanants;
                string vowels;
            public:
                TokenGenerator();
                virtual ~TokenGenerator();
                virtual string generate() = 0;
                
        };

        class BasicTokenGenerator : public TokenGenerator {
            private:
                int length;
            public:
                BasicTokenGenerator(int a=30);
                ~BasicTokenGenerator();
                string generate();
        };
    }
}
#endif