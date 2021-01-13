.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EnableIdleScript
/* 1A742C 80278B4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1A7430 80278B50 AFB20018 */  sw        $s2, 0x18($sp)
/* 1A7434 80278B54 0080902D */  daddu     $s2, $a0, $zero
/* 1A7438 80278B58 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1A743C 80278B5C AFB10014 */  sw        $s1, 0x14($sp)
/* 1A7440 80278B60 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A7444 80278B64 8E51000C */  lw        $s1, 0xc($s2)
/* 1A7448 80278B68 8E250000 */  lw        $a1, ($s1)
/* 1A744C 80278B6C 0C0B1EAF */  jal       get_variable
/* 1A7450 80278B70 26310004 */   addiu    $s1, $s1, 4
/* 1A7454 80278B74 0040802D */  daddu     $s0, $v0, $zero
/* 1A7458 80278B78 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1A745C 80278B7C 16020002 */  bne       $s0, $v0, .L80278B88
/* 1A7460 80278B80 00000000 */   nop
/* 1A7464 80278B84 8E500148 */  lw        $s0, 0x148($s2)
.L80278B88:
/* 1A7468 80278B88 8E250000 */  lw        $a1, ($s1)
/* 1A746C 80278B8C 0C0B1EAF */  jal       get_variable
/* 1A7470 80278B90 0240202D */   daddu    $a0, $s2, $zero
/* 1A7474 80278B94 0200202D */  daddu     $a0, $s0, $zero
/* 1A7478 80278B98 0C09A75B */  jal       get_actor
/* 1A747C 80278B9C 0040802D */   daddu    $s0, $v0, $zero
/* 1A7480 80278BA0 0040882D */  daddu     $s1, $v0, $zero
/* 1A7484 80278BA4 8E2401D0 */  lw        $a0, 0x1d0($s1)
/* 1A7488 80278BA8 10800016 */  beqz      $a0, .L80278C04
/* 1A748C 80278BAC 00000000 */   nop
/* 1A7490 80278BB0 12000012 */  beqz      $s0, .L80278BFC
/* 1A7494 80278BB4 00000000 */   nop
/* 1A7498 80278BB8 1E000006 */  bgtz      $s0, .L80278BD4
/* 1A749C 80278BBC 24020001 */   addiu    $v0, $zero, 1
/* 1A74A0 80278BC0 2402FFFF */  addiu     $v0, $zero, -1
/* 1A74A4 80278BC4 12020007 */  beq       $s0, $v0, .L80278BE4
/* 1A74A8 80278BC8 00000000 */   nop
/* 1A74AC 80278BCC 0809E301 */  j         .L80278C04
/* 1A74B0 80278BD0 00000000 */   nop
.L80278BD4:
/* 1A74B4 80278BD4 12020005 */  beq       $s0, $v0, .L80278BEC
/* 1A74B8 80278BD8 00000000 */   nop
/* 1A74BC 80278BDC 0809E301 */  j         .L80278C04
/* 1A74C0 80278BE0 00000000 */   nop
.L80278BE4:
/* 1A74C4 80278BE4 0C0B0F41 */  jal       restart_script
/* 1A74C8 80278BE8 00000000 */   nop
.L80278BEC:
/* 1A74CC 80278BEC 0C0B1123 */  jal       resume_all_script
/* 1A74D0 80278BF0 8E2401E0 */   lw       $a0, 0x1e0($s1)
/* 1A74D4 80278BF4 0809E301 */  j         .L80278C04
/* 1A74D8 80278BF8 00000000 */   nop
.L80278BFC:
/* 1A74DC 80278BFC 0C0B1108 */  jal       suspend_all_script
/* 1A74E0 80278C00 8E2401E0 */   lw       $a0, 0x1e0($s1)
.L80278C04:
/* 1A74E4 80278C04 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1A74E8 80278C08 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A74EC 80278C0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A74F0 80278C10 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A74F4 80278C14 24020002 */  addiu     $v0, $zero, 2
/* 1A74F8 80278C18 03E00008 */  jr        $ra
/* 1A74FC 80278C1C 27BD0020 */   addiu    $sp, $sp, 0x20
