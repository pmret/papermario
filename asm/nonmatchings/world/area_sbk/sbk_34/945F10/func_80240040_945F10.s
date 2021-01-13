.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_945F10
/* 945F10 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 945F14 80240044 AFB00010 */  sw        $s0, 0x10($sp)
/* 945F18 80240048 3C108024 */  lui       $s0, %hi(D_80240D9C)
/* 945F1C 8024004C 26100D9C */  addiu     $s0, $s0, %lo(D_80240D9C)
/* 945F20 80240050 AFBF0018 */  sw        $ra, 0x18($sp)
/* 945F24 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* 945F28 80240058 8E020000 */  lw        $v0, ($s0)
/* 945F2C 8024005C 14400010 */  bnez      $v0, .L802400A0
/* 945F30 80240060 0080882D */   daddu    $s1, $a0, $zero
/* 945F34 80240064 0C00AB39 */  jal       heap_malloc
/* 945F38 80240068 24040040 */   addiu    $a0, $zero, 0x40
/* 945F3C 8024006C AE020000 */  sw        $v0, ($s0)
/* 945F40 80240070 0000182D */  daddu     $v1, $zero, $zero
/* 945F44 80240074 0040282D */  daddu     $a1, $v0, $zero
/* 945F48 80240078 0220202D */  daddu     $a0, $s1, $zero
.L8024007C:
/* 945F4C 8024007C 8C820084 */  lw        $v0, 0x84($a0)
/* 945F50 80240080 24840004 */  addiu     $a0, $a0, 4
/* 945F54 80240084 24630001 */  addiu     $v1, $v1, 1
/* 945F58 80240088 ACA20000 */  sw        $v0, ($a1)
/* 945F5C 8024008C 28620010 */  slti      $v0, $v1, 0x10
/* 945F60 80240090 1440FFFA */  bnez      $v0, .L8024007C
/* 945F64 80240094 24A50004 */   addiu    $a1, $a1, 4
/* 945F68 80240098 08090037 */  j         .L802400DC
/* 945F6C 8024009C 00000000 */   nop
.L802400A0:
/* 945F70 802400A0 0000182D */  daddu     $v1, $zero, $zero
/* 945F74 802400A4 0040282D */  daddu     $a1, $v0, $zero
/* 945F78 802400A8 0220202D */  daddu     $a0, $s1, $zero
.L802400AC:
/* 945F7C 802400AC 8CA20000 */  lw        $v0, ($a1)
/* 945F80 802400B0 24A50004 */  addiu     $a1, $a1, 4
/* 945F84 802400B4 24630001 */  addiu     $v1, $v1, 1
/* 945F88 802400B8 AC820084 */  sw        $v0, 0x84($a0)
/* 945F8C 802400BC 28620010 */  slti      $v0, $v1, 0x10
/* 945F90 802400C0 1440FFFA */  bnez      $v0, .L802400AC
/* 945F94 802400C4 24840004 */   addiu    $a0, $a0, 4
/* 945F98 802400C8 3C108024 */  lui       $s0, %hi(D_80240D9C)
/* 945F9C 802400CC 26100D9C */  addiu     $s0, $s0, %lo(D_80240D9C)
/* 945FA0 802400D0 0C00AB4B */  jal       heap_free
/* 945FA4 802400D4 8E040000 */   lw       $a0, ($s0)
/* 945FA8 802400D8 AE000000 */  sw        $zero, ($s0)
.L802400DC:
/* 945FAC 802400DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 945FB0 802400E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 945FB4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 945FB8 802400E8 24020002 */  addiu     $v0, $zero, 2
/* 945FBC 802400EC 03E00008 */  jr        $ra
/* 945FC0 802400F0 27BD0020 */   addiu    $sp, $sp, 0x20
