.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417AC_C8F35C
/* C8F35C 802417AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8F360 802417B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* C8F364 802417B4 10A00003 */  beqz      $a1, .L802417C4
/* C8F368 802417B8 8C86000C */   lw       $a2, 0xc($a0)
/* C8F36C 802417BC 3C018024 */  lui       $at, %hi(D_80243DD8_C91988)
/* C8F370 802417C0 AC203DD8 */  sw        $zero, %lo(D_80243DD8_C91988)($at)
.L802417C4:
/* C8F374 802417C4 3C038024 */  lui       $v1, %hi(D_80243DD8_C91988)
/* C8F378 802417C8 24633DD8 */  addiu     $v1, $v1, %lo(D_80243DD8_C91988)
/* C8F37C 802417CC 8C620000 */  lw        $v0, ($v1)
/* C8F380 802417D0 54400003 */  bnel      $v0, $zero, .L802417E0
/* C8F384 802417D4 AC600000 */   sw       $zero, ($v1)
/* C8F388 802417D8 080905FD */  j         .L802417F4
/* C8F38C 802417DC 0000102D */   daddu    $v0, $zero, $zero
.L802417E0:
/* C8F390 802417E0 8CC50000 */  lw        $a1, ($a2)
/* C8F394 802417E4 3C068024 */  lui       $a2, %hi(D_80243DDC_C9198C)
/* C8F398 802417E8 0C0B2026 */  jal       set_variable
/* C8F39C 802417EC 8CC63DDC */   lw       $a2, %lo(D_80243DDC_C9198C)($a2)
/* C8F3A0 802417F0 24020002 */  addiu     $v0, $zero, 2
.L802417F4:
/* C8F3A4 802417F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C8F3A8 802417F8 03E00008 */  jr        $ra
/* C8F3AC 802417FC 27BD0018 */   addiu    $sp, $sp, 0x18
