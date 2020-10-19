.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AEC
/* 80236C 80241AEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 802370 80241AF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 802374 80241AF4 0080882D */  daddu     $s1, $a0, $zero
/* 802378 80241AF8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 80237C 80241AFC AFB00010 */  sw        $s0, 0x10($sp)
/* 802380 80241B00 8E300148 */  lw        $s0, 0x148($s1)
/* 802384 80241B04 0C00EABB */  jal       get_npc_unsafe
/* 802388 80241B08 86040008 */   lh       $a0, 8($s0)
/* 80238C 80241B0C 9443008E */  lhu       $v1, 0x8e($v0)
/* 802390 80241B10 2463FFFF */  addiu     $v1, $v1, -1
/* 802394 80241B14 A443008E */  sh        $v1, 0x8e($v0)
/* 802398 80241B18 00031C00 */  sll       $v1, $v1, 0x10
/* 80239C 80241B1C 14600008 */  bnez      $v1, .L80241B40
/* 8023A0 80241B20 00000000 */   nop      
/* 8023A4 80241B24 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 8023A8 80241B28 30420080 */  andi      $v0, $v0, 0x80
/* 8023AC 80241B2C 10400003 */  beqz      $v0, .L80241B3C
/* 8023B0 80241B30 2402000F */   addiu    $v0, $zero, 0xf
/* 8023B4 80241B34 080906D0 */  j         .L80241B40
/* 8023B8 80241B38 AE220070 */   sw       $v0, 0x70($s1)
.L80241B3C:
/* 8023BC 80241B3C AE200070 */  sw        $zero, 0x70($s1)
.L80241B40:
/* 8023C0 80241B40 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8023C4 80241B44 8FB10014 */  lw        $s1, 0x14($sp)
/* 8023C8 80241B48 8FB00010 */  lw        $s0, 0x10($sp)
/* 8023CC 80241B4C 03E00008 */  jr        $ra
/* 8023D0 80241B50 27BD0020 */   addiu    $sp, $sp, 0x20
