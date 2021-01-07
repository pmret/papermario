.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024027C_A7873C
/* A7873C 8024027C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A78740 80240280 AFBF0010 */  sw        $ra, 0x10($sp)
/* A78744 80240284 10A00003 */  beqz      $a1, .L80240294
/* A78748 80240288 8C86000C */   lw       $a2, 0xc($a0)
/* A7874C 8024028C 3C018024 */  lui       $at, %hi(D_80240D98)
/* A78750 80240290 AC200D98 */  sw        $zero, %lo(D_80240D98)($at)
.L80240294:
/* A78754 80240294 3C038024 */  lui       $v1, %hi(D_80240D98)
/* A78758 80240298 24630D98 */  addiu     $v1, $v1, %lo(D_80240D98)
/* A7875C 8024029C 8C620000 */  lw        $v0, ($v1)
/* A78760 802402A0 54400003 */  bnel      $v0, $zero, .L802402B0
/* A78764 802402A4 AC600000 */   sw       $zero, ($v1)
/* A78768 802402A8 080900B1 */  j         .L802402C4
/* A7876C 802402AC 0000102D */   daddu    $v0, $zero, $zero
.L802402B0:
/* A78770 802402B0 8CC50000 */  lw        $a1, ($a2)
/* A78774 802402B4 3C068024 */  lui       $a2, %hi(D_80240D9C)
/* A78778 802402B8 0C0B2026 */  jal       set_variable
/* A7877C 802402BC 8CC60D9C */   lw       $a2, %lo(D_80240D9C)($a2)
/* A78780 802402C0 24020002 */  addiu     $v0, $zero, 2
.L802402C4:
/* A78784 802402C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* A78788 802402C8 03E00008 */  jr        $ra
/* A7878C 802402CC 27BD0018 */   addiu    $sp, $sp, 0x18
