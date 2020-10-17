.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260A20
/* 18F300 80260A20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18F304 80260A24 3C04001D */  lui       $a0, 0x1d
/* 18F308 80260A28 348400AB */  ori       $a0, $a0, 0xab
/* 18F30C 80260A2C 2402000F */  addiu     $v0, $zero, 0xf
/* 18F310 80260A30 24A5000B */  addiu     $a1, $a1, 0xb
/* 18F314 80260A34 24C60006 */  addiu     $a2, $a2, 6
/* 18F318 80260A38 240700FF */  addiu     $a3, $zero, 0xff
/* 18F31C 80260A3C AFBF0018 */  sw        $ra, 0x18($sp)
/* 18F320 80260A40 AFA20010 */  sw        $v0, 0x10($sp)
/* 18F324 80260A44 0C04993B */  jal       draw_string
/* 18F328 80260A48 AFA00014 */   sw       $zero, 0x14($sp)
/* 18F32C 80260A4C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18F330 80260A50 03E00008 */  jr        $ra
/* 18F334 80260A54 27BD0020 */   addiu    $sp, $sp, 0x20
/* 18F338 80260A58 00000000 */  nop       
/* 18F33C 80260A5C 00000000 */  nop       
