.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802E3A00
/* 105280 802E3A00 2403000E */  addiu $v1, $zero, 0xe
/* 105284 802E3A04 9082000A */  lbu   $v0, 0xa($a0)
/* 105288 802E3A08 8C840040 */  lw    $a0, 0x40($a0)
/* 10528C 802E3A0C 1443000C */  bne   $v0, $v1, .L802E3A40
/* 105290 802E3A10 2402000A */   addiu $v0, $zero, 0xa
/* 105294 802E3A14 84830004 */  lh    $v1, 4($a0)
/* 105298 802E3A18 10620009 */  beq   $v1, $v0, .L802E3A40
/* 10529C 802E3A1C 00000000 */   nop   
/* 1052A0 802E3A20 94820006 */  lhu   $v0, 6($a0)
/* 1052A4 802E3A24 2442FFFF */  addiu $v0, $v0, -1
/* 1052A8 802E3A28 A4820006 */  sh    $v0, 6($a0)
/* 1052AC 802E3A2C 00021400 */  sll   $v0, $v0, 0x10
/* 1052B0 802E3A30 04410003 */  bgez  $v0, .L802E3A40
/* 1052B4 802E3A34 24020001 */   addiu $v0, $zero, 1
/* 1052B8 802E3A38 A4800006 */  sh    $zero, 6($a0)
/* 1052BC 802E3A3C A4820004 */  sh    $v0, 4($a0)
.L802E3A40:
/* 1052C0 802E3A40 03E00008 */  jr    $ra
/* 1052C4 802E3A44 00000000 */   nop   

/* 1052C8 802E3A48 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1052CC 802E3A4C AFB00018 */  sw    $s0, 0x18($sp)
/* 1052D0 802E3A50 0080802D */  daddu $s0, $a0, $zero
/* 1052D4 802E3A54 AFBF0020 */  sw    $ra, 0x20($sp)
/* 1052D8 802E3A58 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1052DC 802E3A5C 92020006 */  lbu   $v0, 6($s0)
/* 1052E0 802E3A60 8E110040 */  lw    $s1, 0x40($s0)
/* 1052E4 802E3A64 30420080 */  andi  $v0, $v0, 0x80
/* 1052E8 802E3A68 10400005 */  beqz  $v0, .L802E3A80
/* 1052EC 802E3A6C 00000000 */   nop   
/* 1052F0 802E3A70 0C043F5A */  jal   func_8010FD68
/* 1052F4 802E3A74 00000000 */   nop   
/* 1052F8 802E3A78 080B8EBD */  j     .L802E3AF4
/* 1052FC 802E3A7C 00000000 */   nop   

.L802E3A80:
/* 105300 802E3A80 0C0B8E80 */  jal   func_802E3A00
/* 105304 802E3A84 0200202D */   daddu $a0, $s0, $zero
/* 105308 802E3A88 0C0B8D94 */  jal   func_802E3650
/* 10530C 802E3A8C 0200202D */   daddu $a0, $s0, $zero
/* 105310 802E3A90 82220003 */  lb    $v0, 3($s1)
/* 105314 802E3A94 10400017 */  beqz  $v0, .L802E3AF4
/* 105318 802E3A98 3C028000 */   lui   $v0, 0x8000
/* 10531C 802E3A9C 3C04802F */  lui   $a0, 0x802f
/* 105320 802E3AA0 2484A07C */  addiu $a0, $a0, -0x5f84
/* 105324 802E3AA4 C6020048 */  lwc1  $f2, 0x48($s0)
/* 105328 802E3AA8 C604004C */  lwc1  $f4, 0x4c($s0)
/* 10532C 802E3AAC C6060050 */  lwc1  $f6, 0x50($s0)
/* 105330 802E3AB0 C6000064 */  lwc1  $f0, 0x64($s0)
/* 105334 802E3AB4 AFA20014 */  sw    $v0, 0x14($sp)
/* 105338 802E3AB8 4600020D */  trunc.w.s $f8, $f0
/* 10533C 802E3ABC E7A80010 */  swc1  $f8, 0x10($sp)
/* 105340 802E3AC0 4600120D */  trunc.w.s $f8, $f2
/* 105344 802E3AC4 44054000 */  mfc1  $a1, $f8
/* 105348 802E3AC8 4600220D */  trunc.w.s $f8, $f4
/* 10534C 802E3ACC 44064000 */  mfc1  $a2, $f8
/* 105350 802E3AD0 4600320D */  trunc.w.s $f8, $f6
/* 105354 802E3AD4 44074000 */  mfc1  $a3, $f8
/* 105358 802E3AD8 0C044631 */  jal   create_entity
/* 10535C 802E3ADC 00000000 */   nop   
/* 105360 802E3AE0 3C032000 */  lui   $v1, 0x2000
/* 105364 802E3AE4 8E020000 */  lw    $v0, ($s0)
/* 105368 802E3AE8 34630020 */  ori   $v1, $v1, 0x20
/* 10536C 802E3AEC 00431025 */  or    $v0, $v0, $v1
/* 105370 802E3AF0 AE020000 */  sw    $v0, ($s0)
.L802E3AF4:
/* 105374 802E3AF4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 105378 802E3AF8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 10537C 802E3AFC 8FB00018 */  lw    $s0, 0x18($sp)
/* 105380 802E3B00 03E00008 */  jr    $ra
/* 105384 802E3B04 27BD0028 */   addiu $sp, $sp, 0x28

