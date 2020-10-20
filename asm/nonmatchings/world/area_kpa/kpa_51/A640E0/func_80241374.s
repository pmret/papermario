.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241374
/* A65404 80241374 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A65408 80241378 AFB10014 */  sw        $s1, 0x14($sp)
/* A6540C 8024137C 0080882D */  daddu     $s1, $a0, $zero
/* A65410 80241380 AFBF0018 */  sw        $ra, 0x18($sp)
/* A65414 80241384 AFB00010 */  sw        $s0, 0x10($sp)
/* A65418 80241388 8E300148 */  lw        $s0, 0x148($s1)
/* A6541C 8024138C 0C00EABB */  jal       get_npc_unsafe
/* A65420 80241390 86040008 */   lh       $a0, 8($s0)
/* A65424 80241394 0040182D */  daddu     $v1, $v0, $zero
/* A65428 80241398 240200FF */  addiu     $v0, $zero, 0xff
/* A6542C 8024139C A06200AC */  sb        $v0, 0xac($v1)
/* A65430 802413A0 8E0200CC */  lw        $v0, 0xcc($s0)
/* A65434 802413A4 8C440008 */  lw        $a0, 8($v0)
/* A65438 802413A8 A460008E */  sh        $zero, 0x8e($v1)
/* A6543C 802413AC AC640028 */  sw        $a0, 0x28($v1)
/* A65440 802413B0 AE200070 */  sw        $zero, 0x70($s1)
/* A65444 802413B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A65448 802413B8 8FB10014 */  lw        $s1, 0x14($sp)
/* A6544C 802413BC 8FB00010 */  lw        $s0, 0x10($sp)
/* A65450 802413C0 24020002 */  addiu     $v0, $zero, 2
/* A65454 802413C4 03E00008 */  jr        $ra
/* A65458 802413C8 27BD0020 */   addiu    $sp, $sp, 0x20
