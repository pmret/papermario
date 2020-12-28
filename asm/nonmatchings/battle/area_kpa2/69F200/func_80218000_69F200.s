.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_69F200
/* 69F200 80218000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 69F204 80218004 AFB00010 */  sw        $s0, 0x10($sp)
/* 69F208 80218008 0080802D */  daddu     $s0, $a0, $zero
/* 69F20C 8021800C 10A0000E */  beqz      $a1, .L80218048
/* 69F210 80218010 AFBF0014 */   sw       $ra, 0x14($sp)
/* 69F214 80218014 0C04760B */  jal       func_8011D82C
/* 69F218 80218018 24040001 */   addiu    $a0, $zero, 1
/* 69F21C 8021801C 0000202D */  daddu     $a0, $zero, $zero
/* 69F220 80218020 0080282D */  daddu     $a1, $a0, $zero
/* 69F224 80218024 0080302D */  daddu     $a2, $a0, $zero
/* 69F228 80218028 0080382D */  daddu     $a3, $a0, $zero
/* 69F22C 8021802C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 69F230 80218030 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 69F234 80218034 24030001 */  addiu     $v1, $zero, 1
/* 69F238 80218038 0C046F97 */  jal       set_background_color_blend
/* 69F23C 8021803C A0430000 */   sb       $v1, ($v0)
/* 69F240 80218040 24020014 */  addiu     $v0, $zero, 0x14
/* 69F244 80218044 AE020070 */  sw        $v0, 0x70($s0)
.L80218048:
/* 69F248 80218048 0000202D */  daddu     $a0, $zero, $zero
/* 69F24C 8021804C 0080282D */  daddu     $a1, $a0, $zero
/* 69F250 80218050 0080302D */  daddu     $a2, $a0, $zero
/* 69F254 80218054 8E030070 */  lw        $v1, 0x70($s0)
/* 69F258 80218058 24020014 */  addiu     $v0, $zero, 0x14
/* 69F25C 8021805C 00431023 */  subu      $v0, $v0, $v1
/* 69F260 80218060 00023880 */  sll       $a3, $v0, 2
/* 69F264 80218064 00E23821 */  addu      $a3, $a3, $v0
/* 69F268 80218068 00073840 */  sll       $a3, $a3, 1
/* 69F26C 8021806C 0C046F97 */  jal       set_background_color_blend
/* 69F270 80218070 30E700FE */   andi     $a3, $a3, 0xfe
/* 69F274 80218074 8E020070 */  lw        $v0, 0x70($s0)
/* 69F278 80218078 2442FFFF */  addiu     $v0, $v0, -1
/* 69F27C 8021807C AE020070 */  sw        $v0, 0x70($s0)
/* 69F280 80218080 2C420001 */  sltiu     $v0, $v0, 1
/* 69F284 80218084 8FBF0014 */  lw        $ra, 0x14($sp)
/* 69F288 80218088 8FB00010 */  lw        $s0, 0x10($sp)
/* 69F28C 8021808C 00021040 */  sll       $v0, $v0, 1
/* 69F290 80218090 03E00008 */  jr        $ra
/* 69F294 80218094 27BD0018 */   addiu    $sp, $sp, 0x18
