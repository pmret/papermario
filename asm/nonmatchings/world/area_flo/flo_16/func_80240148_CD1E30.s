.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240148_CD1F78
/* CD1F78 80240148 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD1F7C 8024014C AFB00010 */  sw        $s0, 0x10($sp)
/* CD1F80 80240150 0080802D */  daddu     $s0, $a0, $zero
/* CD1F84 80240154 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD1F88 80240158 AFB10014 */  sw        $s1, 0x14($sp)
/* CD1F8C 8024015C 8E11000C */  lw        $s1, 0xc($s0)
/* CD1F90 80240160 8E250000 */  lw        $a1, ($s1)
/* CD1F94 80240164 0C0B1EAF */  jal       get_variable
/* CD1F98 80240168 26310004 */   addiu    $s1, $s1, 4
/* CD1F9C 8024016C 0200202D */  daddu     $a0, $s0, $zero
/* CD1FA0 80240170 3C038011 */  lui       $v1, %hi(gPlayerData)
/* CD1FA4 80240174 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* CD1FA8 80240178 000210C0 */  sll       $v0, $v0, 3
/* CD1FAC 8024017C 00431021 */  addu      $v0, $v0, $v1
/* CD1FB0 80240180 90460015 */  lbu       $a2, 0x15($v0)
/* CD1FB4 80240184 8E250000 */  lw        $a1, ($s1)
/* CD1FB8 80240188 24C60001 */  addiu     $a2, $a2, 1
/* CD1FBC 8024018C A0460015 */  sb        $a2, 0x15($v0)
/* CD1FC0 80240190 00063600 */  sll       $a2, $a2, 0x18
/* CD1FC4 80240194 0C0B2026 */  jal       set_variable
/* CD1FC8 80240198 00063603 */   sra      $a2, $a2, 0x18
/* CD1FCC 8024019C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD1FD0 802401A0 8FB10014 */  lw        $s1, 0x14($sp)
/* CD1FD4 802401A4 8FB00010 */  lw        $s0, 0x10($sp)
/* CD1FD8 802401A8 24020002 */  addiu     $v0, $zero, 2
/* CD1FDC 802401AC 03E00008 */  jr        $ra
/* CD1FE0 802401B0 27BD0020 */   addiu    $sp, $sp, 0x20
