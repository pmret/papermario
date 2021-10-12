.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_114_render
/* 3DE90C E00E490C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3DE910 E00E4910 3C02E00E */  lui       $v0, %hi(fx_114_appendGfx)
/* 3DE914 E00E4914 2442495C */  addiu     $v0, $v0, %lo(fx_114_appendGfx)
/* 3DE918 E00E4918 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3DE91C E00E491C 24020007 */  addiu     $v0, $zero, 7
/* 3DE920 E00E4920 AFA20014 */  sw        $v0, 0x14($sp)
/* 3DE924 E00E4924 2402002D */  addiu     $v0, $zero, 0x2d
/* 3DE928 E00E4928 AFA40018 */  sw        $a0, 0x18($sp)
/* 3DE92C E00E492C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DE930 E00E4930 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3DE934 E00E4934 0C080120 */  jal       shim_queue_render_task
/* 3DE938 E00E4938 AFA20010 */   sw       $v0, 0x10($sp)
/* 3DE93C E00E493C 8C430000 */  lw        $v1, ($v0)
/* 3DE940 E00E4940 34630002 */  ori       $v1, $v1, 2
/* 3DE944 E00E4944 AC430000 */  sw        $v1, ($v0)
/* 3DE948 E00E4948 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3DE94C E00E494C 03E00008 */  jr        $ra
/* 3DE950 E00E4950 27BD0028 */   addiu    $sp, $sp, 0x28
