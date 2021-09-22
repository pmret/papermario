.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80110F10
/* A7610 80110F10 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A7614 80110F14 AFB3001C */  sw        $s3, 0x1c($sp)
/* A7618 80110F18 0000982D */  daddu     $s3, $zero, $zero
/* A761C 80110F1C AFB50024 */  sw        $s5, 0x24($sp)
/* A7620 80110F20 0260A82D */  daddu     $s5, $s3, $zero
/* A7624 80110F24 AFB60028 */  sw        $s6, 0x28($sp)
/* A7628 80110F28 3C168015 */  lui       $s6, %hi(D_80151300)
/* A762C 80110F2C 26D61300 */  addiu     $s6, $s6, %lo(D_80151300)
/* A7630 80110F30 AFB7002C */  sw        $s7, 0x2c($sp)
/* A7634 80110F34 3C178015 */  lui       $s7, %hi(gEntityHeapBase)
/* A7638 80110F38 26F712C4 */  addiu     $s7, $s7, %lo(gEntityHeapBase)
/* A763C 80110F3C AFB40020 */  sw        $s4, 0x20($sp)
/* A7640 80110F40 3C148015 */  lui       $s4, %hi(wStaticEntityData)
/* A7644 80110F44 26941668 */  addiu     $s4, $s4, %lo(wStaticEntityData)
/* A7648 80110F48 AFBF0030 */  sw        $ra, 0x30($sp)
/* A764C 80110F4C AFB20018 */  sw        $s2, 0x18($sp)
/* A7650 80110F50 AFB10014 */  sw        $s1, 0x14($sp)
/* A7654 80110F54 AFB00010 */  sw        $s0, 0x10($sp)
.L80110F58:
/* A7658 80110F58 8E910000 */  lw        $s1, ($s4)
/* A765C 80110F5C 1220004A */  beqz      $s1, .L80111088
/* A7660 80110F60 00000000 */   nop
/* A7664 80110F64 96220000 */  lhu       $v0, ($s1)
/* A7668 80110F68 30420008 */  andi      $v0, $v0, 8
/* A766C 80110F6C 1440000F */  bnez      $v0, .L80110FAC
/* A7670 80110F70 24030043 */   addiu    $v1, $zero, 0x43
/* A7674 80110F74 8E25001C */  lw        $a1, 0x1c($s1)
/* A7678 80110F78 8E240018 */  lw        $a0, 0x18($s1)
/* A767C 80110F7C 3C038015 */  lui       $v1, %hi(gEntityHeapBase)
/* A7680 80110F80 8C6312C4 */  lw        $v1, %lo(gEntityHeapBase)($v1)
/* A7684 80110F84 00A41023 */  subu      $v0, $a1, $a0
/* A7688 80110F88 00023083 */  sra       $a2, $v0, 2
/* A768C 80110F8C 00131080 */  sll       $v0, $s3, 2
/* A7690 80110F90 00621823 */  subu      $v1, $v1, $v0
/* A7694 80110F94 00063080 */  sll       $a2, $a2, 2
/* A7698 80110F98 0C00A5CF */  jal       dma_copy
/* A769C 80110F9C 00663023 */   subu     $a2, $v1, $a2
/* A76A0 80110FA0 00021082 */  srl       $v0, $v0, 2
/* A76A4 80110FA4 0804441E */  j         .L80111078
/* A76A8 80110FA8 02629821 */   addu     $s3, $s3, $v0
.L80110FAC:
/* A76AC 80110FAC 92220020 */  lbu       $v0, 0x20($s1)
/* A76B0 80110FB0 14430012 */  bne       $v0, $v1, .L80110FFC
/* A76B4 80110FB4 8E300018 */   lw       $s0, 0x18($s1)
/* A76B8 80110FB8 8ED20000 */  lw        $s2, ($s6)
/* A76BC 80110FBC 8E040000 */  lw        $a0, ($s0)
/* A76C0 80110FC0 8E050004 */  lw        $a1, 4($s0)
/* A76C4 80110FC4 0C00A5CF */  jal       dma_copy
/* A76C8 80110FC8 0240302D */   daddu    $a2, $s2, $zero
/* A76CC 80110FCC 8E040008 */  lw        $a0, 8($s0)
/* A76D0 80110FD0 8E05000C */  lw        $a1, 0xc($s0)
/* A76D4 80110FD4 00028082 */  srl       $s0, $v0, 2
/* A76D8 80110FD8 8EC60000 */  lw        $a2, ($s6)
/* A76DC 80110FDC 00108080 */  sll       $s0, $s0, 2
/* A76E0 80110FE0 0C00A5CF */  jal       dma_copy
/* A76E4 80110FE4 00D03021 */   addu     $a2, $a2, $s0
/* A76E8 80110FE8 0220202D */  daddu     $a0, $s1, $zero
/* A76EC 80110FEC 8EC50000 */  lw        $a1, ($s6)
/* A76F0 80110FF0 0240302D */  daddu     $a2, $s2, $zero
/* A76F4 80110FF4 0804441C */  j         .L80111070
/* A76F8 80110FF8 00B02821 */   addu     $a1, $a1, $s0
.L80110FFC:
/* A76FC 80110FFC 8E050004 */  lw        $a1, 4($s0)
/* A7700 80111000 8E040000 */  lw        $a0, ($s0)
/* A7704 80111004 8EE30000 */  lw        $v1, ($s7)
/* A7708 80111008 00A41023 */  subu      $v0, $a1, $a0
/* A770C 8011100C 00023083 */  sra       $a2, $v0, 2
/* A7710 80111010 00131080 */  sll       $v0, $s3, 2
/* A7714 80111014 00621823 */  subu      $v1, $v1, $v0
/* A7718 80111018 00061080 */  sll       $v0, $a2, 2
/* A771C 8011101C 00629023 */  subu      $s2, $v1, $v0
/* A7720 80111020 0C00A5CF */  jal       dma_copy
/* A7724 80111024 0240302D */   daddu    $a2, $s2, $zero
/* A7728 80111028 00021082 */  srl       $v0, $v0, 2
/* A772C 8011102C 02629821 */  addu      $s3, $s3, $v0
/* A7730 80111030 8E05000C */  lw        $a1, 0xc($s0)
/* A7734 80111034 8E040008 */  lw        $a0, 8($s0)
/* A7738 80111038 8EE30000 */  lw        $v1, ($s7)
/* A773C 8011103C 00A41023 */  subu      $v0, $a1, $a0
/* A7740 80111040 00023083 */  sra       $a2, $v0, 2
/* A7744 80111044 00131080 */  sll       $v0, $s3, 2
/* A7748 80111048 00621823 */  subu      $v1, $v1, $v0
/* A774C 8011104C 00061080 */  sll       $v0, $a2, 2
/* A7750 80111050 00628023 */  subu      $s0, $v1, $v0
/* A7754 80111054 0C00A5CF */  jal       dma_copy
/* A7758 80111058 0200302D */   daddu    $a2, $s0, $zero
/* A775C 8011105C 00021082 */  srl       $v0, $v0, 2
/* A7760 80111060 02629821 */  addu      $s3, $s3, $v0
/* A7764 80111064 0220202D */  daddu     $a0, $s1, $zero
/* A7768 80111068 0200282D */  daddu     $a1, $s0, $zero
/* A776C 8011106C 0240302D */  daddu     $a2, $s2, $zero
.L80111070:
/* A7770 80111070 0C04442D */  jal       entity_anim_make_vertex_pointers
/* A7774 80111074 00000000 */   nop
.L80111078:
/* A7778 80111078 26B50001 */  addiu     $s5, $s5, 1
/* A777C 8011107C 2AA2001E */  slti      $v0, $s5, 0x1e
/* A7780 80111080 1440FFB5 */  bnez      $v0, .L80110F58
/* A7784 80111084 26940004 */   addiu    $s4, $s4, 4
.L80111088:
/* A7788 80111088 8FBF0030 */  lw        $ra, 0x30($sp)
/* A778C 8011108C 8FB7002C */  lw        $s7, 0x2c($sp)
/* A7790 80111090 8FB60028 */  lw        $s6, 0x28($sp)
/* A7794 80111094 8FB50024 */  lw        $s5, 0x24($sp)
/* A7798 80111098 8FB40020 */  lw        $s4, 0x20($sp)
/* A779C 8011109C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A77A0 801110A0 8FB20018 */  lw        $s2, 0x18($sp)
/* A77A4 801110A4 8FB10014 */  lw        $s1, 0x14($sp)
/* A77A8 801110A8 8FB00010 */  lw        $s0, 0x10($sp)
/* A77AC 801110AC 03E00008 */  jr        $ra
/* A77B0 801110B0 27BD0038 */   addiu    $sp, $sp, 0x38
