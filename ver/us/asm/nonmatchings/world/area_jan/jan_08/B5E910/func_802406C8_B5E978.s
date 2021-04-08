.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_08_UnkFunc18
/* B5E978 802406C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5E97C 802406CC AFB00010 */  sw        $s0, 0x10($sp)
/* B5E980 802406D0 0080802D */  daddu     $s0, $a0, $zero
/* B5E984 802406D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5E988 802406D8 AFB10014 */  sw        $s1, 0x14($sp)
/* B5E98C 802406DC 8E11000C */  lw        $s1, 0xc($s0)
/* B5E990 802406E0 8E250000 */  lw        $a1, ($s1)
/* B5E994 802406E4 0C0B1EAF */  jal       get_variable
/* B5E998 802406E8 26310004 */   addiu    $s1, $s1, 4
/* B5E99C 802406EC 0200202D */  daddu     $a0, $s0, $zero
/* B5E9A0 802406F0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* B5E9A4 802406F4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* B5E9A8 802406F8 000210C0 */  sll       $v0, $v0, 3
/* B5E9AC 802406FC 00431021 */  addu      $v0, $v0, $v1
/* B5E9B0 80240700 90460015 */  lbu       $a2, 0x15($v0)
/* B5E9B4 80240704 8E250000 */  lw        $a1, ($s1)
/* B5E9B8 80240708 24C60001 */  addiu     $a2, $a2, 1
/* B5E9BC 8024070C A0460015 */  sb        $a2, 0x15($v0)
/* B5E9C0 80240710 00063600 */  sll       $a2, $a2, 0x18
/* B5E9C4 80240714 0C0B2026 */  jal       set_variable
/* B5E9C8 80240718 00063603 */   sra      $a2, $a2, 0x18
/* B5E9CC 8024071C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5E9D0 80240720 8FB10014 */  lw        $s1, 0x14($sp)
/* B5E9D4 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* B5E9D8 80240728 24020002 */  addiu     $v0, $zero, 2
/* B5E9DC 8024072C 03E00008 */  jr        $ra
/* B5E9E0 80240730 27BD0020 */   addiu    $sp, $sp, 0x20
