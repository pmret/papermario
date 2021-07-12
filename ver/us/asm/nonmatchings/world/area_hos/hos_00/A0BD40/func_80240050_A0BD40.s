.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_A0BD40
/* A0BD40 80240050 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A0BD44 80240054 AFB1002C */  sw        $s1, 0x2c($sp)
/* A0BD48 80240058 0080882D */  daddu     $s1, $a0, $zero
/* A0BD4C 8024005C AFBF0030 */  sw        $ra, 0x30($sp)
/* A0BD50 80240060 AFB00028 */  sw        $s0, 0x28($sp)
/* A0BD54 80240064 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* A0BD58 80240068 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* A0BD5C 8024006C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* A0BD60 80240070 F7B80048 */  sdc1      $f24, 0x48($sp)
/* A0BD64 80240074 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A0BD68 80240078 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A0BD6C 8024007C 8E30000C */  lw        $s0, 0xc($s1)
/* A0BD70 80240080 8E050000 */  lw        $a1, ($s0)
/* A0BD74 80240084 0C0B210B */  jal       get_float_variable
/* A0BD78 80240088 26100004 */   addiu    $s0, $s0, 4
/* A0BD7C 8024008C 8E050000 */  lw        $a1, ($s0)
/* A0BD80 80240090 26100004 */  addiu     $s0, $s0, 4
/* A0BD84 80240094 0220202D */  daddu     $a0, $s1, $zero
/* A0BD88 80240098 0C0B210B */  jal       get_float_variable
/* A0BD8C 8024009C E7A00020 */   swc1     $f0, 0x20($sp)
/* A0BD90 802400A0 8E050000 */  lw        $a1, ($s0)
/* A0BD94 802400A4 26100004 */  addiu     $s0, $s0, 4
/* A0BD98 802400A8 0220202D */  daddu     $a0, $s1, $zero
/* A0BD9C 802400AC 0C0B210B */  jal       get_float_variable
/* A0BDA0 802400B0 46000786 */   mov.s    $f30, $f0
/* A0BDA4 802400B4 8E050000 */  lw        $a1, ($s0)
/* A0BDA8 802400B8 26100004 */  addiu     $s0, $s0, 4
/* A0BDAC 802400BC 0220202D */  daddu     $a0, $s1, $zero
/* A0BDB0 802400C0 0C0B210B */  jal       get_float_variable
/* A0BDB4 802400C4 46000706 */   mov.s    $f28, $f0
/* A0BDB8 802400C8 8E050000 */  lw        $a1, ($s0)
/* A0BDBC 802400CC 26100004 */  addiu     $s0, $s0, 4
/* A0BDC0 802400D0 0220202D */  daddu     $a0, $s1, $zero
/* A0BDC4 802400D4 0C0B210B */  jal       get_float_variable
/* A0BDC8 802400D8 46000686 */   mov.s    $f26, $f0
/* A0BDCC 802400DC 8E050000 */  lw        $a1, ($s0)
/* A0BDD0 802400E0 26100004 */  addiu     $s0, $s0, 4
/* A0BDD4 802400E4 0220202D */  daddu     $a0, $s1, $zero
/* A0BDD8 802400E8 0C0B210B */  jal       get_float_variable
/* A0BDDC 802400EC 46000606 */   mov.s    $f24, $f0
/* A0BDE0 802400F0 8E050000 */  lw        $a1, ($s0)
/* A0BDE4 802400F4 26100004 */  addiu     $s0, $s0, 4
/* A0BDE8 802400F8 0220202D */  daddu     $a0, $s1, $zero
/* A0BDEC 802400FC 0C0B210B */  jal       get_float_variable
/* A0BDF0 80240100 46000586 */   mov.s    $f22, $f0
/* A0BDF4 80240104 0220202D */  daddu     $a0, $s1, $zero
/* A0BDF8 80240108 8E050000 */  lw        $a1, ($s0)
/* A0BDFC 8024010C 0C0B210B */  jal       get_float_variable
/* A0BE00 80240110 46000506 */   mov.s    $f20, $f0
/* A0BE04 80240114 4405F000 */  mfc1      $a1, $f30
/* A0BE08 80240118 4406E000 */  mfc1      $a2, $f28
/* A0BE0C 8024011C 4407D000 */  mfc1      $a3, $f26
/* A0BE10 80240120 C7A20020 */  lwc1      $f2, 0x20($sp)
/* A0BE14 80240124 E7B80010 */  swc1      $f24, 0x10($sp)
/* A0BE18 80240128 E7B60014 */  swc1      $f22, 0x14($sp)
/* A0BE1C 8024012C E7B40018 */  swc1      $f20, 0x18($sp)
/* A0BE20 80240130 4600108D */  trunc.w.s $f2, $f2
/* A0BE24 80240134 44041000 */  mfc1      $a0, $f2
/* A0BE28 80240138 0C01BF8C */  jal       playFX_0F
/* A0BE2C 8024013C E7A0001C */   swc1     $f0, 0x1c($sp)
/* A0BE30 80240140 8FBF0030 */  lw        $ra, 0x30($sp)
/* A0BE34 80240144 8FB1002C */  lw        $s1, 0x2c($sp)
/* A0BE38 80240148 8FB00028 */  lw        $s0, 0x28($sp)
/* A0BE3C 8024014C D7BE0060 */  ldc1      $f30, 0x60($sp)
/* A0BE40 80240150 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* A0BE44 80240154 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* A0BE48 80240158 D7B80048 */  ldc1      $f24, 0x48($sp)
/* A0BE4C 8024015C D7B60040 */  ldc1      $f22, 0x40($sp)
/* A0BE50 80240160 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A0BE54 80240164 24020002 */  addiu     $v0, $zero, 2
/* A0BE58 80240168 03E00008 */  jr        $ra
/* A0BE5C 8024016C 27BD0068 */   addiu    $sp, $sp, 0x68
