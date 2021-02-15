.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DD89C
/* 10098C 802DD89C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 100990 802DD8A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 100994 802DD8A4 2490FFFF */  addiu     $s0, $a0, -1
/* 100998 802DD8A8 0200202D */  daddu     $a0, $s0, $zero
/* 10099C 802DD8AC 24050001 */  addiu     $a1, $zero, 1
/* 1009A0 802DD8B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1009A4 802DD8B4 0C0B7AC3 */  jal       load_sprite
/* 1009A8 802DD8B8 0000302D */   daddu    $a2, $zero, $zero
/* 1009AC 802DD8BC 00108080 */  sll       $s0, $s0, 2
/* 1009B0 802DD8C0 3C04802E */  lui       $a0, %hi(D_802DF580)
/* 1009B4 802DD8C4 2484F580 */  addiu     $a0, $a0, %lo(D_802DF580)
/* 1009B8 802DD8C8 3C01802E */  lui       $at, %hi(D_802DF548)
/* 1009BC 802DD8CC 00300821 */  addu      $at, $at, $s0
/* 1009C0 802DD8D0 AC22F548 */  sw        $v0, %lo(D_802DF548)($at)
/* 1009C4 802DD8D4 8C830000 */  lw        $v1, ($a0)
/* 1009C8 802DD8D8 8C420008 */  lw        $v0, 8($v0)
/* 1009CC 802DD8DC 0062182A */  slt       $v1, $v1, $v0
/* 1009D0 802DD8E0 54600001 */  bnel      $v1, $zero, .L802DD8E8
/* 1009D4 802DD8E4 AC820000 */   sw       $v0, ($a0)
.L802DD8E8:
/* 1009D8 802DD8E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1009DC 802DD8EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1009E0 802DD8F0 03E00008 */  jr        $ra
/* 1009E4 802DD8F4 27BD0018 */   addiu    $sp, $sp, 0x18
