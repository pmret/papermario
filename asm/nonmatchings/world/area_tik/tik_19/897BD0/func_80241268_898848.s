.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_19_UnkPartnerPosFunc
/* 898848 80241268 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 89884C 8024126C AFBF0018 */  sw        $ra, 0x18($sp)
/* 898850 80241270 0C00EAD2 */  jal       get_npc_safe
/* 898854 80241274 2404FFFC */   addiu    $a0, $zero, -4
/* 898858 80241278 3C0141F0 */  lui       $at, 0x41f0
/* 89885C 8024127C 44810000 */  mtc1      $at, $f0
/* 898860 80241280 C442003C */  lwc1      $f2, 0x3c($v0)
/* 898864 80241284 46001080 */  add.s     $f2, $f2, $f0
/* 898868 80241288 E7A00010 */  swc1      $f0, 0x10($sp)
/* 89886C 8024128C 8C450038 */  lw        $a1, 0x38($v0)
/* 898870 80241290 8C470040 */  lw        $a3, 0x40($v0)
/* 898874 80241294 44061000 */  mfc1      $a2, $f2
/* 898878 80241298 0C01BFBC */  jal       func_8006FEF0
/* 89887C 8024129C 24040002 */   addiu    $a0, $zero, 2
/* 898880 802412A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 898884 802412A4 24020002 */  addiu     $v0, $zero, 2
/* 898888 802412A8 03E00008 */  jr        $ra
/* 89888C 802412AC 27BD0020 */   addiu    $sp, $sp, 0x20
