.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* B59AF0 80240280 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B59AF4 80240284 AFB10014 */  sw        $s1, 0x14($sp)
/* B59AF8 80240288 0080882D */  daddu     $s1, $a0, $zero
/* B59AFC 8024028C AFBF0018 */  sw        $ra, 0x18($sp)
/* B59B00 80240290 AFB00010 */  sw        $s0, 0x10($sp)
/* B59B04 80240294 8E300148 */  lw        $s0, 0x148($s1)
/* B59B08 80240298 0C00EABB */  jal       get_npc_unsafe
/* B59B0C 8024029C 86040008 */   lh       $a0, 8($s0)
/* B59B10 802402A0 0040202D */  daddu     $a0, $v0, $zero
/* B59B14 802402A4 9482008E */  lhu       $v0, 0x8e($a0)
/* B59B18 802402A8 2442FFFF */  addiu     $v0, $v0, -1
/* B59B1C 802402AC A482008E */  sh        $v0, 0x8e($a0)
/* B59B20 802402B0 00021400 */  sll       $v0, $v0, 0x10
/* B59B24 802402B4 1C400009 */  bgtz      $v0, .L802402DC
/* B59B28 802402B8 24020003 */   addiu    $v0, $zero, 3
/* B59B2C 802402BC 96030076 */  lhu       $v1, 0x76($s0)
/* B59B30 802402C0 AE02006C */  sw        $v0, 0x6c($s0)
/* B59B34 802402C4 A483008E */  sh        $v1, 0x8e($a0)
/* B59B38 802402C8 8E0200CC */  lw        $v0, 0xcc($s0)
/* B59B3C 802402CC 8C420024 */  lw        $v0, 0x24($v0)
/* B59B40 802402D0 AC820028 */  sw        $v0, 0x28($a0)
/* B59B44 802402D4 24020020 */  addiu     $v0, $zero, 0x20
/* B59B48 802402D8 AE220070 */  sw        $v0, 0x70($s1)
.L802402DC:
/* B59B4C 802402DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* B59B50 802402E0 8FB10014 */  lw        $s1, 0x14($sp)
/* B59B54 802402E4 8FB00010 */  lw        $s0, 0x10($sp)
/* B59B58 802402E8 03E00008 */  jr        $ra
/* B59B5C 802402EC 27BD0020 */   addiu    $sp, $sp, 0x20
