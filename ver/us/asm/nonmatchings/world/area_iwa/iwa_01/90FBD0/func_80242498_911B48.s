.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802465D0_915C80
.double 0.85

.section .text

glabel func_80242498_911B48
/* 911B48 80242498 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 911B4C 8024249C AFB3003C */  sw        $s3, 0x3c($sp)
/* 911B50 802424A0 0080982D */  daddu     $s3, $a0, $zero
/* 911B54 802424A4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 911B58 802424A8 AFB40040 */  sw        $s4, 0x40($sp)
/* 911B5C 802424AC AFB20038 */  sw        $s2, 0x38($sp)
/* 911B60 802424B0 AFB10034 */  sw        $s1, 0x34($sp)
/* 911B64 802424B4 AFB00030 */  sw        $s0, 0x30($sp)
/* 911B68 802424B8 8E700148 */  lw        $s0, 0x148($s3)
/* 911B6C 802424BC 00A0902D */  daddu     $s2, $a1, $zero
/* 911B70 802424C0 86040008 */  lh        $a0, 8($s0)
/* 911B74 802424C4 0C00EABB */  jal       get_npc_unsafe
/* 911B78 802424C8 00C0A02D */   daddu    $s4, $a2, $zero
/* 911B7C 802424CC 8E630074 */  lw        $v1, 0x74($s3)
/* 911B80 802424D0 1C600032 */  bgtz      $v1, .L8024259C
/* 911B84 802424D4 0040882D */   daddu    $s1, $v0, $zero
/* 911B88 802424D8 8E420014 */  lw        $v0, 0x14($s2)
/* 911B8C 802424DC AE620074 */  sw        $v0, 0x74($s3)
/* 911B90 802424E0 C640000C */  lwc1      $f0, 0xc($s2)
/* 911B94 802424E4 3C018024 */  lui       $at, %hi(D_802465D0_915C80)
/* 911B98 802424E8 D42265D0 */  ldc1      $f2, %lo(D_802465D0_915C80)($at)
/* 911B9C 802424EC 46000021 */  cvt.d.s   $f0, $f0
/* 911BA0 802424F0 46220002 */  mul.d     $f0, $f0, $f2
/* 911BA4 802424F4 00000000 */  nop
/* 911BA8 802424F8 0280202D */  daddu     $a0, $s4, $zero
/* 911BAC 802424FC AFA00010 */  sw        $zero, 0x10($sp)
/* 911BB0 80242500 8E470010 */  lw        $a3, 0x10($s2)
/* 911BB4 80242504 46200020 */  cvt.s.d   $f0, $f0
/* 911BB8 80242508 44060000 */  mfc1      $a2, $f0
/* 911BBC 8024250C 0C01242D */  jal       func_800490B4
/* 911BC0 80242510 0200282D */   daddu    $a1, $s0, $zero
/* 911BC4 80242514 10400021 */  beqz      $v0, .L8024259C
/* 911BC8 80242518 0000202D */   daddu    $a0, $zero, $zero
/* 911BCC 8024251C 0220282D */  daddu     $a1, $s1, $zero
/* 911BD0 80242520 0000302D */  daddu     $a2, $zero, $zero
/* 911BD4 80242524 8E0200CC */  lw        $v0, 0xcc($s0)
/* 911BD8 80242528 3C013F80 */  lui       $at, 0x3f80
/* 911BDC 8024252C 44810000 */  mtc1      $at, $f0
/* 911BE0 80242530 3C014000 */  lui       $at, 0x4000
/* 911BE4 80242534 44811000 */  mtc1      $at, $f2
/* 911BE8 80242538 8C430024 */  lw        $v1, 0x24($v0)
/* 911BEC 8024253C 862200A8 */  lh        $v0, 0xa8($s1)
/* 911BF0 80242540 3C01C1A0 */  lui       $at, 0xc1a0
/* 911BF4 80242544 44812000 */  mtc1      $at, $f4
/* 911BF8 80242548 44823000 */  mtc1      $v0, $f6
/* 911BFC 8024254C 00000000 */  nop
/* 911C00 80242550 468031A0 */  cvt.s.w   $f6, $f6
/* 911C04 80242554 44073000 */  mfc1      $a3, $f6
/* 911C08 80242558 2402000F */  addiu     $v0, $zero, 0xf
/* 911C0C 8024255C AE230028 */  sw        $v1, 0x28($s1)
/* 911C10 80242560 AFA2001C */  sw        $v0, 0x1c($sp)
/* 911C14 80242564 27A20028 */  addiu     $v0, $sp, 0x28
/* 911C18 80242568 E7A00010 */  swc1      $f0, 0x10($sp)
/* 911C1C 8024256C E7A20014 */  swc1      $f2, 0x14($sp)
/* 911C20 80242570 E7A40018 */  swc1      $f4, 0x18($sp)
/* 911C24 80242574 0C01BFA4 */  jal       fx_emote
/* 911C28 80242578 AFA20020 */   sw       $v0, 0x20($sp)
/* 911C2C 8024257C 0220202D */  daddu     $a0, $s1, $zero
/* 911C30 80242580 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 911C34 80242584 0C012530 */  jal       ai_enemy_play_sound
/* 911C38 80242588 3C060020 */   lui      $a2, 0x20
/* 911C3C 8024258C 2402000C */  addiu     $v0, $zero, 0xc
/* 911C40 80242590 A622008E */  sh        $v0, 0x8e($s1)
/* 911C44 80242594 24020002 */  addiu     $v0, $zero, 2
/* 911C48 80242598 AE620070 */  sw        $v0, 0x70($s3)
.L8024259C:
/* 911C4C 8024259C 8E620074 */  lw        $v0, 0x74($s3)
/* 911C50 802425A0 2442FFFF */  addiu     $v0, $v0, -1
/* 911C54 802425A4 AE620074 */  sw        $v0, 0x74($s3)
/* 911C58 802425A8 8FBF0044 */  lw        $ra, 0x44($sp)
/* 911C5C 802425AC 8FB40040 */  lw        $s4, 0x40($sp)
/* 911C60 802425B0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 911C64 802425B4 8FB20038 */  lw        $s2, 0x38($sp)
/* 911C68 802425B8 8FB10034 */  lw        $s1, 0x34($sp)
/* 911C6C 802425BC 8FB00030 */  lw        $s0, 0x30($sp)
/* 911C70 802425C0 03E00008 */  jr        $ra
/* 911C74 802425C4 27BD0048 */   addiu    $sp, $sp, 0x48
