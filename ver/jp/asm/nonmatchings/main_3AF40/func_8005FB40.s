.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FB40
/* 3AF40 8005FB40 00041080 */  sll       $v0, $a0, 2
/* 3AF44 8005FB44 00441021 */  addu      $v0, $v0, $a0
/* 3AF48 8005FB48 00021040 */  sll       $v0, $v0, 1
/* 3AF4C 8005FB4C 3C01800B */  lui       $at, %hi(D_800B1D27)
/* 3AF50 8005FB50 00220821 */  addu      $at, $at, $v0
/* 3AF54 8005FB54 90221D27 */  lbu       $v0, %lo(D_800B1D27)($at)
/* 3AF58 8005FB58 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3AF5C 8005FB5C 30420080 */  andi      $v0, $v0, 0x80
/* 3AF60 8005FB60 1440000B */  bnez      $v0, .L8005FB90
/* 3AF64 8005FB64 AFBF0030 */   sw       $ra, 0x30($sp)
/* 3AF68 8005FB68 24020003 */  addiu     $v0, $zero, 3
/* 3AF6C 8005FB6C A3A20016 */  sb        $v0, 0x16($sp)
/* 3AF70 8005FB70 27A20010 */  addiu     $v0, $sp, 0x10
/* 3AF74 8005FB74 A3A40020 */  sb        $a0, 0x20($sp)
/* 3AF78 8005FB78 24040302 */  addiu     $a0, $zero, 0x302
/* 3AF7C 8005FB7C A7A50010 */  sh        $a1, 0x10($sp)
/* 3AF80 8005FB80 27A50020 */  addiu     $a1, $sp, 0x20
/* 3AF84 8005FB84 A7A60012 */  sh        $a2, 0x12($sp)
/* 3AF88 8005FB88 0C0180B2 */  jal       func_800602C8
/* 3AF8C 8005FB8C AFA20028 */   sw       $v0, 0x28($sp)
.L8005FB90:
/* 3AF90 8005FB90 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3AF94 8005FB94 03E00008 */  jr        $ra
/* 3AF98 8005FB98 27BD0038 */   addiu    $sp, $sp, 0x38
/* 3AF9C 8005FB9C 00000000 */  nop
