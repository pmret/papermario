.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024A2D4
/* 13D614 8024A2D4 24040004 */  addiu $a0, $zero, 4
/* 13D618 8024A2D8 3C058027 */  lui   $a1, 0x8027
/* 13D61C 8024A2DC 24A5FCB8 */  addiu $a1, $a1, -0x348
/* 13D620 8024A2E0 24020140 */  addiu $v0, $zero, 0x140
/* 13D624 8024A2E4 AFA20044 */  sw    $v0, 0x44($sp)
/* 13D628 8024A2E8 240200F0 */  addiu $v0, $zero, 0xf0
/* 13D62C 8024A2EC AFA00024 */  sw    $zero, 0x24($sp)
/* 13D630 8024A2F0 AFA00028 */  sw    $zero, 0x28($sp)
/* 13D634 8024A2F4 AFA0002C */  sw    $zero, 0x2c($sp)
/* 13D638 8024A2F8 AFA00030 */  sw    $zero, 0x30($sp)
/* 13D63C 8024A2FC AFA00034 */  sw    $zero, 0x34($sp)
/* 13D640 8024A300 AFA00038 */  sw    $zero, 0x38($sp)
/* 13D644 8024A304 AFA0003C */  sw    $zero, 0x3c($sp)
/* 13D648 8024A308 AFA00040 */  sw    $zero, 0x40($sp)
/* 13D64C 8024A30C AFA20048 */  sw    $v0, 0x48($sp)
/* 13D650 8024A310 0C03D4B8 */  jal   draw_box
/* 13D654 8024A314 AFA0004C */   sw    $zero, 0x4c($sp)
/* 13D658 8024A318 0C093BA0 */  jal   func_8024EE80
/* 13D65C 8024A31C 24040050 */   addiu $a0, $zero, 0x50
/* 13D660 8024A320 3C108027 */  lui   $s0, 0x8027
/* 13D664 8024A324 261005E4 */  addiu $s0, $s0, 0x5e4
/* 13D668 8024A328 24080001 */  addiu $t0, $zero, 1
/* 13D66C 8024A32C 8FAB00AC */  lw    $t3, 0xac($sp)
/* 13D670 8024A330 8E030000 */  lw    $v1, ($s0)
/* 13D674 8024A334 14680002 */  bne   $v1, $t0, .L8024A340
/* 13D678 8024A338 25650019 */   addiu $a1, $t3, 0x19
/* 13D67C 8024A33C 25650022 */  addiu $a1, $t3, 0x22
.L8024A340:
/* 13D680 8024A340 8FAA00B0 */  lw    $t2, 0xb0($sp)
/* 13D684 8024A344 240700FF */  addiu $a3, $zero, 0xff
/* 13D688 8024A348 14600002 */  bnez  $v1, .L8024A354
/* 13D68C 8024A34C 25460031 */   addiu $a2, $t2, 0x31
/* 13D690 8024A350 240700BF */  addiu $a3, $zero, 0xbf
.L8024A354:
/* 13D694 8024A354 0040202D */  daddu $a0, $v0, $zero
/* 13D698 8024A358 AFA00010 */  sw    $zero, 0x10($sp)
/* 13D69C 8024A35C 0C04993B */  jal   draw_string
/* 13D6A0 8024A360 AFA80014 */   sw    $t0, 0x14($sp)
/* 13D6A4 8024A364 3C038027 */  lui   $v1, 0x8027
/* 13D6A8 8024A368 806300D4 */  lb    $v1, 0xd4($v1)
/* 13D6AC 8024A36C 24020003 */  addiu $v0, $zero, 3
/* 13D6B0 8024A370 1462004E */  bne   $v1, $v0, .L8024A4AC
/* 13D6B4 8024A374 00000000 */   nop   
/* 13D6B8 8024A378 3C028027 */  lui   $v0, 0x8027
/* 13D6BC 8024A37C 8C4205E0 */  lw    $v0, 0x5e0($v0)
/* 13D6C0 8024A380 14400008 */  bnez  $v0, .L8024A3A4
/* 13D6C4 8024A384 24040021 */   addiu $a0, $zero, 0x21
/* 13D6C8 8024A388 8E060000 */  lw    $a2, ($s0)
/* 13D6CC 8024A38C 8FAB00AC */  lw    $t3, 0xac($sp)
/* 13D6D0 8024A390 8FAA00B0 */  lw    $t2, 0xb0($sp)
/* 13D6D4 8024A394 2565000C */  addiu $a1, $t3, 0xc
/* 13D6D8 8024A398 00063140 */  sll   $a2, $a2, 5
/* 13D6DC 8024A39C 08092929 */  j     func_8024A4A4
/* 13D6E0 8024A3A0 24C6001A */   addiu $a2, $a2, 0x1a

