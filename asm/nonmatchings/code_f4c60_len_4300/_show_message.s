.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel _show_message
/* 0F4CD0 802D0320 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0F4CD4 802D0324 AFB20038 */  sw    $s2, 0x38($sp)
/* 0F4CD8 802D0328 0080902D */  daddu $s2, $a0, $zero
/* 0F4CDC 802D032C AFB50044 */  sw    $s5, 0x44($sp)
/* 0F4CE0 802D0330 0000A82D */  daddu $s5, $zero, $zero
/* 0F4CE4 802D0334 AFB7004C */  sw    $s7, 0x4c($sp)
/* 0F4CE8 802D0338 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0F4CEC 802D033C 3C138011 */  lui   $s3, 0x8011
/* 0F4CF0 802D0340 2673EFC8 */  addiu $s3, $s3, -0x1038
/* 0F4CF4 802D0344 AFBF0054 */  sw    $ra, 0x54($sp)
/* 0F4CF8 802D0348 AFBE0050 */  sw    $fp, 0x50($sp)
/* 0F4CFC 802D034C AFB60048 */  sw    $s6, 0x48($sp)
/* 0F4D00 802D0350 AFB40040 */  sw    $s4, 0x40($sp)
/* 0F4D04 802D0354 AFB10034 */  sw    $s1, 0x34($sp)
/* 0F4D08 802D0358 AFB00030 */  sw    $s0, 0x30($sp)
/* 0F4D0C 802D035C F7B40058 */  sdc1  $f20, 0x58($sp)
/* 0F4D10 802D0360 8E50000C */  lw    $s0, 0xc($s2)
/* 0F4D14 802D0364 10A000CD */  beqz  $a1, .L802D069C
/* 0F4D18 802D0368 00C0B82D */   daddu $s7, $a2, $zero
/* 0F4D1C 802D036C 3C16802E */  lui   $s6, 0x802e
/* 0F4D20 802D0370 26D6B264 */  addiu $s6, $s6, -0x4d9c
/* 0F4D24 802D0374 AEC00000 */  sw    $zero, ($s6)
/* 0F4D28 802D0378 8E050000 */  lw    $a1, ($s0)
/* 0F4D2C 802D037C 0C0B1EAF */  jal   get_variable
/* 0F4D30 802D0380 26100004 */   addiu $s0, $s0, 4
/* 0F4D34 802D0384 8E050000 */  lw    $a1, ($s0)
/* 0F4D38 802D0388 26100004 */  addiu $s0, $s0, 4
/* 0F4D3C 802D038C 0240202D */  daddu $a0, $s2, $zero
/* 0F4D40 802D0390 0C0B1EAF */  jal   get_variable
/* 0F4D44 802D0394 0040F02D */   daddu $fp, $v0, $zero
/* 0F4D48 802D0398 AE4200B8 */  sw    $v0, 0xb8($s2)
/* 0F4D4C 802D039C 8E050000 */  lw    $a1, ($s0)
/* 0F4D50 802D03A0 26100004 */  addiu $s0, $s0, 4
/* 0F4D54 802D03A4 0C0B1EAF */  jal   get_variable
/* 0F4D58 802D03A8 0240202D */   daddu $a0, $s2, $zero
/* 0F4D5C 802D03AC AE4200BC */  sw    $v0, 0xbc($s2)
/* 0F4D60 802D03B0 8E050000 */  lw    $a1, ($s0)
/* 0F4D64 802D03B4 26100004 */  addiu $s0, $s0, 4
/* 0F4D68 802D03B8 0C0B1EAF */  jal   get_variable
/* 0F4D6C 802D03BC 0240202D */   daddu $a0, $s2, $zero
/* 0F4D70 802D03C0 3C14802E */  lui   $s4, 0x802e
/* 0F4D74 802D03C4 2694AE54 */  addiu $s4, $s4, -0x51ac
/* 0F4D78 802D03C8 AE420074 */  sw    $v0, 0x74($s2)
/* 0F4D7C 802D03CC AE800000 */  sw    $zero, ($s4)
/* 0F4D80 802D03D0 8E420074 */  lw    $v0, 0x74($s2)
/* 0F4D84 802D03D4 3C11802E */  lui   $s1, 0x802e
/* 0F4D88 802D03D8 2631AE50 */  addiu $s1, $s1, -0x51b0
/* 0F4D8C 802D03DC 30420100 */  andi  $v0, $v0, 0x100
/* 0F4D90 802D03E0 1040000B */  beqz  $v0, .L802D0410
/* 0F4D94 802D03E4 AE200000 */   sw    $zero, ($s1)
/* 0F4D98 802D03E8 8E050000 */  lw    $a1, ($s0)
/* 0F4D9C 802D03EC 26100004 */  addiu $s0, $s0, 4
/* 0F4DA0 802D03F0 0C0B1EAF */  jal   get_variable
/* 0F4DA4 802D03F4 0240202D */   daddu $a0, $s2, $zero
/* 0F4DA8 802D03F8 AE220000 */  sw    $v0, ($s1)
/* 0F4DAC 802D03FC 8E050000 */  lw    $a1, ($s0)
/* 0F4DB0 802D0400 26100004 */  addiu $s0, $s0, 4
/* 0F4DB4 802D0404 0C0B1EAF */  jal   get_variable
/* 0F4DB8 802D0408 0240202D */   daddu $a0, $s2, $zero
/* 0F4DBC 802D040C AE820000 */  sw    $v0, ($s4)
.L802D0410:
/* 0F4DC0 802D0410 24020001 */  addiu $v0, $zero, 1
/* 0F4DC4 802D0414 12E20012 */  beq   $s7, $v0, .L802D0460
/* 0F4DC8 802D0418 2AE20002 */   slti  $v0, $s7, 2
/* 0F4DCC 802D041C 10400005 */  beqz  $v0, .L802D0434
/* 0F4DD0 802D0420 24020002 */   addiu $v0, $zero, 2
/* 0F4DD4 802D0424 12E00009 */  beqz  $s7, .L802D044C
/* 0F4DD8 802D0428 2402FFFE */   addiu $v0, $zero, -2
/* 0F4DDC 802D042C 080B413A */  j     .L802D04E8
/* 0F4DE0 802D0430 00000000 */   nop   

