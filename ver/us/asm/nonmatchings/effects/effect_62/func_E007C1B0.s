.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007C1B0
/* 37D640 E007C1B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 37D644 E007C1B4 3C02E008 */  lui       $v0, %hi(func_E007C1F4)
/* 37D648 E007C1B8 2442C1F4 */  addiu     $v0, $v0, %lo(func_E007C1F4)
/* 37D64C E007C1BC AFA2001C */  sw        $v0, 0x1c($sp)
/* 37D650 E007C1C0 24020028 */  addiu     $v0, $zero, 0x28
/* 37D654 E007C1C4 AFA40018 */  sw        $a0, 0x18($sp)
/* 37D658 E007C1C8 27A40010 */  addiu     $a0, $sp, 0x10
/* 37D65C E007C1CC AFBF0020 */  sw        $ra, 0x20($sp)
/* 37D660 E007C1D0 AFA00014 */  sw        $zero, 0x14($sp)
/* 37D664 E007C1D4 0C080120 */  jal       shim_queue_render_task
/* 37D668 E007C1D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 37D66C E007C1DC 8C430000 */  lw        $v1, ($v0)
/* 37D670 E007C1E0 34630002 */  ori       $v1, $v1, 2
/* 37D674 E007C1E4 AC430000 */  sw        $v1, ($v0)
/* 37D678 E007C1E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 37D67C E007C1EC 03E00008 */  jr        $ra
/* 37D680 E007C1F0 27BD0028 */   addiu    $sp, $sp, 0x28
