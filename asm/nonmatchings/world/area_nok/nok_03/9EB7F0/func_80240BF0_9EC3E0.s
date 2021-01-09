.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BF0_9EC3E0
/* 9EC3E0 80240BF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9EC3E4 80240BF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9EC3E8 80240BF8 0080982D */  daddu     $s3, $a0, $zero
/* 9EC3EC 80240BFC AFBF0048 */  sw        $ra, 0x48($sp)
/* 9EC3F0 80240C00 AFB50044 */  sw        $s5, 0x44($sp)
/* 9EC3F4 80240C04 AFB40040 */  sw        $s4, 0x40($sp)
/* 9EC3F8 80240C08 AFB20038 */  sw        $s2, 0x38($sp)
/* 9EC3FC 80240C0C AFB10034 */  sw        $s1, 0x34($sp)
/* 9EC400 80240C10 AFB00030 */  sw        $s0, 0x30($sp)
/* 9EC404 80240C14 8E720148 */  lw        $s2, 0x148($s3)
/* 9EC408 80240C18 86440008 */  lh        $a0, 8($s2)
/* 9EC40C 80240C1C 8E70000C */  lw        $s0, 0xc($s3)
/* 9EC410 80240C20 0C00EABB */  jal       get_npc_unsafe
/* 9EC414 80240C24 00A0882D */   daddu    $s1, $a1, $zero
/* 9EC418 80240C28 8E050000 */  lw        $a1, ($s0)
/* 9EC41C 80240C2C 26100004 */  addiu     $s0, $s0, 4
/* 9EC420 80240C30 0260202D */  daddu     $a0, $s3, $zero
/* 9EC424 80240C34 0C0B1EAF */  jal       get_variable
/* 9EC428 80240C38 0040A82D */   daddu    $s5, $v0, $zero
/* 9EC42C 80240C3C 0260202D */  daddu     $a0, $s3, $zero
/* 9EC430 80240C40 8E050000 */  lw        $a1, ($s0)
/* 9EC434 80240C44 0C0B1EAF */  jal       get_variable
/* 9EC438 80240C48 0040A02D */   daddu    $s4, $v0, $zero
/* 9EC43C 80240C4C AE420094 */  sw        $v0, 0x94($s2)
/* 9EC440 80240C50 AFA00010 */  sw        $zero, 0x10($sp)
/* 9EC444 80240C54 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9EC448 80240C58 8C420030 */  lw        $v0, 0x30($v0)
/* 9EC44C 80240C5C AFA20014 */  sw        $v0, 0x14($sp)
/* 9EC450 80240C60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9EC454 80240C64 8C42001C */  lw        $v0, 0x1c($v0)
/* 9EC458 80240C68 AFA20018 */  sw        $v0, 0x18($sp)
/* 9EC45C 80240C6C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9EC460 80240C70 8C420024 */  lw        $v0, 0x24($v0)
/* 9EC464 80240C74 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9EC468 80240C78 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9EC46C 80240C7C 8C420028 */  lw        $v0, 0x28($v0)
/* 9EC470 80240C80 AFA20020 */  sw        $v0, 0x20($sp)
/* 9EC474 80240C84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9EC478 80240C88 3C0142C8 */  lui       $at, 0x42c8
/* 9EC47C 80240C8C 44810000 */  mtc1      $at, $f0
/* 9EC480 80240C90 8C42002C */  lw        $v0, 0x2c($v0)
/* 9EC484 80240C94 27B00010 */  addiu     $s0, $sp, 0x10
/* 9EC488 80240C98 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9EC48C 80240C9C A7A0002C */  sh        $zero, 0x2c($sp)
/* 9EC490 80240CA0 12200019 */  beqz      $s1, .L80240D08
/* 9EC494 80240CA4 AFA20024 */   sw       $v0, 0x24($sp)
/* 9EC498 80240CA8 AE600070 */  sw        $zero, 0x70($s3)
/* 9EC49C 80240CAC A6A0008E */  sh        $zero, 0x8e($s5)
/* 9EC4A0 80240CB0 AE600074 */  sw        $zero, 0x74($s3)
/* 9EC4A4 80240CB4 8EA20000 */  lw        $v0, ($s5)
/* 9EC4A8 80240CB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* 9EC4AC 80240CBC 00431024 */  and       $v0, $v0, $v1
/* 9EC4B0 80240CC0 2403FDFF */  addiu     $v1, $zero, -0x201
/* 9EC4B4 80240CC4 00431024 */  and       $v0, $v0, $v1
/* 9EC4B8 80240CC8 34420008 */  ori       $v0, $v0, 8
/* 9EC4BC 80240CCC AEA20000 */  sw        $v0, ($s5)
/* 9EC4C0 80240CD0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 9EC4C4 80240CD4 34420018 */  ori       $v0, $v0, 0x18
/* 9EC4C8 80240CD8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* 9EC4CC 80240CDC 8E420000 */  lw        $v0, ($s2)
/* 9EC4D0 80240CE0 3C034000 */  lui       $v1, 0x4000
/* 9EC4D4 80240CE4 00431024 */  and       $v0, $v0, $v1
/* 9EC4D8 80240CE8 10400007 */  beqz      $v0, .L80240D08
/* 9EC4DC 80240CEC 3C03BFFF */   lui      $v1, 0xbfff
/* 9EC4E0 80240CF0 2402000C */  addiu     $v0, $zero, 0xc
/* 9EC4E4 80240CF4 AE620070 */  sw        $v0, 0x70($s3)
/* 9EC4E8 80240CF8 8E420000 */  lw        $v0, ($s2)
/* 9EC4EC 80240CFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9EC4F0 80240D00 00431024 */  and       $v0, $v0, $v1
/* 9EC4F4 80240D04 AE420000 */  sw        $v0, ($s2)
.L80240D08:
/* 9EC4F8 80240D08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 9EC4FC 80240D0C 30620004 */  andi      $v0, $v1, 4
/* 9EC500 80240D10 10400007 */  beqz      $v0, .L80240D30
/* 9EC504 80240D14 00000000 */   nop      
/* 9EC508 80240D18 824200B4 */  lb        $v0, 0xb4($s2)
/* 9EC50C 80240D1C 14400034 */  bnez      $v0, .L80240DF0
/* 9EC510 80240D20 0000102D */   daddu    $v0, $zero, $zero
/* 9EC514 80240D24 2402FFFB */  addiu     $v0, $zero, -5
/* 9EC518 80240D28 00621024 */  and       $v0, $v1, $v0
/* 9EC51C 80240D2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240D30:
/* 9EC520 80240D30 8E630070 */  lw        $v1, 0x70($s3)
/* 9EC524 80240D34 2C62000F */  sltiu     $v0, $v1, 0xf
/* 9EC528 80240D38 1040002C */  beqz      $v0, .L80240DEC
/* 9EC52C 80240D3C 00031080 */   sll      $v0, $v1, 2
/* 9EC530 80240D40 3C018024 */  lui       $at, %hi(D_802423B8)
/* 9EC534 80240D44 00220821 */  addu      $at, $at, $v0
/* 9EC538 80240D48 8C2223B8 */  lw        $v0, %lo(D_802423B8)($at)
/* 9EC53C 80240D4C 00400008 */  jr        $v0
/* 9EC540 80240D50 00000000 */   nop      
/* 9EC544 80240D54 0260202D */  daddu     $a0, $s3, $zero
/* 9EC548 80240D58 0280282D */  daddu     $a1, $s4, $zero
/* 9EC54C 80240D5C 0C090000 */  jal       func_80240000_9EB7F0
/* 9EC550 80240D60 0200302D */   daddu    $a2, $s0, $zero
/* 9EC554 80240D64 0260202D */  daddu     $a0, $s3, $zero
/* 9EC558 80240D68 0280282D */  daddu     $a1, $s4, $zero
/* 9EC55C 80240D6C 0C09008C */  jal       func_80240230_9EBA20
/* 9EC560 80240D70 0200302D */   daddu    $a2, $s0, $zero
/* 9EC564 80240D74 0809037C */  j         .L80240DF0
/* 9EC568 80240D78 0000102D */   daddu    $v0, $zero, $zero
/* 9EC56C 80240D7C 0260202D */  daddu     $a0, $s3, $zero
/* 9EC570 80240D80 0280282D */  daddu     $a1, $s4, $zero
/* 9EC574 80240D84 0C09015A */  jal       func_80240568_9EBD58
/* 9EC578 80240D88 0200302D */   daddu    $a2, $s0, $zero
/* 9EC57C 80240D8C 8E630070 */  lw        $v1, 0x70($s3)
/* 9EC580 80240D90 24020003 */  addiu     $v0, $zero, 3
/* 9EC584 80240D94 14620016 */  bne       $v1, $v0, .L80240DF0
/* 9EC588 80240D98 0000102D */   daddu    $v0, $zero, $zero
/* 9EC58C 80240D9C 0260202D */  daddu     $a0, $s3, $zero
/* 9EC590 80240DA0 0280282D */  daddu     $a1, $s4, $zero
/* 9EC594 80240DA4 0C09018A */  jal       func_80240628_9EBE18
/* 9EC598 80240DA8 0200302D */   daddu    $a2, $s0, $zero
/* 9EC59C 80240DAC 0809037C */  j         .L80240DF0
/* 9EC5A0 80240DB0 0000102D */   daddu    $v0, $zero, $zero
/* 9EC5A4 80240DB4 0260202D */  daddu     $a0, $s3, $zero
/* 9EC5A8 80240DB8 0280282D */  daddu     $a1, $s4, $zero
/* 9EC5AC 80240DBC 0C0901F3 */  jal       func_802407CC_9EBFBC
/* 9EC5B0 80240DC0 0200302D */   daddu    $a2, $s0, $zero
/* 9EC5B4 80240DC4 0260202D */  daddu     $a0, $s3, $zero
/* 9EC5B8 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* 9EC5BC 80240DCC 0C09022B */  jal       func_802408AC_9EC09C
/* 9EC5C0 80240DD0 0200302D */   daddu    $a2, $s0, $zero
/* 9EC5C4 80240DD4 0809037C */  j         .L80240DF0
/* 9EC5C8 80240DD8 0000102D */   daddu    $v0, $zero, $zero
/* 9EC5CC 80240DDC 0260202D */  daddu     $a0, $s3, $zero
/* 9EC5D0 80240DE0 0280282D */  daddu     $a1, $s4, $zero
/* 9EC5D4 80240DE4 0C0902EB */  jal       func_80240BAC_9EC39C
/* 9EC5D8 80240DE8 0200302D */   daddu    $a2, $s0, $zero
.L80240DEC:
/* 9EC5DC 80240DEC 0000102D */  daddu     $v0, $zero, $zero
.L80240DF0:
/* 9EC5E0 80240DF0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 9EC5E4 80240DF4 8FB50044 */  lw        $s5, 0x44($sp)
/* 9EC5E8 80240DF8 8FB40040 */  lw        $s4, 0x40($sp)
/* 9EC5EC 80240DFC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9EC5F0 80240E00 8FB20038 */  lw        $s2, 0x38($sp)
/* 9EC5F4 80240E04 8FB10034 */  lw        $s1, 0x34($sp)
/* 9EC5F8 80240E08 8FB00030 */  lw        $s0, 0x30($sp)
/* 9EC5FC 80240E0C 03E00008 */  jr        $ra
/* 9EC600 80240E10 27BD0050 */   addiu    $sp, $sp, 0x50
/* 9EC604 80240E14 00000000 */  nop       
/* 9EC608 80240E18 00000000 */  nop       
/* 9EC60C 80240E1C 00000000 */  nop       
