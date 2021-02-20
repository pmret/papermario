.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414D0_EDFE90
/* EDFE90 802414D0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EDFE94 802414D4 AFB50044 */  sw        $s5, 0x44($sp)
/* EDFE98 802414D8 0080A82D */  daddu     $s5, $a0, $zero
/* EDFE9C 802414DC AFBF0048 */  sw        $ra, 0x48($sp)
/* EDFEA0 802414E0 AFB40040 */  sw        $s4, 0x40($sp)
/* EDFEA4 802414E4 AFB3003C */  sw        $s3, 0x3c($sp)
/* EDFEA8 802414E8 AFB20038 */  sw        $s2, 0x38($sp)
/* EDFEAC 802414EC AFB10034 */  sw        $s1, 0x34($sp)
/* EDFEB0 802414F0 AFB00030 */  sw        $s0, 0x30($sp)
/* EDFEB4 802414F4 8EB20148 */  lw        $s2, 0x148($s5)
/* EDFEB8 802414F8 86440008 */  lh        $a0, 8($s2)
/* EDFEBC 802414FC 8EB0000C */  lw        $s0, 0xc($s5)
/* EDFEC0 80241500 0C00F92F */  jal       func_8003E4BC
/* EDFEC4 80241504 00A0882D */   daddu    $s1, $a1, $zero
/* EDFEC8 80241508 02A0202D */  daddu     $a0, $s5, $zero
/* EDFECC 8024150C 8E050000 */  lw        $a1, ($s0)
/* EDFED0 80241510 0C0B53A3 */  jal       func_802D4E8C
/* EDFED4 80241514 0040A02D */   daddu    $s4, $v0, $zero
/* EDFED8 80241518 AFA00010 */  sw        $zero, 0x10($sp)
/* EDFEDC 8024151C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EDFEE0 80241520 8C630030 */  lw        $v1, 0x30($v1)
/* EDFEE4 80241524 AFA30014 */  sw        $v1, 0x14($sp)
/* EDFEE8 80241528 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EDFEEC 8024152C 8C63001C */  lw        $v1, 0x1c($v1)
/* EDFEF0 80241530 AFA30018 */  sw        $v1, 0x18($sp)
/* EDFEF4 80241534 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EDFEF8 80241538 8C630024 */  lw        $v1, 0x24($v1)
/* EDFEFC 8024153C AFA3001C */  sw        $v1, 0x1c($sp)
/* EDFF00 80241540 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EDFF04 80241544 8C630028 */  lw        $v1, 0x28($v1)
/* EDFF08 80241548 AFA30020 */  sw        $v1, 0x20($sp)
/* EDFF0C 8024154C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EDFF10 80241550 3C0142F0 */  lui       $at, 0x42f0
/* EDFF14 80241554 44810000 */  mtc1      $at, $f0
/* EDFF18 80241558 8C63002C */  lw        $v1, 0x2c($v1)
/* EDFF1C 8024155C E7A00028 */  swc1      $f0, 0x28($sp)
/* EDFF20 80241560 A7A0002C */  sh        $zero, 0x2c($sp)
/* EDFF24 80241564 AFA30024 */  sw        $v1, 0x24($sp)
/* EDFF28 80241568 C6800038 */  lwc1      $f0, 0x38($s4)
/* EDFF2C 8024156C E6400108 */  swc1      $f0, 0x108($s2)
/* EDFF30 80241570 C680003C */  lwc1      $f0, 0x3c($s4)
/* EDFF34 80241574 27B30010 */  addiu     $s3, $sp, 0x10
/* EDFF38 80241578 E640010C */  swc1      $f0, 0x10c($s2)
/* EDFF3C 8024157C 3C0138D1 */  lui       $at, 0x38d1
/* EDFF40 80241580 3421B717 */  ori       $at, $at, 0xb717
/* EDFF44 80241584 44810000 */  mtc1      $at, $f0
/* EDFF48 80241588 C6820040 */  lwc1      $f2, 0x40($s4)
/* EDFF4C 8024158C 0040802D */  daddu     $s0, $v0, $zero
/* EDFF50 80241590 E6400114 */  swc1      $f0, 0x114($s2)
/* EDFF54 80241594 E6400118 */  swc1      $f0, 0x118($s2)
/* EDFF58 80241598 12200006 */  beqz      $s1, .L802415B4
/* EDFF5C 8024159C E6420110 */   swc1     $f2, 0x110($s2)
/* EDFF60 802415A0 0280202D */  daddu     $a0, $s4, $zero
/* EDFF64 802415A4 0240282D */  daddu     $a1, $s2, $zero
/* EDFF68 802415A8 02A0302D */  daddu     $a2, $s5, $zero
/* EDFF6C 802415AC 0C0904EB */  jal       func_802413AC_EDFD6C
/* EDFF70 802415B0 0200382D */   daddu    $a3, $s0, $zero
.L802415B4:
/* EDFF74 802415B4 2402FFFE */  addiu     $v0, $zero, -2
/* EDFF78 802415B8 A28200AB */  sb        $v0, 0xab($s4)
/* EDFF7C 802415BC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* EDFF80 802415C0 30620004 */  andi      $v0, $v1, 4
/* EDFF84 802415C4 10400007 */  beqz      $v0, .L802415E4
/* EDFF88 802415C8 00000000 */   nop
/* EDFF8C 802415CC 824200B4 */  lb        $v0, 0xb4($s2)
/* EDFF90 802415D0 1440003C */  bnez      $v0, .L802416C4
/* EDFF94 802415D4 0000102D */   daddu    $v0, $zero, $zero
/* EDFF98 802415D8 2402FFFB */  addiu     $v0, $zero, -5
/* EDFF9C 802415DC 00621024 */  and       $v0, $v1, $v0
/* EDFFA0 802415E0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802415E4:
/* EDFFA4 802415E4 8EA30070 */  lw        $v1, 0x70($s5)
/* EDFFA8 802415E8 2C62000F */  sltiu     $v0, $v1, 0xf
/* EDFFAC 802415EC 10400034 */  beqz      $v0, .L802416C0
/* EDFFB0 802415F0 00031080 */   sll      $v0, $v1, 2
/* EDFFB4 802415F4 3C018024 */  lui       $at, %hi(jtbl_80247B08_EE64C8)
/* EDFFB8 802415F8 00220821 */  addu      $at, $at, $v0
/* EDFFBC 802415FC 8C227B08 */  lw        $v0, %lo(jtbl_80247B08_EE64C8)($at)
/* EDFFC0 80241600 00400008 */  jr        $v0
/* EDFFC4 80241604 00000000 */   nop
glabel L80241608_EDFFC8
/* EDFFC8 80241608 02A0202D */  daddu     $a0, $s5, $zero
/* EDFFCC 8024160C 0200282D */  daddu     $a1, $s0, $zero
/* EDFFD0 80241610 0C090071 */  jal       func_802401C4_EDEB84
/* EDFFD4 80241614 0260302D */   daddu    $a2, $s3, $zero
glabel L80241618_EDFFD8
/* EDFFD8 80241618 02A0202D */  daddu     $a0, $s5, $zero
/* EDFFDC 8024161C 0200282D */  daddu     $a1, $s0, $zero
/* EDFFE0 80241620 0C0900DD */  jal       func_80240374_EDED34
/* EDFFE4 80241624 0260302D */   daddu    $a2, $s3, $zero
/* EDFFE8 80241628 080905B1 */  j         .L802416C4
/* EDFFEC 8024162C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241630_EDFFF0
/* EDFFF0 80241630 02A0202D */  daddu     $a0, $s5, $zero
/* EDFFF4 80241634 0200282D */  daddu     $a1, $s0, $zero
/* EDFFF8 80241638 0C090267 */  jal       func_8024099C_EDF35C
/* EDFFFC 8024163C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241640_EE0000
/* EE0000 80241640 02A0202D */  daddu     $a0, $s5, $zero
/* EE0004 80241644 0200282D */  daddu     $a1, $s0, $zero
/* EE0008 80241648 0C090297 */  jal       func_80240A5C_EDF41C
/* EE000C 8024164C 0260302D */   daddu    $a2, $s3, $zero
/* EE0010 80241650 080905B1 */  j         .L802416C4
/* EE0014 80241654 0000102D */   daddu    $v0, $zero, $zero
glabel L80241658_EE0018
/* EE0018 80241658 02A0202D */  daddu     $a0, $s5, $zero
/* EE001C 8024165C 0200282D */  daddu     $a1, $s0, $zero
/* EE0020 80241660 0C090368 */  jal       func_80240DA0_EDF760
/* EE0024 80241664 0260302D */   daddu    $a2, $s3, $zero
glabel L80241668_EE0028
/* EE0028 80241668 02A0202D */  daddu     $a0, $s5, $zero
/* EE002C 8024166C 0200282D */  daddu     $a1, $s0, $zero
/* EE0030 80241670 0C090386 */  jal       func_80240E18_EDF7D8
/* EE0034 80241674 0260302D */   daddu    $a2, $s3, $zero
/* EE0038 80241678 080905B1 */  j         .L802416C4
/* EE003C 8024167C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241680_EE0040
/* EE0040 80241680 02A0202D */  daddu     $a0, $s5, $zero
/* EE0044 80241684 0200282D */  daddu     $a1, $s0, $zero
/* EE0048 80241688 0C0903A1 */  jal       code_EDEA00_DeadUnkNpcAIFunc14
/* EE004C 8024168C 0260302D */   daddu    $a2, $s3, $zero
/* EE0050 80241690 080905B1 */  j         .L802416C4
/* EE0054 80241694 0000102D */   daddu    $v0, $zero, $zero
glabel L80241698_EE0058
/* EE0058 80241698 02A0202D */  daddu     $a0, $s5, $zero
/* EE005C 8024169C 0200282D */  daddu     $a1, $s0, $zero
/* EE0060 802416A0 0C0903EE */  jal       func_80240FB8_EDF978
/* EE0064 802416A4 0260302D */   daddu    $a2, $s3, $zero
/* EE0068 802416A8 080905B1 */  j         .L802416C4
/* EE006C 802416AC 0000102D */   daddu    $v0, $zero, $zero
glabel L802416B0_EE0070
/* EE0070 802416B0 02A0202D */  daddu     $a0, $s5, $zero
/* EE0074 802416B4 0200282D */  daddu     $a1, $s0, $zero
/* EE0078 802416B8 0C090407 */  jal       func_8024101C_EDF9DC
/* EE007C 802416BC 0260302D */   daddu    $a2, $s3, $zero
.L802416C0:
glabel L802416C0_EE0080
/* EE0080 802416C0 0000102D */  daddu     $v0, $zero, $zero
.L802416C4:
/* EE0084 802416C4 8FBF0048 */  lw        $ra, 0x48($sp)
/* EE0088 802416C8 8FB50044 */  lw        $s5, 0x44($sp)
/* EE008C 802416CC 8FB40040 */  lw        $s4, 0x40($sp)
/* EE0090 802416D0 8FB3003C */  lw        $s3, 0x3c($sp)
/* EE0094 802416D4 8FB20038 */  lw        $s2, 0x38($sp)
/* EE0098 802416D8 8FB10034 */  lw        $s1, 0x34($sp)
/* EE009C 802416DC 8FB00030 */  lw        $s0, 0x30($sp)
/* EE00A0 802416E0 03E00008 */  jr        $ra
/* EE00A4 802416E4 27BD0050 */   addiu    $sp, $sp, 0x50
