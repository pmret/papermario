.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240100_B1CB50
/* B1CB50 80240100 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* B1CB54 80240104 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* B1CB58 80240108 3C07BF80 */  lui       $a3, 0xbf80
/* B1CB5C 8024010C 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* B1CB60 80240110 F7B40128 */  sdc1      $f20, 0x128($sp)
/* B1CB64 80240114 4480A000 */  mtc1      $zero, $f20
/* B1CB68 80240118 AFB1011C */  sw        $s1, 0x11c($sp)
/* B1CB6C 8024011C 0080882D */  daddu     $s1, $a0, $zero
/* B1CB70 80240120 AFB00118 */  sw        $s0, 0x118($sp)
/* B1CB74 80240124 27B00098 */  addiu     $s0, $sp, 0x98
/* B1CB78 80240128 AFBF0120 */  sw        $ra, 0x120($sp)
/* B1CB7C 8024012C F7B80138 */  sdc1      $f24, 0x138($sp)
/* B1CB80 80240130 F7B60130 */  sdc1      $f22, 0x130($sp)
/* B1CB84 80240134 00031080 */  sll       $v0, $v1, 2
/* B1CB88 80240138 00431021 */  addu      $v0, $v0, $v1
/* B1CB8C 8024013C 00021080 */  sll       $v0, $v0, 2
/* B1CB90 80240140 00431023 */  subu      $v0, $v0, $v1
/* B1CB94 80240144 000218C0 */  sll       $v1, $v0, 3
/* B1CB98 80240148 00431021 */  addu      $v0, $v0, $v1
/* B1CB9C 8024014C 000210C0 */  sll       $v0, $v0, 3
/* B1CBA0 80240150 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* B1CBA4 80240154 00220821 */  addu      $at, $at, $v0
/* B1CBA8 80240158 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* B1CBAC 8024015C 4406A000 */  mfc1      $a2, $f20
/* B1CBB0 80240160 4600B587 */  neg.s     $f22, $f22
/* B1CBB4 80240164 4405B000 */  mfc1      $a1, $f22
/* B1CBB8 80240168 0200202D */  daddu     $a0, $s0, $zero
/* B1CBBC 8024016C 0C019EC8 */  jal       guRotateF
/* B1CBC0 80240170 E7B40010 */   swc1     $f20, 0x10($sp)
/* B1CBC4 80240174 C62C008C */  lwc1      $f12, 0x8c($s1)
/* B1CBC8 80240178 0C00A6C9 */  jal       clamp_angle
/* B1CBCC 8024017C 00000000 */   nop
/* B1CBD0 80240180 44050000 */  mfc1      $a1, $f0
/* B1CBD4 80240184 4406A000 */  mfc1      $a2, $f20
/* B1CBD8 80240188 4407A000 */  mfc1      $a3, $f20
/* B1CBDC 8024018C 3C013F80 */  lui       $at, 0x3f80
/* B1CBE0 80240190 4481C000 */  mtc1      $at, $f24
/* B1CBE4 80240194 27A40018 */  addiu     $a0, $sp, 0x18
/* B1CBE8 80240198 0C019EC8 */  jal       guRotateF
/* B1CBEC 8024019C E7B80010 */   swc1     $f24, 0x10($sp)
/* B1CBF0 802401A0 0200202D */  daddu     $a0, $s0, $zero
/* B1CBF4 802401A4 27A50018 */  addiu     $a1, $sp, 0x18
/* B1CBF8 802401A8 0C019D80 */  jal       guMtxCatF
/* B1CBFC 802401AC 00A0302D */   daddu    $a2, $a1, $zero
/* B1CC00 802401B0 4405B000 */  mfc1      $a1, $f22
/* B1CC04 802401B4 4406A000 */  mfc1      $a2, $f20
/* B1CC08 802401B8 4407C000 */  mfc1      $a3, $f24
/* B1CC0C 802401BC 0200202D */  daddu     $a0, $s0, $zero
/* B1CC10 802401C0 0C019EC8 */  jal       guRotateF
/* B1CC14 802401C4 E7B40010 */   swc1     $f20, 0x10($sp)
/* B1CC18 802401C8 27A40018 */  addiu     $a0, $sp, 0x18
/* B1CC1C 802401CC 0200282D */  daddu     $a1, $s0, $zero
/* B1CC20 802401D0 0C019D80 */  jal       guMtxCatF
/* B1CC24 802401D4 0080302D */   daddu    $a2, $a0, $zero
/* B1CC28 802401D8 E7B40010 */  swc1      $f20, 0x10($sp)
/* B1CC2C 802401DC 8E2500A8 */  lw        $a1, 0xa8($s1)
/* B1CC30 802401E0 4406A000 */  mfc1      $a2, $f20
/* B1CC34 802401E4 4407C000 */  mfc1      $a3, $f24
/* B1CC38 802401E8 0C019EC8 */  jal       guRotateF
/* B1CC3C 802401EC 0200202D */   daddu    $a0, $s0, $zero
/* B1CC40 802401F0 27A40018 */  addiu     $a0, $sp, 0x18
/* B1CC44 802401F4 0200282D */  daddu     $a1, $s0, $zero
/* B1CC48 802401F8 0C019D80 */  jal       guMtxCatF
/* B1CC4C 802401FC 0080302D */   daddu    $a2, $a0, $zero
/* B1CC50 80240200 3C013F36 */  lui       $at, 0x3f36
/* B1CC54 80240204 3421DB6E */  ori       $at, $at, 0xdb6e
/* B1CC58 80240208 44810000 */  mtc1      $at, $f0
/* B1CC5C 8024020C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* B1CC60 80240210 44050000 */  mfc1      $a1, $f0
/* B1CC64 80240214 0200202D */  daddu     $a0, $s0, $zero
/* B1CC68 80240218 00A0302D */  daddu     $a2, $a1, $zero
/* B1CC6C 8024021C 0C019DF0 */  jal       guScaleF
/* B1CC70 80240220 00A0382D */   daddu    $a3, $a1, $zero
/* B1CC74 80240224 27A40018 */  addiu     $a0, $sp, 0x18
/* B1CC78 80240228 0200282D */  daddu     $a1, $s0, $zero
/* B1CC7C 8024022C 0C019D80 */  jal       guMtxCatF
/* B1CC80 80240230 0080302D */   daddu    $a2, $a0, $zero
/* B1CC84 80240234 27B00058 */  addiu     $s0, $sp, 0x58
/* B1CC88 80240238 8E250028 */  lw        $a1, 0x28($s1)
/* B1CC8C 8024023C C6200030 */  lwc1      $f0, 0x30($s1)
/* B1CC90 80240240 8E26002C */  lw        $a2, 0x2c($s1)
/* B1CC94 80240244 46000007 */  neg.s     $f0, $f0
/* B1CC98 80240248 44070000 */  mfc1      $a3, $f0
/* B1CC9C 8024024C 0C019E40 */  jal       guTranslateF
/* B1CCA0 80240250 0200202D */   daddu    $a0, $s0, $zero
/* B1CCA4 80240254 27A40018 */  addiu     $a0, $sp, 0x18
/* B1CCA8 80240258 0200282D */  daddu     $a1, $s0, $zero
/* B1CCAC 8024025C 0C019D80 */  jal       guMtxCatF
/* B1CCB0 80240260 0080302D */   daddu    $a2, $a0, $zero
/* B1CCB4 80240264 24040001 */  addiu     $a0, $zero, 1
/* B1CCB8 80240268 3C050100 */  lui       $a1, 0x100
/* B1CCBC 8024026C 8E2200A4 */  lw        $v0, 0xa4($s1)
/* B1CCC0 80240270 4406C000 */  mfc1      $a2, $f24
/* B1CCC4 80240274 0C0B76A3 */  jal       func_802DDA8C
/* B1CCC8 80240278 00452826 */   xor      $a1, $v0, $a1
/* B1CCCC 8024027C 24040001 */  addiu     $a0, $zero, 1
/* B1CCD0 80240280 0000282D */  daddu     $a1, $zero, $zero
/* B1CCD4 80240284 00A0302D */  daddu     $a2, $a1, $zero
/* B1CCD8 80240288 00A0382D */  daddu     $a3, $a1, $zero
/* B1CCDC 8024028C 27A20018 */  addiu     $v0, $sp, 0x18
/* B1CCE0 80240290 0C0B7710 */  jal       render_sprite
/* B1CCE4 80240294 AFA20010 */   sw       $v0, 0x10($sp)
/* B1CCE8 80240298 8FBF0120 */  lw        $ra, 0x120($sp)
/* B1CCEC 8024029C 8FB1011C */  lw        $s1, 0x11c($sp)
/* B1CCF0 802402A0 8FB00118 */  lw        $s0, 0x118($sp)
/* B1CCF4 802402A4 D7B80138 */  ldc1      $f24, 0x138($sp)
/* B1CCF8 802402A8 D7B60130 */  ldc1      $f22, 0x130($sp)
/* B1CCFC 802402AC D7B40128 */  ldc1      $f20, 0x128($sp)
/* B1CD00 802402B0 03E00008 */  jr        $ra
/* B1CD04 802402B4 27BD0140 */   addiu    $sp, $sp, 0x140
