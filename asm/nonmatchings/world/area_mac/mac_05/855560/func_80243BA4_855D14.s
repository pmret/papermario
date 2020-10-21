.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243BA4_855D14
/* 855D14 80243BA4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 855D18 80243BA8 AFB10034 */  sw        $s1, 0x34($sp)
/* 855D1C 80243BAC 0080882D */  daddu     $s1, $a0, $zero
/* 855D20 80243BB0 AFBF003C */  sw        $ra, 0x3c($sp)
/* 855D24 80243BB4 AFB20038 */  sw        $s2, 0x38($sp)
/* 855D28 80243BB8 AFB00030 */  sw        $s0, 0x30($sp)
/* 855D2C 80243BBC F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 855D30 80243BC0 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 855D34 80243BC4 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 855D38 80243BC8 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 855D3C 80243BCC F7B60048 */  sdc1      $f22, 0x48($sp)
/* 855D40 80243BD0 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 855D44 80243BD4 8E30000C */  lw        $s0, 0xc($s1)
/* 855D48 80243BD8 8E050000 */  lw        $a1, ($s0)
/* 855D4C 80243BDC 0C0B1EAF */  jal       get_variable
/* 855D50 80243BE0 26100004 */   addiu    $s0, $s0, 4
/* 855D54 80243BE4 8E050000 */  lw        $a1, ($s0)
/* 855D58 80243BE8 26100004 */  addiu     $s0, $s0, 4
/* 855D5C 80243BEC 0220202D */  daddu     $a0, $s1, $zero
/* 855D60 80243BF0 0C0B210B */  jal       get_float_variable
/* 855D64 80243BF4 0040902D */   daddu    $s2, $v0, $zero
/* 855D68 80243BF8 8E050000 */  lw        $a1, ($s0)
/* 855D6C 80243BFC 26100004 */  addiu     $s0, $s0, 4
/* 855D70 80243C00 0220202D */  daddu     $a0, $s1, $zero
/* 855D74 80243C04 0C0B210B */  jal       get_float_variable
/* 855D78 80243C08 46000706 */   mov.s    $f28, $f0
/* 855D7C 80243C0C 8E050000 */  lw        $a1, ($s0)
/* 855D80 80243C10 26100004 */  addiu     $s0, $s0, 4
/* 855D84 80243C14 0220202D */  daddu     $a0, $s1, $zero
/* 855D88 80243C18 0C0B210B */  jal       get_float_variable
/* 855D8C 80243C1C 46000786 */   mov.s    $f30, $f0
/* 855D90 80243C20 8E050000 */  lw        $a1, ($s0)
/* 855D94 80243C24 26100004 */  addiu     $s0, $s0, 4
/* 855D98 80243C28 0220202D */  daddu     $a0, $s1, $zero
/* 855D9C 80243C2C 0C0B210B */  jal       get_float_variable
/* 855DA0 80243C30 46000686 */   mov.s    $f26, $f0
/* 855DA4 80243C34 8E050000 */  lw        $a1, ($s0)
/* 855DA8 80243C38 26100004 */  addiu     $s0, $s0, 4
/* 855DAC 80243C3C 0220202D */  daddu     $a0, $s1, $zero
/* 855DB0 80243C40 0C0B210B */  jal       get_float_variable
/* 855DB4 80243C44 46000606 */   mov.s    $f24, $f0
/* 855DB8 80243C48 8E050000 */  lw        $a1, ($s0)
/* 855DBC 80243C4C 26100004 */  addiu     $s0, $s0, 4
/* 855DC0 80243C50 0220202D */  daddu     $a0, $s1, $zero
/* 855DC4 80243C54 0C0B210B */  jal       get_float_variable
/* 855DC8 80243C58 46000586 */   mov.s    $f22, $f0
/* 855DCC 80243C5C 0220202D */  daddu     $a0, $s1, $zero
/* 855DD0 80243C60 8E050000 */  lw        $a1, ($s0)
/* 855DD4 80243C64 0C0B1EAF */  jal       get_variable
/* 855DD8 80243C68 46000506 */   mov.s    $f20, $f0
/* 855DDC 80243C6C 4405E000 */  mfc1      $a1, $f28
/* 855DE0 80243C70 4406F000 */  mfc1      $a2, $f30
/* 855DE4 80243C74 4407D000 */  mfc1      $a3, $f26
/* 855DE8 80243C78 0240202D */  daddu     $a0, $s2, $zero
/* 855DEC 80243C7C AFA2001C */  sw        $v0, 0x1c($sp)
/* 855DF0 80243C80 27A20028 */  addiu     $v0, $sp, 0x28
/* 855DF4 80243C84 E7B80010 */  swc1      $f24, 0x10($sp)
/* 855DF8 80243C88 E7B60014 */  swc1      $f22, 0x14($sp)
/* 855DFC 80243C8C E7B40018 */  swc1      $f20, 0x18($sp)
/* 855E00 80243C90 0C01C3DC */  jal       func_80070F70
/* 855E04 80243C94 AFA20020 */   sw       $v0, 0x20($sp)
/* 855E08 80243C98 8FA30028 */  lw        $v1, 0x28($sp)
/* 855E0C 80243C9C AE230084 */  sw        $v1, 0x84($s1)
/* 855E10 80243CA0 8FBF003C */  lw        $ra, 0x3c($sp)
/* 855E14 80243CA4 8FB20038 */  lw        $s2, 0x38($sp)
/* 855E18 80243CA8 8FB10034 */  lw        $s1, 0x34($sp)
/* 855E1C 80243CAC 8FB00030 */  lw        $s0, 0x30($sp)
/* 855E20 80243CB0 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 855E24 80243CB4 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 855E28 80243CB8 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 855E2C 80243CBC D7B80050 */  ldc1      $f24, 0x50($sp)
/* 855E30 80243CC0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 855E34 80243CC4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 855E38 80243CC8 24020002 */  addiu     $v0, $zero, 2
/* 855E3C 80243CCC 03E00008 */  jr        $ra
/* 855E40 80243CD0 27BD0070 */   addiu    $sp, $sp, 0x70
