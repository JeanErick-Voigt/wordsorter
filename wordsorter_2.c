#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//		char words[100][20];
//		char **words;
//

char ** array_size(char filename[]);
void put_word(char ** array, FILE *fpt);

int main(int argc, char ** argv)
{
	char line[100]; 
	char *p;
	int i;
	FILE *fp2;
	FILE *fp;
	FILE *fp1; 
	char filename[] = "temp_file.txt";
	//fp1 = fopen(filename, "w+");
	for(i = 1; i < argc; i++){
		fp1 = fopen(filename,"a+");
		fp = fopen(argv[i], "r");
		fp2 = fopen(filename, "r+");
		printf("%s\n", argv[i]);
		while(fgets(line, 100, fp) != NULL){
			p = strtok(line, " ");
			while(p != NULL){
				fprintf(fp1, "%s\n", p);
				p = strtok(NULL, " \n");
			}
		}
		fclose(fp);
		fclose(fp1);
	}  // end of for loop

	char ** new_array = array_size(filename);
	//new_array[0] = "BOB";
	//printf("THIS IS STRING index %s\n", string[0]);
	//if(new_array){
	//	printf("malloc succesfule ---> %s\n", new_array[0]);
//	}
	//printf("This is array\n");
	//new_array = put_word(array, fp2);
	//rewind(fp2);
	put_word(new_array, fp2);
	rewind(fp2);
	printf("NEW ARRAY sub 0 --> %s\n", new_array[0]);
	//while(*new_array){
	//	printf("%s\n", new_array[i]);
	//}
}


char ** array_size(char filename[])
{
	char ** string;
	FILE *fp = fopen(filename, "r");
	char line[50];
	int count = 0;
	int sum = 0;
	while(fgets(line, 50, fp) != NULL){
		count++;
		//printf("THIS IS COUNT %d \n", count);
		line[(strlen(line) - 1)] = '\0';
		//printf("CHECK THIS PRINT STATEMENT %s\n", line);
		//printf("This is size of char ---> %lu\n", sizeof(char));
		//printf("THIS IS LENGTH OF LINE--> %lu\n", strlen(line));
		//sum += (strlen(line) * sizeof(char)+ 1);
		//printf("SUM --> %d\n", sum;
	}
	rewind(fp);
	string = (char **) malloc(count);
	for(int i = 0; i < count; i ++){
		fgets(line, 100, fp);
		string[i] = (char *) malloc(strlen(line));
	}
	rewind(fp);
	return(string);
}




void put_word(char **array, FILE *fpt)
{
	rewind(fpt);
	char line[100];
	int count = 0;
	int i;
	while(fgets(line, 100, fpt) != NULL){
		count++;
		printf("LINE COUNT %d", count);
	}
	printf("\n");
	rewind(fpt);
	for(i = 0; i < count; i++){
		fgets(line, 100, fpt);
		//line[strlen(line) - 1] = '\0';
		//printf("This is line---> %s\n", line);
		array[i] = line;  //go back to array[i] if doesnt work
		printf("This is array line--> %s\n", array[i]);

	}
	//array[i] = '\0'; //comment out if doesn't work
	rewind(fpt);

}


