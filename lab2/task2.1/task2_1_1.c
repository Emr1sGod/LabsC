#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Rus");
	int choice, lengthEdge = 0;
	while (1) {
		system("cls");
		printf("1. ���� ����� ����� ���������.\n2. ����� ����� ����� ���� ����� ���������.\n3. ����� ������� ���� ������ ���������.\n4. ����� ������ ���������.\n5. ����� ������ ���������.\n6. ����� ������� ���������� ����.\n7. ���������� � ������ � ������ ���������.\n8. ����� �� ���������.\n\n�������� �����: ");
		if (scanf("%d", &choice)) {
			switch (choice) {
			case 1:
				system("cls");
					printf("������� ����� ����� ���������: ");
					inputLengthEdge(&lengthEdge);
					break;
			case 2:
				system("cls");
					if (lengthEdge == 0) {
						printf("������ ������� ����� ����� ���������.");
							Sleep(2500);
						break;
					}
					else {
						printf("����� ����� ���� ���� ���������: %.1f", outputEdgeSum(&lengthEdge));
						Sleep(2500);
						break;
					}
			case 3:
				system("cls");
				if (lengthEdge == 0) {
					printf("������ ������� ����� ����� ���������.");
					Sleep(2500);
					break;
				}
				else {
					printf("������� ���� ������ ���������: %.1f", outputAreaFace(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 4:
				system("cls");
				if (lengthEdge == 0) {
					printf("������ ������� ����� ����� ���������.");
					Sleep(2500);
					break;
				}
				else {
					printf("����� ���������: %.1f", outputVolumeTetrahedron(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 5:
				system("cls");
				if (lengthEdge == 0) {
					printf("������ ������� ����� ����� ���������.");
					Sleep(2500);
					break;
				}
				else {
					printf("������ ���������: %.1f", outputLengthHeight(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 6:
				system("cls");
				if (lengthEdge == 0) {
					printf("������ ������� ����� ����� ���������.");
					Sleep(2500);
					break;
				}
				else {
					printf("������ ���������� ����: %.1f", outputRadiusInscribedSphere(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 7:
				system("cls");
				printf("���������� � ������ � ������ ���������:\n");
				outputInfo(&lengthEdge);
				Sleep(5000);
				break;
			case 8:
				end();
			default:
				system("cls");
				printf("������ � ������ ������");
				Sleep(2500);
			}
		}
		else {
			while (getchar() != '\n');
			system("cls");
			printf("������������ ����");
			Sleep(2500);
		}
	}
}