.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412B0_898890
/* 898890 802412B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 898894 802412B4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 898898 802412B8 0C00EAD2 */  jal       get_npc_safe
/* 89889C 802412BC 2404FFFC */   addiu    $a0, $zero, -4
/* 8988A0 802412C0 3C0141F0 */  lui       $at, 0x41f0
/* 8988A4 802412C4 44810000 */  mtc1      $at, $f0
/* 8988A8 802412C8 C442003C */  lwc1      $f2, 0x3c($v0)
/* 8988AC 802412CC 46001080 */  add.s     $f2, $f2, $f0
/* 8988B0 802412D0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8988B4 802412D4 8C450038 */  lw        $a1, 0x38($v0)
/* 8988B8 802412D8 8C470040 */  lw        $a3, 0x40($v0)
/* 8988BC 802412DC 44061000 */  mfc1      $a2, $f2
/* 8988C0 802412E0 0C01BFBC */  jal       func_8006FEF0
/* 8988C4 802412E4 24040004 */   addiu    $a0, $zero, 4
/* 8988C8 802412E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8988CC 802412EC 24020002 */  addiu     $v0, $zero, 2
/* 8988D0 802412F0 03E00008 */  jr        $ra
/* 8988D4 802412F4 27BD0020 */   addiu    $sp, $sp, 0x20
