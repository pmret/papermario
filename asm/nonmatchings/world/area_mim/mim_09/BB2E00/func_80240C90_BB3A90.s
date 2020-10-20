.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C90_BB3A90
/* BB3A90 80240C90 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BB3A94 80240C94 AFB3003C */  sw        $s3, 0x3c($sp)
/* BB3A98 80240C98 0080982D */  daddu     $s3, $a0, $zero
/* BB3A9C 80240C9C AFBF0048 */  sw        $ra, 0x48($sp)
/* BB3AA0 80240CA0 AFB50044 */  sw        $s5, 0x44($sp)
/* BB3AA4 80240CA4 AFB40040 */  sw        $s4, 0x40($sp)
/* BB3AA8 80240CA8 AFB20038 */  sw        $s2, 0x38($sp)
/* BB3AAC 80240CAC AFB10034 */  sw        $s1, 0x34($sp)
/* BB3AB0 80240CB0 AFB00030 */  sw        $s0, 0x30($sp)
/* BB3AB4 80240CB4 8E720148 */  lw        $s2, 0x148($s3)
/* BB3AB8 80240CB8 86440008 */  lh        $a0, 8($s2)
/* BB3ABC 80240CBC 8E70000C */  lw        $s0, 0xc($s3)
/* BB3AC0 80240CC0 0C00EABB */  jal       get_npc_unsafe
/* BB3AC4 80240CC4 00A0882D */   daddu    $s1, $a1, $zero
/* BB3AC8 80240CC8 8E050000 */  lw        $a1, ($s0)
/* BB3ACC 80240CCC 26100004 */  addiu     $s0, $s0, 4
/* BB3AD0 80240CD0 0260202D */  daddu     $a0, $s3, $zero
/* BB3AD4 80240CD4 0C0B1EAF */  jal       get_variable
/* BB3AD8 80240CD8 0040A82D */   daddu    $s5, $v0, $zero
/* BB3ADC 80240CDC 0260202D */  daddu     $a0, $s3, $zero
/* BB3AE0 80240CE0 8E050000 */  lw        $a1, ($s0)
/* BB3AE4 80240CE4 0C0B1EAF */  jal       get_variable
/* BB3AE8 80240CE8 0040A02D */   daddu    $s4, $v0, $zero
/* BB3AEC 80240CEC AE420094 */  sw        $v0, 0x94($s2)
/* BB3AF0 80240CF0 AFA00010 */  sw        $zero, 0x10($sp)
/* BB3AF4 80240CF4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BB3AF8 80240CF8 8C420030 */  lw        $v0, 0x30($v0)
/* BB3AFC 80240CFC AFA20014 */  sw        $v0, 0x14($sp)
/* BB3B00 80240D00 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BB3B04 80240D04 8C42001C */  lw        $v0, 0x1c($v0)
/* BB3B08 80240D08 AFA20018 */  sw        $v0, 0x18($sp)
/* BB3B0C 80240D0C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BB3B10 80240D10 8C420024 */  lw        $v0, 0x24($v0)
/* BB3B14 80240D14 AFA2001C */  sw        $v0, 0x1c($sp)
/* BB3B18 80240D18 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BB3B1C 80240D1C 8C420028 */  lw        $v0, 0x28($v0)
/* BB3B20 80240D20 AFA20020 */  sw        $v0, 0x20($sp)
/* BB3B24 80240D24 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BB3B28 80240D28 3C0142C8 */  lui       $at, 0x42c8
/* BB3B2C 80240D2C 44810000 */  mtc1      $at, $f0
/* BB3B30 80240D30 8C42002C */  lw        $v0, 0x2c($v0)
/* BB3B34 80240D34 27B00010 */  addiu     $s0, $sp, 0x10
/* BB3B38 80240D38 E7A00028 */  swc1      $f0, 0x28($sp)
/* BB3B3C 80240D3C A7A0002C */  sh        $zero, 0x2c($sp)
/* BB3B40 80240D40 12200019 */  beqz      $s1, .L80240DA8
/* BB3B44 80240D44 AFA20024 */   sw       $v0, 0x24($sp)
/* BB3B48 80240D48 AE600070 */  sw        $zero, 0x70($s3)
/* BB3B4C 80240D4C A6A0008E */  sh        $zero, 0x8e($s5)
/* BB3B50 80240D50 AE600074 */  sw        $zero, 0x74($s3)
/* BB3B54 80240D54 8EA20000 */  lw        $v0, ($s5)
/* BB3B58 80240D58 2403F7FF */  addiu     $v1, $zero, -0x801
/* BB3B5C 80240D5C 00431024 */  and       $v0, $v0, $v1
/* BB3B60 80240D60 2403FDFF */  addiu     $v1, $zero, -0x201
/* BB3B64 80240D64 00431024 */  and       $v0, $v0, $v1
/* BB3B68 80240D68 34420008 */  ori       $v0, $v0, 8
/* BB3B6C 80240D6C AEA20000 */  sw        $v0, ($s5)
/* BB3B70 80240D70 8E4200B0 */  lw        $v0, 0xb0($s2)
/* BB3B74 80240D74 34420018 */  ori       $v0, $v0, 0x18
/* BB3B78 80240D78 AE4200B0 */  sw        $v0, 0xb0($s2)
/* BB3B7C 80240D7C 8E420000 */  lw        $v0, ($s2)
/* BB3B80 80240D80 3C034000 */  lui       $v1, 0x4000
/* BB3B84 80240D84 00431024 */  and       $v0, $v0, $v1
/* BB3B88 80240D88 10400007 */  beqz      $v0, .L80240DA8
/* BB3B8C 80240D8C 3C03BFFF */   lui      $v1, 0xbfff
/* BB3B90 80240D90 2402000C */  addiu     $v0, $zero, 0xc
/* BB3B94 80240D94 AE620070 */  sw        $v0, 0x70($s3)
/* BB3B98 80240D98 8E420000 */  lw        $v0, ($s2)
/* BB3B9C 80240D9C 3463FFFF */  ori       $v1, $v1, 0xffff
/* BB3BA0 80240DA0 00431024 */  and       $v0, $v0, $v1
/* BB3BA4 80240DA4 AE420000 */  sw        $v0, ($s2)
.L80240DA8:
/* BB3BA8 80240DA8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BB3BAC 80240DAC 30620004 */  andi      $v0, $v1, 4
/* BB3BB0 80240DB0 10400007 */  beqz      $v0, .L80240DD0
/* BB3BB4 80240DB4 00000000 */   nop      
/* BB3BB8 80240DB8 824200B4 */  lb        $v0, 0xb4($s2)
/* BB3BBC 80240DBC 14400034 */  bnez      $v0, .L80240E90
/* BB3BC0 80240DC0 0000102D */   daddu    $v0, $zero, $zero
/* BB3BC4 80240DC4 2402FFFB */  addiu     $v0, $zero, -5
/* BB3BC8 80240DC8 00621024 */  and       $v0, $v1, $v0
/* BB3BCC 80240DCC AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240DD0:
/* BB3BD0 80240DD0 8E630070 */  lw        $v1, 0x70($s3)
/* BB3BD4 80240DD4 2C62000F */  sltiu     $v0, $v1, 0xf
/* BB3BD8 80240DD8 1040002C */  beqz      $v0, .L80240E8C
/* BB3BDC 80240DDC 00031080 */   sll      $v0, $v1, 2
/* BB3BE0 80240DE0 3C018024 */  lui       $at, 0x8024
/* BB3BE4 80240DE4 00220821 */  addu      $at, $at, $v0
/* BB3BE8 80240DE8 8C222B98 */  lw        $v0, 0x2b98($at)
/* BB3BEC 80240DEC 00400008 */  jr        $v0
/* BB3BF0 80240DF0 00000000 */   nop      
/* BB3BF4 80240DF4 0260202D */  daddu     $a0, $s3, $zero
/* BB3BF8 80240DF8 0280282D */  daddu     $a1, $s4, $zero
/* BB3BFC 80240DFC 0C090028 */  jal       func_802400A0
/* BB3C00 80240E00 0200302D */   daddu    $a2, $s0, $zero
/* BB3C04 80240E04 0260202D */  daddu     $a0, $s3, $zero
/* BB3C08 80240E08 0280282D */  daddu     $a1, $s4, $zero
/* BB3C0C 80240E0C 0C0900B4 */  jal       func_802402D0
/* BB3C10 80240E10 0200302D */   daddu    $a2, $s0, $zero
/* BB3C14 80240E14 080903A4 */  j         .L80240E90
/* BB3C18 80240E18 0000102D */   daddu    $v0, $zero, $zero
/* BB3C1C 80240E1C 0260202D */  daddu     $a0, $s3, $zero
/* BB3C20 80240E20 0280282D */  daddu     $a1, $s4, $zero
/* BB3C24 80240E24 0C090182 */  jal       func_80240608
/* BB3C28 80240E28 0200302D */   daddu    $a2, $s0, $zero
/* BB3C2C 80240E2C 8E630070 */  lw        $v1, 0x70($s3)
/* BB3C30 80240E30 24020003 */  addiu     $v0, $zero, 3
/* BB3C34 80240E34 14620016 */  bne       $v1, $v0, .L80240E90
/* BB3C38 80240E38 0000102D */   daddu    $v0, $zero, $zero
/* BB3C3C 80240E3C 0260202D */  daddu     $a0, $s3, $zero
/* BB3C40 80240E40 0280282D */  daddu     $a1, $s4, $zero
/* BB3C44 80240E44 0C0901B2 */  jal       func_802406C8
/* BB3C48 80240E48 0200302D */   daddu    $a2, $s0, $zero
/* BB3C4C 80240E4C 080903A4 */  j         .L80240E90
/* BB3C50 80240E50 0000102D */   daddu    $v0, $zero, $zero
/* BB3C54 80240E54 0260202D */  daddu     $a0, $s3, $zero
/* BB3C58 80240E58 0280282D */  daddu     $a1, $s4, $zero
/* BB3C5C 80240E5C 0C09021B */  jal       func_8024086C
/* BB3C60 80240E60 0200302D */   daddu    $a2, $s0, $zero
/* BB3C64 80240E64 0260202D */  daddu     $a0, $s3, $zero
/* BB3C68 80240E68 0280282D */  daddu     $a1, $s4, $zero
/* BB3C6C 80240E6C 0C090253 */  jal       func_8024094C
/* BB3C70 80240E70 0200302D */   daddu    $a2, $s0, $zero
/* BB3C74 80240E74 080903A4 */  j         .L80240E90
/* BB3C78 80240E78 0000102D */   daddu    $v0, $zero, $zero
/* BB3C7C 80240E7C 0260202D */  daddu     $a0, $s3, $zero
/* BB3C80 80240E80 0280282D */  daddu     $a1, $s4, $zero
/* BB3C84 80240E84 0C090313 */  jal       func_80240C4C
/* BB3C88 80240E88 0200302D */   daddu    $a2, $s0, $zero
.L80240E8C:
/* BB3C8C 80240E8C 0000102D */  daddu     $v0, $zero, $zero
.L80240E90:
/* BB3C90 80240E90 8FBF0048 */  lw        $ra, 0x48($sp)
/* BB3C94 80240E94 8FB50044 */  lw        $s5, 0x44($sp)
/* BB3C98 80240E98 8FB40040 */  lw        $s4, 0x40($sp)
/* BB3C9C 80240E9C 8FB3003C */  lw        $s3, 0x3c($sp)
/* BB3CA0 80240EA0 8FB20038 */  lw        $s2, 0x38($sp)
/* BB3CA4 80240EA4 8FB10034 */  lw        $s1, 0x34($sp)
/* BB3CA8 80240EA8 8FB00030 */  lw        $s0, 0x30($sp)
/* BB3CAC 80240EAC 03E00008 */  jr        $ra
/* BB3CB0 80240EB0 27BD0050 */   addiu    $sp, $sp, 0x50
/* BB3CB4 80240EB4 00000000 */  nop       
/* BB3CB8 80240EB8 00000000 */  nop       
/* BB3CBC 80240EBC 00000000 */  nop       