/* 105388 802E3B08 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 10538C 802E3B0C AFB00018 */  sw    $s0, 0x18($sp)
/* 105390 802E3B10 0080802D */  daddu $s0, $a0, $zero
/* 105394 802E3B14 AFBF001C */  sw    $ra, 0x1c($sp)
/* 105398 802E3B18 8E040040 */  lw    $a0, 0x40($s0)
/* 10539C 802E3B1C 9483000A */  lhu   $v1, 0xa($a0)
/* 1053A0 802E3B20 3402FFFF */  ori   $v0, $zero, 0xffff
/* 1053A4 802E3B24 1062001B */  beq   $v1, $v0, .L802E3B94
/* 1053A8 802E3B28 00000000 */   nop   
/* 1053AC 802E3B2C 0C05152F */  jal   get_global_flag
/* 1053B0 802E3B30 0060202D */   daddu $a0, $v1, $zero
/* 1053B4 802E3B34 10400017 */  beqz  $v0, .L802E3B94
/* 1053B8 802E3B38 3C028000 */   lui   $v0, 0x8000
/* 1053BC 802E3B3C 3C04802F */  lui   $a0, 0x802f
/* 1053C0 802E3B40 2484A07C */  addiu $a0, $a0, -0x5f84
/* 1053C4 802E3B44 C6020048 */  lwc1  $f2, 0x48($s0)
/* 1053C8 802E3B48 C604004C */  lwc1  $f4, 0x4c($s0)
/* 1053CC 802E3B4C C6060050 */  lwc1  $f6, 0x50($s0)
/* 1053D0 802E3B50 C6000064 */  lwc1  $f0, 0x64($s0)
/* 1053D4 802E3B54 AFA20014 */  sw    $v0, 0x14($sp)
/* 1053D8 802E3B58 4600020D */  trunc.w.s $f8, $f0
/* 1053DC 802E3B5C E7A80010 */  swc1  $f8, 0x10($sp)
/* 1053E0 802E3B60 4600120D */  trunc.w.s $f8, $f2
/* 1053E4 802E3B64 44054000 */  mfc1  $a1, $f8
/* 1053E8 802E3B68 4600220D */  trunc.w.s $f8, $f4
/* 1053EC 802E3B6C 44064000 */  mfc1  $a2, $f8
/* 1053F0 802E3B70 4600320D */  trunc.w.s $f8, $f6
/* 1053F4 802E3B74 44074000 */  mfc1  $a3, $f8
/* 1053F8 802E3B78 0C044631 */  jal   create_entity
/* 1053FC 802E3B7C 00000000 */   nop   
/* 105400 802E3B80 3C032000 */  lui   $v1, 0x2000
/* 105404 802E3B84 8E020000 */  lw    $v0, ($s0)
/* 105408 802E3B88 34630020 */  ori   $v1, $v1, 0x20
/* 10540C 802E3B8C 00431025 */  or    $v0, $v0, $v1
/* 105410 802E3B90 AE020000 */  sw    $v0, ($s0)
.L802E3B94:
/* 105414 802E3B94 8FBF001C */  lw    $ra, 0x1c($sp)
/* 105418 802E3B98 8FB00018 */  lw    $s0, 0x18($sp)
/* 10541C 802E3B9C 03E00008 */  jr    $ra
/* 105420 802E3BA0 27BD0020 */   addiu $sp, $sp, 0x20

