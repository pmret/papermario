.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_10_UnkPartnerPosFunc
/* 8876B8 802412F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8876BC 802412FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 8876C0 80241300 0C00EAD2 */  jal       get_npc_safe
/* 8876C4 80241304 2404FFFC */   addiu    $a0, $zero, -4
/* 8876C8 80241308 3C0141F0 */  lui       $at, 0x41f0
/* 8876CC 8024130C 44810000 */  mtc1      $at, $f0
/* 8876D0 80241310 C442003C */  lwc1      $f2, 0x3c($v0)
/* 8876D4 80241314 46001080 */  add.s     $f2, $f2, $f0
/* 8876D8 80241318 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8876DC 8024131C 8C450038 */  lw        $a1, 0x38($v0)
/* 8876E0 80241320 8C470040 */  lw        $a3, 0x40($v0)
/* 8876E4 80241324 44061000 */  mfc1      $a2, $f2
/* 8876E8 80241328 0C01BFBC */  jal       func_8006FEF0
/* 8876EC 8024132C 24040002 */   addiu    $a0, $zero, 2
/* 8876F0 80241330 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8876F4 80241334 24020002 */  addiu     $v0, $zero, 2
/* 8876F8 80241338 03E00008 */  jr        $ra
/* 8876FC 8024133C 27BD0020 */   addiu    $sp, $sp, 0x20
