.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel BindNpcIdle
/* 1FFAC 80044BAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1FFB0 80044BB0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1FFB4 80044BB4 0080882D */  daddu     $s1, $a0, $zero
/* 1FFB8 80044BB8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1FFBC 80044BBC AFB3001C */  sw        $s3, 0x1c($sp)
/* 1FFC0 80044BC0 AFB20018 */  sw        $s2, 0x18($sp)
/* 1FFC4 80044BC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1FFC8 80044BC8 8E30000C */  lw        $s0, 0xc($s1)
/* 1FFCC 80044BCC 8E330148 */  lw        $s3, 0x148($s1)
/* 1FFD0 80044BD0 8E050000 */  lw        $a1, ($s0)
/* 1FFD4 80044BD4 0C0B1EAF */  jal       get_variable
/* 1FFD8 80044BD8 26100004 */   addiu    $s0, $s0, 4
/* 1FFDC 80044BDC 0040902D */  daddu     $s2, $v0, $zero
/* 1FFE0 80044BE0 8E050000 */  lw        $a1, ($s0)
/* 1FFE4 80044BE4 0C0B1EAF */  jal       get_variable
/* 1FFE8 80044BE8 0220202D */   daddu    $a0, $s1, $zero
/* 1FFEC 80044BEC 0040802D */  daddu     $s0, $v0, $zero
/* 1FFF0 80044BF0 2402FFFF */  addiu     $v0, $zero, -1
/* 1FFF4 80044BF4 16420002 */  bne       $s2, $v0, .L80044C00
/* 1FFF8 80044BF8 00000000 */   nop      
/* 1FFFC 80044BFC 86720008 */  lh        $s2, 8($s3)
.L80044C00:
/* 20000 80044C00 0C00FB3A */  jal       get_enemy
/* 20004 80044C04 0240202D */   daddu    $a0, $s2, $zero
/* 20008 80044C08 AC500024 */  sw        $s0, 0x24($v0)
/* 2000C 80044C0C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 20010 80044C10 8FB3001C */  lw        $s3, 0x1c($sp)
/* 20014 80044C14 8FB20018 */  lw        $s2, 0x18($sp)
/* 20018 80044C18 8FB10014 */  lw        $s1, 0x14($sp)
/* 2001C 80044C1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20020 80044C20 24020002 */  addiu     $v0, $zero, 2
/* 20024 80044C24 03E00008 */  jr        $ra
/* 20028 80044C28 27BD0028 */   addiu    $sp, $sp, 0x28