.L802D0434:
/* 0F4DE4 802D0434 12E20010 */  beq   $s7, $v0, .L802D0478
/* 0F4DE8 802D0438 24020003 */   addiu $v0, $zero, 3
/* 0F4DEC 802D043C 12E20017 */  beq   $s7, $v0, .L802D049C
/* 0F4DF0 802D0440 2402FFFE */   addiu $v0, $zero, -2
/* 0F4DF4 802D0444 080B413A */  j     .L802D04E8
/* 0F4DF8 802D0448 00000000 */   nop   

.L802D044C:
/* 0F4DFC 802D044C 8E050000 */  lw    $a1, ($s0)
/* 0F4E00 802D0450 0C0B1EAF */  jal   get_variable
/* 0F4E04 802D0454 0240202D */   daddu $a0, $s2, $zero
/* 0F4E08 802D0458 080B4135 */  j     .L802D04D4
/* 0F4E0C 802D045C 0040202D */   daddu $a0, $v0, $zero

.L802D0460:
/* 0F4E10 802D0460 3C04802E */  lui   $a0, 0x802e
/* 0F4E14 802D0464 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F4E18 802D0468 0C04971C */  jal   close_message
/* 0F4E1C 802D046C 00000000 */   nop   
/* 0F4E20 802D0470 080B413A */  j     .L802D04E8
/* 0F4E24 802D0474 2402FFFE */   addiu $v0, $zero, -2

