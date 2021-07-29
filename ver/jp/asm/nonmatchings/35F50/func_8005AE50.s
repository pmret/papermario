.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005AE50
/* 36250 8005AE50 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 36254 8005AE54 AFB00018 */  sw        $s0, 0x18($sp)
/* 36258 8005AE58 0080802D */  daddu     $s0, $a0, $zero
/* 3625C 8005AE5C AFBF0024 */  sw        $ra, 0x24($sp)
/* 36260 8005AE60 AFB20020 */  sw        $s2, 0x20($sp)
/* 36264 8005AE64 16000005 */  bnez      $s0, .L8005AE7C
/* 36268 8005AE68 AFB1001C */   sw       $s1, 0x1c($sp)
/* 3626C 8005AE6C 3C01800B */  lui       $at, %hi(D_800B42CC)
/* 36270 8005AE70 A42042CC */  sh        $zero, %lo(D_800B42CC)($at)
/* 36274 8005AE74 08016BB5 */  j         .L8005AED4
/* 36278 8005AE78 00000000 */   nop
.L8005AE7C:
/* 3627C 8005AE7C 0C016A28 */  jal       func_8005A8A0
/* 36280 8005AE80 00000000 */   nop
/* 36284 8005AE84 0200202D */  daddu     $a0, $s0, $zero
/* 36288 8005AE88 27A50010 */  addiu     $a1, $sp, 0x10
/* 3628C 8005AE8C 0C016A68 */  jal       func_8005A9A0
/* 36290 8005AE90 0040902D */   daddu    $s2, $v0, $zero
/* 36294 8005AE94 8FA40010 */  lw        $a0, 0x10($sp)
/* 36298 8005AE98 0C00AB29 */  jal       func_8002ACA4
/* 3629C 8005AE9C 0040882D */   daddu    $s1, $v0, $zero
/* 362A0 8005AEA0 0220202D */  daddu     $a0, $s1, $zero
/* 362A4 8005AEA4 0040802D */  daddu     $s0, $v0, $zero
/* 362A8 8005AEA8 0C01BB74 */  jal       func_8006EDD0
/* 362AC 8005AEAC 0200282D */   daddu    $a1, $s0, $zero
/* 362B0 8005AEB0 0C00AB0E */  jal       func_8002AC38
/* 362B4 8005AEB4 0220202D */   daddu    $a0, $s1, $zero
/* 362B8 8005AEB8 0000202D */  daddu     $a0, $zero, $zero
/* 362BC 8005AEBC 8E020000 */  lw        $v0, ($s0)
/* 362C0 8005AEC0 0200282D */  daddu     $a1, $s0, $zero
/* 362C4 8005AEC4 0C016BBB */  jal       func_8005AEEC
/* 362C8 8005AEC8 AE420004 */   sw       $v0, 4($s2)
/* 362CC 8005AECC 0C00AB3B */  jal       func_8002ACEC
/* 362D0 8005AED0 0200202D */   daddu    $a0, $s0, $zero
.L8005AED4:
/* 362D4 8005AED4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 362D8 8005AED8 8FB20020 */  lw        $s2, 0x20($sp)
/* 362DC 8005AEDC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 362E0 8005AEE0 8FB00018 */  lw        $s0, 0x18($sp)
/* 362E4 8005AEE4 03E00008 */  jr        $ra
/* 362E8 8005AEE8 27BD0028 */   addiu    $sp, $sp, 0x28
