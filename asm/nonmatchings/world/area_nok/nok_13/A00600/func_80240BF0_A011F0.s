.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BF0_A011F0
/* A011F0 80240BF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A011F4 80240BF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* A011F8 80240BF8 0080982D */  daddu     $s3, $a0, $zero
/* A011FC 80240BFC AFBF0048 */  sw        $ra, 0x48($sp)
/* A01200 80240C00 AFB50044 */  sw        $s5, 0x44($sp)
/* A01204 80240C04 AFB40040 */  sw        $s4, 0x40($sp)
/* A01208 80240C08 AFB20038 */  sw        $s2, 0x38($sp)
/* A0120C 80240C0C AFB10034 */  sw        $s1, 0x34($sp)
/* A01210 80240C10 AFB00030 */  sw        $s0, 0x30($sp)
/* A01214 80240C14 8E720148 */  lw        $s2, 0x148($s3)
/* A01218 80240C18 86440008 */  lh        $a0, 8($s2)
/* A0121C 80240C1C 8E70000C */  lw        $s0, 0xc($s3)
/* A01220 80240C20 0C00EABB */  jal       get_npc_unsafe
/* A01224 80240C24 00A0882D */   daddu    $s1, $a1, $zero
/* A01228 80240C28 8E050000 */  lw        $a1, ($s0)
/* A0122C 80240C2C 26100004 */  addiu     $s0, $s0, 4
/* A01230 80240C30 0260202D */  daddu     $a0, $s3, $zero
/* A01234 80240C34 0C0B1EAF */  jal       get_variable
/* A01238 80240C38 0040A82D */   daddu    $s5, $v0, $zero
/* A0123C 80240C3C 0260202D */  daddu     $a0, $s3, $zero
/* A01240 80240C40 8E050000 */  lw        $a1, ($s0)
/* A01244 80240C44 0C0B1EAF */  jal       get_variable
/* A01248 80240C48 0040A02D */   daddu    $s4, $v0, $zero
/* A0124C 80240C4C AE420094 */  sw        $v0, 0x94($s2)
/* A01250 80240C50 AFA00010 */  sw        $zero, 0x10($sp)
/* A01254 80240C54 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A01258 80240C58 8C420030 */  lw        $v0, 0x30($v0)
/* A0125C 80240C5C AFA20014 */  sw        $v0, 0x14($sp)
/* A01260 80240C60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A01264 80240C64 8C42001C */  lw        $v0, 0x1c($v0)
/* A01268 80240C68 AFA20018 */  sw        $v0, 0x18($sp)
/* A0126C 80240C6C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A01270 80240C70 8C420024 */  lw        $v0, 0x24($v0)
/* A01274 80240C74 AFA2001C */  sw        $v0, 0x1c($sp)
/* A01278 80240C78 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A0127C 80240C7C 8C420028 */  lw        $v0, 0x28($v0)
/* A01280 80240C80 AFA20020 */  sw        $v0, 0x20($sp)
/* A01284 80240C84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A01288 80240C88 3C0142C8 */  lui       $at, 0x42c8
/* A0128C 80240C8C 44810000 */  mtc1      $at, $f0
/* A01290 80240C90 8C42002C */  lw        $v0, 0x2c($v0)
/* A01294 80240C94 27B00010 */  addiu     $s0, $sp, 0x10
/* A01298 80240C98 E7A00028 */  swc1      $f0, 0x28($sp)
/* A0129C 80240C9C A7A0002C */  sh        $zero, 0x2c($sp)
/* A012A0 80240CA0 12200019 */  beqz      $s1, .L80240D08
/* A012A4 80240CA4 AFA20024 */   sw       $v0, 0x24($sp)
/* A012A8 80240CA8 AE600070 */  sw        $zero, 0x70($s3)
/* A012AC 80240CAC A6A0008E */  sh        $zero, 0x8e($s5)
/* A012B0 80240CB0 AE600074 */  sw        $zero, 0x74($s3)
/* A012B4 80240CB4 8EA20000 */  lw        $v0, ($s5)
/* A012B8 80240CB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A012BC 80240CBC 00431024 */  and       $v0, $v0, $v1
/* A012C0 80240CC0 2403FDFF */  addiu     $v1, $zero, -0x201
/* A012C4 80240CC4 00431024 */  and       $v0, $v0, $v1
/* A012C8 80240CC8 34420008 */  ori       $v0, $v0, 8
/* A012CC 80240CCC AEA20000 */  sw        $v0, ($s5)
/* A012D0 80240CD0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A012D4 80240CD4 34420018 */  ori       $v0, $v0, 0x18
/* A012D8 80240CD8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* A012DC 80240CDC 8E420000 */  lw        $v0, ($s2)
/* A012E0 80240CE0 3C034000 */  lui       $v1, 0x4000
/* A012E4 80240CE4 00431024 */  and       $v0, $v0, $v1
/* A012E8 80240CE8 10400007 */  beqz      $v0, .L80240D08
/* A012EC 80240CEC 3C03BFFF */   lui      $v1, 0xbfff
/* A012F0 80240CF0 2402000C */  addiu     $v0, $zero, 0xc
/* A012F4 80240CF4 AE620070 */  sw        $v0, 0x70($s3)
/* A012F8 80240CF8 8E420000 */  lw        $v0, ($s2)
/* A012FC 80240CFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* A01300 80240D00 00431024 */  and       $v0, $v0, $v1
/* A01304 80240D04 AE420000 */  sw        $v0, ($s2)
.L80240D08:
/* A01308 80240D08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A0130C 80240D0C 30620004 */  andi      $v0, $v1, 4
/* A01310 80240D10 10400007 */  beqz      $v0, .L80240D30
/* A01314 80240D14 00000000 */   nop      
/* A01318 80240D18 824200B4 */  lb        $v0, 0xb4($s2)
/* A0131C 80240D1C 14400034 */  bnez      $v0, .L80240DF0
/* A01320 80240D20 0000102D */   daddu    $v0, $zero, $zero
/* A01324 80240D24 2402FFFB */  addiu     $v0, $zero, -5
/* A01328 80240D28 00621024 */  and       $v0, $v1, $v0
/* A0132C 80240D2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240D30:
/* A01330 80240D30 8E630070 */  lw        $v1, 0x70($s3)
/* A01334 80240D34 2C62000F */  sltiu     $v0, $v1, 0xf
/* A01338 80240D38 1040002C */  beqz      $v0, .L80240DEC
/* A0133C 80240D3C 00031080 */   sll      $v0, $v1, 2
/* A01340 80240D40 3C018024 */  lui       $at, %hi(D_802421D8)
/* A01344 80240D44 00220821 */  addu      $at, $at, $v0
/* A01348 80240D48 8C2221D8 */  lw        $v0, %lo(D_802421D8)($at)
/* A0134C 80240D4C 00400008 */  jr        $v0
/* A01350 80240D50 00000000 */   nop      
/* A01354 80240D54 0260202D */  daddu     $a0, $s3, $zero
/* A01358 80240D58 0280282D */  daddu     $a1, $s4, $zero
/* A0135C 80240D5C 0C090000 */  jal       func_80240000_A00600
/* A01360 80240D60 0200302D */   daddu    $a2, $s0, $zero
/* A01364 80240D64 0260202D */  daddu     $a0, $s3, $zero
/* A01368 80240D68 0280282D */  daddu     $a1, $s4, $zero
/* A0136C 80240D6C 0C09008C */  jal       func_80240230_A00830
/* A01370 80240D70 0200302D */   daddu    $a2, $s0, $zero
/* A01374 80240D74 0809037C */  j         .L80240DF0
/* A01378 80240D78 0000102D */   daddu    $v0, $zero, $zero
/* A0137C 80240D7C 0260202D */  daddu     $a0, $s3, $zero
/* A01380 80240D80 0280282D */  daddu     $a1, $s4, $zero
/* A01384 80240D84 0C09015A */  jal       func_80240568_A00B68
/* A01388 80240D88 0200302D */   daddu    $a2, $s0, $zero
/* A0138C 80240D8C 8E630070 */  lw        $v1, 0x70($s3)
/* A01390 80240D90 24020003 */  addiu     $v0, $zero, 3
/* A01394 80240D94 14620016 */  bne       $v1, $v0, .L80240DF0
/* A01398 80240D98 0000102D */   daddu    $v0, $zero, $zero
/* A0139C 80240D9C 0260202D */  daddu     $a0, $s3, $zero
/* A013A0 80240DA0 0280282D */  daddu     $a1, $s4, $zero
/* A013A4 80240DA4 0C09018A */  jal       func_80240628_A00C28
/* A013A8 80240DA8 0200302D */   daddu    $a2, $s0, $zero
/* A013AC 80240DAC 0809037C */  j         .L80240DF0
/* A013B0 80240DB0 0000102D */   daddu    $v0, $zero, $zero
/* A013B4 80240DB4 0260202D */  daddu     $a0, $s3, $zero
/* A013B8 80240DB8 0280282D */  daddu     $a1, $s4, $zero
/* A013BC 80240DBC 0C0901F3 */  jal       func_802407CC_A00DCC
/* A013C0 80240DC0 0200302D */   daddu    $a2, $s0, $zero
/* A013C4 80240DC4 0260202D */  daddu     $a0, $s3, $zero
/* A013C8 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* A013CC 80240DCC 0C09022B */  jal       func_802408AC_A00EAC
/* A013D0 80240DD0 0200302D */   daddu    $a2, $s0, $zero
/* A013D4 80240DD4 0809037C */  j         .L80240DF0
/* A013D8 80240DD8 0000102D */   daddu    $v0, $zero, $zero
/* A013DC 80240DDC 0260202D */  daddu     $a0, $s3, $zero
/* A013E0 80240DE0 0280282D */  daddu     $a1, $s4, $zero
/* A013E4 80240DE4 0C0902EB */  jal       func_80240BAC_A011AC
/* A013E8 80240DE8 0200302D */   daddu    $a2, $s0, $zero
.L80240DEC:
/* A013EC 80240DEC 0000102D */  daddu     $v0, $zero, $zero
.L80240DF0:
/* A013F0 80240DF0 8FBF0048 */  lw        $ra, 0x48($sp)
/* A013F4 80240DF4 8FB50044 */  lw        $s5, 0x44($sp)
/* A013F8 80240DF8 8FB40040 */  lw        $s4, 0x40($sp)
/* A013FC 80240DFC 8FB3003C */  lw        $s3, 0x3c($sp)
/* A01400 80240E00 8FB20038 */  lw        $s2, 0x38($sp)
/* A01404 80240E04 8FB10034 */  lw        $s1, 0x34($sp)
/* A01408 80240E08 8FB00030 */  lw        $s0, 0x30($sp)
/* A0140C 80240E0C 03E00008 */  jr        $ra
/* A01410 80240E10 27BD0050 */   addiu    $sp, $sp, 0x50
/* A01414 80240E14 00000000 */  nop       
/* A01418 80240E18 00000000 */  nop       
/* A0141C 80240E1C 00000000 */  nop       
