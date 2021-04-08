.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_10_UnkFunc22
/* 886FE8 80240C28 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 886FEC 80240C2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 886FF0 80240C30 0C00EAD2 */  jal       get_npc_safe
/* 886FF4 80240C34 2404FFFC */   addiu    $a0, $zero, -4
/* 886FF8 80240C38 C444003C */  lwc1      $f4, 0x3c($v0)
/* 886FFC 80240C3C 3C014148 */  lui       $at, 0x4148
/* 887000 80240C40 44811000 */  mtc1      $at, $f2
/* 887004 80240C44 3C013F80 */  lui       $at, 0x3f80
/* 887008 80240C48 44810000 */  mtc1      $at, $f0
/* 88700C 80240C4C 2403001E */  addiu     $v1, $zero, 0x1e
/* 887010 80240C50 AFA30014 */  sw        $v1, 0x14($sp)
/* 887014 80240C54 46022100 */  add.s     $f4, $f4, $f2
/* 887018 80240C58 E7A00010 */  swc1      $f0, 0x10($sp)
/* 88701C 80240C5C 8C450038 */  lw        $a1, 0x38($v0)
/* 887020 80240C60 8C470040 */  lw        $a3, 0x40($v0)
/* 887024 80240C64 44062000 */  mfc1      $a2, $f4
/* 887028 80240C68 0C01C2EC */  jal       func_80070BB0
/* 88702C 80240C6C 24040009 */   addiu    $a0, $zero, 9
/* 887030 80240C70 8FBF0018 */  lw        $ra, 0x18($sp)
/* 887034 80240C74 24020002 */  addiu     $v0, $zero, 2
/* 887038 80240C78 03E00008 */  jr        $ra
/* 88703C 80240C7C 27BD0020 */   addiu    $sp, $sp, 0x20
