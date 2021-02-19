.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_07_UnkPartnerPosFunc
/* 87AB80 80240FA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 87AB84 80240FA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 87AB88 80240FA8 0C00EAD2 */  jal       get_npc_safe
/* 87AB8C 80240FAC 2404FFFC */   addiu    $a0, $zero, -4
/* 87AB90 80240FB0 3C0141F0 */  lui       $at, 0x41f0
/* 87AB94 80240FB4 44810000 */  mtc1      $at, $f0
/* 87AB98 80240FB8 C442003C */  lwc1      $f2, 0x3c($v0)
/* 87AB9C 80240FBC 46001080 */  add.s     $f2, $f2, $f0
/* 87ABA0 80240FC0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 87ABA4 80240FC4 8C450038 */  lw        $a1, 0x38($v0)
/* 87ABA8 80240FC8 8C470040 */  lw        $a3, 0x40($v0)
/* 87ABAC 80240FCC 44061000 */  mfc1      $a2, $f2
/* 87ABB0 80240FD0 0C01BFBC */  jal       func_8006FEF0
/* 87ABB4 80240FD4 24040004 */   addiu    $a0, $zero, 4
/* 87ABB8 80240FD8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 87ABBC 80240FDC 24020002 */  addiu     $v0, $zero, 2
/* 87ABC0 80240FE0 03E00008 */  jr        $ra
/* 87ABC4 80240FE4 27BD0020 */   addiu    $sp, $sp, 0x20
