.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419D8_B365A8
/* B365A8 802419D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B365AC 802419DC AFBF0010 */  sw        $ra, 0x10($sp)
/* B365B0 802419E0 10A00003 */  beqz      $a1, .L802419F0
/* B365B4 802419E4 8C86000C */   lw       $a2, 0xc($a0)
/* B365B8 802419E8 3C018024 */  lui       $at, 0x8024
/* B365BC 802419EC AC207444 */  sw        $zero, 0x7444($at)
.L802419F0:
/* B365C0 802419F0 3C038024 */  lui       $v1, 0x8024
/* B365C4 802419F4 24637444 */  addiu     $v1, $v1, 0x7444
/* B365C8 802419F8 8C620000 */  lw        $v0, ($v1)
/* B365CC 802419FC 54400003 */  bnel      $v0, $zero, .L80241A0C
/* B365D0 80241A00 AC600000 */   sw       $zero, ($v1)
/* B365D4 80241A04 08090688 */  j         .L80241A20
/* B365D8 80241A08 0000102D */   daddu    $v0, $zero, $zero
.L80241A0C:
/* B365DC 80241A0C 8CC50000 */  lw        $a1, ($a2)
/* B365E0 80241A10 3C068024 */  lui       $a2, 0x8024
/* B365E4 80241A14 0C0B2026 */  jal       set_variable
/* B365E8 80241A18 8CC67448 */   lw       $a2, 0x7448($a2)
/* B365EC 80241A1C 24020002 */  addiu     $v0, $zero, 2
.L80241A20:
/* B365F0 80241A20 8FBF0010 */  lw        $ra, 0x10($sp)
/* B365F4 80241A24 03E00008 */  jr        $ra
/* B365F8 80241A28 27BD0018 */   addiu    $sp, $sp, 0x18
