.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414C8_C621D8
/* C621D8 802414C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C621DC 802414CC AFB10014 */  sw        $s1, 0x14($sp)
/* C621E0 802414D0 0080882D */  daddu     $s1, $a0, $zero
/* C621E4 802414D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C621E8 802414D8 AFB00010 */  sw        $s0, 0x10($sp)
/* C621EC 802414DC 8E300148 */  lw        $s0, 0x148($s1)
/* C621F0 802414E0 0C00EABB */  jal       get_npc_unsafe
/* C621F4 802414E4 86040008 */   lh       $a0, 8($s0)
/* C621F8 802414E8 0040202D */  daddu     $a0, $v0, $zero
/* C621FC 802414EC 8482008E */  lh        $v0, 0x8e($a0)
/* C62200 802414F0 9483008E */  lhu       $v1, 0x8e($a0)
/* C62204 802414F4 18400003 */  blez      $v0, .L80241504
/* C62208 802414F8 2462FFFF */   addiu    $v0, $v1, -1
/* C6220C 802414FC 08090548 */  j         .L80241520
/* C62210 80241500 A482008E */   sh       $v0, 0x8e($a0)
.L80241504:
/* C62214 80241504 8E0200CC */  lw        $v0, 0xcc($s0)
/* C62218 80241508 AE00006C */  sw        $zero, 0x6c($s0)
/* C6221C 8024150C 8C420000 */  lw        $v0, ($v0)
/* C62220 80241510 AC820028 */  sw        $v0, 0x28($a0)
/* C62224 80241514 24020001 */  addiu     $v0, $zero, 1
/* C62228 80241518 AE200074 */  sw        $zero, 0x74($s1)
/* C6222C 8024151C AE220070 */  sw        $v0, 0x70($s1)
.L80241520:
/* C62230 80241520 8FBF0018 */  lw        $ra, 0x18($sp)
/* C62234 80241524 8FB10014 */  lw        $s1, 0x14($sp)
/* C62238 80241528 8FB00010 */  lw        $s0, 0x10($sp)
/* C6223C 8024152C 03E00008 */  jr        $ra
/* C62240 80241530 27BD0020 */   addiu    $sp, $sp, 0x20
