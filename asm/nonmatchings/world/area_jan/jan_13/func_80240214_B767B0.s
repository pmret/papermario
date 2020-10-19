.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240214_B769C4
/* B769C4 80240214 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B769C8 80240218 AFB1001C */  sw        $s1, 0x1c($sp)
/* B769CC 8024021C 0080882D */  daddu     $s1, $a0, $zero
/* B769D0 80240220 AFBF0020 */  sw        $ra, 0x20($sp)
/* B769D4 80240224 AFB00018 */  sw        $s0, 0x18($sp)
/* B769D8 80240228 8E30000C */  lw        $s0, 0xc($s1)
/* B769DC 8024022C 8E020000 */  lw        $v0, ($s0)
/* B769E0 80240230 1040001B */  beqz      $v0, .L802402A0
/* B769E4 80240234 26100004 */   addiu    $s0, $s0, 4
/* B769E8 80240238 8E050000 */  lw        $a1, ($s0)
/* B769EC 8024023C 0C0B1EAF */  jal       get_variable
/* B769F0 80240240 26100004 */   addiu    $s0, $s0, 4
/* B769F4 80240244 AE220070 */  sw        $v0, 0x70($s1)
/* B769F8 80240248 8E050000 */  lw        $a1, ($s0)
/* B769FC 8024024C 26100004 */  addiu     $s0, $s0, 4
/* B76A00 80240250 0C0B1EAF */  jal       get_variable
/* B76A04 80240254 0220202D */   daddu    $a0, $s1, $zero
/* B76A08 80240258 AE220074 */  sw        $v0, 0x74($s1)
/* B76A0C 8024025C 8E050000 */  lw        $a1, ($s0)
/* B76A10 80240260 0C0B1EAF */  jal       get_variable
/* B76A14 80240264 0220202D */   daddu    $a0, $s1, $zero
/* B76A18 80240268 2404004E */  addiu     $a0, $zero, 0x4e
/* B76A1C 8024026C 0000282D */  daddu     $a1, $zero, $zero
/* B76A20 80240270 C6200070 */  lwc1      $f0, 0x70($s1)
/* B76A24 80240274 46800020 */  cvt.s.w   $f0, $f0
/* B76A28 80240278 C6220074 */  lwc1      $f2, 0x74($s1)
/* B76A2C 8024027C 468010A0 */  cvt.s.w   $f2, $f2
/* B76A30 80240280 44060000 */  mfc1      $a2, $f0
/* B76A34 80240284 44071000 */  mfc1      $a3, $f2
/* B76A38 80240288 44820000 */  mtc1      $v0, $f0
/* B76A3C 8024028C 00000000 */  nop       
/* B76A40 80240290 46800020 */  cvt.s.w   $f0, $f0
/* B76A44 80240294 AE220078 */  sw        $v0, 0x78($s1)
/* B76A48 80240298 0C05267B */  jal       func_801499EC
/* B76A4C 8024029C E7A00010 */   swc1     $f0, 0x10($sp)
.L802402A0:
/* B76A50 802402A0 8FBF0020 */  lw        $ra, 0x20($sp)
/* B76A54 802402A4 8FB1001C */  lw        $s1, 0x1c($sp)
/* B76A58 802402A8 8FB00018 */  lw        $s0, 0x18($sp)
/* B76A5C 802402AC 24020002 */  addiu     $v0, $zero, 2
/* B76A60 802402B0 03E00008 */  jr        $ra
/* B76A64 802402B4 27BD0028 */   addiu    $sp, $sp, 0x28
