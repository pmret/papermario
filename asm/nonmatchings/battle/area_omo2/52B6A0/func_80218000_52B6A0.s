.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_52B6A0
/* 52B6A0 80218000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 52B6A4 80218004 AFB00010 */  sw        $s0, 0x10($sp)
/* 52B6A8 80218008 0080802D */  daddu     $s0, $a0, $zero
/* 52B6AC 8021800C 10A0000E */  beqz      $a1, .L80218048
/* 52B6B0 80218010 AFBF0014 */   sw       $ra, 0x14($sp)
/* 52B6B4 80218014 0C04760B */  jal       func_8011D82C
/* 52B6B8 80218018 24040001 */   addiu    $a0, $zero, 1
/* 52B6BC 8021801C 0000202D */  daddu     $a0, $zero, $zero
/* 52B6C0 80218020 0080282D */  daddu     $a1, $a0, $zero
/* 52B6C4 80218024 0080302D */  daddu     $a2, $a0, $zero
/* 52B6C8 80218028 0080382D */  daddu     $a3, $a0, $zero
/* 52B6CC 8021802C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 52B6D0 80218030 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 52B6D4 80218034 24030001 */  addiu     $v1, $zero, 1
/* 52B6D8 80218038 0C046F97 */  jal       set_background_color_blend
/* 52B6DC 8021803C A0430000 */   sb       $v1, ($v0)
/* 52B6E0 80218040 24020014 */  addiu     $v0, $zero, 0x14
/* 52B6E4 80218044 AE020070 */  sw        $v0, 0x70($s0)
.L80218048:
/* 52B6E8 80218048 0000202D */  daddu     $a0, $zero, $zero
/* 52B6EC 8021804C 0080282D */  daddu     $a1, $a0, $zero
/* 52B6F0 80218050 0080302D */  daddu     $a2, $a0, $zero
/* 52B6F4 80218054 8E030070 */  lw        $v1, 0x70($s0)
/* 52B6F8 80218058 24020014 */  addiu     $v0, $zero, 0x14
/* 52B6FC 8021805C 00431023 */  subu      $v0, $v0, $v1
/* 52B700 80218060 00023880 */  sll       $a3, $v0, 2
/* 52B704 80218064 00E23821 */  addu      $a3, $a3, $v0
/* 52B708 80218068 00073840 */  sll       $a3, $a3, 1
/* 52B70C 8021806C 0C046F97 */  jal       set_background_color_blend
/* 52B710 80218070 30E700FE */   andi     $a3, $a3, 0xfe
/* 52B714 80218074 8E020070 */  lw        $v0, 0x70($s0)
/* 52B718 80218078 2442FFFF */  addiu     $v0, $v0, -1
/* 52B71C 8021807C AE020070 */  sw        $v0, 0x70($s0)
/* 52B720 80218080 2C420001 */  sltiu     $v0, $v0, 1
/* 52B724 80218084 8FBF0014 */  lw        $ra, 0x14($sp)
/* 52B728 80218088 8FB00010 */  lw        $s0, 0x10($sp)
/* 52B72C 8021808C 00021040 */  sll       $v0, $v0, 1
/* 52B730 80218090 03E00008 */  jr        $ra
/* 52B734 80218094 27BD0018 */   addiu    $sp, $sp, 0x18
