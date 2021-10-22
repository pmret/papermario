.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_52_render
/* 36AAA8 E00681D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 36AAAC E00681DC AFBF0020 */  sw        $ra, 0x20($sp)
/* 36AAB0 E00681E0 8C83000C */  lw        $v1, 0xc($a0)
/* 36AAB4 E00681E4 3C02E007 */  lui       $v0, %hi(fx_52_appendGfx)
/* 36AAB8 E00681E8 24428234 */  addiu     $v0, $v0, %lo(fx_52_appendGfx)
/* 36AABC E00681EC AFA2001C */  sw        $v0, 0x1c($sp)
/* 36AAC0 E00681F0 2402000A */  addiu     $v0, $zero, 0xa
/* 36AAC4 E00681F4 AFA40018 */  sw        $a0, 0x18($sp)
/* 36AAC8 E00681F8 AFA20014 */  sw        $v0, 0x14($sp)
/* 36AACC E00681FC 8C620000 */  lw        $v0, ($v1)
/* 36AAD0 E0068200 14400003 */  bnez      $v0, .LE0068210
/* 36AAD4 E0068204 27A40010 */   addiu    $a0, $sp, 0x10
/* 36AAD8 E0068208 0801A085 */  j         .LE0068214
/* 36AADC E006820C 24020001 */   addiu    $v0, $zero, 1
.LE0068210:
/* 36AAE0 E0068210 2402002D */  addiu     $v0, $zero, 0x2d
.LE0068214:
/* 36AAE4 E0068214 0C080120 */  jal       shim_queue_render_task
/* 36AAE8 E0068218 AFA20010 */   sw       $v0, 0x10($sp)
/* 36AAEC E006821C 8C430000 */  lw        $v1, ($v0)
/* 36AAF0 E0068220 34630002 */  ori       $v1, $v1, 2
/* 36AAF4 E0068224 AC430000 */  sw        $v1, ($v0)
/* 36AAF8 E0068228 8FBF0020 */  lw        $ra, 0x20($sp)
/* 36AAFC E006822C 03E00008 */  jr        $ra
/* 36AB00 E0068230 27BD0028 */   addiu    $sp, $sp, 0x28
