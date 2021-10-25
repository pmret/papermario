.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_31_render
/* 352A34 E003E5F4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 352A38 E003E5F8 3C02E004 */  lui       $v0, %hi(fx_31_appendGfx)
/* 352A3C E003E5FC 2442E638 */  addiu     $v0, $v0, %lo(fx_31_appendGfx)
/* 352A40 E003E600 AFA2001C */  sw        $v0, 0x1c($sp)
/* 352A44 E003E604 2402002D */  addiu     $v0, $zero, 0x2d
/* 352A48 E003E608 AFA40018 */  sw        $a0, 0x18($sp)
/* 352A4C E003E60C 27A40010 */  addiu     $a0, $sp, 0x10
/* 352A50 E003E610 AFBF0020 */  sw        $ra, 0x20($sp)
/* 352A54 E003E614 AFA00014 */  sw        $zero, 0x14($sp)
/* 352A58 E003E618 0C080120 */  jal       shim_queue_render_task
/* 352A5C E003E61C AFA20010 */   sw       $v0, 0x10($sp)
/* 352A60 E003E620 8C430000 */  lw        $v1, ($v0)
/* 352A64 E003E624 34630002 */  ori       $v1, $v1, 2
/* 352A68 E003E628 AC430000 */  sw        $v1, ($v0)
/* 352A6C E003E62C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 352A70 E003E630 03E00008 */  jr        $ra
/* 352A74 E003E634 27BD0028 */   addiu    $sp, $sp, 0x28
