.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_all_effects
/* 358E0 8005A4E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 358E4 8005A4E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 358E8 8005A4E8 0000902D */  daddu     $s2, $zero, $zero
/* 358EC 8005A4EC AFB10014 */  sw        $s1, 0x14($sp)
/* 358F0 8005A4F0 3C11800B */  lui       $s1, 0x800b
/* 358F4 8005A4F4 26314398 */  addiu     $s1, $s1, 0x4398
/* 358F8 8005A4F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 358FC 8005A4FC AFB00010 */  sw        $s0, 0x10($sp)
.L8005A500:
/* 35900 8005A500 8E300000 */  lw        $s0, ($s1)
/* 35904 8005A504 5200000E */  beql      $s0, $zero, .L8005A540
/* 35908 8005A508 26520001 */   addiu    $s2, $s2, 1
/* 3590C 8005A50C 8E020000 */  lw        $v0, ($s0)
/* 35910 8005A510 30420004 */  andi      $v0, $v0, 4
/* 35914 8005A514 5040000A */  beql      $v0, $zero, .L8005A540
/* 35918 8005A518 26520001 */   addiu    $s2, $s2, 1
/* 3591C 8005A51C 8E04000C */  lw        $a0, 0xc($s0)
/* 35920 8005A520 10800003 */  beqz      $a0, .L8005A530
/* 35924 8005A524 00000000 */   nop      
/* 35928 8005A528 0C00AB1E */  jal       general_heap_free
/* 3592C 8005A52C 00000000 */   nop      
.L8005A530:
/* 35930 8005A530 0C00AB1E */  jal       general_heap_free
/* 35934 8005A534 0200202D */   daddu    $a0, $s0, $zero
/* 35938 8005A538 AE200000 */  sw        $zero, ($s1)
/* 3593C 8005A53C 26520001 */  addiu     $s2, $s2, 1
.L8005A540:
/* 35940 8005A540 2A420060 */  slti      $v0, $s2, 0x60
/* 35944 8005A544 1440FFEE */  bnez      $v0, .L8005A500
/* 35948 8005A548 26310004 */   addiu    $s1, $s1, 4
/* 3594C 8005A54C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 35950 8005A550 8FB20018 */  lw        $s2, 0x18($sp)
/* 35954 8005A554 8FB10014 */  lw        $s1, 0x14($sp)
/* 35958 8005A558 8FB00010 */  lw        $s0, 0x10($sp)
/* 3595C 8005A55C 03E00008 */  jr        $ra
/* 35960 8005A560 27BD0020 */   addiu    $sp, $sp, 0x20
