.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12E0_716F40
/* 716F40 802A12E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 716F44 802A12E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 716F48 802A12E8 0080802D */  daddu     $s0, $a0, $zero
/* 716F4C 802A12EC 10A0000E */  beqz      $a1, .L802A1328
/* 716F50 802A12F0 AFBF0014 */   sw       $ra, 0x14($sp)
/* 716F54 802A12F4 0C04760B */  jal       func_8011D82C
/* 716F58 802A12F8 24040001 */   addiu    $a0, $zero, 1
/* 716F5C 802A12FC 0000202D */  daddu     $a0, $zero, $zero
/* 716F60 802A1300 0080282D */  daddu     $a1, $a0, $zero
/* 716F64 802A1304 0080302D */  daddu     $a2, $a0, $zero
/* 716F68 802A1308 0080382D */  daddu     $a3, $a0, $zero
/* 716F6C 802A130C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 716F70 802A1310 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 716F74 802A1314 24030001 */  addiu     $v1, $zero, 1
/* 716F78 802A1318 0C046F97 */  jal       set_background_color_blend
/* 716F7C 802A131C A0430000 */   sb       $v1, ($v0)
/* 716F80 802A1320 24020014 */  addiu     $v0, $zero, 0x14
/* 716F84 802A1324 AE020070 */  sw        $v0, 0x70($s0)
.L802A1328:
/* 716F88 802A1328 0000202D */  daddu     $a0, $zero, $zero
/* 716F8C 802A132C 0080282D */  daddu     $a1, $a0, $zero
/* 716F90 802A1330 0080302D */  daddu     $a2, $a0, $zero
/* 716F94 802A1334 8E030070 */  lw        $v1, 0x70($s0)
/* 716F98 802A1338 24020014 */  addiu     $v0, $zero, 0x14
/* 716F9C 802A133C 00431023 */  subu      $v0, $v0, $v1
/* 716FA0 802A1340 00023880 */  sll       $a3, $v0, 2
/* 716FA4 802A1344 00E23821 */  addu      $a3, $a3, $v0
/* 716FA8 802A1348 00073840 */  sll       $a3, $a3, 1
/* 716FAC 802A134C 0C046F97 */  jal       set_background_color_blend
/* 716FB0 802A1350 30E700FE */   andi     $a3, $a3, 0xfe
/* 716FB4 802A1354 8E020070 */  lw        $v0, 0x70($s0)
/* 716FB8 802A1358 2442FFFF */  addiu     $v0, $v0, -1
/* 716FBC 802A135C AE020070 */  sw        $v0, 0x70($s0)
/* 716FC0 802A1360 2C420001 */  sltiu     $v0, $v0, 1
/* 716FC4 802A1364 8FBF0014 */  lw        $ra, 0x14($sp)
/* 716FC8 802A1368 8FB00010 */  lw        $s0, 0x10($sp)
/* 716FCC 802A136C 00021040 */  sll       $v0, $v0, 1
/* 716FD0 802A1370 03E00008 */  jr        $ra
/* 716FD4 802A1374 27BD0018 */   addiu    $sp, $sp, 0x18
