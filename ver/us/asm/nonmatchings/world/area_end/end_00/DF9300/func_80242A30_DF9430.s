.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A30_DF9430
/* DF9430 80242A30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DF9434 80242A34 AFB10014 */  sw        $s1, 0x14($sp)
/* DF9438 80242A38 0080882D */  daddu     $s1, $a0, $zero
/* DF943C 80242A3C AFBF001C */  sw        $ra, 0x1c($sp)
/* DF9440 80242A40 AFB20018 */  sw        $s2, 0x18($sp)
/* DF9444 80242A44 AFB00010 */  sw        $s0, 0x10($sp)
/* DF9448 80242A48 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DF944C 80242A4C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DF9450 80242A50 8E30000C */  lw        $s0, 0xc($s1)
/* DF9454 80242A54 8E050000 */  lw        $a1, ($s0)
/* DF9458 80242A58 0C0B1EAF */  jal       evt_get_variable
/* DF945C 80242A5C 26100004 */   addiu    $s0, $s0, 4
/* DF9460 80242A60 8E050000 */  lw        $a1, ($s0)
/* DF9464 80242A64 26100004 */  addiu     $s0, $s0, 4
/* DF9468 80242A68 0220202D */  daddu     $a0, $s1, $zero
/* DF946C 80242A6C 0C0B210B */  jal       evt_get_float_variable
/* DF9470 80242A70 0040902D */   daddu    $s2, $v0, $zero
/* DF9474 80242A74 8E050000 */  lw        $a1, ($s0)
/* DF9478 80242A78 26100004 */  addiu     $s0, $s0, 4
/* DF947C 80242A7C 0220202D */  daddu     $a0, $s1, $zero
/* DF9480 80242A80 0C0B210B */  jal       evt_get_float_variable
/* DF9484 80242A84 46000586 */   mov.s    $f22, $f0
/* DF9488 80242A88 0220202D */  daddu     $a0, $s1, $zero
/* DF948C 80242A8C 8E050000 */  lw        $a1, ($s0)
/* DF9490 80242A90 0C0B210B */  jal       evt_get_float_variable
/* DF9494 80242A94 46000506 */   mov.s    $f20, $f0
/* DF9498 80242A98 8E42000C */  lw        $v0, 0xc($s2)
/* DF949C 80242A9C E4560008 */  swc1      $f22, 8($v0)
/* DF94A0 80242AA0 8E42000C */  lw        $v0, 0xc($s2)
/* DF94A4 80242AA4 E454000C */  swc1      $f20, 0xc($v0)
/* DF94A8 80242AA8 8E43000C */  lw        $v1, 0xc($s2)
/* DF94AC 80242AAC E4600010 */  swc1      $f0, 0x10($v1)
/* DF94B0 80242AB0 8FBF001C */  lw        $ra, 0x1c($sp)
/* DF94B4 80242AB4 8FB20018 */  lw        $s2, 0x18($sp)
/* DF94B8 80242AB8 8FB10014 */  lw        $s1, 0x14($sp)
/* DF94BC 80242ABC 8FB00010 */  lw        $s0, 0x10($sp)
/* DF94C0 80242AC0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DF94C4 80242AC4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DF94C8 80242AC8 24020002 */  addiu     $v0, $zero, 2
/* DF94CC 80242ACC 03E00008 */  jr        $ra
/* DF94D0 80242AD0 27BD0030 */   addiu    $sp, $sp, 0x30
