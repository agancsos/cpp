#include "sr.h"

namespace sr {
	/**
 	 * This method is displayed as a help menu for non-interactive options
 	 * @precondition  (Utility has been with the help switch)
 	 * @postcondition (Details of the utility are displayed in the system console)
 	 */
	void SR::helpMenu(){
    	cout << padRight("", 80, "=") << endl;
    	cout << "* Name   :" <<  __PRODUCT_NAME_STRING__ << endl;
    	cout << "* Author :" << __PRODUCT_AUTHOR_STRING__ << endl;
    	cout << "* Version: v. " << __AGENT_VERSION_STRING__ << endl;
    	cout << "* Flags:" << endl;
    	cout << padRight("", 80, "=") << endl;
	}
	string SR::padRight(string str, int len, string pad) {
		if(str.length() > len){                                                                                                                                                         
            return str.substr(0,len);                                                                                                                                                   
        }                                                                                                                                                                               
        else{                                                                                                                                                                           
            string mFinal = "";                                                                                                                                                         
            for(int i = str.length(); i < len; i++){                                                                                                                                    
                mFinal += pad;                                                                                                                                                          
            }                                                                                                                                                                           
            return (str + mFinal);                                                                                                                                                      
        }    
	}
}
