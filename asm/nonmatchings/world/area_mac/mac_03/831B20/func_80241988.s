.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241988
/* 833188 80241988 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 83318C 8024198C AFB1001C */  sw        $s1, 0x1c($sp)
/* 833190 80241990 0080882D */  daddu     $s1, $a0, $zero
/* 833194 80241994 AFBF0034 */  sw        $ra, 0x34($sp)
/* 833198 80241998 AFB60030 */  sw        $s6, 0x30($sp)
/* 83319C 8024199C AFB5002C */  sw        $s5, 0x2c($sp)
/* 8331A0 802419A0 AFB40028 */  sw        $s4, 0x28($sp)
/* 8331A4 802419A4 AFB30024 */  sw        $s3, 0x24($sp)
/* 8331A8 802419A8 AFB20020 */  sw        $s2, 0x20($sp)
/* 8331AC 802419AC AFB00018 */  sw        $s0, 0x18($sp)
/* 8331B0 802419B0 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 8331B4 802419B4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 8331B8 802419B8 8E30000C */  lw        $s0, 0xc($s1)
/* 8331BC 802419BC 8E160000 */  lw        $s6, ($s0)
/* 8331C0 802419C0 26100004 */  addiu     $s0, $s0, 4
/* 8331C4 802419C4 0C0B1EAF */  jal       get_variable
/* 8331C8 802419C8 02C0282D */   daddu    $a1, $s6, $zero
/* 8331CC 802419CC 44820000 */  mtc1      $v0, $f0
/* 8331D0 802419D0 00000000 */  nop       
/* 8331D4 802419D4 46800020 */  cvt.s.w   $f0, $f0
/* 8331D8 802419D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8331DC 802419DC 8E140000 */  lw        $s4, ($s0)
/* 8331E0 802419E0 26100004 */  addiu     $s0, $s0, 4
/* 8331E4 802419E4 0220202D */  daddu     $a0, $s1, $zero
/* 8331E8 802419E8 0C0B1EAF */  jal       get_variable
/* 8331EC 802419EC 0280282D */   daddu    $a1, $s4, $zero
/* 8331F0 802419F0 0220202D */  daddu     $a0, $s1, $zero
/* 8331F4 802419F4 8E150000 */  lw        $s5, ($s0)
/* 8331F8 802419F8 4482B000 */  mtc1      $v0, $f22
/* 8331FC 802419FC 00000000 */  nop       
/* 833200 80241A00 4680B5A0 */  cvt.s.w   $f22, $f22
/* 833204 80241A04 0C0B1EAF */  jal       get_variable
/* 833208 80241A08 02A0282D */   daddu    $a1, $s5, $zero
/* 83320C 80241A0C 2404FFFC */  addiu     $a0, $zero, -4
/* 833210 80241A10 44820000 */  mtc1      $v0, $f0
/* 833214 80241A14 00000000 */  nop       
/* 833218 80241A18 46800020 */  cvt.s.w   $f0, $f0
/* 83321C 80241A1C 0C00EABB */  jal       get_npc_unsafe
/* 833220 80241A20 E7A00014 */   swc1     $f0, 0x14($sp)
/* 833224 80241A24 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 833228 80241A28 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 83322C 80241A2C 3C014334 */  lui       $at, 0x4334
/* 833230 80241A30 44816000 */  mtc1      $at, $f12
/* 833234 80241A34 00041880 */  sll       $v1, $a0, 2
/* 833238 80241A38 00641821 */  addu      $v1, $v1, $a0
/* 83323C 80241A3C 00031880 */  sll       $v1, $v1, 2
/* 833240 80241A40 00641823 */  subu      $v1, $v1, $a0
/* 833244 80241A44 000320C0 */  sll       $a0, $v1, 3
/* 833248 80241A48 00641821 */  addu      $v1, $v1, $a0
/* 83324C 80241A4C 000318C0 */  sll       $v1, $v1, 3
/* 833250 80241A50 3C01800B */  lui       $at, 0x800b
/* 833254 80241A54 00230821 */  addu      $at, $at, $v1
/* 833258 80241A58 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 83325C 80241A5C 460C0300 */  add.s     $f12, $f0, $f12
/* 833260 80241A60 0C00A6C9 */  jal       clamp_angle
/* 833264 80241A64 0040982D */   daddu    $s3, $v0, $zero
/* 833268 80241A68 27B00010 */  addiu     $s0, $sp, 0x10
/* 83326C 80241A6C 0200202D */  daddu     $a0, $s0, $zero
/* 833270 80241A70 27B20014 */  addiu     $s2, $sp, 0x14
/* 833274 80241A74 0240282D */  daddu     $a1, $s2, $zero
/* 833278 80241A78 3C064170 */  lui       $a2, 0x4170
/* 83327C 80241A7C 8E67000C */  lw        $a3, 0xc($s3)
/* 833280 80241A80 0C00A7E7 */  jal       add_vec2D_polar
/* 833284 80241A84 46000506 */   mov.s    $f20, $f0
/* 833288 80241A88 0200202D */  daddu     $a0, $s0, $zero
/* 83328C 80241A8C 3C064120 */  lui       $a2, 0x4120
/* 833290 80241A90 4407A000 */  mfc1      $a3, $f20
/* 833294 80241A94 0C00A7E7 */  jal       add_vec2D_polar
/* 833298 80241A98 0240282D */   daddu    $a1, $s2, $zero
/* 83329C 80241A9C 0220202D */  daddu     $a0, $s1, $zero
/* 8332A0 80241AA0 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 8332A4 80241AA4 4600008D */  trunc.w.s $f2, $f0
/* 8332A8 80241AA8 44061000 */  mfc1      $a2, $f2
/* 8332AC 80241AAC 0C0B2026 */  jal       set_variable
/* 8332B0 80241AB0 02C0282D */   daddu    $a1, $s6, $zero
/* 8332B4 80241AB4 0220202D */  daddu     $a0, $s1, $zero
/* 8332B8 80241AB8 4600B08D */  trunc.w.s $f2, $f22
/* 8332BC 80241ABC 44061000 */  mfc1      $a2, $f2
/* 8332C0 80241AC0 0C0B2026 */  jal       set_variable
/* 8332C4 80241AC4 0280282D */   daddu    $a1, $s4, $zero
/* 8332C8 80241AC8 0220202D */  daddu     $a0, $s1, $zero
/* 8332CC 80241ACC C7A00014 */  lwc1      $f0, 0x14($sp)
/* 8332D0 80241AD0 4600008D */  trunc.w.s $f2, $f0
/* 8332D4 80241AD4 44061000 */  mfc1      $a2, $f2
/* 8332D8 80241AD8 0C0B2026 */  jal       set_variable
/* 8332DC 80241ADC 02A0282D */   daddu    $a1, $s5, $zero
/* 8332E0 80241AE0 8FBF0034 */  lw        $ra, 0x34($sp)
/* 8332E4 80241AE4 8FB60030 */  lw        $s6, 0x30($sp)
/* 8332E8 80241AE8 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8332EC 80241AEC 8FB40028 */  lw        $s4, 0x28($sp)
/* 8332F0 80241AF0 8FB30024 */  lw        $s3, 0x24($sp)
/* 8332F4 80241AF4 8FB20020 */  lw        $s2, 0x20($sp)
/* 8332F8 80241AF8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8332FC 80241AFC 8FB00018 */  lw        $s0, 0x18($sp)
/* 833300 80241B00 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 833304 80241B04 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 833308 80241B08 24020002 */  addiu     $v0, $zero, 2
/* 83330C 80241B0C 03E00008 */  jr        $ra
/* 833310 80241B10 27BD0048 */   addiu    $sp, $sp, 0x48
