.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel render_player_model
/* 07A618 800E1168 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 07A61C 800E116C AFB10044 */  sw    $s1, 0x44($sp)
/* 07A620 800E1170 AFB00040 */  sw    $s0, 0x40($sp)
/* 07A624 800E1174 3C108011 */  lui   $s0, 0x8011
/* 07A628 800E1178 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 07A62C 800E117C AFBF0048 */  sw    $ra, 0x48($sp)
/* 07A630 800E1180 8E030000 */  lw    $v1, ($s0)
/* 07A634 800E1184 3C024000 */  lui   $v0, 0x4000
/* 07A638 800E1188 00621024 */  and   $v0, $v1, $v0
/* 07A63C 800E118C 10400054 */  beqz  $v0, .L800E12E0
/* 07A640 800E1190 27B10020 */   addiu $s1, $sp, 0x20
/* 07A644 800E1194 3C02BFFF */  lui   $v0, 0xbfff
/* 07A648 800E1198 3442FFFF */  ori   $v0, $v0, 0xffff
/* 07A64C 800E119C 8E050028 */  lw    $a1, 0x28($s0)
/* 07A650 800E11A0 8E06002C */  lw    $a2, 0x2c($s0)
/* 07A654 800E11A4 8E070030 */  lw    $a3, 0x30($s0)
/* 07A658 800E11A8 3C04800A */  lui   $a0, 0x800a
/* 07A65C 800E11AC 8484A634 */  lh    $a0, -0x59cc($a0)
/* 07A660 800E11B0 00621024 */  and   $v0, $v1, $v0
/* 07A664 800E11B4 AE020000 */  sw    $v0, ($s0)
/* 07A668 800E11B8 27A20030 */  addiu $v0, $sp, 0x30
/* 07A66C 800E11BC AFA20010 */  sw    $v0, 0x10($sp)
/* 07A670 800E11C0 27A20034 */  addiu $v0, $sp, 0x34
/* 07A674 800E11C4 AFA20014 */  sw    $v0, 0x14($sp)
/* 07A678 800E11C8 27A20038 */  addiu $v0, $sp, 0x38
/* 07A67C 800E11CC 0C00B94E */  jal   get_screen_coords
/* 07A680 800E11D0 AFA20018 */   sw    $v0, 0x18($sp)
/* 07A684 800E11D4 8E020000 */  lw    $v0, ($s0)
/* 07A688 800E11D8 3C030002 */  lui   $v1, 2
/* 07A68C 800E11DC 00431024 */  and   $v0, $v0, $v1
/* 07A690 800E11E0 14400026 */  bnez  $v0, .L800E127C
/* 07A694 800E11E4 24020011 */   addiu $v0, $zero, 0x11
/* 07A698 800E11E8 9203000E */  lbu   $v1, 0xe($s0)
/* 07A69C 800E11EC 9202000F */  lbu   $v0, 0xf($s0)
/* 07A6A0 800E11F0 1062001F */  beq   $v1, $v0, .L800E1270
/* 07A6A4 800E11F4 2C6200FE */   sltiu $v0, $v1, 0xfe
/* 07A6A8 800E11F8 10400011 */  beqz  $v0, .L800E1240
/* 07A6AC 800E11FC 3C030100 */   lui   $v1, 0x100
/* 07A6B0 800E1200 8E020004 */  lw    $v0, 4($s0)
/* 07A6B4 800E1204 00431024 */  and   $v0, $v0, $v1
/* 07A6B8 800E1208 14400002 */  bnez  $v0, .L800E1214
/* 07A6BC 800E120C 24080016 */   addiu $t0, $zero, 0x16
/* 07A6C0 800E1210 24080011 */  addiu $t0, $zero, 0x11
.L800E1214:
/* 07A6C4 800E1214 0000202D */  daddu $a0, $zero, $zero
/* 07A6C8 800E1218 2405FFFF */  addiu $a1, $zero, -1
/* 07A6CC 800E121C 24060007 */  addiu $a2, $zero, 7
/* 07A6D0 800E1220 9202000E */  lbu   $v0, 0xe($s0)
/* 07A6D4 800E1224 0080382D */  daddu $a3, $a0, $zero
/* 07A6D8 800E1228 A20800BE */  sb    $t0, 0xbe($s0)
/* 07A6DC 800E122C AFA00010 */  sw    $zero, 0x10($sp)
/* 07A6E0 800E1230 AFA00014 */  sw    $zero, 0x14($sp)
/* 07A6E4 800E1234 AFA0001C */  sw    $zero, 0x1c($sp)
/* 07A6E8 800E1238 0803849A */  j     .L800E1268
/* 07A6EC 800E123C AFA20018 */   sw    $v0, 0x18($sp)

