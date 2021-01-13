.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055D38
/* 31138 80055D38 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3113C 80055D3C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 31140 80055D40 4485A000 */  mtc1      $a1, $f20
/* 31144 80055D44 27A50010 */  addiu     $a1, $sp, 0x10
/* 31148 80055D48 27A60014 */  addiu     $a2, $sp, 0x14
/* 3114C 80055D4C AFBF001C */  sw        $ra, 0x1c($sp)
/* 31150 80055D50 0C01573A */  jal       func_80055CE8
/* 31154 80055D54 AFB00018 */   sw       $s0, 0x18($sp)
/* 31158 80055D58 0040802D */  daddu     $s0, $v0, $zero
/* 3115C 80055D5C 16000006 */  bnez      $s0, .L80055D78
/* 31160 80055D60 0200102D */   daddu    $v0, $s0, $zero
/* 31164 80055D64 8FA40014 */  lw        $a0, 0x14($sp)
/* 31168 80055D68 4405A000 */  mfc1      $a1, $f20
/* 3116C 80055D6C 0C0141DC */  jal       func_80050770
/* 31170 80055D70 00000000 */   nop
/* 31174 80055D74 0200102D */  daddu     $v0, $s0, $zero
.L80055D78:
/* 31178 80055D78 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3117C 80055D7C 8FB00018 */  lw        $s0, 0x18($sp)
/* 31180 80055D80 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 31184 80055D84 03E00008 */  jr        $ra
/* 31188 80055D88 27BD0028 */   addiu    $sp, $sp, 0x28
