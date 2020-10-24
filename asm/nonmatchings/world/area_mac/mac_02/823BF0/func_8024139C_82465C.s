.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024139C_82465C
/* 82465C 8024139C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 824660 802413A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 824664 802413A4 0080882D */  daddu     $s1, $a0, $zero
/* 824668 802413A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 82466C 802413AC AFB00010 */  sw        $s0, 0x10($sp)
/* 824670 802413B0 8E300148 */  lw        $s0, 0x148($s1)
/* 824674 802413B4 0C00EABB */  jal       get_npc_unsafe
/* 824678 802413B8 86040008 */   lh       $a0, 8($s0)
/* 82467C 802413BC 9443008E */  lhu       $v1, 0x8e($v0)
/* 824680 802413C0 2463FFFF */  addiu     $v1, $v1, -1
/* 824684 802413C4 A443008E */  sh        $v1, 0x8e($v0)
/* 824688 802413C8 00031C00 */  sll       $v1, $v1, 0x10
/* 82468C 802413CC 14600008 */  bnez      $v1, .L802413F0
/* 824690 802413D0 00000000 */   nop      
/* 824694 802413D4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 824698 802413D8 30420080 */  andi      $v0, $v0, 0x80
/* 82469C 802413DC 10400003 */  beqz      $v0, .L802413EC
/* 8246A0 802413E0 2402000F */   addiu    $v0, $zero, 0xf
/* 8246A4 802413E4 080904FC */  j         .L802413F0
/* 8246A8 802413E8 AE220070 */   sw       $v0, 0x70($s1)
.L802413EC:
/* 8246AC 802413EC AE200070 */  sw        $zero, 0x70($s1)
.L802413F0:
/* 8246B0 802413F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8246B4 802413F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8246B8 802413F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8246BC 802413FC 03E00008 */  jr        $ra
/* 8246C0 80241400 27BD0020 */   addiu    $sp, $sp, 0x20
