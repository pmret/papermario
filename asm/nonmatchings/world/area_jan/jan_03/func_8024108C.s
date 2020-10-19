.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024108C
/* B35C5C 8024108C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B35C60 80241090 AFB10014 */  sw        $s1, 0x14($sp)
/* B35C64 80241094 0080882D */  daddu     $s1, $a0, $zero
/* B35C68 80241098 AFBF0018 */  sw        $ra, 0x18($sp)
/* B35C6C 8024109C AFB00010 */  sw        $s0, 0x10($sp)
/* B35C70 802410A0 8E300148 */  lw        $s0, 0x148($s1)
/* B35C74 802410A4 0C00EABB */  jal       get_npc_unsafe
/* B35C78 802410A8 86040008 */   lh       $a0, 8($s0)
/* B35C7C 802410AC 9443008E */  lhu       $v1, 0x8e($v0)
/* B35C80 802410B0 2463FFFF */  addiu     $v1, $v1, -1
/* B35C84 802410B4 A443008E */  sh        $v1, 0x8e($v0)
/* B35C88 802410B8 00031C00 */  sll       $v1, $v1, 0x10
/* B35C8C 802410BC 14600008 */  bnez      $v1, .L802410E0
/* B35C90 802410C0 00000000 */   nop      
/* B35C94 802410C4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* B35C98 802410C8 30420080 */  andi      $v0, $v0, 0x80
/* B35C9C 802410CC 10400003 */  beqz      $v0, .L802410DC
/* B35CA0 802410D0 2402000F */   addiu    $v0, $zero, 0xf
/* B35CA4 802410D4 08090438 */  j         .L802410E0
/* B35CA8 802410D8 AE220070 */   sw       $v0, 0x70($s1)
.L802410DC:
/* B35CAC 802410DC AE200070 */  sw        $zero, 0x70($s1)
.L802410E0:
/* B35CB0 802410E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B35CB4 802410E4 8FB10014 */  lw        $s1, 0x14($sp)
/* B35CB8 802410E8 8FB00010 */  lw        $s0, 0x10($sp)
/* B35CBC 802410EC 03E00008 */  jr        $ra
/* B35CC0 802410F0 27BD0020 */   addiu    $sp, $sp, 0x20
