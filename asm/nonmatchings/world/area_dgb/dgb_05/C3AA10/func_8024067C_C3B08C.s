.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024067C_C3B08C
/* C3B08C 8024067C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3B090 80240680 AFB10014 */  sw        $s1, 0x14($sp)
/* C3B094 80240684 0080882D */  daddu     $s1, $a0, $zero
/* C3B098 80240688 AFBF0018 */  sw        $ra, 0x18($sp)
/* C3B09C 8024068C AFB00010 */  sw        $s0, 0x10($sp)
/* C3B0A0 80240690 8E300148 */  lw        $s0, 0x148($s1)
/* C3B0A4 80240694 0C00EABB */  jal       get_npc_unsafe
/* C3B0A8 80240698 86040008 */   lh       $a0, 8($s0)
/* C3B0AC 8024069C 0040202D */  daddu     $a0, $v0, $zero
/* C3B0B0 802406A0 8482008E */  lh        $v0, 0x8e($a0)
/* C3B0B4 802406A4 9483008E */  lhu       $v1, 0x8e($a0)
/* C3B0B8 802406A8 18400002 */  blez      $v0, .L802406B4
/* C3B0BC 802406AC 2462FFFF */   addiu    $v0, $v1, -1
/* C3B0C0 802406B0 A482008E */  sh        $v0, 0x8e($a0)
.L802406B4:
/* C3B0C4 802406B4 8482008E */  lh        $v0, 0x8e($a0)
/* C3B0C8 802406B8 24030001 */  addiu     $v1, $zero, 1
/* C3B0CC 802406BC 14430005 */  bne       $v0, $v1, .L802406D4
/* C3B0D0 802406C0 00000000 */   nop      
/* C3B0D4 802406C4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C3B0D8 802406C8 8C420030 */  lw        $v0, 0x30($v0)
/* C3B0DC 802406CC 080901BC */  j         .L802406F0
/* C3B0E0 802406D0 AC820028 */   sw       $v0, 0x28($a0)
.L802406D4:
/* C3B0E4 802406D4 1C400006 */  bgtz      $v0, .L802406F0
/* C3B0E8 802406D8 00000000 */   nop      
/* C3B0EC 802406DC 8E0200CC */  lw        $v0, 0xcc($s0)
/* C3B0F0 802406E0 8C420028 */  lw        $v0, 0x28($v0)
/* C3B0F4 802406E4 A480008E */  sh        $zero, 0x8e($a0)
/* C3B0F8 802406E8 AC820028 */  sw        $v0, 0x28($a0)
/* C3B0FC 802406EC AE230070 */  sw        $v1, 0x70($s1)
.L802406F0:
/* C3B100 802406F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C3B104 802406F4 8FB10014 */  lw        $s1, 0x14($sp)
/* C3B108 802406F8 8FB00010 */  lw        $s0, 0x10($sp)
/* C3B10C 802406FC 03E00008 */  jr        $ra
/* C3B110 80240700 27BD0020 */   addiu    $sp, $sp, 0x20
