.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240920_BD4190
/* BD4190 80240920 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BD4194 80240924 AFB00020 */  sw        $s0, 0x20($sp)
/* BD4198 80240928 0080802D */  daddu     $s0, $a0, $zero
/* BD419C 8024092C AFBF0024 */  sw        $ra, 0x24($sp)
/* BD41A0 80240930 C602000C */  lwc1      $f2, 0xc($s0)
/* BD41A4 80240934 3C0143AA */  lui       $at, 0x43aa
/* BD41A8 80240938 44810000 */  mtc1      $at, $f0
/* BD41AC 8024093C 00000000 */  nop
/* BD41B0 80240940 4602003C */  c.lt.s    $f0, $f2
/* BD41B4 80240944 00000000 */  nop
/* BD41B8 80240948 45010008 */  bc1t      .L8024096C
/* BD41BC 8024094C 0200202D */   daddu    $a0, $s0, $zero
/* BD41C0 80240950 3C0141A0 */  lui       $at, 0x41a0
/* BD41C4 80240954 44810000 */  mtc1      $at, $f0
/* BD41C8 80240958 00000000 */  nop
/* BD41CC 8024095C 4600103C */  c.lt.s    $f2, $f0
/* BD41D0 80240960 00000000 */  nop
/* BD41D4 80240964 4500000E */  bc1f      .L802409A0
/* BD41D8 80240968 24020016 */   addiu    $v0, $zero, 0x16
.L8024096C:
/* BD41DC 8024096C 0000282D */  daddu     $a1, $zero, $zero
/* BD41E0 80240970 00A0302D */  daddu     $a2, $a1, $zero
/* BD41E4 80240974 2402000D */  addiu     $v0, $zero, 0xd
/* BD41E8 80240978 A08200AA */  sb        $v0, 0xaa($a0)
/* BD41EC 8024097C A48000A2 */  sh        $zero, 0xa2($a0)
/* BD41F0 80240980 AFA00010 */  sw        $zero, 0x10($sp)
/* BD41F4 80240984 AFA00014 */  sw        $zero, 0x14($sp)
/* BD41F8 80240988 948200A2 */  lhu       $v0, 0xa2($a0)
/* BD41FC 8024098C 00A0382D */  daddu     $a3, $a1, $zero
/* BD4200 80240990 0C00F589 */  jal       func_8003D624
/* BD4204 80240994 AFA20018 */   sw       $v0, 0x18($sp)
/* BD4208 80240998 08090276 */  j         .L802409D8
/* BD420C 8024099C 00000000 */   nop
.L802409A0:
/* BD4210 802409A0 A20200AA */  sb        $v0, 0xaa($s0)
/* BD4214 802409A4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BD4218 802409A8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BD421C 802409AC 0200202D */  daddu     $a0, $s0, $zero
/* BD4220 802409B0 9046000E */  lbu       $a2, 0xe($v0)
/* BD4224 802409B4 24050007 */  addiu     $a1, $zero, 7
/* BD4228 802409B8 AFA00010 */  sw        $zero, 0x10($sp)
/* BD422C 802409BC AFA00014 */  sw        $zero, 0x14($sp)
/* BD4230 802409C0 960200A2 */  lhu       $v0, 0xa2($s0)
/* BD4234 802409C4 0000382D */  daddu     $a3, $zero, $zero
/* BD4238 802409C8 0C00F589 */  jal       func_8003D624
/* BD423C 802409CC AFA20018 */   sw       $v0, 0x18($sp)
/* BD4240 802409D0 240200FF */  addiu     $v0, $zero, 0xff
/* BD4244 802409D4 A602009A */  sh        $v0, 0x9a($s0)
.L802409D8:
/* BD4248 802409D8 8FBF0024 */  lw        $ra, 0x24($sp)
/* BD424C 802409DC 8FB00020 */  lw        $s0, 0x20($sp)
/* BD4250 802409E0 03E00008 */  jr        $ra
/* BD4254 802409E4 27BD0028 */   addiu    $sp, $sp, 0x28
