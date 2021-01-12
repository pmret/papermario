.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241994_EA2294
/* EA2294 80241994 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA2298 80241998 AFB10014 */  sw        $s1, 0x14($sp)
/* EA229C 8024199C 0080882D */  daddu     $s1, $a0, $zero
/* EA22A0 802419A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA22A4 802419A4 AFB00010 */  sw        $s0, 0x10($sp)
/* EA22A8 802419A8 8E300148 */  lw        $s0, 0x148($s1)
/* EA22AC 802419AC 0C00F92F */  jal       func_8003E4BC
/* EA22B0 802419B0 86040008 */   lh       $a0, 8($s0)
/* EA22B4 802419B4 0040182D */  daddu     $v1, $v0, $zero
/* EA22B8 802419B8 9462008E */  lhu       $v0, 0x8e($v1)
/* EA22BC 802419BC 2442FFFF */  addiu     $v0, $v0, -1
/* EA22C0 802419C0 A462008E */  sh        $v0, 0x8e($v1)
/* EA22C4 802419C4 00021400 */  sll       $v0, $v0, 0x10
/* EA22C8 802419C8 14400005 */  bnez      $v0, .L802419E0
/* EA22CC 802419CC 00000000 */   nop      
/* EA22D0 802419D0 960200AA */  lhu       $v0, 0xaa($s0)
/* EA22D4 802419D4 A462008E */  sh        $v0, 0x8e($v1)
/* EA22D8 802419D8 2402000E */  addiu     $v0, $zero, 0xe
/* EA22DC 802419DC AE220070 */  sw        $v0, 0x70($s1)
.L802419E0:
/* EA22E0 802419E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA22E4 802419E4 8FB10014 */  lw        $s1, 0x14($sp)
/* EA22E8 802419E8 8FB00010 */  lw        $s0, 0x10($sp)
/* EA22EC 802419EC 03E00008 */  jr        $ra
/* EA22F0 802419F0 27BD0020 */   addiu    $sp, $sp, 0x20
