.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066A40
/* 41E40 80066A40 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 41E44 80066A44 AFB40028 */  sw        $s4, 0x28($sp)
/* 41E48 80066A48 3C148009 */  lui       $s4, %hi(__osRunningThread)
/* 41E4C 80066A4C 26944660 */  addiu     $s4, $s4, %lo(__osRunningThread)
/* 41E50 80066A50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 41E54 80066A54 AFB30024 */  sw        $s3, 0x24($sp)
/* 41E58 80066A58 AFB20020 */  sw        $s2, 0x20($sp)
/* 41E5C 80066A5C AFB1001C */  sw        $s1, 0x1c($sp)
/* 41E60 80066A60 AFB00018 */  sw        $s0, 0x18($sp)
/* 41E64 80066A64 8E820000 */  lw        $v0, ($s4)
/* 41E68 80066A68 14400055 */  bnez      $v0, .L80066BC0
/* 41E6C 80066A6C 00808821 */   addu     $s1, $a0, $zero
/* 41E70 80066A70 0C019914 */  jal       func_80066450
/* 41E74 80066A74 2412FFFF */   addiu    $s2, $zero, -1
/* 41E78 80066A78 3C13800B */  lui       $s3, %hi(D_800B0AB0)
/* 41E7C 80066A7C 26730AB0 */  addiu     $s3, $s3, %lo(D_800B0AB0)
/* 41E80 80066A80 02602021 */  addu      $a0, $s3, $zero
/* 41E84 80066A84 3C05800B */  lui       $a1, %hi(D_800B0AC8)
/* 41E88 80066A88 24A50AC8 */  addiu     $a1, $a1, %lo(D_800B0AC8)
/* 41E8C 80066A8C 3C018009 */  lui       $at, %hi(D_8009467C)
/* 41E90 80066A90 AC20467C */  sw        $zero, %lo(D_8009467C)($at)
/* 41E94 80066A94 0C019554 */  jal       func_80065550
/* 41E98 80066A98 24060005 */   addiu    $a2, $zero, 5
/* 41E9C 80066A9C 24040007 */  addiu     $a0, $zero, 7
/* 41EA0 80066AA0 3C06800B */  lui       $a2, %hi(D_800B0AE0)
/* 41EA4 80066AA4 24C60AE0 */  addiu     $a2, $a2, %lo(D_800B0AE0)
/* 41EA8 80066AA8 2402000D */  addiu     $v0, $zero, 0xd
/* 41EAC 80066AAC 3C10800B */  lui       $s0, %hi(D_800B0AF8)
/* 41EB0 80066AB0 26100AF8 */  addiu     $s0, $s0, %lo(D_800B0AF8)
/* 41EB4 80066AB4 A4C20000 */  sh        $v0, ($a2)
/* 41EB8 80066AB8 2402000E */  addiu     $v0, $zero, 0xe
/* 41EBC 80066ABC 3C01800B */  lui       $at, %hi(D_800B0AE2)
/* 41EC0 80066AC0 A0200AE2 */  sb        $zero, %lo(D_800B0AE2)($at)
/* 41EC4 80066AC4 3C01800B */  lui       $at, %hi(D_800B0AE4)
/* 41EC8 80066AC8 AC200AE4 */  sw        $zero, %lo(D_800B0AE4)($at)
/* 41ECC 80066ACC A6020000 */  sh        $v0, ($s0)
/* 41ED0 80066AD0 3C01800B */  lui       $at, %hi(D_800B0AFA)
/* 41ED4 80066AD4 A0200AFA */  sb        $zero, %lo(D_800B0AFA)($at)
/* 41ED8 80066AD8 3C01800B */  lui       $at, %hi(D_800B0AFC)
/* 41EDC 80066ADC AC200AFC */  sw        $zero, %lo(D_800B0AFC)($at)
/* 41EE0 80066AE0 0C019648 */  jal       func_80065920
/* 41EE4 80066AE4 02602821 */   addu     $a1, $s3, $zero
/* 41EE8 80066AE8 24040003 */  addiu     $a0, $zero, 3
/* 41EEC 80066AEC 02602821 */  addu      $a1, $s3, $zero
/* 41EF0 80066AF0 0C019648 */  jal       func_80065920
/* 41EF4 80066AF4 02003021 */   addu     $a2, $s0, $zero
/* 41EF8 80066AF8 0C0197C0 */  jal       func_80065F00
/* 41EFC 80066AFC 00002021 */   addu     $a0, $zero, $zero
/* 41F00 80066B00 00401821 */  addu      $v1, $v0, $zero
/* 41F04 80066B04 0071102A */  slt       $v0, $v1, $s1
/* 41F08 80066B08 10400005 */  beqz      $v0, .L80066B20
/* 41F0C 80066B0C 00000000 */   nop
/* 41F10 80066B10 00609021 */  addu      $s2, $v1, $zero
/* 41F14 80066B14 00002021 */  addu      $a0, $zero, $zero
/* 41F18 80066B18 0C0197C8 */  jal       func_80065F20
/* 41F1C 80066B1C 02202821 */   addu     $a1, $s1, $zero
.L80066B20:
/* 41F20 80066B20 0C01ACD0 */  jal       func_8006B340
/* 41F24 80066B24 00000000 */   nop
/* 41F28 80066B28 3C10800B */  lui       $s0, %hi(D_800AF8F8)
/* 41F2C 80066B2C 2610F8F8 */  addiu     $s0, $s0, %lo(D_800AF8F8)
/* 41F30 80066B30 02002021 */  addu      $a0, $s0, $zero
/* 41F34 80066B34 00002821 */  addu      $a1, $zero, $zero
/* 41F38 80066B38 3C068006 */  lui       $a2, %hi(func_80066BE0)
/* 41F3C 80066B3C 24C66BE0 */  addiu     $a2, $a2, %lo(func_80066BE0)
/* 41F40 80066B40 24030001 */  addiu     $v1, $zero, 1
/* 41F44 80066B44 AE830000 */  sw        $v1, ($s4)
/* 41F48 80066B48 3C03800B */  lui       $v1, %hi(D_800B0AB0)
/* 41F4C 80066B4C 24630AB0 */  addiu     $v1, $v1, %lo(D_800B0AB0)
/* 41F50 80066B50 AFB10014 */  sw        $s1, 0x14($sp)
/* 41F54 80066B54 00408821 */  addu      $s1, $v0, $zero
/* 41F58 80066B58 02803821 */  addu      $a3, $s4, $zero
/* 41F5C 80066B5C 3C018009 */  lui       $at, %hi(D_80094664)
/* 41F60 80066B60 AC304664 */  sw        $s0, %lo(D_80094664)($at)
/* 41F64 80066B64 3C018009 */  lui       $at, %hi(D_80094668)
/* 41F68 80066B68 AC334668 */  sw        $s3, %lo(D_80094668)($at)
/* 41F6C 80066B6C 3C018009 */  lui       $at, %hi(D_8009466C)
/* 41F70 80066B70 AC33466C */  sw        $s3, %lo(D_8009466C)($at)
/* 41F74 80066B74 3C018009 */  lui       $at, %hi(D_80094670)
/* 41F78 80066B78 AC204670 */  sw        $zero, %lo(D_80094670)($at)
/* 41F7C 80066B7C 3C018009 */  lui       $at, %hi(D_80094674)
/* 41F80 80066B80 AC204674 */  sw        $zero, %lo(D_80094674)($at)
/* 41F84 80066B84 3C018009 */  lui       $at, %hi(D_80094678)
/* 41F88 80066B88 AC204678 */  sw        $zero, %lo(D_80094678)($at)
/* 41F8C 80066B8C 0C01978C */  jal       func_80065E30
/* 41F90 80066B90 AFA30010 */   sw       $v1, 0x10($sp)
/* 41F94 80066B94 0C01B29C */  jal       func_8006CA70
/* 41F98 80066B98 00000000 */   nop
/* 41F9C 80066B9C 0C0197FC */  jal       func_80065FF0
/* 41FA0 80066BA0 02002021 */   addu     $a0, $s0, $zero
/* 41FA4 80066BA4 0C01ACEC */  jal       func_8006B3B0
/* 41FA8 80066BA8 02202021 */   addu     $a0, $s1, $zero
/* 41FAC 80066BAC 2402FFFF */  addiu     $v0, $zero, -1
/* 41FB0 80066BB0 12420003 */  beq       $s2, $v0, .L80066BC0
/* 41FB4 80066BB4 00002021 */   addu     $a0, $zero, $zero
/* 41FB8 80066BB8 0C0197C8 */  jal       func_80065F20
/* 41FBC 80066BBC 02402821 */   addu     $a1, $s2, $zero
.L80066BC0:
/* 41FC0 80066BC0 8FBF002C */  lw        $ra, 0x2c($sp)
/* 41FC4 80066BC4 8FB40028 */  lw        $s4, 0x28($sp)
/* 41FC8 80066BC8 8FB30024 */  lw        $s3, 0x24($sp)
/* 41FCC 80066BCC 8FB20020 */  lw        $s2, 0x20($sp)
/* 41FD0 80066BD0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 41FD4 80066BD4 8FB00018 */  lw        $s0, 0x18($sp)
/* 41FD8 80066BD8 03E00008 */  jr        $ra
/* 41FDC 80066BDC 27BD0030 */   addiu    $sp, $sp, 0x30
