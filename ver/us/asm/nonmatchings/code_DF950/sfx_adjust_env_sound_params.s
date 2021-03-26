.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sfx_adjust_env_sound_params
/* E02E4 80149BE4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E02E8 80149BE8 AFB00010 */  sw        $s0, 0x10($sp)
/* E02EC 80149BEC 00A0802D */  daddu     $s0, $a1, $zero
/* E02F0 80149BF0 AFB10014 */  sw        $s1, 0x14($sp)
/* E02F4 80149BF4 00C0882D */  daddu     $s1, $a2, $zero
/* E02F8 80149BF8 AFB20018 */  sw        $s2, 0x18($sp)
/* E02FC 80149BFC 00E0902D */  daddu     $s2, $a3, $zero
/* E0300 80149C00 0200282D */  daddu     $a1, $s0, $zero
/* E0304 80149C04 0220302D */  daddu     $a2, $s1, $zero
/* E0308 80149C08 0481000D */  bgez      $a0, .L80149C40
/* E030C 80149C0C AFBF001C */   sw       $ra, 0x1c($sp)
/* E0310 80149C10 3082FFFF */  andi      $v0, $a0, 0xffff
/* E0314 80149C14 00021080 */  sll       $v0, $v0, 2
/* E0318 80149C18 3C048015 */  lui       $a0, %hi(D_8014F2D0)
/* E031C 80149C1C 00822021 */  addu      $a0, $a0, $v0
/* E0320 80149C20 0C052631 */  jal       sfx_get_env_sound_instance
/* E0324 80149C24 8C84F2D0 */   lw       $a0, %lo(D_8014F2D0)($a0)
/* E0328 80149C28 1040000A */  beqz      $v0, .L80149C54
/* E032C 80149C2C 00000000 */   nop
/* E0330 80149C30 A050000C */  sb        $s0, 0xc($v0)
/* E0334 80149C34 A051000D */  sb        $s1, 0xd($v0)
/* E0338 80149C38 08052715 */  j         .L80149C54
/* E033C 80149C3C A452000E */   sh       $s2, 0xe($v0)
.L80149C40:
/* E0340 80149C40 00123C00 */  sll       $a3, $s2, 0x10
/* E0344 80149C44 30A500FF */  andi      $a1, $a1, 0xff
/* E0348 80149C48 30C600FF */  andi      $a2, $a2, 0xff
/* E034C 80149C4C 0C0154CC */  jal       func_80055330
/* E0350 80149C50 00073C03 */   sra      $a3, $a3, 0x10
.L80149C54:
/* E0354 80149C54 8FBF001C */  lw        $ra, 0x1c($sp)
/* E0358 80149C58 8FB20018 */  lw        $s2, 0x18($sp)
/* E035C 80149C5C 8FB10014 */  lw        $s1, 0x14($sp)
/* E0360 80149C60 8FB00010 */  lw        $s0, 0x10($sp)
/* E0364 80149C64 03E00008 */  jr        $ra
/* E0368 80149C68 27BD0020 */   addiu    $sp, $sp, 0x20
