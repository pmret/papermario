.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005C2B4
/* 3611F4 E005C2B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3611F8 E005C2B8 3C02E006 */  lui       $v0, %hi(func_E005C2F8)
/* 3611FC E005C2BC 2442C2F8 */  addiu     $v0, $v0, %lo(func_E005C2F8)
/* 361200 E005C2C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 361204 E005C2C4 24020028 */  addiu     $v0, $zero, 0x28
/* 361208 E005C2C8 AFA40018 */  sw        $a0, 0x18($sp)
/* 36120C E005C2CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 361210 E005C2D0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 361214 E005C2D4 AFA00014 */  sw        $zero, 0x14($sp)
/* 361218 E005C2D8 0C080120 */  jal       shim_queue_render_task
/* 36121C E005C2DC AFA20010 */   sw       $v0, 0x10($sp)
/* 361220 E005C2E0 8C430000 */  lw        $v1, ($v0)
/* 361224 E005C2E4 34630002 */  ori       $v1, $v1, 2
/* 361228 E005C2E8 AC430000 */  sw        $v1, ($v0)
/* 36122C E005C2EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 361230 E005C2F0 03E00008 */  jr        $ra
/* 361234 E005C2F4 27BD0028 */   addiu    $sp, $sp, 0x28