.L802D0478:
/* 0F4E28 802D0478 8E050000 */  lw    $a1, ($s0)
/* 0F4E2C 802D047C 0C0B1EAF */  jal   get_variable
/* 0F4E30 802D0480 0240202D */   daddu $a0, $s2, $zero
/* 0F4E34 802D0484 3C05802E */  lui   $a1, 0x802e
/* 0F4E38 802D0488 8CA5B260 */  lw    $a1, -0x4da0($a1)
/* 0F4E3C 802D048C 0C04969A */  jal   load_message_to_printer
/* 0F4E40 802D0490 0040202D */   daddu $a0, $v0, $zero
/* 0F4E44 802D0494 080B413A */  j     .L802D04E8
/* 0F4E48 802D0498 2402FFFE */   addiu $v0, $zero, -2

.L802D049C:
/* 0F4E4C 802D049C 8E050000 */  lw    $a1, ($s0)
/* 0F4E50 802D04A0 26100004 */  addiu $s0, $s0, 4
/* 0F4E54 802D04A4 0C0B1EAF */  jal   get_variable
/* 0F4E58 802D04A8 0240202D */   daddu $a0, $s2, $zero
/* 0F4E5C 802D04AC 0240202D */  daddu $a0, $s2, $zero
/* 0F4E60 802D04B0 8E050000 */  lw    $a1, ($s0)
/* 0F4E64 802D04B4 0C0B1EAF */  jal   get_variable
/* 0F4E68 802D04B8 0040802D */   daddu $s0, $v0, $zero
/* 0F4E6C 802D04BC 0240202D */  daddu $a0, $s2, $zero
/* 0F4E70 802D04C0 0200282D */  daddu $a1, $s0, $zero
/* 0F4E74 802D04C4 0C0B36B0 */  jal   func_802CDAC0
/* 0F4E78 802D04C8 0040802D */   daddu $s0, $v0, $zero
/* 0F4E7C 802D04CC 0040A82D */  daddu $s5, $v0, $zero
/* 0F4E80 802D04D0 0200202D */  daddu $a0, $s0, $zero
.L802D04D4:
/* 0F4E84 802D04D4 0C049640 */  jal   load_string
/* 0F4E88 802D04D8 02C0282D */   daddu $a1, $s6, $zero
/* 0F4E8C 802D04DC 3C01802E */  lui   $at, 0x802e
/* 0F4E90 802D04E0 AC22B260 */  sw    $v0, -0x4da0($at)
/* 0F4E94 802D04E4 2402FFFE */  addiu $v0, $zero, -2
.L802D04E8:
/* 0F4E98 802D04E8 17C20018 */  bne   $fp, $v0, .L802D054C
/* 0F4E9C 802D04EC 0240202D */   daddu $a0, $s2, $zero
/* 0F4EA0 802D04F0 8E650028 */  lw    $a1, 0x28($s3)
/* 0F4EA4 802D04F4 8E670030 */  lw    $a3, 0x30($s3)
/* 0F4EA8 802D04F8 27A20020 */  addiu $v0, $sp, 0x20
/* 0F4EAC 802D04FC AFA20010 */  sw    $v0, 0x10($sp)
/* 0F4EB0 802D0500 27A20024 */  addiu $v0, $sp, 0x24
/* 0F4EB4 802D0504 AFA20014 */  sw    $v0, 0x14($sp)
/* 0F4EB8 802D0508 866200B0 */  lh    $v0, 0xb0($s3)
/* 0F4EBC 802D050C C662002C */  lwc1  $f2, 0x2c($s3)
/* 0F4EC0 802D0510 44820000 */  mtc1  $v0, $f0
/* 0F4EC4 802D0514 00000000 */  nop   
/* 0F4EC8 802D0518 46800020 */  cvt.s.w $f0, $f0
/* 0F4ECC 802D051C 46001080 */  add.s $f2, $f2, $f0
/* 0F4ED0 802D0520 3C048007 */  lui   $a0, 0x8007
/* 0F4ED4 802D0524 8C847410 */  lw    $a0, 0x7410($a0)
/* 0F4ED8 802D0528 44061000 */  mfc1  $a2, $f2
/* 0F4EDC 802D052C 27A20028 */  addiu $v0, $sp, 0x28
/* 0F4EE0 802D0530 0C00B94E */  jal   get_screen_coords
/* 0F4EE4 802D0534 AFA20018 */   sw    $v0, 0x18($sp)
/* 0F4EE8 802D0538 8E6200B8 */  lw    $v0, 0xb8($s3)
/* 0F4EEC 802D053C AE42007C */  sw    $v0, 0x7c($s2)
/* 0F4EF0 802D0540 C6600080 */  lwc1  $f0, 0x80($s3)
/* 0F4EF4 802D0544 080B416C */  j     .L802D05B0
/* 0F4EF8 802D0548 2410FFFE */   addiu $s0, $zero, -2

