.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8014AB0C
/* 0E120C 8014AB0C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E1210 8014AB10 3C028016 */  lui   $v0, 0x8016
/* 0E1214 8014AB14 24429AF0 */  addiu $v0, $v0, -0x6510
/* 0E1218 8014AB18 00041840 */  sll   $v1, $a0, 1
/* 0E121C 8014AB1C 00641821 */  addu  $v1, $v1, $a0
/* 0E1220 8014AB20 00031900 */  sll   $v1, $v1, 4
/* 0E1224 8014AB24 00621821 */  addu  $v1, $v1, $v0
/* 0E1228 8014AB28 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E122C 8014AB2C 94620000 */  lhu   $v0, ($v1)
/* 0E1230 8014AB30 30420001 */  andi  $v0, $v0, 1
/* 0E1234 8014AB34 10400006 */  beqz  $v0, .L8014AB50
/* 0E1238 8014AB38 00052C00 */   sll   $a1, $a1, 0x10
/* 0E123C 8014AB3C 8C640018 */  lw    $a0, 0x18($v1)
/* 0E1240 8014AB40 0C015777 */  jal   func_80055DDC
/* 0E1244 8014AB44 00052C03 */   sra   $a1, $a1, 0x10
/* 0E1248 8014AB48 08052AD5 */  j     .L8014AB54
/* 0E124C 8014AB4C 00000000 */   nop   

.L8014AB50:
/* 0E1250 8014AB50 0000102D */  daddu $v0, $zero, $zero
.L8014AB54:
/* 0E1254 8014AB54 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E1258 8014AB58 03E00008 */  jr    $ra
/* 0E125C 8014AB5C 27BD0018 */   addiu $sp, $sp, 0x18

/* 0E1260 8014AB60 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E1264 8014AB64 3C028016 */  lui   $v0, 0x8016
/* 0E1268 8014AB68 24429AF0 */  addiu $v0, $v0, -0x6510
/* 0E126C 8014AB6C 00041840 */  sll   $v1, $a0, 1
/* 0E1270 8014AB70 00641821 */  addu  $v1, $v1, $a0
/* 0E1274 8014AB74 00031900 */  sll   $v1, $v1, 4
/* 0E1278 8014AB78 00621821 */  addu  $v1, $v1, $v0
/* 0E127C 8014AB7C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E1280 8014AB80 94620000 */  lhu   $v0, ($v1)
/* 0E1284 8014AB84 30420001 */  andi  $v0, $v0, 1
/* 0E1288 8014AB88 10400006 */  beqz  $v0, .L8014ABA4
/* 0E128C 8014AB8C 00052C00 */   sll   $a1, $a1, 0x10
/* 0E1290 8014AB90 8C640018 */  lw    $a0, 0x18($v1)
/* 0E1294 8014AB94 0C015792 */  jal   func_80055E48
/* 0E1298 8014AB98 00052C03 */   sra   $a1, $a1, 0x10
/* 0E129C 8014AB9C 08052AEA */  j     .L8014ABA8
/* 0E12A0 8014ABA0 00000000 */   nop   

.L8014ABA4:
/* 0E12A4 8014ABA4 0000102D */  daddu $v0, $zero, $zero
.L8014ABA8:
/* 0E12A8 8014ABA8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E12AC 8014ABAC 03E00008 */  jr    $ra
/* 0E12B0 8014ABB0 27BD0018 */   addiu $sp, $sp, 0x18

/* 0E12B4 8014ABB4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E12B8 8014ABB8 3C028016 */  lui   $v0, 0x8016
/* 0E12BC 8014ABBC 24429AF0 */  addiu $v0, $v0, -0x6510
/* 0E12C0 8014ABC0 00041840 */  sll   $v1, $a0, 1
/* 0E12C4 8014ABC4 00641821 */  addu  $v1, $v1, $a0
/* 0E12C8 8014ABC8 00031900 */  sll   $v1, $v1, 4
/* 0E12CC 8014ABCC 00621821 */  addu  $v1, $v1, $v0
/* 0E12D0 8014ABD0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E12D4 8014ABD4 94620000 */  lhu   $v0, ($v1)
/* 0E12D8 8014ABD8 30420001 */  andi  $v0, $v0, 1
/* 0E12DC 8014ABDC 10400006 */  beqz  $v0, .L8014ABF8
/* 0E12E0 8014ABE0 00052C00 */   sll   $a1, $a1, 0x10
/* 0E12E4 8014ABE4 8C640018 */  lw    $a0, 0x18($v1)
/* 0E12E8 8014ABE8 0C015731 */  jal   func_80055CC4
/* 0E12EC 8014ABEC 00052C03 */   sra   $a1, $a1, 0x10
/* 0E12F0 8014ABF0 08052AFF */  j     .L8014ABFC
/* 0E12F4 8014ABF4 00000000 */   nop   

.L8014ABF8:
/* 0E12F8 8014ABF8 0000102D */  daddu $v0, $zero, $zero
.L8014ABFC:
/* 0E12FC 8014ABFC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E1300 8014AC00 03E00008 */  jr    $ra
/* 0E1304 8014AC04 27BD0018 */   addiu $sp, $sp, 0x18

