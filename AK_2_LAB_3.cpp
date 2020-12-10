#include <map>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>


int main(int argc, char *argv[]) {
	int rez = 0;
	map <string, bool> used;
	
	 bool flag[] = {0, 0, 0};

	const char* short_opts = "l::hv::"; 
	const struct option long_opts[] = 
	{ 
		{ "LIST", optional_argument, NULL, 'l' },
		{ "HELP", no_argument, NULL, 'h' },
		{ "VALUE", optional_argument, NULL, 'v' },
		{ "VERSION", optional_argument, NULL, 'V'}
		{ NULL, 0, NULL, 0 }
	};

	int rez;

	int OP_IND = -1;
	const char* BART_OP = "hlvV::";
	 printf("AKLAB3\n");


	while ((rez = getopt_long(argc, argv, BART_OP, long_options, &OP_IND)) != -1) 
	{
		switch (rez) {case 'h': {
			if (used["h"] == false) {
				printf("ARGUMENT: Help\n");
				used["h"] = true;
				break;}

			break;}


           case 'Z': {
			if (used["s"] == false) {
				printf("testval\n");
				used["s"] = true;
				break;}
			break;}


		case 'l': {
			if (used["l"] == false) {
				printf("ARGUMENT: List\n");
				used["l"] = true;
				break;}
			break;}

		case 'v': {
			if (used["v"] == false) {
				printf("ARGUMENT: Version\n");
				used["v"] = true;
				break;}

			break;}
		
		
		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("ARGUMENT: Value\n");
					used["V"] = true;}
				else
				{printf("ARGUMENT: %s Value\n", optarg);
				used["V"] = true;}

				break;}
			break;}
		case '?': default: {
			printf("unknown\n", rez);
			break;}
		};
		OP_IND = -1;
	};
};