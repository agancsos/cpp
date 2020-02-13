#include "authenticationsource_sqlite.h"
namespace amgcommon {
    namespace auth {
        shared_ptr<AuthenticationSourceSqlite> AuthenticationSourceSqlite::instance = nullptr;

            AuthenticationSourceSqlite::AuthenticationSourceSqlite(const string path, const string table) : AuthenticationSource() {
                this->path = path;
                this->usersTable = table;
                this->source = shared_ptr<DataConnectionSQLite>(new DataConnectionSQLite(this->path));
            }

            AuthenticationSourceSqlite::~AuthenticationSourceSqlite() {

            }

            shared_ptr<AuthenticationSourceSqlite> AuthenticationSourceSqlite::getInstance(const string path, const string table) {
                if (instance == nullptr) {
                    instance = shared_ptr<AuthenticationSourceSqlite>(new AuthenticationSourceSqlite(path, table));
                }
                return instance;
            }

            bool AuthenticationSourceSqlite::isValid(const string username, const string password) {
                if (this->usersTable != "") {
                    return (sizeof(this->source->query("SELECT 1 FROM user WHERE USER_NAME = '" + username + "' AND USER_PASSWORD = '" + password + "'")->getRows()) > 0);
                }
                return false;
            }

            bool AuthenticationSourceSqlite::isValid(const string token) {
                if (this->sessionTable != "") {
                    return (sizeof(this->source->query("SELECT 1 FROM session WHERE SESSION_TOKEN = '" + token + "'")->getRows()) > 0);
                }
                return false;
            }

            string AuthenticationSourceSqlite::authenticate(const string username, const string password) {
                if (this->isValid(username, password)) {
                    string token = BasicTokenGenerator().generate();
                    // Insert into sessions
                    string sql = "INSERT INTO session (SESSION_TOKEN, SESSION_UID) VALUES ('" + token + "', (SELECT USER_ID FROM user WHERE USER_NAME = '" + username + "'))";
                    if (!this->source->runQuery(sql)) {
                        throw "Failed to insert token";
                    }
                    return token;
                }
                return "-1";
            }

            void AuthenticationSourceSqlite::setPath(string a) {
                this->path = a;
                this->source->setDatabaseFile(a);
            }

            string AuthenticationSourceSqlite::getSessionTable() { return this->sessionTable; }
            void AuthenticationSourceSqlite::setSessionTable(const string a) { this->sessionTable = a; }
            string AuthenticationSourceSqlite::getUsersTable() { return this->usersTable; }
    }
}
