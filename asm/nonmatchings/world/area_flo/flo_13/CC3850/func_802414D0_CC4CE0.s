.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414D0_CC4CE0
/* CC4CE0 802414D0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CC4CE4 802414D4 AFB40040 */  sw        $s4, 0x40($sp)
/* CC4CE8 802414D8 0080A02D */  daddu     $s4, $a0, $zero
/* CC4CEC 802414DC AFBF0048 */  sw        $ra, 0x48($sp)
/* CC4CF0 802414E0 AFB50044 */  sw        $s5, 0x44($sp)
/* CC4CF4 802414E4 AFB3003C */  sw        $s3, 0x3c($sp)
/* CC4CF8 802414E8 AFB20038 */  sw        $s2, 0x38($sp)
/* CC4CFC 802414EC AFB10034 */  sw        $s1, 0x34($sp)
/* CC4D00 802414F0 AFB00030 */  sw        $s0, 0x30($sp)
/* CC4D04 802414F4 8E920148 */  lw        $s2, 0x148($s4)
/* CC4D08 802414F8 86440008 */  lh        $a0, 8($s2)
/* CC4D0C 802414FC 8E90000C */  lw        $s0, 0xc($s4)
/* CC4D10 80241500 0C00EABB */  jal       get_npc_unsafe
/* CC4D14 80241504 00A0882D */   daddu    $s1, $a1, $zero
/* CC4D18 80241508 0280202D */  daddu     $a0, $s4, $zero
/* CC4D1C 8024150C 8E050000 */  lw        $a1, ($s0)
/* CC4D20 80241510 0C0B1EAF */  jal       get_variable
/* CC4D24 80241514 0040A82D */   daddu    $s5, $v0, $zero
/* CC4D28 80241518 AFA00010 */  sw        $zero, 0x10($sp)
/* CC4D2C 8024151C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC4D30 80241520 8C630030 */  lw        $v1, 0x30($v1)
/* CC4D34 80241524 AFA30014 */  sw        $v1, 0x14($sp)
/* CC4D38 80241528 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC4D3C 8024152C 8C63001C */  lw        $v1, 0x1c($v1)
/* CC4D40 80241530 AFA30018 */  sw        $v1, 0x18($sp)
/* CC4D44 80241534 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC4D48 80241538 8C630024 */  lw        $v1, 0x24($v1)
/* CC4D4C 8024153C AFA3001C */  sw        $v1, 0x1c($sp)
/* CC4D50 80241540 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC4D54 80241544 8C630028 */  lw        $v1, 0x28($v1)
/* CC4D58 80241548 27B30010 */  addiu     $s3, $sp, 0x10
/* CC4D5C 8024154C AFA30020 */  sw        $v1, 0x20($sp)
/* CC4D60 80241550 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CC4D64 80241554 3C0142F0 */  lui       $at, 0x42f0
/* CC4D68 80241558 44810000 */  mtc1      $at, $f0
/* CC4D6C 8024155C 8C63002C */  lw        $v1, 0x2c($v1)
/* CC4D70 80241560 0040802D */  daddu     $s0, $v0, $zero
/* CC4D74 80241564 E7A00028 */  swc1      $f0, 0x28($sp)
/* CC4D78 80241568 A7A0002C */  sh        $zero, 0x2c($sp)
/* CC4D7C 8024156C 12200006 */  beqz      $s1, .L80241588
/* CC4D80 80241570 AFA30024 */   sw       $v1, 0x24($sp)
/* CC4D84 80241574 02A0202D */  daddu     $a0, $s5, $zero
/* CC4D88 80241578 0240282D */  daddu     $a1, $s2, $zero
/* CC4D8C 8024157C 0280302D */  daddu     $a2, $s4, $zero
/* CC4D90 80241580 0C0904EB */  jal       func_802413AC_CC4BBC
/* CC4D94 80241584 0200382D */   daddu    $a3, $s0, $zero
.L80241588:
/* CC4D98 80241588 2402FFFE */  addiu     $v0, $zero, -2
/* CC4D9C 8024158C A2A200AB */  sb        $v0, 0xab($s5)
/* CC4DA0 80241590 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CC4DA4 80241594 30620004 */  andi      $v0, $v1, 4
/* CC4DA8 80241598 10400007 */  beqz      $v0, .L802415B8
/* CC4DAC 8024159C 00000000 */   nop      
/* CC4DB0 802415A0 824200B4 */  lb        $v0, 0xb4($s2)
/* CC4DB4 802415A4 1440003C */  bnez      $v0, .L80241698
/* CC4DB8 802415A8 0000102D */   daddu    $v0, $zero, $zero
/* CC4DBC 802415AC 2402FFFB */  addiu     $v0, $zero, -5
/* CC4DC0 802415B0 00621024 */  and       $v0, $v1, $v0
/* CC4DC4 802415B4 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802415B8:
/* CC4DC8 802415B8 8E830070 */  lw        $v1, 0x70($s4)
/* CC4DCC 802415BC 2C62000F */  sltiu     $v0, $v1, 0xf
/* CC4DD0 802415C0 10400034 */  beqz      $v0, .L80241694
/* CC4DD4 802415C4 00031080 */   sll      $v0, $v1, 2
/* CC4DD8 802415C8 3C018024 */  lui       $at, 0x8024
/* CC4DDC 802415CC 00220821 */  addu      $at, $at, $v0
/* CC4DE0 802415D0 8C227A48 */  lw        $v0, 0x7a48($at)
/* CC4DE4 802415D4 00400008 */  jr        $v0
/* CC4DE8 802415D8 00000000 */   nop      
/* CC4DEC 802415DC 0280202D */  daddu     $a0, $s4, $zero
/* CC4DF0 802415E0 0200282D */  daddu     $a1, $s0, $zero
/* CC4DF4 802415E4 0C090071 */  jal       func_802401C4_CC39D4
/* CC4DF8 802415E8 0260302D */   daddu    $a2, $s3, $zero
/* CC4DFC 802415EC 0280202D */  daddu     $a0, $s4, $zero
/* CC4E00 802415F0 0200282D */  daddu     $a1, $s0, $zero
/* CC4E04 802415F4 0C0900DD */  jal       func_80240374_CC3B84
/* CC4E08 802415F8 0260302D */   daddu    $a2, $s3, $zero
/* CC4E0C 802415FC 080905A6 */  j         .L80241698
/* CC4E10 80241600 0000102D */   daddu    $v0, $zero, $zero
/* CC4E14 80241604 0280202D */  daddu     $a0, $s4, $zero
/* CC4E18 80241608 0200282D */  daddu     $a1, $s0, $zero
/* CC4E1C 8024160C 0C090267 */  jal       func_8024099C_CC41AC
/* CC4E20 80241610 0260302D */   daddu    $a2, $s3, $zero
/* CC4E24 80241614 0280202D */  daddu     $a0, $s4, $zero
/* CC4E28 80241618 0200282D */  daddu     $a1, $s0, $zero
/* CC4E2C 8024161C 0C090297 */  jal       func_80240A5C_CC426C
/* CC4E30 80241620 0260302D */   daddu    $a2, $s3, $zero
/* CC4E34 80241624 080905A6 */  j         .L80241698
/* CC4E38 80241628 0000102D */   daddu    $v0, $zero, $zero
/* CC4E3C 8024162C 0280202D */  daddu     $a0, $s4, $zero
/* CC4E40 80241630 0200282D */  daddu     $a1, $s0, $zero
/* CC4E44 80241634 0C090368 */  jal       func_80240DA0_CC45B0
/* CC4E48 80241638 0260302D */   daddu    $a2, $s3, $zero
/* CC4E4C 8024163C 0280202D */  daddu     $a0, $s4, $zero
/* CC4E50 80241640 0200282D */  daddu     $a1, $s0, $zero
/* CC4E54 80241644 0C090386 */  jal       func_80240E18_CC4628
/* CC4E58 80241648 0260302D */   daddu    $a2, $s3, $zero
/* CC4E5C 8024164C 080905A6 */  j         .L80241698
/* CC4E60 80241650 0000102D */   daddu    $v0, $zero, $zero
/* CC4E64 80241654 0280202D */  daddu     $a0, $s4, $zero
/* CC4E68 80241658 0200282D */  daddu     $a1, $s0, $zero
/* CC4E6C 8024165C 0C0903A1 */  jal       func_80240E84_CC4694
/* CC4E70 80241660 0260302D */   daddu    $a2, $s3, $zero
/* CC4E74 80241664 080905A6 */  j         .L80241698
/* CC4E78 80241668 0000102D */   daddu    $v0, $zero, $zero
/* CC4E7C 8024166C 0280202D */  daddu     $a0, $s4, $zero
/* CC4E80 80241670 0200282D */  daddu     $a1, $s0, $zero
/* CC4E84 80241674 0C0903EE */  jal       func_80240FB8_CC47C8
/* CC4E88 80241678 0260302D */   daddu    $a2, $s3, $zero
/* CC4E8C 8024167C 080905A6 */  j         .L80241698
/* CC4E90 80241680 0000102D */   daddu    $v0, $zero, $zero
/* CC4E94 80241684 0280202D */  daddu     $a0, $s4, $zero
/* CC4E98 80241688 0200282D */  daddu     $a1, $s0, $zero
/* CC4E9C 8024168C 0C090407 */  jal       func_8024101C_CC482C
/* CC4EA0 80241690 0260302D */   daddu    $a2, $s3, $zero
.L80241694:
/* CC4EA4 80241694 0000102D */  daddu     $v0, $zero, $zero
.L80241698:
/* CC4EA8 80241698 8FBF0048 */  lw        $ra, 0x48($sp)
/* CC4EAC 8024169C 8FB50044 */  lw        $s5, 0x44($sp)
/* CC4EB0 802416A0 8FB40040 */  lw        $s4, 0x40($sp)
/* CC4EB4 802416A4 8FB3003C */  lw        $s3, 0x3c($sp)
/* CC4EB8 802416A8 8FB20038 */  lw        $s2, 0x38($sp)
/* CC4EBC 802416AC 8FB10034 */  lw        $s1, 0x34($sp)
/* CC4EC0 802416B0 8FB00030 */  lw        $s0, 0x30($sp)
/* CC4EC4 802416B4 03E00008 */  jr        $ra
/* CC4EC8 802416B8 27BD0050 */   addiu    $sp, $sp, 0x50
