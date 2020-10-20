.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241978_C87428
/* C87428 80241978 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C8742C 8024197C AFB40040 */  sw        $s4, 0x40($sp)
/* C87430 80241980 0080A02D */  daddu     $s4, $a0, $zero
/* C87434 80241984 AFBF0044 */  sw        $ra, 0x44($sp)
/* C87438 80241988 AFB3003C */  sw        $s3, 0x3c($sp)
/* C8743C 8024198C AFB20038 */  sw        $s2, 0x38($sp)
/* C87440 80241990 AFB10034 */  sw        $s1, 0x34($sp)
/* C87444 80241994 AFB00030 */  sw        $s0, 0x30($sp)
/* C87448 80241998 8E910148 */  lw        $s1, 0x148($s4)
/* C8744C 8024199C 00A0902D */  daddu     $s2, $a1, $zero
/* C87450 802419A0 86240008 */  lh        $a0, 8($s1)
/* C87454 802419A4 0C00EABB */  jal       get_npc_unsafe
/* C87458 802419A8 00C0982D */   daddu    $s3, $a2, $zero
/* C8745C 802419AC 0040802D */  daddu     $s0, $v0, $zero
/* C87460 802419B0 9602008E */  lhu       $v0, 0x8e($s0)
/* C87464 802419B4 2442FFFF */  addiu     $v0, $v0, -1
/* C87468 802419B8 A602008E */  sh        $v0, 0x8e($s0)
/* C8746C 802419BC 00021400 */  sll       $v0, $v0, 0x10
/* C87470 802419C0 14400020 */  bnez      $v0, .L80241A44
/* C87474 802419C4 0260202D */   daddu    $a0, $s3, $zero
/* C87478 802419C8 AFA00010 */  sw        $zero, 0x10($sp)
/* C8747C 802419CC 8E46000C */  lw        $a2, 0xc($s2)
/* C87480 802419D0 8E470010 */  lw        $a3, 0x10($s2)
/* C87484 802419D4 0C01242D */  jal       func_800490B4
/* C87488 802419D8 0220282D */   daddu    $a1, $s1, $zero
/* C8748C 802419DC 54400018 */  bnel      $v0, $zero, .L80241A40
/* C87490 802419E0 A600008E */   sh       $zero, 0x8e($s0)
/* C87494 802419E4 24040002 */  addiu     $a0, $zero, 2
/* C87498 802419E8 0200282D */  daddu     $a1, $s0, $zero
/* C8749C 802419EC 0000302D */  daddu     $a2, $zero, $zero
/* C874A0 802419F0 860300A8 */  lh        $v1, 0xa8($s0)
/* C874A4 802419F4 3C013F80 */  lui       $at, 0x3f80
/* C874A8 802419F8 44810000 */  mtc1      $at, $f0
/* C874AC 802419FC 3C014000 */  lui       $at, 0x4000
/* C874B0 80241A00 44811000 */  mtc1      $at, $f2
/* C874B4 80241A04 3C01C1A0 */  lui       $at, 0xc1a0
/* C874B8 80241A08 44812000 */  mtc1      $at, $f4
/* C874BC 80241A0C 2402000F */  addiu     $v0, $zero, 0xf
/* C874C0 80241A10 AFA2001C */  sw        $v0, 0x1c($sp)
/* C874C4 80241A14 44833000 */  mtc1      $v1, $f6
/* C874C8 80241A18 00000000 */  nop       
/* C874CC 80241A1C 468031A0 */  cvt.s.w   $f6, $f6
/* C874D0 80241A20 44073000 */  mfc1      $a3, $f6
/* C874D4 80241A24 27A20028 */  addiu     $v0, $sp, 0x28
/* C874D8 80241A28 AFA20020 */  sw        $v0, 0x20($sp)
/* C874DC 80241A2C E7A00010 */  swc1      $f0, 0x10($sp)
/* C874E0 80241A30 E7A20014 */  swc1      $f2, 0x14($sp)
/* C874E4 80241A34 0C01BFA4 */  jal       fx_emote
/* C874E8 80241A38 E7A40018 */   swc1     $f4, 0x18($sp)
/* C874EC 80241A3C A600008E */  sh        $zero, 0x8e($s0)
.L80241A40:
/* C874F0 80241A40 AE800070 */  sw        $zero, 0x70($s4)
.L80241A44:
/* C874F4 80241A44 8FBF0044 */  lw        $ra, 0x44($sp)
/* C874F8 80241A48 8FB40040 */  lw        $s4, 0x40($sp)
/* C874FC 80241A4C 8FB3003C */  lw        $s3, 0x3c($sp)
/* C87500 80241A50 8FB20038 */  lw        $s2, 0x38($sp)
/* C87504 80241A54 8FB10034 */  lw        $s1, 0x34($sp)
/* C87508 80241A58 8FB00030 */  lw        $s0, 0x30($sp)
/* C8750C 80241A5C 03E00008 */  jr        $ra
/* C87510 80241A60 27BD0048 */   addiu    $sp, $sp, 0x48
