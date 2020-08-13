.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuScCreateScheduler
/* 039DB0 8005E9B0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 039DB4 8005E9B4 AFB40028 */  sw    $s4, 0x28($sp)
/* 039DB8 8005E9B8 0080A02D */  daddu $s4, $a0, $zero
/* 039DBC 8005E9BC AFB30024 */  sw    $s3, 0x24($sp)
/* 039DC0 8005E9C0 00A0982D */  daddu $s3, $a1, $zero
/* 039DC4 8005E9C4 3C04800E */  lui   $a0, 0x800e
/* 039DC8 8005E9C8 2484AAAC */  addiu $a0, $a0, -0x5554
/* 039DCC 8005E9CC 24020001 */  addiu $v0, $zero, 1
/* 039DD0 8005E9D0 24030002 */  addiu $v1, $zero, 2
/* 039DD4 8005E9D4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 039DD8 8005E9D8 AFB20020 */  sw    $s2, 0x20($sp)
/* 039DDC 8005E9DC AFB1001C */  sw    $s1, 0x1c($sp)
/* 039DE0 8005E9E0 AFB00018 */  sw    $s0, 0x18($sp)
/* 039DE4 8005E9E4 A482F994 */  sh    $v0, -0x66c($a0)
/* 039DE8 8005E9E8 326200FF */  andi  $v0, $s3, 0xff
/* 039DEC 8005E9EC AC82000C */  sw    $v0, 0xc($a0)
/* 039DF0 8005E9F0 A0830011 */  sb    $v1, 0x11($a0)
/* 039DF4 8005E9F4 3C028000 */  lui   $v0, 0x8000
/* 039DF8 8005E9F8 8C420300 */  lw    $v0, 0x300($v0)
/* 039DFC 8005E9FC A483F996 */  sh    $v1, -0x66a($a0)
/* 039E00 8005EA00 2483F994 */  addiu $v1, $a0, -0x66c
/* 039E04 8005EA04 AC800000 */  sw    $zero, ($a0)
/* 039E08 8005EA08 AC800004 */  sw    $zero, 4($a0)
/* 039E0C 8005EA0C AC800008 */  sw    $zero, 8($a0)
/* 039E10 8005EA10 14400004 */  bnez  $v0, .L8005EA24
/* 039E14 8005EA14 AC80FFFC */   sw    $zero, -4($a0)
/* 039E18 8005EA18 24020032 */  addiu $v0, $zero, 0x32
/* 039E1C 8005EA1C 08017A8B */  j     .L8005EA2C
/* 039E20 8005EA20 A062067C */   sb    $v0, 0x67c($v1)

