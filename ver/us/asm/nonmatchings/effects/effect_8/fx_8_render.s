.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_8_render
/* 32CC50 E00104B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32CC54 E00104B4 3C02E001 */  lui       $v0, %hi(func_E0010510)
/* 32CC58 E00104B8 24420510 */  addiu     $v0, $v0, %lo(func_E0010510)
/* 32CC5C E00104BC AFA2001C */  sw        $v0, 0x1c($sp)
/* 32CC60 E00104C0 24020028 */  addiu     $v0, $zero, 0x28
/* 32CC64 E00104C4 AFA40018 */  sw        $a0, 0x18($sp)
/* 32CC68 E00104C8 27A40010 */  addiu     $a0, $sp, 0x10
/* 32CC6C E00104CC AFBF0020 */  sw        $ra, 0x20($sp)
/* 32CC70 E00104D0 AFA00014 */  sw        $zero, 0x14($sp)
/* 32CC74 E00104D4 0C080120 */  jal       shim_queue_render_task
/* 32CC78 E00104D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 32CC7C E00104DC 8C430000 */  lw        $v1, ($v0)
/* 32CC80 E00104E0 34630002 */  ori       $v1, $v1, 2
/* 32CC84 E00104E4 AC430000 */  sw        $v1, ($v0)
/* 32CC88 E00104E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 32CC8C E00104EC 03E00008 */  jr        $ra
/* 32CC90 E00104F0 27BD0028 */   addiu    $sp, $sp, 0x28
