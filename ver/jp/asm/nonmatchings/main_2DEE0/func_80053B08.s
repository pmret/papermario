.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053B08
/* 2EF08 80053B08 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 2EF0C 80053B0C AFB00020 */  sw        $s0, 0x20($sp)
/* 2EF10 80053B10 00A0802D */  daddu     $s0, $a1, $zero
/* 2EF14 80053B14 AFB20028 */  sw        $s2, 0x28($sp)
/* 2EF18 80053B18 3C12800A */  lui       $s2, %hi(D_8009A5A0)
/* 2EF1C 80053B1C 8E52A5A0 */  lw        $s2, %lo(D_8009A5A0)($s2)
/* 2EF20 80053B20 24050010 */  addiu     $a1, $zero, 0x10
/* 2EF24 80053B24 AFBF0038 */  sw        $ra, 0x38($sp)
/* 2EF28 80053B28 AFB50034 */  sw        $s5, 0x34($sp)
/* 2EF2C 80053B2C AFB40030 */  sw        $s4, 0x30($sp)
/* 2EF30 80053B30 AFB3002C */  sw        $s3, 0x2c($sp)
/* 2EF34 80053B34 AFB10024 */  sw        $s1, 0x24($sp)
/* 2EF38 80053B38 8E42002C */  lw        $v0, 0x2c($s2)
/* 2EF3C 80053B3C 000420C0 */  sll       $a0, $a0, 3
/* 2EF40 80053B40 00448821 */  addu      $s1, $v0, $a0
/* 2EF44 80053B44 96240000 */  lhu       $a0, ($s1)
/* 2EF48 80053B48 0C01504B */  jal       func_8005412C
/* 2EF4C 80053B4C 27A60018 */   addiu    $a2, $sp, 0x18
/* 2EF50 80053B50 0040982D */  daddu     $s3, $v0, $zero
/* 2EF54 80053B54 16600026 */  bnez      $s3, .L80053BF0
/* 2EF58 80053B58 0260102D */   daddu    $v0, $s3, $zero
/* 2EF5C 80053B5C 3C0200FF */  lui       $v0, 0xff
/* 2EF60 80053B60 3442FFFF */  ori       $v0, $v0, 0xffff
/* 2EF64 80053B64 0200282D */  daddu     $a1, $s0, $zero
/* 2EF68 80053B68 0000802D */  daddu     $s0, $zero, $zero
/* 2EF6C 80053B6C 3C1400FF */  lui       $s4, 0xff
/* 2EF70 80053B70 3694FFFF */  ori       $s4, $s4, 0xffff
/* 2EF74 80053B74 24150030 */  addiu     $s5, $zero, 0x30
/* 2EF78 80053B78 8FA6001C */  lw        $a2, 0x1c($sp)
/* 2EF7C 80053B7C 8FA40018 */  lw        $a0, 0x18($sp)
/* 2EF80 80053B80 0C0152AC */  jal       func_80054AB0
/* 2EF84 80053B84 00C23024 */   and      $a2, $a2, $v0
.L80053B88:
/* 2EF88 80053B88 96220002 */  lhu       $v0, 2($s1)
/* 2EF8C 80053B8C 50400014 */  beql      $v0, $zero, .L80053BE0
/* 2EF90 80053B90 26310002 */   addiu    $s1, $s1, 2
/* 2EF94 80053B94 8E440020 */  lw        $a0, 0x20($s2)
/* 2EF98 80053B98 000210C0 */  sll       $v0, $v0, 3
/* 2EF9C 80053B9C 00822021 */  addu      $a0, $a0, $v0
/* 2EFA0 80053BA0 8C820000 */  lw        $v0, ($a0)
/* 2EFA4 80053BA4 8E43001C */  lw        $v1, 0x1c($s2)
/* 2EFA8 80053BA8 00541024 */  and       $v0, $v0, $s4
/* 2EFAC 80053BAC 00431821 */  addu      $v1, $v0, $v1
/* 2EFB0 80053BB0 AFA30010 */  sw        $v1, 0x10($sp)
/* 2EFB4 80053BB4 8C820004 */  lw        $v0, 4($a0)
/* 2EFB8 80053BB8 AFA20014 */  sw        $v0, 0x14($sp)
/* 2EFBC 80053BBC 00021602 */  srl       $v0, $v0, 0x18
/* 2EFC0 80053BC0 54550006 */  bnel      $v0, $s5, .L80053BDC
/* 2EFC4 80053BC4 24130066 */   addiu    $s3, $zero, 0x66
/* 2EFC8 80053BC8 0060202D */  daddu     $a0, $v1, $zero
/* 2EFCC 80053BCC 0C01523F */  jal       func_800548FC
/* 2EFD0 80053BD0 0200282D */   daddu    $a1, $s0, $zero
/* 2EFD4 80053BD4 08014EF8 */  j         .L80053BE0
/* 2EFD8 80053BD8 26310002 */   addiu    $s1, $s1, 2
.L80053BDC:
/* 2EFDC 80053BDC 26310002 */  addiu     $s1, $s1, 2
.L80053BE0:
/* 2EFE0 80053BE0 26100001 */  addiu     $s0, $s0, 1
/* 2EFE4 80053BE4 2A020003 */  slti      $v0, $s0, 3
/* 2EFE8 80053BE8 1440FFE7 */  bnez      $v0, .L80053B88
/* 2EFEC 80053BEC 0260102D */   daddu    $v0, $s3, $zero
.L80053BF0:
/* 2EFF0 80053BF0 8FBF0038 */  lw        $ra, 0x38($sp)
/* 2EFF4 80053BF4 8FB50034 */  lw        $s5, 0x34($sp)
/* 2EFF8 80053BF8 8FB40030 */  lw        $s4, 0x30($sp)
/* 2EFFC 80053BFC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 2F000 80053C00 8FB20028 */  lw        $s2, 0x28($sp)
/* 2F004 80053C04 8FB10024 */  lw        $s1, 0x24($sp)
/* 2F008 80053C08 8FB00020 */  lw        $s0, 0x20($sp)
/* 2F00C 80053C0C 03E00008 */  jr        $ra
/* 2F010 80053C10 27BD0040 */   addiu    $sp, $sp, 0x40