.L800E1240:
/* 07A6F0 800E1240 0000202D */  daddu $a0, $zero, $zero
/* 07A6F4 800E1244 2405FFFF */  addiu $a1, $zero, -1
/* 07A6F8 800E1248 0080302D */  daddu $a2, $a0, $zero
/* 07A6FC 800E124C 0080382D */  daddu $a3, $a0, $zero
/* 07A700 800E1250 2402000D */  addiu $v0, $zero, 0xd
/* 07A704 800E1254 A20200BE */  sb    $v0, 0xbe($s0)
/* 07A708 800E1258 AFA00010 */  sw    $zero, 0x10($sp)
/* 07A70C 800E125C AFA00014 */  sw    $zero, 0x14($sp)
/* 07A710 800E1260 AFA00018 */  sw    $zero, 0x18($sp)
/* 07A714 800E1264 AFA0001C */  sw    $zero, 0x1c($sp)
.L800E1268:
/* 07A718 800E1268 0C0B77B9 */  jal   func_802DDEE4
/* 07A71C 800E126C 00000000 */   nop   
.L800E1270:
/* 07A720 800E1270 9202000E */  lbu   $v0, 0xe($s0)
/* 07A724 800E1274 080384A1 */  j     .L800E1284
/* 07A728 800E1278 A202000F */   sb    $v0, 0xf($s0)

.L800E127C:
/* 07A72C 800E127C A20200BE */  sb    $v0, 0xbe($s0)
/* 07A730 800E1280 A200000F */  sb    $zero, 0xf($s0)
.L800E1284:
/* 07A734 800E1284 8E020004 */  lw    $v0, 4($s0)
/* 07A738 800E1288 30422000 */  andi  $v0, $v0, 0x2000
/* 07A73C 800E128C 14400012 */  bnez  $v0, .L800E12D8
/* 07A740 800E1290 3C030002 */   lui   $v1, 2
/* 07A744 800E1294 8FA20038 */  lw    $v0, 0x38($sp)
/* 07A748 800E1298 AE300008 */  sw    $s0, 8($s1)
/* 07A74C 800E129C 00021023 */  negu  $v0, $v0
/* 07A750 800E12A0 AE220004 */  sw    $v0, 4($s1)
/* 07A754 800E12A4 820200BE */  lb    $v0, 0xbe($s0)
/* 07A758 800E12A8 3C04800E */  lui   $a0, 0x800e
/* 07A75C 800E12AC 24841704 */  addiu $a0, $a0, 0x1704
/* 07A760 800E12B0 AE220000 */  sw    $v0, ($s1)
/* 07A764 800E12B4 8E020000 */  lw    $v0, ($s0)
/* 07A768 800E12B8 00431024 */  and   $v0, $v0, $v1
/* 07A76C 800E12BC 54400004 */  bnezl $v0, .L800E12D0
/* 07A770 800E12C0 AE24000C */   sw    $a0, 0xc($s1)
/* 07A774 800E12C4 3C04800E */  lui   $a0, 0x800e
/* 07A778 800E12C8 248412F4 */  addiu $a0, $a0, 0x12f4
/* 07A77C 800E12CC AE24000C */  sw    $a0, 0xc($s1)
.L800E12D0:
/* 07A780 800E12D0 0C047644 */  jal   queue_render_task
/* 07A784 800E12D4 0220202D */   daddu $a0, $s1, $zero
.L800E12D8:
/* 07A788 800E12D8 0C03C327 */  jal   func_800F0C9C
/* 07A78C 800E12DC 00000000 */   nop   
.L800E12E0:
/* 07A790 800E12E0 8FBF0048 */  lw    $ra, 0x48($sp)
/* 07A794 800E12E4 8FB10044 */  lw    $s1, 0x44($sp)
/* 07A798 800E12E8 8FB00040 */  lw    $s0, 0x40($sp)
/* 07A79C 800E12EC 03E00008 */  jr    $ra
/* 07A7A0 800E12F0 27BD0050 */   addiu $sp, $sp, 0x50

