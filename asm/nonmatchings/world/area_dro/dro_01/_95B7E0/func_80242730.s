.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242730
/* 95D930 80242730 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D934 80242734 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D938 80242738 10A00003 */  beqz      $a1, .L80242748
/* 95D93C 8024273C 8C86000C */   lw       $a2, 0xc($a0)
/* 95D940 80242740 3C018024 */  lui       $at, 0x8024
/* 95D944 80242744 AC2077E0 */  sw        $zero, 0x77e0($at)
.L80242748:
/* 95D948 80242748 3C038024 */  lui       $v1, 0x8024
/* 95D94C 8024274C 246377E0 */  addiu     $v1, $v1, 0x77e0
/* 95D950 80242750 8C620000 */  lw        $v0, ($v1)
/* 95D954 80242754 54400003 */  bnel      $v0, $zero, .L80242764
/* 95D958 80242758 AC600000 */   sw       $zero, ($v1)
/* 95D95C 8024275C 080909DE */  j         .L80242778
/* 95D960 80242760 0000102D */   daddu    $v0, $zero, $zero
.L80242764:
/* 95D964 80242764 8CC50000 */  lw        $a1, ($a2)
/* 95D968 80242768 3C068024 */  lui       $a2, 0x8024
/* 95D96C 8024276C 0C0B2026 */  jal       set_variable
/* 95D970 80242770 8CC677E4 */   lw       $a2, 0x77e4($a2)
/* 95D974 80242774 24020002 */  addiu     $v0, $zero, 2
.L80242778:
/* 95D978 80242778 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D97C 8024277C 03E00008 */  jr        $ra
/* 95D980 80242780 27BD0018 */   addiu    $sp, $sp, 0x18
