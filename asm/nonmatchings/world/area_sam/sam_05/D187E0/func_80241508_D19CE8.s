.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241508_D19CE8
/* D19CE8 80241508 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D19CEC 8024150C AFB10034 */  sw        $s1, 0x34($sp)
/* D19CF0 80241510 0080882D */  daddu     $s1, $a0, $zero
/* D19CF4 80241514 AFBF0038 */  sw        $ra, 0x38($sp)
/* D19CF8 80241518 AFB00030 */  sw        $s0, 0x30($sp)
/* D19CFC 8024151C 8E300148 */  lw        $s0, 0x148($s1)
/* D19D00 80241520 0C00EABB */  jal       get_npc_unsafe
/* D19D04 80241524 86040008 */   lh       $a0, 8($s0)
/* D19D08 80241528 0040282D */  daddu     $a1, $v0, $zero
/* D19D0C 8024152C 94A2008E */  lhu       $v0, 0x8e($a1)
/* D19D10 80241530 24420001 */  addiu     $v0, $v0, 1
/* D19D14 80241534 A4A2008E */  sh        $v0, 0x8e($a1)
/* D19D18 80241538 00021400 */  sll       $v0, $v0, 0x10
/* D19D1C 8024153C 8E0300A0 */  lw        $v1, 0xa0($s0)
/* D19D20 80241540 00021403 */  sra       $v0, $v0, 0x10
/* D19D24 80241544 14430004 */  bne       $v0, $v1, .L80241558
/* D19D28 80241548 00000000 */   nop      
/* D19D2C 8024154C 8E0200CC */  lw        $v0, 0xcc($s0)
/* D19D30 80241550 8C42002C */  lw        $v0, 0x2c($v0)
/* D19D34 80241554 ACA20028 */  sw        $v0, 0x28($a1)
.L80241558:
/* D19D38 80241558 84A3008E */  lh        $v1, 0x8e($a1)
/* D19D3C 8024155C 8E0200A4 */  lw        $v0, 0xa4($s0)
/* D19D40 80241560 14620002 */  bne       $v1, $v0, .L8024156C
/* D19D44 80241564 24020003 */   addiu    $v0, $zero, 3
/* D19D48 80241568 AE02006C */  sw        $v0, 0x6c($s0)
.L8024156C:
/* D19D4C 8024156C 84A2008E */  lh        $v0, 0x8e($a1)
/* D19D50 80241570 8E03009C */  lw        $v1, 0x9c($s0)
/* D19D54 80241574 0043102A */  slt       $v0, $v0, $v1
/* D19D58 80241578 1440001E */  bnez      $v0, .L802415F4
/* D19D5C 8024157C 24020004 */   addiu    $v0, $zero, 4
/* D19D60 80241580 AE02006C */  sw        $v0, 0x6c($s0)
/* D19D64 80241584 24020008 */  addiu     $v0, $zero, 8
/* D19D68 80241588 24040003 */  addiu     $a0, $zero, 3
/* D19D6C 8024158C A4A2008E */  sh        $v0, 0x8e($a1)
/* D19D70 80241590 8E0200CC */  lw        $v0, 0xcc($s0)
/* D19D74 80241594 84A300A8 */  lh        $v1, 0xa8($a1)
/* D19D78 80241598 3C013F80 */  lui       $at, 0x3f80
/* D19D7C 8024159C 44810000 */  mtc1      $at, $f0
/* D19D80 802415A0 3C014000 */  lui       $at, 0x4000
/* D19D84 802415A4 44811000 */  mtc1      $at, $f2
/* D19D88 802415A8 3C01C1A0 */  lui       $at, 0xc1a0
/* D19D8C 802415AC 44812000 */  mtc1      $at, $f4
/* D19D90 802415B0 44833000 */  mtc1      $v1, $f6
/* D19D94 802415B4 00000000 */  nop       
/* D19D98 802415B8 468031A0 */  cvt.s.w   $f6, $f6
/* D19D9C 802415BC 8C420000 */  lw        $v0, ($v0)
/* D19DA0 802415C0 44073000 */  mfc1      $a3, $f6
/* D19DA4 802415C4 0000302D */  daddu     $a2, $zero, $zero
/* D19DA8 802415C8 ACA20028 */  sw        $v0, 0x28($a1)
/* D19DAC 802415CC 2402000A */  addiu     $v0, $zero, 0xa
/* D19DB0 802415D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* D19DB4 802415D4 27A20028 */  addiu     $v0, $sp, 0x28
/* D19DB8 802415D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* D19DBC 802415DC E7A20014 */  swc1      $f2, 0x14($sp)
/* D19DC0 802415E0 E7A40018 */  swc1      $f4, 0x18($sp)
/* D19DC4 802415E4 0C01BFA4 */  jal       fx_emote
/* D19DC8 802415E8 AFA20020 */   sw       $v0, 0x20($sp)
/* D19DCC 802415EC 2402000D */  addiu     $v0, $zero, 0xd
/* D19DD0 802415F0 AE220070 */  sw        $v0, 0x70($s1)
.L802415F4:
/* D19DD4 802415F4 8FBF0038 */  lw        $ra, 0x38($sp)
/* D19DD8 802415F8 8FB10034 */  lw        $s1, 0x34($sp)
/* D19DDC 802415FC 8FB00030 */  lw        $s0, 0x30($sp)
/* D19DE0 80241600 03E00008 */  jr        $ra
/* D19DE4 80241604 27BD0040 */   addiu    $sp, $sp, 0x40
