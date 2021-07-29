.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80242A38_995168
.word L80240D54_993484, L80240D64_993494, L80240D7C_9934AC, L80240D9C_9934CC, L80240DEC_99351C, L80240DEC_99351C, L80240DEC_99351C, L80240DEC_99351C, L80240DEC_99351C, L80240DEC_99351C, L80240DEC_99351C, L80240DEC_99351C, L80240DB4_9934E4, L80240DC4_9934F4, L80240DDC_99350C, 0

.section .text

glabel func_80240BF0_993320
/* 993320 80240BF0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 993324 80240BF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 993328 80240BF8 0080982D */  daddu     $s3, $a0, $zero
/* 99332C 80240BFC AFBF0048 */  sw        $ra, 0x48($sp)
/* 993330 80240C00 AFB50044 */  sw        $s5, 0x44($sp)
/* 993334 80240C04 AFB40040 */  sw        $s4, 0x40($sp)
/* 993338 80240C08 AFB20038 */  sw        $s2, 0x38($sp)
/* 99333C 80240C0C AFB10034 */  sw        $s1, 0x34($sp)
/* 993340 80240C10 AFB00030 */  sw        $s0, 0x30($sp)
/* 993344 80240C14 8E720148 */  lw        $s2, 0x148($s3)
/* 993348 80240C18 86440008 */  lh        $a0, 8($s2)
/* 99334C 80240C1C 8E70000C */  lw        $s0, 0xc($s3)
/* 993350 80240C20 0C00EABB */  jal       get_npc_unsafe
/* 993354 80240C24 00A0882D */   daddu    $s1, $a1, $zero
/* 993358 80240C28 8E050000 */  lw        $a1, ($s0)
/* 99335C 80240C2C 26100004 */  addiu     $s0, $s0, 4
/* 993360 80240C30 0260202D */  daddu     $a0, $s3, $zero
/* 993364 80240C34 0C0B1EAF */  jal       get_variable
/* 993368 80240C38 0040A82D */   daddu    $s5, $v0, $zero
/* 99336C 80240C3C 0260202D */  daddu     $a0, $s3, $zero
/* 993370 80240C40 8E050000 */  lw        $a1, ($s0)
/* 993374 80240C44 0C0B1EAF */  jal       get_variable
/* 993378 80240C48 0040A02D */   daddu    $s4, $v0, $zero
/* 99337C 80240C4C AE420094 */  sw        $v0, 0x94($s2)
/* 993380 80240C50 AFA00010 */  sw        $zero, 0x10($sp)
/* 993384 80240C54 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 993388 80240C58 8C420030 */  lw        $v0, 0x30($v0)
/* 99338C 80240C5C AFA20014 */  sw        $v0, 0x14($sp)
/* 993390 80240C60 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 993394 80240C64 8C42001C */  lw        $v0, 0x1c($v0)
/* 993398 80240C68 AFA20018 */  sw        $v0, 0x18($sp)
/* 99339C 80240C6C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9933A0 80240C70 8C420024 */  lw        $v0, 0x24($v0)
/* 9933A4 80240C74 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9933A8 80240C78 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9933AC 80240C7C 8C420028 */  lw        $v0, 0x28($v0)
/* 9933B0 80240C80 AFA20020 */  sw        $v0, 0x20($sp)
/* 9933B4 80240C84 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9933B8 80240C88 3C0142C8 */  lui       $at, 0x42c8
/* 9933BC 80240C8C 44810000 */  mtc1      $at, $f0
/* 9933C0 80240C90 8C42002C */  lw        $v0, 0x2c($v0)
/* 9933C4 80240C94 27B00010 */  addiu     $s0, $sp, 0x10
/* 9933C8 80240C98 E7A00028 */  swc1      $f0, 0x28($sp)
/* 9933CC 80240C9C A7A0002C */  sh        $zero, 0x2c($sp)
/* 9933D0 80240CA0 12200019 */  beqz      $s1, .L80240D08
/* 9933D4 80240CA4 AFA20024 */   sw       $v0, 0x24($sp)
/* 9933D8 80240CA8 AE600070 */  sw        $zero, 0x70($s3)
/* 9933DC 80240CAC A6A0008E */  sh        $zero, 0x8e($s5)
/* 9933E0 80240CB0 AE600074 */  sw        $zero, 0x74($s3)
/* 9933E4 80240CB4 8EA20000 */  lw        $v0, ($s5)
/* 9933E8 80240CB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* 9933EC 80240CBC 00431024 */  and       $v0, $v0, $v1
/* 9933F0 80240CC0 2403FDFF */  addiu     $v1, $zero, -0x201
/* 9933F4 80240CC4 00431024 */  and       $v0, $v0, $v1
/* 9933F8 80240CC8 34420008 */  ori       $v0, $v0, 8
/* 9933FC 80240CCC AEA20000 */  sw        $v0, ($s5)
/* 993400 80240CD0 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 993404 80240CD4 34420018 */  ori       $v0, $v0, 0x18
/* 993408 80240CD8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* 99340C 80240CDC 8E420000 */  lw        $v0, ($s2)
/* 993410 80240CE0 3C034000 */  lui       $v1, 0x4000
/* 993414 80240CE4 00431024 */  and       $v0, $v0, $v1
/* 993418 80240CE8 10400007 */  beqz      $v0, .L80240D08
/* 99341C 80240CEC 3C03BFFF */   lui      $v1, 0xbfff
/* 993420 80240CF0 2402000C */  addiu     $v0, $zero, 0xc
/* 993424 80240CF4 AE620070 */  sw        $v0, 0x70($s3)
/* 993428 80240CF8 8E420000 */  lw        $v0, ($s2)
/* 99342C 80240CFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 993430 80240D00 00431024 */  and       $v0, $v0, $v1
/* 993434 80240D04 AE420000 */  sw        $v0, ($s2)
.L80240D08:
/* 993438 80240D08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 99343C 80240D0C 30620004 */  andi      $v0, $v1, 4
/* 993440 80240D10 10400007 */  beqz      $v0, .L80240D30
/* 993444 80240D14 00000000 */   nop
/* 993448 80240D18 824200B4 */  lb        $v0, 0xb4($s2)
/* 99344C 80240D1C 14400034 */  bnez      $v0, .L80240DF0
/* 993450 80240D20 0000102D */   daddu    $v0, $zero, $zero
/* 993454 80240D24 2402FFFB */  addiu     $v0, $zero, -5
/* 993458 80240D28 00621024 */  and       $v0, $v1, $v0
/* 99345C 80240D2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80240D30:
/* 993460 80240D30 8E630070 */  lw        $v1, 0x70($s3)
/* 993464 80240D34 2C62000F */  sltiu     $v0, $v1, 0xf
/* 993468 80240D38 1040002C */  beqz      $v0, L80240DEC_99351C
/* 99346C 80240D3C 00031080 */   sll      $v0, $v1, 2
/* 993470 80240D40 3C018024 */  lui       $at, %hi(jtbl_80242A38_995168)
/* 993474 80240D44 00220821 */  addu      $at, $at, $v0
/* 993478 80240D48 8C222A38 */  lw        $v0, %lo(jtbl_80242A38_995168)($at)
/* 99347C 80240D4C 00400008 */  jr        $v0
/* 993480 80240D50 00000000 */   nop
glabel L80240D54_993484
/* 993484 80240D54 0260202D */  daddu     $a0, $s3, $zero
/* 993488 80240D58 0280282D */  daddu     $a1, $s4, $zero
/* 99348C 80240D5C 0C090000 */  jal       func_80240000_992730
/* 993490 80240D60 0200302D */   daddu    $a2, $s0, $zero
glabel L80240D64_993494
/* 993494 80240D64 0260202D */  daddu     $a0, $s3, $zero
/* 993498 80240D68 0280282D */  daddu     $a1, $s4, $zero
/* 99349C 80240D6C 0C09008C */  jal       func_80240230_992960
/* 9934A0 80240D70 0200302D */   daddu    $a2, $s0, $zero
/* 9934A4 80240D74 0809037C */  j         .L80240DF0
/* 9934A8 80240D78 0000102D */   daddu    $v0, $zero, $zero
glabel L80240D7C_9934AC
/* 9934AC 80240D7C 0260202D */  daddu     $a0, $s3, $zero
/* 9934B0 80240D80 0280282D */  daddu     $a1, $s4, $zero
/* 9934B4 80240D84 0C09015A */  jal       isk_14_UnkNpcAIFunc1
/* 9934B8 80240D88 0200302D */   daddu    $a2, $s0, $zero
/* 9934BC 80240D8C 8E630070 */  lw        $v1, 0x70($s3)
/* 9934C0 80240D90 24020003 */  addiu     $v0, $zero, 3
/* 9934C4 80240D94 14620016 */  bne       $v1, $v0, .L80240DF0
/* 9934C8 80240D98 0000102D */   daddu    $v0, $zero, $zero
glabel L80240D9C_9934CC
/* 9934CC 80240D9C 0260202D */  daddu     $a0, $s3, $zero
/* 9934D0 80240DA0 0280282D */  daddu     $a1, $s4, $zero
/* 9934D4 80240DA4 0C09018A */  jal       func_80240628_992D58
/* 9934D8 80240DA8 0200302D */   daddu    $a2, $s0, $zero
/* 9934DC 80240DAC 0809037C */  j         .L80240DF0
/* 9934E0 80240DB0 0000102D */   daddu    $v0, $zero, $zero
glabel L80240DB4_9934E4
/* 9934E4 80240DB4 0260202D */  daddu     $a0, $s3, $zero
/* 9934E8 80240DB8 0280282D */  daddu     $a1, $s4, $zero
/* 9934EC 80240DBC 0C0901F3 */  jal       isk_14_UnkNpcAIFunc15
/* 9934F0 80240DC0 0200302D */   daddu    $a2, $s0, $zero
glabel L80240DC4_9934F4
/* 9934F4 80240DC4 0260202D */  daddu     $a0, $s3, $zero
/* 9934F8 80240DC8 0280282D */  daddu     $a1, $s4, $zero
/* 9934FC 80240DCC 0C09022B */  jal       func_802408AC_992FDC
/* 993500 80240DD0 0200302D */   daddu    $a2, $s0, $zero
/* 993504 80240DD4 0809037C */  j         .L80240DF0
/* 993508 80240DD8 0000102D */   daddu    $v0, $zero, $zero
glabel L80240DDC_99350C
/* 99350C 80240DDC 0260202D */  daddu     $a0, $s3, $zero
/* 993510 80240DE0 0280282D */  daddu     $a1, $s4, $zero
/* 993514 80240DE4 0C0902EB */  jal       isk_14_UnkDurationCheck
/* 993518 80240DE8 0200302D */   daddu    $a2, $s0, $zero
glabel L80240DEC_99351C
/* 99351C 80240DEC 0000102D */  daddu     $v0, $zero, $zero
.L80240DF0:
/* 993520 80240DF0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 993524 80240DF4 8FB50044 */  lw        $s5, 0x44($sp)
/* 993528 80240DF8 8FB40040 */  lw        $s4, 0x40($sp)
/* 99352C 80240DFC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 993530 80240E00 8FB20038 */  lw        $s2, 0x38($sp)
/* 993534 80240E04 8FB10034 */  lw        $s1, 0x34($sp)
/* 993538 80240E08 8FB00030 */  lw        $s0, 0x30($sp)
/* 99353C 80240E0C 03E00008 */  jr        $ra
/* 993540 80240E10 27BD0050 */   addiu    $sp, $sp, 0x50
