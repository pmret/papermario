.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00284E8
/* 33D2D8 E00284E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 33D2DC E00284EC 3C02E003 */  lui       $v0, %hi(func_E002852C)
/* 33D2E0 E00284F0 2442852C */  addiu     $v0, $v0, %lo(func_E002852C)
/* 33D2E4 E00284F4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 33D2E8 E00284F8 2402002D */  addiu     $v0, $zero, 0x2d
/* 33D2EC E00284FC AFA40018 */  sw        $a0, 0x18($sp)
/* 33D2F0 E0028500 27A40010 */  addiu     $a0, $sp, 0x10
/* 33D2F4 E0028504 AFBF0020 */  sw        $ra, 0x20($sp)
/* 33D2F8 E0028508 AFA00014 */  sw        $zero, 0x14($sp)
/* 33D2FC E002850C 0C080120 */  jal       shim_queue_render_task
/* 33D300 E0028510 AFA20010 */   sw       $v0, 0x10($sp)
/* 33D304 E0028514 8C430000 */  lw        $v1, ($v0)
/* 33D308 E0028518 34630002 */  ori       $v1, $v1, 2
/* 33D30C E002851C AC430000 */  sw        $v1, ($v0)
/* 33D310 E0028520 8FBF0020 */  lw        $ra, 0x20($sp)
/* 33D314 E0028524 03E00008 */  jr        $ra
/* 33D318 E0028528 27BD0028 */   addiu    $sp, $sp, 0x28
