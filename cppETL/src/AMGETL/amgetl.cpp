#include "amgetl.h"
using namespace std;

AMGETL::AMGETL(){
	applicationFilePath = "";
	dataType = "0";
	silent = false;
	basePath = "../resources/";
}

AMGETL::~AMGETL(){
}

void AMGETL::Run(){
	AMGData dataSession = AMGData();
	dataSession.basePath = basePath;

	if(dataSession.CreateDBs()){
		
		// Check if specific file was selected
		if(applicationFilePath != ""){
			if(dataType != ""){
				if(dataType == "0"){
					cout << "This is the default value, please specify a data type..." << endl;
				}
				else if(dataType == "1"){
            		vector<BaseballStatRecord> records1;
            		try{
                		records1 = BaseballCSVReader(applicationFilePath).Load();
                		for(int i = 0; i < records1.size(); i++){
                   			try{
                       			dataSession.InsertBaseball(records1[i]);
                       			cout << records1[i] << endl;
                   			}
                   			catch(exception &e){
                       			continue;
                   			}
                		}
            		}
            		catch(exception &e){
                		if(!silent){
                   			cout << "Failed to load BaseballRecords data from CSV file..." << endl;
                		}
            		}
				}
				else if(dataType == "2"){
                	vector<StockStatRecord> records2;
                    try{
                   	 	records2 = StockCSVReader(applicationFilePath).Load();
                        for(int i = 0; i < records2.size(); i++){
                        	try{
								dataSession.InsertStock(records2[i]);
                            	cout << records2[i] << endl;
                            }
                            catch(exception &e){
                            	continue;
                            }
                        }
                    }
                    catch(exception &e){
                        if(!silent){
                            cout << "Failed to load StockRecords data from CSV file..." << endl;
                        }
                	}
				}
				else{
					cout << "This data type is not implemented..." << endl;
				}
			}
			else{
				cout << "You must specify the data type if you specify the data file..." << endl;
			}
		}
		
		// Run all data files
		else{
			// Run baseball stats
			vector<BaseballStatRecord> records1;
			try{
				records1 = BaseballCSVReader(basePath + "/csv/MLB2008.csv").Load();
				for(int i = 0; i < records1.size(); i++){
					try{
						dataSession.InsertBaseball(records1[i]);		
						cout << records1[i] << endl;
					}
					catch(exception &e){
						continue;
					}
				}
			}
			catch(exception &e){
				if(!silent){
					cout << "Failed to load BaseballRecords data from CSV file..." << endl;
				}
			}

			// Run stock stats
            vector<StockStatRecord> records2;
            try{
                records2 = StockCSVReader(basePath + "/csv/StockValuations.csv").Load();
                for(int i = 0; i < records2.size(); i++){
                    try{
						dataSession.InsertStock(records2[i]);
                        cout << records2[i] << endl;
                    }
                    catch(exception &e){
                        continue;
                    }
                }
            }
            catch(exception &e){
                if(!silent){
                    cout << "Failed to load StockRecords data from CSV file..." << endl;
                }
            }
		}
	}
	else{
		if(!silent){
			cout << "Failed to create databases..." << endl;
		}
	}	
}

