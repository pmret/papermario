.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BF0_97E6C0
/* 97E6C0 80240BF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 97E6C4 80240BF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 97E6C8 80240BF8 0080982D */  daddu     $s3, $a0, $zero
/* 97E6CC 80240BFC AFBF0048 */  sw        $ra, 0x48($sp)
/* 97E6D0 80240C00 AFB50044 */  sw        $s5, 0x44($sp)
/* 97E6D4 80240C04 AFB40040 */  sw        $s4, 0x40($sp)
/* 97E6D8 80240C08 AFB20038 */  sw        $s2, 0x38($sp)
/* 97E6DC 80240C0C AFB10034 */  sw        $s1, 0x34($sp)
/* 97E6E0 80240C10 AFB00030 */  sw        $s0, 0x30($sp)
/* 97E6E4 80240C14 8E720148 */  lw        $s2, 0x148($s3)
/* 97E6E8 80240C18 86440008 */  lh        $a0, 8($s2)
/* 97E6EC 80240C1C 8E70000C */  lw        $s0, 0xc($s3)
/* 97E6F0 80240C20 0C00EABB */  jal       get_npc_unsafe
/* 97E6F4 80240C24 00A0882D */   daddu    $s1, $a1, $zero
/* 97E6F8 80240C28 8E050000 */  lw        $a1, ($s0)
/* 97E6FC 80240C2C 26100004 */  addiu     $s0, $s0, 4
/* 97E700 80240C30 0260202D */  daddu     $a0, $s3, $zero
/* 97E704 80240C34 0C0B1EAF */  jal       get_variable
/* 97E708 80240C38 0040A82D */   daddu    $s5, $v0, $zero
/* 97E70C 80240C3C 0260202D */  daddu     $a0, $s3, $zero
/* 97E710 80240C40 8E050000 */  lw        $a1, ($s0)
/* 97E714 80240C44 0C0B1EAF */  jal       get_variable
/* 97E718 80240C48 0040A02D */   daddu    $s4, $v0, $zero
/* 97E71C 80240C4C AE420094 */  sw        $v0, 0x94($s2)
/* 97E720 80240C50 AFA00010 */  sw        $zero, 0x10($sp)
/* 97E724 80240C54 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 97E728 80240C58 8C420030 */  lw        $v0, 0x30($v0)
/* 97E72C 80240C5C AFA20014 */  sw        $v0, 0x14($sp)
/* 97E730 80240C60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 97E734 80240C64 8C42001C */  lw        $v0, 0x1c($v0)
/* 97E738 80240C68 AFA20018 */  sw        $v0, 0x18($sp)
/* 97E73C 80240C6C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 97E740 80240C70 8C420024 */  lw        $v0, 0x24($v0)
/* 97E744 80240C74 AFA2001C */  sw        $v0, 0x1c($sp)
/* 97E748 80240C78 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 97E74C 80240C7C 8C420028 */  lw        $v0, 0x28($v0)
/* 97E750 80240C80 AFA20020 */  sw        $v0, 0x20($sp)
/* 97E754 80240C84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 97E758 80240C88 3C0142C8 */  lui       $at, 0x42c8
/* 97E75C 80240C8C 44810000 */  mtc1      $at, $f0
/* 97E760 80240C90 8C42002C */  lw        $v0, 0x2c($v0)
/* 97E764 80240C94 27B00010 */  addiu     $s0, $sp, 0x10
/* 97E768 80240C98 E7A00028 */  swc1      $f0, 0x28($sp)
/* 97E76C 80240C9C A7A0002C */  sh        $zero, 0x2c($sp)
/* 97E770 80240CA0 12200019 */  beqz      $s1, .L80240D08
/* 97E774 80240CA4 AFA20024 */   sw       $v0, 0x24($sp)
/* 97E778 80240CA8 AE600070 */  sw        $zero, 0x70($s3)
/* 97E77C 80240CAC A6A0008E */  sh        $zero, 0x8e($s5)
/* 97E780 80240CB0 AE600074 */  sw        $zero, 0x74($s3)
/* 97E784 80240CB4 8EA20000 */  lw        $v0, ($s5)
/* 97E788 80240CB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* 97E78C 80240CBC 00431024 */  and       $v0, $v0, $v1
/* 97E790 80240CC0 2403FDFF */  addiu     $v1, $zero, -0x201
/* 97E794 80240CC4 00431024 */  and       $v0, $v0, $v1
/* 97E798 80240CC8 34420008 */  ori       $v0, $v0, 8
/* 97E79C 80240CCC AEA20000 */  sw        $v0, ($s5)
/* 97E7A0 80240CD0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 97E7A4 80240CD4 34420018 */  ori       $v0, $v0, 0x18
/* 97E7A8 80240CD8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* 97E7AC 80240CDC 8E420000 */  lw        $v0, ($s2)
/* 97E7B0 80240CE0 3C034000 */  lui       $v1, 0x4000
/* 97E7B4 80240CE4 00431024 */  and       $v0, $v0, $v1
/* 97E7B8 80240CE8 10400007 */  beqz      $v0, .L80240D08
/* 97E7BC 80240CEC 3C03BFFF */   lui      $v1, 0xbfff
/* 97E7C0 80240CF0 2402000C */  addiu     $v0, $zero, 0xc
/* 97E7C4 80240CF4 AE620070 */  sw        $v0, 0x70($s3)
/* 97E7C8 80240CF8 8E420000 */  lw        $v0, ($s2)
/* 97E7CC 80240CFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 97E7D0 80240D00 00431024 */  and       $v0, $v0, $v1
/* 97E7D4 80240D04 AE420000 */  sw        $v0, ($s2)
.L80240D08:
/* 97E7D8 80240D08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 97E7DC 80240D0C 30620004 */  andi      $v0, $v1, 4
/* 97E7E0 80240D10 10400007 */  beqz      $v0, .L80240D30
/* 97E7E4 80240D14 00000000 */   nop
/* 97E7E8 80240D18 824200B4 */  lb        $v0, 0xb4($s2)
/* 97E7EC 80240D1C 14400034 */  bnez      $v0, .L80240DF0
/* 97E7F0 80240D20 0000102D */   daddu    $v0, $zero, $zero
/* 97E7F4 80240D24 2402FFFB */  addiu     $v0, $zero, -5
/* 97E7F8 80240D28 00621024 */  and       $v0, $v1, $v0
/* 97E7FC 80240D2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240D30:
/* 97E800 80240D30 8E630070 */  lw        $v1, 0x70($s3)
/* 97E804 80240D34 2C62000F */  sltiu     $v0, $v1, 0xf
/* 97E808 80240D38 1040002C */  beqz      $v0, .L80240DEC
/* 97E80C 80240D3C 00031080 */   sll      $v0, $v1, 2
/* 97E810 80240D40 3C018024 */  lui       $at, %hi(jtbl_80242EB8_980988)
/* 97E814 80240D44 00220821 */  addu      $at, $at, $v0
/* 97E818 80240D48 8C222EB8 */  lw        $v0, %lo(jtbl_80242EB8_980988)($at)
/* 97E81C 80240D4C 00400008 */  jr        $v0
/* 97E820 80240D50 00000000 */   nop
glabel L80240D54_97E824
/* 97E824 80240D54 0260202D */  daddu     $a0, $s3, $zero
/* 97E828 80240D58 0280282D */  daddu     $a1, $s4, $zero
/* 97E82C 80240D5C 0C090000 */  jal       func_80240000_97DAD0
/* 97E830 80240D60 0200302D */   daddu    $a2, $s0, $zero
glabel L80240D64_97E834
/* 97E834 80240D64 0260202D */  daddu     $a0, $s3, $zero
/* 97E838 80240D68 0280282D */  daddu     $a1, $s4, $zero
/* 97E83C 80240D6C 0C09008C */  jal       func_80240230_97DD00
/* 97E840 80240D70 0200302D */   daddu    $a2, $s0, $zero
/* 97E844 80240D74 0809037C */  j         .L80240DF0
/* 97E848 80240D78 0000102D */   daddu    $v0, $zero, $zero
glabel L80240D7C_97E84C
/* 97E84C 80240D7C 0260202D */  daddu     $a0, $s3, $zero
/* 97E850 80240D80 0280282D */  daddu     $a1, $s4, $zero
/* 97E854 80240D84 0C09015A */  jal       isk_05_UnkNpcAIFunc1
/* 97E858 80240D88 0200302D */   daddu    $a2, $s0, $zero
/* 97E85C 80240D8C 8E630070 */  lw        $v1, 0x70($s3)
/* 97E860 80240D90 24020003 */  addiu     $v0, $zero, 3
/* 97E864 80240D94 14620016 */  bne       $v1, $v0, .L80240DF0
/* 97E868 80240D98 0000102D */   daddu    $v0, $zero, $zero
glabel L80240D9C_97E86C
/* 97E86C 80240D9C 0260202D */  daddu     $a0, $s3, $zero
/* 97E870 80240DA0 0280282D */  daddu     $a1, $s4, $zero
/* 97E874 80240DA4 0C09018A */  jal       func_80240628_97E0F8
/* 97E878 80240DA8 0200302D */   daddu    $a2, $s0, $zero
/* 97E87C 80240DAC 0809037C */  j         .L80240DF0
/* 97E880 80240DB0 0000102D */   daddu    $v0, $zero, $zero
glabel L80240DB4_97E884
/* 97E884 80240DB4 0260202D */  daddu     $a0, $s3, $zero
/* 97E888 80240DB8 0280282D */  daddu     $a1, $s4, $zero
/* 97E88C 80240DBC 0C0901F3 */  jal       isk_05_UnkNpcAIFunc15
/* 97E890 80240DC0 0200302D */   daddu    $a2, $s0, $zero
glabel L80240DC4_97E894
/* 97E894 80240DC4 0260202D */  daddu     $a0, $s3, $zero
/* 97E898 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* 97E89C 80240DCC 0C09022B */  jal       func_802408AC_97E37C
/* 97E8A0 80240DD0 0200302D */   daddu    $a2, $s0, $zero
/* 97E8A4 80240DD4 0809037C */  j         .L80240DF0
/* 97E8A8 80240DD8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240DDC_97E8AC
/* 97E8AC 80240DDC 0260202D */  daddu     $a0, $s3, $zero
/* 97E8B0 80240DE0 0280282D */  daddu     $a1, $s4, $zero
/* 97E8B4 80240DE4 0C0902EB */  jal       isk_05_UnkDurationCheck
/* 97E8B8 80240DE8 0200302D */   daddu    $a2, $s0, $zero
.L80240DEC:
glabel L80240DEC_97E8BC
/* 97E8BC 80240DEC 0000102D */  daddu     $v0, $zero, $zero
.L80240DF0:
/* 97E8C0 80240DF0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 97E8C4 80240DF4 8FB50044 */  lw        $s5, 0x44($sp)
/* 97E8C8 80240DF8 8FB40040 */  lw        $s4, 0x40($sp)
/* 97E8CC 80240DFC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 97E8D0 80240E00 8FB20038 */  lw        $s2, 0x38($sp)
/* 97E8D4 80240E04 8FB10034 */  lw        $s1, 0x34($sp)
/* 97E8D8 80240E08 8FB00030 */  lw        $s0, 0x30($sp)
/* 97E8DC 80240E0C 03E00008 */  jr        $ra
/* 97E8E0 80240E10 27BD0050 */   addiu    $sp, $sp, 0x50
