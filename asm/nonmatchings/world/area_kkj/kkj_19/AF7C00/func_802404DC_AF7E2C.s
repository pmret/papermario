.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404DC_AF7E2C
/* AF7E2C 802404DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF7E30 802404E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF7E34 802404E4 10A00003 */  beqz      $a1, .L802404F4
/* AF7E38 802404E8 8C86000C */   lw       $a2, 0xc($a0)
/* AF7E3C 802404EC 3C018024 */  lui       $at, %hi(D_80241B10_AF9460)
/* AF7E40 802404F0 AC201B10 */  sw        $zero, %lo(D_80241B10_AF9460)($at)
.L802404F4:
/* AF7E44 802404F4 3C038024 */  lui       $v1, %hi(D_80241B10_AF9460)
/* AF7E48 802404F8 24631B10 */  addiu     $v1, $v1, %lo(D_80241B10_AF9460)
/* AF7E4C 802404FC 8C620000 */  lw        $v0, ($v1)
/* AF7E50 80240500 54400003 */  bnel      $v0, $zero, .L80240510
/* AF7E54 80240504 AC600000 */   sw       $zero, ($v1)
/* AF7E58 80240508 08090149 */  j         .L80240524
/* AF7E5C 8024050C 0000102D */   daddu    $v0, $zero, $zero
.L80240510:
/* AF7E60 80240510 8CC50000 */  lw        $a1, ($a2)
/* AF7E64 80240514 3C068024 */  lui       $a2, %hi(D_80241B14_AF9464)
/* AF7E68 80240518 0C0B2026 */  jal       set_variable
/* AF7E6C 8024051C 8CC61B14 */   lw       $a2, %lo(D_80241B14_AF9464)($a2)
/* AF7E70 80240520 24020002 */  addiu     $v0, $zero, 2
.L80240524:
/* AF7E74 80240524 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF7E78 80240528 03E00008 */  jr        $ra
/* AF7E7C 8024052C 27BD0018 */   addiu    $sp, $sp, 0x18
