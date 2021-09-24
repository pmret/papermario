.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D0448
/* 3D4268 E00D0448 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D426C E00D044C 3C02E00D */  lui       $v0, %hi(func_E00D048C)
/* 3D4270 E00D0450 2442048C */  addiu     $v0, $v0, %lo(func_E00D048C)
/* 3D4274 E00D0454 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D4278 E00D0458 24020028 */  addiu     $v0, $zero, 0x28
/* 3D427C E00D045C AFA40018 */  sw        $a0, 0x18($sp)
/* 3D4280 E00D0460 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D4284 E00D0464 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D4288 E00D0468 AFA00014 */  sw        $zero, 0x14($sp)
/* 3D428C E00D046C 0C080120 */  jal       shim_queue_render_task
/* 3D4290 E00D0470 AFA20010 */   sw       $v0, 0x10($sp)
/* 3D4294 E00D0474 8C430000 */  lw        $v1, ($v0)
/* 3D4298 E00D0478 34630002 */  ori       $v1, $v1, 2
/* 3D429C E00D047C AC430000 */  sw        $v1, ($v0)
/* 3D42A0 E00D0480 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D42A4 E00D0484 03E00008 */  jr        $ra
/* 3D42A8 E00D0488 27BD0028 */   addiu    $sp, $sp, 0x28
