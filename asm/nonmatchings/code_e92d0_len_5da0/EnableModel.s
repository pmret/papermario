.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel EnableModel
/* 0EDC38 802C9288 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDC3C 802C928C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDC40 802C9290 0080882D */  daddu $s1, $a0, $zero
/* 0EDC44 802C9294 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EDC48 802C9298 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDC4C 802C929C 8E30000C */  lw    $s0, 0xc($s1)
/* 0EDC50 802C92A0 8E050000 */  lw    $a1, ($s0)
/* 0EDC54 802C92A4 0C0B1EAF */  jal   get_variable
/* 0EDC58 802C92A8 26100004 */   addiu $s0, $s0, 4
/* 0EDC5C 802C92AC 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0EDC60 802C92B0 0040202D */   daddu $a0, $v0, $zero
/* 0EDC64 802C92B4 0220202D */  daddu $a0, $s1, $zero
/* 0EDC68 802C92B8 8E050000 */  lw    $a1, ($s0)
/* 0EDC6C 802C92BC 0C0B1EAF */  jal   get_variable
/* 0EDC70 802C92C0 0040802D */   daddu $s0, $v0, $zero
/* 0EDC74 802C92C4 0200202D */  daddu $a0, $s0, $zero
/* 0EDC78 802C92C8 0C046B4C */  jal   get_model_from_list_index
/* 0EDC7C 802C92CC 0040802D */   daddu $s0, $v0, $zero
/* 0EDC80 802C92D0 12000004 */  beqz  $s0, .L802C92E4
/* 0EDC84 802C92D4 0040182D */   daddu $v1, $v0, $zero
/* 0EDC88 802C92D8 94620000 */  lhu   $v0, ($v1)
/* 0EDC8C 802C92DC 080B24BB */  j     .L802C92EC
/* 0EDC90 802C92E0 3042FFFD */   andi  $v0, $v0, 0xfffd

.L802C92E4:
/* 0EDC94 802C92E4 94620000 */  lhu   $v0, ($v1)
/* 0EDC98 802C92E8 34420002 */  ori   $v0, $v0, 2
.L802C92EC:
/* 0EDC9C 802C92EC A4620000 */  sh    $v0, ($v1)
/* 0EDCA0 802C92F0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EDCA4 802C92F4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDCA8 802C92F8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDCAC 802C92FC 24020002 */  addiu $v0, $zero, 2
/* 0EDCB0 802C9300 03E00008 */  jr    $ra
/* 0EDCB4 802C9304 27BD0020 */   addiu $sp, $sp, 0x20

