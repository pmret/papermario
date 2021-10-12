.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_24_render
/* 342B64 E0030A24 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 342B68 E0030A28 3C02E003 */  lui       $v0, %hi(func_E0030A68)
/* 342B6C E0030A2C 24420A68 */  addiu     $v0, $v0, %lo(func_E0030A68)
/* 342B70 E0030A30 AFA2001C */  sw        $v0, 0x1c($sp)
/* 342B74 E0030A34 2402002D */  addiu     $v0, $zero, 0x2d
/* 342B78 E0030A38 AFA40018 */  sw        $a0, 0x18($sp)
/* 342B7C E0030A3C 27A40010 */  addiu     $a0, $sp, 0x10
/* 342B80 E0030A40 AFBF0020 */  sw        $ra, 0x20($sp)
/* 342B84 E0030A44 AFA00014 */  sw        $zero, 0x14($sp)
/* 342B88 E0030A48 0C080120 */  jal       shim_queue_render_task
/* 342B8C E0030A4C AFA20010 */   sw       $v0, 0x10($sp)
/* 342B90 E0030A50 8C430000 */  lw        $v1, ($v0)
/* 342B94 E0030A54 34630002 */  ori       $v1, $v1, 2
/* 342B98 E0030A58 AC430000 */  sw        $v1, ($v0)
/* 342B9C E0030A5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 342BA0 E0030A60 03E00008 */  jr        $ra
/* 342BA4 E0030A64 27BD0028 */   addiu    $sp, $sp, 0x28
