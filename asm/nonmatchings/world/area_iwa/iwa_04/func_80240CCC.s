.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CCC
/* 91C5AC 80240CCC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91C5B0 80240CD0 AFB00010 */  sw        $s0, 0x10($sp)
/* 91C5B4 80240CD4 0080802D */  daddu     $s0, $a0, $zero
/* 91C5B8 80240CD8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 91C5BC 80240CDC 8E020148 */  lw        $v0, 0x148($s0)
/* 91C5C0 80240CE0 0C00EABB */  jal       get_npc_unsafe
/* 91C5C4 80240CE4 84440008 */   lh       $a0, 8($v0)
/* 91C5C8 80240CE8 9443008E */  lhu       $v1, 0x8e($v0)
/* 91C5CC 80240CEC 2463FFFF */  addiu     $v1, $v1, -1
/* 91C5D0 80240CF0 A443008E */  sh        $v1, 0x8e($v0)
/* 91C5D4 80240CF4 00031C00 */  sll       $v1, $v1, 0x10
/* 91C5D8 80240CF8 58600001 */  blezl     $v1, .L80240D00
/* 91C5DC 80240CFC AE000070 */   sw       $zero, 0x70($s0)
.L80240D00:
/* 91C5E0 80240D00 8FBF0014 */  lw        $ra, 0x14($sp)
/* 91C5E4 80240D04 8FB00010 */  lw        $s0, 0x10($sp)
/* 91C5E8 80240D08 03E00008 */  jr        $ra
/* 91C5EC 80240D0C 27BD0018 */   addiu    $sp, $sp, 0x18
