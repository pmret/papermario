.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243170_EDBF90
.ascii "[%d] dokan get pos  (no=%d)  pos=%d, %d, %d,  dir=%d\n\0\0\0flo_23\0\0flo_12\0\0flo_11\0\0"

.section .text

glabel func_802400F0_ED8F10
/* ED8F10 802400F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* ED8F14 802400F4 AFB00020 */  sw        $s0, 0x20($sp)
/* ED8F18 802400F8 0080802D */  daddu     $s0, $a0, $zero
/* ED8F1C 802400FC AFBF002C */  sw        $ra, 0x2c($sp)
/* ED8F20 80240100 AFB20028 */  sw        $s2, 0x28($sp)
/* ED8F24 80240104 0C017C4A */  jal       func_8005F128
/* ED8F28 80240108 AFB10024 */   sw       $s1, 0x24($sp)
/* ED8F2C 8024010C 0200202D */  daddu     $a0, $s0, $zero
/* ED8F30 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* ED8F34 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* ED8F38 80240118 0C0B53A3 */  jal       dead_get_variable
/* ED8F3C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* ED8F40 80240120 0200202D */  daddu     $a0, $s0, $zero
/* ED8F44 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* ED8F48 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* ED8F4C 8024012C 00028900 */  sll       $s1, $v0, 4
/* ED8F50 80240130 02231821 */  addu      $v1, $s1, $v1
/* ED8F54 80240134 C4600000 */  lwc1      $f0, ($v1)
/* ED8F58 80240138 4600008D */  trunc.w.s $f2, $f0
/* ED8F5C 8024013C 44061000 */  mfc1      $a2, $f2
/* ED8F60 80240140 0C0B551A */  jal       dead_set_variable
/* ED8F64 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* ED8F68 80240148 0200202D */  daddu     $a0, $s0, $zero
/* ED8F6C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* ED8F70 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* ED8F74 80240154 02221021 */  addu      $v0, $s1, $v0
/* ED8F78 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* ED8F7C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* ED8F80 80240160 44061000 */  mfc1      $a2, $f2
/* ED8F84 80240164 0C0B551A */  jal       dead_set_variable
/* ED8F88 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* ED8F8C 8024016C 0200202D */  daddu     $a0, $s0, $zero
/* ED8F90 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* ED8F94 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* ED8F98 80240178 02221021 */  addu      $v0, $s1, $v0
/* ED8F9C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* ED8FA0 80240180 4600008D */  trunc.w.s $f2, $f0
/* ED8FA4 80240184 44061000 */  mfc1      $a2, $f2
/* ED8FA8 80240188 0C0B551A */  jal       dead_set_variable
/* ED8FAC 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* ED8FB0 80240190 0200202D */  daddu     $a0, $s0, $zero
/* ED8FB4 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* ED8FB8 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* ED8FBC 8024019C 02228821 */  addu      $s1, $s1, $v0
/* ED8FC0 802401A0 C620000C */  lwc1      $f0, 0xc($s1)
/* ED8FC4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* ED8FC8 802401A8 44061000 */  mfc1      $a2, $f2
/* ED8FCC 802401AC 0C0B551A */  jal       dead_set_variable
/* ED8FD0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* ED8FD4 802401B4 3C028008 */  lui       $v0, %hi(D_80079430)
/* ED8FD8 802401B8 8C429430 */  lw        $v0, %lo(D_80079430)($v0)
/* ED8FDC 802401BC 8E03008C */  lw        $v1, 0x8c($s0)
/* ED8FE0 802401C0 94450134 */  lhu       $a1, 0x134($v0)
/* ED8FE4 802401C4 AFA30010 */  sw        $v1, 0x10($sp)
/* ED8FE8 802401C8 8E020090 */  lw        $v0, 0x90($s0)
/* ED8FEC 802401CC AFA20014 */  sw        $v0, 0x14($sp)
/* ED8FF0 802401D0 8E020094 */  lw        $v0, 0x94($s0)
/* ED8FF4 802401D4 AFA20018 */  sw        $v0, 0x18($sp)
/* ED8FF8 802401D8 8E060084 */  lw        $a2, 0x84($s0)
/* ED8FFC 802401DC 8E070088 */  lw        $a3, 0x88($s0)
/* ED9000 802401E0 3C048024 */  lui       $a0, %hi(D_80243170_EDBF90)
/* ED9004 802401E4 0C00973F */  jal       func_80025CFC
/* ED9008 802401E8 24843170 */   addiu    $a0, $a0, %lo(D_80243170_EDBF90)
/* ED900C 802401EC 8FBF002C */  lw        $ra, 0x2c($sp)
/* ED9010 802401F0 8FB20028 */  lw        $s2, 0x28($sp)
/* ED9014 802401F4 8FB10024 */  lw        $s1, 0x24($sp)
/* ED9018 802401F8 8FB00020 */  lw        $s0, 0x20($sp)
/* ED901C 802401FC 24020002 */  addiu     $v0, $zero, 2
/* ED9020 80240200 03E00008 */  jr        $ra
/* ED9024 80240204 27BD0030 */   addiu    $sp, $sp, 0x30
