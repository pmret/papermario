.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DCB7C
/* 7602C 800DCB7C 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 76030 800DCB80 AFB40048 */  sw        $s4, 0x48($sp)
/* 76034 800DCB84 8FB40090 */  lw        $s4, 0x90($sp)
/* 76038 800DCB88 AFBF004C */  sw        $ra, 0x4c($sp)
/* 7603C 800DCB8C AFB30044 */  sw        $s3, 0x44($sp)
/* 76040 800DCB90 AFB20040 */  sw        $s2, 0x40($sp)
/* 76044 800DCB94 AFB1003C */  sw        $s1, 0x3c($sp)
/* 76048 800DCB98 AFB00038 */  sw        $s0, 0x38($sp)
/* 7604C 800DCB9C F7BE0078 */  sdc1      $f30, 0x78($sp)
/* 76050 800DCBA0 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 76054 800DCBA4 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 76058 800DCBA8 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 7605C 800DCBAC F7B60058 */  sdc1      $f22, 0x58($sp)
/* 76060 800DCBB0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 76064 800DCBB4 C4A60000 */  lwc1      $f6, ($a1)
/* 76068 800DCBB8 00C0882D */  daddu     $s1, $a2, $zero
/* 7606C 800DCBBC E7A60028 */  swc1      $f6, 0x28($sp)
/* 76070 800DCBC0 C63E0000 */  lwc1      $f30, ($s1)
/* 76074 800DCBC4 C4E60000 */  lwc1      $f6, ($a3)
/* 76078 800DCBC8 3C128011 */  lui       $s2, %hi(D_8010C970)
/* 7607C 800DCBCC 2652C970 */  addiu     $s2, $s2, %lo(D_8010C970)
/* 76080 800DCBD0 E7A6002C */  swc1      $f6, 0x2c($sp)
/* 76084 800DCBD4 4600F18D */  trunc.w.s $f6, $f30
/* 76088 800DCBD8 E6460000 */  swc1      $f6, ($s2)
/* 7608C 800DCBDC C6200000 */  lwc1      $f0, ($s1)
/* 76090 800DCBE0 4600018D */  trunc.w.s $f6, $f0
/* 76094 800DCBE4 3C018011 */  lui       $at, %hi(D_8010C94C)
/* 76098 800DCBE8 E426C94C */  swc1      $f6, %lo(D_8010C94C)($at)
/* 7609C 800DCBEC C6200000 */  lwc1      $f0, ($s1)
/* 760A0 800DCBF0 0080982D */  daddu     $s3, $a0, $zero
/* 760A4 800DCBF4 4600018D */  trunc.w.s $f6, $f0
/* 760A8 800DCBF8 3C018011 */  lui       $at, %hi(D_8010C974)
/* 760AC 800DCBFC E426C974 */  swc1      $f6, %lo(D_8010C974)($at)
/* 760B0 800DCC00 C6800000 */  lwc1      $f0, ($s4)
/* 760B4 800DCC04 44806000 */  mtc1      $zero, $f12
/* 760B8 800DCC08 0C00A6C9 */  jal       clamp_angle
/* 760BC 800DCC0C 46000605 */   abs.s    $f24, $f0
/* 760C0 800DCC10 3C0140C9 */  lui       $at, 0x40c9
/* 760C4 800DCC14 34210FD0 */  ori       $at, $at, 0xfd0
/* 760C8 800DCC18 44811000 */  mtc1      $at, $f2
/* 760CC 800DCC1C 00000000 */  nop
/* 760D0 800DCC20 46020002 */  mul.s     $f0, $f0, $f2
/* 760D4 800DCC24 00000000 */  nop
/* 760D8 800DCC28 3C0143B4 */  lui       $at, 0x43b4
/* 760DC 800DCC2C 44811000 */  mtc1      $at, $f2
/* 760E0 800DCC30 00000000 */  nop
/* 760E4 800DCC34 46020503 */  div.s     $f20, $f0, $f2
/* 760E8 800DCC38 0C00A85B */  jal       sin_rad
/* 760EC 800DCC3C 4600A306 */   mov.s    $f12, $f20
/* 760F0 800DCC40 46000586 */  mov.s     $f22, $f0
/* 760F4 800DCC44 0C00A874 */  jal       cos_rad
/* 760F8 800DCC48 4600A306 */   mov.s    $f12, $f20
/* 760FC 800DCC4C 3C014120 */  lui       $at, 0x4120
/* 76100 800DCC50 44813000 */  mtc1      $at, $f6
/* 76104 800DCC54 00000000 */  nop
/* 76108 800DCC58 4606B102 */  mul.s     $f4, $f22, $f6
/* 7610C 800DCC5C 00000000 */  nop
/* 76110 800DCC60 0000802D */  daddu     $s0, $zero, $zero
/* 76114 800DCC64 0260202D */  daddu     $a0, $s3, $zero
/* 76118 800DCC68 27A50018 */  addiu     $a1, $sp, 0x18
/* 7611C 800DCC6C 46003087 */  neg.s     $f2, $f6
/* 76120 800DCC70 46020002 */  mul.s     $f0, $f0, $f2
/* 76124 800DCC74 00000000 */  nop
/* 76128 800DCC78 27A6001C */  addiu     $a2, $sp, 0x1c
/* 7612C 800DCC7C 27A70020 */  addiu     $a3, $sp, 0x20
/* 76130 800DCC80 C7A60028 */  lwc1      $f6, 0x28($sp)
/* 76134 800DCC84 3C01C6FF */  lui       $at, 0xc6ff
/* 76138 800DCC88 3421FE00 */  ori       $at, $at, 0xfe00
/* 7613C 800DCC8C 4481D000 */  mtc1      $at, $f26
/* 76140 800DCC90 46043080 */  add.s     $f2, $f6, $f4
/* 76144 800DCC94 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* 76148 800DCC98 27A20024 */  addiu     $v0, $sp, 0x24
/* 7614C 800DCC9C E7BE001C */  swc1      $f30, 0x1c($sp)
/* 76150 800DCCA0 E7B80024 */  swc1      $f24, 0x24($sp)
/* 76154 800DCCA4 46003000 */  add.s     $f0, $f6, $f0
/* 76158 800DCCA8 4600D706 */  mov.s     $f28, $f26
/* 7615C 800DCCAC E7A20018 */  swc1      $f2, 0x18($sp)
/* 76160 800DCCB0 E7A00020 */  swc1      $f0, 0x20($sp)
/* 76164 800DCCB4 0C037140 */  jal       func_800DC500
/* 76168 800DCCB8 AFA20010 */   sw       $v0, 0x10($sp)
/* 7616C 800DCCBC 0440000F */  bltz      $v0, .L800DCCFC
/* 76170 800DCCC0 E7B80030 */   swc1     $f24, 0x30($sp)
/* 76174 800DCCC4 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 76178 800DCCC8 4618003E */  c.le.s    $f0, $f24
/* 7617C 800DCCCC 00000000 */  nop
/* 76180 800DCCD0 4500000A */  bc1f      .L800DCCFC
/* 76184 800DCCD4 00000000 */   nop
/* 76188 800DCCD8 46000606 */  mov.s     $f24, $f0
/* 7618C 800DCCDC C7BA001C */  lwc1      $f26, 0x1c($sp)
/* 76190 800DCCE0 24100001 */  addiu     $s0, $zero, 1
/* 76194 800DCCE4 3C018011 */  lui       $at, %hi(D_8010C978)
/* 76198 800DCCE8 AC22C978 */  sw        $v0, %lo(D_8010C978)($at)
/* 7619C 800DCCEC 3C018011 */  lui       $at, %hi(D_8010C98C)
/* 761A0 800DCCF0 AC22C98C */  sw        $v0, %lo(D_8010C98C)($at)
/* 761A4 800DCCF4 4600D18D */  trunc.w.s $f6, $f26
/* 761A8 800DCCF8 E6460000 */  swc1      $f6, ($s2)
.L800DCCFC:
/* 761AC 800DCCFC 3C014334 */  lui       $at, 0x4334
/* 761B0 800DCD00 44816000 */  mtc1      $at, $f12
/* 761B4 800DCD04 44803000 */  mtc1      $zero, $f6
/* 761B8 800DCD08 0C00A6C9 */  jal       clamp_angle
/* 761BC 800DCD0C 460C3300 */   add.s    $f12, $f6, $f12
/* 761C0 800DCD10 3C0140C9 */  lui       $at, 0x40c9
/* 761C4 800DCD14 34210FD0 */  ori       $at, $at, 0xfd0
/* 761C8 800DCD18 44811000 */  mtc1      $at, $f2
/* 761CC 800DCD1C 00000000 */  nop
/* 761D0 800DCD20 46020002 */  mul.s     $f0, $f0, $f2
/* 761D4 800DCD24 00000000 */  nop
/* 761D8 800DCD28 3C0143B4 */  lui       $at, 0x43b4
/* 761DC 800DCD2C 44811000 */  mtc1      $at, $f2
/* 761E0 800DCD30 00000000 */  nop
/* 761E4 800DCD34 46020503 */  div.s     $f20, $f0, $f2
/* 761E8 800DCD38 0C00A85B */  jal       sin_rad
/* 761EC 800DCD3C 4600A306 */   mov.s    $f12, $f20
/* 761F0 800DCD40 46000586 */  mov.s     $f22, $f0
/* 761F4 800DCD44 0C00A874 */  jal       cos_rad
/* 761F8 800DCD48 4600A306 */   mov.s    $f12, $f20
/* 761FC 800DCD4C 3C014120 */  lui       $at, 0x4120
/* 76200 800DCD50 44813000 */  mtc1      $at, $f6
/* 76204 800DCD54 00000000 */  nop
/* 76208 800DCD58 46163102 */  mul.s     $f4, $f6, $f22
/* 7620C 800DCD5C 00000000 */  nop
/* 76210 800DCD60 46003087 */  neg.s     $f2, $f6
/* 76214 800DCD64 46001002 */  mul.s     $f0, $f2, $f0
/* 76218 800DCD68 00000000 */  nop
/* 7621C 800DCD6C 0260202D */  daddu     $a0, $s3, $zero
/* 76220 800DCD70 27A50018 */  addiu     $a1, $sp, 0x18
/* 76224 800DCD74 C7A60028 */  lwc1      $f6, 0x28($sp)
/* 76228 800DCD78 27A6001C */  addiu     $a2, $sp, 0x1c
/* 7622C 800DCD7C 46043080 */  add.s     $f2, $f6, $f4
/* 76230 800DCD80 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* 76234 800DCD84 27A70020 */  addiu     $a3, $sp, 0x20
/* 76238 800DCD88 46003000 */  add.s     $f0, $f6, $f0
/* 7623C 800DCD8C C7A60030 */  lwc1      $f6, 0x30($sp)
/* 76240 800DCD90 27A20024 */  addiu     $v0, $sp, 0x24
/* 76244 800DCD94 E7BE001C */  swc1      $f30, 0x1c($sp)
/* 76248 800DCD98 E7A60024 */  swc1      $f6, 0x24($sp)
/* 7624C 800DCD9C E7A20018 */  swc1      $f2, 0x18($sp)
/* 76250 800DCDA0 E7A00020 */  swc1      $f0, 0x20($sp)
/* 76254 800DCDA4 0C037140 */  jal       func_800DC500
/* 76258 800DCDA8 AFA20010 */   sw       $v0, 0x10($sp)
/* 7625C 800DCDAC 04400010 */  bltz      $v0, .L800DCDF0
/* 76260 800DCDB0 00000000 */   nop
/* 76264 800DCDB4 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 76268 800DCDB8 4618003E */  c.le.s    $f0, $f24
/* 7626C 800DCDBC 00000000 */  nop
/* 76270 800DCDC0 4500000B */  bc1f      .L800DCDF0
/* 76274 800DCDC4 00000000 */   nop
/* 76278 800DCDC8 46000606 */  mov.s     $f24, $f0
/* 7627C 800DCDCC C7BC001C */  lwc1      $f28, 0x1c($sp)
/* 76280 800DCDD0 24100001 */  addiu     $s0, $zero, 1
/* 76284 800DCDD4 3C018011 */  lui       $at, %hi(D_8010C978)
/* 76288 800DCDD8 AC22C978 */  sw        $v0, %lo(D_8010C978)($at)
/* 7628C 800DCDDC 3C018011 */  lui       $at, %hi(D_8010C968)
/* 76290 800DCDE0 AC22C968 */  sw        $v0, %lo(D_8010C968)($at)
/* 76294 800DCDE4 4600E18D */  trunc.w.s $f6, $f28
/* 76298 800DCDE8 3C018011 */  lui       $at, %hi(D_8010C94C)
/* 7629C 800DCDEC E426C94C */  swc1      $f6, %lo(D_8010C94C)($at)
.L800DCDF0:
/* 762A0 800DCDF0 12000011 */  beqz      $s0, .L800DCE38
/* 762A4 800DCDF4 0000102D */   daddu    $v0, $zero, $zero
/* 762A8 800DCDF8 461CD03C */  c.lt.s    $f26, $f28
/* 762AC 800DCDFC 00000000 */  nop
/* 762B0 800DCE00 45020002 */  bc1fl     .L800DCE0C
/* 762B4 800DCE04 E63A0000 */   swc1     $f26, ($s1)
/* 762B8 800DCE08 E63C0000 */  swc1      $f28, ($s1)
.L800DCE0C:
/* 762BC 800DCE0C C6200000 */  lwc1      $f0, ($s1)
/* 762C0 800DCE10 3C01C6FF */  lui       $at, 0xc6ff
/* 762C4 800DCE14 3421FE00 */  ori       $at, $at, 0xfe00
/* 762C8 800DCE18 44813000 */  mtc1      $at, $f6
/* 762CC 800DCE1C 00000000 */  nop
/* 762D0 800DCE20 4606003C */  c.lt.s    $f0, $f6
/* 762D4 800DCE24 00000000 */  nop
/* 762D8 800DCE28 45030001 */  bc1tl     .L800DCE30
/* 762DC 800DCE2C E6260000 */   swc1     $f6, ($s1)
.L800DCE30:
/* 762E0 800DCE30 E6980000 */  swc1      $f24, ($s4)
/* 762E4 800DCE34 24020001 */  addiu     $v0, $zero, 1
.L800DCE38:
/* 762E8 800DCE38 8FBF004C */  lw        $ra, 0x4c($sp)
/* 762EC 800DCE3C 8FB40048 */  lw        $s4, 0x48($sp)
/* 762F0 800DCE40 8FB30044 */  lw        $s3, 0x44($sp)
/* 762F4 800DCE44 8FB20040 */  lw        $s2, 0x40($sp)
/* 762F8 800DCE48 8FB1003C */  lw        $s1, 0x3c($sp)
/* 762FC 800DCE4C 8FB00038 */  lw        $s0, 0x38($sp)
/* 76300 800DCE50 D7BE0078 */  ldc1      $f30, 0x78($sp)
/* 76304 800DCE54 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 76308 800DCE58 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 7630C 800DCE5C D7B80060 */  ldc1      $f24, 0x60($sp)
/* 76310 800DCE60 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 76314 800DCE64 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 76318 800DCE68 03E00008 */  jr        $ra
/* 7631C 800DCE6C 27BD0080 */   addiu    $sp, $sp, 0x80
