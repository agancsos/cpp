#ifndef __AMGSYSTEMEXCEPTION_H_INCLUDED__  
#define __AMGSYSTEMEXCEPTION_H_INCLUDED__ 

#include <string>
using namespace std;

/**
 * This is a custom exception class
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 */
class AMGSystemException : public exception{
	protected:
		string message;
	public:
		AMGSystemException();
		AMGSystemException(string msg) : message(msg);
		~AMGSystemException() throw() {};
		virtual const char* what() const throw (){
       		return message.c_str();
    	}
};

#endif
