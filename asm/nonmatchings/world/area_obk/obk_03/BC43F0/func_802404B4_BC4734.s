.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404B4_BC4734
/* BC4734 802404B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC4738 802404B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* BC473C 802404BC 10A00003 */  beqz      $a1, .L802404CC
/* BC4740 802404C0 8C86000C */   lw       $a2, 0xc($a0)
/* BC4744 802404C4 3C018024 */  lui       $at, %hi(D_80242F30)
/* BC4748 802404C8 AC202F30 */  sw        $zero, %lo(D_80242F30)($at)
.L802404CC:
/* BC474C 802404CC 3C038024 */  lui       $v1, %hi(D_80242F30)
/* BC4750 802404D0 24632F30 */  addiu     $v1, $v1, %lo(D_80242F30)
/* BC4754 802404D4 8C620000 */  lw        $v0, ($v1)
/* BC4758 802404D8 54400003 */  bnel      $v0, $zero, .L802404E8
/* BC475C 802404DC AC600000 */   sw       $zero, ($v1)
/* BC4760 802404E0 0809013F */  j         .L802404FC
/* BC4764 802404E4 0000102D */   daddu    $v0, $zero, $zero
.L802404E8:
/* BC4768 802404E8 8CC50000 */  lw        $a1, ($a2)
/* BC476C 802404EC 3C068024 */  lui       $a2, %hi(D_80242F34)
/* BC4770 802404F0 0C0B2026 */  jal       set_variable
/* BC4774 802404F4 8CC62F34 */   lw       $a2, %lo(D_80242F34)($a2)
/* BC4778 802404F8 24020002 */  addiu     $v0, $zero, 2
.L802404FC:
/* BC477C 802404FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC4780 80240500 03E00008 */  jr        $ra
/* BC4784 80240504 27BD0018 */   addiu    $sp, $sp, 0x18
