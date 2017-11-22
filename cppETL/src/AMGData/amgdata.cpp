#include "amgdata.h"
using namespace std;

AMGData::AMGData(){
}

AMGData::~AMGData(){
}

bool AMGData::CreateDBs(){
	try{
		if(CreateBaseballDB()){
			if(CreateStockDB()){
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	catch(exception &e){
		return false;
	}
	return true;
}

bool AMGData::CreateBaseballDB(){
	try{
		string longSQL = "create table if not exists baseball_stats(player_name text primary";
		longSQL += "key,games_played integer default '0',average real default '0.00',salary real";
		longSQL += "default '0.00')";
		
		AMGSQLite dbSession = AMGSQLite(basePath + "/db/baseball.db");
		if(dbSession.RunQuery(longSQL)){
		}
		else{
			return false;
		}
		dbSession.RunQuery("delete from baseball_stats");
	}
	catch(exception &e){
	}
	return true;
}

bool AMGData::CreateStockDB(){
    try{
        string longSQL = "create table if not exists stock_stats(company_name text,ticker text";
        longSQL += "primary key,country text,price real default '0.00',exchange_rate real default '0.00',";
        longSQL += "shares_outstanding real default '0.00',net_income real default";
        longSQL += "'0.00',market_value real default '0.00',pe_ratio real default '0.00')";

        AMGSQLite dbSession = AMGSQLite(basePath + "/db/stocks.db");
        if(dbSession.RunQuery(longSQL)){
        }
        else{
            return false;
        }
		dbSession.RunQuery("delete from stock_stats");
    }
    catch(exception &e){
    }
	return true;
}

bool AMGData::InsertBaseball(BaseballStatRecord a){
	try{
		AMGSQLite dbSession = AMGSQLite(basePath + "/db/baseball.db");
		string longQuery = "insert into baseball_stats (player_name,games_played, average, salary) values ";
		longQuery += ("('" + a.name + "','" + to_string(a.games) + "','" + to_string(a.average) + "','" + to_string(a.salary) + "')");
		dbSession.RunQuery(longQuery);
		
	}
	catch(exception &e){
		return false;
	}
	return true;
}

bool AMGData::InsertStock(StockStatRecord a){
	try{
		AMGSQLite dbSession = AMGSQLite(basePath + "/db/stocks.db");
		string longQuery = "insert into stock_stats (company_name,ticker, country, price, exchange_rate";
		longQuery += ",net_income, market_value, pe_ratio,shares_outstanding) values ('";
		longQuery += (a.companyName + "','" + a.name + "','" + a.exchangeCountry + "','" + to_string(a.price) + "','" + to_string(a.exchangeRate) + "','");
		longQuery += (to_string(a.netIncome) + "','" + to_string(a.marketValueUsd) + "','" + to_string(a.peRatio) + "'," + to_string(a.sharesOutstanding) + "')");
		dbSession.RunQuery(longQuery);
	}
	catch(exception &e){
		return false;
	}
	return true;
}

