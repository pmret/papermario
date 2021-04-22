.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061ED0
/* 3D2D0 80061ED0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D2D4 80061ED4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D2D8 80061ED8 24844000 */  addiu     $a0, $a0, 0x4000
/* 3D2DC 80061EDC 0C019170 */  jal       func_800645C0
/* 3D2E0 80061EE0 3084FFFF */   andi     $a0, $a0, 0xffff
/* 3D2E4 80061EE4 00021400 */  sll       $v0, $v0, 0x10
/* 3D2E8 80061EE8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D2EC 80061EEC 00021403 */  sra       $v0, $v0, 0x10
/* 3D2F0 80061EF0 03E00008 */  jr        $ra
/* 3D2F4 80061EF4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3D2F8 80061EF8 00000000 */  nop
/* 3D2FC 80061EFC 00000000 */  nop
