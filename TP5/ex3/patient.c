#include "patient.h"

void displayPatient(Patient *patient)
{
	printf("ID : %d\n", patient->id);
	printf("Waiting time : %d\n", patient->waitingTime);
	printf("Examination time : %d\n\n", patient->examinationTime);
}