.L802D054C:
/* 0F4EFC 802D054C 0C0B36B0 */  jal   func_802CDAC0
/* 0F4F00 802D0550 03C0282D */   daddu $a1, $fp, $zero
/* 0F4F04 802D0554 0040802D */  daddu $s0, $v0, $zero
/* 0F4F08 802D0558 3C048007 */  lui   $a0, 0x8007
/* 0F4F0C 802D055C 8C847410 */  lw    $a0, 0x7410($a0)
/* 0F4F10 802D0560 860300A8 */  lh    $v1, 0xa8($s0)
/* 0F4F14 802D0564 C602003C */  lwc1  $f2, 0x3c($s0)
/* 0F4F18 802D0568 27A20020 */  addiu $v0, $sp, 0x20
/* 0F4F1C 802D056C AFA20010 */  sw    $v0, 0x10($sp)
/* 0F4F20 802D0570 27A20024 */  addiu $v0, $sp, 0x24
/* 0F4F24 802D0574 AFA20014 */  sw    $v0, 0x14($sp)
/* 0F4F28 802D0578 27A20028 */  addiu $v0, $sp, 0x28
/* 0F4F2C 802D057C AFA20018 */  sw    $v0, 0x18($sp)
/* 0F4F30 802D0580 44830000 */  mtc1  $v1, $f0
/* 0F4F34 802D0584 00000000 */  nop   
/* 0F4F38 802D0588 46800020 */  cvt.s.w $f0, $f0
/* 0F4F3C 802D058C 46001080 */  add.s $f2, $f2, $f0
/* 0F4F40 802D0590 8E050038 */  lw    $a1, 0x38($s0)
/* 0F4F44 802D0594 8E070040 */  lw    $a3, 0x40($s0)
/* 0F4F48 802D0598 44061000 */  mfc1  $a2, $f2
/* 0F4F4C 802D059C 0C00B94E */  jal   get_screen_coords
/* 0F4F50 802D05A0 00000000 */   nop   
/* 0F4F54 802D05A4 8E020028 */  lw    $v0, 0x28($s0)
/* 0F4F58 802D05A8 AE42007C */  sw    $v0, 0x7c($s2)
/* 0F4F5C 802D05AC C600000C */  lwc1  $f0, 0xc($s0)
.L802D05B0:
/* 0F4F60 802D05B0 4600010D */  trunc.w.s $f4, $f0
/* 0F4F64 802D05B4 E64400C0 */  swc1  $f4, 0xc0($s2)
/* 0F4F68 802D05B8 3C04802E */  lui   $a0, 0x802e
/* 0F4F6C 802D05BC 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F4F70 802D05C0 8FA30020 */  lw    $v1, 0x20($sp)
/* 0F4F74 802D05C4 3C05802E */  lui   $a1, 0x802e
/* 0F4F78 802D05C8 8CA5AE50 */  lw    $a1, -0x51b0($a1)
/* 0F4F7C 802D05CC 8FA20024 */  lw    $v0, 0x24($sp)
/* 0F4F80 802D05D0 3C06802E */  lui   $a2, 0x802e
/* 0F4F84 802D05D4 8CC6AE54 */  lw    $a2, -0x51ac($a2)
/* 0F4F88 802D05D8 00652821 */  addu  $a1, $v1, $a1
/* 0F4F8C 802D05DC 0C0496AE */  jal   clamp_printer_coords
/* 0F4F90 802D05E0 00463021 */   addu  $a2, $v0, $a2
/* 0F4F94 802D05E4 2402FFFE */  addiu $v0, $zero, -2
/* 0F4F98 802D05E8 1202002C */  beq   $s0, $v0, .L802D069C
/* 0F4F9C 802D05EC AE5000B4 */   sw    $s0, 0xb4($s2)
/* 0F4FA0 802D05F0 24020003 */  addiu $v0, $zero, 3
/* 0F4FA4 802D05F4 16E20007 */  bne   $s7, $v0, .L802D0614
/* 0F4FA8 802D05F8 26710080 */   addiu $s1, $s3, 0x80
/* 0F4FAC 802D05FC C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F4FB0 802D0600 C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F4FB4 802D0604 8EA60038 */  lw    $a2, 0x38($s5)
/* 0F4FB8 802D0608 8EA70040 */  lw    $a3, 0x40($s5)
/* 0F4FBC 802D060C 080B4189 */  j     .L802D0624
/* 0F4FC0 802D0610 26B1000C */   addiu $s1, $s5, 0xc

