.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238BCC_6F1CAC
/* 6F1CAC 80238BCC 3C02800E */  lui       $v0, %hi(gBattleStatus+0xDC)
/* 6F1CB0 80238BD0 8C42C14C */  lw        $v0, %lo(gBattleStatus+0xDC)($v0)
/* 6F1CB4 80238BD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6F1CB8 80238BD8 AFB00010 */  sw        $s0, 0x10($sp)
/* 6F1CBC 80238BDC 0080802D */  daddu     $s0, $a0, $zero
/* 6F1CC0 80238BE0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6F1CC4 80238BE4 0C09A75B */  jal       get_actor
/* 6F1CC8 80238BE8 84440428 */   lh       $a0, 0x428($v0)
/* 6F1CCC 80238BEC 0040202D */  daddu     $a0, $v0, $zero
/* 6F1CD0 80238BF0 8C820000 */  lw        $v0, ($a0)
/* 6F1CD4 80238BF4 30420800 */  andi      $v0, $v0, 0x800
/* 6F1CD8 80238BF8 14400022 */  bnez      $v0, .L80238C84
/* 6F1CDC 80238BFC 00000000 */   nop
/* 6F1CE0 80238C00 90830191 */  lbu       $v1, 0x191($a0)
/* 6F1CE4 80238C04 3C02AAAA */  lui       $v0, 0xaaaa
/* 6F1CE8 80238C08 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 6F1CEC 80238C0C 00620019 */  multu     $v1, $v0
/* 6F1CF0 80238C10 C4800188 */  lwc1      $f0, 0x188($a0)
/* 6F1CF4 80238C14 00003010 */  mfhi      $a2
/* 6F1CF8 80238C18 00061042 */  srl       $v0, $a2, 1
/* 6F1CFC 80238C1C 304200FF */  andi      $v0, $v0, 0xff
/* 6F1D00 80238C20 44821000 */  mtc1      $v0, $f2
/* 6F1D04 80238C24 00000000 */  nop
/* 6F1D08 80238C28 468010A0 */  cvt.s.w   $f2, $f2
/* 6F1D0C 80238C2C 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1D10 80238C30 00000000 */  nop
/* 6F1D14 80238C34 C6000088 */  lwc1      $f0, 0x88($s0)
/* 6F1D18 80238C38 46800020 */  cvt.s.w   $f0, $f0
/* 6F1D1C 80238C3C 46020000 */  add.s     $f0, $f0, $f2
/* 6F1D20 80238C40 4600010D */  trunc.w.s $f4, $f0
/* 6F1D24 80238C44 44032000 */  mfc1      $v1, $f4
/* 6F1D28 80238C48 00000000 */  nop
/* 6F1D2C 80238C4C AE030088 */  sw        $v1, 0x88($s0)
/* 6F1D30 80238C50 90820191 */  lbu       $v0, 0x191($a0)
/* 6F1D34 80238C54 C4800188 */  lwc1      $f0, 0x188($a0)
/* 6F1D38 80238C58 00021082 */  srl       $v0, $v0, 2
/* 6F1D3C 80238C5C 44821000 */  mtc1      $v0, $f2
/* 6F1D40 80238C60 00000000 */  nop
/* 6F1D44 80238C64 468010A0 */  cvt.s.w   $f2, $f2
/* 6F1D48 80238C68 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1D4C 80238C6C 00000000 */  nop
/* 6F1D50 80238C70 44830000 */  mtc1      $v1, $f0
/* 6F1D54 80238C74 00000000 */  nop
/* 6F1D58 80238C78 46800020 */  cvt.s.w   $f0, $f0
/* 6F1D5C 80238C7C 0808E341 */  j         .L80238D04
/* 6F1D60 80238C80 46020000 */   add.s    $f0, $f0, $f2
.L80238C84:
/* 6F1D64 80238C84 90830191 */  lbu       $v1, 0x191($a0)
/* 6F1D68 80238C88 3C02AAAA */  lui       $v0, 0xaaaa
/* 6F1D6C 80238C8C 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 6F1D70 80238C90 00620019 */  multu     $v1, $v0
/* 6F1D74 80238C94 C4800188 */  lwc1      $f0, 0x188($a0)
/* 6F1D78 80238C98 00003010 */  mfhi      $a2
/* 6F1D7C 80238C9C 00061042 */  srl       $v0, $a2, 1
/* 6F1D80 80238CA0 304200FF */  andi      $v0, $v0, 0xff
/* 6F1D84 80238CA4 44821000 */  mtc1      $v0, $f2
/* 6F1D88 80238CA8 00000000 */  nop
/* 6F1D8C 80238CAC 468010A0 */  cvt.s.w   $f2, $f2
/* 6F1D90 80238CB0 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1D94 80238CB4 00000000 */  nop
/* 6F1D98 80238CB8 C6000088 */  lwc1      $f0, 0x88($s0)
/* 6F1D9C 80238CBC 46800020 */  cvt.s.w   $f0, $f0
/* 6F1DA0 80238CC0 46020001 */  sub.s     $f0, $f0, $f2
/* 6F1DA4 80238CC4 4600010D */  trunc.w.s $f4, $f0
/* 6F1DA8 80238CC8 44032000 */  mfc1      $v1, $f4
/* 6F1DAC 80238CCC 00000000 */  nop
/* 6F1DB0 80238CD0 AE030088 */  sw        $v1, 0x88($s0)
/* 6F1DB4 80238CD4 90820191 */  lbu       $v0, 0x191($a0)
/* 6F1DB8 80238CD8 C4800188 */  lwc1      $f0, 0x188($a0)
/* 6F1DBC 80238CDC 00021082 */  srl       $v0, $v0, 2
/* 6F1DC0 80238CE0 44821000 */  mtc1      $v0, $f2
/* 6F1DC4 80238CE4 00000000 */  nop
/* 6F1DC8 80238CE8 468010A0 */  cvt.s.w   $f2, $f2
/* 6F1DCC 80238CEC 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1DD0 80238CF0 00000000 */  nop
/* 6F1DD4 80238CF4 44830000 */  mtc1      $v1, $f0
/* 6F1DD8 80238CF8 00000000 */  nop
/* 6F1DDC 80238CFC 46800020 */  cvt.s.w   $f0, $f0
/* 6F1DE0 80238D00 46020001 */  sub.s     $f0, $f0, $f2
.L80238D04:
/* 6F1DE4 80238D04 4600010D */  trunc.w.s $f4, $f0
/* 6F1DE8 80238D08 E6040088 */  swc1      $f4, 0x88($s0)
/* 6F1DEC 80238D0C 8C820000 */  lw        $v0, ($a0)
/* 6F1DF0 80238D10 30428000 */  andi      $v0, $v0, 0x8000
/* 6F1DF4 80238D14 1040000E */  beqz      $v0, .L80238D50
/* 6F1DF8 80238D18 00000000 */   nop
/* 6F1DFC 80238D1C 90820191 */  lbu       $v0, 0x191($a0)
/* 6F1E00 80238D20 C4800188 */  lwc1      $f0, 0x188($a0)
/* 6F1E04 80238D24 00021042 */  srl       $v0, $v0, 1
/* 6F1E08 80238D28 44821000 */  mtc1      $v0, $f2
/* 6F1E0C 80238D2C 00000000 */  nop
/* 6F1E10 80238D30 468010A0 */  cvt.s.w   $f2, $f2
/* 6F1E14 80238D34 46001082 */  mul.s     $f2, $f2, $f0
/* 6F1E18 80238D38 00000000 */  nop
/* 6F1E1C 80238D3C C6000088 */  lwc1      $f0, 0x88($s0)
/* 6F1E20 80238D40 46800020 */  cvt.s.w   $f0, $f0
/* 6F1E24 80238D44 46020001 */  sub.s     $f0, $f0, $f2
/* 6F1E28 80238D48 4600010D */  trunc.w.s $f4, $f0
/* 6F1E2C 80238D4C E6040088 */  swc1      $f4, 0x88($s0)
.L80238D50:
/* 6F1E30 80238D50 90820191 */  lbu       $v0, 0x191($a0)
/* 6F1E34 80238D54 C4820188 */  lwc1      $f2, 0x188($a0)
/* 6F1E38 80238D58 44820000 */  mtc1      $v0, $f0
/* 6F1E3C 80238D5C 00000000 */  nop
/* 6F1E40 80238D60 46800020 */  cvt.s.w   $f0, $f0
/* 6F1E44 80238D64 46020002 */  mul.s     $f0, $f0, $f2
/* 6F1E48 80238D68 00000000 */  nop
/* 6F1E4C 80238D6C 90850190 */  lbu       $a1, 0x190($a0)
/* 6F1E50 80238D70 4600010D */  trunc.w.s $f4, $f0
/* 6F1E54 80238D74 44032000 */  mfc1      $v1, $f4
/* 6F1E58 80238D78 00000000 */  nop
/* 6F1E5C 80238D7C 0065102A */  slt       $v0, $v1, $a1
/* 6F1E60 80238D80 54400001 */  bnel      $v0, $zero, .L80238D88
/* 6F1E64 80238D84 00A0182D */   daddu    $v1, $a1, $zero
.L80238D88:
/* 6F1E68 80238D88 2462004C */  addiu     $v0, $v1, 0x4c
/* 6F1E6C 80238D8C AE020090 */  sw        $v0, 0x90($s0)
/* 6F1E70 80238D90 90820136 */  lbu       $v0, 0x136($a0)
/* 6F1E74 80238D94 00021080 */  sll       $v0, $v0, 2
/* 6F1E78 80238D98 3C038028 */  lui       $v1, %hi(bActorOffsets)
/* 6F1E7C 80238D9C 00621821 */  addu      $v1, $v1, $v0
/* 6F1E80 80238DA0 80632EE8 */  lb        $v1, %lo(bActorOffsets)($v1)
/* 6F1E84 80238DA4 8E020084 */  lw        $v0, 0x84($s0)
/* 6F1E88 80238DA8 00431021 */  addu      $v0, $v0, $v1
/* 6F1E8C 80238DAC AE020084 */  sw        $v0, 0x84($s0)
/* 6F1E90 80238DB0 90820136 */  lbu       $v0, 0x136($a0)
/* 6F1E94 80238DB4 00021080 */  sll       $v0, $v0, 2
/* 6F1E98 80238DB8 3C038028 */  lui       $v1, %hi(D_80282EE9)
/* 6F1E9C 80238DBC 00621821 */  addu      $v1, $v1, $v0
/* 6F1EA0 80238DC0 80632EE9 */  lb        $v1, %lo(D_80282EE9)($v1)
/* 6F1EA4 80238DC4 8E020088 */  lw        $v0, 0x88($s0)
/* 6F1EA8 80238DC8 00431021 */  addu      $v0, $v0, $v1
/* 6F1EAC 80238DCC AE020088 */  sw        $v0, 0x88($s0)
/* 6F1EB0 80238DD0 90820136 */  lbu       $v0, 0x136($a0)
/* 6F1EB4 80238DD4 8E030090 */  lw        $v1, 0x90($s0)
/* 6F1EB8 80238DD8 00021080 */  sll       $v0, $v0, 2
/* 6F1EBC 80238DDC 3C048028 */  lui       $a0, %hi(D_80282EEA)
/* 6F1EC0 80238DE0 00822021 */  addu      $a0, $a0, $v0
/* 6F1EC4 80238DE4 80842EEA */  lb        $a0, %lo(D_80282EEA)($a0)
/* 6F1EC8 80238DE8 00641821 */  addu      $v1, $v1, $a0
/* 6F1ECC 80238DEC AE030090 */  sw        $v1, 0x90($s0)
/* 6F1ED0 80238DF0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6F1ED4 80238DF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 6F1ED8 80238DF8 24020002 */  addiu     $v0, $zero, 2
/* 6F1EDC 80238DFC 03E00008 */  jr        $ra
/* 6F1EE0 80238E00 27BD0018 */   addiu    $sp, $sp, 0x18
