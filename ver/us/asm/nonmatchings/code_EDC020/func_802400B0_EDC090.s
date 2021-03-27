.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B0_EDC090
/* EDC090 802400B0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* EDC094 802400B4 AFB10054 */  sw        $s1, 0x54($sp)
/* EDC098 802400B8 0080882D */  daddu     $s1, $a0, $zero
/* EDC09C 802400BC AFBF005C */  sw        $ra, 0x5c($sp)
/* EDC0A0 802400C0 AFB20058 */  sw        $s2, 0x58($sp)
/* EDC0A4 802400C4 AFB00050 */  sw        $s0, 0x50($sp)
/* EDC0A8 802400C8 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* EDC0AC 802400CC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* EDC0B0 802400D0 F7B80070 */  sdc1      $f24, 0x70($sp)
/* EDC0B4 802400D4 F7B60068 */  sdc1      $f22, 0x68($sp)
/* EDC0B8 802400D8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* EDC0BC 802400DC 8E30000C */  lw        $s0, 0xc($s1)
/* EDC0C0 802400E0 8E050000 */  lw        $a1, ($s0)
/* EDC0C4 802400E4 0C0B53A3 */  jal       dead_get_variable
/* EDC0C8 802400E8 26100004 */   addiu    $s0, $s0, 4
/* EDC0CC 802400EC 0C04949C */  jal       func_80125270
/* EDC0D0 802400F0 0040202D */   daddu    $a0, $v0, $zero
/* EDC0D4 802400F4 8E050000 */  lw        $a1, ($s0)
/* EDC0D8 802400F8 26100004 */  addiu     $s0, $s0, 4
/* EDC0DC 802400FC 0220202D */  daddu     $a0, $s1, $zero
/* EDC0E0 80240100 0C0B55FF */  jal       dead_get_float_variable
/* EDC0E4 80240104 0040902D */   daddu    $s2, $v0, $zero
/* EDC0E8 80240108 8E050000 */  lw        $a1, ($s0)
/* EDC0EC 8024010C 26100004 */  addiu     $s0, $s0, 4
/* EDC0F0 80240110 0220202D */  daddu     $a0, $s1, $zero
/* EDC0F4 80240114 0C0B55FF */  jal       dead_get_float_variable
/* EDC0F8 80240118 46000706 */   mov.s    $f28, $f0
/* EDC0FC 8024011C 8E050000 */  lw        $a1, ($s0)
/* EDC100 80240120 26100004 */  addiu     $s0, $s0, 4
/* EDC104 80240124 0220202D */  daddu     $a0, $s1, $zero
/* EDC108 80240128 0C0B55FF */  jal       dead_get_float_variable
/* EDC10C 8024012C 46000686 */   mov.s    $f26, $f0
/* EDC110 80240130 0220202D */  daddu     $a0, $s1, $zero
/* EDC114 80240134 8E050000 */  lw        $a1, ($s0)
/* EDC118 80240138 0C0B55FF */  jal       dead_get_float_variable
/* EDC11C 8024013C 46000586 */   mov.s    $f22, $f0
/* EDC120 80240140 0240202D */  daddu     $a0, $s2, $zero
/* EDC124 80240144 0C0493D1 */  jal       func_80124F44
/* EDC128 80240148 46000606 */   mov.s    $f24, $f0
/* EDC12C 8024014C 0040882D */  daddu     $s1, $v0, $zero
/* EDC130 80240150 96220000 */  lhu       $v0, ($s1)
/* EDC134 80240154 30420400 */  andi      $v0, $v0, 0x400
/* EDC138 80240158 1440001E */  bnez      $v0, .L802401D4
/* EDC13C 8024015C 26300058 */   addiu    $s0, $s1, 0x58
/* EDC140 80240160 4480A000 */  mtc1      $zero, $f20
/* EDC144 80240164 4406B000 */  mfc1      $a2, $f22
/* EDC148 80240168 4405A000 */  mfc1      $a1, $f20
/* EDC14C 8024016C 4407A000 */  mfc1      $a3, $f20
/* EDC150 80240170 0C01B2B0 */  jal       func_8006CAC0
/* EDC154 80240174 0200202D */   daddu    $a0, $s0, $zero
/* EDC158 80240178 4405E000 */  mfc1      $a1, $f28
/* EDC15C 8024017C 4406D000 */  mfc1      $a2, $f26
/* EDC160 80240180 4407C000 */  mfc1      $a3, $f24
/* EDC164 80240184 0C090010 */  jal       func_80240040_EDC020
/* EDC168 80240188 27A40010 */   addiu    $a0, $sp, 0x10
/* EDC16C 8024018C 27A40010 */  addiu     $a0, $sp, 0x10
/* EDC170 80240190 0200282D */  daddu     $a1, $s0, $zero
/* EDC174 80240194 0C01B1F0 */  jal       osSiRawReadIo
/* EDC178 80240198 0200302D */   daddu    $a2, $s0, $zero
/* EDC17C 8024019C 27A40010 */  addiu     $a0, $sp, 0x10
/* EDC180 802401A0 4600B587 */  neg.s     $f22, $f22
/* EDC184 802401A4 4405A000 */  mfc1      $a1, $f20
/* EDC188 802401A8 4406B000 */  mfc1      $a2, $f22
/* EDC18C 802401AC 0C01B2B0 */  jal       func_8006CAC0
/* EDC190 802401B0 00A0382D */   daddu    $a3, $a1, $zero
/* EDC194 802401B4 27A40010 */  addiu     $a0, $sp, 0x10
/* EDC198 802401B8 0200282D */  daddu     $a1, $s0, $zero
/* EDC19C 802401BC 0C01B1F0 */  jal       osSiRawReadIo
/* EDC1A0 802401C0 00A0302D */   daddu    $a2, $a1, $zero
/* EDC1A4 802401C4 96220000 */  lhu       $v0, ($s1)
/* EDC1A8 802401C8 34421400 */  ori       $v0, $v0, 0x1400
/* EDC1AC 802401CC 08090093 */  j         .L8024024C
/* EDC1B0 802401D0 A6220000 */   sh       $v0, ($s1)
.L802401D4:
/* EDC1B4 802401D4 4480A000 */  mtc1      $zero, $f20
/* EDC1B8 802401D8 4406B000 */  mfc1      $a2, $f22
/* EDC1BC 802401DC 4405A000 */  mfc1      $a1, $f20
/* EDC1C0 802401E0 4407A000 */  mfc1      $a3, $f20
/* EDC1C4 802401E4 0C01B2B0 */  jal       func_8006CAC0
/* EDC1C8 802401E8 27A40010 */   addiu    $a0, $sp, 0x10
/* EDC1CC 802401EC 27A40010 */  addiu     $a0, $sp, 0x10
/* EDC1D0 802401F0 26300058 */  addiu     $s0, $s1, 0x58
/* EDC1D4 802401F4 0200282D */  daddu     $a1, $s0, $zero
/* EDC1D8 802401F8 0C01B1F0 */  jal       osSiRawReadIo
/* EDC1DC 802401FC 0200302D */   daddu    $a2, $s0, $zero
/* EDC1E0 80240200 4405E000 */  mfc1      $a1, $f28
/* EDC1E4 80240204 4406D000 */  mfc1      $a2, $f26
/* EDC1E8 80240208 4407C000 */  mfc1      $a3, $f24
/* EDC1EC 8024020C 0C090010 */  jal       func_80240040_EDC020
/* EDC1F0 80240210 27A40010 */   addiu    $a0, $sp, 0x10
/* EDC1F4 80240214 27A40010 */  addiu     $a0, $sp, 0x10
/* EDC1F8 80240218 0200282D */  daddu     $a1, $s0, $zero
/* EDC1FC 8024021C 0C01B1F0 */  jal       osSiRawReadIo
/* EDC200 80240220 0200302D */   daddu    $a2, $s0, $zero
/* EDC204 80240224 27A40010 */  addiu     $a0, $sp, 0x10
/* EDC208 80240228 4600B587 */  neg.s     $f22, $f22
/* EDC20C 8024022C 4405A000 */  mfc1      $a1, $f20
/* EDC210 80240230 4406B000 */  mfc1      $a2, $f22
/* EDC214 80240234 0C01B2B0 */  jal       func_8006CAC0
/* EDC218 80240238 00A0382D */   daddu    $a3, $a1, $zero
/* EDC21C 8024023C 27A40010 */  addiu     $a0, $sp, 0x10
/* EDC220 80240240 0200282D */  daddu     $a1, $s0, $zero
/* EDC224 80240244 0C01B1F0 */  jal       osSiRawReadIo
/* EDC228 80240248 00A0302D */   daddu    $a2, $a1, $zero
.L8024024C:
/* EDC22C 8024024C 8FBF005C */  lw        $ra, 0x5c($sp)
/* EDC230 80240250 8FB20058 */  lw        $s2, 0x58($sp)
/* EDC234 80240254 8FB10054 */  lw        $s1, 0x54($sp)
/* EDC238 80240258 8FB00050 */  lw        $s0, 0x50($sp)
/* EDC23C 8024025C D7BC0080 */  ldc1      $f28, 0x80($sp)
/* EDC240 80240260 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* EDC244 80240264 D7B80070 */  ldc1      $f24, 0x70($sp)
/* EDC248 80240268 D7B60068 */  ldc1      $f22, 0x68($sp)
/* EDC24C 8024026C D7B40060 */  ldc1      $f20, 0x60($sp)
/* EDC250 80240270 24020002 */  addiu     $v0, $zero, 2
/* EDC254 80240274 03E00008 */  jr        $ra
/* EDC258 80240278 27BD0088 */   addiu    $sp, $sp, 0x88
