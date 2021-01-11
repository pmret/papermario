.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CA0_ECB9A0
/* ECB9A0 80241CA0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* ECB9A4 80241CA4 AFB10054 */  sw        $s1, 0x54($sp)
/* ECB9A8 80241CA8 0080882D */  daddu     $s1, $a0, $zero
/* ECB9AC 80241CAC AFBF005C */  sw        $ra, 0x5c($sp)
/* ECB9B0 80241CB0 AFB20058 */  sw        $s2, 0x58($sp)
/* ECB9B4 80241CB4 AFB00050 */  sw        $s0, 0x50($sp)
/* ECB9B8 80241CB8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* ECB9BC 80241CBC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* ECB9C0 80241CC0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* ECB9C4 80241CC4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* ECB9C8 80241CC8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* ECB9CC 80241CCC 8E30000C */  lw        $s0, 0xc($s1)
/* ECB9D0 80241CD0 8E050000 */  lw        $a1, ($s0)
/* ECB9D4 80241CD4 0C0B53A3 */  jal       func_802D4E8C
/* ECB9D8 80241CD8 26100004 */   addiu    $s0, $s0, 4
/* ECB9DC 80241CDC 0C04949C */  jal       func_80125270
/* ECB9E0 80241CE0 0040202D */   daddu    $a0, $v0, $zero
/* ECB9E4 80241CE4 8E050000 */  lw        $a1, ($s0)
/* ECB9E8 80241CE8 26100004 */  addiu     $s0, $s0, 4
/* ECB9EC 80241CEC 0220202D */  daddu     $a0, $s1, $zero
/* ECB9F0 80241CF0 0C0B55FF */  jal       func_802D57FC
/* ECB9F4 80241CF4 0040902D */   daddu    $s2, $v0, $zero
/* ECB9F8 80241CF8 8E050000 */  lw        $a1, ($s0)
/* ECB9FC 80241CFC 26100004 */  addiu     $s0, $s0, 4
/* ECBA00 80241D00 0220202D */  daddu     $a0, $s1, $zero
/* ECBA04 80241D04 0C0B55FF */  jal       func_802D57FC
/* ECBA08 80241D08 46000706 */   mov.s    $f28, $f0
/* ECBA0C 80241D0C 8E050000 */  lw        $a1, ($s0)
/* ECBA10 80241D10 26100004 */  addiu     $s0, $s0, 4
/* ECBA14 80241D14 0220202D */  daddu     $a0, $s1, $zero
/* ECBA18 80241D18 0C0B55FF */  jal       func_802D57FC
/* ECBA1C 80241D1C 46000686 */   mov.s    $f26, $f0
/* ECBA20 80241D20 0220202D */  daddu     $a0, $s1, $zero
/* ECBA24 80241D24 8E050000 */  lw        $a1, ($s0)
/* ECBA28 80241D28 0C0B55FF */  jal       func_802D57FC
/* ECBA2C 80241D2C 46000586 */   mov.s    $f22, $f0
/* ECBA30 80241D30 0240202D */  daddu     $a0, $s2, $zero
/* ECBA34 80241D34 0C0493D1 */  jal       func_80124F44
/* ECBA38 80241D38 46000606 */   mov.s    $f24, $f0
/* ECBA3C 80241D3C 0040882D */  daddu     $s1, $v0, $zero
/* ECBA40 80241D40 96220000 */  lhu       $v0, ($s1)
/* ECBA44 80241D44 30420400 */  andi      $v0, $v0, 0x400
/* ECBA48 80241D48 1440001E */  bnez      $v0, .L80241DC4
/* ECBA4C 80241D4C 26300058 */   addiu    $s0, $s1, 0x58
/* ECBA50 80241D50 4480A000 */  mtc1      $zero, $f20
/* ECBA54 80241D54 4406B000 */  mfc1      $a2, $f22
/* ECBA58 80241D58 4405A000 */  mfc1      $a1, $f20
/* ECBA5C 80241D5C 4407A000 */  mfc1      $a3, $f20
/* ECBA60 80241D60 0C01B2B0 */  jal       func_8006CAC0
/* ECBA64 80241D64 0200202D */   daddu    $a0, $s0, $zero
/* ECBA68 80241D68 4405E000 */  mfc1      $a1, $f28
/* ECBA6C 80241D6C 4406D000 */  mfc1      $a2, $f26
/* ECBA70 80241D70 4407C000 */  mfc1      $a3, $f24
/* ECBA74 80241D74 0C09070C */  jal       func_80241C30_ECB930
/* ECBA78 80241D78 27A40010 */   addiu    $a0, $sp, 0x10
/* ECBA7C 80241D7C 27A40010 */  addiu     $a0, $sp, 0x10
/* ECBA80 80241D80 0200282D */  daddu     $a1, $s0, $zero
/* ECBA84 80241D84 0C01B1F0 */  jal       osSiRawReadIo
/* ECBA88 80241D88 0200302D */   daddu    $a2, $s0, $zero
/* ECBA8C 80241D8C 27A40010 */  addiu     $a0, $sp, 0x10
/* ECBA90 80241D90 4600B587 */  neg.s     $f22, $f22
/* ECBA94 80241D94 4405A000 */  mfc1      $a1, $f20
/* ECBA98 80241D98 4406B000 */  mfc1      $a2, $f22
/* ECBA9C 80241D9C 0C01B2B0 */  jal       func_8006CAC0
/* ECBAA0 80241DA0 00A0382D */   daddu    $a3, $a1, $zero
/* ECBAA4 80241DA4 27A40010 */  addiu     $a0, $sp, 0x10
/* ECBAA8 80241DA8 0200282D */  daddu     $a1, $s0, $zero
/* ECBAAC 80241DAC 0C01B1F0 */  jal       osSiRawReadIo
/* ECBAB0 80241DB0 00A0302D */   daddu    $a2, $a1, $zero
/* ECBAB4 80241DB4 96220000 */  lhu       $v0, ($s1)
/* ECBAB8 80241DB8 34421400 */  ori       $v0, $v0, 0x1400
/* ECBABC 80241DBC 0809078F */  j         .L80241E3C
/* ECBAC0 80241DC0 A6220000 */   sh       $v0, ($s1)
.L80241DC4:
/* ECBAC4 80241DC4 4480A000 */  mtc1      $zero, $f20
/* ECBAC8 80241DC8 4406B000 */  mfc1      $a2, $f22
/* ECBACC 80241DCC 4405A000 */  mfc1      $a1, $f20
/* ECBAD0 80241DD0 4407A000 */  mfc1      $a3, $f20
/* ECBAD4 80241DD4 0C01B2B0 */  jal       func_8006CAC0
/* ECBAD8 80241DD8 27A40010 */   addiu    $a0, $sp, 0x10
/* ECBADC 80241DDC 27A40010 */  addiu     $a0, $sp, 0x10
/* ECBAE0 80241DE0 26300058 */  addiu     $s0, $s1, 0x58
/* ECBAE4 80241DE4 0200282D */  daddu     $a1, $s0, $zero
/* ECBAE8 80241DE8 0C01B1F0 */  jal       osSiRawReadIo
/* ECBAEC 80241DEC 0200302D */   daddu    $a2, $s0, $zero
/* ECBAF0 80241DF0 4405E000 */  mfc1      $a1, $f28
/* ECBAF4 80241DF4 4406D000 */  mfc1      $a2, $f26
/* ECBAF8 80241DF8 4407C000 */  mfc1      $a3, $f24
/* ECBAFC 80241DFC 0C09070C */  jal       func_80241C30_ECB930
/* ECBB00 80241E00 27A40010 */   addiu    $a0, $sp, 0x10
/* ECBB04 80241E04 27A40010 */  addiu     $a0, $sp, 0x10
/* ECBB08 80241E08 0200282D */  daddu     $a1, $s0, $zero
/* ECBB0C 80241E0C 0C01B1F0 */  jal       osSiRawReadIo
/* ECBB10 80241E10 0200302D */   daddu    $a2, $s0, $zero
/* ECBB14 80241E14 27A40010 */  addiu     $a0, $sp, 0x10
/* ECBB18 80241E18 4600B587 */  neg.s     $f22, $f22
/* ECBB1C 80241E1C 4405A000 */  mfc1      $a1, $f20
/* ECBB20 80241E20 4406B000 */  mfc1      $a2, $f22
/* ECBB24 80241E24 0C01B2B0 */  jal       func_8006CAC0
/* ECBB28 80241E28 00A0382D */   daddu    $a3, $a1, $zero
/* ECBB2C 80241E2C 27A40010 */  addiu     $a0, $sp, 0x10
/* ECBB30 80241E30 0200282D */  daddu     $a1, $s0, $zero
/* ECBB34 80241E34 0C01B1F0 */  jal       osSiRawReadIo
/* ECBB38 80241E38 00A0302D */   daddu    $a2, $a1, $zero
.L80241E3C:
/* ECBB3C 80241E3C 8FBF005C */  lw        $ra, 0x5c($sp)
/* ECBB40 80241E40 8FB20058 */  lw        $s2, 0x58($sp)
/* ECBB44 80241E44 8FB10054 */  lw        $s1, 0x54($sp)
/* ECBB48 80241E48 8FB00050 */  lw        $s0, 0x50($sp)
/* ECBB4C 80241E4C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* ECBB50 80241E50 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* ECBB54 80241E54 D7B80070 */  ldc1      $f24, 0x70($sp)
/* ECBB58 80241E58 D7B60068 */  ldc1      $f22, 0x68($sp)
/* ECBB5C 80241E5C D7B40060 */  ldc1      $f20, 0x60($sp)
/* ECBB60 80241E60 24020002 */  addiu     $v0, $zero, 2
/* ECBB64 80241E64 03E00008 */  jr        $ra
/* ECBB68 80241E68 27BD0088 */   addiu    $sp, $sp, 0x88
/* ECBB6C 80241E6C 00000000 */  nop       
