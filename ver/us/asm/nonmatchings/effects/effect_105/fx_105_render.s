.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_105_render
/* 3D4BA4 E00D2234 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D4BA8 E00D2238 3C02E00D */  lui       $v0, %hi(fx_105_appendGfx)
/* 3D4BAC E00D223C 24422284 */  addiu     $v0, $v0, %lo(fx_105_appendGfx)
/* 3D4BB0 E00D2240 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D4BB4 E00D2244 2402000A */  addiu     $v0, $zero, 0xa
/* 3D4BB8 E00D2248 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D4BBC E00D224C 2402002D */  addiu     $v0, $zero, 0x2d
/* 3D4BC0 E00D2250 AFA40018 */  sw        $a0, 0x18($sp)
/* 3D4BC4 E00D2254 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D4BC8 E00D2258 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3D4BCC E00D225C 0C080120 */  jal       shim_queue_render_task
/* 3D4BD0 E00D2260 AFA20010 */   sw       $v0, 0x10($sp)
/* 3D4BD4 E00D2264 8C430000 */  lw        $v1, ($v0)
/* 3D4BD8 E00D2268 34630002 */  ori       $v1, $v1, 2
/* 3D4BDC E00D226C AC430000 */  sw        $v1, ($v0)
/* 3D4BE0 E00D2270 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3D4BE4 E00D2274 03E00008 */  jr        $ra
/* 3D4BE8 E00D2278 27BD0028 */   addiu    $sp, $sp, 0x28
