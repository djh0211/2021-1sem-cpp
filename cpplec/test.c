//
//  test.c
//  cpplec
//
//  Created by 하동준 on 2021/03/29.
//

#include <stdio.h>

int main() {
    double width;
    double hight;
    double area;
    double circumference;

    printf("가로,세로길이를 입력하시오. :");
    scanf("%f",&hight);
    area = hight*hight;
//    circumference = 2 * (width + hight);
    printf("사각형의 넓이는?:%f",area);
    //printf("사각형의 둘레는?:%f",circumference);
    return 0;

}