.L802D0614:
/* 0F4FC4 802D0614 C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F4FC8 802D0618 C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F4FCC 802D061C 8E660028 */  lw    $a2, 0x28($s3)
/* 0F4FD0 802D0620 8E670030 */  lw    $a3, 0x30($s3)
.L802D0624:
/* 0F4FD4 802D0624 0C00A720 */  jal   atan2
/* 0F4FD8 802D0628 00000000 */   nop   
/* 0F4FDC 802D062C 46000506 */  mov.s $f20, $f0
/* 0F4FE0 802D0630 3C014334 */  lui   $at, 0x4334
/* 0F4FE4 802D0634 44816000 */  mtc1  $at, $f12
/* 0F4FE8 802D0638 0C00A6C9 */  jal   clamp_angle
/* 0F4FEC 802D063C 460CA300 */   add.s $f12, $f20, $f12
/* 0F4FF0 802D0640 8E420074 */  lw    $v0, 0x74($s2)
/* 0F4FF4 802D0644 3043000F */  andi  $v1, $v0, 0xf
/* 0F4FF8 802D0648 2C620006 */  sltiu $v0, $v1, 6
/* 0F4FFC 802D064C 10400013 */  beqz  $v0, .L802D069C
/* 0F5000 802D0650 00031080 */   sll   $v0, $v1, 2
/* 0F5004 802D0654 3C01802E */  lui   $at, 0x802e
/* 0F5008 802D0658 00220821 */  addu  $at, $at, $v0
/* 0F500C 802D065C 8C22A1F0 */  lw    $v0, -0x5e10($at)
/* 0F5010 802D0660 00400008 */  jr    $v0
/* 0F5014 802D0664 00000000 */   nop   
/* 0F5018 802D0668 E614000C */  swc1  $f20, 0xc($s0)
/* 0F501C 802D066C 080B41A7 */  j     .L802D069C
/* 0F5020 802D0670 E6200000 */   swc1  $f0, ($s1)

/* 0F5024 802D0674 E600000C */  swc1  $f0, 0xc($s0)
/* 0F5028 802D0678 080B41A7 */  j     .L802D069C
/* 0F502C 802D067C E6200000 */   swc1  $f0, ($s1)

/* 0F5030 802D0680 E614000C */  swc1  $f20, 0xc($s0)
/* 0F5034 802D0684 080B41A7 */  j     .L802D069C
/* 0F5038 802D0688 E6340000 */   swc1  $f20, ($s1)

