.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240514
/* 8430E4 80240514 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8430E8 80240518 AFB00010 */  sw        $s0, 0x10($sp)
/* 8430EC 8024051C 0080802D */  daddu     $s0, $a0, $zero
/* 8430F0 80240520 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8430F4 80240524 AFB10014 */  sw        $s1, 0x14($sp)
/* 8430F8 80240528 8E02000C */  lw        $v0, 0xc($s0)
/* 8430FC 8024052C 8C510000 */  lw        $s1, ($v0)
/* 843100 80240530 0C0B1EAF */  jal       get_variable
/* 843104 80240534 0220282D */   daddu    $a1, $s1, $zero
/* 843108 80240538 3C03FFF0 */  lui       $v1, 0xfff0
/* 84310C 8024053C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 843110 80240540 0200202D */  daddu     $a0, $s0, $zero
/* 843114 80240544 00431024 */  and       $v0, $v0, $v1
/* 843118 80240548 00021140 */  sll       $v0, $v0, 5
/* 84311C 8024054C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 843120 80240550 00C23021 */  addu      $a2, $a2, $v0
/* 843124 80240554 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 843128 80240558 0C0B2026 */  jal       set_variable
/* 84312C 8024055C 0220282D */   daddu    $a1, $s1, $zero
/* 843130 80240560 8FBF0018 */  lw        $ra, 0x18($sp)
/* 843134 80240564 8FB10014 */  lw        $s1, 0x14($sp)
/* 843138 80240568 8FB00010 */  lw        $s0, 0x10($sp)
/* 84313C 8024056C 24020002 */  addiu     $v0, $zero, 2
/* 843140 80240570 03E00008 */  jr        $ra
/* 843144 80240574 27BD0020 */   addiu    $sp, $sp, 0x20
