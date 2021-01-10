.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405C0_CC13F0
/* CC13F0 802405C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CC13F4 802405C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* CC13F8 802405C8 10A00003 */  beqz      $a1, .L802405D8
/* CC13FC 802405CC 8C86000C */   lw       $a2, 0xc($a0)
/* CC1400 802405D0 3C018024 */  lui       $at, %hi(func_80241850_A2BA90)
/* CC1404 802405D4 AC201850 */  sw        $zero, %lo(func_80241850_A2BA90)($at)
.L802405D8:
/* CC1408 802405D8 3C038024 */  lui       $v1, %hi(func_80241850_A2BA90)
/* CC140C 802405DC 24631850 */  addiu     $v1, $v1, %lo(func_80241850_A2BA90)
/* CC1410 802405E0 8C620000 */  lw        $v0, ($v1)
/* CC1414 802405E4 54400003 */  bnel      $v0, $zero, .L802405F4
/* CC1418 802405E8 AC600000 */   sw       $zero, ($v1)
/* CC141C 802405EC 08090182 */  j         .L80240608
/* CC1420 802405F0 0000102D */   daddu    $v0, $zero, $zero
.L802405F4:
/* CC1424 802405F4 8CC50000 */  lw        $a1, ($a2)
/* CC1428 802405F8 3C068024 */  lui       $a2, %hi(D_80241854)
/* CC142C 802405FC 0C0B2026 */  jal       set_variable
/* CC1430 80240600 8CC61854 */   lw       $a2, %lo(D_80241854)($a2)
/* CC1434 80240604 24020002 */  addiu     $v0, $zero, 2
.L80240608:
/* CC1438 80240608 8FBF0010 */  lw        $ra, 0x10($sp)
/* CC143C 8024060C 03E00008 */  jr        $ra
/* CC1440 80240610 27BD0018 */   addiu    $sp, $sp, 0x18
