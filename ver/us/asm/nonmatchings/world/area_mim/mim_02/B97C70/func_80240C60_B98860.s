.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C60_B98860
/* B98860 80240C60 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B98864 80240C64 AFB3003C */  sw        $s3, 0x3c($sp)
/* B98868 80240C68 0080982D */  daddu     $s3, $a0, $zero
/* B9886C 80240C6C AFBF0048 */  sw        $ra, 0x48($sp)
/* B98870 80240C70 AFB50044 */  sw        $s5, 0x44($sp)
/* B98874 80240C74 AFB40040 */  sw        $s4, 0x40($sp)
/* B98878 80240C78 AFB20038 */  sw        $s2, 0x38($sp)
/* B9887C 80240C7C AFB10034 */  sw        $s1, 0x34($sp)
/* B98880 80240C80 AFB00030 */  sw        $s0, 0x30($sp)
/* B98884 80240C84 8E720148 */  lw        $s2, 0x148($s3)
/* B98888 80240C88 86440008 */  lh        $a0, 8($s2)
/* B9888C 80240C8C 8E70000C */  lw        $s0, 0xc($s3)
/* B98890 80240C90 0C00EABB */  jal       get_npc_unsafe
/* B98894 80240C94 00A0882D */   daddu    $s1, $a1, $zero
/* B98898 80240C98 8E050000 */  lw        $a1, ($s0)
/* B9889C 80240C9C 26100004 */  addiu     $s0, $s0, 4
/* B988A0 80240CA0 0260202D */  daddu     $a0, $s3, $zero
/* B988A4 80240CA4 0C0B1EAF */  jal       get_variable
/* B988A8 80240CA8 0040A82D */   daddu    $s5, $v0, $zero
/* B988AC 80240CAC 0260202D */  daddu     $a0, $s3, $zero
/* B988B0 80240CB0 8E050000 */  lw        $a1, ($s0)
/* B988B4 80240CB4 0C0B1EAF */  jal       get_variable
/* B988B8 80240CB8 0040A02D */   daddu    $s4, $v0, $zero
/* B988BC 80240CBC AE420094 */  sw        $v0, 0x94($s2)
/* B988C0 80240CC0 AFA00010 */  sw        $zero, 0x10($sp)
/* B988C4 80240CC4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B988C8 80240CC8 8C420030 */  lw        $v0, 0x30($v0)
/* B988CC 80240CCC AFA20014 */  sw        $v0, 0x14($sp)
/* B988D0 80240CD0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B988D4 80240CD4 8C42001C */  lw        $v0, 0x1c($v0)
/* B988D8 80240CD8 AFA20018 */  sw        $v0, 0x18($sp)
/* B988DC 80240CDC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B988E0 80240CE0 8C420024 */  lw        $v0, 0x24($v0)
/* B988E4 80240CE4 AFA2001C */  sw        $v0, 0x1c($sp)
/* B988E8 80240CE8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B988EC 80240CEC 8C420028 */  lw        $v0, 0x28($v0)
/* B988F0 80240CF0 AFA20020 */  sw        $v0, 0x20($sp)
/* B988F4 80240CF4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B988F8 80240CF8 3C0142C8 */  lui       $at, 0x42c8
/* B988FC 80240CFC 44810000 */  mtc1      $at, $f0
/* B98900 80240D00 8C42002C */  lw        $v0, 0x2c($v0)
/* B98904 80240D04 27B00010 */  addiu     $s0, $sp, 0x10
/* B98908 80240D08 E7A00028 */  swc1      $f0, 0x28($sp)
/* B9890C 80240D0C A7A0002C */  sh        $zero, 0x2c($sp)
/* B98910 80240D10 12200019 */  beqz      $s1, .L80240D78
/* B98914 80240D14 AFA20024 */   sw       $v0, 0x24($sp)
/* B98918 80240D18 AE600070 */  sw        $zero, 0x70($s3)
/* B9891C 80240D1C A6A0008E */  sh        $zero, 0x8e($s5)
/* B98920 80240D20 AE600074 */  sw        $zero, 0x74($s3)
/* B98924 80240D24 8EA20000 */  lw        $v0, ($s5)
/* B98928 80240D28 2403F7FF */  addiu     $v1, $zero, -0x801
/* B9892C 80240D2C 00431024 */  and       $v0, $v0, $v1
/* B98930 80240D30 2403FDFF */  addiu     $v1, $zero, -0x201
/* B98934 80240D34 00431024 */  and       $v0, $v0, $v1
/* B98938 80240D38 34420008 */  ori       $v0, $v0, 8
/* B9893C 80240D3C AEA20000 */  sw        $v0, ($s5)
/* B98940 80240D40 8E4200B0 */  lw        $v0, 0xb0($s2)
/* B98944 80240D44 34420018 */  ori       $v0, $v0, 0x18
/* B98948 80240D48 AE4200B0 */  sw        $v0, 0xb0($s2)
/* B9894C 80240D4C 8E420000 */  lw        $v0, ($s2)
/* B98950 80240D50 3C034000 */  lui       $v1, 0x4000
/* B98954 80240D54 00431024 */  and       $v0, $v0, $v1
/* B98958 80240D58 10400007 */  beqz      $v0, .L80240D78
/* B9895C 80240D5C 3C03BFFF */   lui      $v1, 0xbfff
/* B98960 80240D60 2402000C */  addiu     $v0, $zero, 0xc
/* B98964 80240D64 AE620070 */  sw        $v0, 0x70($s3)
/* B98968 80240D68 8E420000 */  lw        $v0, ($s2)
/* B9896C 80240D6C 3463FFFF */  ori       $v1, $v1, 0xffff
/* B98970 80240D70 00431024 */  and       $v0, $v0, $v1
/* B98974 80240D74 AE420000 */  sw        $v0, ($s2)
.L80240D78:
/* B98978 80240D78 8E4300B0 */  lw        $v1, 0xb0($s2)
/* B9897C 80240D7C 30620004 */  andi      $v0, $v1, 4
/* B98980 80240D80 10400007 */  beqz      $v0, .L80240DA0
/* B98984 80240D84 00000000 */   nop
/* B98988 80240D88 824200B4 */  lb        $v0, 0xb4($s2)
/* B9898C 80240D8C 14400034 */  bnez      $v0, .L80240E60
/* B98990 80240D90 0000102D */   daddu    $v0, $zero, $zero
/* B98994 80240D94 2402FFFB */  addiu     $v0, $zero, -5
/* B98998 80240D98 00621024 */  and       $v0, $v1, $v0
/* B9899C 80240D9C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240DA0:
/* B989A0 80240DA0 8E630070 */  lw        $v1, 0x70($s3)
/* B989A4 80240DA4 2C62000F */  sltiu     $v0, $v1, 0xf
/* B989A8 80240DA8 1040002C */  beqz      $v0, .L80240E5C
/* B989AC 80240DAC 00031080 */   sll      $v0, $v1, 2
/* B989B0 80240DB0 3C018024 */  lui       $at, %hi(jtbl_80243838_B9B438)
/* B989B4 80240DB4 00220821 */  addu      $at, $at, $v0
/* B989B8 80240DB8 8C223838 */  lw        $v0, %lo(jtbl_80243838_B9B438)($at)
/* B989BC 80240DBC 00400008 */  jr        $v0
/* B989C0 80240DC0 00000000 */   nop
glabel L80240DC4_B989C4
/* B989C4 80240DC4 0260202D */  daddu     $a0, $s3, $zero
/* B989C8 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* B989CC 80240DCC 0C09001C */  jal       func_80240070_B97C70
/* B989D0 80240DD0 0200302D */   daddu    $a2, $s0, $zero
glabel L80240DD4_B989D4
/* B989D4 80240DD4 0260202D */  daddu     $a0, $s3, $zero
/* B989D8 80240DD8 0280282D */  daddu     $a1, $s4, $zero
/* B989DC 80240DDC 0C0900A8 */  jal       func_802402A0_B97EA0
/* B989E0 80240DE0 0200302D */   daddu    $a2, $s0, $zero
/* B989E4 80240DE4 08090398 */  j         .L80240E60
/* B989E8 80240DE8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240DEC_B989EC
/* B989EC 80240DEC 0260202D */  daddu     $a0, $s3, $zero
/* B989F0 80240DF0 0280282D */  daddu     $a1, $s4, $zero
/* B989F4 80240DF4 0C090176 */  jal       mim_02_UnkNpcAIFunc1
/* B989F8 80240DF8 0200302D */   daddu    $a2, $s0, $zero
/* B989FC 80240DFC 8E630070 */  lw        $v1, 0x70($s3)
/* B98A00 80240E00 24020003 */  addiu     $v0, $zero, 3
/* B98A04 80240E04 14620016 */  bne       $v1, $v0, .L80240E60
/* B98A08 80240E08 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E0C_B98A0C
/* B98A0C 80240E0C 0260202D */  daddu     $a0, $s3, $zero
/* B98A10 80240E10 0280282D */  daddu     $a1, $s4, $zero
/* B98A14 80240E14 0C0901A6 */  jal       func_80240698_B98298
/* B98A18 80240E18 0200302D */   daddu    $a2, $s0, $zero
/* B98A1C 80240E1C 08090398 */  j         .L80240E60
/* B98A20 80240E20 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E24_B98A24
/* B98A24 80240E24 0260202D */  daddu     $a0, $s3, $zero
/* B98A28 80240E28 0280282D */  daddu     $a1, $s4, $zero
/* B98A2C 80240E2C 0C09020F */  jal       mim_02_UnkNpcAIFunc15
/* B98A30 80240E30 0200302D */   daddu    $a2, $s0, $zero
glabel L80240E34_B98A34
/* B98A34 80240E34 0260202D */  daddu     $a0, $s3, $zero
/* B98A38 80240E38 0280282D */  daddu     $a1, $s4, $zero
/* B98A3C 80240E3C 0C090247 */  jal       func_8024091C_B9851C
/* B98A40 80240E40 0200302D */   daddu    $a2, $s0, $zero
/* B98A44 80240E44 08090398 */  j         .L80240E60
/* B98A48 80240E48 0000102D */   daddu    $v0, $zero, $zero
glabel L80240E4C_B98A4C
/* B98A4C 80240E4C 0260202D */  daddu     $a0, $s3, $zero
/* B98A50 80240E50 0280282D */  daddu     $a1, $s4, $zero
/* B98A54 80240E54 0C090307 */  jal       mim_02_UnkDurationCheck
/* B98A58 80240E58 0200302D */   daddu    $a2, $s0, $zero
.L80240E5C:
glabel L80240E5C_B98A5C
/* B98A5C 80240E5C 0000102D */  daddu     $v0, $zero, $zero
.L80240E60:
/* B98A60 80240E60 8FBF0048 */  lw        $ra, 0x48($sp)
/* B98A64 80240E64 8FB50044 */  lw        $s5, 0x44($sp)
/* B98A68 80240E68 8FB40040 */  lw        $s4, 0x40($sp)
/* B98A6C 80240E6C 8FB3003C */  lw        $s3, 0x3c($sp)
/* B98A70 80240E70 8FB20038 */  lw        $s2, 0x38($sp)
/* B98A74 80240E74 8FB10034 */  lw        $s1, 0x34($sp)
/* B98A78 80240E78 8FB00030 */  lw        $s0, 0x30($sp)
/* B98A7C 80240E7C 03E00008 */  jr        $ra
/* B98A80 80240E80 27BD0050 */   addiu    $sp, $sp, 0x50
