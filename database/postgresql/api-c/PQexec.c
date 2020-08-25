/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:59 CST. */
/* 
 Copyright (C) Rong Tao @Beijing

 Permission is granted to copy, distribute and/or modify this document
 under the terms of the GNU Free Documentation License, Version 1.3
 or any later version published by the Free Software Foundation;
 with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
 Texts. A copy of the license is included in the section entitled ‘‘GNU
 Free Documentation License’’.
   2019年 03月 15日 星期五 13:47:15 CST. 
*/
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 15日 星期五 13:46:59 CST. */
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

#define CHECK_RESULT(conn, res) \
	if(PQresultStatus(res) != PGRES_COMMAND_OK) { \
		do_exit(conn, res); \
	}

#define debug() printf("%s:%d\n", __func__, __LINE__)

void do_exit(PGconn *conn, PGresult *res)
{
	fprintf(stderr, "exit: %s\n", PQerrorMessage(conn));
	PQclear(res);
	PQfinish(conn);
	exit(1);
}

int main()
{
	PGconn *conn = PQconnectdb("user=rongtao dbname=testdb");

	if(PQstatus(conn) == CONNECTION_BAD)
	{
		fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
		PQfinish(conn);
		exit(1);
	}

	debug();

	/**
	 *	drop table
	 */
	PGresult *res = PQexec(conn, "drop table if exists Cars");
	CHECK_RESULT(conn, res);
	PQclear(res);

	debug();

	/**
	 * create table
	 */
	res = PQexec(conn, "create table Cars("\
						"Id integer primary key,"\
						"Name varchar(20),"\
						"Price integer);");
	CHECK_RESULT(conn, res);
	PQclear(res);

	debug();

	/**
	 *	insert into table
	 */
	res = PQexec(conn, "insert into Cars "\
						"values"\
						"(1, 'Audi', 52642),"\
						"(2, 'Mercedes', 57127),"\
						"(3, 'Skoda', 9000),"\
						"(4, 'Volvo', 29000),"\
						"(5, 'Bentley', 350000),"\
						"(6, 'Citroen', 21000),"\
						"(7, 'Hummer', 41400),"\
						"(8, 'Volkswagen', 21600)");
	CHECK_RESULT(conn, res);
	PQclear(res);
	
	debug();

	PQfinish(conn);

	return 0;
}
