.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435F0_C7A2D0
/* C7A2D0 802435F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7A2D4 802435F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C7A2D8 802435F8 10A00003 */  beqz      $a1, .L80243608
/* C7A2DC 802435FC 8C86000C */   lw       $a2, 0xc($a0)
/* C7A2E0 80243600 3C018024 */  lui       $at, 0x8024
/* C7A2E4 80243604 AC2052B4 */  sw        $zero, 0x52b4($at)
.L80243608:
/* C7A2E8 80243608 3C038024 */  lui       $v1, 0x8024
/* C7A2EC 8024360C 246352B4 */  addiu     $v1, $v1, 0x52b4
/* C7A2F0 80243610 8C620000 */  lw        $v0, ($v1)
/* C7A2F4 80243614 54400003 */  bnel      $v0, $zero, .L80243624
/* C7A2F8 80243618 AC600000 */   sw       $zero, ($v1)
/* C7A2FC 8024361C 08090D8E */  j         .L80243638
/* C7A300 80243620 0000102D */   daddu    $v0, $zero, $zero
.L80243624:
/* C7A304 80243624 8CC50000 */  lw        $a1, ($a2)
/* C7A308 80243628 3C068024 */  lui       $a2, 0x8024
/* C7A30C 8024362C 0C0B2026 */  jal       set_variable
/* C7A310 80243630 8CC652B8 */   lw       $a2, 0x52b8($a2)
/* C7A314 80243634 24020002 */  addiu     $v0, $zero, 2
.L80243638:
/* C7A318 80243638 8FBF0010 */  lw        $ra, 0x10($sp)
/* C7A31C 8024363C 03E00008 */  jr        $ra
/* C7A320 80243640 27BD0018 */   addiu    $sp, $sp, 0x18