/* 105424 802E3BA4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 105428 802E3BA8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 10542C 802E3BAC 0080882D */  daddu $s1, $a0, $zero
/* 105430 802E3BB0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 105434 802E3BB4 AFB20020 */  sw    $s2, 0x20($sp)
/* 105438 802E3BB8 AFB00018 */  sw    $s0, 0x18($sp)
/* 10543C 802E3BBC 9222000B */  lbu   $v0, 0xb($s1)
/* 105440 802E3BC0 3C128011 */  lui   $s2, 0x8011
/* 105444 802E3BC4 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 105448 802E3BC8 14400005 */  bnez  $v0, .L802E3BE0
/* 10544C 802E3BCC 00000000 */   nop   
/* 105450 802E3BD0 92220006 */  lbu   $v0, 6($s1)
/* 105454 802E3BD4 30420001 */  andi  $v0, $v0, 1
/* 105458 802E3BD8 14400083 */  bnez  $v0, .L802E3DE8
/* 10545C 802E3BDC 0000102D */   daddu $v0, $zero, $zero
.L802E3BE0:
/* 105460 802E3BE0 92230006 */  lbu   $v1, 6($s1)
/* 105464 802E3BE4 30620004 */  andi  $v0, $v1, 4
/* 105468 802E3BE8 10400016 */  beqz  $v0, .L802E3C44
/* 10546C 802E3BEC 30620080 */   andi  $v0, $v1, 0x80
/* 105470 802E3BF0 92240004 */  lbu   $a0, 4($s1)
/* 105474 802E3BF4 0C0441A9 */  jal   func_801106A4
/* 105478 802E3BF8 00000000 */   nop   
/* 10547C 802E3BFC 0040182D */  daddu $v1, $v0, $zero
/* 105480 802E3C00 2402000C */  addiu $v0, $zero, 0xc
/* 105484 802E3C04 10620019 */  beq   $v1, $v0, .L802E3C6C
/* 105488 802E3C08 0062102A */   slt   $v0, $v1, $v0
/* 10548C 802E3C0C 14400005 */  bnez  $v0, .L802E3C24
/* 105490 802E3C10 2862001B */   slti  $v0, $v1, 0x1b
/* 105494 802E3C14 10400003 */  beqz  $v0, .L802E3C24
/* 105498 802E3C18 28620015 */   slti  $v0, $v1, 0x15
/* 10549C 802E3C1C 10400072 */  beqz  $v0, .L802E3DE8
/* 1054A0 802E3C20 0000102D */   daddu $v0, $zero, $zero
.L802E3C24:
/* 1054A4 802E3C24 8E420000 */  lw    $v0, ($s2)
/* 1054A8 802E3C28 30420002 */  andi  $v0, $v0, 2
/* 1054AC 802E3C2C 1040006E */  beqz  $v0, .L802E3DE8
/* 1054B0 802E3C30 24020001 */   addiu $v0, $zero, 1
.L802E3C34:
/* 1054B4 802E3C34 0C043F5A */  jal   func_8010FD68
/* 1054B8 802E3C38 0220202D */   daddu $a0, $s1, $zero
/* 1054BC 802E3C3C 080B8F7A */  j     .L802E3DE8
/* 1054C0 802E3C40 24020001 */   addiu $v0, $zero, 1

