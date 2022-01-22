.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D8264
/* 3D6A24 E00D8264 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D6A28 E00D8268 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D6A2C E00D826C 0C03618C */  jal       func_E00D8630
/* 3D6A30 E00D8270 00000000 */   nop
/* 3D6A34 E00D8274 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D6A38 E00D8278 03E00008 */  jr        $ra
/* 3D6A3C E00D827C 27BD0018 */   addiu    $sp, $sp, 0x18
