extern "C"
{
#define new tripouille
#include "get_next_line.h"
#undef new
}

#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sigsegv.hpp"
#include "check.hpp"
#include "gnl.hpp"

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv); int fd;
	cout << FG_LGRAY << "[BUFFER_SIZE = " << BUFFER_SIZE << "]: " << ENDL;
	cout << FG_LGRAY << "Invalid fd: "; cout.flush();
	TEST(/* 1 */ gnl(1000, -1, NULL);
		 /* 2 */ gnl(-1, -1, NULL);) cout << ENDL;

	cout << FG_LGRAY << "files/empty: "; cout.flush();
	fd = open("files/empty", O_RDWR);
	TEST(/* 1 */ gnl(fd, 0, "");
		 /* 2 */ gnl(fd, 0, "");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/nl: "; cout.flush();
	fd = open("files/nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "");
		 /* 2 */ gnl(fd, 0, "");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/41_no_nl: "; cout.flush();
	fd = open("files/41_no_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 0, "01234567890123456789012345678901234567890");
		 /* 2 */ gnl(fd, 0, "");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/41_with_nl: "; cout.flush();
	fd = open("files/41_with_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "0123456789012345678901234567890123456789");
		 /* 2 */ gnl(fd, 0, "0");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/42_no_nl: "; cout.flush();
	fd = open("files/42_no_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 0, "012345678901234567890123456789012345678901");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/42_with_nl: "; cout.flush();
	fd = open("files/42_with_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "01234567890123456789012345678901234567890");
	if (BUFFER_SIZE == 42) {
		 /* 2 */ char c = 0; read(fd, &c, 1); check(c == '1'); ++iTest;
	     /* 3 */ gnl(fd, 0, "");}
	else {
		 /* 2 */ gnl(fd, 1, "1");
		 /* 3 */ gnl(fd, 0, "");})
	iTest = 1; cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/43_no_nl: "; cout.flush();
	fd = open("files/43_no_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 0, "0123456789012345678901234567890123456789012");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/43_with_nl: "; cout.flush();
	fd = open("files/43_with_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "012345678901234567890123456789012345678901");
		 /* 2 */ gnl(fd, 1, "2");
		 /* 3 */ gnl(fd, 0, "");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/multiple_nlx5: "; cout.flush();
	fd = open("files/multiple_nlx5", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "");
		 /* 2 */ gnl(fd, 1, "");
		 /* 3 */ gnl(fd, 1, "");
		 /* 4 */ gnl(fd, 1, "");
		 /* 5 */ gnl(fd, 1, "");
		 /* 6 */ gnl(fd, 0, "");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/multiple_line_no_nl: "; cout.flush();
	fd = open("files/multiple_line_no_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "01234567890123456789012345678901234567890");
		 /* 2 */ gnl(fd, 1, "987654321098765432109876543210987654321098");
		 /* 3 */ gnl(fd, 1, "0123456789012345678901234567890123456789012");
		 /* 4 */ gnl(fd, 1, "987654321098765432109876543210987654321098");
		 /* 5 */ gnl(fd, 0, "01234567890123456789012345678901234567890");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/multiple_line_with_nl: "; cout.flush();
	fd = open("files/multiple_line_with_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "9876543210987654321098765432109876543210");
		 /* 2 */ gnl(fd, 1, "01234567890123456789012345678901234567890");
		 /* 3 */ gnl(fd, 1, "987654321098765432109876543210987654321098");
		 /* 4 */ gnl(fd, 1, "01234567890123456789012345678901234567890");
		 /* 5 */ gnl(fd, 1, "9876543210987654321098765432109876543210");
		 /* 6 */ gnl(fd, 0, "");) cout << ENDL; close(fd);	

	cout << FG_LGRAY << "files/alternate_line_nl_no_nl: "; cout.flush();
	fd = open("files/alternate_line_nl_no_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "98765432109876543210987654321098765432109");
		 /* 1 */ gnl(fd, 1, "");
		 /* 2 */ gnl(fd, 1, "012345678901234567890123456789012345678901");
		 /* 1 */ gnl(fd, 1, "");
		 /* 3 */ gnl(fd, 1, "9876543210987654321098765432109876543210987");
		 /* 1 */ gnl(fd, 1, "");
		 /* 4 */ gnl(fd, 1, "012345678901234567890123456789012345678901");
		 /* 1 */ gnl(fd, 1, "");
		 /* 5 */ gnl(fd, 1, "98765432109876543210987654321098765432109");
		 /* 6 */ gnl(fd, 0, "");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "files/alternate_line_nl_with_nl: "; cout.flush();
	fd = open("files/alternate_line_nl_with_nl", O_RDWR);
	TEST(/* 1 */ gnl(fd, 1, "01234567890123456789012345678901234567890");
		 /* 1 */ gnl(fd, 1, "");
		 /* 2 */ gnl(fd, 1, "987654321098765432109876543210987654321090");
		 /* 1 */ gnl(fd, 1, "");
		 /* 3 */ gnl(fd, 1, "0123456789012345678901234567890123456789012");
		 /* 1 */ gnl(fd, 1, "");
		 /* 4 */ gnl(fd, 1, "987654321098765432109876543210987654321090");
		 /* 1 */ gnl(fd, 1, "");
		 /* 5 */ gnl(fd, 1, "01234567890123456789012345678901234567890");
		 /* 6 */ gnl(fd, 0, "");) cout << ENDL; close(fd);

	cout << FG_LGRAY << "stdin: "; cout.flush();
	fd = open("files/alternate_line_nl_with_nl", O_RDWR);
	TEST(/* 1 */ gnl(0, 1, "01234567890123456789012345678901234567890");
		 /* 1 */ gnl(0, 1, "");
		 /* 2 */ gnl(0, 1, "987654321098765432109876543210987654321090");
		 /* 1 */ gnl(0, 1, "");
		 /* 3 */ gnl(0, 1, "0123456789012345678901234567890123456789012");
		 /* 1 */ gnl(0, 1, "");
		 /* 4 */ gnl(0, 1, "987654321098765432109876543210987654321090");
		 /* 1 */ gnl(0, 1, "");
		 /* 5 */ gnl(0, 1, "01234567890123456789012345678901234567890");
		 /* 6 */ gnl(0, 0, "");) cout << ENDL; close(fd);
	return (0);
}