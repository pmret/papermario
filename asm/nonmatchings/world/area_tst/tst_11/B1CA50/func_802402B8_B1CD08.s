.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402B8_B1CD08
/* B1CD08 802402B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1CD0C 802402BC AFB00010 */  sw        $s0, 0x10($sp)
/* B1CD10 802402C0 0080802D */  daddu     $s0, $a0, $zero
/* B1CD14 802402C4 3C058024 */  lui       $a1, %hi(D_802402F4)
/* B1CD18 802402C8 24A502F4 */  addiu     $a1, $a1, %lo(D_802402F4)
/* B1CD1C 802402CC AFBF0014 */  sw        $ra, 0x14($sp)
/* B1CD20 802402D0 0C048C8F */  jal       bind_dynamic_entity_7
/* B1CD24 802402D4 0000202D */   daddu    $a0, $zero, $zero
/* B1CD28 802402D8 8E03013C */  lw        $v1, 0x13c($s0)
/* B1CD2C 802402DC AC620000 */  sw        $v0, ($v1)
/* B1CD30 802402E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* B1CD34 802402E4 8FB00010 */  lw        $s0, 0x10($sp)
/* B1CD38 802402E8 24020002 */  addiu     $v0, $zero, 2
/* B1CD3C 802402EC 03E00008 */  jr        $ra
/* B1CD40 802402F0 27BD0018 */   addiu    $sp, $sp, 0x18
