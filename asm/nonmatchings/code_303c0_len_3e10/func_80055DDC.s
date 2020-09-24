.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055DDC
/* 311DC 80055DDC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 311E0 80055DE0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 311E4 80055DE4 00A0882D */  daddu     $s1, $a1, $zero
/* 311E8 80055DE8 27A50010 */  addiu     $a1, $sp, 0x10
/* 311EC 80055DEC 27A60014 */  addiu     $a2, $sp, 0x14
/* 311F0 80055DF0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 311F4 80055DF4 0C01573A */  jal       func_80055CE8
/* 311F8 80055DF8 AFB00018 */   sw       $s0, 0x18($sp)
/* 311FC 80055DFC 0040802D */  daddu     $s0, $v0, $zero
/* 31200 80055E00 1600000C */  bnez      $s0, .L80055E34
/* 31204 80055E04 0200102D */   daddu    $v0, $s0, $zero
/* 31208 80055E08 0C0157AD */  jal       func_80055EB4
/* 3120C 80055E0C 0220202D */   daddu    $a0, $s1, $zero
/* 31210 80055E10 10400006 */  beqz      $v0, .L80055E2C
/* 31214 80055E14 0040282D */   daddu    $a1, $v0, $zero
/* 31218 80055E18 8FA40014 */  lw        $a0, 0x14($sp)
/* 3121C 80055E1C 0C01421F */  jal       func_8005087C
/* 31220 80055E20 24060001 */   addiu    $a2, $zero, 1
/* 31224 80055E24 0801578D */  j         .L80055E34
/* 31228 80055E28 0200102D */   daddu    $v0, $s0, $zero
.L80055E2C:
/* 3122C 80055E2C 2410000B */  addiu     $s0, $zero, 0xb
/* 31230 80055E30 0200102D */  daddu     $v0, $s0, $zero
.L80055E34:
/* 31234 80055E34 8FBF0020 */  lw        $ra, 0x20($sp)
/* 31238 80055E38 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3123C 80055E3C 8FB00018 */  lw        $s0, 0x18($sp)
/* 31240 80055E40 03E00008 */  jr        $ra
/* 31244 80055E44 27BD0028 */   addiu    $sp, $sp, 0x28
