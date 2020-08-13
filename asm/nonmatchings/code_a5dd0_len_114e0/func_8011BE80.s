.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8011BE80
/* 0B2580 8011BE80 3C028015 */  lui   $v0, 0x8015
/* 0B2584 8011BE84 9042B74D */  lbu   $v0, -0x48b3($v0)
/* 0B2588 8011BE88 A0820000 */  sb    $v0, ($a0)
/* 0B258C 8011BE8C 3C028015 */  lui   $v0, 0x8015
/* 0B2590 8011BE90 9042B74E */  lbu   $v0, -0x48b2($v0)
/* 0B2594 8011BE94 A0A20000 */  sb    $v0, ($a1)
/* 0B2598 8011BE98 3C028015 */  lui   $v0, 0x8015
/* 0B259C 8011BE9C 9042B74F */  lbu   $v0, -0x48b1($v0)
/* 0B25A0 8011BEA0 A0C20000 */  sb    $v0, ($a2)
/* 0B25A4 8011BEA4 3C028015 */  lui   $v0, 0x8015
/* 0B25A8 8011BEA8 9042B74C */  lbu   $v0, -0x48b4($v0)
/* 0B25AC 8011BEAC 03E00008 */  jr    $ra
/* 0B25B0 8011BEB0 A0E20000 */   sb    $v0, ($a3)

/* 0B25B4 8011BEB4 8FA20010 */  lw    $v0, 0x10($sp)
/* 0B25B8 8011BEB8 8FA30014 */  lw    $v1, 0x14($sp)
/* 0B25BC 8011BEBC 8FA80018 */  lw    $t0, 0x18($sp)
/* 0B25C0 8011BEC0 8FA9001C */  lw    $t1, 0x1c($sp)
/* 0B25C4 8011BEC4 8FAA0020 */  lw    $t2, 0x20($sp)
/* 0B25C8 8011BEC8 3C018015 */  lui   $at, 0x8015
/* 0B25CC 8011BECC A024B750 */  sb    $a0, -0x48b0($at)
/* 0B25D0 8011BED0 3C018015 */  lui   $at, 0x8015
/* 0B25D4 8011BED4 A025B751 */  sb    $a1, -0x48af($at)
/* 0B25D8 8011BED8 3C018015 */  lui   $at, 0x8015
/* 0B25DC 8011BEDC A026B752 */  sb    $a2, -0x48ae($at)
/* 0B25E0 8011BEE0 3C018015 */  lui   $at, 0x8015
/* 0B25E4 8011BEE4 A027B753 */  sb    $a3, -0x48ad($at)
/* 0B25E8 8011BEE8 3C018015 */  lui   $at, 0x8015
/* 0B25EC 8011BEEC A022B754 */  sb    $v0, -0x48ac($at)
/* 0B25F0 8011BEF0 3C018015 */  lui   $at, 0x8015
/* 0B25F4 8011BEF4 A023B755 */  sb    $v1, -0x48ab($at)
/* 0B25F8 8011BEF8 3C018015 */  lui   $at, 0x8015
/* 0B25FC 8011BEFC A028B756 */  sb    $t0, -0x48aa($at)
/* 0B2600 8011BF00 3C018015 */  lui   $at, 0x8015
/* 0B2604 8011BF04 AC29B758 */  sw    $t1, -0x48a8($at)
/* 0B2608 8011BF08 3C018015 */  lui   $at, 0x8015
/* 0B260C 8011BF0C 03E00008 */  jr    $ra
/* 0B2610 8011BF10 AC2AB75C */   sw    $t2, -0x48a4($at)

