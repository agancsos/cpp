#include "amgsqlite.h"
using namespace std;

AMGSQLite::AMGSQLite(){
	databaseFile = "";
	databaseHandler = NULL;
}

AMGSQLite::~AMGSQLite(){
}

AMGSQLite::AMGSQLite(string path){
	databaseFile = path;
	databaseHandler = NULL;
}

bool AMGSQLite::Connect(){
	if(sqlite3_open(databaseFile.c_str(),&databaseHandler)){
		return false;
	}
	return true;
}

void AMGSQLite::Disconnect(){
	if(databaseHandler){
		sqlite3_close(databaseHandler);
	}
}

bool AMGSQLite::RunQuery(string sql){
	int status;
	if(Connect()){
		status = sqlite3_exec(databaseHandler,sql.c_str(), NULL, 0, NULL);
		if(status != SQLITE_OK){
			return false;
		}
		Disconnect();
	}
	else{
		Disconnect();
		return false;
	}
	Disconnect();
	return true;
}

vector<AMGDBRow> AMGSQLite::Query(string sql){
	vector<AMGDBRow> mFinal;
	if(Connect()){
		
		Disconnect();
	}
	return mFinal;
}
