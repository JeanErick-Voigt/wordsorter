#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//		char words[100][20];
//		char **words;
//

int reverse(const void *a, const void *b);
int cmp(const void *pa, const void* pb);
int main(int argc, char ** argv)
{
	char options[10];
	char word[100];
	char temp[20];
	char words[100][20];
	int y;
	char line[100];
	char *p;
	int i, count = 0;
	FILE *fp2;
	FILE *fp;
	FILE *fp1;
	char filename[] = "temp_file.txt";
	fp1 = fopen(filename, "w+");
	fp2 = fopen(filename, "r+");
	int flags = 0;
	for(i = 1; i < argc; i++){
		char c = argv[i][0];
		char banner = argv[i][1];
		if(c == '-'){
			printf("Test");
			flags++;
			options[i-1] = banner;
		}else{
			options[i] = '\0';
		}
	}
	if(flags == 0){
		int input = 0;
		print("Enter words to be sorted or quit to exit");
		while(1){
			 fgets(line, 20, stdin);
			if(line == "quit")
				break;
			char container[20][20];  
			container[input++] =  line;
		}
		for(int z = 0; z < count; z++){
			for(int j = z + 1; j < count; j++){
				if(strcmp(words[z], words[j]) > 0){
					strcpy(temp, words[z]);
					strcpy(words[z], words[j]);
					strcpy(words[j], temp);
				}
			}
		}
	}
	for(int files = flags + 1; files <  argc; files++){
			fp = fopen(argv[files], "r");
			printf("%s\n", argv[files]);
		while(fgets(line, 20, fp) != NULL){
			line[strlen(line) - 1] = '\0';
			p = strtok(line, " \n");
			while(p != NULL){
				fprintf(fp1, "%s\n", p);
					count++;
				p = strtok(NULL, " \n");
			}
		}
	}
	rewind(fp1);
	fclose(fp);
	i = 0;
	fclose(fp1);
	while(fgets(words[i++], 20, fp2));
	fclose(fp2);
	printf("This is count %d", count);
	for(i = 0; i < strlen(options); i++){ 
		if(options[i] = 'a'){
			for(int z = 0; z < count - 1; z++){
				for(int j = z+1; j < count; j++){
					if(strcmp(words[z], words[j]) > 0){
						strcpy(temp, words[z]);
						strcpy(words[z], words[j]);
						strcpy(words[j], temp);
					}
				}
			}
	}
	for(int z = 0; z < count; z++){
		printf("THIS IS word %s", words[z]);
	}
}






int reverse(const void *a, const void * b)
{
	const char *pa = *(const char **)a;
	const char *pb = *(const char**)b;
	return(pb - pa);
}

int cmp ( const void * pa, const void *pb)
{
	return strcmp(*((char**)pa), *((char**)pb));
}



