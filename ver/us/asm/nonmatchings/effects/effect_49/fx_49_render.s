.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_49_render
/* 3647A8 E00624A8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3647AC E00624AC 3C02E006 */  lui       $v0, %hi(func_E00624EC)
/* 3647B0 E00624B0 244224EC */  addiu     $v0, $v0, %lo(func_E00624EC)
/* 3647B4 E00624B4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3647B8 E00624B8 24020028 */  addiu     $v0, $zero, 0x28
/* 3647BC E00624BC AFA40018 */  sw        $a0, 0x18($sp)
/* 3647C0 E00624C0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3647C4 E00624C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3647C8 E00624C8 AFA00014 */  sw        $zero, 0x14($sp)
/* 3647CC E00624CC 0C080120 */  jal       shim_queue_render_task
/* 3647D0 E00624D0 AFA20010 */   sw       $v0, 0x10($sp)
/* 3647D4 E00624D4 8C430000 */  lw        $v1, ($v0)
/* 3647D8 E00624D8 34630002 */  ori       $v1, $v1, 2
/* 3647DC E00624DC AC430000 */  sw        $v1, ($v0)
/* 3647E0 E00624E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3647E4 E00624E4 03E00008 */  jr        $ra
/* 3647E8 E00624E8 27BD0028 */   addiu    $sp, $sp, 0x28
