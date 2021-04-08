.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxRetraceWait
/* 3B770 80060370 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B774 80060374 AFB10044 */  sw        $s1, 0x44($sp)
/* 3B778 80060378 0080882D */  daddu     $s1, $a0, $zero
/* 3B77C 8006037C AFB00040 */  sw        $s0, 0x40($sp)
/* 3B780 80060380 27B00020 */  addiu     $s0, $sp, 0x20
/* 3B784 80060384 0200202D */  daddu     $a0, $s0, $zero
/* 3B788 80060388 27A50038 */  addiu     $a1, $sp, 0x38
/* 3B78C 8006038C AFBF0048 */  sw        $ra, 0x48($sp)
/* 3B790 80060390 0C019560 */  jal       osCreateMesgQueue
/* 3B794 80060394 24060001 */   addiu    $a2, $zero, 1
/* 3B798 80060398 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B79C 8006039C 0200282D */  daddu     $a1, $s0, $zero
/* 3B7A0 800603A0 0C017B8C */  jal       nuScAddClient
/* 3B7A4 800603A4 24060001 */   addiu    $a2, $zero, 1
/* 3B7A8 800603A8 12200007 */  beqz      $s1, .L800603C8
/* 3B7AC 800603AC 27A40020 */   addiu    $a0, $sp, 0x20
.L800603B0:
/* 3B7B0 800603B0 0000282D */  daddu     $a1, $zero, $zero
/* 3B7B4 800603B4 0C0195BC */  jal       osRecvMesg
/* 3B7B8 800603B8 24060001 */   addiu    $a2, $zero, 1
/* 3B7BC 800603BC 2631FFFF */  addiu     $s1, $s1, -1
/* 3B7C0 800603C0 1620FFFB */  bnez      $s1, .L800603B0
/* 3B7C4 800603C4 27A40020 */   addiu    $a0, $sp, 0x20
.L800603C8:
/* 3B7C8 800603C8 0C017BAF */  jal       nuScRemoveClient
/* 3B7CC 800603CC 27A40010 */   addiu    $a0, $sp, 0x10
/* 3B7D0 800603D0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 3B7D4 800603D4 8FB10044 */  lw        $s1, 0x44($sp)
/* 3B7D8 800603D8 8FB00040 */  lw        $s0, 0x40($sp)
/* 3B7DC 800603DC 03E00008 */  jr        $ra
/* 3B7E0 800603E0 27BD0050 */   addiu    $sp, $sp, 0x50
/* 3B7E4 800603E4 00000000 */  nop
/* 3B7E8 800603E8 00000000 */  nop
/* 3B7EC 800603EC 00000000 */  nop