/* 0F503C 802D068C E600000C */  swc1  $f0, 0xc($s0)
/* 0F5040 802D0690 080B41A7 */  j     .L802D069C
/* 0F5044 802D0694 E6340000 */   swc1  $f20, ($s1)

/* 0F5048 802D0698 E614000C */  swc1  $f20, 0xc($s0)
.L802D069C:
/* 0F504C 802D069C 8E5000B4 */  lw    $s0, 0xb4($s2)
/* 0F5050 802D06A0 2402FFFE */  addiu $v0, $zero, -2
/* 0F5054 802D06A4 12020022 */  beq   $s0, $v0, .L802D0730
/* 0F5058 802D06A8 27A20020 */   addiu $v0, $sp, 0x20
/* 0F505C 802D06AC 3C048007 */  lui   $a0, 0x8007
/* 0F5060 802D06B0 8C847410 */  lw    $a0, 0x7410($a0)
/* 0F5064 802D06B4 860300A8 */  lh    $v1, 0xa8($s0)
/* 0F5068 802D06B8 C602003C */  lwc1  $f2, 0x3c($s0)
/* 0F506C 802D06BC AFA20010 */  sw    $v0, 0x10($sp)
/* 0F5070 802D06C0 27A20024 */  addiu $v0, $sp, 0x24
/* 0F5074 802D06C4 AFA20014 */  sw    $v0, 0x14($sp)
/* 0F5078 802D06C8 27A20028 */  addiu $v0, $sp, 0x28
/* 0F507C 802D06CC AFA20018 */  sw    $v0, 0x18($sp)
/* 0F5080 802D06D0 44830000 */  mtc1  $v1, $f0
/* 0F5084 802D06D4 00000000 */  nop   
/* 0F5088 802D06D8 46800020 */  cvt.s.w $f0, $f0
/* 0F508C 802D06DC 46001080 */  add.s $f2, $f2, $f0
/* 0F5090 802D06E0 8E050038 */  lw    $a1, 0x38($s0)
/* 0F5094 802D06E4 8E070040 */  lw    $a3, 0x40($s0)
/* 0F5098 802D06E8 44061000 */  mfc1  $a2, $f2
/* 0F509C 802D06EC 0C00B94E */  jal   get_screen_coords
/* 0F50A0 802D06F0 00000000 */   nop   
/* 0F50A4 802D06F4 8E4500B8 */  lw    $a1, 0xb8($s2)
/* 0F50A8 802D06F8 2402FFFF */  addiu $v0, $zero, -1
/* 0F50AC 802D06FC 10A2002B */  beq   $a1, $v0, .L802D07AC
/* 0F50B0 802D0700 00000000 */   nop   
/* 0F50B4 802D0704 3C02802E */  lui   $v0, 0x802e
/* 0F50B8 802D0708 8C42B260 */  lw    $v0, -0x4da0($v0)
/* 0F50BC 802D070C 8C4204FC */  lw    $v0, 0x4fc($v0)
/* 0F50C0 802D0710 30420080 */  andi  $v0, $v0, 0x80
/* 0F50C4 802D0714 14400002 */  bnez  $v0, .L802D0720
/* 0F50C8 802D0718 00000000 */   nop   
/* 0F50CC 802D071C 8E4500BC */  lw    $a1, 0xbc($s2)
.L802D0720:
/* 0F50D0 802D0720 0C0B36C3 */  jal   set_npc_animation
/* 0F50D4 802D0724 0200202D */   daddu $a0, $s0, $zero
/* 0F50D8 802D0728 080B41EB */  j     .L802D07AC
/* 0F50DC 802D072C 00000000 */   nop   

