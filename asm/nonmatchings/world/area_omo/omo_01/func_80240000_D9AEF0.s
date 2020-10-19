.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D9AEF0
/* D9AEF0 80240000 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* D9AEF4 80240004 AFB600B0 */  sw        $s6, 0xb0($sp)
/* D9AEF8 80240008 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* D9AEFC 8024000C AFB500AC */  sw        $s5, 0xac($sp)
/* D9AF00 80240010 AFB400A8 */  sw        $s4, 0xa8($sp)
/* D9AF04 80240014 AFB300A4 */  sw        $s3, 0xa4($sp)
/* D9AF08 80240018 AFB200A0 */  sw        $s2, 0xa0($sp)
/* D9AF0C 8024001C AFB1009C */  sw        $s1, 0x9c($sp)
/* D9AF10 80240020 AFB00098 */  sw        $s0, 0x98($sp)
/* D9AF14 80240024 F7B800C8 */  sdc1      $f24, 0xc8($sp)
/* D9AF18 80240028 F7B600C0 */  sdc1      $f22, 0xc0($sp)
/* D9AF1C 8024002C F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* D9AF20 80240030 10A0001E */  beqz      $a1, .L802400AC
/* D9AF24 80240034 0080B02D */   daddu    $s6, $a0, $zero
/* D9AF28 80240038 0C00AB39 */  jal       heap_malloc
/* D9AF2C 8024003C 24040030 */   addiu    $a0, $zero, 0x30
/* D9AF30 80240040 0040982D */  daddu     $s3, $v0, $zero
/* D9AF34 80240044 0000A02D */  daddu     $s4, $zero, $zero
/* D9AF38 80240048 26700008 */  addiu     $s0, $s3, 8
/* D9AF3C 8024004C 3C014060 */  lui       $at, 0x4060
/* D9AF40 80240050 4481A000 */  mtc1      $at, $f20
/* D9AF44 80240054 3C128024 */  lui       $s2, 0x8024
/* D9AF48 80240058 265212A0 */  addiu     $s2, $s2, 0x12a0
/* D9AF4C 8024005C AED30070 */  sw        $s3, 0x70($s6)
.L80240060:
/* D9AF50 80240060 8E440000 */  lw        $a0, ($s2)
/* D9AF54 80240064 26520004 */  addiu     $s2, $s2, 4
/* D9AF58 80240068 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D9AF5C 8024006C AE04000C */   sw       $a0, 0xc($s0)
/* D9AF60 80240070 0C046B4C */  jal       get_model_from_list_index
/* D9AF64 80240074 0040202D */   daddu    $a0, $v0, $zero
/* D9AF68 80240078 0040882D */  daddu     $s1, $v0, $zero
/* D9AF6C 8024007C 26940001 */  addiu     $s4, $s4, 1
/* D9AF70 80240080 C6200098 */  lwc1      $f0, 0x98($s1)
/* D9AF74 80240084 2E820002 */  sltiu     $v0, $s4, 2
/* D9AF78 80240088 E6600000 */  swc1      $f0, ($s3)
/* D9AF7C 8024008C C62000A0 */  lwc1      $f0, 0xa0($s1)
/* D9AF80 80240090 26730018 */  addiu     $s3, $s3, 0x18
/* D9AF84 80240094 E6140004 */  swc1      $f20, 4($s0)
/* D9AF88 80240098 AE000008 */  sw        $zero, 8($s0)
/* D9AF8C 8024009C AE000000 */  sw        $zero, ($s0)
/* D9AF90 802400A0 E600FFFC */  swc1      $f0, -4($s0)
/* D9AF94 802400A4 1440FFEE */  bnez      $v0, .L80240060
/* D9AF98 802400A8 26100018 */   addiu    $s0, $s0, 0x18
.L802400AC:
/* D9AF9C 802400AC 0000A02D */  daddu     $s4, $zero, $zero
/* D9AFA0 802400B0 27B50058 */  addiu     $s5, $sp, 0x58
/* D9AFA4 802400B4 8ED30070 */  lw        $s3, 0x70($s6)
/* D9AFA8 802400B8 4480B000 */  mtc1      $zero, $f22
/* D9AFAC 802400BC 26720004 */  addiu     $s2, $s3, 4
.L802400C0:
/* D9AFB0 802400C0 C64C000C */  lwc1      $f12, 0xc($s2)
/* D9AFB4 802400C4 C6400008 */  lwc1      $f0, 8($s2)
/* D9AFB8 802400C8 46006300 */  add.s     $f12, $f12, $f0
/* D9AFBC 802400CC 0C00A6C9 */  jal       clamp_angle
/* D9AFC0 802400D0 E64C000C */   swc1     $f12, 0xc($s2)
/* D9AFC4 802400D4 46000306 */  mov.s     $f12, $f0
/* D9AFC8 802400D8 0C00A8BB */  jal       sin_deg
/* D9AFCC 802400DC E64C000C */   swc1     $f12, 0xc($s2)
/* D9AFD0 802400E0 3C0141A0 */  lui       $at, 0x41a0
/* D9AFD4 802400E4 44811000 */  mtc1      $at, $f2
/* D9AFD8 802400E8 00000000 */  nop       
/* D9AFDC 802400EC 46020502 */  mul.s     $f20, $f0, $f2
/* D9AFE0 802400F0 00000000 */  nop       
/* D9AFE4 802400F4 4614A082 */  mul.s     $f2, $f20, $f20
/* D9AFE8 802400F8 00000000 */  nop       
/* D9AFEC 802400FC 3C0142B4 */  lui       $at, 0x42b4
/* D9AFF0 80240100 44810000 */  mtc1      $at, $f0
/* D9AFF4 80240104 1680001B */  bnez      $s4, .L80240174
/* D9AFF8 80240108 46001603 */   div.s    $f24, $f2, $f0
/* D9AFFC 8024010C C6400004 */  lwc1      $f0, 4($s2)
/* D9B000 80240110 4600B03E */  c.le.s    $f22, $f0
/* D9B004 80240114 00000000 */  nop       
/* D9B008 80240118 45000005 */  bc1f      .L80240130
/* D9B00C 8024011C 00000000 */   nop      
/* D9B010 80240120 4616A03C */  c.lt.s    $f20, $f22
/* D9B014 80240124 00000000 */  nop       
/* D9B018 80240128 4501000A */  bc1t      .L80240154
/* D9B01C 8024012C 240401D6 */   addiu    $a0, $zero, 0x1d6
.L80240130:
/* D9B020 80240130 4616003C */  c.lt.s    $f0, $f22
/* D9B024 80240134 00000000 */  nop       
/* D9B028 80240138 4502000E */  bc1fl     .L80240174
/* D9B02C 8024013C E6540004 */   swc1     $f20, 4($s2)
/* D9B030 80240140 4614B03E */  c.le.s    $f22, $f20
/* D9B034 80240144 00000000 */  nop       
/* D9B038 80240148 4502000A */  bc1fl     .L80240174
/* D9B03C 8024014C E6540004 */   swc1     $f20, 4($s2)
/* D9B040 80240150 240401D6 */  addiu     $a0, $zero, 0x1d6
.L80240154:
/* D9B044 80240154 0000282D */  daddu     $a1, $zero, $zero
/* D9B048 80240158 3C06C339 */  lui       $a2, 0xc339
/* D9B04C 8024015C 3C014320 */  lui       $at, 0x4320
/* D9B050 80240160 44810000 */  mtc1      $at, $f0
/* D9B054 80240164 0000382D */  daddu     $a3, $zero, $zero
/* D9B058 80240168 0C052757 */  jal       play_sound_at_position
/* D9B05C 8024016C E7A00010 */   swc1     $f0, 0x10($sp)
/* D9B060 80240170 E6540004 */  swc1      $f20, 4($s2)
.L80240174:
/* D9B064 80240174 8E440010 */  lw        $a0, 0x10($s2)
/* D9B068 80240178 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D9B06C 8024017C 26940001 */   addiu    $s4, $s4, 1
/* D9B070 80240180 0C046B4C */  jal       get_model_from_list_index
/* D9B074 80240184 0040202D */   daddu    $a0, $v0, $zero
/* D9B078 80240188 0040882D */  daddu     $s1, $v0, $zero
/* D9B07C 8024018C 96220000 */  lhu       $v0, ($s1)
/* D9B080 80240190 4406B000 */  mfc1      $a2, $f22
/* D9B084 80240194 34421400 */  ori       $v0, $v0, 0x1400
/* D9B088 80240198 A6220000 */  sh        $v0, ($s1)
/* D9B08C 8024019C C6600000 */  lwc1      $f0, ($s3)
/* D9B090 802401A0 C6420000 */  lwc1      $f2, ($s2)
/* D9B094 802401A4 46000007 */  neg.s     $f0, $f0
/* D9B098 802401A8 46001087 */  neg.s     $f2, $f2
/* D9B09C 802401AC 44050000 */  mfc1      $a1, $f0
/* D9B0A0 802401B0 44071000 */  mfc1      $a3, $f2
/* D9B0A4 802401B4 0C019E40 */  jal       guTranslateF
/* D9B0A8 802401B8 27A40018 */   addiu    $a0, $sp, 0x18
/* D9B0AC 802401BC 4405A000 */  mfc1      $a1, $f20
/* D9B0B0 802401C0 4406B000 */  mfc1      $a2, $f22
/* D9B0B4 802401C4 4407B000 */  mfc1      $a3, $f22
/* D9B0B8 802401C8 3C013F80 */  lui       $at, 0x3f80
/* D9B0BC 802401CC 44810000 */  mtc1      $at, $f0
/* D9B0C0 802401D0 02A0202D */  daddu     $a0, $s5, $zero
/* D9B0C4 802401D4 0C019EC8 */  jal       guRotateF
/* D9B0C8 802401D8 E7A00010 */   swc1     $f0, 0x10($sp)
/* D9B0CC 802401DC 27A40018 */  addiu     $a0, $sp, 0x18
/* D9B0D0 802401E0 02A0282D */  daddu     $a1, $s5, $zero
/* D9B0D4 802401E4 26300058 */  addiu     $s0, $s1, 0x58
/* D9B0D8 802401E8 0C019D80 */  jal       guMtxCatF
/* D9B0DC 802401EC 0200302D */   daddu    $a2, $s0, $zero
/* D9B0E0 802401F0 27A40018 */  addiu     $a0, $sp, 0x18
/* D9B0E4 802401F4 8E470000 */  lw        $a3, ($s2)
/* D9B0E8 802401F8 26520018 */  addiu     $s2, $s2, 0x18
/* D9B0EC 802401FC 8E650000 */  lw        $a1, ($s3)
/* D9B0F0 80240200 4406C000 */  mfc1      $a2, $f24
/* D9B0F4 80240204 0C019E40 */  jal       guTranslateF
/* D9B0F8 80240208 26730018 */   addiu    $s3, $s3, 0x18
/* D9B0FC 8024020C 0200202D */  daddu     $a0, $s0, $zero
/* D9B100 80240210 27A50018 */  addiu     $a1, $sp, 0x18
/* D9B104 80240214 0C019D80 */  jal       guMtxCatF
/* D9B108 80240218 0080302D */   daddu    $a2, $a0, $zero
/* D9B10C 8024021C 2E820002 */  sltiu     $v0, $s4, 2
/* D9B110 80240220 1440FFA7 */  bnez      $v0, .L802400C0
/* D9B114 80240224 0000102D */   daddu    $v0, $zero, $zero
/* D9B118 80240228 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* D9B11C 8024022C 8FB600B0 */  lw        $s6, 0xb0($sp)
/* D9B120 80240230 8FB500AC */  lw        $s5, 0xac($sp)
/* D9B124 80240234 8FB400A8 */  lw        $s4, 0xa8($sp)
/* D9B128 80240238 8FB300A4 */  lw        $s3, 0xa4($sp)
/* D9B12C 8024023C 8FB200A0 */  lw        $s2, 0xa0($sp)
/* D9B130 80240240 8FB1009C */  lw        $s1, 0x9c($sp)
/* D9B134 80240244 8FB00098 */  lw        $s0, 0x98($sp)
/* D9B138 80240248 D7B800C8 */  ldc1      $f24, 0xc8($sp)
/* D9B13C 8024024C D7B600C0 */  ldc1      $f22, 0xc0($sp)
/* D9B140 80240250 D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* D9B144 80240254 03E00008 */  jr        $ra
/* D9B148 80240258 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* D9B14C 8024025C 00000000 */  nop       