.L802E3C44:
/* 1054C4 802E3C44 1440FFFB */  bnez  $v0, .L802E3C34
/* 1054C8 802E3C48 30620001 */   andi  $v0, $v1, 1
/* 1054CC 802E3C4C 1040000F */  beqz  $v0, .L802E3C8C
/* 1054D0 802E3C50 0000802D */   daddu $s0, $zero, $zero
/* 1054D4 802E3C54 824300B4 */  lb    $v1, 0xb4($s2)
/* 1054D8 802E3C58 2402000D */  addiu $v0, $zero, 0xd
/* 1054DC 802E3C5C 10620003 */  beq   $v1, $v0, .L802E3C6C
/* 1054E0 802E3C60 2402000F */   addiu $v0, $zero, 0xf
/* 1054E4 802E3C64 14620003 */  bne   $v1, $v0, .L802E3C74
/* 1054E8 802E3C68 2402000E */   addiu $v0, $zero, 0xe
.L802E3C6C:
/* 1054EC 802E3C6C 080B8F7A */  j     .L802E3DE8
/* 1054F0 802E3C70 0000102D */   daddu $v0, $zero, $zero

.L802E3C74:
/* 1054F4 802E3C74 10620003 */  beq   $v1, $v0, .L802E3C84
/* 1054F8 802E3C78 24020010 */   addiu $v0, $zero, 0x10
/* 1054FC 802E3C7C 1462005A */  bne   $v1, $v0, .L802E3DE8
/* 105500 802E3C80 24020001 */   addiu $v0, $zero, 1
.L802E3C84:
/* 105504 802E3C84 080B8F2A */  j     .L802E3CA8
/* 105508 802E3C88 24100001 */   addiu $s0, $zero, 1

.L802E3C8C:
/* 10550C 802E3C8C 30620040 */  andi  $v0, $v1, 0x40
/* 105510 802E3C90 10400054 */  beqz  $v0, .L802E3DE4
/* 105514 802E3C94 3C030100 */   lui   $v1, 0x100
/* 105518 802E3C98 8E420000 */  lw    $v0, ($s2)
/* 10551C 802E3C9C 00431024 */  and   $v0, $v0, $v1
/* 105520 802E3CA0 10400051 */  beqz  $v0, .L802E3DE8
/* 105524 802E3CA4 24020001 */   addiu $v0, $zero, 1
.L802E3CA8:
/* 105528 802E3CA8 92240004 */  lbu   $a0, 4($s1)
/* 10552C 802E3CAC 0C0441A9 */  jal   func_801106A4
/* 105530 802E3CB0 00000000 */   nop   
/* 105534 802E3CB4 2443FFF5 */  addiu $v1, $v0, -0xb
/* 105538 802E3CB8 2C620015 */  sltiu $v0, $v1, 0x15
/* 10553C 802E3CBC 10400049 */  beqz  $v0, .L802E3DE4
/* 105540 802E3CC0 00031080 */   sll   $v0, $v1, 2
/* 105544 802E3CC4 3C01802F */  lui   $at, 0x802f
/* 105548 802E3CC8 00220821 */  addu  $at, $at, $v0
/* 10554C 802E3CCC 8C22B210 */  lw    $v0, -0x4df0($at)
/* 105550 802E3CD0 00400008 */  jr    $v0
/* 105554 802E3CD4 00000000 */   nop   
/* 105558 802E3CD8 12000007 */  beqz  $s0, .L802E3CF8
/* 10555C 802E3CDC 00000000 */   nop   
/* 105560 802E3CE0 3C028011 */  lui   $v0, 0x8011
/* 105564 802E3CE4 8042F290 */  lb    $v0, -0xd70($v0)
/* 105568 802E3CE8 58400007 */  blezl $v0, .L802E3D08
/* 10556C 802E3CEC 0000802D */   daddu $s0, $zero, $zero
/* 105570 802E3CF0 080B8F42 */  j     .L802E3D08
/* 105574 802E3CF4 00000000 */   nop   

