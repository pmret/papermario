.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800478C0
/* 22CC0 800478C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 22CC4 800478C4 00041040 */  sll       $v0, $a0, 1
/* 22CC8 800478C8 00441021 */  addu      $v0, $v0, $a0
/* 22CCC 800478CC 00021080 */  sll       $v0, $v0, 2
/* 22CD0 800478D0 00441023 */  subu      $v0, $v0, $a0
/* 22CD4 800478D4 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22CD8 800478D8 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22CDC 800478DC 00021100 */  sll       $v0, $v0, 4
/* 22CE0 800478E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 22CE4 800478E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 22CE8 800478E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 22CEC 800478EC 00628821 */  addu      $s1, $v1, $v0
/* 22CF0 800478F0 2403FFBF */  addiu     $v1, $zero, -0x41
/* 22CF4 800478F4 8E220000 */  lw        $v0, ($s1)
/* 22CF8 800478F8 82240078 */  lb        $a0, 0x78($s1)
/* 22CFC 800478FC 00431024 */  and       $v0, $v0, $v1
/* 22D00 80047900 1480000E */  bnez      $a0, .L8004793C
/* 22D04 80047904 AE220000 */   sw       $v0, ($s1)
/* 22D08 80047908 3C048010 */  lui       $a0, %hi(D_801071AC)
/* 22D0C 8004790C 248471AC */  addiu     $a0, $a0, %lo(D_801071AC)
/* 22D10 80047910 24020001 */  addiu     $v0, $zero, 1
/* 22D14 80047914 0C051955 */  jal       func_80146554
/* 22D18 80047918 A2220078 */   sb       $v0, 0x78($s1)
/* 22D1C 8004791C 0040802D */  daddu     $s0, $v0, $zero
/* 22D20 80047920 0200202D */  daddu     $a0, $s0, $zero
/* 22D24 80047924 0C0526AC */  jal       func_80149AB0
/* 22D28 80047928 24050002 */   addiu    $a1, $zero, 2
/* 22D2C 8004792C 0200202D */  daddu     $a0, $s0, $zero
/* 22D30 80047930 0C0526AC */  jal       func_80149AB0
/* 22D34 80047934 24050080 */   addiu    $a1, $zero, 0x80
/* 22D38 80047938 AE30007C */  sw        $s0, 0x7c($s1)
.L8004793C:
/* 22D3C 8004793C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 22D40 80047940 8FB10014 */  lw        $s1, 0x14($sp)
/* 22D44 80047944 8FB00010 */  lw        $s0, 0x10($sp)
/* 22D48 80047948 03E00008 */  jr        $ra
/* 22D4C 8004794C 27BD0020 */   addiu    $sp, $sp, 0x20
