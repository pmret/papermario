.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243048_C39578
/* C39578 80243048 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3957C 8024304C AFBF0018 */  sw        $ra, 0x18($sp)
/* C39580 80243050 0C00EAD2 */  jal       get_npc_safe
/* C39584 80243054 2404FFFC */   addiu    $a0, $zero, -4
/* C39588 80243058 3C0141F0 */  lui       $at, 0x41f0
/* C3958C 8024305C 44810000 */  mtc1      $at, $f0
/* C39590 80243060 C442003C */  lwc1      $f2, 0x3c($v0)
/* C39594 80243064 46001080 */  add.s     $f2, $f2, $f0
/* C39598 80243068 E7A00010 */  swc1      $f0, 0x10($sp)
/* C3959C 8024306C 8C450038 */  lw        $a1, 0x38($v0)
/* C395A0 80243070 8C470040 */  lw        $a3, 0x40($v0)
/* C395A4 80243074 44061000 */  mfc1      $a2, $f2
/* C395A8 80243078 0C01BFBC */  jal       func_8006FEF0
/* C395AC 8024307C 24040002 */   addiu    $a0, $zero, 2
/* C395B0 80243080 8FBF0018 */  lw        $ra, 0x18($sp)
/* C395B4 80243084 24020002 */  addiu     $v0, $zero, 2
/* C395B8 80243088 03E00008 */  jr        $ra
/* C395BC 8024308C 27BD0020 */   addiu    $sp, $sp, 0x20
