.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_08_UnkPartnerPosFunc
/* B5F588 802412D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5F58C 802412DC AFBF0018 */  sw        $ra, 0x18($sp)
/* B5F590 802412E0 0C00EAD2 */  jal       get_npc_safe
/* B5F594 802412E4 2404FFFC */   addiu    $a0, $zero, -4
/* B5F598 802412E8 3C0141F0 */  lui       $at, 0x41f0
/* B5F59C 802412EC 44810000 */  mtc1      $at, $f0
/* B5F5A0 802412F0 C442003C */  lwc1      $f2, 0x3c($v0)
/* B5F5A4 802412F4 46001080 */  add.s     $f2, $f2, $f0
/* B5F5A8 802412F8 E7A00010 */  swc1      $f0, 0x10($sp)
/* B5F5AC 802412FC 8C450038 */  lw        $a1, 0x38($v0)
/* B5F5B0 80241300 8C470040 */  lw        $a3, 0x40($v0)
/* B5F5B4 80241304 44061000 */  mfc1      $a2, $f2
/* B5F5B8 80241308 0C01BFBC */  jal       func_8006FEF0
/* B5F5BC 8024130C 24040002 */   addiu    $a0, $zero, 2
/* B5F5C0 80241310 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5F5C4 80241314 24020002 */  addiu     $v0, $zero, 2
/* B5F5C8 80241318 03E00008 */  jr        $ra
/* B5F5CC 8024131C 27BD0020 */   addiu    $sp, $sp, 0x20
