.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_77_render
/* 396948 E009A398 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 39694C E009A39C 3C02E00A */  lui       $v0, %hi(fx_77_appendGfx)
/* 396950 E009A3A0 2442A3E0 */  addiu     $v0, $v0, %lo(fx_77_appendGfx)
/* 396954 E009A3A4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 396958 E009A3A8 2402FFF6 */  addiu     $v0, $zero, -0xa
/* 39695C E009A3AC AFA20014 */  sw        $v0, 0x14($sp)
/* 396960 E009A3B0 24020011 */  addiu     $v0, $zero, 0x11
/* 396964 E009A3B4 AFA40018 */  sw        $a0, 0x18($sp)
/* 396968 E009A3B8 27A40010 */  addiu     $a0, $sp, 0x10
/* 39696C E009A3BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 396970 E009A3C0 0C080120 */  jal       shim_queue_render_task
/* 396974 E009A3C4 AFA20010 */   sw       $v0, 0x10($sp)
/* 396978 E009A3C8 8C430000 */  lw        $v1, ($v0)
/* 39697C E009A3CC 34630002 */  ori       $v1, $v1, 2
/* 396980 E009A3D0 AC430000 */  sw        $v1, ($v0)
/* 396984 E009A3D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 396988 E009A3D8 03E00008 */  jr        $ra
/* 39698C E009A3DC 27BD0028 */   addiu    $sp, $sp, 0x28
