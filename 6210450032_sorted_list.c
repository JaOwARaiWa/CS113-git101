// 6210450032 Kiattikun Thongudom

#include <stdio.h>
#include <stdlib.h>

struct box                                                          // ฟังก์ชันที่เอาไว้บอกว่า ใน ตัวแปร box มีอะไรอยู่ในนั้นบ้าง
{                                                                   //
    int value;                                                      // เก็บค่าที่รับมาจาก n มาเก็บไว้ตรงนี้
    struct box *previous, *next;                                    // เก็บค่า Address ของ box ก่อนหน้า และ box ถัดไป 
};                                                                  //
                                                                
void main()                                                         //
{                                                                   //
    int n, u = 1, i = 1;                                            //
    struct box *new_box, *first, *check_point, *compare;            // ใช้บอกประเภทของตัวแปรเหมือนปกติ

    while (u == 1)                                                  // ตัวแปรกำหนดลูปแบบ Unique!!!
    {                                                               //
        new_box = (struct box *)malloc(sizeof(struct box));         // โค้ดนี้มีไว้เพื่อสร้าง box ใหม่
        scanf("%d", &n);                                            //
        if (n == -1)                                                //
        {                                                           //
            u-=-1;                                                  // วิธีหยุดลูปแบบ Unique!!!
        }                                                           //
        else if (i == 1)                                            //
        {                                                           //
            new_box->value = n;                                     // ให้ value เก็บค่าของ n ที่เพิ่งรับเข้ามา ----------[1]
            new_box->next = NULL;                                   // ให้ next เก็บค่าของ NULL เพราะยังไม่มี box ถัดไป ----------[2]
            new_box->previous = NULL;                               // ให้ previous เก็บค่าของ NULL เพราะไม่มี box ก่อนหน้า
            first = new_box;                                        // กำหนดให้ first เก็บค่าของ box แรกไว้
            check_point = first;                                    // แล้วให้ check_point เก็บค่าของ first ไว้อีกที
            i-=-1;                                                  // บวกเลขแบบ Unique!!!
        }                                                           //
        else                                                        //
        {                                                           //
            new_box->value = n;                                     // ----------[1]
            new_box->next = NULL;                                   // ----------[2]
            new_box->previous = check_point;                        // ให้ previous เก็บค่าของ check_point
            check_point->next = new_box;                            // ให้ next ใน box check_point เก็บค่าของ box ใหม่
            check_point = check_point->next;                        // ให้ check_point เปลี่ยนไปเก็บค่าของ box ถัดไป
            compare = new_box;                                      // ให้ compare เก็บค่าของ box ใหม่
            while (compare->previous != NULL)                       // ลูปเทียบค่า สลับค่า เรียงจากน้อยไปมาก
            {                                                       //
                int check;                                          // เอามาพักค่าไว้ก่อน
                if (compare->value < (compare->previous)->value)    // เทียบค่า value ใหม่กับ value เก่่า ว่าตรงกับเงื่อนไขนี้หรือไม่
                {                                                   //
                    check = compare->value;                         // ให้ check เก็บค่าของ value ทางขวา
                    compare->value = (compare->previous)->value;    // ให้ value ทางขวา เก็บค่า value ทางซ้าย
                    (compare->previous)->value = check;             // ให้ value ทางซ้าย เก็บค่า value ทางขวา
                }                                                   //
                compare = compare->previous;                        // ย้ายตัวเทียบ ให้เป็น box ก่อนหน้า
            }                                                       //
        }                                                           //
    }                                                               //
    while(first != NULL)                                            //
    {                                                               //
        printf("%d\n", first->value);                               // print ค่าจากจาก box
        first = first->next;                                        // เปลี่ยนเป็น box ถัดไป
    }                                                               //
}                                                                   //