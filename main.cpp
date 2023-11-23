#include <iostream>
#include "checkbitmask.h"
#include <vector>
#include "tree.h"



int main()
{
    /* ЗАДАНИЕ 1.
     *
     * 32-х битная маска считается правильной, если ее двоичное представление
     * содержит непрерывный ряд «1» и следующий за ним ряд «0».
     * Пример “правильных” битовых масок:
     * 11110000000000000000000000000000
     * 11111000000000000000000000000000
     * 11111111111100000000000000000000
     * Пример “неправильных” битовых масок:
     * 10110000000000000000000000001000
     * 01111100000000000000001000000001
     * Задача — разработать функцию проверки правильности битовой маски.
    */

    std::vector<uint32_t> test_val;
    test_val.push_back(0b11110000000000000000000000000000);
    test_val.push_back(0b11111000000000000000000000000000);
    test_val.push_back(0b11111111111100000000000000000000);
    test_val.push_back(0b10110000000000000000000000001000);
    test_val.push_back(0b01111100000000000000001000000001);
    test_val.push_back(0b1 << 31);
    test_val.push_back(1);
    test_val.push_back(0);

    std::cout << "TASK 1 ======================================" << std::endl;
    for (const auto & a : test_val) {
        std::cout << "val = " << convertIntToBinString(a) << ", answer = " << checkBitMask(a) << std::endl;
    }
    std::cout << "=============================================" << std::endl;

    /* ЗАДАНИЕ 2.
     *
     * Есть функция добавления элемента в дерево. Напишите парную к ней функцию
     * удаления элемента из дерева.
     *
     * void insert(node ** tree, int val)
     * {
     *      node *temp = NULL;
     *      if(!(*tree)) {
     *          temp = (node *)malloc(sizeof(node));
     *          temp->left = temp->right = NULL;
     *          temp->data = val;
     *          *tree = temp;
     *          return;
     *      }
     *
     *      if(val < (*tree)->data) {
     *          insert(&(*tree)->left, val);
     *      }
     *      else if(val > (*tree)->data) {
     *          insert(&(*tree)->right, val);
     *      }
     * }
    */

    node ** head;
    head = (node**)malloc(sizeof(*head));
    *head = NULL;

    for (int i = -3; i < 4; i++) {
        insert(head, i);
    }
    printLevelByLevel(*head);

    std::cout << std::endl;

    for (int i = -3; i < 4; i++) {
        deleteNode(head, i);
    }
    printLevelByLevel(*head);

    /* ЗАДАНИЕ 3.
     *
     * Что произошло при исполнении данного кода на языке Ассемблера? Как
     * модифицировать код, чтобы избежать этой проблемы?
     * 10eca968 <Screensaver_Sleep_Activate>:
     * 10eca968 b530 push {r4,r5,lr}
     * 10eca96a 4d13 ldr r5, [$10eca9b8]
     * 10eca96c 1c0c add r4, r1, #0x0
     * 10eca96e 2117 mov r1, #0x17
     * 10eca970 1c28 add r0, r5, #0x0
     * 10eca972 f1a1 bl $1106bbdc
     * 10eca974 f933
     * 10eca976 2000 mov r0, #0x0
     * 10eca978 2117 mov r1, #0x17
     * 10eca97a 6001 str r1, [r0, #0x0]
     * 10eca97c f000 bl $10ecb274
     * 10eca97e fc7a
     * 10eca980 2800 cmp r0, #0x0
     * 10eca982 d116 bne $10eca9b2
     * 10eca984 f1df bl $110aa820
     * 10eca986 ff4c
     * 10eca988 2800 cmp r0, #0x0
     * Dump of registers at crash point:
     * r0 0x00000000 r1 0x00000017 r2 0x00000000 r3 0x00000013
     * r4 0x00000000 r5 0x11b8c0c4 r6 0x00000000 r7 0x11d89560
     * r8 0xffffffff r9 0xffffffff r10 0x00000000 r11 0x00000000
     * r12 0x55555555
     **/

    /*
     * К слжалению, я не могду дать достойный ответ на этот вопрос,
     * поскольку послкедний раз имел дело с ассемблерным кодом в университете 10 лет назад.
     *
     * Хотя, я могу сделать предположение, основанное на исследовании,
     * которое я провел в меру своего понимания.
     *
     * Проблема, на мой взгляд, связана с тем, что регистр r0 содержит значение 0x0.
     * Не реккомедуется хранить значение 0x0 в этом регистре, поскольку это
     * может привести к непредсказуемым результатам.
     * Из-за этого происходит некорректный результат в справнении cmp, что приводит
     * к некорректному вызову bne.
     *
     * К сожалению, моя низкая компетенция не позволяет исправить аозникующую ошибку.
     *
     *
    */


    return 0;
}