/* 0B2614 8011BF14 3C028015 */  lui   $v0, 0x8015
/* 0B2618 8011BF18 9042B750 */  lbu   $v0, -0x48b0($v0)
/* 0B261C 8011BF1C 8FA30010 */  lw    $v1, 0x10($sp)
/* 0B2620 8011BF20 8FA80014 */  lw    $t0, 0x14($sp)
/* 0B2624 8011BF24 8FA90018 */  lw    $t1, 0x18($sp)
/* 0B2628 8011BF28 8FAA001C */  lw    $t2, 0x1c($sp)
/* 0B262C 8011BF2C 8FAB0020 */  lw    $t3, 0x20($sp)
/* 0B2630 8011BF30 A0820000 */  sb    $v0, ($a0)
/* 0B2634 8011BF34 3C028015 */  lui   $v0, 0x8015
/* 0B2638 8011BF38 9042B751 */  lbu   $v0, -0x48af($v0)
/* 0B263C 8011BF3C A0A20000 */  sb    $v0, ($a1)
/* 0B2640 8011BF40 3C028015 */  lui   $v0, 0x8015
/* 0B2644 8011BF44 9042B752 */  lbu   $v0, -0x48ae($v0)
/* 0B2648 8011BF48 A0C20000 */  sb    $v0, ($a2)
/* 0B264C 8011BF4C 3C028015 */  lui   $v0, 0x8015
/* 0B2650 8011BF50 9042B753 */  lbu   $v0, -0x48ad($v0)
/* 0B2654 8011BF54 A0E20000 */  sb    $v0, ($a3)
/* 0B2658 8011BF58 3C028015 */  lui   $v0, 0x8015
/* 0B265C 8011BF5C 9042B754 */  lbu   $v0, -0x48ac($v0)
/* 0B2660 8011BF60 A0620000 */  sb    $v0, ($v1)
/* 0B2664 8011BF64 3C028015 */  lui   $v0, 0x8015
/* 0B2668 8011BF68 9042B755 */  lbu   $v0, -0x48ab($v0)
/* 0B266C 8011BF6C A1020000 */  sb    $v0, ($t0)
/* 0B2670 8011BF70 3C028015 */  lui   $v0, 0x8015
/* 0B2674 8011BF74 9042B756 */  lbu   $v0, -0x48aa($v0)
/* 0B2678 8011BF78 A1220000 */  sb    $v0, ($t1)
/* 0B267C 8011BF7C 3C028015 */  lui   $v0, 0x8015
/* 0B2680 8011BF80 8C42B758 */  lw    $v0, -0x48a8($v0)
/* 0B2684 8011BF84 AD420000 */  sw    $v0, ($t2)
/* 0B2688 8011BF88 3C028015 */  lui   $v0, 0x8015
/* 0B268C 8011BF8C 8C42B75C */  lw    $v0, -0x48a4($v0)
/* 0B2690 8011BF90 03E00008 */  jr    $ra
/* 0B2694 8011BF94 AD620000 */   sw    $v0, ($t3)

/* 0B2698 8011BF98 8FA20010 */  lw    $v0, 0x10($sp)
/* 0B269C 8011BF9C 8FA30014 */  lw    $v1, 0x14($sp)
/* 0B26A0 8011BFA0 3C018015 */  lui   $at, 0x8015
/* 0B26A4 8011BFA4 A024B760 */  sb    $a0, -0x48a0($at)
/* 0B26A8 8011BFA8 3C018015 */  lui   $at, 0x8015
/* 0B26AC 8011BFAC A025B761 */  sb    $a1, -0x489f($at)
/* 0B26B0 8011BFB0 3C018015 */  lui   $at, 0x8015
/* 0B26B4 8011BFB4 A026B762 */  sb    $a2, -0x489e($at)
/* 0B26B8 8011BFB8 3C018015 */  lui   $at, 0x8015
/* 0B26BC 8011BFBC A027B763 */  sb    $a3, -0x489d($at)
/* 0B26C0 8011BFC0 3C018015 */  lui   $at, 0x8015
/* 0B26C4 8011BFC4 A022B764 */  sb    $v0, -0x489c($at)
/* 0B26C8 8011BFC8 3C018015 */  lui   $at, 0x8015
/* 0B26CC 8011BFCC 03E00008 */  jr    $ra
/* 0B26D0 8011BFD0 A023B765 */   sb    $v1, -0x489b($at)

