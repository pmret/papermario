.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetPartEventFlags
/* 19BD68 8026D488 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19BD6C 8026D48C AFB20018 */  sw        $s2, 0x18($sp)
/* 19BD70 8026D490 0080902D */  daddu     $s2, $a0, $zero
/* 19BD74 8026D494 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19BD78 8026D498 AFB10014 */  sw        $s1, 0x14($sp)
/* 19BD7C 8026D49C AFB00010 */  sw        $s0, 0x10($sp)
/* 19BD80 8026D4A0 8E51000C */  lw        $s1, 0xc($s2)
/* 19BD84 8026D4A4 8E250000 */  lw        $a1, ($s1)
/* 19BD88 8026D4A8 0C0B1EAF */  jal       get_variable
/* 19BD8C 8026D4AC 26310004 */   addiu    $s1, $s1, 4
/* 19BD90 8026D4B0 0040802D */  daddu     $s0, $v0, $zero
/* 19BD94 8026D4B4 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19BD98 8026D4B8 16020002 */  bne       $s0, $v0, .L8026D4C4
/* 19BD9C 8026D4BC 00000000 */   nop      
/* 19BDA0 8026D4C0 8E500148 */  lw        $s0, 0x148($s2)
.L8026D4C4:
/* 19BDA4 8026D4C4 8E250000 */  lw        $a1, ($s1)
/* 19BDA8 8026D4C8 26310004 */  addiu     $s1, $s1, 4
/* 19BDAC 8026D4CC 0C0B1EAF */  jal       get_variable
/* 19BDB0 8026D4D0 0240202D */   daddu    $a0, $s2, $zero
/* 19BDB4 8026D4D4 0200202D */  daddu     $a0, $s0, $zero
/* 19BDB8 8026D4D8 8E310000 */  lw        $s1, ($s1)
/* 19BDBC 8026D4DC 0C09A75B */  jal       get_actor
/* 19BDC0 8026D4E0 0040802D */   daddu    $s0, $v0, $zero
/* 19BDC4 8026D4E4 0040202D */  daddu     $a0, $v0, $zero
/* 19BDC8 8026D4E8 0C099117 */  jal       get_actor_part
/* 19BDCC 8026D4EC 0200282D */   daddu    $a1, $s0, $zero
/* 19BDD0 8026D4F0 0240202D */  daddu     $a0, $s2, $zero
/* 19BDD4 8026D4F4 8C46007C */  lw        $a2, 0x7c($v0)
/* 19BDD8 8026D4F8 0C0B2026 */  jal       set_variable
/* 19BDDC 8026D4FC 0220282D */   daddu    $a1, $s1, $zero
/* 19BDE0 8026D500 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19BDE4 8026D504 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BDE8 8026D508 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BDEC 8026D50C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BDF0 8026D510 24020002 */  addiu     $v0, $zero, 2
/* 19BDF4 8026D514 03E00008 */  jr        $ra
/* 19BDF8 8026D518 27BD0020 */   addiu    $sp, $sp, 0x20
