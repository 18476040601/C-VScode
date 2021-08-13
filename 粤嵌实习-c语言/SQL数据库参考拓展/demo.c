#include "common.h"

typedef struct info
{
	unsigned int CarId ;
	char UserName [32];
	unsigned int Money ;
}Info;

Info Car_info ;

sqlite3 *db = NULL;
char *errmsg = NULL;
static int calltimes = 0;

static int callback(void *notused, int argc, char **argv, char **azColName)
{
	int i;
	calltimes++;

	for(i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i],
				argv[i] ? argv[i] : "NULL");
	}

	Car_info.CarId = atoi(argv[0]);
	strcpy(Car_info.UserName , argv[1]); 
	Car_info.Money = atoi(argv[2]);

	printf("number %d callback.....\n", calltimes);

	return 0;
}

int sql_init (void)
{

	//打开数据库
	sqlite3_open("test.db",&db);
	char * sql = "create table if not exists test_id (CardId INTEGER PRIMARY KEY, UserName text, Money text , logtime TIMESTAMP default (datetime('now', 'localtime')) );";  
	
	int ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);  
    if(ret != SQLITE_OK)  
    {  
        printf("create table error : %s\n",errmsg);  
		return -1;
    }  

    sqlite3_close(db);
}

int main(int argc, char **argv)
{
	// sql_init ();

	char * sql = NULL ;
	// create db
	Sqlite3_open_v2("test.db", &db,
			SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
			NULL);

	// insert item
	// char *errmsg = NULL;
	// sql = "insert into test_id(CardId, UserName , Money) values(0x0F0F0F0F , 'Even' , 1024);";
	// Sqlite3_exec(db, sql, NULL, NULL, &errmsg);

	// find item
	sql = "select * from test_id where CardId = 0x0F0F0F0F;";
	Sqlite3_exec(db, sql, callback, NULL, &errmsg);
	
	// update item
	sql = "update test_id set Money = 128 where CardId = 0x0F0F0F0F;" ;
	Sqlite3_exec(db, sql, callback, NULL, &errmsg);


	// select items
	sql = "select * from test_id;";
	Sqlite3_exec(db, sql, callback, NULL, &errmsg);


	// close db
	sqlite3_close(db);

	printf("检查卡片数据：\n");
	printf("ID:%#X\n" , Car_info.CarId);
	printf("UsrName:%s\n" , Car_info.UserName);
	printf("Money:%d\n" , Car_info.Money);


	return 0;
}
