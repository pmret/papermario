.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_131_render
/* 40CC64 E01226C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 40CC68 E01226C8 3C02E012 */  lui       $v0, %hi(func_E012270C)
/* 40CC6C E01226CC 2442270C */  addiu     $v0, $v0, %lo(func_E012270C)
/* 40CC70 E01226D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 40CC74 E01226D4 2402000A */  addiu     $v0, $zero, 0xa
/* 40CC78 E01226D8 AFA20014 */  sw        $v0, 0x14($sp)
/* 40CC7C E01226DC 2402002D */  addiu     $v0, $zero, 0x2d
/* 40CC80 E01226E0 AFA40018 */  sw        $a0, 0x18($sp)
/* 40CC84 E01226E4 27A40010 */  addiu     $a0, $sp, 0x10
/* 40CC88 E01226E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 40CC8C E01226EC 0C080120 */  jal       shim_queue_render_task
/* 40CC90 E01226F0 AFA20010 */   sw       $v0, 0x10($sp)
/* 40CC94 E01226F4 8C430000 */  lw        $v1, ($v0)
/* 40CC98 E01226F8 34630002 */  ori       $v1, $v1, 2
/* 40CC9C E01226FC AC430000 */  sw        $v1, ($v0)
/* 40CCA0 E0122700 8FBF0020 */  lw        $ra, 0x20($sp)
/* 40CCA4 E0122704 03E00008 */  jr        $ra
/* 40CCA8 E0122708 27BD0028 */   addiu    $sp, $sp, 0x28
