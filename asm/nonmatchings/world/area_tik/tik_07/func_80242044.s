.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242044
/* 87BC24 80242044 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 87BC28 80242048 AFB00010 */  sw        $s0, 0x10($sp)
/* 87BC2C 8024204C 0080802D */  daddu     $s0, $a0, $zero
/* 87BC30 80242050 AFBF0014 */  sw        $ra, 0x14($sp)
/* 87BC34 80242054 8E020148 */  lw        $v0, 0x148($s0)
/* 87BC38 80242058 0C00EABB */  jal       get_npc_unsafe
/* 87BC3C 8024205C 84440008 */   lh       $a0, 8($v0)
/* 87BC40 80242060 9443008E */  lhu       $v1, 0x8e($v0)
/* 87BC44 80242064 C440003C */  lwc1      $f0, 0x3c($v0)
/* 87BC48 80242068 24640001 */  addiu     $a0, $v1, 1
/* 87BC4C 8024206C 00031C00 */  sll       $v1, $v1, 0x10
/* 87BC50 80242070 00031B83 */  sra       $v1, $v1, 0xe
/* 87BC54 80242074 A444008E */  sh        $a0, 0x8e($v0)
/* 87BC58 80242078 3C018024 */  lui       $at, 0x8024
/* 87BC5C 8024207C 00230821 */  addu      $at, $at, $v1
/* 87BC60 80242080 C4224CB0 */  lwc1      $f2, 0x4cb0($at)
/* 87BC64 80242084 8443008E */  lh        $v1, 0x8e($v0)
/* 87BC68 80242088 46020000 */  add.s     $f0, $f0, $f2
/* 87BC6C 8024208C 28630005 */  slti      $v1, $v1, 5
/* 87BC70 80242090 14600003 */  bnez      $v1, .L802420A0
/* 87BC74 80242094 E440003C */   swc1     $f0, 0x3c($v0)
/* 87BC78 80242098 2402000C */  addiu     $v0, $zero, 0xc
/* 87BC7C 8024209C AE020070 */  sw        $v0, 0x70($s0)
.L802420A0:
/* 87BC80 802420A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 87BC84 802420A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 87BC88 802420A8 03E00008 */  jr        $ra
/* 87BC8C 802420AC 27BD0018 */   addiu    $sp, $sp, 0x18
