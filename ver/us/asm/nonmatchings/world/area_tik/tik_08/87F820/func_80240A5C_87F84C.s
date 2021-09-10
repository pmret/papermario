.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A5C_87F84C
/* 87F84C 80240A5C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 87F850 80240A60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 87F854 80240A64 AFB00010 */  sw        $s0, 0x10($sp)
/* 87F858 80240A68 8C82000C */  lw        $v0, 0xc($a0)
/* 87F85C 80240A6C 8C450000 */  lw        $a1, ($v0)
/* 87F860 80240A70 0C0B1EAF */  jal       evt_get_variable
/* 87F864 80240A74 8C900148 */   lw       $s0, 0x148($a0)
/* 87F868 80240A78 82030004 */  lb        $v1, 4($s0)
/* 87F86C 80240A7C 00021080 */  sll       $v0, $v0, 2
/* 87F870 80240A80 00031880 */  sll       $v1, $v1, 2
/* 87F874 80240A84 3C04800B */  lui       $a0, %hi(gCurrentEncounter+0x28)
/* 87F878 80240A88 00832021 */  addu      $a0, $a0, $v1
/* 87F87C 80240A8C 8C840F38 */  lw        $a0, %lo(gCurrentEncounter+0x28)($a0)
/* 87F880 80240A90 3C038024 */  lui       $v1, %hi(D_80242C0E_8819FE)
/* 87F884 80240A94 00621821 */  addu      $v1, $v1, $v0
/* 87F888 80240A98 94632C0E */  lhu       $v1, %lo(D_80242C0E_8819FE)($v1)
/* 87F88C 80240A9C A4830044 */  sh        $v1, 0x44($a0)
/* 87F890 80240AA0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 87F894 80240AA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 87F898 80240AA8 24020002 */  addiu     $v0, $zero, 2
/* 87F89C 80240AAC 03E00008 */  jr        $ra
/* 87F8A0 80240AB0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 87F8A4 80240AB4 00000000 */  nop
/* 87F8A8 80240AB8 00000000 */  nop
/* 87F8AC 80240ABC 00000000 */  nop
