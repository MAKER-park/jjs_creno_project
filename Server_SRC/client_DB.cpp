#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
//MYSQL_HEADER
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#define BUF_SIZE 100
#define NAME_SIZE 20
//컨테이너 번호 , 행선지  [INFO] /BICU123456/7 
//<QR_DB> BICU6789012 2,0,1
void* send_msg(void* arg);
void* recv_msg(void* arg);
void error_handling(const char* msg);

using namespace std;

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

int main(int argc, char* argv[]) {
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void* thread_return;

	if(argc != 4) {
		printf("Usage : %s <IP> <port> <name> \n", argv[0]);
		exit(1);
	}

	sprintf(name, "[%s]", argv[3]);
	sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");

	pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
	pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);
	close(sock);
	return 0;
}

void* send_msg(void* arg) {
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE+BUF_SIZE];

	while(1) {
		fgets(msg, BUF_SIZE, stdin);
		if(!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) {
			close(sock);
			exit(0);
		}
        
		sprintf(name_msg, "%s %s", name, msg);
		write(sock, name_msg, strlen(name_msg));
        
	}
	return NULL;
}

void* recv_msg(void* arg) {
	int sock = *((int*)arg);
	char name_msg[NAME_SIZE+BUF_SIZE];
	int str_len;
	string msg_recv;

	while(1) {
		str_len = read(sock, name_msg, NAME_SIZE+BUF_SIZE-1);
		if(str_len == -1)
			return (void*)-1;
		name_msg[str_len] = 0;
		msg_recv += name_msg;
		fputs(name_msg, stdout);

		if((msg_recv.find("QR_DB") != string::npos)){
			cout << "get QR data! : " << msg_recv << endl;
			string num = msg_recv.substr(12,11);
			string pos = msg_recv.substr(24,5);
			cout << "num : " << num << " pos : " << pos << endl;
			//--------------UPLOAD DATA TO MYSQL-----------------
			try{
				sql::Driver *driver;
				sql::Connection *con;
				sql::Statement *stmt;
				sql::ResultSet *res;
				sql::PreparedStatement *pstmt;
				//connection
				// cout << "connect DB" << endl;
				driver = get_driver_instance();
  				con = driver->connect("tcp://127.0.0.1:3306", "park", "134625Wo@");
  				/* Connect to the MySQL test database */
  				con->setSchema("JJS");
				// cout << "connect done" << endl;

				//will change location 
				// cout << "INSERT" << endl;
				
				// cout << "INSERT INTO 'smart_crane'('ID','INFO','location') VALUES ('"+num+"','"+num+"','"+pos+"') ON DUPLICATE KEY UPDATE location='"+pos+"'" << endl;
  				cout << "pos : " << pos << endl;
				if(pos == "0,0,1"){
					//remove
					cout << "remove!" << endl;
					pstmt = con->prepareStatement("DELETE FROM `smart_crane` WHERE ID = '"+num+"'");
  					pstmt->executeUpdate();
  					delete pstmt;

				}else{
					//insert or update
					cout << "insert or update" << endl;
					// cout << "INSERT INTO `smart_crane`(`ID`, `INFO`, `location`) VALUES ('"+num+"','"+num+"','"+pos+"') ON DUPLICATE KEY UPDATE location='"+pos+"'" << endl;
					////INSERT INTO `smart_crane`(`ID`, `INFO`, `location`) VALUES ('BICU6789022','BICU6789022','1,0,2') ON DUPLICATE KEY UPDATE location='1,0,2'
					pstmt = con->prepareStatement("INSERT INTO `smart_crane`(`ID`, `INFO`, `location`) VALUES ('"+num+"','"+num+"','"+pos+"') ON DUPLICATE KEY UPDATE location='"+pos+"'");
  					pstmt->executeUpdate();
  					delete pstmt;
				}
  				// cout << "INSERT DONE" << endl;

				/* Select in ascending order */
  				pstmt = con->prepareStatement("SELECT * FROM `smart_crane` WHERE 1 ORDER BY id ASC");
  				res = pstmt->executeQuery();
  				res->afterLast();
  				while (res->previous())
    				cout << "\t... MySQL counts: " << res->getInt("id") << " , " << res->getString("DATE") << endl;
  				delete res;
  				delete pstmt;
  				delete con;
			}	catch (sql::SQLException &e) {
				cout << "# ERR: SQLException in " << __FILE__;
  				cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  				cout << "# ERR: " << e.what();
				cout << " (MySQL error code: " << e.getErrorCode();
				cout << ", SQLState: " << e.getSQLState() << " )" << endl;
				}

			//---------------------------------------------------
		}else if((msg_recv.find("move") != string::npos)){
			string pos = msg_recv.substr(15,5);
			string pos2 = msg_recv.substr(9,5);
			cout << " pos2 : " << pos2 << endl;
			//--------------UPLOAD DATA TO MYSQL-----------------
			try{
				sql::Driver *driver;
				sql::Connection *con;
				sql::Statement *stmt;
				sql::ResultSet *res;
				sql::PreparedStatement *pstmt;
				//connection
				// cout << "connect DB" << endl;
				driver = get_driver_instance();
  				con = driver->connect("tcp://127.0.0.1:3306", "park", "134625Wo@");
  				/* Connect to the MySQL test database */
  				con->setSchema("JJS");
				// cout << "connect done" << endl;

				//will change location 
				// cout << "INSERT" << endl;
				
				// cout << "INSERT INTO 'smart_crane'('ID','INFO','location') VALUES ('"+num+"','"+num+"','"+pos+"') ON DUPLICATE KEY UPDATE location='"+pos+"'" << endl;
				if(pos == "0,0,1"){
					//remove
					cout << "remove!" << endl;
					pstmt = con->prepareStatement("DELETE FROM `smart_crane` WHERE location = '"+pos2+"'");
  					pstmt->executeUpdate();
  					delete pstmt;
				}

				/* Select in ascending order */
  				pstmt = con->prepareStatement("SELECT * FROM `smart_crane` WHERE 1 ORDER BY id ASC");
  				res = pstmt->executeQuery();
  				res->afterLast();
  				while (res->previous())
    				cout << "\t... MySQL counts: " << res->getInt("id") << " , " << res->getString("DATE") << endl;
  				delete res;
  				delete pstmt;
  				delete con;
			}	catch (sql::SQLException &e) {
				cout << "# ERR: SQLException in " << __FILE__;
  				cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  				cout << "# ERR: " << e.what();
				cout << " (MySQL error code: " << e.getErrorCode();
				cout << ", SQLState: " << e.getSQLState() << " )" << endl;
				}

			//---------------------------------------------------
		}

		msg_recv.clear();
	}
	return NULL;
}

void error_handling(const char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}