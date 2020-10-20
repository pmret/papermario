.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419C4_C8F574
/* C8F574 802419C4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C8F578 802419C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* C8F57C 802419CC 0080882D */  daddu     $s1, $a0, $zero
/* C8F580 802419D0 AFBF0034 */  sw        $ra, 0x34($sp)
/* C8F584 802419D4 AFB60030 */  sw        $s6, 0x30($sp)
/* C8F588 802419D8 AFB5002C */  sw        $s5, 0x2c($sp)
/* C8F58C 802419DC AFB40028 */  sw        $s4, 0x28($sp)
/* C8F590 802419E0 AFB30024 */  sw        $s3, 0x24($sp)
/* C8F594 802419E4 AFB20020 */  sw        $s2, 0x20($sp)
/* C8F598 802419E8 AFB00018 */  sw        $s0, 0x18($sp)
/* C8F59C 802419EC F7B60040 */  sdc1      $f22, 0x40($sp)
/* C8F5A0 802419F0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* C8F5A4 802419F4 8E30000C */  lw        $s0, 0xc($s1)
/* C8F5A8 802419F8 8E160000 */  lw        $s6, ($s0)
/* C8F5AC 802419FC 26100004 */  addiu     $s0, $s0, 4
/* C8F5B0 80241A00 0C0B1EAF */  jal       get_variable
/* C8F5B4 80241A04 02C0282D */   daddu    $a1, $s6, $zero
/* C8F5B8 80241A08 44820000 */  mtc1      $v0, $f0
/* C8F5BC 80241A0C 00000000 */  nop       
/* C8F5C0 80241A10 46800020 */  cvt.s.w   $f0, $f0
/* C8F5C4 80241A14 E7A00010 */  swc1      $f0, 0x10($sp)
/* C8F5C8 80241A18 8E140000 */  lw        $s4, ($s0)
/* C8F5CC 80241A1C 26100004 */  addiu     $s0, $s0, 4
/* C8F5D0 80241A20 0220202D */  daddu     $a0, $s1, $zero
/* C8F5D4 80241A24 0C0B1EAF */  jal       get_variable
/* C8F5D8 80241A28 0280282D */   daddu    $a1, $s4, $zero
/* C8F5DC 80241A2C 0220202D */  daddu     $a0, $s1, $zero
/* C8F5E0 80241A30 8E150000 */  lw        $s5, ($s0)
/* C8F5E4 80241A34 4482B000 */  mtc1      $v0, $f22
/* C8F5E8 80241A38 00000000 */  nop       
/* C8F5EC 80241A3C 4680B5A0 */  cvt.s.w   $f22, $f22
/* C8F5F0 80241A40 0C0B1EAF */  jal       get_variable
/* C8F5F4 80241A44 02A0282D */   daddu    $a1, $s5, $zero
/* C8F5F8 80241A48 2404FFFC */  addiu     $a0, $zero, -4
/* C8F5FC 80241A4C 44820000 */  mtc1      $v0, $f0
/* C8F600 80241A50 00000000 */  nop       
/* C8F604 80241A54 46800020 */  cvt.s.w   $f0, $f0
/* C8F608 80241A58 0C00EABB */  jal       get_npc_unsafe
/* C8F60C 80241A5C E7A00014 */   swc1     $f0, 0x14($sp)
/* C8F610 80241A60 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* C8F614 80241A64 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* C8F618 80241A68 3C014334 */  lui       $at, 0x4334
/* C8F61C 80241A6C 44816000 */  mtc1      $at, $f12
/* C8F620 80241A70 00041880 */  sll       $v1, $a0, 2
/* C8F624 80241A74 00641821 */  addu      $v1, $v1, $a0
/* C8F628 80241A78 00031880 */  sll       $v1, $v1, 2
/* C8F62C 80241A7C 00641823 */  subu      $v1, $v1, $a0
/* C8F630 80241A80 000320C0 */  sll       $a0, $v1, 3
/* C8F634 80241A84 00641821 */  addu      $v1, $v1, $a0
/* C8F638 80241A88 000318C0 */  sll       $v1, $v1, 3
/* C8F63C 80241A8C 3C01800B */  lui       $at, 0x800b
/* C8F640 80241A90 00230821 */  addu      $at, $at, $v1
/* C8F644 80241A94 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* C8F648 80241A98 460C0300 */  add.s     $f12, $f0, $f12
/* C8F64C 80241A9C 0C00A6C9 */  jal       clamp_angle
/* C8F650 80241AA0 0040982D */   daddu    $s3, $v0, $zero
/* C8F654 80241AA4 27B00010 */  addiu     $s0, $sp, 0x10
/* C8F658 80241AA8 0200202D */  daddu     $a0, $s0, $zero
/* C8F65C 80241AAC 27B20014 */  addiu     $s2, $sp, 0x14
/* C8F660 80241AB0 0240282D */  daddu     $a1, $s2, $zero
/* C8F664 80241AB4 3C064170 */  lui       $a2, 0x4170
/* C8F668 80241AB8 8E67000C */  lw        $a3, 0xc($s3)
/* C8F66C 80241ABC 0C00A7E7 */  jal       add_vec2D_polar
/* C8F670 80241AC0 46000506 */   mov.s    $f20, $f0
/* C8F674 80241AC4 0200202D */  daddu     $a0, $s0, $zero
/* C8F678 80241AC8 3C064120 */  lui       $a2, 0x4120
/* C8F67C 80241ACC 4407A000 */  mfc1      $a3, $f20
/* C8F680 80241AD0 0C00A7E7 */  jal       add_vec2D_polar
/* C8F684 80241AD4 0240282D */   daddu    $a1, $s2, $zero
/* C8F688 80241AD8 0220202D */  daddu     $a0, $s1, $zero
/* C8F68C 80241ADC C7A00010 */  lwc1      $f0, 0x10($sp)
/* C8F690 80241AE0 4600008D */  trunc.w.s $f2, $f0
/* C8F694 80241AE4 44061000 */  mfc1      $a2, $f2
/* C8F698 80241AE8 0C0B2026 */  jal       set_variable
/* C8F69C 80241AEC 02C0282D */   daddu    $a1, $s6, $zero
/* C8F6A0 80241AF0 0220202D */  daddu     $a0, $s1, $zero
/* C8F6A4 80241AF4 4600B08D */  trunc.w.s $f2, $f22
/* C8F6A8 80241AF8 44061000 */  mfc1      $a2, $f2
/* C8F6AC 80241AFC 0C0B2026 */  jal       set_variable
/* C8F6B0 80241B00 0280282D */   daddu    $a1, $s4, $zero
/* C8F6B4 80241B04 0220202D */  daddu     $a0, $s1, $zero
/* C8F6B8 80241B08 C7A00014 */  lwc1      $f0, 0x14($sp)
/* C8F6BC 80241B0C 4600008D */  trunc.w.s $f2, $f0
/* C8F6C0 80241B10 44061000 */  mfc1      $a2, $f2
/* C8F6C4 80241B14 0C0B2026 */  jal       set_variable
/* C8F6C8 80241B18 02A0282D */   daddu    $a1, $s5, $zero
/* C8F6CC 80241B1C 8FBF0034 */  lw        $ra, 0x34($sp)
/* C8F6D0 80241B20 8FB60030 */  lw        $s6, 0x30($sp)
/* C8F6D4 80241B24 8FB5002C */  lw        $s5, 0x2c($sp)
/* C8F6D8 80241B28 8FB40028 */  lw        $s4, 0x28($sp)
/* C8F6DC 80241B2C 8FB30024 */  lw        $s3, 0x24($sp)
/* C8F6E0 80241B30 8FB20020 */  lw        $s2, 0x20($sp)
/* C8F6E4 80241B34 8FB1001C */  lw        $s1, 0x1c($sp)
/* C8F6E8 80241B38 8FB00018 */  lw        $s0, 0x18($sp)
/* C8F6EC 80241B3C D7B60040 */  ldc1      $f22, 0x40($sp)
/* C8F6F0 80241B40 D7B40038 */  ldc1      $f20, 0x38($sp)
/* C8F6F4 80241B44 24020002 */  addiu     $v0, $zero, 2
/* C8F6F8 80241B48 03E00008 */  jr        $ra
/* C8F6FC 80241B4C 27BD0048 */   addiu    $sp, $sp, 0x48
