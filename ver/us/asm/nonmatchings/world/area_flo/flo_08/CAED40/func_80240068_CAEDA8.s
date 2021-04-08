.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_08_UnkFunc18
/* CAEDA8 80240068 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAEDAC 8024006C AFB00010 */  sw        $s0, 0x10($sp)
/* CAEDB0 80240070 0080802D */  daddu     $s0, $a0, $zero
/* CAEDB4 80240074 AFBF0018 */  sw        $ra, 0x18($sp)
/* CAEDB8 80240078 AFB10014 */  sw        $s1, 0x14($sp)
/* CAEDBC 8024007C 8E11000C */  lw        $s1, 0xc($s0)
/* CAEDC0 80240080 8E250000 */  lw        $a1, ($s1)
/* CAEDC4 80240084 0C0B1EAF */  jal       get_variable
/* CAEDC8 80240088 26310004 */   addiu    $s1, $s1, 4
/* CAEDCC 8024008C 0200202D */  daddu     $a0, $s0, $zero
/* CAEDD0 80240090 3C038011 */  lui       $v1, %hi(gPlayerData)
/* CAEDD4 80240094 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* CAEDD8 80240098 000210C0 */  sll       $v0, $v0, 3
/* CAEDDC 8024009C 00431021 */  addu      $v0, $v0, $v1
/* CAEDE0 802400A0 90460015 */  lbu       $a2, 0x15($v0)
/* CAEDE4 802400A4 8E250000 */  lw        $a1, ($s1)
/* CAEDE8 802400A8 24C60001 */  addiu     $a2, $a2, 1
/* CAEDEC 802400AC A0460015 */  sb        $a2, 0x15($v0)
/* CAEDF0 802400B0 00063600 */  sll       $a2, $a2, 0x18
/* CAEDF4 802400B4 0C0B2026 */  jal       set_variable
/* CAEDF8 802400B8 00063603 */   sra      $a2, $a2, 0x18
/* CAEDFC 802400BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAEE00 802400C0 8FB10014 */  lw        $s1, 0x14($sp)
/* CAEE04 802400C4 8FB00010 */  lw        $s0, 0x10($sp)
/* CAEE08 802400C8 24020002 */  addiu     $v0, $zero, 2
/* CAEE0C 802400CC 03E00008 */  jr        $ra
/* CAEE10 802400D0 27BD0020 */   addiu    $sp, $sp, 0x20
