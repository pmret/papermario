.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_08_UnkPartnerPosFunc
/* B5F5D0 80241320 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5F5D4 80241324 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5F5D8 80241328 0C00EAD2 */  jal       get_npc_safe
/* B5F5DC 8024132C 2404FFFC */   addiu    $a0, $zero, -4
/* B5F5E0 80241330 3C0141F0 */  lui       $at, 0x41f0
/* B5F5E4 80241334 44810000 */  mtc1      $at, $f0
/* B5F5E8 80241338 C442003C */  lwc1      $f2, 0x3c($v0)
/* B5F5EC 8024133C 46001080 */  add.s     $f2, $f2, $f0
/* B5F5F0 80241340 E7A00010 */  swc1      $f0, 0x10($sp)
/* B5F5F4 80241344 8C450038 */  lw        $a1, 0x38($v0)
/* B5F5F8 80241348 8C470040 */  lw        $a3, 0x40($v0)
/* B5F5FC 8024134C 44061000 */  mfc1      $a2, $f2
/* B5F600 80241350 0C01BFBC */  jal       func_8006FEF0
/* B5F604 80241354 24040004 */   addiu    $a0, $zero, 4
/* B5F608 80241358 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5F60C 8024135C 24020002 */  addiu     $v0, $zero, 2
/* B5F610 80241360 03E00008 */  jr        $ra
/* B5F614 80241364 27BD0020 */   addiu    $sp, $sp, 0x20
