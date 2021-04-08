.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_04_UnkFunc18
/* C684A8 80240378 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C684AC 8024037C AFB00010 */  sw        $s0, 0x10($sp)
/* C684B0 80240380 0080802D */  daddu     $s0, $a0, $zero
/* C684B4 80240384 AFBF0018 */  sw        $ra, 0x18($sp)
/* C684B8 80240388 AFB10014 */  sw        $s1, 0x14($sp)
/* C684BC 8024038C 8E11000C */  lw        $s1, 0xc($s0)
/* C684C0 80240390 8E250000 */  lw        $a1, ($s1)
/* C684C4 80240394 0C0B1EAF */  jal       get_variable
/* C684C8 80240398 26310004 */   addiu    $s1, $s1, 4
/* C684CC 8024039C 0200202D */  daddu     $a0, $s0, $zero
/* C684D0 802403A0 3C038011 */  lui       $v1, %hi(gPlayerData)
/* C684D4 802403A4 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* C684D8 802403A8 000210C0 */  sll       $v0, $v0, 3
/* C684DC 802403AC 00431021 */  addu      $v0, $v0, $v1
/* C684E0 802403B0 90460015 */  lbu       $a2, 0x15($v0)
/* C684E4 802403B4 8E250000 */  lw        $a1, ($s1)
/* C684E8 802403B8 24C60001 */  addiu     $a2, $a2, 1
/* C684EC 802403BC A0460015 */  sb        $a2, 0x15($v0)
/* C684F0 802403C0 00063600 */  sll       $a2, $a2, 0x18
/* C684F4 802403C4 0C0B2026 */  jal       set_variable
/* C684F8 802403C8 00063603 */   sra      $a2, $a2, 0x18
/* C684FC 802403CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C68500 802403D0 8FB10014 */  lw        $s1, 0x14($sp)
/* C68504 802403D4 8FB00010 */  lw        $s0, 0x10($sp)
/* C68508 802403D8 24020002 */  addiu     $v0, $zero, 2
/* C6850C 802403DC 03E00008 */  jr        $ra
/* C68510 802403E0 27BD0020 */   addiu    $sp, $sp, 0x20
