.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241578_BA1CA8
/* BA1CA8 80241578 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BA1CAC 8024157C AFB10034 */  sw        $s1, 0x34($sp)
/* BA1CB0 80241580 0080882D */  daddu     $s1, $a0, $zero
/* BA1CB4 80241584 AFBF0038 */  sw        $ra, 0x38($sp)
/* BA1CB8 80241588 AFB00030 */  sw        $s0, 0x30($sp)
/* BA1CBC 8024158C 8E300148 */  lw        $s0, 0x148($s1)
/* BA1CC0 80241590 0C00EABB */  jal       get_npc_unsafe
/* BA1CC4 80241594 86040008 */   lh       $a0, 8($s0)
/* BA1CC8 80241598 0040282D */  daddu     $a1, $v0, $zero
/* BA1CCC 8024159C 94A2008E */  lhu       $v0, 0x8e($a1)
/* BA1CD0 802415A0 24420001 */  addiu     $v0, $v0, 1
/* BA1CD4 802415A4 A4A2008E */  sh        $v0, 0x8e($a1)
/* BA1CD8 802415A8 00021400 */  sll       $v0, $v0, 0x10
/* BA1CDC 802415AC 8E0300A0 */  lw        $v1, 0xa0($s0)
/* BA1CE0 802415B0 00021403 */  sra       $v0, $v0, 0x10
/* BA1CE4 802415B4 14430004 */  bne       $v0, $v1, .L802415C8
/* BA1CE8 802415B8 00000000 */   nop      
/* BA1CEC 802415BC 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA1CF0 802415C0 8C42002C */  lw        $v0, 0x2c($v0)
/* BA1CF4 802415C4 ACA20028 */  sw        $v0, 0x28($a1)
.L802415C8:
/* BA1CF8 802415C8 84A3008E */  lh        $v1, 0x8e($a1)
/* BA1CFC 802415CC 8E0200A4 */  lw        $v0, 0xa4($s0)
/* BA1D00 802415D0 14620002 */  bne       $v1, $v0, .L802415DC
/* BA1D04 802415D4 24020003 */   addiu    $v0, $zero, 3
/* BA1D08 802415D8 AE02006C */  sw        $v0, 0x6c($s0)
.L802415DC:
/* BA1D0C 802415DC 84A2008E */  lh        $v0, 0x8e($a1)
/* BA1D10 802415E0 8E03009C */  lw        $v1, 0x9c($s0)
/* BA1D14 802415E4 0043102A */  slt       $v0, $v0, $v1
/* BA1D18 802415E8 1440001E */  bnez      $v0, .L80241664
/* BA1D1C 802415EC 24020004 */   addiu    $v0, $zero, 4
/* BA1D20 802415F0 AE02006C */  sw        $v0, 0x6c($s0)
/* BA1D24 802415F4 24020008 */  addiu     $v0, $zero, 8
/* BA1D28 802415F8 24040003 */  addiu     $a0, $zero, 3
/* BA1D2C 802415FC A4A2008E */  sh        $v0, 0x8e($a1)
/* BA1D30 80241600 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA1D34 80241604 84A300A8 */  lh        $v1, 0xa8($a1)
/* BA1D38 80241608 3C013F80 */  lui       $at, 0x3f80
/* BA1D3C 8024160C 44810000 */  mtc1      $at, $f0
/* BA1D40 80241610 3C014000 */  lui       $at, 0x4000
/* BA1D44 80241614 44811000 */  mtc1      $at, $f2
/* BA1D48 80241618 3C01C1A0 */  lui       $at, 0xc1a0
/* BA1D4C 8024161C 44812000 */  mtc1      $at, $f4
/* BA1D50 80241620 44833000 */  mtc1      $v1, $f6
/* BA1D54 80241624 00000000 */  nop       
/* BA1D58 80241628 468031A0 */  cvt.s.w   $f6, $f6
/* BA1D5C 8024162C 8C420000 */  lw        $v0, ($v0)
/* BA1D60 80241630 44073000 */  mfc1      $a3, $f6
/* BA1D64 80241634 0000302D */  daddu     $a2, $zero, $zero
/* BA1D68 80241638 ACA20028 */  sw        $v0, 0x28($a1)
/* BA1D6C 8024163C 2402000A */  addiu     $v0, $zero, 0xa
/* BA1D70 80241640 AFA2001C */  sw        $v0, 0x1c($sp)
/* BA1D74 80241644 27A20028 */  addiu     $v0, $sp, 0x28
/* BA1D78 80241648 E7A00010 */  swc1      $f0, 0x10($sp)
/* BA1D7C 8024164C E7A20014 */  swc1      $f2, 0x14($sp)
/* BA1D80 80241650 E7A40018 */  swc1      $f4, 0x18($sp)
/* BA1D84 80241654 0C01BFA4 */  jal       fx_emote
/* BA1D88 80241658 AFA20020 */   sw       $v0, 0x20($sp)
/* BA1D8C 8024165C 2402000D */  addiu     $v0, $zero, 0xd
/* BA1D90 80241660 AE220070 */  sw        $v0, 0x70($s1)
.L80241664:
/* BA1D94 80241664 8FBF0038 */  lw        $ra, 0x38($sp)
/* BA1D98 80241668 8FB10034 */  lw        $s1, 0x34($sp)
/* BA1D9C 8024166C 8FB00030 */  lw        $s0, 0x30($sp)
/* BA1DA0 80241670 03E00008 */  jr        $ra
/* BA1DA4 80241674 27BD0040 */   addiu    $sp, $sp, 0x40
