.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_47_update
/* 362778 E005E1B8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 36277C E005E1BC AFB20018 */  sw        $s2, 0x18($sp)
/* 362780 E005E1C0 0080902D */  daddu     $s2, $a0, $zero
/* 362784 E005E1C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 362788 E005E1C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 36278C E005E1CC AFB00010 */  sw        $s0, 0x10($sp)
/* 362790 E005E1D0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 362794 E005E1D4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 362798 E005E1D8 8E43000C */  lw        $v1, 0xc($s2)
/* 36279C E005E1DC 8C620028 */  lw        $v0, 0x28($v1)
/* 3627A0 E005E1E0 10400043 */  beqz      $v0, .LE005E2F0
/* 3627A4 E005E1E4 24110001 */   addiu    $s1, $zero, 1
/* 3627A8 E005E1E8 C4620010 */  lwc1      $f2, 0x10($v1)
/* 3627AC E005E1EC C4600014 */  lwc1      $f0, 0x14($v1)
/* 3627B0 E005E1F0 46020001 */  sub.s     $f0, $f0, $f2
/* 3627B4 E005E1F4 3C01E006 */  lui       $at, %hi(D_E005E680)
/* 3627B8 E005E1F8 D424E680 */  ldc1      $f4, %lo(D_E005E680)($at)
/* 3627BC E005E1FC 46000021 */  cvt.d.s   $f0, $f0
/* 3627C0 E005E200 46240002 */  mul.d     $f0, $f0, $f4
/* 3627C4 E005E204 00000000 */  nop
/* 3627C8 E005E208 8C620024 */  lw        $v0, 0x24($v1)
/* 3627CC E005E20C 460010A1 */  cvt.d.s   $f2, $f2
/* 3627D0 E005E210 46201080 */  add.d     $f2, $f2, $f0
/* 3627D4 E005E214 00511021 */  addu      $v0, $v0, $s1
/* 3627D8 E005E218 AC620024 */  sw        $v0, 0x24($v1)
/* 3627DC E005E21C 462010A0 */  cvt.s.d   $f2, $f2
/* 3627E0 E005E220 E4620010 */  swc1      $f2, 0x10($v1)
/* 3627E4 E005E224 2463002C */  addiu     $v1, $v1, 0x2c
/* 3627E8 E005E228 8E420008 */  lw        $v0, 8($s2)
/* 3627EC E005E22C 0222102A */  slt       $v0, $s1, $v0
/* 3627F0 E005E230 1040002F */  beqz      $v0, .LE005E2F0
/* 3627F4 E005E234 46001586 */   mov.s    $f22, $f2
/* 3627F8 E005E238 24700024 */  addiu     $s0, $v1, 0x24
.LE005E23C:
/* 3627FC E005E23C C60C0000 */  lwc1      $f12, ($s0)
/* 362800 E005E240 0C080140 */  jal       shim_sin_deg
/* 362804 E005E244 46806320 */   cvt.s.w  $f12, $f12
/* 362808 E005E248 4600B002 */  mul.s     $f0, $f22, $f0
/* 36280C E005E24C 00000000 */  nop
/* 362810 E005E250 C60C0000 */  lwc1      $f12, ($s0)
/* 362814 E005E254 46806320 */  cvt.s.w   $f12, $f12
/* 362818 E005E258 0C080144 */  jal       shim_cos_deg
/* 36281C E005E25C E600FFE0 */   swc1     $f0, -0x20($s0)
/* 362820 E005E260 C60CFFFC */  lwc1      $f12, -4($s0)
/* 362824 E005E264 0C080144 */  jal       shim_cos_deg
/* 362828 E005E268 46000506 */   mov.s    $f20, $f0
/* 36282C E005E26C 4614B502 */  mul.s     $f20, $f22, $f20
/* 362830 E005E270 00000000 */  nop
/* 362834 E005E274 4600A502 */  mul.s     $f20, $f20, $f0
/* 362838 E005E278 00000000 */  nop
/* 36283C E005E27C C60C0000 */  lwc1      $f12, ($s0)
/* 362840 E005E280 46806320 */  cvt.s.w   $f12, $f12
/* 362844 E005E284 0C080144 */  jal       shim_cos_deg
/* 362848 E005E288 E614FFE8 */   swc1     $f20, -0x18($s0)
/* 36284C E005E28C C60CFFFC */  lwc1      $f12, -4($s0)
/* 362850 E005E290 0C080140 */  jal       shim_sin_deg
/* 362854 E005E294 46000506 */   mov.s    $f20, $f0
/* 362858 E005E298 4614B502 */  mul.s     $f20, $f22, $f20
/* 36285C E005E29C 00000000 */  nop
/* 362860 E005E2A0 C602FFF8 */  lwc1      $f2, -8($s0)
/* 362864 E005E2A4 8E030000 */  lw        $v1, ($s0)
/* 362868 E005E2A8 4600A502 */  mul.s     $f20, $f20, $f0
/* 36286C E005E2AC 00000000 */  nop
/* 362870 E005E2B0 AE00FFFC */  sw        $zero, -4($s0)
/* 362874 E005E2B4 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 362878 E005E2B8 24620010 */  addiu     $v0, $v1, 0x10
/* 36287C E005E2BC 46020000 */  add.s     $f0, $f0, $f2
/* 362880 E005E2C0 AE020000 */  sw        $v0, ($s0)
/* 362884 E005E2C4 28420169 */  slti      $v0, $v0, 0x169
/* 362888 E005E2C8 E600FFF4 */  swc1      $f0, -0xc($s0)
/* 36288C E005E2CC 14400003 */  bnez      $v0, .LE005E2DC
/* 362890 E005E2D0 E614FFE4 */   swc1     $f20, -0x1c($s0)
/* 362894 E005E2D4 2462FEA8 */  addiu     $v0, $v1, -0x158
/* 362898 E005E2D8 AE020000 */  sw        $v0, ($s0)
.LE005E2DC:
/* 36289C E005E2DC 26310001 */  addiu     $s1, $s1, 1
/* 3628A0 E005E2E0 8E420008 */  lw        $v0, 8($s2)
/* 3628A4 E005E2E4 0222102A */  slt       $v0, $s1, $v0
/* 3628A8 E005E2E8 1440FFD4 */  bnez      $v0, .LE005E23C
/* 3628AC E005E2EC 2610002C */   addiu    $s0, $s0, 0x2c
.LE005E2F0:
/* 3628B0 E005E2F0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3628B4 E005E2F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 3628B8 E005E2F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 3628BC E005E2FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3628C0 E005E300 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 3628C4 E005E304 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 3628C8 E005E308 03E00008 */  jr        $ra
/* 3628CC E005E30C 27BD0030 */   addiu    $sp, $sp, 0x30
