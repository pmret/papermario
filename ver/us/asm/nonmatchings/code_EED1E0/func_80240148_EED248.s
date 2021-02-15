.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240148_EED248
/* EED248 80240148 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EED24C 8024014C AFB00010 */  sw        $s0, 0x10($sp)
/* EED250 80240150 0080802D */  daddu     $s0, $a0, $zero
/* EED254 80240154 AFBF0018 */  sw        $ra, 0x18($sp)
/* EED258 80240158 AFB10014 */  sw        $s1, 0x14($sp)
/* EED25C 8024015C 8E11000C */  lw        $s1, 0xc($s0)
/* EED260 80240160 8E250000 */  lw        $a1, ($s1)
/* EED264 80240164 0C0B53A3 */  jal       func_802D4E8C
/* EED268 80240168 26310004 */   addiu    $s1, $s1, 4
/* EED26C 8024016C 0200202D */  daddu     $a0, $s0, $zero
/* EED270 80240170 3C038011 */  lui       $v1, %hi(D_80117840)
/* EED274 80240174 24637840 */  addiu     $v1, $v1, %lo(D_80117840)
/* EED278 80240178 000210C0 */  sll       $v0, $v0, 3
/* EED27C 8024017C 00431021 */  addu      $v0, $v0, $v1
/* EED280 80240180 90460015 */  lbu       $a2, 0x15($v0)
/* EED284 80240184 8E250000 */  lw        $a1, ($s1)
/* EED288 80240188 24C60001 */  addiu     $a2, $a2, 1
/* EED28C 8024018C A0460015 */  sb        $a2, 0x15($v0)
/* EED290 80240190 00063600 */  sll       $a2, $a2, 0x18
/* EED294 80240194 0C0B551A */  jal       func_802D5468
/* EED298 80240198 00063603 */   sra      $a2, $a2, 0x18
/* EED29C 8024019C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EED2A0 802401A0 8FB10014 */  lw        $s1, 0x14($sp)
/* EED2A4 802401A4 8FB00010 */  lw        $s0, 0x10($sp)
/* EED2A8 802401A8 24020002 */  addiu     $v0, $zero, 2
/* EED2AC 802401AC 03E00008 */  jr        $ra
/* EED2B0 802401B0 27BD0020 */   addiu    $sp, $sp, 0x20
