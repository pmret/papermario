.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CF0_9113A0
/* 9113A0 80241CF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9113A4 80241CF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9113A8 80241CF8 0080882D */  daddu     $s1, $a0, $zero
/* 9113AC 80241CFC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9113B0 80241D00 AFB00010 */  sw        $s0, 0x10($sp)
/* 9113B4 80241D04 8E300148 */  lw        $s0, 0x148($s1)
/* 9113B8 80241D08 0C00EABB */  jal       get_npc_unsafe
/* 9113BC 80241D0C 86040008 */   lh       $a0, 8($s0)
/* 9113C0 80241D10 0040202D */  daddu     $a0, $v0, $zero
/* 9113C4 80241D14 9482008E */  lhu       $v0, 0x8e($a0)
/* 9113C8 80241D18 24030003 */  addiu     $v1, $zero, 3
/* 9113CC 80241D1C 2442FFFF */  addiu     $v0, $v0, -1
/* 9113D0 80241D20 A482008E */  sh        $v0, 0x8e($a0)
/* 9113D4 80241D24 00021400 */  sll       $v0, $v0, 0x10
/* 9113D8 80241D28 00021403 */  sra       $v0, $v0, 0x10
/* 9113DC 80241D2C 14430004 */  bne       $v0, $v1, .L80241D40
/* 9113E0 80241D30 3C031F10 */   lui      $v1, 0x1f10
/* 9113E4 80241D34 8E020000 */  lw        $v0, ($s0)
/* 9113E8 80241D38 00431025 */  or        $v0, $v0, $v1
/* 9113EC 80241D3C AE020000 */  sw        $v0, ($s0)
.L80241D40:
/* 9113F0 80241D40 8482008E */  lh        $v0, 0x8e($a0)
/* 9113F4 80241D44 1C400005 */  bgtz      $v0, .L80241D5C
/* 9113F8 80241D48 00000000 */   nop      
/* 9113FC 80241D4C 8C820000 */  lw        $v0, ($a0)
/* 911400 80241D50 34420002 */  ori       $v0, $v0, 2
/* 911404 80241D54 AC820000 */  sw        $v0, ($a0)
/* 911408 80241D58 AE200070 */  sw        $zero, 0x70($s1)
.L80241D5C:
/* 91140C 80241D5C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 911410 80241D60 8FB10014 */  lw        $s1, 0x14($sp)
/* 911414 80241D64 8FB00010 */  lw        $s0, 0x10($sp)
/* 911418 80241D68 03E00008 */  jr        $ra
/* 91141C 80241D6C 27BD0020 */   addiu    $sp, $sp, 0x20
