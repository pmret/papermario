.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047F58
/* 23358 80047F58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2335C 80047F5C 00041040 */  sll       $v0, $a0, 1
/* 23360 80047F60 00441021 */  addu      $v0, $v0, $a0
/* 23364 80047F64 00021080 */  sll       $v0, $v0, 2
/* 23368 80047F68 00441023 */  subu      $v0, $v0, $a0
/* 2336C 80047F6C 3C03800A */  lui       $v1, 0x800a
/* 23370 80047F70 8C630F44 */  lw        $v1, 0xf44($v1)
/* 23374 80047F74 00021100 */  sll       $v0, $v0, 4
/* 23378 80047F78 AFBF0018 */  sw        $ra, 0x18($sp)
/* 2337C 80047F7C AFB10014 */  sw        $s1, 0x14($sp)
/* 23380 80047F80 AFB00010 */  sw        $s0, 0x10($sp)
/* 23384 80047F84 00628821 */  addu      $s1, $v1, $v0
/* 23388 80047F88 2403FDFF */  addiu     $v1, $zero, -0x201
/* 2338C 80047F8C 8E220000 */  lw        $v0, ($s1)
/* 23390 80047F90 82240098 */  lb        $a0, 0x98($s1)
/* 23394 80047F94 00431024 */  and       $v0, $v0, $v1
/* 23398 80047F98 1480000E */  bnez      $a0, .L80047FD4
/* 2339C 80047F9C AE220000 */   sw       $v0, ($s1)
/* 233A0 80047FA0 3C048010 */  lui       $a0, 0x8010
/* 233A4 80047FA4 2484760C */  addiu     $a0, $a0, 0x760c
/* 233A8 80047FA8 24020001 */  addiu     $v0, $zero, 1
/* 233AC 80047FAC 0C050529 */  jal       create_icon
/* 233B0 80047FB0 A2220098 */   sb       $v0, 0x98($s1)
/* 233B4 80047FB4 0040802D */  daddu     $s0, $v0, $zero
/* 233B8 80047FB8 0200202D */  daddu     $a0, $s0, $zero
/* 233BC 80047FBC 0C051280 */  jal       set_icon_flags
/* 233C0 80047FC0 24050002 */   addiu    $a1, $zero, 2
/* 233C4 80047FC4 0200202D */  daddu     $a0, $s0, $zero
/* 233C8 80047FC8 0C051280 */  jal       set_icon_flags
/* 233CC 80047FCC 24050080 */   addiu    $a1, $zero, 0x80
/* 233D0 80047FD0 AE30009C */  sw        $s0, 0x9c($s1)
.L80047FD4:
/* 233D4 80047FD4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 233D8 80047FD8 8FB10014 */  lw        $s1, 0x14($sp)
/* 233DC 80047FDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 233E0 80047FE0 03E00008 */  jr        $ra
/* 233E4 80047FE4 27BD0020 */   addiu    $sp, $sp, 0x20
