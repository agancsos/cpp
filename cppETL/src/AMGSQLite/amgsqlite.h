#ifndef __AMGSQLITE_H_INCLUDED__  
#define __AMGSQLITE_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include "../AMGString/amgstring.h"
#include "../AMGSystem/amgsystem.h"
#include "amgdbrow.h"
using namespace std;

class AMGSQLite{
	public:
		string databaseFile;
		AMGSQLite();
		~AMGSQLite();
		AMGSQLite(string path);
		bool RunQuery(string sql);
		vector<AMGDBRow> Query(string sql);
	private:
		sqlite3 *databaseHandler;
		bool Connect();
		void Disconnect();
};

#endif
