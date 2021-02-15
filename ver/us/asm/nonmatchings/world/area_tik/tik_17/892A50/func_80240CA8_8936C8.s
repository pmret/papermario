.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CA8_8936C8
/* 8936C8 80240CA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8936CC 80240CAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 8936D0 80240CB0 0C00EAD2 */  jal       get_npc_safe
/* 8936D4 80240CB4 2404FFFC */   addiu    $a0, $zero, -4
/* 8936D8 80240CB8 3C0141F0 */  lui       $at, 0x41f0
/* 8936DC 80240CBC 44810000 */  mtc1      $at, $f0
/* 8936E0 80240CC0 C442003C */  lwc1      $f2, 0x3c($v0)
/* 8936E4 80240CC4 46001080 */  add.s     $f2, $f2, $f0
/* 8936E8 80240CC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8936EC 80240CCC 8C450038 */  lw        $a1, 0x38($v0)
/* 8936F0 80240CD0 8C470040 */  lw        $a3, 0x40($v0)
/* 8936F4 80240CD4 44061000 */  mfc1      $a2, $f2
/* 8936F8 80240CD8 0C01BFBC */  jal       func_8006FEF0
/* 8936FC 80240CDC 24040002 */   addiu    $a0, $zero, 2
/* 893700 80240CE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 893704 80240CE4 24020002 */  addiu     $v0, $zero, 2
/* 893708 80240CE8 03E00008 */  jr        $ra
/* 89370C 80240CEC 27BD0020 */   addiu    $sp, $sp, 0x20
