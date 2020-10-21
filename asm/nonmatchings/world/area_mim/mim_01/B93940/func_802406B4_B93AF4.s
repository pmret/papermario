.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406B4_B93AF4
/* B93AF4 802406B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B93AF8 802406B8 AFB10014 */  sw        $s1, 0x14($sp)
/* B93AFC 802406BC 0080882D */  daddu     $s1, $a0, $zero
/* B93B00 802406C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* B93B04 802406C4 AFB00010 */  sw        $s0, 0x10($sp)
/* B93B08 802406C8 8E300148 */  lw        $s0, 0x148($s1)
/* B93B0C 802406CC 0C00EABB */  jal       get_npc_unsafe
/* B93B10 802406D0 86040008 */   lh       $a0, 8($s0)
/* B93B14 802406D4 9443008E */  lhu       $v1, 0x8e($v0)
/* B93B18 802406D8 2463FFFF */  addiu     $v1, $v1, -1
/* B93B1C 802406DC A443008E */  sh        $v1, 0x8e($v0)
/* B93B20 802406E0 00031C00 */  sll       $v1, $v1, 0x10
/* B93B24 802406E4 1C600003 */  bgtz      $v1, .L802406F4
/* B93B28 802406E8 2402000C */   addiu    $v0, $zero, 0xc
/* B93B2C 802406EC AE00006C */  sw        $zero, 0x6c($s0)
/* B93B30 802406F0 AE220070 */  sw        $v0, 0x70($s1)
.L802406F4:
/* B93B34 802406F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B93B38 802406F8 8FB10014 */  lw        $s1, 0x14($sp)
/* B93B3C 802406FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B93B40 80240700 03E00008 */  jr        $ra
/* B93B44 80240704 27BD0020 */   addiu    $sp, $sp, 0x20
