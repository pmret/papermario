.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DDAE4
/* 076F94 800DDAE4 27BDFF98 */  addiu $sp, $sp, -0x68
/* 076F98 800DDAE8 F7B40050 */  sdc1  $f20, 0x50($sp)
/* 076F9C 800DDAEC C7B40084 */  lwc1  $f20, 0x84($sp)
/* 076FA0 800DDAF0 C7A40078 */  lwc1  $f4, 0x78($sp)
/* 076FA4 800DDAF4 AFB60048 */  sw    $s6, 0x48($sp)
/* 076FA8 800DDAF8 0080B02D */  daddu $s6, $a0, $zero
/* 076FAC 800DDAFC AFB3003C */  sw    $s3, 0x3c($sp)
/* 076FB0 800DDB00 00A0982D */  daddu $s3, $a1, $zero
/* 076FB4 800DDB04 AFB50044 */  sw    $s5, 0x44($sp)
/* 076FB8 800DDB08 00C0A82D */  daddu $s5, $a2, $zero
/* 076FBC 800DDB0C AFB40040 */  sw    $s4, 0x40($sp)
/* 076FC0 800DDB10 00E0A02D */  daddu $s4, $a3, $zero
/* 076FC4 800DDB14 F7B80060 */  sdc1  $f24, 0x60($sp)
/* 076FC8 800DDB18 C7B8007C */  lwc1  $f24, 0x7c($sp)
/* 076FCC 800DDB1C C7A20080 */  lwc1  $f2, 0x80($sp)
/* 076FD0 800DDB20 AFBF004C */  sw    $ra, 0x4c($sp)
/* 076FD4 800DDB24 AFB20038 */  sw    $s2, 0x38($sp)
/* 076FD8 800DDB28 AFB10034 */  sw    $s1, 0x34($sp)
/* 076FDC 800DDB2C AFB00030 */  sw    $s0, 0x30($sp)
/* 076FE0 800DDB30 F7B60058 */  sdc1  $f22, 0x58($sp)
/* 076FE4 800DDB34 C6600000 */  lwc1  $f0, ($s3)
/* 076FE8 800DDB38 27B20020 */  addiu $s2, $sp, 0x20
/* 076FEC 800DDB3C E7A00020 */  swc1  $f0, 0x20($sp)
/* 076FF0 800DDB40 C6A00000 */  lwc1  $f0, ($s5)
/* 076FF4 800DDB44 0240282D */  daddu $a1, $s2, $zero
/* 076FF8 800DDB48 46020000 */  add.s $f0, $f0, $f2
/* 076FFC 800DDB4C 3C013F80 */  lui   $at, 0x3f80
/* 077000 800DDB50 44811000 */  mtc1  $at, $f2
/* 077004 800DDB54 27B10024 */  addiu $s1, $sp, 0x24
/* 077008 800DDB58 46020001 */  sub.s $f0, $f0, $f2
/* 07700C 800DDB5C 3C013F00 */  lui   $at, 0x3f00
/* 077010 800DDB60 44811000 */  mtc1  $at, $f2
/* 077014 800DDB64 0220302D */  daddu $a2, $s1, $zero
/* 077018 800DDB68 4602A502 */  mul.s $f20, $f20, $f2
/* 07701C 800DDB6C 00000000 */  nop   
/* 077020 800DDB70 27B00028 */  addiu $s0, $sp, 0x28
/* 077024 800DDB74 0200382D */  daddu $a3, $s0, $zero
/* 077028 800DDB78 E7A00024 */  swc1  $f0, 0x24($sp)
/* 07702C 800DDB7C C6800000 */  lwc1  $f0, ($s4)
/* 077030 800DDB80 46002585 */  abs.s $f22, $f4
/* 077034 800DDB84 E7A00028 */  swc1  $f0, 0x28($sp)
/* 077038 800DDB88 E7B60010 */  swc1  $f22, 0x10($sp)
/* 07703C 800DDB8C E7B80014 */  swc1  $f24, 0x14($sp)
/* 077040 800DDB90 0C037586 */  jal   func_800DD618
/* 077044 800DDB94 E7B40018 */   swc1  $f20, 0x18($sp)
/* 077048 800DDB98 04430019 */  bgezl $v0, .L800DDC00
/* 07704C 800DDB9C 24020001 */   addiu $v0, $zero, 1
/* 077050 800DDBA0 C6600000 */  lwc1  $f0, ($s3)
/* 077054 800DDBA4 3C014120 */  lui   $at, 0x4120
/* 077058 800DDBA8 342128F6 */  ori   $at, $at, 0x28f6
/* 07705C 800DDBAC 44811000 */  mtc1  $at, $f2
/* 077060 800DDBB0 E7A00020 */  swc1  $f0, 0x20($sp)
/* 077064 800DDBB4 C6A00000 */  lwc1  $f0, ($s5)
/* 077068 800DDBB8 02C0202D */  daddu $a0, $s6, $zero
/* 07706C 800DDBBC 46020000 */  add.s $f0, $f0, $f2
/* 077070 800DDBC0 0240282D */  daddu $a1, $s2, $zero
/* 077074 800DDBC4 0220302D */  daddu $a2, $s1, $zero
/* 077078 800DDBC8 E7A00024 */  swc1  $f0, 0x24($sp)
/* 07707C 800DDBCC C6800000 */  lwc1  $f0, ($s4)
/* 077080 800DDBD0 0200382D */  daddu $a3, $s0, $zero
/* 077084 800DDBD4 E7A00028 */  swc1  $f0, 0x28($sp)
/* 077088 800DDBD8 E7B60010 */  swc1  $f22, 0x10($sp)
/* 07708C 800DDBDC E7B80014 */  swc1  $f24, 0x14($sp)
/* 077090 800DDBE0 0C037586 */  jal   func_800DD618
/* 077094 800DDBE4 E7B40018 */   swc1  $f20, 0x18($sp)
/* 077098 800DDBE8 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07709C 800DDBEC 00021027 */  nor   $v0, $zero, $v0
/* 0770A0 800DDBF0 E6600000 */  swc1  $f0, ($s3)
/* 0770A4 800DDBF4 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0770A8 800DDBF8 08037703 */  j     .L800DDC0C
/* 0770AC 800DDBFC 000217C2 */   srl   $v0, $v0, 0x1f

