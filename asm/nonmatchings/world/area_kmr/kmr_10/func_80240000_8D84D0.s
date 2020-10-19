.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8D84D0
/* 8D84D0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8D84D4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D84D8 80240008 3C108024 */  lui       $s0, 0x8024
/* 8D84DC 8024000C 26100C20 */  addiu     $s0, $s0, 0xc20
/* 8D84E0 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8D84E4 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* 8D84E8 80240018 8E020000 */  lw        $v0, ($s0)
/* 8D84EC 8024001C 14400010 */  bnez      $v0, .L80240060
/* 8D84F0 80240020 0080882D */   daddu    $s1, $a0, $zero
/* 8D84F4 80240024 0C00AB39 */  jal       heap_malloc
/* 8D84F8 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* 8D84FC 8024002C AE020000 */  sw        $v0, ($s0)
/* 8D8500 80240030 0000182D */  daddu     $v1, $zero, $zero
/* 8D8504 80240034 0040282D */  daddu     $a1, $v0, $zero
/* 8D8508 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* 8D850C 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* 8D8510 80240040 24840004 */  addiu     $a0, $a0, 4
/* 8D8514 80240044 24630001 */  addiu     $v1, $v1, 1
/* 8D8518 80240048 ACA20000 */  sw        $v0, ($a1)
/* 8D851C 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* 8D8520 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* 8D8524 80240054 24A50004 */   addiu    $a1, $a1, 4
/* 8D8528 80240058 08090027 */  j         .L8024009C
/* 8D852C 8024005C 00000000 */   nop      
.L80240060:
/* 8D8530 80240060 0000182D */  daddu     $v1, $zero, $zero
/* 8D8534 80240064 0040282D */  daddu     $a1, $v0, $zero
/* 8D8538 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* 8D853C 8024006C 8CA20000 */  lw        $v0, ($a1)
/* 8D8540 80240070 24A50004 */  addiu     $a1, $a1, 4
/* 8D8544 80240074 24630001 */  addiu     $v1, $v1, 1
/* 8D8548 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* 8D854C 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* 8D8550 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* 8D8554 80240084 24840004 */   addiu    $a0, $a0, 4
/* 8D8558 80240088 3C108024 */  lui       $s0, 0x8024
/* 8D855C 8024008C 26100C20 */  addiu     $s0, $s0, 0xc20
/* 8D8560 80240090 0C00AB4B */  jal       heap_free
/* 8D8564 80240094 8E040000 */   lw       $a0, ($s0)
/* 8D8568 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* 8D856C 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8D8570 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D8574 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D8578 802400A8 24020002 */  addiu     $v0, $zero, 2
/* 8D857C 802400AC 03E00008 */  jr        $ra
/* 8D8580 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
