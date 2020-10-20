.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C00_BB0540
/* BB0540 80242C00 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BB0544 80242C04 AFB40040 */  sw        $s4, 0x40($sp)
/* BB0548 80242C08 0080A02D */  daddu     $s4, $a0, $zero
/* BB054C 80242C0C AFBF0044 */  sw        $ra, 0x44($sp)
/* BB0550 80242C10 AFB3003C */  sw        $s3, 0x3c($sp)
/* BB0554 80242C14 AFB20038 */  sw        $s2, 0x38($sp)
/* BB0558 80242C18 AFB10034 */  sw        $s1, 0x34($sp)
/* BB055C 80242C1C AFB00030 */  sw        $s0, 0x30($sp)
/* BB0560 80242C20 8E910148 */  lw        $s1, 0x148($s4)
/* BB0564 80242C24 00A0902D */  daddu     $s2, $a1, $zero
/* BB0568 80242C28 86240008 */  lh        $a0, 8($s1)
/* BB056C 80242C2C 0C00EABB */  jal       get_npc_unsafe
/* BB0570 80242C30 00C0982D */   daddu    $s3, $a2, $zero
/* BB0574 80242C34 0040802D */  daddu     $s0, $v0, $zero
/* BB0578 80242C38 9602008E */  lhu       $v0, 0x8e($s0)
/* BB057C 80242C3C 2442FFFF */  addiu     $v0, $v0, -1
/* BB0580 80242C40 A602008E */  sh        $v0, 0x8e($s0)
/* BB0584 80242C44 00021400 */  sll       $v0, $v0, 0x10
/* BB0588 80242C48 14400020 */  bnez      $v0, .L80242CCC
/* BB058C 80242C4C 0260202D */   daddu    $a0, $s3, $zero
/* BB0590 80242C50 AFA00010 */  sw        $zero, 0x10($sp)
/* BB0594 80242C54 8E46000C */  lw        $a2, 0xc($s2)
/* BB0598 80242C58 8E470010 */  lw        $a3, 0x10($s2)
/* BB059C 80242C5C 0C01242D */  jal       func_800490B4
/* BB05A0 80242C60 0220282D */   daddu    $a1, $s1, $zero
/* BB05A4 80242C64 54400018 */  bnel      $v0, $zero, .L80242CC8
/* BB05A8 80242C68 A600008E */   sh       $zero, 0x8e($s0)
/* BB05AC 80242C6C 24040002 */  addiu     $a0, $zero, 2
/* BB05B0 80242C70 0200282D */  daddu     $a1, $s0, $zero
/* BB05B4 80242C74 0000302D */  daddu     $a2, $zero, $zero
/* BB05B8 80242C78 860300A8 */  lh        $v1, 0xa8($s0)
/* BB05BC 80242C7C 3C013F80 */  lui       $at, 0x3f80
/* BB05C0 80242C80 44810000 */  mtc1      $at, $f0
/* BB05C4 80242C84 3C014000 */  lui       $at, 0x4000
/* BB05C8 80242C88 44811000 */  mtc1      $at, $f2
/* BB05CC 80242C8C 3C01C1A0 */  lui       $at, 0xc1a0
/* BB05D0 80242C90 44812000 */  mtc1      $at, $f4
/* BB05D4 80242C94 2402000F */  addiu     $v0, $zero, 0xf
/* BB05D8 80242C98 AFA2001C */  sw        $v0, 0x1c($sp)
/* BB05DC 80242C9C 44833000 */  mtc1      $v1, $f6
/* BB05E0 80242CA0 00000000 */  nop       
/* BB05E4 80242CA4 468031A0 */  cvt.s.w   $f6, $f6
/* BB05E8 80242CA8 44073000 */  mfc1      $a3, $f6
/* BB05EC 80242CAC 27A20028 */  addiu     $v0, $sp, 0x28
/* BB05F0 80242CB0 AFA20020 */  sw        $v0, 0x20($sp)
/* BB05F4 80242CB4 E7A00010 */  swc1      $f0, 0x10($sp)
/* BB05F8 80242CB8 E7A20014 */  swc1      $f2, 0x14($sp)
/* BB05FC 80242CBC 0C01BFA4 */  jal       fx_emote
/* BB0600 80242CC0 E7A40018 */   swc1     $f4, 0x18($sp)
/* BB0604 80242CC4 A600008E */  sh        $zero, 0x8e($s0)
.L80242CC8:
/* BB0608 80242CC8 AE800070 */  sw        $zero, 0x70($s4)
.L80242CCC:
/* BB060C 80242CCC 8FBF0044 */  lw        $ra, 0x44($sp)
/* BB0610 80242CD0 8FB40040 */  lw        $s4, 0x40($sp)
/* BB0614 80242CD4 8FB3003C */  lw        $s3, 0x3c($sp)
/* BB0618 80242CD8 8FB20038 */  lw        $s2, 0x38($sp)
/* BB061C 80242CDC 8FB10034 */  lw        $s1, 0x34($sp)
/* BB0620 80242CE0 8FB00030 */  lw        $s0, 0x30($sp)
/* BB0624 80242CE4 03E00008 */  jr        $ra
/* BB0628 80242CE8 27BD0048 */   addiu    $sp, $sp, 0x48
