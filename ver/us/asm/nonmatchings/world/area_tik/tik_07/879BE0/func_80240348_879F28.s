.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_07_UnkFunc18
/* 879F28 80240348 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 879F2C 8024034C AFB00010 */  sw        $s0, 0x10($sp)
/* 879F30 80240350 0080802D */  daddu     $s0, $a0, $zero
/* 879F34 80240354 AFBF0018 */  sw        $ra, 0x18($sp)
/* 879F38 80240358 AFB10014 */  sw        $s1, 0x14($sp)
/* 879F3C 8024035C 8E11000C */  lw        $s1, 0xc($s0)
/* 879F40 80240360 8E250000 */  lw        $a1, ($s1)
/* 879F44 80240364 0C0B1EAF */  jal       get_variable
/* 879F48 80240368 26310004 */   addiu    $s1, $s1, 4
/* 879F4C 8024036C 0200202D */  daddu     $a0, $s0, $zero
/* 879F50 80240370 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 879F54 80240374 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 879F58 80240378 000210C0 */  sll       $v0, $v0, 3
/* 879F5C 8024037C 00431021 */  addu      $v0, $v0, $v1
/* 879F60 80240380 90460015 */  lbu       $a2, 0x15($v0)
/* 879F64 80240384 8E250000 */  lw        $a1, ($s1)
/* 879F68 80240388 24C60001 */  addiu     $a2, $a2, 1
/* 879F6C 8024038C A0460015 */  sb        $a2, 0x15($v0)
/* 879F70 80240390 00063600 */  sll       $a2, $a2, 0x18
/* 879F74 80240394 0C0B2026 */  jal       set_variable
/* 879F78 80240398 00063603 */   sra      $a2, $a2, 0x18
/* 879F7C 8024039C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 879F80 802403A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 879F84 802403A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 879F88 802403A8 24020002 */  addiu     $v0, $zero, 2
/* 879F8C 802403AC 03E00008 */  jr        $ra
/* 879F90 802403B0 27BD0020 */   addiu    $sp, $sp, 0x20
