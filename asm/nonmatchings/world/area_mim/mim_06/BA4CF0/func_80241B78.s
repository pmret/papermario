.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B78
/* BA62F8 80241B78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA62FC 80241B7C AFB10014 */  sw        $s1, 0x14($sp)
/* BA6300 80241B80 0080882D */  daddu     $s1, $a0, $zero
/* BA6304 80241B84 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA6308 80241B88 AFB00010 */  sw        $s0, 0x10($sp)
/* BA630C 80241B8C 8E300148 */  lw        $s0, 0x148($s1)
/* BA6310 80241B90 0C00EABB */  jal       get_npc_unsafe
/* BA6314 80241B94 86040008 */   lh       $a0, 8($s0)
/* BA6318 80241B98 0040182D */  daddu     $v1, $v0, $zero
/* BA631C 80241B9C 9462008E */  lhu       $v0, 0x8e($v1)
/* BA6320 80241BA0 2442FFFF */  addiu     $v0, $v0, -1
/* BA6324 80241BA4 A462008E */  sh        $v0, 0x8e($v1)
/* BA6328 80241BA8 00021400 */  sll       $v0, $v0, 0x10
/* BA632C 80241BAC 14400005 */  bnez      $v0, .L80241BC4
/* BA6330 80241BB0 00000000 */   nop      
/* BA6334 80241BB4 960200AA */  lhu       $v0, 0xaa($s0)
/* BA6338 80241BB8 A462008E */  sh        $v0, 0x8e($v1)
/* BA633C 80241BBC 2402000E */  addiu     $v0, $zero, 0xe
/* BA6340 80241BC0 AE220070 */  sw        $v0, 0x70($s1)
.L80241BC4:
/* BA6344 80241BC4 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA6348 80241BC8 8FB10014 */  lw        $s1, 0x14($sp)
/* BA634C 80241BCC 8FB00010 */  lw        $s0, 0x10($sp)
/* BA6350 80241BD0 03E00008 */  jr        $ra
/* BA6354 80241BD4 27BD0020 */   addiu    $sp, $sp, 0x20
