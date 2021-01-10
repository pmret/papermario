.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024027C_A7A77C
/* A7A77C 8024027C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A7A780 80240280 AFBF0010 */  sw        $ra, 0x10($sp)
/* A7A784 80240284 10A00003 */  beqz      $a1, .L80240294
/* A7A788 80240288 8C86000C */   lw       $a2, 0xc($a0)
/* A7A78C 8024028C 3C018024 */  lui       $at, %hi(func_80240C20_872650)
/* A7A790 80240290 AC200C20 */  sw        $zero, %lo(func_80240C20_872650)($at)
.L80240294:
/* A7A794 80240294 3C038024 */  lui       $v1, %hi(func_80240C20_872650)
/* A7A798 80240298 24630C20 */  addiu     $v1, $v1, %lo(func_80240C20_872650)
/* A7A79C 8024029C 8C620000 */  lw        $v0, ($v1)
/* A7A7A0 802402A0 54400003 */  bnel      $v0, $zero, .L802402B0
/* A7A7A4 802402A4 AC600000 */   sw       $zero, ($v1)
/* A7A7A8 802402A8 080900B1 */  j         .L802402C4
/* A7A7AC 802402AC 0000102D */   daddu    $v0, $zero, $zero
.L802402B0:
/* A7A7B0 802402B0 8CC50000 */  lw        $a1, ($a2)
/* A7A7B4 802402B4 3C068024 */  lui       $a2, %hi(D_80240C24)
/* A7A7B8 802402B8 0C0B2026 */  jal       set_variable
/* A7A7BC 802402BC 8CC60C24 */   lw       $a2, %lo(D_80240C24)($a2)
/* A7A7C0 802402C0 24020002 */  addiu     $v0, $zero, 2
.L802402C4:
/* A7A7C4 802402C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* A7A7C8 802402C8 03E00008 */  jr        $ra
/* A7A7CC 802402CC 27BD0018 */   addiu    $sp, $sp, 0x18
