.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802449D0_88D5A0
.double 0.8

.section .text

glabel func_802419DC_88A5AC
/* 88A5AC 802419DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 88A5B0 802419E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 88A5B4 802419E4 0080982D */  daddu     $s3, $a0, $zero
/* 88A5B8 802419E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 88A5BC 802419EC AFB20018 */  sw        $s2, 0x18($sp)
/* 88A5C0 802419F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 88A5C4 802419F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 88A5C8 802419F8 8E710148 */  lw        $s1, 0x148($s3)
/* 88A5CC 802419FC 86240008 */  lh        $a0, 8($s1)
/* 88A5D0 80241A00 0C00EABB */  jal       get_npc_unsafe
/* 88A5D4 80241A04 00A0902D */   daddu    $s2, $a1, $zero
/* 88A5D8 80241A08 0040802D */  daddu     $s0, $v0, $zero
/* 88A5DC 80241A0C 8602008E */  lh        $v0, 0x8e($s0)
/* 88A5E0 80241A10 9603008E */  lhu       $v1, 0x8e($s0)
/* 88A5E4 80241A14 18400005 */  blez      $v0, .L80241A2C
/* 88A5E8 80241A18 2462FFFF */   addiu    $v0, $v1, -1
/* 88A5EC 80241A1C A602008E */  sh        $v0, 0x8e($s0)
/* 88A5F0 80241A20 00021400 */  sll       $v0, $v0, 0x10
/* 88A5F4 80241A24 1C400033 */  bgtz      $v0, .L80241AF4
/* 88A5F8 80241A28 00000000 */   nop
.L80241A2C:
/* 88A5FC 80241A2C 8602008C */  lh        $v0, 0x8c($s0)
/* 88A600 80241A30 14400030 */  bnez      $v0, .L80241AF4
/* 88A604 80241A34 00000000 */   nop
/* 88A608 80241A38 8E2200CC */  lw        $v0, 0xcc($s1)
/* 88A60C 80241A3C 8C420024 */  lw        $v0, 0x24($v0)
/* 88A610 80241A40 AE020028 */  sw        $v0, 0x28($s0)
/* 88A614 80241A44 C6400018 */  lwc1      $f0, 0x18($s2)
/* 88A618 80241A48 E6000018 */  swc1      $f0, 0x18($s0)
/* 88A61C 80241A4C 8E230088 */  lw        $v1, 0x88($s1)
/* 88A620 80241A50 24020005 */  addiu     $v0, $zero, 5
/* 88A624 80241A54 10620005 */  beq       $v1, $v0, .L80241A6C
/* 88A628 80241A58 00000000 */   nop
/* 88A62C 80241A5C 10600003 */  beqz      $v1, .L80241A6C
/* 88A630 80241A60 24020001 */   addiu    $v0, $zero, 1
/* 88A634 80241A64 14620006 */  bne       $v1, $v0, .L80241A80
/* 88A638 80241A68 00000000 */   nop
.L80241A6C:
/* 88A63C 80241A6C 8E220084 */  lw        $v0, 0x84($s1)
/* 88A640 80241A70 00021FC2 */  srl       $v1, $v0, 0x1f
/* 88A644 80241A74 00431021 */  addu      $v0, $v0, $v1
/* 88A648 80241A78 00021043 */  sra       $v0, $v0, 1
/* 88A64C 80241A7C A60200A8 */  sh        $v0, 0xa8($s0)
.L80241A80:
/* 88A650 80241A80 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 88A654 80241A84 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 88A658 80241A88 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 88A65C 80241A8C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 88A660 80241A90 8C460028 */  lw        $a2, 0x28($v0)
/* 88A664 80241A94 0C00A7B5 */  jal       dist2D
/* 88A668 80241A98 8C470030 */   lw       $a3, 0x30($v0)
/* 88A66C 80241A9C C6020018 */  lwc1      $f2, 0x18($s0)
/* 88A670 80241AA0 46020003 */  div.s     $f0, $f0, $f2
/* 88A674 80241AA4 3C018024 */  lui       $at, %hi(D_802449D0_88D5A0)
/* 88A678 80241AA8 D42249D0 */  ldc1      $f2, %lo(D_802449D0_88D5A0)($at)
/* 88A67C 80241AAC 46000021 */  cvt.d.s   $f0, $f0
/* 88A680 80241AB0 46220000 */  add.d     $f0, $f0, $f2
/* 88A684 80241AB4 4620010D */  trunc.w.d $f4, $f0
/* 88A688 80241AB8 44022000 */  mfc1      $v0, $f4
/* 88A68C 80241ABC 00000000 */  nop
/* 88A690 80241AC0 A602008E */  sh        $v0, 0x8e($s0)
/* 88A694 80241AC4 00021400 */  sll       $v0, $v0, 0x10
/* 88A698 80241AC8 8E230078 */  lw        $v1, 0x78($s1)
/* 88A69C 80241ACC 00021403 */  sra       $v0, $v0, 0x10
/* 88A6A0 80241AD0 0043102A */  slt       $v0, $v0, $v1
/* 88A6A4 80241AD4 10400003 */  beqz      $v0, .L80241AE4
/* 88A6A8 80241AD8 00000000 */   nop
/* 88A6AC 80241ADC 9622007A */  lhu       $v0, 0x7a($s1)
/* 88A6B0 80241AE0 A602008E */  sh        $v0, 0x8e($s0)
.L80241AE4:
/* 88A6B4 80241AE4 8602008E */  lh        $v0, 0x8e($s0)
/* 88A6B8 80241AE8 AE22007C */  sw        $v0, 0x7c($s1)
/* 88A6BC 80241AEC 2402000E */  addiu     $v0, $zero, 0xe
/* 88A6C0 80241AF0 AE620070 */  sw        $v0, 0x70($s3)
.L80241AF4:
/* 88A6C4 80241AF4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 88A6C8 80241AF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 88A6CC 80241AFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 88A6D0 80241B00 8FB10014 */  lw        $s1, 0x14($sp)
/* 88A6D4 80241B04 8FB00010 */  lw        $s0, 0x10($sp)
/* 88A6D8 80241B08 03E00008 */  jr        $ra
/* 88A6DC 80241B0C 27BD0028 */   addiu    $sp, $sp, 0x28
