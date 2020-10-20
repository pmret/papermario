.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241364_BE00F4
/* BE00F4 80241364 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE00F8 80241368 AFB00010 */  sw        $s0, 0x10($sp)
/* BE00FC 8024136C 0080802D */  daddu     $s0, $a0, $zero
/* BE0100 80241370 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE0104 80241374 AFB10014 */  sw        $s1, 0x14($sp)
/* BE0108 80241378 8E02000C */  lw        $v0, 0xc($s0)
/* BE010C 8024137C 8C510000 */  lw        $s1, ($v0)
/* BE0110 80241380 0C0B1EAF */  jal       get_variable
/* BE0114 80241384 0220282D */   daddu    $a1, $s1, $zero
/* BE0118 80241388 3C03FFF0 */  lui       $v1, 0xfff0
/* BE011C 8024138C 3463FFFF */  ori       $v1, $v1, 0xffff
/* BE0120 80241390 0200202D */  daddu     $a0, $s0, $zero
/* BE0124 80241394 00431024 */  and       $v0, $v0, $v1
/* BE0128 80241398 00021140 */  sll       $v0, $v0, 5
/* BE012C 8024139C 3C068008 */  lui       $a2, %hi(gItemTable)
/* BE0130 802413A0 00C23021 */  addu      $a2, $a2, $v0
/* BE0134 802413A4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* BE0138 802413A8 0C0B2026 */  jal       set_variable
/* BE013C 802413AC 0220282D */   daddu    $a1, $s1, $zero
/* BE0140 802413B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE0144 802413B4 8FB10014 */  lw        $s1, 0x14($sp)
/* BE0148 802413B8 8FB00010 */  lw        $s0, 0x10($sp)
/* BE014C 802413BC 24020002 */  addiu     $v0, $zero, 2
/* BE0150 802413C0 03E00008 */  jr        $ra
/* BE0154 802413C4 27BD0020 */   addiu    $sp, $sp, 0x20
