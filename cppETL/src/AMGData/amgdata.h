#ifndef __AMGData_H_INCLUDED__  
#define __AMGData_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
#include "../AMGString/amgstring.h"
#include "../AMGSystem/amgsystem.h"
#include "../AMGSQLite/amgsqlite.h"
#include "../ETL/baseballstatrecord.h"
#include "../ETL/stockstatrecord.h"

class AMGData{
	public:
		string basePath;
		AMGData();
		~AMGData();
		bool CreateDBs();
		bool InsertBaseball(BaseballStatRecord a);
		bool InsertStock(StockStatRecord a);

	private:
		bool CreateBaseballDB();
		bool CreateStockDB();
};

#endif
