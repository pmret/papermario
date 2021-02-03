.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414EC_B2D95C
/* B2D95C 802414EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2D960 802414F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2D964 802414F4 10A00003 */  beqz      $a1, .L80241504
/* B2D968 802414F8 8C86000C */   lw       $a2, 0xc($a0)
/* B2D96C 802414FC 3C018024 */  lui       $at, %hi(D_80243048_B2F4B8)
/* B2D970 80241500 AC203048 */  sw        $zero, %lo(D_80243048_B2F4B8)($at)
.L80241504:
/* B2D974 80241504 3C038024 */  lui       $v1, %hi(D_80243048_B2F4B8)
/* B2D978 80241508 24633048 */  addiu     $v1, $v1, %lo(D_80243048_B2F4B8)
/* B2D97C 8024150C 8C620000 */  lw        $v0, ($v1)
/* B2D980 80241510 54400003 */  bnel      $v0, $zero, .L80241520
/* B2D984 80241514 AC600000 */   sw       $zero, ($v1)
/* B2D988 80241518 0809054D */  j         .L80241534
/* B2D98C 8024151C 0000102D */   daddu    $v0, $zero, $zero
.L80241520:
/* B2D990 80241520 8CC50000 */  lw        $a1, ($a2)
/* B2D994 80241524 3C068024 */  lui       $a2, %hi(D_8024304C_B2F4BC)
/* B2D998 80241528 0C0B2026 */  jal       set_variable
/* B2D99C 8024152C 8CC6304C */   lw       $a2, %lo(D_8024304C_B2F4BC)($a2)
/* B2D9A0 80241530 24020002 */  addiu     $v0, $zero, 2
.L80241534:
/* B2D9A4 80241534 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2D9A8 80241538 03E00008 */  jr        $ra
/* B2D9AC 8024153C 27BD0018 */   addiu    $sp, $sp, 0x18
