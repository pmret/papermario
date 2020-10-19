.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC0_989820
/* 989820 80240CC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 989824 80240CC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 989828 80240CC8 0C00EAD2 */  jal       get_npc_safe
/* 98982C 80240CCC 2404FFFC */   addiu    $a0, $zero, -4
/* 989830 80240CD0 3C0141F0 */  lui       $at, 0x41f0
/* 989834 80240CD4 44810000 */  mtc1      $at, $f0
/* 989838 80240CD8 C442003C */  lwc1      $f2, 0x3c($v0)
/* 98983C 80240CDC 46001080 */  add.s     $f2, $f2, $f0
/* 989840 80240CE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 989844 80240CE4 8C450038 */  lw        $a1, 0x38($v0)
/* 989848 80240CE8 8C470040 */  lw        $a3, 0x40($v0)
/* 98984C 80240CEC 44061000 */  mfc1      $a2, $f2
/* 989850 80240CF0 0C01BFBC */  jal       func_8006FEF0
/* 989854 80240CF4 24040004 */   addiu    $a0, $zero, 4
/* 989858 80240CF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 98985C 80240CFC 24020002 */  addiu     $v0, $zero, 2
/* 989860 80240D00 03E00008 */  jr        $ra
/* 989864 80240D04 27BD0020 */   addiu    $sp, $sp, 0x20
