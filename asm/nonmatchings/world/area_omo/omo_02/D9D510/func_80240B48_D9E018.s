.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B48_D9E018
/* D9E018 80240B48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D9E01C 80240B4C AFB10014 */  sw        $s1, 0x14($sp)
/* D9E020 80240B50 0080882D */  daddu     $s1, $a0, $zero
/* D9E024 80240B54 AFBF0018 */  sw        $ra, 0x18($sp)
/* D9E028 80240B58 AFB00010 */  sw        $s0, 0x10($sp)
/* D9E02C 80240B5C 8E300148 */  lw        $s0, 0x148($s1)
/* D9E030 80240B60 0C00EABB */  jal       get_npc_unsafe
/* D9E034 80240B64 86040008 */   lh       $a0, 8($s0)
/* D9E038 80240B68 0040182D */  daddu     $v1, $v0, $zero
/* D9E03C 80240B6C 9462008E */  lhu       $v0, 0x8e($v1)
/* D9E040 80240B70 2442FFFF */  addiu     $v0, $v0, -1
/* D9E044 80240B74 A462008E */  sh        $v0, 0x8e($v1)
/* D9E048 80240B78 00021400 */  sll       $v0, $v0, 0x10
/* D9E04C 80240B7C 14400005 */  bnez      $v0, .L80240B94
/* D9E050 80240B80 00000000 */   nop
/* D9E054 80240B84 8E0200CC */  lw        $v0, 0xcc($s0)
/* D9E058 80240B88 8C420000 */  lw        $v0, ($v0)
/* D9E05C 80240B8C AC620028 */  sw        $v0, 0x28($v1)
/* D9E060 80240B90 AE200070 */  sw        $zero, 0x70($s1)
.L80240B94:
/* D9E064 80240B94 8FBF0018 */  lw        $ra, 0x18($sp)
/* D9E068 80240B98 8FB10014 */  lw        $s1, 0x14($sp)
/* D9E06C 80240B9C 8FB00010 */  lw        $s0, 0x10($sp)
/* D9E070 80240BA0 03E00008 */  jr        $ra
/* D9E074 80240BA4 27BD0020 */   addiu    $sp, $sp, 0x20
