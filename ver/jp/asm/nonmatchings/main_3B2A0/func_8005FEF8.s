.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FEF8
/* 3B2F8 8005FEF8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3B2FC 8005FEFC AFB00028 */  sw        $s0, 0x28($sp)
/* 3B300 8005FF00 3C10800B */  lui       $s0, %hi(D_800B42D0)
/* 3B304 8005FF04 261042D0 */  addiu     $s0, $s0, %lo(D_800B42D0)
/* 3B308 8005FF08 0200202D */  daddu     $a0, $s0, $zero
/* 3B30C 8005FF0C 3C05800B */  lui       $a1, %hi(D_800AA4C0)
/* 3B310 8005FF10 24A5A4C0 */  addiu     $a1, $a1, %lo(D_800AA4C0)
/* 3B314 8005FF14 24060008 */  addiu     $a2, $zero, 8
/* 3B318 8005FF18 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3B31C 8005FF1C 0C019554 */  jal       func_80065550
/* 3B320 8005FF20 AFB1002C */   sw       $s1, 0x2c($sp)
/* 3B324 8005FF24 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B328 8005FF28 0200282D */  daddu     $a1, $s0, $zero
/* 3B32C 8005FF2C 0C017AB8 */  jal       func_8005EAE0
/* 3B330 8005FF30 24060003 */   addiu    $a2, $zero, 3
/* 3B334 8005FF34 24110001 */  addiu     $s1, $zero, 1
/* 3B338 8005FF38 24100002 */  addiu     $s0, $zero, 2
.L8005FF3C:
/* 3B33C 8005FF3C 3C04800B */  lui       $a0, %hi(D_800B42D0)
/* 3B340 8005FF40 248442D0 */  addiu     $a0, $a0, %lo(D_800B42D0)
/* 3B344 8005FF44 27A50020 */  addiu     $a1, $sp, 0x20
/* 3B348 8005FF48 0C0195B0 */  jal       func_800656C0
/* 3B34C 8005FF4C 24060001 */   addiu    $a2, $zero, 1
/* 3B350 8005FF50 8FA20020 */  lw        $v0, 0x20($sp)
/* 3B354 8005FF54 84420000 */  lh        $v0, ($v0)
/* 3B358 8005FF58 10510005 */  beq       $v0, $s1, .L8005FF70
/* 3B35C 8005FF5C 00000000 */   nop
/* 3B360 8005FF60 1050000D */  beq       $v0, $s0, .L8005FF98
/* 3B364 8005FF64 00000000 */   nop
/* 3B368 8005FF68 08017FCF */  j         .L8005FF3C
/* 3B36C 8005FF6C 00000000 */   nop
.L8005FF70:
/* 3B370 8005FF70 3C028009 */  lui       $v0, %hi(D_80093CE0)
/* 3B374 8005FF74 8C423CE0 */  lw        $v0, %lo(D_80093CE0)($v0)
/* 3B378 8005FF78 1040FFF0 */  beqz      $v0, .L8005FF3C
/* 3B37C 8005FF7C 00000000 */   nop
/* 3B380 8005FF80 3C04800A */  lui       $a0, %hi(D_8009A5F8)
/* 3B384 8005FF84 8C84A5F8 */  lw        $a0, %lo(D_8009A5F8)($a0)
/* 3B388 8005FF88 0040F809 */  jalr      $v0
/* 3B38C 8005FF8C 00000000 */   nop
/* 3B390 8005FF90 08017FCF */  j         .L8005FF3C
/* 3B394 8005FF94 00000000 */   nop
.L8005FF98:
/* 3B398 8005FF98 3C028009 */  lui       $v0, %hi(D_80093CE4)
/* 3B39C 8005FF9C 8C423CE4 */  lw        $v0, %lo(D_80093CE4)($v0)
/* 3B3A0 8005FFA0 1040FFE6 */  beqz      $v0, .L8005FF3C
/* 3B3A4 8005FFA4 00000000 */   nop
/* 3B3A8 8005FFA8 0040F809 */  jalr      $v0
/* 3B3AC 8005FFAC 00000000 */   nop
/* 3B3B0 8005FFB0 08017FCF */  j         .L8005FF3C
/* 3B3B4 8005FFB4 00000000 */   nop
/* 3B3B8 8005FFB8 00000000 */  nop
/* 3B3BC 8005FFBC 00000000 */  nop
