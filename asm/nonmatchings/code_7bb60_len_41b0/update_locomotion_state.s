.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_locomotion_state
/* 7F418 800E5F68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7F41C 800E5F6C AFB00010 */  sw        $s0, 0x10($sp)
/* 7F420 800E5F70 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7F424 800E5F74 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7F428 800E5F78 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7F42C 800E5F7C 0C03A752 */  jal       is_ability_active
/* 7F430 800E5F80 2404000B */   addiu    $a0, $zero, 0xb
/* 7F434 800E5F84 1440000C */  bnez      $v0, .L800E5FB8
/* 7F438 800E5F88 24040001 */   addiu    $a0, $zero, 1
/* 7F43C 800E5F8C 8E0200E8 */  lw        $v0, 0xe8($s0)
/* 7F440 800E5F90 00420018 */  mult      $v0, $v0
/* 7F444 800E5F94 00001812 */  mflo      $v1
/* 7F448 800E5F98 8E0200EC */  lw        $v0, 0xec($s0)
/* 7F44C 800E5F9C 00000000 */  nop       
/* 7F450 800E5FA0 00420018 */  mult      $v0, $v0
/* 7F454 800E5FA4 00003012 */  mflo      $a2
/* 7F458 800E5FA8 00661021 */  addu      $v0, $v1, $a2
/* 7F45C 800E5FAC 28420BD2 */  slti      $v0, $v0, 0xbd2
/* 7F460 800E5FB0 50400001 */  beql      $v0, $zero, .L800E5FB8
/* 7F464 800E5FB4 24040002 */   addiu    $a0, $zero, 2
.L800E5FB8:
/* 7F468 800E5FB8 0C039769 */  jal       set_action_state
/* 7F46C 800E5FBC 00000000 */   nop      
/* 7F470 800E5FC0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7F474 800E5FC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7F478 800E5FC8 03E00008 */  jr        $ra
/* 7F47C 800E5FCC 27BD0018 */   addiu    $sp, $sp, 0x18
