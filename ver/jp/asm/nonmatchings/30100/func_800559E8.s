.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800559E8
/* 30DE8 800559E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 30DEC 800559EC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 30DF0 800559F0 4485A000 */  mtc1      $a1, $f20
/* 30DF4 800559F4 27A50010 */  addiu     $a1, $sp, 0x10
/* 30DF8 800559F8 27A60014 */  addiu     $a2, $sp, 0x14
/* 30DFC 800559FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 30E00 80055A00 0C015666 */  jal       func_80055998
/* 30E04 80055A04 AFB00018 */   sw       $s0, 0x18($sp)
/* 30E08 80055A08 0040802D */  daddu     $s0, $v0, $zero
/* 30E0C 80055A0C 16000006 */  bnez      $s0, .L80055A28
/* 30E10 80055A10 0200102D */   daddu    $v0, $s0, $zero
/* 30E14 80055A14 8FA40014 */  lw        $a0, 0x14($sp)
/* 30E18 80055A18 4405A000 */  mfc1      $a1, $f20
/* 30E1C 80055A1C 0C014108 */  jal       func_80050420
/* 30E20 80055A20 00000000 */   nop
/* 30E24 80055A24 0200102D */  daddu     $v0, $s0, $zero
.L80055A28:
/* 30E28 80055A28 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30E2C 80055A2C 8FB00018 */  lw        $s0, 0x18($sp)
/* 30E30 80055A30 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 30E34 80055A34 03E00008 */  jr        $ra
/* 30E38 80055A38 27BD0028 */   addiu    $sp, $sp, 0x28
