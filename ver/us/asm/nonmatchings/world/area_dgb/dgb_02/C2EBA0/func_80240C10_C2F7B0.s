.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C10_C2F7B0
/* C2F7B0 80240C10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C2F7B4 80240C14 AFB10014 */  sw        $s1, 0x14($sp)
/* C2F7B8 80240C18 0080882D */  daddu     $s1, $a0, $zero
/* C2F7BC 80240C1C AFBF0018 */  sw        $ra, 0x18($sp)
/* C2F7C0 80240C20 AFB00010 */  sw        $s0, 0x10($sp)
/* C2F7C4 80240C24 8E300148 */  lw        $s0, 0x148($s1)
/* C2F7C8 80240C28 0C00EABB */  jal       get_npc_unsafe
/* C2F7CC 80240C2C 86040008 */   lh       $a0, 8($s0)
/* C2F7D0 80240C30 0040182D */  daddu     $v1, $v0, $zero
/* C2F7D4 80240C34 9462008E */  lhu       $v0, 0x8e($v1)
/* C2F7D8 80240C38 2442FFFF */  addiu     $v0, $v0, -1
/* C2F7DC 80240C3C A462008E */  sh        $v0, 0x8e($v1)
/* C2F7E0 80240C40 00021400 */  sll       $v0, $v0, 0x10
/* C2F7E4 80240C44 1C400006 */  bgtz      $v0, .L80240C60
/* C2F7E8 80240C48 24020001 */   addiu    $v0, $zero, 1
/* C2F7EC 80240C4C A462008E */  sh        $v0, 0x8e($v1)
/* C2F7F0 80240C50 24020028 */  addiu     $v0, $zero, 0x28
/* C2F7F4 80240C54 AE020088 */  sw        $v0, 0x88($s0)
/* C2F7F8 80240C58 24020003 */  addiu     $v0, $zero, 3
/* C2F7FC 80240C5C AE220070 */  sw        $v0, 0x70($s1)
.L80240C60:
/* C2F800 80240C60 8FBF0018 */  lw        $ra, 0x18($sp)
/* C2F804 80240C64 8FB10014 */  lw        $s1, 0x14($sp)
/* C2F808 80240C68 8FB00010 */  lw        $s0, 0x10($sp)
/* C2F80C 80240C6C 03E00008 */  jr        $ra
/* C2F810 80240C70 27BD0020 */   addiu    $sp, $sp, 0x20
