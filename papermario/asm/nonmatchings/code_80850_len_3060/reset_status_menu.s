.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel reset_status_menu
/* 083060 800E9BB0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 083064 800E9BB4 AFB20018 */  sw    $s2, 0x18($sp)
/* 083068 800E9BB8 0000902D */  daddu $s2, $zero, $zero
/* 08306C 800E9BBC AFB10014 */  sw    $s1, 0x14($sp)
/* 083070 800E9BC0 3C118011 */  lui   $s1, 0x8011
/* 083074 800E9BC4 2631EF58 */  addiu $s1, $s1, -0x10a8
/* 083078 800E9BC8 AFB00010 */  sw    $s0, 0x10($sp)
/* 08307C 800E9BCC 0220802D */  daddu $s0, $s1, $zero
/* 083080 800E9BD0 2402000C */  addiu $v0, $zero, 0xc
/* 083084 800E9BD4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 083088 800E9BD8 A6220034 */  sh    $v0, 0x34($s1)
/* 08308C 800E9BDC 2402FF9C */  addiu $v0, $zero, -0x64
/* 083090 800E9BE0 A6220036 */  sh    $v0, 0x36($s1)
/* 083094 800E9BE4 240200D2 */  addiu $v0, $zero, 0xd2
/* 083098 800E9BE8 3C038011 */  lui   $v1, 0x8011
/* 08309C 800E9BEC 2463F290 */  addiu $v1, $v1, -0xd70
/* 0830A0 800E9BF0 A220003A */  sb    $zero, 0x3a($s1)
/* 0830A4 800E9BF4 A6220038 */  sh    $v0, 0x38($s1)
/* 0830A8 800E9BF8 A220003B */  sb    $zero, 0x3b($s1)
/* 0830AC 800E9BFC A2200044 */  sb    $zero, 0x44($s1)
/* 0830B0 800E9C00 A2200045 */  sb    $zero, 0x45($s1)
/* 0830B4 800E9C04 A2200046 */  sb    $zero, 0x46($s1)
/* 0830B8 800E9C08 A220004A */  sb    $zero, 0x4a($s1)
/* 0830BC 800E9C0C A220004B */  sb    $zero, 0x4b($s1)
/* 0830C0 800E9C10 A220004C */  sb    $zero, 0x4c($s1)
/* 0830C4 800E9C14 A220004D */  sb    $zero, 0x4d($s1)
/* 0830C8 800E9C18 A220004E */  sb    $zero, 0x4e($s1)
/* 0830CC 800E9C1C A220004F */  sb    $zero, 0x4f($s1)
/* 0830D0 800E9C20 A2200054 */  sb    $zero, 0x54($s1)
/* 0830D4 800E9C24 A2200055 */  sb    $zero, 0x55($s1)
/* 0830D8 800E9C28 A2200056 */  sb    $zero, 0x56($s1)
/* 0830DC 800E9C2C A2200050 */  sb    $zero, 0x50($s1)
/* 0830E0 800E9C30 A2200051 */  sb    $zero, 0x51($s1)
/* 0830E4 800E9C34 A2200047 */  sb    $zero, 0x47($s1)
/* 0830E8 800E9C38 A2200052 */  sb    $zero, 0x52($s1)
/* 0830EC 800E9C3C A2200053 */  sb    $zero, 0x53($s1)
/* 0830F0 800E9C40 90640010 */  lbu   $a0, 0x10($v1)
/* 0830F4 800E9C44 2402FFFF */  addiu $v0, $zero, -1
/* 0830F8 800E9C48 A222006E */  sb    $v0, 0x6e($s1)
/* 0830FC 800E9C4C 90620002 */  lbu   $v0, 2($v1)
/* 083100 800E9C50 90650005 */  lbu   $a1, 5($v1)
/* 083104 800E9C54 9466000C */  lhu   $a2, 0xc($v1)
/* 083108 800E9C58 94630290 */  lhu   $v1, 0x290($v1)
/* 08310C 800E9C5C 00042600 */  sll   $a0, $a0, 0x18
/* 083110 800E9C60 00042603 */  sra   $a0, $a0, 0x18
/* 083114 800E9C64 A222003D */  sb    $v0, 0x3d($s1)
/* 083118 800E9C68 A225003E */  sb    $a1, 0x3e($s1)
/* 08311C 800E9C6C A6260040 */  sh    $a2, 0x40($s1)
/* 083120 800E9C70 A6240042 */  sh    $a0, 0x42($s1)
/* 083124 800E9C74 A6230048 */  sh    $v1, 0x48($s1)
/* 083128 800E9C78 A220003C */  sb    $zero, 0x3c($s1)
.L800E9C7C:
/* 08312C 800E9C7C 8E040000 */  lw    $a0, ($s0)
/* 083130 800E9C80 26100004 */  addiu $s0, $s0, 4
/* 083134 800E9C84 26520001 */  addiu $s2, $s2, 1
/* 083138 800E9C88 0C0514AD */  jal   func_801452B4
/* 08313C 800E9C8C 0080282D */   daddu $a1, $a0, $zero
/* 083140 800E9C90 2A420002 */  slti  $v0, $s2, 2
/* 083144 800E9C94 1440FFF9 */  bnez  $v0, .L800E9C7C
/* 083148 800E9C98 00000000 */   nop   
/* 08314C 800E9C9C 0000902D */  daddu $s2, $zero, $zero
/* 083150 800E9CA0 0220802D */  daddu $s0, $s1, $zero
.L800E9CA4:
/* 083154 800E9CA4 8E040008 */  lw    $a0, 8($s0)
/* 083158 800E9CA8 26100004 */  addiu $s0, $s0, 4
/* 08315C 800E9CAC 26520001 */  addiu $s2, $s2, 1
/* 083160 800E9CB0 0C0514AD */  jal   func_801452B4
/* 083164 800E9CB4 0080282D */   daddu $a1, $a0, $zero
/* 083168 800E9CB8 2A420002 */  slti  $v0, $s2, 2
/* 08316C 800E9CBC 1440FFF9 */  bnez  $v0, .L800E9CA4
/* 083170 800E9CC0 00000000 */   nop   
/* 083174 800E9CC4 8E240010 */  lw    $a0, 0x10($s1)
/* 083178 800E9CC8 0C0514AD */  jal   func_801452B4
/* 08317C 800E9CCC 0080282D */   daddu $a1, $a0, $zero
/* 083180 800E9CD0 8E240014 */  lw    $a0, 0x14($s1)
/* 083184 800E9CD4 0C0514AD */  jal   func_801452B4
/* 083188 800E9CD8 0080282D */   daddu $a1, $a0, $zero
/* 08318C 800E9CDC 8E240018 */  lw    $a0, 0x18($s1)
/* 083190 800E9CE0 0C0514AD */  jal   func_801452B4
/* 083194 800E9CE4 0080282D */   daddu $a1, $a0, $zero
/* 083198 800E9CE8 8E24001C */  lw    $a0, 0x1c($s1)
/* 08319C 800E9CEC 0C0514AD */  jal   func_801452B4
/* 0831A0 800E9CF0 0080282D */   daddu $a1, $a0, $zero
/* 0831A4 800E9CF4 8E240020 */  lw    $a0, 0x20($s1)
/* 0831A8 800E9CF8 0C0514AD */  jal   func_801452B4
/* 0831AC 800E9CFC 0080282D */   daddu $a1, $a0, $zero
/* 0831B0 800E9D00 8E240024 */  lw    $a0, 0x24($s1)
/* 0831B4 800E9D04 0C0514AD */  jal   func_801452B4
/* 0831B8 800E9D08 0080282D */   daddu $a1, $a0, $zero
/* 0831BC 800E9D0C 8E240028 */  lw    $a0, 0x28($s1)
/* 0831C0 800E9D10 0C0514AD */  jal   func_801452B4
/* 0831C4 800E9D14 0080282D */   daddu $a1, $a0, $zero
/* 0831C8 800E9D18 8E24002C */  lw    $a0, 0x2c($s1)
/* 0831CC 800E9D1C 0C0514AD */  jal   func_801452B4
/* 0831D0 800E9D20 0080282D */   daddu $a1, $a0, $zero
/* 0831D4 800E9D24 8E240030 */  lw    $a0, 0x30($s1)
/* 0831D8 800E9D28 0C0514AD */  jal   func_801452B4
/* 0831DC 800E9D2C 0080282D */   daddu $a1, $a0, $zero
/* 0831E0 800E9D30 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0831E4 800E9D34 8FB20018 */  lw    $s2, 0x18($sp)
/* 0831E8 800E9D38 8FB10014 */  lw    $s1, 0x14($sp)
/* 0831EC 800E9D3C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0831F0 800E9D40 03E00008 */  jr    $ra
/* 0831F4 800E9D44 27BD0020 */   addiu $sp, $sp, 0x20

