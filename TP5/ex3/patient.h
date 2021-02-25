#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct patient
{
	unsigned int id;
	unsigned int waitingTime; //minutes
	unsigned int examinationTime; //minutes
	
	bool isExamined;

	unsigned int totalWaitingTime; //minutes
	unsigned int totalExaminationTime; //minutes
} Patient;

void displayPatient(Patient *);