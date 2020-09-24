.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E4F10
/* 7E3C0 800E4F10 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 7E3C4 800E4F14 AFB00030 */  sw        $s0, 0x30($sp)
/* 7E3C8 800E4F18 3C108011 */  lui       $s0, 0x8011
/* 7E3CC 800E4F1C 2610EFC8 */  addiu     $s0, $s0, -0x1038
/* 7E3D0 800E4F20 0200202D */  daddu     $a0, $s0, $zero
/* 7E3D4 800E4F24 27A2002C */  addiu     $v0, $sp, 0x2c
/* 7E3D8 800E4F28 27A50020 */  addiu     $a1, $sp, 0x20
/* 7E3DC 800E4F2C 27A60024 */  addiu     $a2, $sp, 0x24
/* 7E3E0 800E4F30 AFBF0034 */  sw        $ra, 0x34($sp)
/* 7E3E4 800E4F34 C6060080 */  lwc1      $f6, 0x80($s0)
/* 7E3E8 800E4F38 C6000028 */  lwc1      $f0, 0x28($s0)
/* 7E3EC 800E4F3C C602002C */  lwc1      $f2, 0x2c($s0)
/* 7E3F0 800E4F40 C6040030 */  lwc1      $f4, 0x30($s0)
/* 7E3F4 800E4F44 27A70028 */  addiu     $a3, $sp, 0x28
/* 7E3F8 800E4F48 AFA0002C */  sw        $zero, 0x2c($sp)
/* 7E3FC 800E4F4C E7A00020 */  swc1      $f0, 0x20($sp)
/* 7E400 800E4F50 E7A20024 */  swc1      $f2, 0x24($sp)
/* 7E404 800E4F54 E7A40028 */  swc1      $f4, 0x28($sp)
/* 7E408 800E4F58 AFA00010 */  sw        $zero, 0x10($sp)
/* 7E40C 800E4F5C E7A60014 */  swc1      $f6, 0x14($sp)
/* 7E410 800E4F60 0C037C57 */  jal       func_800DF15C
/* 7E414 800E4F64 AFA20018 */   sw       $v0, 0x18($sp)
/* 7E418 800E4F68 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7E41C 800E4F6C C7A20028 */  lwc1      $f2, 0x28($sp)
/* 7E420 800E4F70 E6000028 */  swc1      $f0, 0x28($s0)
/* 7E424 800E4F74 E6020030 */  swc1      $f2, 0x30($s0)
/* 7E428 800E4F78 8FA3002C */  lw        $v1, 0x2c($sp)
/* 7E42C 800E4F7C 1060000F */  beqz      $v1, .L800E4FBC
/* 7E430 800E4F80 00000000 */   nop      
/* 7E434 800E4F84 0441000D */  bgez      $v0, .L800E4FBC
/* 7E438 800E4F88 24020018 */   addiu    $v0, $zero, 0x18
/* 7E43C 800E4F8C 820300B4 */  lb        $v1, 0xb4($s0)
/* 7E440 800E4F90 1062000A */  beq       $v1, $v0, .L800E4FBC
/* 7E444 800E4F94 00000000 */   nop      
/* 7E448 800E4F98 C6020054 */  lwc1      $f2, 0x54($s0)
/* 7E44C 800E4F9C 44800000 */  mtc1      $zero, $f0
/* 7E450 800E4FA0 00000000 */  nop       
/* 7E454 800E4FA4 46001032 */  c.eq.s    $f2, $f0
/* 7E458 800E4FA8 00000000 */  nop       
/* 7E45C 800E4FAC 45010003 */  bc1t      .L800E4FBC
/* 7E460 800E4FB0 00000000 */   nop      
/* 7E464 800E4FB4 0C039769 */  jal       set_action_state
/* 7E468 800E4FB8 0040202D */   daddu    $a0, $v0, $zero
.L800E4FBC:
/* 7E46C 800E4FBC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 7E470 800E4FC0 8FB00030 */  lw        $s0, 0x30($sp)
/* 7E474 800E4FC4 03E00008 */  jr        $ra
/* 7E478 800E4FC8 27BD0038 */   addiu    $sp, $sp, 0x38
