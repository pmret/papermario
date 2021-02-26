.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AF98
/* 6398 8002AF98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 639C 8002AF9C 24040006 */  addiu     $a0, $zero, 6
/* 63A0 8002AFA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 63A4 8002AFA4 3C10800E */  lui       $s0, %hi(D_800D95C8)
/* 63A8 8002AFA8 261095C8 */  addiu     $s0, $s0, %lo(D_800D95C8)
/* 63AC 8002AFAC 0200282D */  daddu     $a1, $s0, $zero
/* 63B0 8002AFB0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 63B4 8002AFB4 0C00AE0A */  jal       func_8002B828
/* 63B8 8002AFB8 24060080 */   addiu    $a2, $zero, 0x80
/* 63BC 8002AFBC 0C00ABCC */  jal       func_8002AF30
/* 63C0 8002AFC0 00000000 */   nop
/* 63C4 8002AFC4 1440000D */  bnez      $v0, .L8002AFFC
/* 63C8 8002AFC8 24020001 */   addiu    $v0, $zero, 1
/* 63CC 8002AFCC 24040007 */  addiu     $a0, $zero, 7
/* 63D0 8002AFD0 0200282D */  daddu     $a1, $s0, $zero
/* 63D4 8002AFD4 0C00AE0A */  jal       func_8002B828
/* 63D8 8002AFD8 24060080 */   addiu    $a2, $zero, 0x80
/* 63DC 8002AFDC 0C00ABCC */  jal       func_8002AF30
/* 63E0 8002AFE0 00000000 */   nop
/* 63E4 8002AFE4 14400005 */  bnez      $v0, .L8002AFFC
/* 63E8 8002AFE8 24020001 */   addiu    $v0, $zero, 1
/* 63EC 8002AFEC 0200202D */  daddu     $a0, $s0, $zero
/* 63F0 8002AFF0 0C019250 */  jal       func_80064940
/* 63F4 8002AFF4 24050080 */   addiu    $a1, $zero, 0x80
/* 63F8 8002AFF8 0000102D */  daddu     $v0, $zero, $zero
.L8002AFFC:
/* 63FC 8002AFFC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6400 8002B000 8FB00010 */  lw        $s0, 0x10($sp)
/* 6404 8002B004 03E00008 */  jr        $ra
/* 6408 8002B008 27BD0018 */   addiu    $sp, $sp, 0x18
