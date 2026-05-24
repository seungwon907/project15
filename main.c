#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackMenu.h"
#pragma warning (disable:4996)

int main() {
    ArrayStack* stack = createArrayStack(10);
    int choice;
    char url[123];

    while (1) {
        printf("\n메뉴:\n");
        printf("1. URL 추가\n");
        printf("2. URL 제거\n");
        printf("3. 스택 확인\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
        case 1:
            printf("URL 입력: ");
            fgets(url, 123, stdin);
            url[strcspn(url, "\n")] = 0; 
            pushArrayStack(stack, strdup(url));
            printf("현재 창: %s\n", peakArrayStack(stack));
            break;
        case 2:
        {
            stackElement removedUrl = popArrayStack(stack);
            if (removedUrl) {
                printf("이탈: %s\n", removedUrl);
                free(removedUrl); 
            }
            else {
                printf("스택이 비어 있습니다.\n");
            }
            printf("현재 창: %s\n", peakArrayStack(stack));
        }
        break;
        case 3:

            printf("현재 창: %s\n", peakArrayStack(stack));
            break;
        case 4:
            destroyArrayStack(stack);
            printf("브라우저가 종료되었습니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}
