.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB0_C56EF0
/* C56EF0 80240FB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C56EF4 80240FB4 AFB00010 */  sw        $s0, 0x10($sp)
/* C56EF8 80240FB8 3C108024 */  lui       $s0, %hi(D_802436E0)
/* C56EFC 80240FBC 261036E0 */  addiu     $s0, $s0, %lo(D_802436E0)
/* C56F00 80240FC0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C56F04 80240FC4 AFB10014 */  sw        $s1, 0x14($sp)
/* C56F08 80240FC8 8E020000 */  lw        $v0, ($s0)
/* C56F0C 80240FCC 14400010 */  bnez      $v0, .L80241010
/* C56F10 80240FD0 0080882D */   daddu    $s1, $a0, $zero
/* C56F14 80240FD4 0C00AB39 */  jal       heap_malloc
/* C56F18 80240FD8 24040040 */   addiu    $a0, $zero, 0x40
/* C56F1C 80240FDC AE020000 */  sw        $v0, ($s0)
/* C56F20 80240FE0 0000182D */  daddu     $v1, $zero, $zero
/* C56F24 80240FE4 0040282D */  daddu     $a1, $v0, $zero
/* C56F28 80240FE8 0220202D */  daddu     $a0, $s1, $zero
.L80240FEC:
/* C56F2C 80240FEC 8C820084 */  lw        $v0, 0x84($a0)
/* C56F30 80240FF0 24840004 */  addiu     $a0, $a0, 4
/* C56F34 80240FF4 24630001 */  addiu     $v1, $v1, 1
/* C56F38 80240FF8 ACA20000 */  sw        $v0, ($a1)
/* C56F3C 80240FFC 28620010 */  slti      $v0, $v1, 0x10
/* C56F40 80241000 1440FFFA */  bnez      $v0, .L80240FEC
/* C56F44 80241004 24A50004 */   addiu    $a1, $a1, 4
/* C56F48 80241008 08090413 */  j         .L8024104C
/* C56F4C 8024100C 00000000 */   nop
.L80241010:
/* C56F50 80241010 0000182D */  daddu     $v1, $zero, $zero
/* C56F54 80241014 0040282D */  daddu     $a1, $v0, $zero
/* C56F58 80241018 0220202D */  daddu     $a0, $s1, $zero
.L8024101C:
/* C56F5C 8024101C 8CA20000 */  lw        $v0, ($a1)
/* C56F60 80241020 24A50004 */  addiu     $a1, $a1, 4
/* C56F64 80241024 24630001 */  addiu     $v1, $v1, 1
/* C56F68 80241028 AC820084 */  sw        $v0, 0x84($a0)
/* C56F6C 8024102C 28620010 */  slti      $v0, $v1, 0x10
/* C56F70 80241030 1440FFFA */  bnez      $v0, .L8024101C
/* C56F74 80241034 24840004 */   addiu    $a0, $a0, 4
/* C56F78 80241038 3C108024 */  lui       $s0, %hi(D_802436E0)
/* C56F7C 8024103C 261036E0 */  addiu     $s0, $s0, %lo(D_802436E0)
/* C56F80 80241040 0C00AB4B */  jal       heap_free
/* C56F84 80241044 8E040000 */   lw       $a0, ($s0)
/* C56F88 80241048 AE000000 */  sw        $zero, ($s0)
.L8024104C:
/* C56F8C 8024104C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C56F90 80241050 8FB10014 */  lw        $s1, 0x14($sp)
/* C56F94 80241054 8FB00010 */  lw        $s0, 0x10($sp)
/* C56F98 80241058 24020002 */  addiu     $v0, $zero, 2
/* C56F9C 8024105C 03E00008 */  jr        $ra
/* C56FA0 80241060 27BD0020 */   addiu    $sp, $sp, 0x20
