.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A4_AB0694
/* AB0694 802406A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB0698 802406A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* AB069C 802406AC 10A00003 */  beqz      $a1, .L802406BC
/* AB06A0 802406B0 8C86000C */   lw       $a2, 0xc($a0)
/* AB06A4 802406B4 3C018024 */  lui       $at, %hi(D_8024121C_AB120C)
/* AB06A8 802406B8 AC20121C */  sw        $zero, %lo(D_8024121C_AB120C)($at)
.L802406BC:
/* AB06AC 802406BC 3C038024 */  lui       $v1, %hi(D_8024121C_AB120C)
/* AB06B0 802406C0 2463121C */  addiu     $v1, $v1, %lo(D_8024121C_AB120C)
/* AB06B4 802406C4 8C620000 */  lw        $v0, ($v1)
/* AB06B8 802406C8 54400003 */  bnel      $v0, $zero, .L802406D8
/* AB06BC 802406CC AC600000 */   sw       $zero, ($v1)
/* AB06C0 802406D0 080901BB */  j         .L802406EC
/* AB06C4 802406D4 0000102D */   daddu    $v0, $zero, $zero
.L802406D8:
/* AB06C8 802406D8 8CC50000 */  lw        $a1, ($a2)
/* AB06CC 802406DC 3C068024 */  lui       $a2, %hi(D_80241220_AB1210)
/* AB06D0 802406E0 0C0B2026 */  jal       set_variable
/* AB06D4 802406E4 8CC61220 */   lw       $a2, %lo(D_80241220_AB1210)($a2)
/* AB06D8 802406E8 24020002 */  addiu     $v0, $zero, 2
.L802406EC:
/* AB06DC 802406EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB06E0 802406F0 03E00008 */  jr        $ra
/* AB06E4 802406F4 27BD0018 */   addiu    $sp, $sp, 0x18