.L8005EA24:
/* 039E24 8005EA24 2402003C */  addiu $v0, $zero, 0x3c
/* 039E28 8005EA28 A0820010 */  sb    $v0, 0x10($a0)
.L8005EA2C:
/* 039E2C 8005EA2C 3C10800E */  lui   $s0, 0x800e
/* 039E30 8005EA30 2610A4B4 */  addiu $s0, $s0, -0x5b4c
/* 039E34 8005EA34 0200202D */  daddu $a0, $s0, $zero
/* 039E38 8005EA38 26050018 */  addiu $a1, $s0, 0x18
/* 039E3C 8005EA3C 3C01800A */  lui   $at, 0x800a
/* 039E40 8005EA40 A020A5B0 */  sb    $zero, -0x5a50($at)
/* 039E44 8005EA44 0C019560 */  jal   osCreateMesgQueue
/* 039E48 8005EA48 24060008 */   addiu $a2, $zero, 8
/* 039E4C 8005EA4C 26120038 */  addiu $s2, $s0, 0x38
/* 039E50 8005EA50 0240202D */  daddu $a0, $s2, $zero
/* 039E54 8005EA54 26050050 */  addiu $a1, $s0, 0x50
/* 039E58 8005EA58 0C019560 */  jal   osCreateMesgQueue
/* 039E5C 8005EA5C 24060008 */   addiu $a2, $zero, 8
/* 039E60 8005EA60 26110070 */  addiu $s1, $s0, 0x70
/* 039E64 8005EA64 0220202D */  daddu $a0, $s1, $zero
/* 039E68 8005EA68 26050088 */  addiu $a1, $s0, 0x88
/* 039E6C 8005EA6C 0C019560 */  jal   osCreateMesgQueue
/* 039E70 8005EA70 24060008 */   addiu $a2, $zero, 8
/* 039E74 8005EA74 2604FFC8 */  addiu $a0, $s0, -0x38
/* 039E78 8005EA78 2605FFE0 */  addiu $a1, $s0, -0x20
/* 039E7C 8005EA7C 0C019560 */  jal   osCreateMesgQueue
/* 039E80 8005EA80 24060008 */   addiu $a2, $zero, 8
/* 039E84 8005EA84 2604FF90 */  addiu $a0, $s0, -0x70
/* 039E88 8005EA88 2605FFA8 */  addiu $a1, $s0, -0x58
/* 039E8C 8005EA8C 0C019560 */  jal   osCreateMesgQueue
/* 039E90 8005EA90 24060008 */   addiu $a2, $zero, 8
/* 039E94 8005EA94 260400A8 */  addiu $a0, $s0, 0xa8
/* 039E98 8005EA98 260500C0 */  addiu $a1, $s0, 0xc0
/* 039E9C 8005EA9C 0C019560 */  jal   osCreateMesgQueue
/* 039EA0 8005EAA0 24060008 */   addiu $a2, $zero, 8
/* 039EA4 8005EAA4 0C019A9C */  jal   osCreateViManager
/* 039EA8 8005EAA8 240400FE */   addiu $a0, $zero, 0xfe
/* 039EAC 8005EAAC 328200FF */  andi  $v0, $s4, 0xff
/* 039EB0 8005EAB0 00022080 */  sll   $a0, $v0, 2
/* 039EB4 8005EAB4 00822021 */  addu  $a0, $a0, $v0
/* 039EB8 8005EAB8 00042100 */  sll   $a0, $a0, 4
/* 039EBC 8005EABC 3C028009 */  lui   $v0, 0x8009
/* 039EC0 8005EAC0 244246A0 */  addiu $v0, $v0, 0x46a0
/* 039EC4 8005EAC4 0C019B84 */  jal   osViSetMode
/* 039EC8 8005EAC8 00822021 */   addu  $a0, $a0, $v0
/* 039ECC 8005EACC 0C019CE0 */  jal   osViBlack
/* 039ED0 8005EAD0 24040001 */   addiu $a0, $zero, 1
/* 039ED4 8005EAD4 0200202D */  daddu $a0, $s0, $zero
/* 039ED8 8005EAD8 2405029A */  addiu $a1, $zero, 0x29a
/* 039EDC 8005EADC 0C019B6C */  jal   osViSetEvent
/* 039EE0 8005EAE0 326600FF */   andi  $a2, $s3, 0xff
/* 039EE4 8005EAE4 24040004 */  addiu $a0, $zero, 4
/* 039EE8 8005EAE8 0240282D */  daddu $a1, $s2, $zero
/* 039EEC 8005EAEC 0C019654 */  jal   osSetEventMesg
/* 039EF0 8005EAF0 2406029B */   addiu $a2, $zero, 0x29b
/* 039EF4 8005EAF4 24040009 */  addiu $a0, $zero, 9
/* 039EF8 8005EAF8 0220282D */  daddu $a1, $s1, $zero
/* 039EFC 8005EAFC 0C019654 */  jal   osSetEventMesg
/* 039F00 8005EB00 2406029C */   addiu $a2, $zero, 0x29c
/* 039F04 8005EB04 2404000E */  addiu $a0, $zero, 0xe
/* 039F08 8005EB08 0200282D */  daddu $a1, $s0, $zero
/* 039F0C 8005EB0C 0C019654 */  jal   osSetEventMesg
/* 039F10 8005EB10 2406029D */   addiu $a2, $zero, 0x29d
/* 039F14 8005EB14 261200E4 */  addiu $s2, $s0, 0xe4
/* 039F18 8005EB18 0240202D */  daddu $a0, $s2, $zero
/* 039F1C 8005EB1C 24050013 */  addiu $a1, $zero, 0x13
/* 039F20 8005EB20 3C068006 */  lui   $a2, 0x8006
/* 039F24 8005EB24 24C6EFA8 */  addiu $a2, $a2, -0x1058
/* 039F28 8005EB28 2611FF8C */  addiu $s1, $s0, -0x74
/* 039F2C 8005EB2C 0220382D */  daddu $a3, $s1, $zero
/* 039F30 8005EB30 3C02800B */  lui   $v0, 0x800b
/* 039F34 8005EB34 244285D0 */  addiu $v0, $v0, -0x7a30
/* 039F38 8005EB38 AFA20010 */  sw    $v0, 0x10($sp)
/* 039F3C 8005EB3C 24020078 */  addiu $v0, $zero, 0x78
/* 039F40 8005EB40 0C019798 */  jal   osCreateThread
/* 039F44 8005EB44 AFA20014 */   sw    $v0, 0x14($sp)
/* 039F48 8005EB48 0C019808 */  jal   osStartThread
/* 039F4C 8005EB4C 0240202D */   daddu $a0, $s2, $zero
/* 039F50 8005EB50 26120294 */  addiu $s2, $s0, 0x294
/* 039F54 8005EB54 0240202D */  daddu $a0, $s2, $zero
/* 039F58 8005EB58 24050012 */  addiu $a1, $zero, 0x12
/* 039F5C 8005EB5C 3C068006 */  lui   $a2, 0x8006
/* 039F60 8005EB60 24C6EBE0 */  addiu $a2, $a2, -0x1420
/* 039F64 8005EB64 0220382D */  daddu $a3, $s1, $zero
/* 039F68 8005EB68 3C02800B */  lui   $v0, 0x800b
/* 039F6C 8005EB6C 2442A5D0 */  addiu $v0, $v0, -0x5a30
/* 039F70 8005EB70 AFA20010 */  sw    $v0, 0x10($sp)
/* 039F74 8005EB74 2402006E */  addiu $v0, $zero, 0x6e
/* 039F78 8005EB78 0C019798 */  jal   osCreateThread
/* 039F7C 8005EB7C AFA20014 */   sw    $v0, 0x14($sp)
/* 039F80 8005EB80 0C019808 */  jal   osStartThread
/* 039F84 8005EB84 0240202D */   daddu $a0, $s2, $zero
/* 039F88 8005EB88 26100444 */  addiu $s0, $s0, 0x444
/* 039F8C 8005EB8C 0200202D */  daddu $a0, $s0, $zero
/* 039F90 8005EB90 24050011 */  addiu $a1, $zero, 0x11
/* 039F94 8005EB94 3C068006 */  lui   $a2, 0x8006
/* 039F98 8005EB98 24C6ED14 */  addiu $a2, $a2, -0x12ec
/* 039F9C 8005EB9C 0220382D */  daddu $a3, $s1, $zero
/* 039FA0 8005EBA0 3C02800B */  lui   $v0, 0x800b
/* 039FA4 8005EBA4 2442C5D0 */  addiu $v0, $v0, -0x3a30
/* 039FA8 8005EBA8 AFA20010 */  sw    $v0, 0x10($sp)
/* 039FAC 8005EBAC 24020064 */  addiu $v0, $zero, 0x64
/* 039FB0 8005EBB0 0C019798 */  jal   osCreateThread
/* 039FB4 8005EBB4 AFA20014 */   sw    $v0, 0x14($sp)
/* 039FB8 8005EBB8 0C019808 */  jal   osStartThread
/* 039FBC 8005EBBC 0200202D */   daddu $a0, $s0, $zero
/* 039FC0 8005EBC0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 039FC4 8005EBC4 8FB40028 */  lw    $s4, 0x28($sp)
/* 039FC8 8005EBC8 8FB30024 */  lw    $s3, 0x24($sp)
/* 039FCC 8005EBCC 8FB20020 */  lw    $s2, 0x20($sp)
/* 039FD0 8005EBD0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 039FD4 8005EBD4 8FB00018 */  lw    $s0, 0x18($sp)
/* 039FD8 8005EBD8 03E00008 */  jr    $ra
/* 039FDC 8005EBDC 27BD0030 */   addiu $sp, $sp, 0x30

