.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_npc_animation
/* F24BC 802CDB0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F24C0 802CDB10 AFB10014 */  sw        $s1, 0x14($sp)
/* F24C4 802CDB14 0080882D */  daddu     $s1, $a0, $zero
/* F24C8 802CDB18 AFB00010 */  sw        $s0, 0x10($sp)
/* F24CC 802CDB1C 00A0802D */  daddu     $s0, $a1, $zero
/* F24D0 802CDB20 2604FEFF */  addiu     $a0, $s0, -0x101
/* F24D4 802CDB24 2C820009 */  sltiu     $v0, $a0, 9
/* F24D8 802CDB28 1040000D */  beqz      $v0, .L802CDB60
/* F24DC 802CDB2C AFBF0018 */   sw       $ra, 0x18($sp)
/* F24E0 802CDB30 3C028011 */  lui       $v0, %hi(gPlayerData)
/* F24E4 802CDB34 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* F24E8 802CDB38 80430012 */  lb        $v1, 0x12($v0)
/* F24EC 802CDB3C 000310C0 */  sll       $v0, $v1, 3
/* F24F0 802CDB40 00431021 */  addu      $v0, $v0, $v1
/* F24F4 802CDB44 00441021 */  addu      $v0, $v0, $a0
/* F24F8 802CDB48 00021080 */  sll       $v0, $v0, 2
/* F24FC 802CDB4C 3C018010 */  lui       $at, %hi(gPartnerAnimations)
/* F2500 802CDB50 00220821 */  addu      $at, $at, $v0
/* F2504 802CDB54 8C228348 */  lw        $v0, %lo(gPartnerAnimations)($at)
/* F2508 802CDB58 080B36E4 */  j         .L802CDB90
/* F250C 802CDB5C AE220028 */   sw       $v0, 0x28($s1)
.L802CDB60:
/* F2510 802CDB60 2602FDFF */  addiu     $v0, $s0, -0x201
/* F2514 802CDB64 2C420010 */  sltiu     $v0, $v0, 0x10
/* F2518 802CDB68 50400009 */  beql      $v0, $zero, .L802CDB90
/* F251C 802CDB6C AE300028 */   sw       $s0, 0x28($s1)
/* F2520 802CDB70 822400A4 */  lb        $a0, 0xa4($s1)
/* F2524 802CDB74 0C00FB3A */  jal       get_enemy
/* F2528 802CDB78 00000000 */   nop      
/* F252C 802CDB7C 8C4200CC */  lw        $v0, 0xcc($v0)
/* F2530 802CDB80 00101880 */  sll       $v1, $s0, 2
/* F2534 802CDB84 00621821 */  addu      $v1, $v1, $v0
/* F2538 802CDB88 8C62F7FC */  lw        $v0, -0x804($v1)
/* F253C 802CDB8C AE220028 */  sw        $v0, 0x28($s1)
.L802CDB90:
/* F2540 802CDB90 8FBF0018 */  lw        $ra, 0x18($sp)
/* F2544 802CDB94 8FB10014 */  lw        $s1, 0x14($sp)
/* F2548 802CDB98 8FB00010 */  lw        $s0, 0x10($sp)
/* F254C 802CDB9C 03E00008 */  jr        $ra
/* F2550 802CDBA0 27BD0020 */   addiu    $sp, $sp, 0x20
