.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240980
/* BB79F0 80240980 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BB79F4 80240984 F7B40018 */  sdc1      $f20, 0x18($sp)
/* BB79F8 80240988 4485A000 */  mtc1      $a1, $f20
/* BB79FC 8024098C F7B60020 */  sdc1      $f22, 0x20($sp)
/* BB7A00 80240990 4486B000 */  mtc1      $a2, $f22
/* BB7A04 80240994 AFB00010 */  sw        $s0, 0x10($sp)
/* BB7A08 80240998 F7B80028 */  sdc1      $f24, 0x28($sp)
/* BB7A0C 8024099C 4487C000 */  mtc1      $a3, $f24
/* BB7A10 802409A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* BB7A14 802409A4 0C019D28 */  jal       guMtxIdentF
/* BB7A18 802409A8 0080802D */   daddu    $s0, $a0, $zero
/* BB7A1C 802409AC 4616A582 */  mul.s     $f22, $f20, $f22
/* BB7A20 802409B0 00000000 */  nop       
/* BB7A24 802409B4 4618A502 */  mul.s     $f20, $f20, $f24
/* BB7A28 802409B8 00000000 */  nop       
/* BB7A2C 802409BC 3C013F80 */  lui       $at, 0x3f80
/* BB7A30 802409C0 44810000 */  mtc1      $at, $f0
/* BB7A34 802409C4 00000000 */  nop       
/* BB7A38 802409C8 E6000014 */  swc1      $f0, 0x14($s0)
/* BB7A3C 802409CC E6160010 */  swc1      $f22, 0x10($s0)
/* BB7A40 802409D0 E6140018 */  swc1      $f20, 0x18($s0)
/* BB7A44 802409D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* BB7A48 802409D8 8FB00010 */  lw        $s0, 0x10($sp)
/* BB7A4C 802409DC D7B80028 */  ldc1      $f24, 0x28($sp)
/* BB7A50 802409E0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* BB7A54 802409E4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* BB7A58 802409E8 03E00008 */  jr        $ra
/* BB7A5C 802409EC 27BD0030 */   addiu    $sp, $sp, 0x30
