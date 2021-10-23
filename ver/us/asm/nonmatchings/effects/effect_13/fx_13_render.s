.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_13_render
/* 33022C E001A3FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 330230 E001A400 3C02E002 */  lui       $v0, %hi(fx_13_appendGfx)
/* 330234 E001A404 2442A440 */  addiu     $v0, $v0, %lo(fx_13_appendGfx)
/* 330238 E001A408 AFA2001C */  sw        $v0, 0x1c($sp)
/* 33023C E001A40C 2402002D */  addiu     $v0, $zero, 0x2d
/* 330240 E001A410 AFA40018 */  sw        $a0, 0x18($sp)
/* 330244 E001A414 27A40010 */  addiu     $a0, $sp, 0x10
/* 330248 E001A418 AFBF0020 */  sw        $ra, 0x20($sp)
/* 33024C E001A41C AFA00014 */  sw        $zero, 0x14($sp)
/* 330250 E001A420 0C080120 */  jal       shim_queue_render_task
/* 330254 E001A424 AFA20010 */   sw       $v0, 0x10($sp)
/* 330258 E001A428 8C430000 */  lw        $v1, ($v0)
/* 33025C E001A42C 34630002 */  ori       $v1, $v1, 2
/* 330260 E001A430 AC430000 */  sw        $v1, ($v0)
/* 330264 E001A434 8FBF0020 */  lw        $ra, 0x20($sp)
/* 330268 E001A438 03E00008 */  jr        $ra
/* 33026C E001A43C 27BD0028 */   addiu    $sp, $sp, 0x28
