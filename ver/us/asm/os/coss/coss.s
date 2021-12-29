.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel coss
/* 3D300 80061F00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D304 80061F04 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D308 80061F08 24844000 */  addiu     $a0, $a0, 0x4000
/* 3D30C 80061F0C 0C01917C */  jal       sins
/* 3D310 80061F10 3084FFFF */   andi     $a0, $a0, 0xffff
/* 3D314 80061F14 00021400 */  sll       $v0, $v0, 0x10
/* 3D318 80061F18 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D31C 80061F1C 00021403 */  sra       $v0, $v0, 0x10
/* 3D320 80061F20 03E00008 */  jr        $ra
/* 3D324 80061F24 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3D328 80061F28 00000000 */  nop
/* 3D32C 80061F2C 00000000 */  nop
