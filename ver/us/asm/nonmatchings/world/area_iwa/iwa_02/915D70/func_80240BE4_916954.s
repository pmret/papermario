.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BE4_916954
/* 916954 80240BE4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 916958 80240BE8 AFB10014 */  sw        $s1, 0x14($sp)
/* 91695C 80240BEC 0080882D */  daddu     $s1, $a0, $zero
/* 916960 80240BF0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 916964 80240BF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 916968 80240BF8 8E300148 */  lw        $s0, 0x148($s1)
/* 91696C 80240BFC 0C00EABB */  jal       get_npc_unsafe
/* 916970 80240C00 86040008 */   lh       $a0, 8($s0)
/* 916974 80240C04 0040182D */  daddu     $v1, $v0, $zero
/* 916978 80240C08 9462008E */  lhu       $v0, 0x8e($v1)
/* 91697C 80240C0C 2442FFFF */  addiu     $v0, $v0, -1
/* 916980 80240C10 A462008E */  sh        $v0, 0x8e($v1)
/* 916984 80240C14 00021400 */  sll       $v0, $v0, 0x10
/* 916988 80240C18 1C400007 */  bgtz      $v0, .L80240C38
/* 91698C 80240C1C 24020008 */   addiu    $v0, $zero, 8
/* 916990 80240C20 A462008E */  sh        $v0, 0x8e($v1)
/* 916994 80240C24 8E0200CC */  lw        $v0, 0xcc($s0)
/* 916998 80240C28 8C420038 */  lw        $v0, 0x38($v0)
/* 91699C 80240C2C AC620028 */  sw        $v0, 0x28($v1)
/* 9169A0 80240C30 24020034 */  addiu     $v0, $zero, 0x34
/* 9169A4 80240C34 AE220070 */  sw        $v0, 0x70($s1)
.L80240C38:
/* 9169A8 80240C38 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9169AC 80240C3C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9169B0 80240C40 8FB00010 */  lw        $s0, 0x10($sp)
/* 9169B4 80240C44 03E00008 */  jr        $ra
/* 9169B8 80240C48 27BD0020 */   addiu    $sp, $sp, 0x20
