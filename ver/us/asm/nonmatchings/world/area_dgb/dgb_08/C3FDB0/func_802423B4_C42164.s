.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423B4_C42164
/* C42164 802423B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C42168 802423B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C4216C 802423BC 0080802D */  daddu     $s0, $a0, $zero
/* C42170 802423C0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C42174 802423C4 8E020148 */  lw        $v0, 0x148($s0)
/* C42178 802423C8 0C00EABB */  jal       get_npc_unsafe
/* C4217C 802423CC 84440008 */   lh       $a0, 8($v0)
/* C42180 802423D0 9443008E */  lhu       $v1, 0x8e($v0)
/* C42184 802423D4 C440003C */  lwc1      $f0, 0x3c($v0)
/* C42188 802423D8 24640001 */  addiu     $a0, $v1, 1
/* C4218C 802423DC 00031C00 */  sll       $v1, $v1, 0x10
/* C42190 802423E0 00031B83 */  sra       $v1, $v1, 0xe
/* C42194 802423E4 A444008E */  sh        $a0, 0x8e($v0)
/* C42198 802423E8 3C018024 */  lui       $at, %hi(D_80244460_C44210)
/* C4219C 802423EC 00230821 */  addu      $at, $at, $v1
/* C421A0 802423F0 C4224460 */  lwc1      $f2, %lo(D_80244460_C44210)($at)
/* C421A4 802423F4 8443008E */  lh        $v1, 0x8e($v0)
/* C421A8 802423F8 46020000 */  add.s     $f0, $f0, $f2
/* C421AC 802423FC 28630005 */  slti      $v1, $v1, 5
/* C421B0 80242400 14600003 */  bnez      $v1, .L80242410
/* C421B4 80242404 E440003C */   swc1     $f0, 0x3c($v0)
/* C421B8 80242408 2402000C */  addiu     $v0, $zero, 0xc
/* C421BC 8024240C AE020070 */  sw        $v0, 0x70($s0)
.L80242410:
/* C421C0 80242410 8FBF0014 */  lw        $ra, 0x14($sp)
/* C421C4 80242414 8FB00010 */  lw        $s0, 0x10($sp)
/* C421C8 80242418 03E00008 */  jr        $ra
/* C421CC 8024241C 27BD0018 */   addiu    $sp, $sp, 0x18
