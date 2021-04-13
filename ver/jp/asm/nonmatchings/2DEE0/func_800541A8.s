.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800541A8
/* 2F5A8 800541A8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 2F5AC 800541AC AFB20028 */  sw        $s2, 0x28($sp)
/* 2F5B0 800541B0 0080902D */  daddu     $s2, $a0, $zero
/* 2F5B4 800541B4 AFB00020 */  sw        $s0, 0x20($sp)
/* 2F5B8 800541B8 00A0802D */  daddu     $s0, $a1, $zero
/* 2F5BC 800541BC 0200202D */  daddu     $a0, $s0, $zero
/* 2F5C0 800541C0 27A50010 */  addiu     $a1, $sp, 0x10
/* 2F5C4 800541C4 24060010 */  addiu     $a2, $zero, 0x10
/* 2F5C8 800541C8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 2F5CC 800541CC 0C0152AC */  jal       func_80054AB0
/* 2F5D0 800541D0 AFB10024 */   sw       $s1, 0x24($sp)
/* 2F5D4 800541D4 26040010 */  addiu     $a0, $s0, 0x10
/* 2F5D8 800541D8 8FB00014 */  lw        $s0, 0x14($sp)
/* 2F5DC 800541DC 8E450054 */  lw        $a1, 0x54($s2)
/* 2F5E0 800541E0 2610FFF0 */  addiu     $s0, $s0, -0x10
/* 2F5E4 800541E4 0C0152AC */  jal       func_80054AB0
/* 2F5E8 800541E8 0200302D */   daddu    $a2, $s0, $zero
/* 2F5EC 800541EC 3C0238E3 */  lui       $v0, 0x38e3
/* 2F5F0 800541F0 34428E39 */  ori       $v0, $v0, 0x8e39
/* 2F5F4 800541F4 02020019 */  multu     $s0, $v0
/* 2F5F8 800541F8 24020006 */  addiu     $v0, $zero, 6
/* 2F5FC 800541FC 00003810 */  mfhi      $a3
/* 2F600 80054200 00071942 */  srl       $v1, $a3, 5
/* 2F604 80054204 00438823 */  subu      $s1, $v0, $v1
/* 2F608 80054208 1A200010 */  blez      $s1, .L8005424C
/* 2F60C 8005420C 26440008 */   addiu    $a0, $s2, 8
/* 2F610 80054210 2406000C */  addiu     $a2, $zero, 0xc
/* 2F614 80054214 000310C0 */  sll       $v0, $v1, 3
/* 2F618 80054218 00431021 */  addu      $v0, $v0, $v1
/* 2F61C 8005421C 8E500054 */  lw        $s0, 0x54($s2)
/* 2F620 80054220 00021100 */  sll       $v0, $v0, 4
/* 2F624 80054224 02028021 */  addu      $s0, $s0, $v0
/* 2F628 80054228 0C015309 */  jal       func_80054C24
/* 2F62C 8005422C 0200282D */   daddu    $a1, $s0, $zero
/* 2F630 80054230 0200202D */  daddu     $a0, $s0, $zero
/* 2F634 80054234 2485000C */  addiu     $a1, $a0, 0xc
/* 2F638 80054238 001130C0 */  sll       $a2, $s1, 3
/* 2F63C 8005423C 00D13021 */  addu      $a2, $a2, $s1
/* 2F640 80054240 00063100 */  sll       $a2, $a2, 4
/* 2F644 80054244 0C015309 */  jal       func_80054C24
/* 2F648 80054248 24C6FFF4 */   addiu    $a2, $a2, -0xc
.L8005424C:
/* 2F64C 8005424C 8FBF002C */  lw        $ra, 0x2c($sp)
/* 2F650 80054250 8FB20028 */  lw        $s2, 0x28($sp)
/* 2F654 80054254 8FB10024 */  lw        $s1, 0x24($sp)
/* 2F658 80054258 8FB00020 */  lw        $s0, 0x20($sp)
/* 2F65C 8005425C 03E00008 */  jr        $ra
/* 2F660 80054260 27BD0030 */   addiu    $sp, $sp, 0x30
