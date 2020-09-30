.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel is_actortype_hpbar_visible
/* 18257C 80253C9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 182580 80253CA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 182584 80253CA4 0080882D */  daddu     $s1, $a0, $zero
/* 182588 80253CA8 24040036 */  addiu     $a0, $zero, 0x36
/* 18258C 80253CAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 182590 80253CB0 0C03A752 */  jal       is_ability_active
/* 182594 80253CB4 AFB00010 */   sw       $s0, 0x10($sp)
/* 182598 80253CB8 14400010 */  bnez      $v0, .L80253CFC
/* 18259C 80253CBC 24020001 */   addiu    $v0, $zero, 1
/* 1825A0 80253CC0 06210002 */  bgez      $s1, .L80253CCC
/* 1825A4 80253CC4 0220802D */   daddu    $s0, $s1, $zero
/* 1825A8 80253CC8 26300007 */  addiu     $s0, $s1, 7
.L80253CCC:
/* 1825AC 80253CCC 001080C3 */  sra       $s0, $s0, 3
/* 1825B0 80253CD0 0C05154E */  jal       get_global_byte
/* 1825B4 80253CD4 2604016D */   addiu    $a0, $s0, 0x16d
/* 1825B8 80253CD8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1825BC 80253CDC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1825C0 80253CE0 02031821 */  addu      $v1, $s0, $v1
/* 1825C4 80253CE4 90630440 */  lbu       $v1, 0x440($v1)
/* 1825C8 80253CE8 001080C0 */  sll       $s0, $s0, 3
/* 1825CC 80253CEC 02308023 */  subu      $s0, $s1, $s0
/* 1825D0 80253CF0 00431025 */  or        $v0, $v0, $v1
/* 1825D4 80253CF4 02021007 */  srav      $v0, $v0, $s0
/* 1825D8 80253CF8 30420001 */  andi      $v0, $v0, 1
.L80253CFC:
/* 1825DC 80253CFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1825E0 80253D00 8FB10014 */  lw        $s1, 0x14($sp)
/* 1825E4 80253D04 8FB00010 */  lw        $s0, 0x10($sp)
/* 1825E8 80253D08 03E00008 */  jr        $ra
/* 1825EC 80253D0C 27BD0020 */   addiu    $sp, $sp, 0x20
