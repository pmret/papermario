.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EBA3C
/* 84EEC 800EBA3C 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 84EF0 800EBA40 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 84EF4 800EBA44 8CA20000 */  lw        $v0, ($a1)
/* 84EF8 800EBA48 30420006 */  andi      $v0, $v0, 6
/* 84EFC 800EBA4C 10400005 */  beqz      $v0, .L800EBA64
/* 84F00 800EBA50 0000302D */   daddu    $a2, $zero, $zero
/* 84F04 800EBA54 90A200B4 */  lbu       $v0, 0xb4($a1)
/* 84F08 800EBA58 2442FFF7 */  addiu     $v0, $v0, -9
/* 84F0C 800EBA5C 2C420002 */  sltiu     $v0, $v0, 2
/* 84F10 800EBA60 38460001 */  xori      $a2, $v0, 1
.L800EBA64:
/* 84F14 800EBA64 3C028011 */  lui       $v0, 0x8011
/* 84F18 800EBA68 8C42CFB8 */  lw        $v0, -0x3048($v0)
/* 84F1C 800EBA6C 3C038011 */  lui       $v1, 0x8011
/* 84F20 800EBA70 2463CD38 */  addiu     $v1, $v1, -0x32c8
/* 84F24 800EBA74 00021100 */  sll       $v0, $v0, 4
/* 84F28 800EBA78 00431821 */  addu      $v1, $v0, $v1
/* 84F2C 800EBA7C 80620000 */  lb        $v0, ($v1)
/* 84F30 800EBA80 10400003 */  beqz      $v0, .L800EBA90
/* 84F34 800EBA84 00000000 */   nop      
/* 84F38 800EBA88 14C0002B */  bnez      $a2, .L800EBB38
/* 84F3C 800EBA8C 00000000 */   nop      
.L800EBA90:
/* 84F40 800EBA90 C4620004 */  lwc1      $f2, 4($v1)
/* 84F44 800EBA94 C4A00028 */  lwc1      $f0, 0x28($a1)
/* 84F48 800EBA98 46001032 */  c.eq.s    $f2, $f0
/* 84F4C 800EBA9C 00000000 */  nop       
/* 84F50 800EBAA0 4500000D */  bc1f      .L800EBAD8
/* 84F54 800EBAA4 00000000 */   nop      
/* 84F58 800EBAA8 C4620008 */  lwc1      $f2, 8($v1)
/* 84F5C 800EBAAC C4A0002C */  lwc1      $f0, 0x2c($a1)
/* 84F60 800EBAB0 46001032 */  c.eq.s    $f2, $f0
/* 84F64 800EBAB4 00000000 */  nop       
/* 84F68 800EBAB8 45000007 */  bc1f      .L800EBAD8
/* 84F6C 800EBABC 00000000 */   nop      
/* 84F70 800EBAC0 C462000C */  lwc1      $f2, 0xc($v1)
/* 84F74 800EBAC4 C4A00030 */  lwc1      $f0, 0x30($a1)
/* 84F78 800EBAC8 46001032 */  c.eq.s    $f2, $f0
/* 84F7C 800EBACC 00000000 */  nop       
/* 84F80 800EBAD0 45010019 */  bc1t      .L800EBB38
/* 84F84 800EBAD4 00000000 */   nop      
.L800EBAD8:
/* 84F88 800EBAD8 3C048011 */  lui       $a0, 0x8011
/* 84F8C 800EBADC 2484CFB8 */  addiu     $a0, $a0, -0x3048
/* 84F90 800EBAE0 8C820000 */  lw        $v0, ($a0)
/* 84F94 800EBAE4 3C038011 */  lui       $v1, 0x8011
/* 84F98 800EBAE8 8C63CFBC */  lw        $v1, -0x3044($v1)
/* 84F9C 800EBAEC 24420001 */  addiu     $v0, $v0, 1
/* 84FA0 800EBAF0 10620011 */  beq       $v1, $v0, .L800EBB38
/* 84FA4 800EBAF4 00000000 */   nop      
/* 84FA8 800EBAF8 AC820000 */  sw        $v0, ($a0)
/* 84FAC 800EBAFC 28420028 */  slti      $v0, $v0, 0x28
/* 84FB0 800EBB00 50400001 */  beql      $v0, $zero, .L800EBB08
/* 84FB4 800EBB04 AC800000 */   sw       $zero, ($a0)
.L800EBB08:
/* 84FB8 800EBB08 3C038011 */  lui       $v1, 0x8011
/* 84FBC 800EBB0C 2463CD38 */  addiu     $v1, $v1, -0x32c8
/* 84FC0 800EBB10 8C820000 */  lw        $v0, ($a0)
/* 84FC4 800EBB14 C4A00028 */  lwc1      $f0, 0x28($a1)
/* 84FC8 800EBB18 00021100 */  sll       $v0, $v0, 4
/* 84FCC 800EBB1C 00431821 */  addu      $v1, $v0, $v1
/* 84FD0 800EBB20 E4600004 */  swc1      $f0, 4($v1)
/* 84FD4 800EBB24 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* 84FD8 800EBB28 E4600008 */  swc1      $f0, 8($v1)
/* 84FDC 800EBB2C C4A00030 */  lwc1      $f0, 0x30($a1)
/* 84FE0 800EBB30 A0660000 */  sb        $a2, ($v1)
/* 84FE4 800EBB34 E460000C */  swc1      $f0, 0xc($v1)
.L800EBB38:
/* 84FE8 800EBB38 03E00008 */  jr        $ra
/* 84FEC 800EBB3C 00000000 */   nop      
