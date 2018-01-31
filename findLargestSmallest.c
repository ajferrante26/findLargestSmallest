#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void smallestInt(int *usrList);
void largestInt(int *usrList);

int main(int argc, char *argv[])
{
	int *usrList = (int *)calloc(10, sizeof(int));
	int *sortList = (int *)calloc(10, sizeof(int));

//	I couldn't compare argv[1] to anything to get 
//	the option input, so I ran through some 
//	variables to put it in to optionIn as a char.
	char *cmdIn = argv[1];
	char optionIn;
	char operatorIn;
	operatorIn = cmdIn[0];
	optionIn = cmdIn[1];
//	There's a better way of doing it I think through
//	atoi(), but it was giving me trouble.

	int i;
	for (i=2; i<=11; i++)
		usrList[i-2] = atoi(argv[i]);

	if (operatorIn!='-' && optionIn!='l' && optionIn!='s' && argc!=11)
		printf("USAGE: ./a.out <-l or -s>\n");
	if (optionIn=='s')
		smallestInt(usrList);
	if (optionIn=='l')
		largestInt(usrList);	

	return 0;
}

/////////////////////////////////////////////

void smallestInt(int *usrList)
{
	int tmp,i;
	tmp = usrList[0];

	for (i=0; i<10; i++)
	{
		if (usrList[i]<tmp)
			tmp = usrList[i];
	}

	printf("The smallest integer is %d\n",tmp);
}

////////////////////////////////////////////

void largestInt(int *usrList)
{
	int tmp,i;
	tmp = usrList[0];

	for (i=0; i<10; i++)
	{
		if (usrList[i]>tmp)
			tmp = usrList[i];
	}
	
	printf("The largest integer is %d\n",tmp);
}
