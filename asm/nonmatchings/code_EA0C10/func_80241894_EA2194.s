.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241894_EA2194
/* EA2194 80241894 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* EA2198 80241898 AFB10034 */  sw        $s1, 0x34($sp)
/* EA219C 8024189C 0080882D */  daddu     $s1, $a0, $zero
/* EA21A0 802418A0 AFBF0038 */  sw        $ra, 0x38($sp)
/* EA21A4 802418A4 AFB00030 */  sw        $s0, 0x30($sp)
/* EA21A8 802418A8 8E300148 */  lw        $s0, 0x148($s1)
/* EA21AC 802418AC 0C00F92F */  jal       func_8003E4BC
/* EA21B0 802418B0 86040008 */   lh       $a0, 8($s0)
/* EA21B4 802418B4 0040282D */  daddu     $a1, $v0, $zero
/* EA21B8 802418B8 94A2008E */  lhu       $v0, 0x8e($a1)
/* EA21BC 802418BC 24420001 */  addiu     $v0, $v0, 1
/* EA21C0 802418C0 A4A2008E */  sh        $v0, 0x8e($a1)
/* EA21C4 802418C4 00021400 */  sll       $v0, $v0, 0x10
/* EA21C8 802418C8 8E0300A0 */  lw        $v1, 0xa0($s0)
/* EA21CC 802418CC 00021403 */  sra       $v0, $v0, 0x10
/* EA21D0 802418D0 14430004 */  bne       $v0, $v1, .L802418E4
/* EA21D4 802418D4 00000000 */   nop
/* EA21D8 802418D8 8E0200CC */  lw        $v0, 0xcc($s0)
/* EA21DC 802418DC 8C42002C */  lw        $v0, 0x2c($v0)
/* EA21E0 802418E0 ACA20028 */  sw        $v0, 0x28($a1)
.L802418E4:
/* EA21E4 802418E4 84A3008E */  lh        $v1, 0x8e($a1)
/* EA21E8 802418E8 8E0200A4 */  lw        $v0, 0xa4($s0)
/* EA21EC 802418EC 14620002 */  bne       $v1, $v0, .L802418F8
/* EA21F0 802418F0 24020003 */   addiu    $v0, $zero, 3
/* EA21F4 802418F4 AE02006C */  sw        $v0, 0x6c($s0)
.L802418F8:
/* EA21F8 802418F8 84A2008E */  lh        $v0, 0x8e($a1)
/* EA21FC 802418FC 8E03009C */  lw        $v1, 0x9c($s0)
/* EA2200 80241900 0043102A */  slt       $v0, $v0, $v1
/* EA2204 80241904 1440001E */  bnez      $v0, .L80241980
/* EA2208 80241908 24020004 */   addiu    $v0, $zero, 4
/* EA220C 8024190C AE02006C */  sw        $v0, 0x6c($s0)
/* EA2210 80241910 24020008 */  addiu     $v0, $zero, 8
/* EA2214 80241914 24040003 */  addiu     $a0, $zero, 3
/* EA2218 80241918 A4A2008E */  sh        $v0, 0x8e($a1)
/* EA221C 8024191C 8E0200CC */  lw        $v0, 0xcc($s0)
/* EA2220 80241920 84A300A8 */  lh        $v1, 0xa8($a1)
/* EA2224 80241924 3C013F80 */  lui       $at, 0x3f80
/* EA2228 80241928 44810000 */  mtc1      $at, $f0
/* EA222C 8024192C 3C014000 */  lui       $at, 0x4000
/* EA2230 80241930 44811000 */  mtc1      $at, $f2
/* EA2234 80241934 3C01C1A0 */  lui       $at, 0xc1a0
/* EA2238 80241938 44812000 */  mtc1      $at, $f4
/* EA223C 8024193C 44833000 */  mtc1      $v1, $f6
/* EA2240 80241940 00000000 */  nop
/* EA2244 80241944 468031A0 */  cvt.s.w   $f6, $f6
/* EA2248 80241948 8C420000 */  lw        $v0, ($v0)
/* EA224C 8024194C 44073000 */  mfc1      $a3, $f6
/* EA2250 80241950 0000302D */  daddu     $a2, $zero, $zero
/* EA2254 80241954 ACA20028 */  sw        $v0, 0x28($a1)
/* EA2258 80241958 2402000A */  addiu     $v0, $zero, 0xa
/* EA225C 8024195C AFA2001C */  sw        $v0, 0x1c($sp)
/* EA2260 80241960 27A20028 */  addiu     $v0, $sp, 0x28
/* EA2264 80241964 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA2268 80241968 E7A20014 */  swc1      $f2, 0x14($sp)
/* EA226C 8024196C E7A40018 */  swc1      $f4, 0x18($sp)
/* EA2270 80241970 0C01D444 */  jal       func_80075110
/* EA2274 80241974 AFA20020 */   sw       $v0, 0x20($sp)
/* EA2278 80241978 2402000D */  addiu     $v0, $zero, 0xd
/* EA227C 8024197C AE220070 */  sw        $v0, 0x70($s1)
.L80241980:
/* EA2280 80241980 8FBF0038 */  lw        $ra, 0x38($sp)
/* EA2284 80241984 8FB10034 */  lw        $s1, 0x34($sp)
/* EA2288 80241988 8FB00030 */  lw        $s0, 0x30($sp)
/* EA228C 8024198C 03E00008 */  jr        $ra
/* EA2290 80241990 27BD0040 */   addiu    $sp, $sp, 0x40
