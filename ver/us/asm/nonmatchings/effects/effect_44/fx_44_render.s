.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_44_render
/* 35EDB0 E0058490 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 35EDB4 E0058494 3C02E006 */  lui       $v0, %hi(func_E00584D4)
/* 35EDB8 E0058498 244284D4 */  addiu     $v0, $v0, %lo(func_E00584D4)
/* 35EDBC E005849C AFA2001C */  sw        $v0, 0x1c($sp)
/* 35EDC0 E00584A0 2402002D */  addiu     $v0, $zero, 0x2d
/* 35EDC4 E00584A4 AFA40018 */  sw        $a0, 0x18($sp)
/* 35EDC8 E00584A8 27A40010 */  addiu     $a0, $sp, 0x10
/* 35EDCC E00584AC AFBF0020 */  sw        $ra, 0x20($sp)
/* 35EDD0 E00584B0 AFA00014 */  sw        $zero, 0x14($sp)
/* 35EDD4 E00584B4 0C080120 */  jal       shim_queue_render_task
/* 35EDD8 E00584B8 AFA20010 */   sw       $v0, 0x10($sp)
/* 35EDDC E00584BC 8C430000 */  lw        $v1, ($v0)
/* 35EDE0 E00584C0 34630002 */  ori       $v1, $v1, 2
/* 35EDE4 E00584C4 AC430000 */  sw        $v1, ($v0)
/* 35EDE8 E00584C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 35EDEC E00584CC 03E00008 */  jr        $ra
/* 35EDF0 E00584D0 27BD0028 */   addiu    $sp, $sp, 0x28
