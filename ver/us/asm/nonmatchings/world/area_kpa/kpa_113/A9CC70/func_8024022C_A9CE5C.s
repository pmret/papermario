.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241CF0_A9E920
.double 0.8

.section .text

glabel func_8024022C_A9CE5C
/* A9CE5C 8024022C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A9CE60 80240230 AFB3001C */  sw        $s3, 0x1c($sp)
/* A9CE64 80240234 0080982D */  daddu     $s3, $a0, $zero
/* A9CE68 80240238 AFBF0020 */  sw        $ra, 0x20($sp)
/* A9CE6C 8024023C AFB20018 */  sw        $s2, 0x18($sp)
/* A9CE70 80240240 AFB10014 */  sw        $s1, 0x14($sp)
/* A9CE74 80240244 AFB00010 */  sw        $s0, 0x10($sp)
/* A9CE78 80240248 8E710148 */  lw        $s1, 0x148($s3)
/* A9CE7C 8024024C 86240008 */  lh        $a0, 8($s1)
/* A9CE80 80240250 0C00EABB */  jal       get_npc_unsafe
/* A9CE84 80240254 00A0902D */   daddu    $s2, $a1, $zero
/* A9CE88 80240258 0040802D */  daddu     $s0, $v0, $zero
/* A9CE8C 8024025C 8602008E */  lh        $v0, 0x8e($s0)
/* A9CE90 80240260 9603008E */  lhu       $v1, 0x8e($s0)
/* A9CE94 80240264 18400005 */  blez      $v0, .L8024027C
/* A9CE98 80240268 2462FFFF */   addiu    $v0, $v1, -1
/* A9CE9C 8024026C A602008E */  sh        $v0, 0x8e($s0)
/* A9CEA0 80240270 00021400 */  sll       $v0, $v0, 0x10
/* A9CEA4 80240274 1C400033 */  bgtz      $v0, .L80240344
/* A9CEA8 80240278 00000000 */   nop
.L8024027C:
/* A9CEAC 8024027C 8602008C */  lh        $v0, 0x8c($s0)
/* A9CEB0 80240280 14400030 */  bnez      $v0, .L80240344
/* A9CEB4 80240284 00000000 */   nop
/* A9CEB8 80240288 8E2200CC */  lw        $v0, 0xcc($s1)
/* A9CEBC 8024028C 8C420024 */  lw        $v0, 0x24($v0)
/* A9CEC0 80240290 AE020028 */  sw        $v0, 0x28($s0)
/* A9CEC4 80240294 C6400018 */  lwc1      $f0, 0x18($s2)
/* A9CEC8 80240298 E6000018 */  swc1      $f0, 0x18($s0)
/* A9CECC 8024029C 8E230088 */  lw        $v1, 0x88($s1)
/* A9CED0 802402A0 24020005 */  addiu     $v0, $zero, 5
/* A9CED4 802402A4 10620005 */  beq       $v1, $v0, .L802402BC
/* A9CED8 802402A8 00000000 */   nop
/* A9CEDC 802402AC 10600003 */  beqz      $v1, .L802402BC
/* A9CEE0 802402B0 24020001 */   addiu    $v0, $zero, 1
/* A9CEE4 802402B4 14620006 */  bne       $v1, $v0, .L802402D0
/* A9CEE8 802402B8 00000000 */   nop
.L802402BC:
/* A9CEEC 802402BC 8E220084 */  lw        $v0, 0x84($s1)
/* A9CEF0 802402C0 00021FC2 */  srl       $v1, $v0, 0x1f
/* A9CEF4 802402C4 00431021 */  addu      $v0, $v0, $v1
/* A9CEF8 802402C8 00021043 */  sra       $v0, $v0, 1
/* A9CEFC 802402CC A60200A8 */  sh        $v0, 0xa8($s0)
.L802402D0:
/* A9CF00 802402D0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A9CF04 802402D4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A9CF08 802402D8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A9CF0C 802402DC C60E0040 */  lwc1      $f14, 0x40($s0)
/* A9CF10 802402E0 8C460028 */  lw        $a2, 0x28($v0)
/* A9CF14 802402E4 0C00A7B5 */  jal       dist2D
/* A9CF18 802402E8 8C470030 */   lw       $a3, 0x30($v0)
/* A9CF1C 802402EC C6020018 */  lwc1      $f2, 0x18($s0)
/* A9CF20 802402F0 46020003 */  div.s     $f0, $f0, $f2
/* A9CF24 802402F4 3C018024 */  lui       $at, %hi(D_80241CF0_A9E920)
/* A9CF28 802402F8 D4221CF0 */  ldc1      $f2, %lo(D_80241CF0_A9E920)($at)
/* A9CF2C 802402FC 46000021 */  cvt.d.s   $f0, $f0
/* A9CF30 80240300 46220000 */  add.d     $f0, $f0, $f2
/* A9CF34 80240304 4620010D */  trunc.w.d $f4, $f0
/* A9CF38 80240308 44022000 */  mfc1      $v0, $f4
/* A9CF3C 8024030C 00000000 */  nop
/* A9CF40 80240310 A602008E */  sh        $v0, 0x8e($s0)
/* A9CF44 80240314 00021400 */  sll       $v0, $v0, 0x10
/* A9CF48 80240318 8E230078 */  lw        $v1, 0x78($s1)
/* A9CF4C 8024031C 00021403 */  sra       $v0, $v0, 0x10
/* A9CF50 80240320 0043102A */  slt       $v0, $v0, $v1
/* A9CF54 80240324 10400003 */  beqz      $v0, .L80240334
/* A9CF58 80240328 00000000 */   nop
/* A9CF5C 8024032C 9622007A */  lhu       $v0, 0x7a($s1)
/* A9CF60 80240330 A602008E */  sh        $v0, 0x8e($s0)
.L80240334:
/* A9CF64 80240334 8602008E */  lh        $v0, 0x8e($s0)
/* A9CF68 80240338 AE22007C */  sw        $v0, 0x7c($s1)
/* A9CF6C 8024033C 2402000E */  addiu     $v0, $zero, 0xe
/* A9CF70 80240340 AE620070 */  sw        $v0, 0x70($s3)
.L80240344:
/* A9CF74 80240344 8FBF0020 */  lw        $ra, 0x20($sp)
/* A9CF78 80240348 8FB3001C */  lw        $s3, 0x1c($sp)
/* A9CF7C 8024034C 8FB20018 */  lw        $s2, 0x18($sp)
/* A9CF80 80240350 8FB10014 */  lw        $s1, 0x14($sp)
/* A9CF84 80240354 8FB00010 */  lw        $s0, 0x10($sp)
/* A9CF88 80240358 03E00008 */  jr        $ra
/* A9CF8C 8024035C 27BD0028 */   addiu    $sp, $sp, 0x28
