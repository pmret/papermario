.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DE260
/* 3D8980 E00DE260 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D8984 E00DE264 3C02E00E */  lui       $v0, %hi(func_E00DE2A8)
/* 3D8988 E00DE268 2442E2A8 */  addiu     $v0, $v0, %lo(func_E00DE2A8)
/* 3D898C E00DE26C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D8990 E00DE270 24020006 */  addiu     $v0, $zero, 6
/* 3D8994 E00DE274 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D8998 E00DE278 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D899C E00DE27C AFA40018 */  sw        $a0, 0x18($sp)
/* 3D89A0 E00DE280 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D89A4 E00DE284 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D89A8 E00DE288 0C080120 */  jal       shim_queue_render_task
/* 3D89AC E00DE28C AFA20010 */   sw       $v0, 0x10($sp)
/* 3D89B0 E00DE290 8C430000 */  lw        $v1, ($v0)
/* 3D89B4 E00DE294 34630002 */  ori       $v1, $v1, 2
/* 3D89B8 E00DE298 AC430000 */  sw        $v1, ($v0)
/* 3D89BC E00DE29C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D89C0 E00DE2A0 03E00008 */  jr        $ra
/* 3D89C4 E00DE2A4 27BD0028 */   addiu    $sp, $sp, 0x28
