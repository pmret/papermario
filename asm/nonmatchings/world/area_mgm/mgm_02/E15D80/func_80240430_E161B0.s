.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240430_E161B0
/* E161B0 80240430 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E161B4 80240434 2402002D */  addiu     $v0, $zero, 0x2d
/* E161B8 80240438 AFA20010 */  sw        $v0, 0x10($sp)
/* E161BC 8024043C 3C028024 */  lui       $v0, %hi(func_80240000_E15D80)
/* E161C0 80240440 24420000 */  addiu     $v0, $v0, %lo(func_80240000_E15D80)
/* E161C4 80240444 27A40010 */  addiu     $a0, $sp, 0x10
/* E161C8 80240448 AFBF0020 */  sw        $ra, 0x20($sp)
/* E161CC 8024044C AFA00018 */  sw        $zero, 0x18($sp)
/* E161D0 80240450 AFA2001C */  sw        $v0, 0x1c($sp)
/* E161D4 80240454 0C047644 */  jal       queue_render_task
/* E161D8 80240458 AFA00014 */   sw       $zero, 0x14($sp)
/* E161DC 8024045C 8FBF0020 */  lw        $ra, 0x20($sp)
/* E161E0 80240460 03E00008 */  jr        $ra
/* E161E4 80240464 27BD0028 */   addiu    $sp, $sp, 0x28