.L802D0730:
/* 0F50E0 802D0730 8E650028 */  lw    $a1, 0x28($s3)
/* 0F50E4 802D0734 8E670030 */  lw    $a3, 0x30($s3)
/* 0F50E8 802D0738 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F50EC 802D073C 27A20024 */  addiu $v0, $sp, 0x24
/* 0F50F0 802D0740 AFA20014 */  sw    $v0, 0x14($sp)
/* 0F50F4 802D0744 866200B0 */  lh    $v0, 0xb0($s3)
/* 0F50F8 802D0748 C662002C */  lwc1  $f2, 0x2c($s3)
/* 0F50FC 802D074C 44820000 */  mtc1  $v0, $f0
/* 0F5100 802D0750 00000000 */  nop   
/* 0F5104 802D0754 46800020 */  cvt.s.w $f0, $f0
/* 0F5108 802D0758 46001080 */  add.s $f2, $f2, $f0
/* 0F510C 802D075C 3C048007 */  lui   $a0, 0x8007
/* 0F5110 802D0760 8C847410 */  lw    $a0, 0x7410($a0)
/* 0F5114 802D0764 44061000 */  mfc1  $a2, $f2
/* 0F5118 802D0768 27A20028 */  addiu $v0, $sp, 0x28
/* 0F511C 802D076C 0C00B94E */  jal   get_screen_coords
/* 0F5120 802D0770 AFA20018 */   sw    $v0, 0x18($sp)
/* 0F5124 802D0774 8E4300B8 */  lw    $v1, 0xb8($s2)
/* 0F5128 802D0778 2402FFFF */  addiu $v0, $zero, -1
/* 0F512C 802D077C 1062000B */  beq   $v1, $v0, .L802D07AC
/* 0F5130 802D0780 00000000 */   nop   
/* 0F5134 802D0784 3C02802E */  lui   $v0, 0x802e
/* 0F5138 802D0788 8C42B260 */  lw    $v0, -0x4da0($v0)
/* 0F513C 802D078C 8C4204FC */  lw    $v0, 0x4fc($v0)
/* 0F5140 802D0790 30420080 */  andi  $v0, $v0, 0x80
/* 0F5144 802D0794 10400003 */  beqz  $v0, .L802D07A4
/* 0F5148 802D0798 00000000 */   nop   
/* 0F514C 802D079C 080B41EB */  j     .L802D07AC
/* 0F5150 802D07A0 AE6300B8 */   sw    $v1, 0xb8($s3)

