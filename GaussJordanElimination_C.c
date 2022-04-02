#include <stdio.h>
#define MAX 100

float matrix[MAX][MAX];
int rowTotal = 0;
int columnTotal = 0;
char check;

void setMatrix() {
	for (int rowIndex = 0; rowIndex < rowTotal; rowIndex++) { 
		for (int columnIndex = 0; columnIndex < (columnTotal + 1); columnIndex++) {
			scanf("%f", &matrix[rowIndex][columnIndex]);
		}
	}
}

void showMatrix() {
	printf("the matrix is:\n");
	for (int rowIndex = 0; rowIndex < rowTotal; rowIndex++) {
		for (int columnIndex = 0; columnIndex < (columnTotal + 1); columnIndex++) {
			printf("%.2f ", matrix[rowIndex][columnIndex]);
			if (columnIndex == columnTotal) {
				printf("\n");
			}
		}
	}
    printf("-------------------------------------\n");
}

void switchEquation(int rowTotal1, int rowTotal2) {
    for (int columnIndex = 0; columnIndex < (columnTotal + 1); columnIndex++) {
        float temp = matrix[rowTotal1][columnIndex];
        matrix[rowTotal1][columnIndex] = matrix[rowTotal2][columnIndex];
        matrix[rowTotal2][columnIndex] = temp;
    }
}

void GaussJordanCalculate() {
    int rowPointer = 0;
    int columnPointer = 0;
    int rowSwitchTarget = rowPointer + 1;
    while (rowSwitchTarget < rowTotal && (matrix[rowTotal][columnPointer] == 0)) {
        rowSwitchTarget++;
    }
    while (rowPointer < rowTotal && columnPointer < columnTotal) {
        if (matrix[rowPointer][columnPointer] == 0) {
            switchEquation(rowPointer, rowSwitchTarget);
        }

        float divideNum = matrix[rowPointer][columnPointer];
        for (int i = rowPointer; i < (columnTotal + 1); i++) {
            matrix[rowPointer][i] /= divideNum;
        }

        float minusNum = matrix[rowPointer][columnPointer];
        for (int rowIndex = 0; rowIndex < rowTotal; rowIndex++) {
            if (rowIndex == rowPointer) {
                continue;
            }
            float minusMultiplyTimes = matrix[rowIndex][columnPointer] / minusNum;
            for (int i = columnPointer; i < (columnTotal + 1); i++) {
                matrix[rowIndex][i] -= matrix[rowPointer][i] * minusMultiplyTimes;
            }
        }

        rowPointer++;
        columnPointer++;
        while ((rowPointer < rowTotal && columnPointer < columnTotal) && matrix[rowPointer][columnPointer] == 0) {
        columnPointer++;
        }
        showMatrix();
    }
}

int main()
{
	printf("* This is a program of Gauss-Jordan Elimination *\n");
	do {
		printf("please sequentially enter equations/row, variables/column with space : ");
		scanf("%d%d", &rowTotal, &columnTotal);
		printf("this is a matrix of %d * %d\n", rowTotal, columnTotal);
		printf("enter the value of matrix with space:\n");
		setMatrix();
		showMatrix();
		GaussJordanCalculate();
		printf("try again?(enter Y/N)\n");
		scanf(" %c", &check);
	} while ((check == 'Y') || (check == 'y'));
	return 0;
}