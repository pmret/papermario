.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_43_render
/* 35E58C E0056B8C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 35E590 E0056B90 3C02E005 */  lui       $v0, %hi(fx_43_appendGfx)
/* 35E594 E0056B94 24426BD0 */  addiu     $v0, $v0, %lo(fx_43_appendGfx)
/* 35E598 E0056B98 AFA2001C */  sw        $v0, 0x1c($sp)
/* 35E59C E0056B9C 2402002D */  addiu     $v0, $zero, 0x2d
/* 35E5A0 E0056BA0 AFA40018 */  sw        $a0, 0x18($sp)
/* 35E5A4 E0056BA4 27A40010 */  addiu     $a0, $sp, 0x10
/* 35E5A8 E0056BA8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 35E5AC E0056BAC AFA00014 */  sw        $zero, 0x14($sp)
/* 35E5B0 E0056BB0 0C080120 */  jal       shim_queue_render_task
/* 35E5B4 E0056BB4 AFA20010 */   sw       $v0, 0x10($sp)
/* 35E5B8 E0056BB8 8C430000 */  lw        $v1, ($v0)
/* 35E5BC E0056BBC 34630002 */  ori       $v1, $v1, 2
/* 35E5C0 E0056BC0 AC430000 */  sw        $v1, ($v0)
/* 35E5C4 E0056BC4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 35E5C8 E0056BC8 03E00008 */  jr        $ra
/* 35E5CC E0056BCC 27BD0028 */   addiu    $sp, $sp, 0x28
