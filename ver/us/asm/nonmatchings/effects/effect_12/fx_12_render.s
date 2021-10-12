.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_12_render
/* 32F8F8 E0018378 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32F8FC E001837C 3C02E002 */  lui       $v0, %hi(func_E00183D8)
/* 32F900 E0018380 244283D8 */  addiu     $v0, $v0, %lo(func_E00183D8)
/* 32F904 E0018384 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32F908 E0018388 24020028 */  addiu     $v0, $zero, 0x28
/* 32F90C E001838C AFA40018 */  sw        $a0, 0x18($sp)
/* 32F910 E0018390 27A40010 */  addiu     $a0, $sp, 0x10
/* 32F914 E0018394 AFBF0020 */  sw        $ra, 0x20($sp)
/* 32F918 E0018398 AFA00014 */  sw        $zero, 0x14($sp)
/* 32F91C E001839C 0C080120 */  jal       shim_queue_render_task
/* 32F920 E00183A0 AFA20010 */   sw       $v0, 0x10($sp)
/* 32F924 E00183A4 8C430000 */  lw        $v1, ($v0)
/* 32F928 E00183A8 34630002 */  ori       $v1, $v1, 2
/* 32F92C E00183AC AC430000 */  sw        $v1, ($v0)
/* 32F930 E00183B0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 32F934 E00183B4 03E00008 */  jr        $ra
/* 32F938 E00183B8 27BD0028 */   addiu    $sp, $sp, 0x28
