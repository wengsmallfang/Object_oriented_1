#include<iostream>
#include<fstream>
using namespace std;


//class Dao
//{
//	public static SqlConnection connect()//定义连接数据库的方法（无参的方法）
//	{
//		string str = "Data Source=LAPTOP-D1MIH2P6;Initial Catalog=大学生综合管理系统;Integrated Security=True";//连接字符串@数据库
//		SqlConnection sc = new SqlConnection(str);//生成连接对象
//		sc.Open();//打开数据库链接
//		return sc;
//	}
//	public static SqlCommand command(string sql)//进行数据库操作（封装在SqlCommand源中）接收SQL语句并进行处理
//	{
//		SqlCommand cmd = new SqlCommand(sql, connect());//生成对象两个参数（要执行的SQL语句，连接对象）
//		return cmd;
//	}
//	public static SqlDataReader read(string sql)//用于select语句，生成一个获取的数据的集合（即select到的数据）
//	{
//		return command(sql).ExecuteReader();
//	}
//};


/*
//VS2013连接测试
#include<stdio.h>
#include<windows.h>
#include<sql.h>
#include<sqlext.h>
#include<sqltypes.h>
int main()
{
	SQLRETURN ret;
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;

	ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//申请环境句柄
	ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//申请数据库连接句柄
	//	vs 2013 使用： SQLWCHAR*
	SQLWCHAR db[] = L"test_db";
	SQLWCHAR user[] = L"sa";
	SQLWCHAR password[] = L"666666";

	//VS2013上，这是正确连接用法
	ret = SQLConnect(hdbc, db, SQL_NTS, user, SQL_NTS, password, SQL_NTS);

	//	错误做法：ret = SQLConnect(hdbc, (SQLWCHAR*)"test_db", SQL_NTS, (SQLWCHAR*)"sa", SQL_NTS, (SQLWCHAR*)"666666", SQL_NTS);
	//	这样转换(SQLWCHAR*)"test_db"将无法连接

	//	vc 6.0 要使用：ret=SQLConnect(hdbc,(SQLCHAR*)"DB_61",SQL_NTS,(SQLCHAR*)"sa",SQL_NTS,(SQLCHAR*)"666666",SQL_NTS);

	if (!(ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO))
	{
		printf("连接数据库失败!\n");
		return -1;
	}

	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

	//	vc 6.0 要使用：SQLCHAR sql1[]="use DB_61";

	//	VS2013用的是 SQLWCHAR
	SQLWCHAR sql2[] = L"select * from test_db.dbo.test";

	//	ret=SQLExecDirect(hstmt,sql1,SQL_NTS);
	ret = SQLExecDirect(hstmt, sql2, SQL_NTS);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{
		SQLCHAR str1[20], str2[20], str3[20], str4[20];
		//	VC 6.0
		SQLINTEGER len_str1, len_str2, len_str3, len_str4;
		//	SQLLEN len_str1, len_str2, len_str3;
		printf("编号\t姓名\t地址\t年龄\n");
		while (SQLFetch(hstmt) != SQL_NO_DATA)
		{
			//SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1);   //获取第一列数据
			//SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);
			//SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
			//SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);
			printf("%s\t%s\t%s\t%s\n", str1, str2, str3, str4);
		}
	}

	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//释放连接句柄
	SQLFreeHandle(SQL_HANDLE_ENV, henv);//释放环境句柄
	return 0;
}
*/



class Point
{
public:
	double x, y;
	int tolineid;
public:
	Point(int lid, double x, double y) { this->tolineid = lid; this->x = x; this->y = y; };
	~Point() {};
};

class Polyline
{
public:
	int lineid;
	int topolygonid;
public:
	Polyline(int id, int pid) { this->lineid = id; this->topolygonid = pid;};
	~Polyline() {};
};

class Polygon
{
public:
	int polygonid;
public:
	Polygon(int id) { this->polygonid = id;};
	~Polygon() {};
};

class Rectangle 
{
public:
	double pointx, pointy, width, height;
public:
	Rectangle(double x, double y, double w, double h) { this->pointx = x; this->pointy = y; this->width = w; this->height = h; };
	~Rectangle() {};
};

class Fanshape
{
public:
	double pointx, pointy, width, height;
	int startangle, spanangle;
public:
	Fanshape(double x, double y, double w, double h, int angle1, int angle2) { this->pointx = x; this->pointy = y; this->width = w; this->height = h; this->startangle = angle1; this->spanangle = angle2; };
	~Fanshape() {};
};

class Circle
{
public:
	double centerx, centery, radius;
public:
	Circle(double centerx, double centery, double radius) { this->centerx = centerx; this->centery = centery; this->radius = radius; };
	~Circle() {};
};

class Text
{
public:
	int textid;
	string content;
};

class Picture
{
public:
	int picid, size;
};

int main()
{
	Point P1(1, 5.0, 7.0);
	Point P2(1, 7.0, 9.0);
	Point P3(2, 4.5, 8.2);
	Point P4(2, 9.9, 4.3);
	Polyline Line1(1, 1);
	Polyline Line2(2, 1);
	Polygon Surface1(1);
	ofstream outfile("E:\\学习\\面向对象课设\\data.txt", ios::app);
	outfile << "以下为新输出内容：" << endl;
	outfile << "Point" << endl << P1.tolineid << " " << P1.x << " " << P1.y << endl;
	outfile << "Point" << endl << P2.tolineid << " " << P2.x << " " << P2.y << endl;
	outfile << "Point" << endl << P3.tolineid << " " << P3.x << " " << P3.y << endl;
	outfile << "Point" << endl << P4.tolineid << " " << P4.x << " " << P4.y << endl;
	outfile << "Polyline" << endl << Line1.topolygonid << " " << Line1.lineid << endl;
	outfile << "Polyline" << endl << Line2.topolygonid << " " << Line2.lineid << endl;
	outfile << "Polygon" << endl << Surface1.polygonid << endl;
	outfile.close();
}
