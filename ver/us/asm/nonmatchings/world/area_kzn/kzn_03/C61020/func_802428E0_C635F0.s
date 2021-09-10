.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428E0_C635F0
/* C635F0 802428E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C635F4 802428E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C635F8 802428E8 10A00003 */  beqz      $a1, .L802428F8
/* C635FC 802428EC 8C86000C */   lw       $a2, 0xc($a0)
/* C63600 802428F0 3C018024 */  lui       $at, %hi(D_80244204_C64F14)
/* C63604 802428F4 AC204204 */  sw        $zero, %lo(D_80244204_C64F14)($at)
.L802428F8:
/* C63608 802428F8 3C038024 */  lui       $v1, %hi(D_80244204_C64F14)
/* C6360C 802428FC 24634204 */  addiu     $v1, $v1, %lo(D_80244204_C64F14)
/* C63610 80242900 8C620000 */  lw        $v0, ($v1)
/* C63614 80242904 54400003 */  bnel      $v0, $zero, .L80242914
/* C63618 80242908 AC600000 */   sw       $zero, ($v1)
/* C6361C 8024290C 08090A4A */  j         .L80242928
/* C63620 80242910 0000102D */   daddu    $v0, $zero, $zero
.L80242914:
/* C63624 80242914 8CC50000 */  lw        $a1, ($a2)
/* C63628 80242918 3C068024 */  lui       $a2, %hi(D_80244208_C64F18)
/* C6362C 8024291C 0C0B2026 */  jal       evt_set_variable
/* C63630 80242920 8CC64208 */   lw       $a2, %lo(D_80244208_C64F18)($a2)
/* C63634 80242924 24020002 */  addiu     $v0, $zero, 2
.L80242928:
/* C63638 80242928 8FBF0010 */  lw        $ra, 0x10($sp)
/* C6363C 8024292C 03E00008 */  jr        $ra
/* C63640 80242930 27BD0018 */   addiu    $sp, $sp, 0x18