.L8024A3A4:
/* 13D6E4 8024A3A4 3C118027 */  lui   $s1, 0x8027
/* 13D6E8 8024A3A8 263104C8 */  addiu $s1, $s1, 0x4c8
/* 13D6EC 8024A3AC 8E240000 */  lw    $a0, ($s1)
/* 13D6F0 8024A3B0 3C128027 */  lui   $s2, 0x8027
/* 13D6F4 8024A3B4 265204D0 */  addiu $s2, $s2, 0x4d0
/* 13D6F8 8024A3B8 00041040 */  sll   $v0, $a0, 1
/* 13D6FC 8024A3BC 00441021 */  addu  $v0, $v0, $a0
/* 13D700 8024A3C0 00021080 */  sll   $v0, $v0, 2
/* 13D704 8024A3C4 00521021 */  addu  $v0, $v0, $s2
/* 13D708 8024A3C8 90430001 */  lbu   $v1, 1($v0)
/* 13D70C 8024A3CC 90420002 */  lbu   $v0, 2($v0)
/* 13D710 8024A3D0 00620018 */  mult  $v1, $v0
/* 13D714 8024A3D4 3C108027 */  lui   $s0, 0x8027
/* 13D718 8024A3D8 261005C0 */  addiu $s0, $s0, 0x5c0
/* 13D71C 8024A3DC 8E050000 */  lw    $a1, ($s0)
/* 13D720 8024A3E0 00005012 */  mflo  $t2
/* 13D724 8024A3E4 0C0925F4 */  jal   func_802497D0
/* 13D728 8024A3E8 00AA2823 */   subu  $a1, $a1, $t2
/* 13D72C 8024A3EC 8E240000 */  lw    $a0, ($s1)
/* 13D730 8024A3F0 00041840 */  sll   $v1, $a0, 1
/* 13D734 8024A3F4 00641821 */  addu  $v1, $v1, $a0
/* 13D738 8024A3F8 00031880 */  sll   $v1, $v1, 2
/* 13D73C 8024A3FC 00721821 */  addu  $v1, $v1, $s2
/* 13D740 8024A400 90650001 */  lbu   $a1, 1($v1)
/* 13D744 8024A404 90630002 */  lbu   $v1, 2($v1)
/* 13D748 8024A408 00A30018 */  mult  $a1, $v1
/* 13D74C 8024A40C 8E050000 */  lw    $a1, ($s0)
/* 13D750 8024A410 0040802D */  daddu $s0, $v0, $zero
/* 13D754 8024A414 00005012 */  mflo  $t2
/* 13D758 8024A418 0C09260A */  jal   func_80249828
/* 13D75C 8024A41C 00AA2823 */   subu  $a1, $a1, $t2
/* 13D760 8024A420 0200202D */  daddu $a0, $s0, $zero
/* 13D764 8024A424 0C09265A */  jal   func_80249968
/* 13D768 8024A428 0040802D */   daddu $s0, $v0, $zero
/* 13D76C 8024A42C 0200202D */  daddu $a0, $s0, $zero
/* 13D770 8024A430 0C092656 */  jal   func_80249958
/* 13D774 8024A434 0040802D */   daddu $s0, $v0, $zero
/* 13D778 8024A438 0040302D */  daddu $a2, $v0, $zero
/* 13D77C 8024A43C 04C10003 */  bgez  $a2, .L8024A44C
/* 13D780 8024A440 28C20071 */   slti  $v0, $a2, 0x71
/* 13D784 8024A444 08092915 */  j     func_8024A454
/* 13D788 8024A448 0000302D */   daddu $a2, $zero, $zero

.L8024A44C:
/* 13D78C 8024A44C 50400001 */  beql  $v0, $zero, .L8024A454
/* 13D790 8024A450 24060070 */   addiu $a2, $zero, 0x70
