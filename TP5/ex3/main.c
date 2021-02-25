#include "queue.h"
#include <time.h>
#include <string.h>

#define MAX_TIME 30
#define MIN_TIME 5
#define TOTAL_PATIENTS 10

Queue *wait;
Queue *examination;

Patient *patients[TOTAL_PATIENTS];

enum mode
{
	NORMAL,
	INCREASE,
	DECREASE
};

int randomDuration()
{
	return rand() % (MAX_TIME - MIN_TIME) + MIN_TIME;
}

void setup()
{
	for (unsigned int i = 0; i < TOTAL_PATIENTS; i++)
	{
		int time = randomDuration();

		Patient *patient = (Patient *)calloc(1, sizeof(Patient));
		patient->id = i;
		patient->waitingTime = time;
		patient->examinationTime = 0;
		patient->isExamined = false;
		patient->totalWaitingTime = time;
		patient->totalExaminationTime = 0;

		patients[i] = patient;
	}
}

void bubbleSortIncrease()
{
	for (unsigned int i = 0; i < TOTAL_PATIENTS - 1; i++)
	{
		for (unsigned int j = 0; j < TOTAL_PATIENTS - i - 1; j++)
		{
			if (patients[j]->waitingTime < patients[j+1]->waitingTime)
			{
				Patient temp = *patients[j]; 
				*patients[j] = *patients[j+1]; 
				*patients[j+1] = temp; 
			}
		}
	}		
}

void bubbleSortDecrease()
{
	for (unsigned int i = 0; i < TOTAL_PATIENTS - 1; i++)
	{
		for (unsigned int j = 0; j < TOTAL_PATIENTS - i - 1; j++)
		{
			if (patients[j]->waitingTime > patients[j+1]->waitingTime)
			{
				Patient temp = *patients[j]; 
				*patients[j] = *patients[j+1]; 
				*patients[j+1] = temp; 
			}
		}
	}		
}

void processWaitingRoom()
{
	if (wait == NULL)
		return;

	Patient *patient = wait->val;

	if (patient->waitingTime == 0)
	{
		if (!patient->isExamined)
		{
			int time = randomDuration();

			patient->examinationTime = time;
			patient->totalExaminationTime += time;
			push(&examination, patient);
		}

		pop(&wait);
	}
	else patient->waitingTime--;
}

void processExaminationRoom()
{
	if (examination == NULL)
		return;

	Patient *patient = examination->val;

	if (patient->examinationTime == 0)
	{
		int time = randomDuration();

		Patient *patient = pop(&examination);
		patient->isExamined = true;
		patient->waitingTime = time;
		patient->totalWaitingTime += time;
		push(&wait, patient);
	}
	else patient->examinationTime--;
}

void reset()
{
	memset(patients, 0, TOTAL_PATIENTS * sizeof(Patient));
}

void process(enum mode mode)
{
	bool running = true;

	reset();
	setup();

	switch(mode)
	{
		case INCREASE:
			bubbleSortIncrease();
			break;
		case DECREASE:
			bubbleSortDecrease();
			break;
		case NORMAL:
		default: 
			break;
	}

	int iteration = 0;

	for(unsigned int i = 0; i < TOTAL_PATIENTS; i++)
	{
		push(&wait, patients[i]);
	}

	while (running) // each iteration egal one minute elapsed
	{
		processWaitingRoom();
		processExaminationRoom();

		iteration++;

		if (wait == NULL && examination == NULL) //stoppping condition, this doctor is a good doctor
			running = false;
	}

	printf("Total time : %d minutes\n", iteration);

	unsigned int averageWaitTime = 0;
	unsigned int averageExaminationTime = 0;

	for(unsigned int i = 0; i < TOTAL_PATIENTS; i++)
	{
		Patient *patient = patients[i];
		averageWaitTime += patient->totalWaitingTime;
		averageExaminationTime += patient->totalExaminationTime;
	}

	averageWaitTime /= TOTAL_PATIENTS;
	averageExaminationTime /= TOTAL_PATIENTS;

	printf("Average waiting time : %d minutes\n", averageWaitTime);
	printf("Average examination time : %d minutes\n", averageExaminationTime);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	printf("Mode normal :\n");
	process(NORMAL);
	printf("\nMode increase :\n");
	process(INCREASE);
	printf("\nMode decrease :\n");
	process(DECREASE);

	freeQueue(wait);
	freeQueue(examination);

	return 0;
}