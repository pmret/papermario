.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9864E0
/* 9864E0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9864E4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* 9864E8 80240008 3C108024 */  lui       $s0, %hi(func_802406F0_92A9A0)
/* 9864EC 8024000C 261006F0 */  addiu     $s0, $s0, %lo(func_802406F0_92A9A0)
/* 9864F0 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9864F4 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* 9864F8 80240018 8E020000 */  lw        $v0, ($s0)
/* 9864FC 8024001C 14400010 */  bnez      $v0, .L80240060
/* 986500 80240020 0080882D */   daddu    $s1, $a0, $zero
/* 986504 80240024 0C00AB39 */  jal       heap_malloc
/* 986508 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* 98650C 8024002C AE020000 */  sw        $v0, ($s0)
/* 986510 80240030 0000182D */  daddu     $v1, $zero, $zero
/* 986514 80240034 0040282D */  daddu     $a1, $v0, $zero
/* 986518 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* 98651C 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* 986520 80240040 24840004 */  addiu     $a0, $a0, 4
/* 986524 80240044 24630001 */  addiu     $v1, $v1, 1
/* 986528 80240048 ACA20000 */  sw        $v0, ($a1)
/* 98652C 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* 986530 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* 986534 80240054 24A50004 */   addiu    $a1, $a1, 4
/* 986538 80240058 08090027 */  j         .L8024009C
/* 98653C 8024005C 00000000 */   nop
.L80240060:
/* 986540 80240060 0000182D */  daddu     $v1, $zero, $zero
/* 986544 80240064 0040282D */  daddu     $a1, $v0, $zero
/* 986548 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* 98654C 8024006C 8CA20000 */  lw        $v0, ($a1)
/* 986550 80240070 24A50004 */  addiu     $a1, $a1, 4
/* 986554 80240074 24630001 */  addiu     $v1, $v1, 1
/* 986558 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* 98655C 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* 986560 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* 986564 80240084 24840004 */   addiu    $a0, $a0, 4
/* 986568 80240088 3C108024 */  lui       $s0, %hi(func_802406F0_92A9A0)
/* 98656C 8024008C 261006F0 */  addiu     $s0, $s0, %lo(func_802406F0_92A9A0)
/* 986570 80240090 0C00AB4B */  jal       heap_free
/* 986574 80240094 8E040000 */   lw       $a0, ($s0)
/* 986578 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* 98657C 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 986580 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 986584 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 986588 802400A8 24020002 */  addiu     $v0, $zero, 2
/* 98658C 802400AC 03E00008 */  jr        $ra
/* 986590 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
