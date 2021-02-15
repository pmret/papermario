.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413D0_D659B0
/* D659B0 802413D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D659B4 802413D4 AFB00010 */  sw        $s0, 0x10($sp)
/* D659B8 802413D8 0080802D */  daddu     $s0, $a0, $zero
/* D659BC 802413DC 3C058024 */  lui       $a1, %hi(func_8024140C_D659EC)
/* D659C0 802413E0 24A5140C */  addiu     $a1, $a1, %lo(func_8024140C_D659EC)
/* D659C4 802413E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* D659C8 802413E8 0C048C56 */  jal       bind_dynamic_entity_3
/* D659CC 802413EC 0000202D */   daddu    $a0, $zero, $zero
/* D659D0 802413F0 8E03013C */  lw        $v1, 0x13c($s0)
/* D659D4 802413F4 AC620000 */  sw        $v0, ($v1)
/* D659D8 802413F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D659DC 802413FC 8FB00010 */  lw        $s0, 0x10($sp)
/* D659E0 80241400 24020002 */  addiu     $v0, $zero, 2
/* D659E4 80241404 03E00008 */  jr        $ra
/* D659E8 80241408 27BD0018 */   addiu    $sp, $sp, 0x18
