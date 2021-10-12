.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_83_render
/* 3A58A8 E00A6358 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A58AC E00A635C 3C02E00A */  lui       $v0, %hi(func_E00A63A4)
/* 3A58B0 E00A6360 244263A4 */  addiu     $v0, $v0, %lo(func_E00A63A4)
/* 3A58B4 E00A6364 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A58B8 E00A6368 2402002D */  addiu     $v0, $zero, 0x2d
/* 3A58BC E00A636C AFA40018 */  sw        $a0, 0x18($sp)
/* 3A58C0 E00A6370 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A58C4 E00A6374 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A58C8 E00A6378 AFA00014 */  sw        $zero, 0x14($sp)
/* 3A58CC E00A637C 0C080120 */  jal       shim_queue_render_task
/* 3A58D0 E00A6380 AFA20010 */   sw       $v0, 0x10($sp)
/* 3A58D4 E00A6384 8C430000 */  lw        $v1, ($v0)
/* 3A58D8 E00A6388 34630002 */  ori       $v1, $v1, 2
/* 3A58DC E00A638C AC430000 */  sw        $v1, ($v0)
/* 3A58E0 E00A6390 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3A58E4 E00A6394 03E00008 */  jr        $ra
/* 3A58E8 E00A6398 27BD0028 */   addiu    $sp, $sp, 0x28
