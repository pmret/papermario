.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240540_EFF040
/* EFF040 80240540 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EFF044 80240544 AFB00010 */  sw        $s0, 0x10($sp)
/* EFF048 80240548 0080802D */  daddu     $s0, $a0, $zero
/* EFF04C 8024054C AFBF0018 */  sw        $ra, 0x18($sp)
/* EFF050 80240550 AFB10014 */  sw        $s1, 0x14($sp)
/* EFF054 80240554 F7B80030 */  sdc1      $f24, 0x30($sp)
/* EFF058 80240558 F7B60028 */  sdc1      $f22, 0x28($sp)
/* EFF05C 8024055C F7B40020 */  sdc1      $f20, 0x20($sp)
/* EFF060 80240560 8E05008C */  lw        $a1, 0x8c($s0)
/* EFF064 80240564 4480B000 */  mtc1      $zero, $f22
/* EFF068 80240568 0C0B53A3 */  jal       dead_get_variable
/* EFF06C 8024056C 0000202D */   daddu    $a0, $zero, $zero
/* EFF070 80240570 4600B306 */  mov.s     $f12, $f22
/* EFF074 80240574 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* EFF078 80240578 468010A0 */  cvt.s.w   $f2, $f2
/* EFF07C 8024057C 44061000 */  mfc1      $a2, $f2
/* EFF080 80240580 C60200B0 */  lwc1      $f2, 0xb0($s0)
/* EFF084 80240584 468010A0 */  cvt.s.w   $f2, $f2
/* EFF088 80240588 44071000 */  mfc1      $a3, $f2
/* EFF08C 8024058C 4482A000 */  mtc1      $v0, $f20
/* EFF090 80240590 00000000 */  nop
/* EFF094 80240594 4680A520 */  cvt.s.w   $f20, $f20
/* EFF098 80240598 0C00AC71 */  jal       func_8002B1C4
/* EFF09C 8024059C 4600B386 */   mov.s    $f14, $f22
/* EFF0A0 802405A0 4600B306 */  mov.s     $f12, $f22
/* EFF0A4 802405A4 4600B386 */  mov.s     $f14, $f22
/* EFF0A8 802405A8 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* EFF0AC 802405AC 468010A0 */  cvt.s.w   $f2, $f2
/* EFF0B0 802405B0 44061000 */  mfc1      $a2, $f2
/* EFF0B4 802405B4 C60200B0 */  lwc1      $f2, 0xb0($s0)
/* EFF0B8 802405B8 468010A0 */  cvt.s.w   $f2, $f2
/* EFF0BC 802405BC 44071000 */  mfc1      $a3, $f2
/* EFF0C0 802405C0 0C00ABDC */  jal       fio_validate_header_checksums
/* EFF0C4 802405C4 46000606 */   mov.s    $f24, $f0
/* EFF0C8 802405C8 0C00AB85 */  jal       dead_clamp_angle
/* EFF0CC 802405CC 46140301 */   sub.s    $f12, $f0, $f20
/* EFF0D0 802405D0 46000506 */  mov.s     $f20, $f0
/* EFF0D4 802405D4 0C00AD77 */  jal       func_8002B5DC
/* EFF0D8 802405D8 4600A306 */   mov.s    $f12, $f20
/* EFF0DC 802405DC 4600C002 */  mul.s     $f0, $f24, $f0
/* EFF0E0 802405E0 00000000 */  nop
/* EFF0E4 802405E4 46160000 */  add.s     $f0, $f0, $f22
/* EFF0E8 802405E8 3C118011 */  lui       $s1, %hi(D_80117578)
/* EFF0EC 802405EC 26317578 */  addiu     $s1, $s1, %lo(D_80117578)
/* EFF0F0 802405F0 E6200028 */  swc1      $f0, 0x28($s1)
/* EFF0F4 802405F4 8E0500AC */  lw        $a1, 0xac($s0)
/* EFF0F8 802405F8 0C0B53A3 */  jal       dead_get_variable
/* EFF0FC 802405FC 0000202D */   daddu    $a0, $zero, $zero
/* EFF100 80240600 0000202D */  daddu     $a0, $zero, $zero
/* EFF104 80240604 8E050090 */  lw        $a1, 0x90($s0)
/* EFF108 80240608 0C0B53A3 */  jal       dead_get_variable
/* EFF10C 8024060C 0040802D */   daddu    $s0, $v0, $zero
/* EFF110 80240610 4600A306 */  mov.s     $f12, $f20
/* EFF114 80240614 02028021 */  addu      $s0, $s0, $v0
/* EFF118 80240618 44900000 */  mtc1      $s0, $f0
/* EFF11C 8024061C 00000000 */  nop
/* EFF120 80240620 46800020 */  cvt.s.w   $f0, $f0
/* EFF124 80240624 0C00AD90 */  jal       func_8002B640
/* EFF128 80240628 E620002C */   swc1     $f0, 0x2c($s1)
/* EFF12C 8024062C 4600C602 */  mul.s     $f24, $f24, $f0
/* EFF130 80240630 00000000 */  nop
/* EFF134 80240634 4618B581 */  sub.s     $f22, $f22, $f24
/* EFF138 80240638 E6360030 */  swc1      $f22, 0x30($s1)
/* EFF13C 8024063C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EFF140 80240640 8FB10014 */  lw        $s1, 0x14($sp)
/* EFF144 80240644 8FB00010 */  lw        $s0, 0x10($sp)
/* EFF148 80240648 D7B80030 */  ldc1      $f24, 0x30($sp)
/* EFF14C 8024064C D7B60028 */  ldc1      $f22, 0x28($sp)
/* EFF150 80240650 D7B40020 */  ldc1      $f20, 0x20($sp)
/* EFF154 80240654 24020002 */  addiu     $v0, $zero, 2
/* EFF158 80240658 03E00008 */  jr        $ra
/* EFF15C 8024065C 27BD0038 */   addiu    $sp, $sp, 0x38
