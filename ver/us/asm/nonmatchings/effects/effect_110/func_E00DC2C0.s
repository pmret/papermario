.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DC2C0
/* 3D7D30 E00DC2C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D7D34 E00DC2C4 3C02E00E */  lui       $v0, %hi(func_E00DC304)
/* 3D7D38 E00DC2C8 2442C304 */  addiu     $v0, $v0, %lo(func_E00DC304)
/* 3D7D3C E00DC2CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D7D40 E00DC2D0 2402000A */  addiu     $v0, $zero, 0xa
/* 3D7D44 E00DC2D4 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D7D48 E00DC2D8 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D7D4C E00DC2DC AFA40018 */  sw        $a0, 0x18($sp)
/* 3D7D50 E00DC2E0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D7D54 E00DC2E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D7D58 E00DC2E8 0C080120 */  jal       shim_queue_render_task
/* 3D7D5C E00DC2EC AFA20010 */   sw       $v0, 0x10($sp)
/* 3D7D60 E00DC2F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D7D64 E00DC2F4 03E00008 */  jr        $ra
/* 3D7D68 E00DC2F8 27BD0028 */   addiu    $sp, $sp, 0x28