.L802D07A4:
/* 0F5154 802D07A4 8E4200BC */  lw    $v0, 0xbc($s2)
/* 0F5158 802D07A8 AE6200B8 */  sw    $v0, 0xb8($s3)
.L802D07AC:
/* 0F515C 802D07AC 8E420074 */  lw    $v0, 0x74($s2)
/* 0F5160 802D07B0 30420200 */  andi  $v0, $v0, 0x200
/* 0F5164 802D07B4 1440000C */  bnez  $v0, .L802D07E8
/* 0F5168 802D07B8 00000000 */   nop   
/* 0F516C 802D07BC 3C04802E */  lui   $a0, 0x802e
/* 0F5170 802D07C0 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F5174 802D07C4 8FA30020 */  lw    $v1, 0x20($sp)
/* 0F5178 802D07C8 3C05802E */  lui   $a1, 0x802e
/* 0F517C 802D07CC 8CA5AE50 */  lw    $a1, -0x51b0($a1)
/* 0F5180 802D07D0 8FA20024 */  lw    $v0, 0x24($sp)
/* 0F5184 802D07D4 3C06802E */  lui   $a2, 0x802e
/* 0F5188 802D07D8 8CC6AE54 */  lw    $a2, -0x51ac($a2)
/* 0F518C 802D07DC 00652821 */  addu  $a1, $v1, $a1
/* 0F5190 802D07E0 0C0496AE */  jal   clamp_printer_coords
/* 0F5194 802D07E4 00463021 */   addu  $a2, $v0, $a2
.L802D07E8:
/* 0F5198 802D07E8 3C02802E */  lui   $v0, 0x802e
/* 0F519C 802D07EC 8C42B260 */  lw    $v0, -0x4da0($v0)
/* 0F51A0 802D07F0 8C4204FC */  lw    $v0, 0x4fc($v0)
/* 0F51A4 802D07F4 30420040 */  andi  $v0, $v0, 0x40
/* 0F51A8 802D07F8 14400019 */  bnez  $v0, .L802D0860
/* 0F51AC 802D07FC 24020001 */   addiu $v0, $zero, 1
/* 0F51B0 802D0800 3C03802E */  lui   $v1, 0x802e
/* 0F51B4 802D0804 8C63B264 */  lw    $v1, -0x4d9c($v1)
/* 0F51B8 802D0808 14620015 */  bne   $v1, $v0, .L802D0860
/* 0F51BC 802D080C 0000102D */   daddu $v0, $zero, $zero
/* 0F51C0 802D0810 8E4300B8 */  lw    $v1, 0xb8($s2)
/* 0F51C4 802D0814 2402FFFF */  addiu $v0, $zero, -1
/* 0F51C8 802D0818 1062000A */  beq   $v1, $v0, .L802D0844
/* 0F51CC 802D081C 2402FFFE */   addiu $v0, $zero, -2
/* 0F51D0 802D0820 12020006 */  beq   $s0, $v0, .L802D083C
/* 0F51D4 802D0824 00000000 */   nop   
/* 0F51D8 802D0828 8E45007C */  lw    $a1, 0x7c($s2)
/* 0F51DC 802D082C 0C0B36C3 */  jal   set_npc_animation
/* 0F51E0 802D0830 0200202D */   daddu $a0, $s0, $zero
/* 0F51E4 802D0834 080B4211 */  j     .L802D0844
/* 0F51E8 802D0838 00000000 */   nop   

.L802D083C:
/* 0F51EC 802D083C 8E42007C */  lw    $v0, 0x7c($s2)
/* 0F51F0 802D0840 AE6200B8 */  sw    $v0, 0xb8($s3)
.L802D0844:
/* 0F51F4 802D0844 8E420074 */  lw    $v0, 0x74($s2)
/* 0F51F8 802D0848 30420010 */  andi  $v0, $v0, 0x10
/* 0F51FC 802D084C 10400004 */  beqz  $v0, .L802D0860
/* 0F5200 802D0850 24020001 */   addiu $v0, $zero, 1
/* 0F5204 802D0854 C64000C0 */  lwc1  $f0, 0xc0($s2)
/* 0F5208 802D0858 46800020 */  cvt.s.w $f0, $f0
/* 0F520C 802D085C E600000C */  swc1  $f0, 0xc($s0)
.L802D0860:
/* 0F5210 802D0860 8FBF0054 */  lw    $ra, 0x54($sp)
/* 0F5214 802D0864 8FBE0050 */  lw    $fp, 0x50($sp)
/* 0F5218 802D0868 8FB7004C */  lw    $s7, 0x4c($sp)
/* 0F521C 802D086C 8FB60048 */  lw    $s6, 0x48($sp)
/* 0F5220 802D0870 8FB50044 */  lw    $s5, 0x44($sp)
/* 0F5224 802D0874 8FB40040 */  lw    $s4, 0x40($sp)
/* 0F5228 802D0878 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0F522C 802D087C 8FB20038 */  lw    $s2, 0x38($sp)
/* 0F5230 802D0880 8FB10034 */  lw    $s1, 0x34($sp)
/* 0F5234 802D0884 8FB00030 */  lw    $s0, 0x30($sp)
/* 0F5238 802D0888 D7B40058 */  ldc1  $f20, 0x58($sp)
/* 0F523C 802D088C 03E00008 */  jr    $ra
/* 0F5240 802D0890 27BD0060 */   addiu $sp, $sp, 0x60

