.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242100_C62E10
/* C62E10 80242100 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C62E14 80242104 AFB10034 */  sw        $s1, 0x34($sp)
/* C62E18 80242108 0080882D */  daddu     $s1, $a0, $zero
/* C62E1C 8024210C AFBF0038 */  sw        $ra, 0x38($sp)
/* C62E20 80242110 AFB00030 */  sw        $s0, 0x30($sp)
/* C62E24 80242114 8E300148 */  lw        $s0, 0x148($s1)
/* C62E28 80242118 0C00EABB */  jal       get_npc_unsafe
/* C62E2C 8024211C 86040008 */   lh       $a0, 8($s0)
/* C62E30 80242120 0040282D */  daddu     $a1, $v0, $zero
/* C62E34 80242124 94A2008E */  lhu       $v0, 0x8e($a1)
/* C62E38 80242128 24420001 */  addiu     $v0, $v0, 1
/* C62E3C 8024212C A4A2008E */  sh        $v0, 0x8e($a1)
/* C62E40 80242130 00021400 */  sll       $v0, $v0, 0x10
/* C62E44 80242134 8E0300A0 */  lw        $v1, 0xa0($s0)
/* C62E48 80242138 00021403 */  sra       $v0, $v0, 0x10
/* C62E4C 8024213C 14430004 */  bne       $v0, $v1, .L80242150
/* C62E50 80242140 00000000 */   nop      
/* C62E54 80242144 8E0200CC */  lw        $v0, 0xcc($s0)
/* C62E58 80242148 8C42002C */  lw        $v0, 0x2c($v0)
/* C62E5C 8024214C ACA20028 */  sw        $v0, 0x28($a1)
.L80242150:
/* C62E60 80242150 84A3008E */  lh        $v1, 0x8e($a1)
/* C62E64 80242154 8E0200A4 */  lw        $v0, 0xa4($s0)
/* C62E68 80242158 14620002 */  bne       $v1, $v0, .L80242164
/* C62E6C 8024215C 24020003 */   addiu    $v0, $zero, 3
/* C62E70 80242160 AE02006C */  sw        $v0, 0x6c($s0)
.L80242164:
/* C62E74 80242164 84A2008E */  lh        $v0, 0x8e($a1)
/* C62E78 80242168 8E03009C */  lw        $v1, 0x9c($s0)
/* C62E7C 8024216C 0043102A */  slt       $v0, $v0, $v1
/* C62E80 80242170 1440001E */  bnez      $v0, .L802421EC
/* C62E84 80242174 24020004 */   addiu    $v0, $zero, 4
/* C62E88 80242178 AE02006C */  sw        $v0, 0x6c($s0)
/* C62E8C 8024217C 24020008 */  addiu     $v0, $zero, 8
/* C62E90 80242180 24040003 */  addiu     $a0, $zero, 3
/* C62E94 80242184 A4A2008E */  sh        $v0, 0x8e($a1)
/* C62E98 80242188 8E0200CC */  lw        $v0, 0xcc($s0)
/* C62E9C 8024218C 84A300A8 */  lh        $v1, 0xa8($a1)
/* C62EA0 80242190 3C013F80 */  lui       $at, 0x3f80
/* C62EA4 80242194 44810000 */  mtc1      $at, $f0
/* C62EA8 80242198 3C014000 */  lui       $at, 0x4000
/* C62EAC 8024219C 44811000 */  mtc1      $at, $f2
/* C62EB0 802421A0 3C01C1A0 */  lui       $at, 0xc1a0
/* C62EB4 802421A4 44812000 */  mtc1      $at, $f4
/* C62EB8 802421A8 44833000 */  mtc1      $v1, $f6
/* C62EBC 802421AC 00000000 */  nop       
/* C62EC0 802421B0 468031A0 */  cvt.s.w   $f6, $f6
/* C62EC4 802421B4 8C420000 */  lw        $v0, ($v0)
/* C62EC8 802421B8 44073000 */  mfc1      $a3, $f6
/* C62ECC 802421BC 0000302D */  daddu     $a2, $zero, $zero
/* C62ED0 802421C0 ACA20028 */  sw        $v0, 0x28($a1)
/* C62ED4 802421C4 2402000A */  addiu     $v0, $zero, 0xa
/* C62ED8 802421C8 AFA2001C */  sw        $v0, 0x1c($sp)
/* C62EDC 802421CC 27A20028 */  addiu     $v0, $sp, 0x28
/* C62EE0 802421D0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C62EE4 802421D4 E7A20014 */  swc1      $f2, 0x14($sp)
/* C62EE8 802421D8 E7A40018 */  swc1      $f4, 0x18($sp)
/* C62EEC 802421DC 0C01BFA4 */  jal       fx_emote
/* C62EF0 802421E0 AFA20020 */   sw       $v0, 0x20($sp)
/* C62EF4 802421E4 2402000D */  addiu     $v0, $zero, 0xd
/* C62EF8 802421E8 AE220070 */  sw        $v0, 0x70($s1)
.L802421EC:
/* C62EFC 802421EC 8FBF0038 */  lw        $ra, 0x38($sp)
/* C62F00 802421F0 8FB10034 */  lw        $s1, 0x34($sp)
/* C62F04 802421F4 8FB00030 */  lw        $s0, 0x30($sp)
/* C62F08 802421F8 03E00008 */  jr        $ra
/* C62F0C 802421FC 27BD0040 */   addiu    $sp, $sp, 0x40