.L802E3CF8:
/* 105578 802E3CF8 3C028011 */  lui   $v0, 0x8011
/* 10557C 802E3CFC 8042F291 */  lb    $v0, -0xd6f($v0)
/* 105580 802E3D00 04430001 */  bgezl $v0, .L802E3D08
/* 105584 802E3D04 24100001 */   addiu $s0, $zero, 1
.L802E3D08:
/* 105588 802E3D08 12000037 */  beqz  $s0, .L802E3DE8
/* 10558C 802E3D0C 24020001 */   addiu $v0, $zero, 1
/* 105590 802E3D10 3C05802F */  lui   $a1, 0x802f
/* 105594 802E3D14 24A59E80 */  addiu $a1, $a1, -0x6180
/* 105598 802E3D18 0C043EF0 */  jal   func_8010FBC0
/* 10559C 802E3D1C 0220202D */   daddu $a0, $s1, $zero
/* 1055A0 802E3D20 C6200050 */  lwc1  $f0, 0x50($s1)
/* 1055A4 802E3D24 080B8F6C */  j     .L802E3DB0
/* 1055A8 802E3D28 2404014F */   addiu $a0, $zero, 0x14f

/* 1055AC 802E3D2C 12000008 */  beqz  $s0, .L802E3D50
/* 1055B0 802E3D30 00000000 */   nop   
/* 1055B4 802E3D34 3C028011 */  lui   $v0, 0x8011
/* 1055B8 802E3D38 8042F290 */  lb    $v0, -0xd70($v0)
/* 1055BC 802E3D3C 28420002 */  slti  $v0, $v0, 2
/* 1055C0 802E3D40 54400007 */  bnel  $v0, $zero, .L802E3D60
/* 1055C4 802E3D44 0000802D */   daddu $s0, $zero, $zero
/* 1055C8 802E3D48 080B8F58 */  j     .L802E3D60
/* 1055CC 802E3D4C 00000000 */   nop   

.L802E3D50:
/* 1055D0 802E3D50 3C028011 */  lui   $v0, 0x8011
/* 1055D4 802E3D54 8042F291 */  lb    $v0, -0xd6f($v0)
/* 1055D8 802E3D58 5C400001 */  bgtzl $v0, .L802E3D60
/* 1055DC 802E3D5C 24100001 */   addiu $s0, $zero, 1
.L802E3D60:
/* 1055E0 802E3D60 12000021 */  beqz  $s0, .L802E3DE8
/* 1055E4 802E3D64 24020001 */   addiu $v0, $zero, 1
/* 1055E8 802E3D68 3C05802F */  lui   $a1, 0x802f
/* 1055EC 802E3D6C 24A59E80 */  addiu $a1, $a1, -0x6180
/* 1055F0 802E3D70 0C043EF0 */  jal   func_8010FBC0
/* 1055F4 802E3D74 0220202D */   daddu $a0, $s1, $zero
/* 1055F8 802E3D78 C6200050 */  lwc1  $f0, 0x50($s1)
/* 1055FC 802E3D7C 080B8F6C */  j     .L802E3DB0
/* 105600 802E3D80 24040150 */   addiu $a0, $zero, 0x150

/* 105604 802E3D84 3C028011 */  lui   $v0, 0x8011
/* 105608 802E3D88 8042F291 */  lb    $v0, -0xd6f($v0)
/* 10560C 802E3D8C 28420002 */  slti  $v0, $v0, 2
/* 105610 802E3D90 14400015 */  bnez  $v0, .L802E3DE8
/* 105614 802E3D94 24020001 */   addiu $v0, $zero, 1
/* 105618 802E3D98 3C05802F */  lui   $a1, 0x802f
/* 10561C 802E3D9C 24A59E80 */  addiu $a1, $a1, -0x6180
/* 105620 802E3DA0 0C043EF0 */  jal   func_8010FBC0
/* 105624 802E3DA4 0220202D */   daddu $a0, $s1, $zero
/* 105628 802E3DA8 C6200050 */  lwc1  $f0, 0x50($s1)
/* 10562C 802E3DAC 24040151 */  addiu $a0, $zero, 0x151
.L802E3DB0:
/* 105630 802E3DB0 E7A00010 */  swc1  $f0, 0x10($sp)
/* 105634 802E3DB4 8E260048 */  lw    $a2, 0x48($s1)
/* 105638 802E3DB8 8E27004C */  lw    $a3, 0x4c($s1)
/* 10563C 802E3DBC 0C052757 */  jal   play_sound_at_position
/* 105640 802E3DC0 0000282D */   daddu $a1, $zero, $zero
/* 105644 802E3DC4 080B8F7A */  j     .L802E3DE8
/* 105648 802E3DC8 24020001 */   addiu $v0, $zero, 1

