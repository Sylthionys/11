#include <stdio.h>
#include <string.h>

#define SIZE 50

// 定义结构体，用于存储学生信息
typedef struct {
    int id;             // 学号
    char name[50];      // 姓名
    char gender[10];    // 性别
    float math;         // 数学成绩
    float c;            // C语言成绩
    float database;     // 数据库成绩
} Student;

int main() {
    Student students[SIZE]; // 定义一个长度为50的结构体数组
    int n = 3;              // 实际录入的学生数量
    float totalC = 0;       // 存储C语言成绩总和
    float highest = 0, lowest = 1000; // 存储最高、最低总分
    int highestIndex = 0, lowestIndex = 0; // 存储最高、最低总分对应的索引

    // 通过键盘录入3个学生的信息
    printf("请输入%d位同学的信息：学号 姓名 性别 数学成绩 C语言成绩 数据库成绩\n", n);
    for (int i = 0; i < n; i++) {
        printf("第%d位同学：", i + 1);
        scanf("%d %s %s %f %f %f", 
              &students[i].id, 
              students[i].name, 
              students[i].gender, 
              &students[i].math, 
              &students[i].c, 
              &students[i].database);
        totalC += students[i].c; // 累加C语言成绩
    }

    // 遍历学生信息并输出，同时计算最高、最低总分
    printf("\n学生信息如下：\n");
    for (int i = 0; i < n; i++) {
        float total = students[i].math + students[i].c + students[i].database; // 总分
        printf("学号: %d, 姓名: %s, 性别: %s, 数学: %.2f, C语言: %.2f, 数据库: %.2f, 总分: %.2f\n",
               students[i].id, students[i].name, students[i].gender,
               students[i].math, students[i].c, students[i].database, total);
        // 更新最高、最低总分
        if (total > highest) {
            highest = total;
            highestIndex = i;
        }
        if (total < lowest) {
            lowest = total;
            lowestIndex = i;
        }
    }

    // 输出总分最高和最低的学生信息
    printf("\n总分最高的学生信息:\n");
    printf("学号: %d, 姓名: %s, 性别: %s, 数学: %.2f, C语言: %.2f, 数据库: %.2f, 总分: %.2f\n",
           students[highestIndex].id, students[highestIndex].name, students[highestIndex].gender,
           students[highestIndex].math, students[highestIndex].c, students[highestIndex].database,
           highest);

    printf("\n总分最低的学生信息:\n");
    printf("学号: %d, 姓名: %s, 性别: %s, 数学: %.2f, C语言: %.2f, 数据库: %.2f, 总分: %.2f\n",
           students[lowestIndex].id, students[lowestIndex].name, students[lowestIndex].gender,
           students[lowestIndex].math, students[lowestIndex].c, students[lowestIndex].database,
           lowest);

    // 计算并输出C语言平均成绩
    printf("\nC语言平均成绩: %.2f\n", totalC / n);

    return 0;
}
