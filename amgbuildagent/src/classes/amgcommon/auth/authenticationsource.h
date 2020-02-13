#ifndef __AUTHSOURCE_H_INCLUDED__
#define __AUTHSOURCE_H_INCLUDED__
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "tokengenerator.h"
using namespace std;

namespace amgcommon {
    namespace auth {
        class AuthenticationSource {
            public:
                AuthenticationSource() { }
                virtual ~AuthenticationSource() { }
                virtual shared_ptr<AuthenticationSource> getInstance() { return nullptr; }
                virtual bool isValid(string username, string password) = 0;
                virtual bool isValid(string token) = 0;
                virtual string authenticate(string username, string password) = 0;
        };
    }
}
#endif