/* 10564C 802E3DCC 0C04419E */  jal   func_80110678
/* 105650 802E3DD0 0220202D */   daddu $a0, $s1, $zero
/* 105654 802E3DD4 080B8F0D */  j     .L802E3C34
/* 105658 802E3DD8 00000000 */   nop   

/* 10565C 802E3DDC 0C04419E */  jal   func_80110678
/* 105660 802E3DE0 0220202D */   daddu $a0, $s1, $zero
.L802E3DE4:
/* 105664 802E3DE4 24020001 */  addiu $v0, $zero, 1
.L802E3DE8:
/* 105668 802E3DE8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 10566C 802E3DEC 8FB20020 */  lw    $s2, 0x20($sp)
/* 105670 802E3DF0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 105674 802E3DF4 8FB00018 */  lw    $s0, 0x18($sp)
/* 105678 802E3DF8 03E00008 */  jr    $ra
/* 10567C 802E3DFC 27BD0028 */   addiu $sp, $sp, 0x28

/* 105680 802E3E00 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105684 802E3E04 AFB00010 */  sw    $s0, 0x10($sp)
/* 105688 802E3E08 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10568C 802E3E0C 0C0B8DB9 */  jal   func_802E36E4
/* 105690 802E3E10 0080802D */   daddu $s0, $a0, $zero
/* 105694 802E3E14 3C02802E */  lui   $v0, 0x802e
/* 105698 802E3E18 244230C0 */  addiu $v0, $v0, 0x30c0
/* 10569C 802E3E1C AE02003C */  sw    $v0, 0x3c($s0)
/* 1056A0 802E3E20 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1056A4 802E3E24 8FB00010 */  lw    $s0, 0x10($sp)
/* 1056A8 802E3E28 03E00008 */  jr    $ra
/* 1056AC 802E3E2C 27BD0018 */   addiu $sp, $sp, 0x18

/* 1056B0 802E3E30 2403FFFF */  addiu $v1, $zero, -1
/* 1056B4 802E3E34 8C820040 */  lw    $v0, 0x40($a0)
/* 1056B8 802E3E38 3C05FFDF */  lui   $a1, 0xffdf
/* 1056BC 802E3E3C A4430010 */  sh    $v1, 0x10($v0)
/* 1056C0 802E3E40 C480004C */  lwc1  $f0, 0x4c($a0)
/* 1056C4 802E3E44 34A5FFFF */  ori   $a1, $a1, 0xffff
/* 1056C8 802E3E48 A443000E */  sh    $v1, 0xe($v0)
/* 1056CC 802E3E4C E4400014 */  swc1  $f0, 0x14($v0)
/* 1056D0 802E3E50 8C820000 */  lw    $v0, ($a0)
/* 1056D4 802E3E54 3C013F00 */  lui   $at, 0x3f00
/* 1056D8 802E3E58 44810000 */  mtc1  $at, $f0
/* 1056DC 802E3E5C 00451024 */  and   $v0, $v0, $a1
/* 1056E0 802E3E60 E4800054 */  swc1  $f0, 0x54($a0)
/* 1056E4 802E3E64 E4800058 */  swc1  $f0, 0x58($a0)
/* 1056E8 802E3E68 E480005C */  swc1  $f0, 0x5c($a0)
/* 1056EC 802E3E6C 03E00008 */  jr    $ra
/* 1056F0 802E3E70 AC820000 */   sw    $v0, ($a0)

/* 1056F4 802E3E74 00000000 */  nop   
/* 1056F8 802E3E78 00000000 */  nop   
/* 1056FC 802E3E7C 00000000 */  nop   


