.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BF14
/* B2614 8011BF14 3C028015 */  lui       $v0, 0x8015
/* B2618 8011BF18 9042B750 */  lbu       $v0, -0x48b0($v0)
/* B261C 8011BF1C 8FA30010 */  lw        $v1, 0x10($sp)
/* B2620 8011BF20 8FA80014 */  lw        $t0, 0x14($sp)
/* B2624 8011BF24 8FA90018 */  lw        $t1, 0x18($sp)
/* B2628 8011BF28 8FAA001C */  lw        $t2, 0x1c($sp)
/* B262C 8011BF2C 8FAB0020 */  lw        $t3, 0x20($sp)
/* B2630 8011BF30 A0820000 */  sb        $v0, ($a0)
/* B2634 8011BF34 3C028015 */  lui       $v0, 0x8015
/* B2638 8011BF38 9042B751 */  lbu       $v0, -0x48af($v0)
/* B263C 8011BF3C A0A20000 */  sb        $v0, ($a1)
/* B2640 8011BF40 3C028015 */  lui       $v0, 0x8015
/* B2644 8011BF44 9042B752 */  lbu       $v0, -0x48ae($v0)
/* B2648 8011BF48 A0C20000 */  sb        $v0, ($a2)
/* B264C 8011BF4C 3C028015 */  lui       $v0, 0x8015
/* B2650 8011BF50 9042B753 */  lbu       $v0, -0x48ad($v0)
/* B2654 8011BF54 A0E20000 */  sb        $v0, ($a3)
/* B2658 8011BF58 3C028015 */  lui       $v0, 0x8015
/* B265C 8011BF5C 9042B754 */  lbu       $v0, -0x48ac($v0)
/* B2660 8011BF60 A0620000 */  sb        $v0, ($v1)
/* B2664 8011BF64 3C028015 */  lui       $v0, 0x8015
/* B2668 8011BF68 9042B755 */  lbu       $v0, -0x48ab($v0)
/* B266C 8011BF6C A1020000 */  sb        $v0, ($t0)
/* B2670 8011BF70 3C028015 */  lui       $v0, 0x8015
/* B2674 8011BF74 9042B756 */  lbu       $v0, -0x48aa($v0)
/* B2678 8011BF78 A1220000 */  sb        $v0, ($t1)
/* B267C 8011BF7C 3C028015 */  lui       $v0, 0x8015
/* B2680 8011BF80 8C42B758 */  lw        $v0, -0x48a8($v0)
/* B2684 8011BF84 AD420000 */  sw        $v0, ($t2)
/* B2688 8011BF88 3C028015 */  lui       $v0, 0x8015
/* B268C 8011BF8C 8C42B75C */  lw        $v0, -0x48a4($v0)
/* B2690 8011BF90 03E00008 */  jr        $ra
/* B2694 8011BF94 AD620000 */   sw       $v0, ($t3)
