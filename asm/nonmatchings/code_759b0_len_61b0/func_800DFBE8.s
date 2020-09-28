.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DFBE8
/* 79098 800DFBE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7909C 800DFBEC AFBF0010 */  sw        $ra, 0x10($sp)
/* 790A0 800DFBF0 0C03968B */  jal       func_800E5A2C
/* 790A4 800DFBF4 00000000 */   nop      
/* 790A8 800DFBF8 0C038D8F */  jal       collision_main_lateral
/* 790AC 800DFBFC 00000000 */   nop      
/* 790B0 800DFC00 0C0392EE */  jal       func_800E4BB8
/* 790B4 800DFC04 00000000 */   nop      
/* 790B8 800DFC08 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* 790BC 800DFC0C 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* 790C0 800DFC10 8C820000 */  lw        $v0, ($a0)
/* 790C4 800DFC14 3C030400 */  lui       $v1, 0x400
/* 790C8 800DFC18 00431024 */  and       $v0, $v0, $v1
/* 790CC 800DFC1C 14400009 */  bnez      $v0, .L800DFC44
/* 790D0 800DFC20 00000000 */   nop      
/* 790D4 800DFC24 C4800028 */  lwc1      $f0, 0x28($a0)
/* 790D8 800DFC28 3C02800B */  lui       $v0, %hi(gCameras)
/* 790DC 800DFC2C 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 790E0 800DFC30 E4400060 */  swc1      $f0, 0x60($v0)
/* 790E4 800DFC34 C480002C */  lwc1      $f0, 0x2c($a0)
/* 790E8 800DFC38 E4400064 */  swc1      $f0, 0x64($v0)
/* 790EC 800DFC3C C4800030 */  lwc1      $f0, 0x30($a0)
/* 790F0 800DFC40 E4400068 */  swc1      $f0, 0x68($v0)
.L800DFC44:
/* 790F4 800DFC44 8FBF0010 */  lw        $ra, 0x10($sp)
/* 790F8 800DFC48 03E00008 */  jr        $ra
/* 790FC 800DFC4C 27BD0018 */   addiu    $sp, $sp, 0x18
