.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetTexPanner
/* 0ED9B0 802C9000 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0ED9B4 802C9004 AFB10014 */  sw    $s1, 0x14($sp)
/* 0ED9B8 802C9008 0080882D */  daddu $s1, $a0, $zero
/* 0ED9BC 802C900C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0ED9C0 802C9010 AFB00010 */  sw    $s0, 0x10($sp)
/* 0ED9C4 802C9014 8E30000C */  lw    $s0, 0xc($s1)
/* 0ED9C8 802C9018 8E050000 */  lw    $a1, ($s0)
/* 0ED9CC 802C901C 0C0B1EAF */  jal   get_variable
/* 0ED9D0 802C9020 26100004 */   addiu $s0, $s0, 4
/* 0ED9D4 802C9024 0220202D */  daddu $a0, $s1, $zero
/* 0ED9D8 802C9028 8E050000 */  lw    $a1, ($s0)
/* 0ED9DC 802C902C 0C0B1EAF */  jal   get_variable
/* 0ED9E0 802C9030 0040802D */   daddu $s0, $v0, $zero
/* 0ED9E4 802C9034 0200202D */  daddu $a0, $s0, $zero
/* 0ED9E8 802C9038 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0ED9EC 802C903C 0040882D */   daddu $s1, $v0, $zero
/* 0ED9F0 802C9040 0C046B4C */  jal   get_model_from_list_index
/* 0ED9F4 802C9044 0040202D */   daddu $a0, $v0, $zero
/* 0ED9F8 802C9048 0040802D */  daddu $s0, $v0, $zero
/* 0ED9FC 802C904C 0200202D */  daddu $a0, $s0, $zero
/* 0EDA00 802C9050 0C046F05 */  jal   set_tex_panner
/* 0EDA04 802C9054 0220282D */   daddu $a1, $s1, $zero
/* 0EDA08 802C9058 96030000 */  lhu   $v1, ($s0)
/* 0EDA0C 802C905C 34630800 */  ori   $v1, $v1, 0x800
/* 0EDA10 802C9060 A6030000 */  sh    $v1, ($s0)
/* 0EDA14 802C9064 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EDA18 802C9068 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDA1C 802C906C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDA20 802C9070 24020002 */  addiu $v0, $zero, 2
/* 0EDA24 802C9074 03E00008 */  jr    $ra
/* 0EDA28 802C9078 27BD0020 */   addiu $sp, $sp, 0x20

