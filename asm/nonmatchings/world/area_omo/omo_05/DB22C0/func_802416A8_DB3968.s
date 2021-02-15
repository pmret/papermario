.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416A8_DB3968
/* DB3968 802416A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB396C 802416AC AFB00010 */  sw        $s0, 0x10($sp)
/* DB3970 802416B0 0080802D */  daddu     $s0, $a0, $zero
/* DB3974 802416B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB3978 802416B8 8E020148 */  lw        $v0, 0x148($s0)
/* DB397C 802416BC 0C00EABB */  jal       get_npc_unsafe
/* DB3980 802416C0 84440008 */   lh       $a0, 8($v0)
/* DB3984 802416C4 9443008E */  lhu       $v1, 0x8e($v0)
/* DB3988 802416C8 C440003C */  lwc1      $f0, 0x3c($v0)
/* DB398C 802416CC 24640001 */  addiu     $a0, $v1, 1
/* DB3990 802416D0 00031C00 */  sll       $v1, $v1, 0x10
/* DB3994 802416D4 00031B83 */  sra       $v1, $v1, 0xe
/* DB3998 802416D8 A444008E */  sh        $a0, 0x8e($v0)
/* DB399C 802416DC 3C018024 */  lui       $at, %hi(D_80242F88_DB5248)
/* DB39A0 802416E0 00230821 */  addu      $at, $at, $v1
/* DB39A4 802416E4 C4222F88 */  lwc1      $f2, %lo(D_80242F88_DB5248)($at)
/* DB39A8 802416E8 8443008E */  lh        $v1, 0x8e($v0)
/* DB39AC 802416EC 46020000 */  add.s     $f0, $f0, $f2
/* DB39B0 802416F0 28630005 */  slti      $v1, $v1, 5
/* DB39B4 802416F4 14600003 */  bnez      $v1, .L80241704
/* DB39B8 802416F8 E440003C */   swc1     $f0, 0x3c($v0)
/* DB39BC 802416FC 2402000C */  addiu     $v0, $zero, 0xc
/* DB39C0 80241700 AE020070 */  sw        $v0, 0x70($s0)
.L80241704:
/* DB39C4 80241704 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB39C8 80241708 8FB00010 */  lw        $s0, 0x10($sp)
/* DB39CC 8024170C 03E00008 */  jr        $ra
/* DB39D0 80241710 27BD0018 */   addiu    $sp, $sp, 0x18