.L800DDC00:
/* 0770B0 800DDC00 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0770B4 800DDC04 E6600000 */  swc1  $f0, ($s3)
/* 0770B8 800DDC08 C7A00028 */  lwc1  $f0, 0x28($sp)
.L800DDC0C:
/* 0770BC 800DDC0C E6800000 */  swc1  $f0, ($s4)
/* 0770C0 800DDC10 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0770C4 800DDC14 8FB60048 */  lw    $s6, 0x48($sp)
/* 0770C8 800DDC18 8FB50044 */  lw    $s5, 0x44($sp)
/* 0770CC 800DDC1C 8FB40040 */  lw    $s4, 0x40($sp)
/* 0770D0 800DDC20 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0770D4 800DDC24 8FB20038 */  lw    $s2, 0x38($sp)
/* 0770D8 800DDC28 8FB10034 */  lw    $s1, 0x34($sp)
/* 0770DC 800DDC2C 8FB00030 */  lw    $s0, 0x30($sp)
/* 0770E0 800DDC30 D7B80060 */  ldc1  $f24, 0x60($sp)
/* 0770E4 800DDC34 D7B60058 */  ldc1  $f22, 0x58($sp)
/* 0770E8 800DDC38 D7B40050 */  ldc1  $f20, 0x50($sp)
/* 0770EC 800DDC3C 03E00008 */  jr    $ra
/* 0770F0 800DDC40 27BD0068 */   addiu $sp, $sp, 0x68

