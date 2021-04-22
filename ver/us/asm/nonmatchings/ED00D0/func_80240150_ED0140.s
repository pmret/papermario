.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240150_ED0140
/* ED0140 80240150 27BDFF78 */  addiu     $sp, $sp, -0x88
/* ED0144 80240154 AFB10054 */  sw        $s1, 0x54($sp)
/* ED0148 80240158 0080882D */  daddu     $s1, $a0, $zero
/* ED014C 8024015C AFBF005C */  sw        $ra, 0x5c($sp)
/* ED0150 80240160 AFB20058 */  sw        $s2, 0x58($sp)
/* ED0154 80240164 AFB00050 */  sw        $s0, 0x50($sp)
/* ED0158 80240168 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* ED015C 8024016C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* ED0160 80240170 F7B80070 */  sdc1      $f24, 0x70($sp)
/* ED0164 80240174 F7B60068 */  sdc1      $f22, 0x68($sp)
/* ED0168 80240178 F7B40060 */  sdc1      $f20, 0x60($sp)
/* ED016C 8024017C 8E30000C */  lw        $s0, 0xc($s1)
/* ED0170 80240180 8E050000 */  lw        $a1, ($s0)
/* ED0174 80240184 0C0B53A3 */  jal       dead_get_variable
/* ED0178 80240188 26100004 */   addiu    $s0, $s0, 4
/* ED017C 8024018C 0C04949C */  jal       func_80125270
/* ED0180 80240190 0040202D */   daddu    $a0, $v0, $zero
/* ED0184 80240194 8E050000 */  lw        $a1, ($s0)
/* ED0188 80240198 26100004 */  addiu     $s0, $s0, 4
/* ED018C 8024019C 0220202D */  daddu     $a0, $s1, $zero
/* ED0190 802401A0 0C0B55FF */  jal       dead_get_float_variable
/* ED0194 802401A4 0040902D */   daddu    $s2, $v0, $zero
/* ED0198 802401A8 8E050000 */  lw        $a1, ($s0)
/* ED019C 802401AC 26100004 */  addiu     $s0, $s0, 4
/* ED01A0 802401B0 0220202D */  daddu     $a0, $s1, $zero
/* ED01A4 802401B4 0C0B55FF */  jal       dead_get_float_variable
/* ED01A8 802401B8 46000706 */   mov.s    $f28, $f0
/* ED01AC 802401BC 8E050000 */  lw        $a1, ($s0)
/* ED01B0 802401C0 26100004 */  addiu     $s0, $s0, 4
/* ED01B4 802401C4 0220202D */  daddu     $a0, $s1, $zero
/* ED01B8 802401C8 0C0B55FF */  jal       dead_get_float_variable
/* ED01BC 802401CC 46000686 */   mov.s    $f26, $f0
/* ED01C0 802401D0 0220202D */  daddu     $a0, $s1, $zero
/* ED01C4 802401D4 8E050000 */  lw        $a1, ($s0)
/* ED01C8 802401D8 0C0B55FF */  jal       dead_get_float_variable
/* ED01CC 802401DC 46000586 */   mov.s    $f22, $f0
/* ED01D0 802401E0 0240202D */  daddu     $a0, $s2, $zero
/* ED01D4 802401E4 0C0493D1 */  jal       func_80124F44
/* ED01D8 802401E8 46000606 */   mov.s    $f24, $f0
/* ED01DC 802401EC 0040882D */  daddu     $s1, $v0, $zero
/* ED01E0 802401F0 96220000 */  lhu       $v0, ($s1)
/* ED01E4 802401F4 30420400 */  andi      $v0, $v0, 0x400
/* ED01E8 802401F8 1440001E */  bnez      $v0, .L80240274
/* ED01EC 802401FC 26300058 */   addiu    $s0, $s1, 0x58
/* ED01F0 80240200 4480A000 */  mtc1      $zero, $f20
/* ED01F4 80240204 4406B000 */  mfc1      $a2, $f22
/* ED01F8 80240208 4405A000 */  mfc1      $a1, $f20
/* ED01FC 8024020C 4407A000 */  mfc1      $a3, $f20
/* ED0200 80240210 0C01B2B0 */  jal       func_8006CAC0
/* ED0204 80240214 0200202D */   daddu    $a0, $s0, $zero
/* ED0208 80240218 4405E000 */  mfc1      $a1, $f28
/* ED020C 8024021C 4406D000 */  mfc1      $a2, $f26
/* ED0210 80240220 4407C000 */  mfc1      $a3, $f24
/* ED0214 80240224 0C090038 */  jal       func_802400E0_ED00D0
/* ED0218 80240228 27A40010 */   addiu    $a0, $sp, 0x10
/* ED021C 8024022C 27A40010 */  addiu     $a0, $sp, 0x10
/* ED0220 80240230 0200282D */  daddu     $a1, $s0, $zero
/* ED0224 80240234 0C01B1F0 */  jal       osSiRawReadIo
/* ED0228 80240238 0200302D */   daddu    $a2, $s0, $zero
/* ED022C 8024023C 27A40010 */  addiu     $a0, $sp, 0x10
/* ED0230 80240240 4600B587 */  neg.s     $f22, $f22
/* ED0234 80240244 4405A000 */  mfc1      $a1, $f20
/* ED0238 80240248 4406B000 */  mfc1      $a2, $f22
/* ED023C 8024024C 0C01B2B0 */  jal       func_8006CAC0
/* ED0240 80240250 00A0382D */   daddu    $a3, $a1, $zero
/* ED0244 80240254 27A40010 */  addiu     $a0, $sp, 0x10
/* ED0248 80240258 0200282D */  daddu     $a1, $s0, $zero
/* ED024C 8024025C 0C01B1F0 */  jal       osSiRawReadIo
/* ED0250 80240260 00A0302D */   daddu    $a2, $a1, $zero
/* ED0254 80240264 96220000 */  lhu       $v0, ($s1)
/* ED0258 80240268 34421400 */  ori       $v0, $v0, 0x1400
/* ED025C 8024026C 080900BB */  j         .L802402EC
/* ED0260 80240270 A6220000 */   sh       $v0, ($s1)
.L80240274:
/* ED0264 80240274 4480A000 */  mtc1      $zero, $f20
/* ED0268 80240278 4406B000 */  mfc1      $a2, $f22
/* ED026C 8024027C 4405A000 */  mfc1      $a1, $f20
/* ED0270 80240280 4407A000 */  mfc1      $a3, $f20
/* ED0274 80240284 0C01B2B0 */  jal       func_8006CAC0
/* ED0278 80240288 27A40010 */   addiu    $a0, $sp, 0x10
/* ED027C 8024028C 27A40010 */  addiu     $a0, $sp, 0x10
/* ED0280 80240290 26300058 */  addiu     $s0, $s1, 0x58
/* ED0284 80240294 0200282D */  daddu     $a1, $s0, $zero
/* ED0288 80240298 0C01B1F0 */  jal       osSiRawReadIo
/* ED028C 8024029C 0200302D */   daddu    $a2, $s0, $zero
/* ED0290 802402A0 4405E000 */  mfc1      $a1, $f28
/* ED0294 802402A4 4406D000 */  mfc1      $a2, $f26
/* ED0298 802402A8 4407C000 */  mfc1      $a3, $f24
/* ED029C 802402AC 0C090038 */  jal       func_802400E0_ED00D0
/* ED02A0 802402B0 27A40010 */   addiu    $a0, $sp, 0x10
/* ED02A4 802402B4 27A40010 */  addiu     $a0, $sp, 0x10
/* ED02A8 802402B8 0200282D */  daddu     $a1, $s0, $zero
/* ED02AC 802402BC 0C01B1F0 */  jal       osSiRawReadIo
/* ED02B0 802402C0 0200302D */   daddu    $a2, $s0, $zero
/* ED02B4 802402C4 27A40010 */  addiu     $a0, $sp, 0x10
/* ED02B8 802402C8 4600B587 */  neg.s     $f22, $f22
/* ED02BC 802402CC 4405A000 */  mfc1      $a1, $f20
/* ED02C0 802402D0 4406B000 */  mfc1      $a2, $f22
/* ED02C4 802402D4 0C01B2B0 */  jal       func_8006CAC0
/* ED02C8 802402D8 00A0382D */   daddu    $a3, $a1, $zero
/* ED02CC 802402DC 27A40010 */  addiu     $a0, $sp, 0x10
/* ED02D0 802402E0 0200282D */  daddu     $a1, $s0, $zero
/* ED02D4 802402E4 0C01B1F0 */  jal       osSiRawReadIo
/* ED02D8 802402E8 00A0302D */   daddu    $a2, $a1, $zero
.L802402EC:
/* ED02DC 802402EC 8FBF005C */  lw        $ra, 0x5c($sp)
/* ED02E0 802402F0 8FB20058 */  lw        $s2, 0x58($sp)
/* ED02E4 802402F4 8FB10054 */  lw        $s1, 0x54($sp)
/* ED02E8 802402F8 8FB00050 */  lw        $s0, 0x50($sp)
/* ED02EC 802402FC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* ED02F0 80240300 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* ED02F4 80240304 D7B80070 */  ldc1      $f24, 0x70($sp)
/* ED02F8 80240308 D7B60068 */  ldc1      $f22, 0x68($sp)
/* ED02FC 8024030C D7B40060 */  ldc1      $f20, 0x60($sp)
/* ED0300 80240310 24020002 */  addiu     $v0, $zero, 2
/* ED0304 80240314 03E00008 */  jr        $ra
/* ED0308 80240318 27BD0088 */   addiu    $sp, $sp, 0x88
/* ED030C 8024031C 00000000 */  nop
